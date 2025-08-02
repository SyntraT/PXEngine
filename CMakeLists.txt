cmake_minimum_required(VERSION 3.21)
project(PXEngine)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Export compile commands (for tools like clangd)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify the directory where executable files will be placed after build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Optionally, set separate output directories for different build types
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/Release)

# Define NDEBUG for non-Debug builds
if (NOT CMAKE_BUILD_TYPE MATCHES Debug)
	message(STATUS "Debuging mode is enabled.")
    add_definitions(-DNDEBUG)
endif()

# ========== Tracy Profiler Setup ==========
option(ENABLE_TRACY "Enable Tracy profiler" ON)

if (ENABLE_TRACY)
    message(STATUS "Tracy Profiler is enabled.")
    add_definitions(-DTRACY_ENABLE)

    # Add TracyClient to the build
    add_library(TracyClient STATIC external/tracy/public/TracyClient.cpp)

    # Add include path
    target_include_directories(TracyClient PUBLIC external/tracy/public/tracy)
endif()

# ==========================================


# Add subdirectories
add_subdirectory(src)
add_subdirectory(examples/sandbox)
