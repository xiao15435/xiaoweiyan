#include"std_msgs/msg/string.hpp"
#include"rclcpp/rclcpp.hpp"
class person:public rclcpp::Node
{
private:
     rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub;

public:
     person(std::string node_name):Node(node_name)
     {
        RCLCPP_INFO(this->get_logger(),"hello,I am %s",node_name.c_str());
        pub=this->create_publisher<std_msgs::msg::String>("topic",10);
         
        std_msgs::msg::String name;  
         name.data= node_name;
         pub->publish(name);

     }
     
};

int main(int argc,char**argv)
{
    rclcpp::init(argc,argv);
    auto node =std::make_shared<person>("zhangsan");
    rclcpp::spin(node);
    rclcpp::shutdown();
   
}