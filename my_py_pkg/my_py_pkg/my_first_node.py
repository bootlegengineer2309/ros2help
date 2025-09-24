#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node):

    def __init__(self):
        super().__init__("py_test")
        self.get_logger().info("Hello world")
        self.seconds_passed = 0
        self.create_timer(1.0, self.timer_callback)
        self.create_timer(1.0, self.count_seconds)

    def timer_callback(self):
        self.get_logger().info("Hello")

    def count_seconds(self):
        self.seconds_passed += 1
        self.get_logger().info(f"Seconds passed: {self.seconds_passed}")

def main(args=None):
    rclpy.init(args=args)
    node = MyNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()