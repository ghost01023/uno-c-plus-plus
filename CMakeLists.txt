cmake_minimum_required(VERSION 3.23)
project(UNO)

set(CMAKE_CXX_STANDARD 23)

add_executable(UNO main.cpp player.h player.cpp protodeck.cpp protodeck.h card.h card.cpp deck.h deck.cpp)
