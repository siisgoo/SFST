cmake_minimum_required(VERSION 3.21)

include(GNUInstallDirs)
include(CMakeSources.cmake)

project(${LIB_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

set(BUILD_TYPE Debug)
set(BUILD_TYPE DEBUG)

include_directories("include")

find_package(SFML 2.5
    COMPONENTS
        system window graphics network audio REQUIRED)

add_library(${LIB_NAME} SHARED ${LIB_SOURCES})

target_link_libraries(${LIB_NAME}
    sfml-graphics
    sfml-audio
)

if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif (BUILD_TESTING)

string(TOLOWER ${LIB_NAME} LIB_NAME_LOWER)
set_target_properties(${LIB_NAME} PROPERTIES
    PREFIX         "lib-"
    OUTPUT_NAME    "${LIB_NAME_LOWER}"
    VERSION        "${LIB_VERCION}"
    PUBLIC_HEADER  "${LIB_HEADERS_PUBLIC}"
    PRIVATE_HEADER "${LIB_HEADERS_PRIVATE}"
)

target_include_directories(${LIB_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIB_NAME}>
    $<INSTALL_INTERFACE:include/${LIB_NAME}>
)

target_include_directories(${LIB_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIB_NAME}>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS ${LIB_NAME}
    LIBRARY        DESTINATION ${CMAKE_INSTALL_LIBDIR}/${LIB_NAME}
    PUBLIC_HEADER  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    PRIVATE_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${LIB_NAME}
)

configure_file(${LIB_NAME}.pc.in ${LIB_NAME}.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/${LIB_NAME}.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
)
