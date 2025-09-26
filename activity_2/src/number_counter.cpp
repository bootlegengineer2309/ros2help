#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

using namespace std::chrono_literals;
using namespace std::placeholders;

class NumberCounterNode : public rclcpp::Node // MODIFY NAME
{
public:
    NumberCounterNode() : Node("number_publisher"), count(0)
    {
        numberSubscriber_ = create_subscription<example_interfaces::msg::Int64>(
            "number", 10,
            std::bind(&NumberCounterNode::callbackCount, this, _1)
        );
        numberPublisher_ = create_publisher<example_interfaces::msg::Int64>("number_count", 10);
        RCLCPP_INFO(get_logger(), "Number counter and publisher started.");
    }

private:

    void publishCount()
    {
        auto msg = example_interfaces::msg::Int64();
        msg.data = count;
        numberPublisher_->publish(msg);
    }

    void callbackCount(const example_interfaces::msg::Int64::SharedPtr msg)
    {
        auto newNum = msg->data;
        count = count + newNum;
        
        publishCount();
    }

    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr numberPublisher_;
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr numberSubscriber_;
    int count;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounterNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}