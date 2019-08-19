// local
#include "FakeFileSystemWatcher.h"

void FakeFileSystemWatcher::emitFileChanged(const QString& path) {
    emit AbstractFileSystemWatcher::fileChanged(path);
}

void FakeFileSystemWatcher::emitFileRemoved(const QString& path) {
    emit AbstractFileSystemWatcher::fileRemoved(path);
}

bool FakeFileSystemWatcher::disable() {
    wasDisableCalled = true;
    return true;
}

bool FakeFileSystemWatcher::enable() {
    wasEnableCalled = true;
    return true;
}

QSet<QString> FakeFileSystemWatcher::directories() {
    return QSet<QString>();
}
