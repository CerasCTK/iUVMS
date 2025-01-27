/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

/// @file
///     @author Pritam Ghanghas <pritam.ghanghas@gmail.com>

#pragma once

#include "APMFirmwarePlugin.h"

class APMRoverMode : public APMCustomMode {
  public:
    enum Mode {
        MANUAL = 0,
        ACRO = 1,
        LEARNING = 2, // Deprecated
        STEERING = 3,
        HOLD = 4,
        LOITER = 5,
        FOLLOW = 6,
        SIMPLE = 7,
        DOCK = 8,
        CIRCLE = 9,
        AUTO = 10,
        RTL = 11,
        SMART_RTL = 12,
        GUIDED = 15,
        INITIALIZING = 16,
    };

    APMRoverMode(uint32_t mode, bool settable);
};

class ArduRoverFirmwarePlugin : public APMFirmwarePlugin {
    Q_OBJECT

  public:
    ArduRoverFirmwarePlugin(void);

    // Overrides from FirmwarePlugin
    QString pauseFlightMode(void) const override { return QStringLiteral("Hold"); }

    QString followFlightMode(void) const override { return QStringLiteral("Follow"); }

    void guidedModeChangeAltitude(Vehicle *vehicle, double altitudeChange, bool pauseVehicle) final;
    int remapParamNameHigestMinorVersionNumber(int majorVersionNumber) const final;

    const FirmwarePlugin::remapParamNameMajorVersionMap_t &paramNameRemapMajorVersionMap(void) const final { return _remapParamName; }

    bool supportsNegativeThrust(Vehicle *) final;

    bool supportsSmartRTL(void) const override { return true; }

    QString offlineEditingParamFile(Vehicle *vehicle) override {
        Q_UNUSED(vehicle);
        return QStringLiteral(":/FirmwarePlugin/APM/Rover.OfflineEditing.params");
    }

  private:
    static bool _remapParamNameIntialized;
    static FirmwarePlugin::remapParamNameMajorVersionMap_t _remapParamName;
};
