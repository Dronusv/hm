cmake_minimum_required(VERSION 3.14)

project(lsn2f LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Sql)

add_executable(lsn2f
  main.cpp
)
target_link_libraries(lsn2f Qt${QT_VERSION_MAJOR}::Core
                            Qt${QT_VERSION_MAJOR}::Network
                            Qt${QT_VERSION_MAJOR}::Sql)

include(GNUInstallDirs)
install(TARGETS lsn2f
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
