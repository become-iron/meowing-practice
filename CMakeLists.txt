cmake_minimum_required(VERSION 3.5)

project(App LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(App main.cpp)

#set(BOOST_IN_USE python)
#find_package(Boost COMPONENTS ${BOOST_IN_USE})
#target_link_libraries(App PUBLIC "${Boost_LIBRARIES}")
#message(${Boost_LIBRARIES})
#target_include_directories(App PUBLIC "${Boost_INCLUDE_DIRS}")

find_package(Catch2 REQUIRED)
target_link_libraries(App PUBLIC Catch2::Catch2)

add_subdirectory(sorting)
target_link_libraries(App PRIVATE Sorting)
