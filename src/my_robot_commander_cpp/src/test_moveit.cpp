#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>

int main(int args, char **argc)
{
    rclcpp::init(args, argc);

    auto node = std::make_shared<rclcpp::Node>("test_moveit");

    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node);
    auto spinner = std::thread([&executor](){executor.spin();});

    auto arm = moveit::planning_interface::MoveGroupInterface(node, "arm");
    auto gripper = moveit::planning_interface::MoveGroupInterface(node, "gripper");

    arm.setMaxVelocityScalingFactor(1.0);
    arm.setMaxAccelerationScalingFactor(1.0);
    gripper.setMaxVelocityScalingFactor(1.0);
    gripper.setMaxAccelerationScalingFactor(1.0);

    //Named Goal

    arm.setStartStateToCurrentState();
    gripper.setStartStateToCurrentState();
    
    
    arm.setNamedTarget("pose_1");

    moveit::planning_interface::MoveGroupInterface::Plan plan1;
    bool success1 = (arm.plan(plan1) == moveit::core::MoveItErrorCode::SUCCESS);


    if(success1){
        arm.execute(plan1);
    }

    gripper.setNamedTarget("gripper_half_closed");

    moveit::planning_interface::MoveGroupInterface::Plan plan3;
    bool success3 = (gripper.plan(plan3) == moveit::core::MoveItErrorCode::SUCCESS);

    if(success3){
        gripper.execute(plan3);
    }
    
    arm.setNamedTarget("pose_2");

    moveit::planning_interface::MoveGroupInterface::Plan plan2;
    bool success2 = (arm.plan(plan2) == moveit::core::MoveItErrorCode::SUCCESS);

    if(success2){
        arm.execute(plan2);
    }

    gripper.setNamedTarget("gripper_open");

    moveit::planning_interface::MoveGroupInterface::Plan plan4;
    bool success4 = (gripper.plan(plan4) == moveit::core::MoveItErrorCode::SUCCESS);

    if(success4){
        gripper.execute(plan4);
    }

    arm.setNamedTarget("home");

    moveit::planning_interface::MoveGroupInterface::Plan plan5;
    bool success5 = (arm.plan(plan5) == moveit::core::MoveItErrorCode::SUCCESS);


    if(success5){
        arm.execute(plan5);
    }


    rclcpp::shutdown();
    spinner.join();
    return 0;
}