#!/bin/bash

display_usage() {
  echo
  echo "Usage: $0"
  echo
  echo " -h, --help   Display usage instructions"
  echo
  echo " self-install, Install appimage-appsdir on the system"
  echo " self-uninstall, Uninstall appimage-appsdir from the system"
  echo
}

raise_error() {
  local error_message="$@"
  echo "${error_message}" 1>&2
}

# environment setup
export PATH=$PATH:$APPDIR/usr/bin

if [ "$EUID" -ne 0 ]; then
  # Non root installation
  BINDIR=$HOME/.local/bin
  CONFIG_DIR=$HOME/.config
else
  # Root installation
  BINDIR=/usr/local/bin
  CONFIG_DIR=/etc
fi

SYSTEMD_USER_DIR=$CONFIG_DIR/systemd/user

# arguments parsing
command="$1"
if [[ -z $command ]]; then
  $APPDIR/usr/bin/appimage-appsdir
else
  case $command in
  -h | --help)
    display_usage
    ;;
  self-install)
    "$APPDIR/usr/bin/self-install.sh"
    ;;
  self-uninstall)
    "$APPDIR/usr/bin/self-uninstall.sh"
    ;;
  *)
    raise_error "Unknown command: ${command}"
    display_usage
    ;;
  esac
fi
