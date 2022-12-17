cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOOST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/external)
set(Boost_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)
set(Boost_NO_SYSTEM_PATHS ON)
find_package(Boost 1.80.0 REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

project(boost_asio_tutorial)
add_executable(boost_asio_tutorial ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(boost_asio_tutorial
    PRIVATE
        ${Boost_LIBRARIES}
)
