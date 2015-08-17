cmake_minimum_required(VERSION 3.2)
project(good_project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(good_project ${SOURCE_FILES} IObject.cpp IObject.h Event.cpp Event.h EventSystem.cpp EventSystem.h IEventHandler.cpp IEventHandler.h ObjectMovementHandler.cpp ObjectMovementHandler.h ObjectFactory.cpp ObjectFactory.h MovableObject.cpp MovableObject.h Character.cpp Character.h)
