/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include <QtCore/QLoggingCategory>
#include <QtCore/QObject>
#include <QtPositioning/QGeoCoordinate>

#include "PlanManager.h"

class Vehicle;

Q_DECLARE_LOGGING_CATEGORY(RallyPointManagerLog)

/// This is the base class for firmware specific rally point managers. A rally point manager is responsible
/// for communicating with the vehicle to set/get rally points.
class RallyPointManager : public PlanManager {
    Q_OBJECT

  public:
    RallyPointManager(Vehicle *vehicle);
    ~RallyPointManager();

    bool supported(void) const;
    void sendToVehicle(const QList<QGeoCoordinate> &rgPoints);
    void removeAll(void);

    QString editorQml(void) const { return QStringLiteral("qrc:/FirmwarePlugin/RallyPointEditor.qml"); }

    QList<QGeoCoordinate> points(void) const { return _rgPoints; }

    /// Error codes returned in error signal
    typedef enum {
        InternalError,
        TooFewPoints,  ///< Too few points for valid geofence
        TooManyPoints, ///< Too many points for valid geofence
        InvalidCircleRadius,
    } ErrorCode_t;

  signals:
    void loadComplete(void);
    void inProgressChanged(bool inProgress);
    void error(int errorCode, const QString &errorMsg);
    void removeAllComplete(bool error);
    void sendComplete(bool error);

  private slots:
    void _sendComplete(bool error);
    void _planManagerLoadComplete(bool removeAllRequested);

  protected:
    void _sendError(ErrorCode_t errorCode, const QString &errorMsg);

    QList<QGeoCoordinate> _rgPoints;
    QList<QGeoCoordinate> _rgSendPoints;
};
