/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "shapefil.h"
#include "ShapeFileHelper.h"

#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtPositioning/QGeoCoordinate>

/// The QGCMapPolygon class provides a polygon which can be displayed on a map using a map visuals control.
/// It maintains a representation of the polygon on QVariantList and QmlObjectListModel format.
class SHPFileHelper : public QObject {
    Q_OBJECT

  public:
    static ShapeFileHelper::ShapeType determineShapeType(const QString &shpFile, QString &errorString);
    static bool loadPolygonFromFile(const QString &shpFile, QList<QGeoCoordinate> &vertices, QString &errorString);

  private:
    static bool _validateSHPFiles(const QString &shpFile, int *utmZone, bool *utmSouthernHemisphere, QString &errorString);
    static SHPHandle _loadShape(const QString &shpFile, int *utmZone, bool *utmSouthernHemisphere, QString &errorString);

    static constexpr const char *_errorPrefix = QT_TR_NOOP("SHP file load failed. %1");
};
