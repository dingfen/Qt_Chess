#ifndef CHESSFACTORY_H
#define CHESSFACTORY_H

#include <QString>
#include <QHash>
#include "mesh.h"
#include "pawn.h"
#include "knight.h"
#include "rook.h"
#include "cannon.h"
#include "bishop.h"
#include "guard.h"
#include "king.h"


class ChessFactory {
public:
    template<typename T>
    static void registerClass() {
        constructors().insert(T::classname(), &constructorHelper<T>);
    }

    static Chess* createObject(const QString& className, const Mesh& mesh) {
        Constructor constructor = constructors().value(className);
        if (!constructor)
            return nullptr;
        return (*constructor)(mesh);
    }

private:
    typedef Chess* (*Constructor)(const Mesh&);

    template<typename T>
    static Chess* constructorHelper(const Mesh& mesh) {
        return new T(mesh);
    }

    static QHash<QString, Constructor>& constructors() {
        static QHash<QString, Constructor> instance;
        return instance;
    }
};

#endif // CHESSFACTORY_H
