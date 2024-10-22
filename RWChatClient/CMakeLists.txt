cmake_minimum_required (VERSION 3.27)

project (RWChatClient VERSION 0.1 LANGUAGES CXX)

aux_source_directory(./src SRC_LIST)

add_executable (${PROJECT_NAME} ${SRC_LIST} )

target_include_directories(${PROJECT_NAME} PRIVATE ./include)


