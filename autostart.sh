#!/bin/sh
monitors=$(xrandr --query | grep " connected" | wc -l)

~/.scripts/notifications/update-notify.sh &
dwmstatus &
qutebrowser &
# spotify &
discord &

if [ "$monitors" != "1" ]; then
	echo "Two monitors connected" &
	# kitty -T spotify-tui --override "font_size=16" -e spt &
	# kdeconnect-app &
fi
