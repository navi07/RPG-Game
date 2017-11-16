cmake_minimum_required(VERSION 3.6)
project(Projekt)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Item.h Error.h Sword.h File.h Armor.h Helmet.h Material.h Character.h Monster.h Player.h Fight.h)
add_executable(Projekt ${SOURCE_FILES})