#include "rclcpp/rclcpp.hpp"

class RobotNewsStationNode : public rclcpp::Node // MODIFY NAME
{
public:
    RobotNewsStationNode() : Node("node_name") // MODIFY NAME
    {
    }

private:
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNewsStationNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}