#!/usr/bin/env bash

# ^c$var^ = fg color
# ^b$var^ = bg color

interval=0

# load colors
. ~/.config/chadwm/chadbar/themes/onedark

pkg_updates() {
	# updates=$(doas xbps-install -un | wc -l) # void
	updates=$(checkupdates | wc -l) # arch , needs pacman-contrib
	# updates=$(aptitude search '~U' | wc -l)  # apt (ubuntu,debian etc)

	printf "^c$green^  %02d" $updates
}

battery() {
	# If this script doesn't work look at the output of upower -e and upower -d
	get_capacity="$(cat /sys/class/power_supply/BAT0/capacity)"

	printf "^c$blue^ 󰠠 %s" "$get_capacity"
}

brightness() {
	printf "^c$red^  %.0f\n" "$(cat /sys/class/backlight/*/brightness)"
}

volume() {
	vol=$(pamixer --get-volume)
	is_mute=$(pamixer --get-mute)

	if [ "$is_mute" = "true" ]; then
		printf "^c$green^ 󰝚 mute"
	else
		printf "^c$green^ 󰝚 %s" "$vol"
	fi
}

cpu() {
	cpu_val=$(grep -o "^[^ ]*" /proc/loadavg)

	printf "^c$blue^ 󰠰 %s" "$cpu_val"
}

mem() {
	printf "^c$red^   %s" "$(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g)"
}

wlan() {
	case "$(cat /sys/class/net/wl*/operstate 2>/dev/null)" in
	up) printf "^c$black^ ^b$blue^ 󰤨 ^d^%s" " ^c$blue^Connected" ;;
	down) printf "^c$black^ ^b$blue^ 󰤭 ^d^%s" " ^c$blue^Disconnected" ;;
	esac
}

clock() {
	printf "^c$blue^ %s" "$(date '+%H:%M:%S ╷ %d.%m.%Y | %a') "
}

while true; do
	[ $interval = 0 ] || [ $((interval % 60)) = 0 ] && updates=$(pkg_updates)
	interval=$((interval + 1))

	sleep 1 && xsetroot -name "$(n-mortality) $updates $(volume) $(cpu) $(mem) $(clock)"
done
