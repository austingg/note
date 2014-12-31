include_directories(${PROJECT_SOURCE_DIR}/libhello)
set(APP_SRC main.cpp)
add_executable(hello ${APP_SRC})
target_link_libraries(hello libhello)