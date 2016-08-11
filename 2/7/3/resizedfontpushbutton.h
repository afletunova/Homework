#pragma once
#include <QPushButton>

class ResizedFontPushButton : public QPushButton
{
public:
    ResizedFontPushButton(QPushButton *parent = 0);

    void resizeEvent(QResizeEvent *);

    QFont font;
};
