cmake_minimum_required( VERSION 3.14 )

project( DateBenchmarkTest )

add_executable( date.benchmark )
target_link_libraries( date.benchmark PRIVATE date  )
target_link_libraries( date.benchmark PRIVATE date-tz  )
target_link_libraries( date.benchmark PRIVATE fmt-header-only )
target_link_libraries( date.benchmark PRIVATE gtest )
target_link_libraries( date.benchmark PRIVATE gmock )
target_link_libraries( date.benchmark PRIVATE date.benchmark.utils )

target_sources( date.benchmark PRIVATE main.cpp bench1.cpp bench2.cpp )

find_package(GTest)

gtest_discover_tests(
    date.benchmark
    # WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin # The data directory is linked/copied(Win) into this directory...
    # TEST_PREFIX API:${_component}:
  DISCOVERY_TIMEOUT 10 )




