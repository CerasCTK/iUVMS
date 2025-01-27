/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include <QtCore/QObject>

#include "FactPanelController.h"

class APMAirframeModel;
class APMAirframeType;
class QmlObjectListModel;

/// MVC Controller for APMAirframeComponent.qml.
class APMAirframeComponentController : public FactPanelController {
    Q_OBJECT
    Q_MOC_INCLUDE("QmlObjectListModel.h")

  public:
    APMAirframeComponentController(void);
    ~APMAirframeComponentController();

    Q_PROPERTY(QmlObjectListModel *frameClassModel MEMBER _frameClassModel CONSTANT)

    Q_INVOKABLE void loadParameters(const QString &paramFile);

  private slots:
    void _githubJsonDownloadComplete(QString remoteFile, QString localFile, QString errorMsg);
    void _paramFileDownloadComplete(QString remoteFile, QString localFile, QString errorMsg);

  private:
    void _fillFrameClasses(void);
    void _loadParametersFromDownloadFile(const QString &downloadedParamFile);

    Fact *_frameClassFact;
    Fact *_frameTypeFact;
    QmlObjectListModel *_frameClassModel;
};

class APMFrameClass : public QObject {
    Q_OBJECT

  public:
    APMFrameClass(const QString &name, bool copter, int frameClass, Fact *frameTypeFact, QObject *parent = nullptr);
    ~APMFrameClass();

    Q_PROPERTY(QString name MEMBER _name CONSTANT)
    Q_PROPERTY(int frameClass MEMBER _frameClass CONSTANT)
    Q_PROPERTY(int frameType READ frameType NOTIFY frameTypeChanged)
    Q_PROPERTY(QStringList frameTypeEnumStrings MEMBER _frameTypeEnumStrings CONSTANT)
    Q_PROPERTY(QVariantList frameTypeEnumValues MEMBER _frameTypeEnumValues CONSTANT)
    Q_PROPERTY(int defaultFrameType MEMBER _defaultFrameType CONSTANT)
    Q_PROPERTY(QString imageResource READ imageResource NOTIFY imageResourceChanged)
    Q_PROPERTY(QString imageResourceDefault MEMBER _imageResourceDefault CONSTANT)
    Q_PROPERTY(bool frameTypeSupported MEMBER _frameTypeSupported CONSTANT)

    int frameType(void);
    QString imageResource(void);

    QString _name;
    bool _copter;
    QString _imageResource;
    QString _imageResourceDefault;
    int _frameClass;
    QStringList _frameTypeEnumStrings;
    QVariantList _frameTypeEnumValues;
    int _defaultFrameType;
    bool _frameTypeSupported;

  signals:
    void imageResourceChanged(void);
    void frameTypeChanged();

  private:
    Fact *_frameTypeFact;
};
