#include "ros/ros.h"
#include <iostream>
#include "cv_bridge/cv_bridge.h"
#include "sensor_msgs/Image.h"
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <geometry_msgs/Pose.h>
#include <fstream>

using namespace std;
using namespace cv;

int mode = 0;

float rawX = 0;
float rawY = 0;
int imgX = 0;
int imgY = 0;

int filter = 7;
int t_hold = 100;
int circlet = 65;

float sumX = 0;
float sumY = 0;
int loop = 0;

image_transport::Publisher pub2;
image_transport::Publisher pub3;

cv::Mat getCircles(cv::Mat img){
	vector<Vec3f> circles;

	// Apply the Hough Transform to find the circles
	printf("circlet is %d\n", circlet);
	printf("mode is %d\n", mode);
	HoughCircles(img, circles, CV_HOUGH_GRADIENT, 1, img.rows/8, 200, circlet, 0, 0);

	cvtColor(img, img, CV_GRAY2BGR );

	if(circles.size() >= 1){
		rawX = cvRound(circles[0][0]);
		rawY = cvRound(circles[0][1]);

		sumX += cvRound(circles[0][0]);
		sumY += cvRound(circles[0][1]);
	} else{
		printf("404 FLAP NOT FOUND\n");
		return img;
	}

	if(loop == 10){
		cv::Mat meanImg = img;
		float deltaX = sumX/loop;
		float deltaY = sumY/loop;

		Point center(deltaX, deltaY);
		printf("Test: deltax is %f, deltay is %f\n", deltaX, deltaY);
		circle(meanImg, center, 3, Scalar(255,255,0), -1, 8, 0 );

		cv_bridge::CvImagePtr cv_ptr(new cv_bridge::CvImage);
		cv_ptr->encoding = "bgr8";
		cv_ptr->image = meanImg;
	
		pub3.publish(cv_ptr->toImageMsg());

		//imshow("average flap center", meanImg);
		//waitKey(4010);
	}

	// Draw the circles detected
	for( size_t i = 0; i < circles.size(); i++ )
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);

		printf("%d, %d, %d\n", cvRound(circles[i][0]), cvRound(circles[i][1]), cvRound(circles[i][2]));
		// circle center
		circle(img, center, 3, Scalar(0,255,0), -1, 8, 0 );
		// circle outline
		circle(img, center, radius, Scalar(0,0,255), 3, 8, 0 );
	}

	printf("%lu\n", circles.size());

	return img;
}

cv::Mat findFlap(cv::Mat img){

	cv::Mat detected_edges;

	//clean up
	blur(img, detected_edges, Size(filter, filter) );

	//convert to edges

	//imshow( "b/w blur", detected_edges);

	Canny(detected_edges, detected_edges, t_hold, t_hold*3, 5);

	/// Using Canny's output as a mask, we display our result
	Mat dst;
	dst = Scalar::all(0);

	img.copyTo( dst, detected_edges);
	//imshow( window_name, dst );

	dst = getCircles(dst);

	return dst;
}


//Make any neccessary transformations
cv::Mat imageTransform(cv::Mat img){

	//convert to grayscale
	cvtColor(img, img, CV_BGR2GRAY );

	//add blur
	//GaussianBlur(img, img, Size(9, 9), 2, 2);

	return img;
}

//FOR CAMERA USE
void getLiveImage(const sensor_msgs::ImageConstPtr& msg)
{

	printf("test\n");
	cv::Mat image = cv_bridge::toCvShare(msg, "bgr8")->image;


	printf("test2\n");
	// node handler
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<geometry_msgs::Pose>("rawCV", 1);

	if(!image.data){
		printf("oh no\n");
		return;
	}

	imgX = image.size().width;
	imgY = image.size().height;

	image = imageTransform(image);
	image = findFlap(image);


	//publish image to ros topic 
	//sensor_msgs::Image imgmsg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg;
	cv_bridge::CvImagePtr cv_ptr(new cv_bridge::CvImage);
	cv_ptr->encoding = "bgr8";
	cv_ptr->image = image;
	
	pub2.publish(cv_ptr->toImageMsg());		
	//	while(ros::ok){
	//pub2.publish(imgmsg);
	//		}


	//pub.publish(pose);

	//ros::spin();
}

void getTestImage(){

  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<geometry_msgs::Pose>("rawCV", 1);
  
  cv::Mat img = imread("test_image_2.png");


  imgX = img.size().width;
  imgY = img.size().height;

  img = imageTransform(img);
  img = findFlap(img);

  /*geometry_msgs::Pose msg;
  msg.position.x = rawX/imgX;
  msg.position.y = rawY/imgY;*/

  //pub.publish(msg);

  cv_bridge::CvImagePtr cv_ptr(new cv_bridge::CvImage);
  cv_ptr->encoding = "bgr8";
  cv_ptr->image = img;
  pub2.publish(cv_ptr->toImageMsg());		
}

int main(int argc, char **argv){

	//initialize node
	ros::init(argc, argv, "cv_node");

	// node handler
	ros::NodeHandle n;


	//load setting from .yaml
	n.getParam("settings/mode", mode);
	n.getParam("settings/filter", filter);
	n.getParam("settings/t_hold", t_hold);
	n.getParam("settings/circlet", circlet);

	//publisher
	ros::Publisher pub = n.advertise<geometry_msgs::Pose>("rawCV", 1);

	image_transport::ImageTransport it(n);
	image_transport::ImageTransport it2(n);
	pub2 = it.advertise("arm_camera/image", 1);
	pub3 = it2.advertise("arm_camera/average", 1);
	
	if(mode == 0){
	  // subsribe topic
	  while(ros::ok){
	  	loop++;
	    ros::Subscriber sub = n.subscribe("/cv_camera/image_raw", 1, getLiveImage);
	    
	    if(loop == 10){
	    	printf("Loop = %d\n", loop);
		  	printf("sumX = %f\n", sumX);
		  	printf("sumY = %f\n", sumY);
		  	float deltaX = sumX/imgX/loop;
		  	printf("deltaX = %f\n", deltaX);
		  	float deltaY = sumY/imgY/loop;
		  	printf("deltaY = %f\n", deltaY);

		  	geometry_msgs::Pose pose;
		  	pose.position.x = deltaX;
		  	pose.position.y = deltaY;
		  	pub.publish(pose);

		  	loop = 0;
	  		sumX = 0;
	  		sumY = 0;
	    }

	    ros::spin();

	  }
	}
	else{
	  while(ros::ok){
	  	loop++;
	    getTestImage();
	    sleep(1);

	    if(loop == 10){
	    	printf("Loop = %d\n", loop);
	  		printf("sumX = %f\n", sumX);
	  		printf("sumY = %f\n", sumY);
	  		float deltaX = sumX/imgX/loop;
	  		printf("deltaX = %f\n", deltaX);
	  		float deltaY = sumY/imgY/loop;
			printf("deltaY = %f\n", deltaY);

	  		geometry_msgs::Pose pose;
	  		pose.position.x = deltaX;
	 		pose.position.y = deltaY;
	  		pub.publish(pose);

	  		loop = 0;
	  		sumX = 0;
	  		sumY = 0;
	    }
	  }
	}

	return 0;
}
