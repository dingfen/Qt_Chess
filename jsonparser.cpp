#include "jsonparser.h"

JsonParser::JsonParser(const QString& path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Open " << path << " error!";
    }
    data_ = file.readAll();
    file.close();
}


JsonParser::~JsonParser() {
}


void JsonParser::parseJson() {
    QJsonParseError je;
    QJsonDocument doc = QJsonDocument::fromJson(data_, &je);
    if(doc.isNull() || je.error != QJsonParseError::NoError) {
        qDebug() << "Json file error!";
        return;
    }
    QJsonArray ja;
    if (doc.isArray()) {
        ja = doc.array();
    } else {
        qDebug() << "No Json array in file.";
        return;
    }
    int size = ja.size();
    for(int i = 0; i < size; i++) {
        QJsonObject chess_obj = ja.at(i).toObject();
        objs_.push_back(chess_obj);
    }
}


bool JsonParser::get(QJsonObject *ptr) {
    if (!objs_.empty()) {
        *ptr = objs_.front();
        objs_.pop_front();
        return true;
    }
    return false;
}
