cmake_minimum_required(VERSION 3.10)
project(caesar_cipher CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")

# Include directories
include_directories(src src/include)

# Create library from source files
add_library(caesar_cipher_lib 
    src/include/caesar_cipher.cpp
)

# Add main executable that will process JSON input
add_executable(caesar_cipher_app
    src/main.cpp
)
target_link_libraries(caesar_cipher_app caesar_cipher_lib)

# Add the test executable
add_executable(caesar_cipher_test 
    test/caesar_cipher_tests.cpp
)
target_link_libraries(caesar_cipher_test caesar_cipher_lib)

# Add test targets
enable_testing()
add_test(NAME CaesarCipherTest COMMAND caesar_cipher_test)

# Install targets
install(TARGETS caesar_cipher_app DESTINATION bin)
install(TARGETS caesar_cipher_test DESTINATION test/bin)