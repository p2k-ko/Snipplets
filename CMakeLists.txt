cmake_minimum_required(VERSION 3.0)
project (StateMachine)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically 
set(CMAKE_AUTOMOC ON)

# Find the QtCore library
find_package(Qt5Core)
find_package(Qt5Widgets)

add_executable(${PROJECT_NAME} main.cpp)

# Use the core library
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets) 

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
