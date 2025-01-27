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

class Vehicle;

class VehicleEscStatusFactGroup : public FactGroup {
    Q_OBJECT

  public:
    VehicleEscStatusFactGroup(QObject *parent = nullptr);

    Q_PROPERTY(Fact *index READ index CONSTANT)

    Q_PROPERTY(Fact *rpmFirst READ rpmFirst CONSTANT)
    Q_PROPERTY(Fact *rpmSecond READ rpmSecond CONSTANT)
    Q_PROPERTY(Fact *rpmThird READ rpmThird CONSTANT)
    Q_PROPERTY(Fact *rpmFourth READ rpmFourth CONSTANT)

    Q_PROPERTY(Fact *currentFirst READ currentFirst CONSTANT)
    Q_PROPERTY(Fact *currentSecond READ currentSecond CONSTANT)
    Q_PROPERTY(Fact *currentThird READ currentThird CONSTANT)
    Q_PROPERTY(Fact *currentFourth READ currentFourth CONSTANT)

    Q_PROPERTY(Fact *voltageFirst READ voltageFirst CONSTANT)
    Q_PROPERTY(Fact *voltageSecond READ voltageSecond CONSTANT)
    Q_PROPERTY(Fact *voltageThird READ voltageThird CONSTANT)
    Q_PROPERTY(Fact *voltageFourth READ voltageFourth CONSTANT)

    Fact *index() { return &_indexFact; }

    Fact *rpmFirst() { return &_rpmFirstFact; }

    Fact *rpmSecond() { return &_rpmSecondFact; }

    Fact *rpmThird() { return &_rpmThirdFact; }

    Fact *rpmFourth() { return &_rpmFourthFact; }

    Fact *currentFirst() { return &_currentFirstFact; }

    Fact *currentSecond() { return &_currentSecondFact; }

    Fact *currentThird() { return &_currentThirdFact; }

    Fact *currentFourth() { return &_currentFourthFact; }

    Fact *voltageFirst() { return &_voltageFirstFact; }

    Fact *voltageSecond() { return &_voltageSecondFact; }

    Fact *voltageThird() { return &_voltageThirdFact; }

    Fact *voltageFourth() { return &_voltageFourthFact; }

    // Overrides from FactGroup
    void handleMessage(Vehicle *vehicle, mavlink_message_t &message) override;

  private:
    const QString _indexFactName = QStringLiteral("index");

    const QString _rpmFirstFactName = QStringLiteral("rpm1");
    const QString _rpmSecondFactName = QStringLiteral("rpm2");
    const QString _rpmThirdFactName = QStringLiteral("rpm3");
    const QString _rpmFourthFactName = QStringLiteral("rpm4");

    const QString _currentFirstFactName = QStringLiteral("current1");
    const QString _currentSecondFactName = QStringLiteral("current2");
    const QString _currentThirdFactName = QStringLiteral("current3");
    const QString _currentFourthFactName = QStringLiteral("current4");

    const QString _voltageFirstFactName = QStringLiteral("voltage1");
    const QString _voltageSecondFactName = QStringLiteral("voltage2");
    const QString _voltageThirdFactName = QStringLiteral("voltage3");
    const QString _voltageFourthFactName = QStringLiteral("voltage4");

    Fact _indexFact;

    Fact _rpmFirstFact;
    Fact _rpmSecondFact;
    Fact _rpmThirdFact;
    Fact _rpmFourthFact;

    Fact _currentFirstFact;
    Fact _currentSecondFact;
    Fact _currentThirdFact;
    Fact _currentFourthFact;

    Fact _voltageFirstFact;
    Fact _voltageSecondFact;
    Fact _voltageThirdFact;
    Fact _voltageFourthFact;
};
