cmake_minimum_required( VERSION 3.14 )
set(CMAKE_C_COMPILER_WORKS ON)
set(CMAKE_CXX_COMPILER_WORKS ON)
project( DateBenchmark VERSION 0.0.1 )

#set(DISABLE_STRING_VIEW 1)
#set(MANUAL_TZ_DB 1)
# -DCMAKE_PREFIX_PATH=C:\Users\JC\Documents\vcpkg\packages\curl_x86-windows\share\curl:C:\Users\JC\Documents\vcpkg\packages\zlib_x86-windows\share\curl
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)
