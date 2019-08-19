//
// Created by alexis on 17/08/19.
//

#pragma once
// system
#include <memory>

//libraries
#include <QtCore/QDir>

//local
#include "AbstractLauncher.h"
#include "AbstractFileSystemWatcher.h"

class AppsDir : public QObject {
Q_OBJECT

public:

    void setLauncher(std::shared_ptr<AbstractLauncher> launcher);

    void setWatcher(std::shared_ptr<AbstractFileSystemWatcher> watcher);

public slots:

    void enable();

    void disable();

private slots:

    void onFileChanged(const QString& filePath);

    void onFileRemoved(const QString& filePath);

private:
    std::shared_ptr<AbstractLauncher> launcher;
    std::shared_ptr<AbstractFileSystemWatcher> watcher;
};



