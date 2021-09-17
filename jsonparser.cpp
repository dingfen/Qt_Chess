#include "jsonparser.h"

JsonParser::JsonParser() {

}

JsonParser::JsonParser(const QString& path) {
    file.setFileName(path);
}

void JsonParser::openAndRead(const QString& path) {
    file.setFileName(path);
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


void JsonParser::writeJson(const QVector<QJsonObject>& obj_vec) {
    QJsonArray ja;
    QJsonDocument doc;
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Json file Open error!";
        return;
    }
    for(auto &obj : obj_vec) {
        ja.append(obj);
    }
    doc.setArray(ja);
    file.write(doc.toJson());
    file.close();
}

bool JsonParser::get(QJsonObject *ptr) {
    if (!objs_.empty()) {
        *ptr = objs_.front();
        objs_.pop_front();
        return true;
    }
    return false;
}
