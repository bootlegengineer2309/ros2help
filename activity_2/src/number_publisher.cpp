#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

using namespace std::chrono_literals;

class NumberPublisherNode : public rclcpp::Node // MODIFY NAME
{
public:
    NumberPublisherNode() : Node("number_publisher"), number(2)
    {
        numberPublisher_ = create_publisher<example_interfaces::msg::Int64>("number", 10);
        timer_ = create_wall_timer(1.0s, std::bind(&NumberPublisherNode::publishNumber, this));
        RCLCPP_INFO(get_logger(), "Number publisher started.");
    }

private:

    void publishNumber()
    {
        auto msg = example_interfaces::msg::Int64();
        msg.data = number;
        numberPublisher_->publish(msg);
    }

    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr numberPublisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int number;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}