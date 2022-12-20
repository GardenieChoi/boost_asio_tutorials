cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${Boost_INCLUDE_DIR})

project(boost_asio_tutorial)

set(BOOST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/external/boost_1_80_0)
set(BOOST_INCLUDEDIR ${CMAKE_CURRENT_SOURCE_DIR}/external/boost_1_80_0/build/include)
set(BOOST_LIBRARYDIR ${CMAKE_CURRENT_SOURCE_DIR}/external/boost_1_80_0/build/lib)
set(Boost_NO_SYSTEM_PATHS ON)
find_package(Boost 1.80.0 REQUIRED
COMPONENTS
    thread
)

add_executable(boost_asio_tutorial ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(boost_asio_tutorial
    PRIVATE
        ${Boost_LIBRARIES}
)
