#!/bin/dash

# ^c$var^ = fg color
# ^b$var^ = bg color

interval=0

# load colors
. ~/.config/chadwm/chadbar/themes/onedark

pkg_updates() {
	# updates=$(doas xbps-install -un | wc -l) # void
	updates=$(checkupdates | wc -l) # arch , needs pacman contrib
	# updates=$(aptitude search '~U' | wc -l)  # apt (ubuntu,debian etc)

	if [ "$updates" = 0 ]; then
		printf "^c$green^ fully updated"
	else
		printf "^c$green^ %s updates" "$updates"
	fi
}

battery() {
	# If this script doesn't work look at the output of upower -e and upower -d
	get_capacity="$(cat /sys/class/power_supply/BAT0/capacity)"

	printf "^c$blue^ ﴞ %s" "$get_capacity"
}

brightness() {
	printf "^c$red^  %.0f\n" "$(cat /sys/class/backlight/*/brightness)"
}

volume() {
	vol=$(pamixer --get-volume)
	is_mute=$(pamixer --get-mute)

	if [ "$is_mute" = "true" ]; then
		printf "^c$green^  %s" "$vol"
	else
		printf "^c$green^  %s" "$vol"
	fi
}

cpu() {
	cpu_val=$(grep -o "^[^ ]*" /proc/loadavg)

	printf "^c$blue^ ﴮ %s" "$cpu_val"
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
	printf "^c$blue^󱑆 %s" "$(date '+%I:%M %p ╷ %d.%m.%y') "
}

while true; do

	[ $interval = 0 ] || [ $((interval % 3600)) = 0 ] && updates=$(pkg_updates)
	interval=$((interval + 1))

	sleep 1 && xsetroot -name "$updates $(battery) $(brightness) $(volume) $(cpu) $(mem) $(clock)"
done
