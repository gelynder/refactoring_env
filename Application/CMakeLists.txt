set(TARGET_NAME Application)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(APP_SOURCES
    Controller.cpp
)
set(APP_HEADERS
    Controller.hpp
)

add_library(${TARGET_NAME} STATIC ${APP_SOURCES} ${APP_HEADERS})
target_link_libraries(${TARGET_NAME} Events)


enable_testing()
set(TEST_SOURCES
    Tests/ControllerTest.cpp
)
set(MOCK_LIST
    Tests/Mocks/CommunicationPointMock.hpp
)

set(UT_DRIVER ${TARGET_NAME}_UT)
add_executable(${UT_DRIVER} ${TEST_SOURCES} ${MOCK_LIST})
target_link_libraries(${UT_DRIVER} ${TARGET_NAME} gtest_main gmock)

if (BUILD_COVERAGE_UNIT_TESTS)
    set_target_properties(${TARGET_NAME} PROPERTIES COMPILE_FLAGS ${CMAKE_CXX_FLAGS_COVERAGE})
    set_target_properties(${UT_DRIVER} PROPERTIES COMPILE_FLAGS ${CMAKE_CXX_FLAGS_COVERAGE})
    target_link_libraries(${UT_DRIVER} ${CMAKE_CXX_COVERAGE_LIBRARY})
    setup_target_for_coverage(${UT_DRIVER}_COV ${UT_DRIVER} ${COVERAGE_REPORT_LOCATION})
endif()
