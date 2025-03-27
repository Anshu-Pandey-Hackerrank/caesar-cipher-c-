cmake_minimum_required(VERSION 3.26)

project(person)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++2b")
set(PERSON_INCLUDES ${PERSON_INCLUDES} ${PROJECT_SOURCE_DIR}/src)
set(PERSON_INCLUDES ${PERSON_INCLUDES} ${PROJECT_SOURCE_DIR}/include)

# Gather all sources except the main entry point
file(GLOB_RECURSE INC_FILES src/*/*.hpp)
file(GLOB_RECURSE SRC_FILES src/*/*.cpp)

# Dependencies
find_package(Boost COMPONENTS filesystem system REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
include_directories(${Boost_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS})

# Unit tests
add_subdirectory(test)

# Build
set(SOURCE_FILES src/main.cpp ${INC_FILES} ${SRC_FILES})
add_executable(person ${SOURCE_FILES})
target_link_libraries(person ${Boost_LIBRARIES} ${JSONCPP_LIBRARIES})
