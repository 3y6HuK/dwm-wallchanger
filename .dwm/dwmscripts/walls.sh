#!/bin/sh

while true

do
#file=$(find $HOME/.dwm/wallpapers -type f | shuf -n1) 
# ~/.local/bin/wal -i $file 
wal -R
python $HOME/.dwm/dwmscripts/colors2x.py 
xrdb -merge $HOME/.Xresources 
xdotool key shift+Super+F5 
pywalfox update 
sleep 60m
done &
