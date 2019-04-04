/**
 * @file constraint.cpp
 * @brief Base class for IK-solver Constraints
 *
 * Specify relationship between joint velocities and constraint "error"
 *
 * @author dsolomon
 * @date Sep 15, 2013
 * @version TODO
 * @bug No known bugs
 *
 * @copyright Copyright (c) 2013, Southwest Research Institute
 *
 * @par License
 * Software License Agreement (Apache License)
 * @par
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * @par
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "constrained_ik/constraint.h"
#include "constrained_ik/constrained_ik.h"
#include <ros/ros.h>

using namespace Eigen;

namespace constrained_ik
{

int Constraint::numJoints() const
{
  return ik_->getKin().numJoints();
}

} // namespace constrained_ik
