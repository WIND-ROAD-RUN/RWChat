cmake_minimum_required (VERSION 3.27)

project (RWChatSever VERSION 0.1 LANGUAGES CXX)

aux_source_directory(./src SRC_LIST)

find_package(Boost REQUIRED COMPONENTS system)

add_executable (${PROJECT_NAME} ${SRC_LIST} )
target_include_directories(${PROJECT_NAME} PRIVATE ./include)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::system)


