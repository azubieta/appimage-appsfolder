#pragma once
// system

//libraries

//local
#include <AbstractFileSystemWatcher.h>


class FakeFileSystemWatcher : public AbstractFileSystemWatcher {
Q_OBJECT
public:

    bool enable() override;

    bool disable() override;

    void emitFileChanged(const QString& path);

    void emitFileRemoved(const QString& path);

    QSet<QString> directories() override;

private:
    bool wasEnableCalled = false;
    bool wasDisableCalled = false;
};



