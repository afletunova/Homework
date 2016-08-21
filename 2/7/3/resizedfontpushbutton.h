#pragma once
#include <QPushButton>

/**
 * @brief The ResizedFontPushButton class
 * Implements QPushButton with automatically resize depending on the size of parent window.
 */

class ResizedFontPushButton : public QPushButton
{
public:
    ResizedFontPushButton(QPushButton *parent = 0);

    void resizeEvent(QResizeEvent *);

    QFont font;
};
