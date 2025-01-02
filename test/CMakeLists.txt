if(NOT UVMS_BUILD_TESTING)
    return()
endif()

find_package(Qt6 REQUIRED COMPONENTS Core Test)

include(CTest)
enable_testing()

# if(ANDROID)
    # include(AndroidTestUtilities)
# endif()

add_custom_target(check
    COMMAND ctest --output-on-failure .
    USES_TERMINAL
)

function(add_uvms_test test_name)
    add_test(
        NAME ${test_name}
        COMMAND $<TARGET_FILE:${PROJECT_NAME}> --unittest:${test_name}
    )
    add_dependencies(check ${PROJECT_NAME})
endfunction()

add_subdirectory(ADSB)
add_uvms_test(ADSBTest)

add_subdirectory(AnalyzeView)
add_uvms_test(ExifParserTest)
add_uvms_test(GeoTagControllerTest)
add_uvms_test(LogDownloadTest)
# add_uvms_test(MavlinkLogTest)
add_uvms_test(PX4LogParserTest)
add_uvms_test(ULogParserTest)

add_subdirectory(Audio)
add_uvms_test(AudioOutputTest)

# add_subdirectory(AutoPilotPlugins)
# add_uvms_test(RadioConfigTest)

add_subdirectory(Camera)
add_uvms_test(QGCCameraManagerTest)

add_subdirectory(Comms)
add_uvms_test(QGCSerialPortInfoTest)

add_subdirectory(FactSystem)
add_uvms_test(FactSystemTestGeneric)
add_uvms_test(FactSystemTestPX4)
add_uvms_test(ParameterManagerTest)

add_subdirectory(FollowMe)
add_uvms_test(FollowMeTest)

add_subdirectory(Geo)
add_uvms_test(GeoTest)

add_subdirectory(GPS)
add_uvms_test(GpsTest)

add_subdirectory(MAVLink)
add_uvms_test(StatusTextHandlerTest)
add_uvms_test(SigningTest)

add_subdirectory(MissionManager)
add_uvms_test(CameraCalcTest)
add_uvms_test(CameraSectionTest)
add_uvms_test(CorridorScanComplexItemTest)
# add_uvms_test(FWLandingPatternTest)
# add_uvms_test(LandingComplexItemTest)
# add_uvms_test(MissionCommandTreeEditorTest)
add_uvms_test(MissionCommandTreeTest)
add_uvms_test(MissionControllerManagerTest)
add_uvms_test(MissionControllerTest)
add_uvms_test(MissionItemTest)
add_uvms_test(MissionManagerTest)
add_uvms_test(MissionSettingsTest)
add_uvms_test(PlanMasterControllerTest)
add_uvms_test(QGCMapPolygonTest)
add_uvms_test(QGCMapPolylineTest)
# add_uvms_test(SectionTest)
add_uvms_test(SimpleMissionItemTest)
add_uvms_test(SpeedSectionTest)
add_uvms_test(StructureScanComplexItemTest)
add_uvms_test(SurveyComplexItemTest)
add_uvms_test(TransectStyleComplexItemTest)
# add_uvms_test(VisualMissionItemTest)

add_subdirectory(qgcunittest)
# add_uvms_test(FileDialogTest)
# add_uvms_test(MainWindowTest)
# add_uvms_test(MessageBoxTest)

add_subdirectory(QmlControls)

add_subdirectory(Terrain)
add_uvms_test(TerrainQueryTest)
add_uvms_test(TerrainTileTest)

add_subdirectory(UI)

add_subdirectory(Utilities)
# Compression
add_uvms_test(DecompressionTest)
add_uvms_test(UtilitiesTest)

add_subdirectory(Vehicle)
# Components
add_uvms_test(ComponentInformationCacheTest)
add_uvms_test(ComponentInformationTranslationTest)
add_uvms_test(FTPManagerTest)
# add_uvms_test(InitialConnectTest)
add_uvms_test(MAVLinkLogManagerTest)
# add_uvms_test(RequestMessageTest)
# add_uvms_test(SendMavCommandWithHandlerTest)
# add_uvms_test(SendMavCommandWithSignalingTest)

# add_uvms_test(FlightGearUnitTest)
# add_uvms_test(LinkManagerTest)
# add_uvms_test(SendMavCommandTest)
# add_uvms_test(TCPLinkTest)

# set(UNIT_TESTING_RESOURCES)
# qt_add_resources(UNIT_TESTING_RESOURCES UnitTest.qrc)
qt_add_library(uvmstest
    STATIC
        UnitTestList.cc
        UnitTestList.h
        # ${UNIT_TESTING_RESOURCES}
)

target_link_libraries(uvmstest
    PRIVATE
        ADSBTest
        AnalyzeViewTest
        AudioTest
        CameraTest
        CommsTest
        CompressionTest
        FactSystemTest
        FollowMeTest
        GeoTest
        GpsTest
        MAVLinkTest
        MissionManagerTest
        QmlControlsTest
        TerrainTest
        UITest
        VehicleTest
        VehicleComponentsTest
        Utilities
        UtilitiesTest
    PUBLIC
        Qt6::Core
        qgcunittest
)

target_include_directories(uvmstest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
