#include "resizedfontpushbutton.h"

ResizedFontPushButton::ResizedFontPushButton(QPushButton *parent)
    :QPushButton(parent)
{
    setFont(font);
}

void ResizedFontPushButton::resizeEvent(QResizeEvent *)
{
    font.setPixelSize(this->size().height() / 2);
    setFont(font);
}
