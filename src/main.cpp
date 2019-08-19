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
    QSet<QString> appsDirsPaths = {
            QDir::home().absoluteFilePath("Applications"),
            QDir::home().absoluteFilePath(".local/bin"),
            "/usr/local/bin",
            "/Applications",
    };
    
    auto watcher = std::make_shared<FileSystemWatcher>(appsDirsPaths);
    auto launcher = std::make_shared<AppImageServicesLauncher>();

    AppsDir appsDir;
    appsDir.setLauncher(launcher);
    appsDir.setWatcher(watcher);

    appsDir.enable();
    return QCoreApplication::exec();
}

