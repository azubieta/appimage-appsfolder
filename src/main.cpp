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
    QSet<QString> appsDirs = {
            QDir::home().absoluteFilePath("Applications"),
            QDir::home().absoluteFilePath(".local/bin"),
            "/usr/local/bin",
            "/Applications",
    };
    
    auto watcher = std::make_shared<FileSystemWatcher>(appsDirs);
    auto launcher = std::make_shared<AppImageServicesLauncher>();

    AppsDir appsDir;
    appsDir.setLauncher(launcher);
    appsDir.setWatcher(watcher);

    appsDir.enable();

    return QCoreApplication::exec();
}

