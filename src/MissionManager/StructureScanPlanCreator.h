/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "PlanCreator.h"

class StructureScanPlanCreator : public PlanCreator {
    Q_OBJECT

  public:
    StructureScanPlanCreator(PlanMasterController *planMasterController, QObject *parent = nullptr);

    Q_INVOKABLE void createPlan(const QGeoCoordinate &mapCenterCoord) final;
};
