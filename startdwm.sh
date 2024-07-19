#!/bin/sh

#wal -R & 
$HOME/.dwm/dwmscripts/walls.sh & 
picom --animations --animation-window-mass 0.5 --animation-for-open-window zoom --animation-stiffness-tag-change 500 &
slstatus &
twmnd &
setxkbmap us,ru -option 'grp:alt_shift_toggle' &
#setxkbmap -model pc105 -layout us,ru -option grp:alt_shift_toggle &
#setxkbmap us,ru -option 'grp:caps_toggle' &
#dwmblocks &
export XCURSOR_SIZE=32 # default is 24
#exec /usr/libexec/polkit-gnome-authentication-agent-1 & # for Gentoo
exec /usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
telegram-desktop &
megasync &
discord &
exec dbus-launch --exit-with-session --sh-syntax &


	while true; do
	#Log stderr to a logfile
		dwm 2> ~/.dwm.log
	#No error logging
	#dwm >/dev/null 2>&1
	done

