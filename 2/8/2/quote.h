#pragma once

#include <QString>

/*!
 * \brief The Quote class - class representing quote: text and its id.
 */

class Quote
{
public:
    Quote(const QString &text, int id)
        :text(text),id(id)
    {}

    QString getText()
    {
        return text;
    }

    int getId()
    {
        return id;
    }

private:
    QString text;
    int id;
};
