#pragma once
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QVector>
#include "quote.h"


/*!
 * \brief The Bash class - class to parse and display quotes from the site bash.im (bash.im/rss/)
 */

class Bash : public QObject
{
    Q_OBJECT

public:
    explicit Bash(QObject *parent = 0);

    void loadQuotes();

    Quote getQuote(const int &index);

    int getQuotesCount();

    bool isQuotesLoaded();

    void voteUp(const int &index);

    void voteDown(const int &index);

    void old(const int &index);

private:
    /*!
     * \brief parseRssAndFillsQuotes - parses obtained xml and loads quote
     * \param rss
     */
    void parseRssAndFillsQuotes(const QByteArray &rss);
    /*!
     * \brief vote - sends a voice request to the server
     * \param index - quote index
     * \param rate
     */
    void vote(const int &index, const QString &rate);

    QNetworkAccessManager *networkManager;
    QVector<Quote *> quotes;
    bool wasQuotesLoaded;

signals:
    void quotesLoaded();

public slots:
    void replyFinished(QNetworkReply *reply);
};
