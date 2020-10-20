cmake_minimum_required( VERSION 3.14 )

add_library( date.benchmark.utils STATIC )

target_sources( date.benchmark.utils PRIVATE StopWatch.cpp )
target_include_directories( date.benchmark.utils PUBLIC utils )