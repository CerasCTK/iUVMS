/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "FactGroup.h"
#include "QGCMAVLink.h"

class VehicleTemperatureFactGroup : public FactGroup {
    Q_OBJECT

  public:
    VehicleTemperatureFactGroup(QObject *parent = nullptr);

    Q_PROPERTY(Fact *temperature1 READ temperature1 CONSTANT)
    Q_PROPERTY(Fact *temperature2 READ temperature2 CONSTANT)
    Q_PROPERTY(Fact *temperature3 READ temperature3 CONSTANT)

    Fact *temperature1() { return &_temperature1Fact; }

    Fact *temperature2() { return &_temperature2Fact; }

    Fact *temperature3() { return &_temperature3Fact; }

    // Overrides from FactGroup
    void handleMessage(Vehicle *vehicle, mavlink_message_t &message) override;

  private:
    void _handleScaledPressure(mavlink_message_t &message);
    void _handleScaledPressure2(mavlink_message_t &message);
    void _handleScaledPressure3(mavlink_message_t &message);
    void _handleHighLatency(mavlink_message_t &message);
    void _handleHighLatency2(mavlink_message_t &message);

    const QString _temperature1FactName = QStringLiteral("temperature1");
    const QString _temperature2FactName = QStringLiteral("temperature2");
    const QString _temperature3FactName = QStringLiteral("temperature3");

    Fact _temperature1Fact;
    Fact _temperature2Fact;
    Fact _temperature3Fact;
};
