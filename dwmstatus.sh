#!/usr/bin/env bash

while true
do
	# Battery
	battpercent=$(acpi -b | grep -P -o '[0-9]+(?=%)')
	charging=$(acpi -b | grep -o -F "Charging")
	discharging=$(acpi -b | grep -o -F "Discharging")
	if [ "$charging" == "Charging" ]; then
		battsymbol=""
	elif [ "$discharging" == "Discharging" ]; then
		battsymbol=""
	else
		battsymbol=""
	fi
	batt="$battsymbol $battpercent%"

	# Time
	date=" $(date +%d/%m/%Y)"
	time=" $(date +%H:%M:%S)"

	# Volume
	volpercent=$(pamixer --get-volume-human)
	if [ "$volpercent" == "muted" ]; then
		volpercent="M"
	fi
	vol="墳 $volpercent"

	# Song
	song=$(playerctl metadata title)

	if [ "$song" == "" ]; then
		text=" $vol  $batt  $date  $time "
	else
		song=" $song"
		text=" $song  $vol  $batt  $date  $time "
	fi

	xsetroot -name "$text"
	sleep 0.5
done
