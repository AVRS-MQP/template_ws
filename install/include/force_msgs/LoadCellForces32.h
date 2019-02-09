// Generated by gencpp from file force_msgs/LoadCellForces32.msg
// DO NOT EDIT!


#ifndef FORCE_MSGS_MESSAGE_LOADCELLFORCES32_H
#define FORCE_MSGS_MESSAGE_LOADCELLFORCES32_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace force_msgs
{
template <class ContainerAllocator>
struct LoadCellForces32_
{
  typedef LoadCellForces32_<ContainerAllocator> Type;

  LoadCellForces32_()
    : header()
    , headerstamp()
    , cellA(0.0)
    , cellB(0.0)
    , cellC(0.0)  {
    }
  LoadCellForces32_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , headerstamp()
    , cellA(0.0)
    , cellB(0.0)
    , cellC(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef ros::Time _headerstamp_type;
  _headerstamp_type headerstamp;

   typedef float _cellA_type;
  _cellA_type cellA;

   typedef float _cellB_type;
  _cellB_type cellB;

   typedef float _cellC_type;
  _cellC_type cellC;





  typedef boost::shared_ptr< ::force_msgs::LoadCellForces32_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::force_msgs::LoadCellForces32_<ContainerAllocator> const> ConstPtr;

}; // struct LoadCellForces32_

typedef ::force_msgs::LoadCellForces32_<std::allocator<void> > LoadCellForces32;

typedef boost::shared_ptr< ::force_msgs::LoadCellForces32 > LoadCellForces32Ptr;
typedef boost::shared_ptr< ::force_msgs::LoadCellForces32 const> LoadCellForces32ConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::force_msgs::LoadCellForces32_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::force_msgs::LoadCellForces32_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace force_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'force_msgs': ['/home/avrs/AVRS_ws/src/msgs/force_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::force_msgs::LoadCellForces32_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::force_msgs::LoadCellForces32_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::force_msgs::LoadCellForces32_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::force_msgs::LoadCellForces32_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::force_msgs::LoadCellForces32_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::force_msgs::LoadCellForces32_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::force_msgs::LoadCellForces32_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f212bc1b7495a187d9c991f6bd06e446";
  }

  static const char* value(const ::force_msgs::LoadCellForces32_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf212bc1b7495a187ULL;
  static const uint64_t static_value2 = 0xd9c991f6bd06e446ULL;
};

template<class ContainerAllocator>
struct DataType< ::force_msgs::LoadCellForces32_<ContainerAllocator> >
{
  static const char* value()
  {
    return "force_msgs/LoadCellForces32";
  }

  static const char* value(const ::force_msgs::LoadCellForces32_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::force_msgs::LoadCellForces32_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
time headerstamp\n\
float32 cellA\n\
float32 cellB\n\
float32 cellC\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::force_msgs::LoadCellForces32_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::force_msgs::LoadCellForces32_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.headerstamp);
      stream.next(m.cellA);
      stream.next(m.cellB);
      stream.next(m.cellC);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LoadCellForces32_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::force_msgs::LoadCellForces32_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::force_msgs::LoadCellForces32_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "headerstamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.headerstamp);
    s << indent << "cellA: ";
    Printer<float>::stream(s, indent + "  ", v.cellA);
    s << indent << "cellB: ";
    Printer<float>::stream(s, indent + "  ", v.cellB);
    s << indent << "cellC: ";
    Printer<float>::stream(s, indent + "  ", v.cellC);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FORCE_MSGS_MESSAGE_LOADCELLFORCES32_H