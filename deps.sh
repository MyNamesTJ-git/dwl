#!/bin/sh
set -e

SUDO=${SUDO:-doas}
PATCH_BASE=https://codeberg.org/dwl/dwl-patches/raw/branch/main/patches
PATCHES="focusdir vanitygaps shiftview movestack"

WLROOTS=$(apk search -q 'wlroots*-dev' | sort -V | tail -n 1)

$SUDO apk add \
	build-base git wget patch pkgconf \
	wayland-dev wayland-protocols libxkbcommon-dev libinput-dev \
	"$WLROOTS" xwayland xcb-util-wm-dev \
	kitty rofi thunar librewolf swaylock \
	grim slurp wl-clipboard wlr-randr \
	brightnessctl playerctl wireplumber \
	xdg-desktop-portal xdg-desktop-portal-wlr

[ -d dwl ] || git clone https://codeberg.org/dwl/dwl.git
mkdir -p patches

for name in $PATCHES; do
	wget -q -O "patches/$name.patch" "$PATCH_BASE/$name/$name.patch"
	git -C dwl apply "../patches/$name.patch"
done

echo "Next: merge config-nord.h into dwl/config.h, then run make."
