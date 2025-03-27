cmake_minimum_required(VERSION 3.26)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(PROJECT_UNIT_TESTS_NAME person_tests)

# Gather the header and source files
file(GLOB UNIT_TESTS_INC_FILES ${PROJECT_SOURCE_DIR}/test/*.hpp)
file(GLOB UNIT_TESTS_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

# Dependencies
find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
include_directories(${Boost_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS})

# Build unit tests
add_definitions(-DBOOST_TEST_DYN_LINK)
add_executable(${PROJECT_UNIT_TESTS_NAME} ${UNIT_TESTS_SRC_FILES} ${SRC_FILES})
target_link_libraries(${PROJECT_UNIT_TESTS_NAME} ${Boost_LIBRARIES} ${JSONCPP_LIBRARIES})
enable_testing()
add_test(person_tests ${PROJECT_UNIT_TESTS_NAME})
