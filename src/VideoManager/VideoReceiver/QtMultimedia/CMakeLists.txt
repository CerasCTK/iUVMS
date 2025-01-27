find_package(Qt6 REQUIRED COMPONENTS Core)

qt_add_library(QtMultimediaReceiver STATIC)

cmake_print_variables(UVMS_ENABLE_QT_VIDEOSTREAMING)
if(NOT UVMS_ENABLE_QT_VIDEOSTREAMING)
    return()
endif()

find_package(Qt6 REQUIRED COMPONENTS Multimedia MultimediaQuickPrivate Quick)

target_sources(QtMultimediaReceiver
    PRIVATE
        QtMultimediaReceiver.cc
        QtMultimediaReceiver.h
)

target_link_libraries(QtMultimediaReceiver
    PRIVATE
        Qt6::MultimediaQuickPrivate
        Qt6::Quick
        UVMS
        Utilities
    PUBLIC
        Qt6::Core
        Qt6::Multimedia
        VideoReceiver
)

target_include_directories(QtMultimediaReceiver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(QtMultimediaReceiver PUBLIC UVMS_QT_STREAMING)

if(NOT UVMS_ENABLE_UVC)
    target_compile_definitions(QtMultimediaReceiver PUBLIC UVMS_DISABLE_UVC)
    return()
endif()

target_sources(QtMultimediaReceiver
    PRIVATE
        UVCReceiver.cc
        UVCReceiver.h
)

target_precompile_headers(QtMultimediaReceiver
    PRIVATE
        <QtMultimedia/QMediaDevices>
)
