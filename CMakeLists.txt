cmake_minimum_required(VERSION 3.14)

project(test LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(test
  main.cpp
  Core/Players/HumanPlayer.cpp
  Core/Players/AIPlayer.cpp
  Common/Cell.cpp
  Common/Symbols.cpp
  Core/GameManager.cpp
  Core/Game.cpp
  Core/utils/CheckInputs.cpp
  Core/Display/DisplayConsole.cpp
  Core/Display/Display.cpp
  Games/TicTacToe/TicTacToe.cpp
  Games/ConnectFour/ConnectFour.cpp
  Common/Board.cpp
  Games/Othello/Othello.cpp
  Core/Observer/InterfaceObserver.cpp
  Core/Observer/ConsoleObserver.cpp
  Core/Observer/GUIObserver.cpp
)
target_link_libraries(test Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)