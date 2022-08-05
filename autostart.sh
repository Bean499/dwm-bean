#!/bin/sh
monitors=$(xrandr --query | grep " connected" | wc -l)

dwmstatus &
qutebrowser &
spotify &
discord &

if [ "$monitors" != "1" ]; then
	kitty -T spotify-tui --override "font_size=16" -e spt &
	~/.scripts/notifications/update-notify.sh &
fi
