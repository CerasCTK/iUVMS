/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

/// @file
///     @author Don Gagne <don@thegagnes.com>

#include <QtCore/QLoggingCategory>
#include <QtCore/QObject>
#include <QtCore/QStringList>
#include <QtCore/QTimer>

Q_DECLARE_LOGGING_CATEGORY(FactPanelControllerLog)

class AutoPilotPlugin;
class Vehicle;
class Fact;

/// FactPanelController is used for handling missing Facts from C++ code.
class FactPanelController : public QObject {
    Q_OBJECT
    Q_MOC_INCLUDE("Vehicle.h")
    Q_MOC_INCLUDE("Fact.h")
  public:
    FactPanelController(QObject *parent = nullptr);

    Q_PROPERTY(Vehicle *vehicle MEMBER _vehicle CONSTANT)

    Q_INVOKABLE Fact *getParameterFact(int componentId, const QString &name, bool reportMissing = true);
    Q_INVOKABLE bool parameterExists(int componentId, const QString &name);

    /// Queries the vehicle for parameters which were not available on initial download but should be available now.
    /// Signals missingParametersAvailable when done. Only works for MAV_COMP_ID_AUTOPILOT1 parameters.
    Q_INVOKABLE void getMissingParameters(QStringList rgNames);

  signals:
    void missingParametersAvailable(void);

  protected:
    /// Checks for existence of the specified parameters
    /// @return true: all parameters exists, false: parameters missing and reported
    bool _allParametersExists(int componentId, QStringList names);

    /// Report a missing parameter
    void _reportMissingParameter(int componentId, const QString &name);

    Vehicle *_vehicle = nullptr;
    AutoPilotPlugin *_autopilot = nullptr;

  private slots:
    void _checkForMissingParameters(void);

  private:
    QStringList _missingParameterWaitList;
    QTimer _missingParametersTimer;
};
