# Whats this?

Greetings, friends. This is my attempt to assemble the DWM environment in such a way that it can aesthetically satisfy those who would like the environment itself to change the color scheme depending on the photo on the desktop. It can work both in the automatic photo change mode and in the non-changing desktop mode. I chose the installation option for Arch Linux when the main system is already running, but there is no environment.

To enable the automatic image change mode, edit the file along the way `$HOME/.dwm/dwmscripts/walls.sh` by removing the "#" in lines 6-7 and set this character at the beginning of line 8. In line 13 (sleep), you can specify the time to change the wallpaper.

Run the command `mkdir -p $HOME/.dwm/wallpapers` and download the wallpaper using this path.
