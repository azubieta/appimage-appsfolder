# Includes
SCRIPTS_DIR=$(dirname "$0")
source ${SCRIPTS_DIR}/settings.sh

if [ "$EUID" -ne 0 ]; then
  # Non root installation
  systemctl --user disable $SYSTEMD_SERVICE_NAME
else
  # Root installation
  systemctl --user --global disable $SYSTEMD_SERVICE_NAME
fi

rm -v "$SYSTEMD_USER_DIR/appimage-appsdir.service"
rm -v "$BINDIR/appimage-appsdir"
