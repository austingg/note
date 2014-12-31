set(LIB_SRC hello.cpp)
add_library(libhello ${LIB_SRC})
set_target_properties(libhello PROPERTIES OUTPUT_NAME "hello")
