#include "rclcpp_components/component_manager.hpp"
#include <gazebo_ros/node_visibility_control.h>

namespace gazebo_ros
{

class GAZEBO_ROS_NODE_PUBLIC ComponentManager : public rclcpp_components::ComponentManager{
public:
    using rclcpp_components::ComponentManager::ComponentManager;

    void
    add_node_to_executor(rclcpp::node_interfaces::NodeBaseInterface::SharedPtr node)
    {
        if (auto exec = this->executor_.lock()) {
            exec->add_node(node, true);
        }
    }
};

}