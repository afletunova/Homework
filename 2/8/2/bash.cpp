#include <QDomDocument>
#include "bash.h"

Bash::Bash(QObject *parent)
    :QObject(parent), networkManager(new QNetworkAccessManager(this)), wasQuotesLoaded(false)
{
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

void Bash::loadQuotes()
{
    networkManager->get(QNetworkRequest(QUrl("http://bash.im/rss/")));
}

Quote Bash::getQuote(const int &index)
{
    return *quotes[index];
}

int Bash::getQuotesCount()
{
    return quotes.size();
}

bool Bash::isQuotesLoaded()
{
    return wasQuotesLoaded;
}

void Bash::voteUp(const int &index)
{
    vote(index, "up");
}

void Bash::voteDown(const int &index)
{
    vote(index, "down");
}

void Bash::old(const int &index)
{
    vote(index, "old");
}

void Bash::parseRssAndFillsQuotes(const QByteArray &rss)
{
    for (Quote *quote : quotes)
    {
        delete quote;
    }
    quotes.clear();

    QDomDocument document;
    document.setContent(rss);
    QDomNodeList items = document.elementsByTagName("item");

    for (int i = 0; i < items.count(); i++)
    {
        QDomNode item = items.at(i);
        QString text = item.firstChildElement("description").text();
        int id = item.firstChildElement("link").text().split("/").last().toInt();
        quotes.append(new Quote(text, id));
    }
    wasQuotesLoaded = true;
    emit quotesLoaded();
}

void Bash::vote(const int &index, const QString &rate)
{
    QString url = QString("http://bash.im/quote/%1/%2").arg(QString::number(quotes[index]->getId()), rate);
    QString params =  QString("quote=%1&act=%2").arg(QString::number(quotes[index]->getId()), rate);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    networkManager->post(request, params.toUtf8());
}

void Bash::replyFinished(QNetworkReply *reply)
{
    if (reply->url().toString().contains("rss"))
    {
        QByteArray rss = reply->readAll();
        parseRssAndFillsQuotes(rss);
    }
}
