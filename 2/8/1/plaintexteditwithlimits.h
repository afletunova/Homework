#pragma once

#include <QPlainTextEdit>

/*!
 * \brief The PlainTextEditWithLimits class - represents class based on QPlainTextEdit with limits for user
 */

class PlainTextEditWithLimits : public QPlainTextEdit
{
    Q_OBJECT
public:
    PlainTextEditWithLimits(QWidget *parent)
    {
        this->setParent(parent);
    }
    ~PlainTextEditWithLimits(){}
    void keyPressEvent(QKeyEvent *){}
    void contextMenuEvent(QContextMenuEvent *){}
};
