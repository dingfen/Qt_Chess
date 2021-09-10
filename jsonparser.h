#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QQueue>

class JsonParser {
public:
    JsonParser(const QString& file);
    ~JsonParser();

    void parseJson();
    bool get(QJsonObject *);
private:
    QByteArray data_;
    QQueue<QJsonObject> objs_;
};

#endif // JSONPARSER_H
