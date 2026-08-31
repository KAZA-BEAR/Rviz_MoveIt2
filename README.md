# Rviz_MoveIt2
ROS2 Jazzy Package for Robotic Arm control using move group

## Usage

[Screencast from 2026-08-31 07-44-11.webm](https://github.com/user-attachments/assets/f7392070-57d8-4860-bf2d-2b841880c310)

## Usage

Build the package:

```bash
colcon build
source install/setup.bash
```

Launch the Robot Bringup in Terminal 1:

```bash
ros2 launch my_robot_bringup my_robot.launch.xml 
```
Run the move group interface in Terminal 2 after sourcing:

```bash
source install/setup.bash
ros2 run my_robot_commander_cpp test_moveit
```

## File Structure

```
Rviz_MoveIt2/
├── src/
│   └── my_robot_commander_cpp/
│       ├── launch/
│       │   └── move_group_demo.launch.py
│       ├── src/
│       │   └── commander_node.cpp
│       ├── include/
│       │   └── my_robot_commander_cpp/
│       ├── config/
│       │   ├── moveit_controllers.yaml
│       │   └── kinematics.yaml
│       ├── CMakeLists.txt
│       └── package.xml
├── .gitignore
└── README.md
```
