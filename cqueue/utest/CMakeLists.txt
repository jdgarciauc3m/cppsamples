find_package(GTest REQUIRED)

set(CMAKE_BUILD_TYPE "Debug")
add_compile_options(--coverage)

set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_utest)
file(GLOB TEST_SRC_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/*.cpp)

include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_TEST_NAME} 
    ${GTEST_BOTH_LIBRARIES} 
    ${GTEST_MAIN_LIBRARY} 
    ${GTEST_LIBRARY}
    gcov pthread
)

gtest_add_tests(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_TEST_NAME} 
    "" ${TEST_SRC_FILES})

find_program(LCOV_CMD lcov)
find_program(GENHTML_CMD genhtml)

ADD_CUSTOM_TARGET(coverage
    ${LCOV_CMD} --directory . --zerocounters
    COMMAND ${PROJECT_TEST_NAME}
    COMMAND ${LCOV_CMD} --directory . --capture --output-file mycov.info
    COMMAND ${LCOV_CMD} --remove mycov.info '/usr/*' 'utest/*' 
        --output-file mycov.info.cleaned
    COMMAND ${GENHTML_CMD} -o mycov mycov.info.cleaned --legend -s 
    COMMAND ${CMAKE_COMMAND} -E remove mycov.info mycov.info.cleaned
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Computing coverage and generating report"
)

ADD_CUSTOM_COMMAND(TARGET coverage POST_BUILD
    COMMAND google-chrome ./mycov/index.html &
)


