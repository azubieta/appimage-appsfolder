// library
#include <QDebug>
#include <QtConcurrent/QtConcurrent>

// local
#include "AppsDir.h"

void AppsDir::setLauncher(std::shared_ptr<AbstractLauncher> launcher) {
    AppsDir::launcher = launcher;
}

void AppsDir::setWatcher(std::shared_ptr<AbstractFileSystemWatcher> watcher) {
    if (watcher)
        disconnect(watcher.get(), nullptr, this, nullptr);

    AppsDir::watcher = watcher;

    connect(watcher.get(), &AbstractFileSystemWatcher::fileChanged, this, &AppsDir::onFileChanged);
    connect(watcher.get(), &AbstractFileSystemWatcher::fileRemoved, this, &AppsDir::onFileRemoved);
}

void AppsDir::enable() {
    watcher->enable();
    for (const QString& appDirPath : watcher->directories())
        QtConcurrent::run(updateAppsRegistration, appDirPath, launcher);
}

void AppsDir::disable() {
    watcher->disable();
}

void AppsDir::onFileChanged(const QString& filePath) {
    qDebug() << "Registering app: " << filePath;
    bool succeed = launcher->registerApp(filePath);
    if (!succeed)
        qWarning() << "Unable to register app: " << filePath;
}

void AppsDir::onFileRemoved(const QString& filePath) {
    qDebug() << "Unregistering app: " << filePath;
    bool succeed = launcher->unregisterApp(filePath);
    if (!succeed)
        qWarning() << "Unable to unregister app: " << filePath;
}

void AppsDir::updateAppsRegistration(const QString& appDirPath, std::shared_ptr<AbstractLauncher> launcher) {
    QDir appDir(appDirPath);
    QStringList allFiles = appDir.entryList(
            QDir::NoDotAndDotDot | QDir::System | QDir::Hidden | QDir::Files, QDir::DirsFirst);

    for (const QString& filePath: allFiles) {
        QString absoluteFilePath = appDir.absoluteFilePath(filePath);
        launcher->registerApp(absoluteFilePath);
    }
}
