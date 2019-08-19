// system includes
#include <memory>

// library includes
#include <QObject>
#include <QSet>
#include <QString>
#include <QThread>

// local
#include "AbstractFileSystemWatcher.h"

#pragma once

class FileSystemWatcherError : public std::runtime_error {
public:
    explicit FileSystemWatcherError(const QString& message) : std::runtime_error(message.toStdString().c_str()) {};
};

class FileSystemWatcher : public AbstractFileSystemWatcher {
Q_OBJECT

private:
    class PrivateData;

    std::shared_ptr<PrivateData> d;

public:
    explicit FileSystemWatcher(const QString& path);

    explicit FileSystemWatcher(const QSet<QString>& paths);

    FileSystemWatcher();

public slots:

    bool enable() override;

    bool disable() override;

    void readEvents();

public:
    QSet<QString> directories();
};
