/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "ToolStripAction.h"

ToolStripAction::ToolStripAction(QObject *parent) : QObject(parent) {}

void ToolStripAction::setEnabled(bool enabled) {
    if (enabled != _enabled) {
        _enabled = enabled;
        emit enabledChanged(enabled);
    }
}

void ToolStripAction::setVisible(bool visible) {
    if (visible != _visible) {
        _visible = visible;
        emit visibleChanged(visible);
    }
}

void ToolStripAction::setCheckable(bool checkable) {
    if (checkable != _checkable) {
        _checkable = checkable;
        emit checkableChanged(checkable);
    }
}

void ToolStripAction::setChecked(bool checked) {
    if (checked != _checked) {
        _checked = checked;
        emit checkedChanged(checked);
    }
}

void ToolStripAction::setShowAlternateIcon(bool showAlternateIcon) {
    if (showAlternateIcon != _showAlternateIcon) {
        _showAlternateIcon = showAlternateIcon;
        emit showAlternateIconChanged(showAlternateIcon);
    }
}

void ToolStripAction::setbiColorIcon(bool biColorIcon) {
    if (biColorIcon != _biColorIcon) {
        _biColorIcon = biColorIcon;
        emit biColorIconChanged(biColorIcon);
    }
}

void ToolStripAction::setfullColorIcon(bool fullColorIcon) {
    if (fullColorIcon != _fullColorIcon) {
        _fullColorIcon = fullColorIcon;
        emit fullColorIconChanged(fullColorIcon);
    }
}

void ToolStripAction::setNonExclusive(bool nonExclusive) {
    if (nonExclusive != _nonExclusive) {
        _nonExclusive = nonExclusive;
        emit nonExclusiveChanged(nonExclusive);
    }
}

void ToolStripAction::setToolStripIndex(int toolStripIndex) {
    if (toolStripIndex != _toolStripIndex) {
        _toolStripIndex = toolStripIndex;
        emit toolStripIndexChanged(toolStripIndex);
    }
}

void ToolStripAction::setText(const QString &text) {
    if (text != _text) {
        _text = text;
        emit textChanged(text);
    }
}

void ToolStripAction::setIconSource(const QString &iconSource) {
    if (iconSource != _iconSource) {
        _iconSource = iconSource;
        emit iconSourceChanged(iconSource);
    }
}

void ToolStripAction::setAlternateIconSource(const QString &alternateIconSource) {
    if (alternateIconSource != _alternateIconSource) {
        _alternateIconSource = alternateIconSource;
        emit alternateIconSourceChanged(alternateIconSource);
    }
}

void ToolStripAction::setDropPanelComponent(QQmlComponent *dropPanelComponent) {
    _dropPanelComponent = dropPanelComponent;
    emit dropPanelComponentChanged();
}
