#include "rclcpp_components/component_manager.hpp"
#include "rclcpp_components/node_instance_wrapper.hpp"
#include <gazebo_ros/node_visibility_control.h>

namespace gazebo_ros
{

class GAZEBO_ROS_NODE_PUBLIC ComponentManager : public rclcpp_components::ComponentManager{
public:
    using rclcpp_components::ComponentManager::ComponentManager;

    void
    add_node_to_executor(
        rclcpp_components::NodeInstanceWrapper & node)
    {
        auto node_id = unique_id_++;
        node_wrappers_[node_id] = node;
        if (auto exec = this->executor_.lock()) {
            exec->add_node(node.get_node_base_interface(), true);
        }
    }
};

}