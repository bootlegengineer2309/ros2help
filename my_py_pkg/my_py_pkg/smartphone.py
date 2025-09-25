#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String


class SmartphoneNode(Node):  # MODIFY NAME
    def __init__(self):
        super().__init__("smartphone")
        self.subscriber_=self.create_subscription(String, "robot_news",self.callback_robot_news, 10)

    def callback_robot_news(self, msg):
        news = msg.data
        self.get_logger().info(f"News is: {news}")

def main(args=None):
    rclpy.init(args=args)
    node = SmartphoneNode()  # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()