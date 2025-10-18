
#include"rclcpp/rclcpp.hpp"
#include"std_msgs/msg/string.hpp"
class subperson:public rclcpp::Node
{
private:
     rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub;


    void callback(const std_msgs::msg::String::SharedPtr name)
     {
        RCLCPP_INFO(this->get_logger(),"hello,%s",name->data.c_str());
       
     }
     
public:
subperson(std::string node_name):Node(node_name)
{
     sub=this->create_subscription<std_msgs::msg::String>("topic",10,std::bind(&subperson::callback,this,std::placeholders::_1));
     RCLCPP_INFO(this->get_logger(),"waiting");
}

};

int main(int argc,char**argv)
{
    rclcpp::init(argc,argv);
    auto node =std::make_shared<subperson>("lisi");
    rclcpp::spin(node);
    rclcpp::shutdown();

}