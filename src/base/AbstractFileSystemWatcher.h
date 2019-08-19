#pragma once
//libraries
#include <QSet>
#include <QObject>
#include <QString>

//local


class AbstractFileSystemWatcher : public QObject {
Q_OBJECT

public:
    AbstractFileSystemWatcher(QObject* parent = nullptr) : QObject(parent) {}

    virtual QSet<QString> directories() = 0;

public slots:

    virtual bool enable() = 0;

    virtual bool disable() = 0;

Q_SIGNALS:

    void fileChanged(QString path);

    void fileRemoved(QString path);
};



