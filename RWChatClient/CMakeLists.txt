cmake_minimum_required (VERSION 3.27)

project (RWChatClient VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Boost REQUIRED COMPONENTS system)

list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS ./ui)
aux_source_directory(./src SRC_FILES)
file(GLOB INCLUDE_FILES "include/*.h")
file(GLOB UI_FILES "ui/*.ui")

add_executable(${PROJECT_NAME} ${SRC_FILES} ${UI_FILES} ${INCLUDE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::system)
target_include_directories(${PROJECT_NAME} PRIVATE ./include)

