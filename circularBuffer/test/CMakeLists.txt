

if(BUILD_TESTING)
    add_executable(circularBufferTest CircularBuffer_test.cpp)
    
    target_link_libraries(circularBufferTest PUBLIC gtest gmock gtest_main)
    target_link_libraries(circularBufferTest PUBLIC circularBuffer)
    target_include_directories(circularBufferTest
                           PUBLIC "${PROJECT_BINARY_DIR}"
                           PUBLIC "${PROJECT_SOURCE_DIR}/circularBuffer/include"
                           )

    add_test(NAME circularBufferTests COMMAND circularBufferTest)
    include(GoogleTest)

    gtest_discover_tests(circularBufferTest)
endif()