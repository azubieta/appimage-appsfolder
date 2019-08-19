// libraries
#include <QDir>
#include <QDebug>
#include <QMetaObject>
#include <QCommandLineParser>

// local
#include "AppsDir.h"
#include "FileSystemWatcher.h"
#include "AppImageServicesInspector.h"
#include "AppImageServicesLauncher.h"

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    auto watcher = std::make_shared<FileSystemWatcher>(QDir::home().absoluteFilePath("Applications"));
    auto launcher = std::make_shared<AppImageServicesLauncher>();

    AppsDir appsDir;
    appsDir.setLauncher(launcher);
    appsDir.setWatcher(watcher);

    appsDir.enable();

    return QCoreApplication::exec();
}

