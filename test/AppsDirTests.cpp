// system
#include <memory>

// libraries
#include <QObject>
#include <QTest>

// local
#include "AppsDir.h"
#include "FakeLauncher.h"
#include "FakeFileSystemWatcher.h"

class AppsDirTests : public QObject {
Q_OBJECT
public:
    explicit AppsDirTests() : QObject() {}


public:

private slots:

    void testRegister() {
        auto watcher = std::make_shared<FakeFileSystemWatcher>();
        auto launcher = std::make_shared<FakeLauncher>();

        AppsDir appsDir;
        appsDir.setLauncher(launcher);
        appsDir.setWatcher(watcher);

        appsDir.enable();

        watcher->emitFileChanged("path");
        QVERIFY(launcher->isRegisterAppCalled());
    }

    void testUnregister() {
        auto watcher = std::make_shared<FakeFileSystemWatcher>();
        auto launcher = std::make_shared<FakeLauncher>();

        AppsDir appsDir;
        appsDir.setLauncher(launcher);
        appsDir.setWatcher(watcher);

        appsDir.enable();

        watcher->emitFileRemoved("path");
        QVERIFY(launcher->isUnregisterAppCalled());
    }
};

int main(int argc, char* argv[]) {
    AppsDirTests appsDirTests;
    QCoreApplication app(argc, argv);
    app.setAttribute(Qt::AA_Use96Dpi, true);
    QTEST_SET_MAIN_SOURCE_PATH
    return QTest::qExec(&appsDirTests, argc, argv);
}


#include "AppsDirTests.moc"