cmake_minimum_required(VERSION 3.16)
project(pacman LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(pacman 
src/main.cpp 
src/entities/player.h 
src/entities/player.cpp
src/utility/time.h
src/utility/time.cpp
src/common/updatable.h
src/common/time-updatable.h)
target_link_libraries(pacman PRIVATE sfml-graphics)
target_compile_features(pacman PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET pacman
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:pacman>
        VERBATIM)
endif()

install(TARGETS pacman)