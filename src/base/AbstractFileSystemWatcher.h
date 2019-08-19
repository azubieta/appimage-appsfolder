#pragma once
//libraries
#include <QObject>
//local


class AbstractFileSystemWatcher : public QObject {
Q_OBJECT

public:
    AbstractFileSystemWatcher(QObject* parent = nullptr) : QObject(parent) {}

public slots:

    virtual bool enable() = 0;

    virtual bool disable() = 0;

Q_SIGNALS:

    void fileChanged(QString path);

    void fileRemoved(QString path);
};



