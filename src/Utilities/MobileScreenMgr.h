/****************************************************************************
 *
 *   (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#ifdef __mobile__

class MobileScreenMgr {

  public:
    /// Turns on/off screen sleep on mobile devices
    static void setKeepScreenOn(bool keepScreenOn);
};

#endif
