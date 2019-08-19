#!/usr/bin/env bash

# Includes
SCRIPTS_DIR=$(dirname "$0")
source ${SCRIPTS_DIR}/settings.sh

echo "Installing binary"
mkdir -p $APPIMAGE $BINDIR
cp -v $APPIMAGE $BINDIR/appimage-appsdir

echo "Installing systemd service to $SYSTEMD_SERVICE_FILE"

mkdir -p $SYSTEMD_USER_DIR
cat >"$SYSTEMD_SERVICE_FILE" <<EOF
[Unit]
Description=AppImage Apps Dir

[Service]
ExecStart=$BINDIR/appimage-appsdir
Restart=on-failure
RestartSec=10

[Install]
WantedBy=default.target
EOF

if [ "$EUID" -ne 0 ]; then
  # Non root installation
  systemctl --user daemon-reload
  systemctl --user enable $SYSTEMD_SERVICE_NAME
  systemctl --user restart $SYSTEMD_SERVICE_NAME
else
  # Root installation
  systemctl daemon-reload
  systemctl --user --global enable $SYSTEMD_SERVICE_NAME

  echo ""
  echo "Please run the following commmand to start the appsdir services on your user space"
  echo "systemctl --user restart $SYSTEMD_SERVICE_NAME"
fi
