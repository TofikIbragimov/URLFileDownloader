cmake_minimum_required(VERSION 3.16)
project(URLFileDownloader LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(URLFileDownloader
    src/main.cpp
)

target_include_directories(URLFileDownloader PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

find_package(OpenSSL REQUIRED)

target_link_libraries(URLFileDownloader PRIVATE
    OpenSSL::SSL
    OpenSSL::Crypto
)

if (WIN32)
    target_compile_definitions(URLFileDownloader PRIVATE
        _WIN32_WINNT=0x0A00
        WIN32_LEAN_AND_MEAN
        NOMINMAX
    )

    target_link_libraries(URLFileDownloader PRIVATE
        ws2_32
        crypt32
    )
endif()

if (UNIX AND NOT APPLE)
    target_link_libraries(URLFileDownloader PRIVATE
        pthread
    )
endif()