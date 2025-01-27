/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "TerrainFactGroup.h"

TerrainFactGroup::TerrainFactGroup(QObject *parent)
    : FactGroup(1000, ":/json/Vehicle/TerrainFactGroup.json", parent), _blocksPendingFact(0, _blocksPendingFactName, FactMetaData::valueTypeDouble), _blocksLoadedFact(0, _blocksLoadedFactName, FactMetaData::valueTypeDouble) {
    _addFact(&_blocksPendingFact, _blocksPendingFactName);
    _addFact(&_blocksLoadedFact, _blocksLoadedFactName);
}
