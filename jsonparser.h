#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QQueue>
#include <QVector>

class JsonParser {
public:
    JsonParser();
    JsonParser(const QString& path);
    ~JsonParser();

    void openAndRead(const QString& path);
    void parseJson();
    void writeJson(const QVector<QJsonObject>& j);
    bool get(QJsonObject *);
private:
    QFile file;
    QByteArray data_;
    QQueue<QJsonObject> objs_;
};

#endif // JSONPARSER_H
