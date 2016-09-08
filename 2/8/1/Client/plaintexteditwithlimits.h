#pragma once

#include <QPlainTextEdit>

class PlainTextEditWithLimits : public QPlainTextEdit
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *){}
    void contextMenuEvent(QContextMenuEvent *){}
};
