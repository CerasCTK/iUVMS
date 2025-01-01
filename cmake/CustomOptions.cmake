# The following options can be overriden by custom builds using the CustomOverrides.cmake file

# General

# TODO: change this file to match with iUVMS application

set(UVMS_APP_NAME "iUVMS" CACHE STRING "App Name")
set(UVMS_APP_COPYRIGHT "Copyright (c) 2024 QGroundControl. All rights reserved." CACHE STRING "Copyright")
set(UVMS_APP_DESCRIPTION "Open Source Ground Control App" CACHE STRING "Description")
set(UVMS_ORG_NAME "QGroundControl.org" CACHE STRING "Org Name")
set(UVMS_ORG_DOMAIN "org.qgroundcontrol" CACHE STRING "Domain")

option(UVMS_STABLE_BUILD "Stable Build" OFF)

option(UVMS_ENABLE_BLUETOOTH "Enable Bluetooth Links" ON) # Qt6Bluetooth_FOUND
option(UVMS_ZEROCONF_ENABLED "Enable ZeroConf Compatibility" OFF)
option(UVMS_AIRLINK_DISABLED "Disable AIRLink" ON)
option(UVMS_NO_SERIAL_LINK "Disable Serial Links" OFF) # NOT IOS AND Qt6SerialPort_FOUND

option(UVMS_UTM_ADAPTER "Enable UTM Adapter" OFF)
option(UVMS_VIEWER3D "Enable Viewer3D" ON) # Qt6Quick3D_FOUND

option(UVMS_ENABLE_UVC "Enable UVC Devices" ON) # Qt6Multimedia_FOUND
option(UVMS_ENABLE_GST_VIDEOSTREAMING "Enable GStreamer Video Backend" ON)
option(UVMS_ENABLE_QT_VIDEOSTREAMING "Enable QtMultimedia Video Backend" OFF) # Qt6Multimedia_FOUND

set(UVMS_MAVLINK_GIT_REPO "https://github.com/mavlink/c_library_v2.git" CACHE STRING "URL to MAVLink Git Repo")
set(UVMS_MAVLINK_GIT_TAG "4db2f67156d996eae90ef437a73353468d850407" CACHE STRING "Tag of MAVLink Git Repo")

set(UVMS_QT_ANDROID_MIN_SDK_VERSION "26" CACHE STRING "Android Min SDK Version")
set(UVMS_QT_ANDROID_TARGET_SDK_VERSION "35" CACHE STRING "Android Target SDK Version")

# MacOS
set(UVMS_BUNDLE_ID "org.qgroundcontrol.QGroundControl" CACHE STRING "MacOS Bundle ID") # MACOS
set(UVMS_MACOS_ICON_PATH "${CMAKE_SOURCE_DIR}/deploy/mac" CACHE PATH "MacOS Icon Path") # MACOS

# APM
option(UVMS_DISABLE_APM_MAVLINK "Disable APM Dialect" OFF)
option(UVMS_DISABLE_APM_PLUGIN "Disable APM Plugin" OFF)
option(UVMS_DISABLE_APM_PLUGIN_FACTORY "Disable APM Plugin Factory" OFF)

# PX4
option(UVMS_DISABLE_PX4_PLUGIN "Disable PX4 Plugin" OFF)
option(UVMS_DISABLE_PX4_PLUGIN_FACTORY "Disable PX4 Plugin Factory" OFF)

