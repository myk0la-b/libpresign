cmake_minimum_required(VERSION 3.15)
project(libpresign VERSION 1.2.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(BUILD_PYTHON_MODULE "Build Python module" ON)
option(BUILD_SHARED_LIB "Build shared library" OFF)
option(BUILD_STATIC_LIB "Build static library" OFF)

# Find OpenSSL
if(APPLE AND DEFINED ENV{CIBUILDWHEEL})
    # For macOS wheels, prefer static linking to avoid runtime dependencies
    set(OPENSSL_USE_STATIC_LIBS TRUE)
endif()
find_package(OpenSSL REQUIRED)

# Platform-specific settings
if(APPLE)
    message(STATUS "Building for macOS")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    if(CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64")
        message(STATUS "Building for ARM64 Mac")
        # ARM64 Mac
        set(MACOSX_DEPLOYMENT_TARGET "13.0" CACHE STRING "Minimum macOS deployment version")
        set(CMAKE_OSX_DEPLOYMENT_TARGET "13.0" CACHE STRING "Minimum macOS deployment version")
    else()
        # Intel Mac
        set(MACOSX_DEPLOYMENT_TARGET "10.9" CACHE STRING "Minimum macOS deployment version")
        set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9" CACHE STRING "Minimum macOS deployment version")
    endif()
elseif(UNIX)
    # Linux specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
endif()

# Core library sources
set(CORE_SOURCES
    src/presign.cpp
    src/presign.h
)

# Create object library for shared code
add_library(presign_core OBJECT ${CORE_SOURCES})
target_include_directories(presign_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(presign_core PUBLIC OpenSSL::Crypto)
# Ensure -fPIC is used for object files that will be part of a shared library
set_property(TARGET presign_core PROPERTY POSITION_INDEPENDENT_CODE ON)

# Optional: Build standalone shared library
if(BUILD_SHARED_LIB)
    add_library(presign SHARED $<TARGET_OBJECTS:presign_core>)
    target_link_libraries(presign PUBLIC OpenSSL::Crypto ${CMAKE_DL_LIBS})
    set_target_properties(presign PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
    )
endif()

# Optional: Build standalone static library
if(BUILD_STATIC_LIB)
    add_library(presign_static STATIC $<TARGET_OBJECTS:presign_core>)
    target_link_libraries(presign_static PUBLIC OpenSSL::Crypto ${CMAKE_DL_LIBS})
endif()

# Python module
if(BUILD_PYTHON_MODULE)
    # Find Python
    if(WIN32)
        # On Windows, we need Development component for stable ABI
        find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
    else()
        find_package(Python3 COMPONENTS Interpreter Development.Module REQUIRED)
    endif()
    
    # Create Python extension module
    # Note: We don't use WITH_SOABI for stable ABI compatibility
    Python3_add_library(libpresign MODULE
        src/module.cpp
        $<TARGET_OBJECTS:presign_core>
    )
    
    target_link_libraries(libpresign PRIVATE
        OpenSSL::Crypto
        ${CMAKE_DL_LIBS}
    )
    
    # Windows specific settings
    if(WIN32)
        # Set the library suffix for Windows
        set_target_properties(libpresign PROPERTIES SUFFIX ".pyd")
    endif()
    
    # Set the output name (without prefix)
    set_target_properties(libpresign PROPERTIES PREFIX "")
    
    
    # Install rules for scikit-build-core
    install(TARGETS libpresign LIBRARY DESTINATION libpresign)
endif()

# Export compile commands for IDEs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Print configuration summary
message(STATUS "")
message(STATUS "libpresign configuration summary:")
message(STATUS "  Version: ${PROJECT_VERSION}")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Build Python Module: ${BUILD_PYTHON_MODULE}")
message(STATUS "  Build Shared Library: ${BUILD_SHARED_LIB}")
message(STATUS "  Build Static Library: ${BUILD_STATIC_LIB}")
message(STATUS "  OpenSSL Version: ${OPENSSL_VERSION}")
if(APPLE)
    message(STATUS "  macOS Deployment Target: ${CMAKE_OSX_DEPLOYMENT_TARGET}")
    message(STATUS "  MACOSX_DEPLOYMENT_TARGET: ${MACOSX_DEPLOYMENT_TARGET}")
endif()
if(BUILD_PYTHON_MODULE)
    message(STATUS "  Python Version: ${Python3_VERSION}")
    message(STATUS "  Python Site Packages: ${Python3_SITELIB}")
endif()
message(STATUS "")