/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "PlanElementController.h"
#include "PlanMasterController.h"

PlanElementController::PlanElementController(PlanMasterController *masterController, QObject *parent) : QObject(parent), _masterController(masterController), _flyView(false) {}

PlanElementController::~PlanElementController() {}

void PlanElementController::start(bool flyView) { _flyView = flyView; }
