cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(PROJECT_UNIT_TESTS_NAME caesar_cipher_test)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/src/include)

# Build unit tests
add_executable(${PROJECT_UNIT_TESTS_NAME} caesar_cipher_tests.cpp)
target_link_libraries(${PROJECT_UNIT_TESTS_NAME} caesar_cipher_lib)

# Enable testing
enable_testing()
add_test(NAME CaesarCipherTest COMMAND ${PROJECT_UNIT_TESTS_NAME})