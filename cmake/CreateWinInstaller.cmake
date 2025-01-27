message(STATUS "Creating Win Installer")

include(CMakePrintHelpers)

# cmake_path(CONVERT "${CMAKE_BINARY_DIR}/../deploy/windows" TO_CMAKE_PATH_LIST UVMS_INSTALLER_SOURCE)
file(TO_NATIVE_PATH "${CMAKE_BINARY_DIR}/deploy/windows" UVMS_INSTALLER_SOURCE)
file(TO_NATIVE_PATH "${UVMS_INSTALLER_SOURCE}/WindowsQGC.ico" UVMS_INSTALLER_ICON)
file(TO_NATIVE_PATH "${UVMS_INSTALLER_SOURCE}/installheader.bmp" UVMS_INSTALLER_HEADER_BITMAP)
file(TO_NATIVE_PATH "${UVMS_INSTALLER_SOURCE}/driver.msi" UVMS_INSTALLER_DRIVER_MSI)
file(TO_NATIVE_PATH "${CMAKE_BINARY_DIR}/QGroundControl-installer.exe" UVMS_INSTALLER_OUT)
cmake_print_variables(UVMS_INSTALLER_SOURCE UVMS_INSTALLER_ICON UVMS_INSTALLER_HEADER_BITMAP UVMS_INSTALLER_DRIVER_MSI)

file(TO_NATIVE_PATH "${UVMS_INSTALLER_SOURCE}/nullsoft_installer.nsi" UVMS_NSIS_INSTALLER_SCRIPT)
set(_PF86 "PROGRAMFILES(x86)")
find_program(UVMS_NSIS_INSTALLER_CMD makensis
    PATHS "$ENV{PROGRAMFILES}/NSIS" "$ENV{${_PF86}}/NSIS" "$ENV{PROGRAMW6432}/NSIS"
    DOC "Path to the makensis utility."
)
cmake_print_variables(UVMS_NSIS_INSTALLER_SCRIPT UVMS_NSIS_INSTALLER_CMD)

set(UVMS_NSIS_INSTALLER_PARAMETERS
    /DDRIVER_MSI=${UVMS_INSTALLER_DRIVER_MSI}
    /DINSTALLER_ICON=${UVMS_INSTALLER_ICON}
    /DHEADER_BITMAP=${UVMS_INSTALLER_HEADER_BITMAP}
    /DAPPNAME=QGroundControl
    /DEXENAME=QGroundControl
    /DORGNAME=org.mavlink.qgroundcontrol
    /DDESTDIR=${CMAKE_BINARY_DIR}/staging
    /NOCD
    "/XOutFile ${UVMS_INSTALLER_OUT}"
    ${UVMS_NSIS_INSTALLER_SCRIPT}
)
cmake_print_variables(UVMS_NSIS_INSTALLER_PARAMETERS)

message(STATUS "Win Installer Command: \"${UVMS_NSIS_INSTALLER_CMD} ${UVMS_NSIS_INSTALLER_PARAMETERS}\"")

execute_process(
    COMMAND ${UVMS_NSIS_INSTALLER_CMD} ${UVMS_NSIS_INSTALLER_PARAMETERS}
    RESULT_VARIABLE NSIS_RESULT
    OUTPUT_VARIABLE NSIS_OUTPUT
    ERROR_VARIABLE NSIS_ERROR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

cmake_print_variables(NSIS_RESULT NSIS_OUTPUT NSIS_ERROR)
