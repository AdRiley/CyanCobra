project(CyanCobra)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/mybuild $ENV{GMOCK_HOME}/gtest/mybuild)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources
    CursesInput.cpp
    GameEngine.cpp
    GameMap.cpp
    RoomGenerator.cpp
    AsciiGameMapView.cpp
    RoomMaker.cpp
    Player.cpp)
add_library(CyanCobra_lib ${sources})
add_executable(CyanCobra main.cpp CursesDisplay.cpp)
target_link_libraries(CyanCobra CyanCobra_lib) 
target_link_libraries(CyanCobra ncurses)

enable_testing()
set (testSources
     testMain.cpp
     GameEngineTester.cpp
     GameMapTester.cpp
     RoomGeneratorTester.cpp
     AsciiGameMapViewTester.cpp
     PlayerTester.cpp
     RoomMakerTester.cpp
     PointTester.cpp)
add_executable(runUnitTests ${testSources})
target_link_libraries(runUnitTests CyanCobra_lib) 
target_link_libraries(runUnitTests pthread)
target_link_libraries(runUnitTests gmock)
target_link_libraries(runUnitTests gtest)

add_test(runTests runUnitTests)

