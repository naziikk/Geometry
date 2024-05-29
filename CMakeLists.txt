cmake_minimum_required(VERSION 3.27)
project(untitled17)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled17 main.cpp
        point.h
        ishape.h
        segment.h
        line.h
        ray.h
        polygon.h
        circle.h
        vector.h
        src/point.cpp
        src/vector.cpp
        src/segment.cpp
        src/circle.cpp
        src/ray.cpp
        src/line.cpp
        src/polygon.cpp)
