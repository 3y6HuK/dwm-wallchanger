# Whats this?

Greetings, friends. This is my attempt to assemble the DWM environment in such a way that it can aesthetically satisfy those who would like the environment itself to change the color scheme depending on the photo on the desktop. It can work both in the automatic photo change mode and in the non-changing desktop mode. I chose the installation option for Arch Linux when the main system is already running, but there is no environment.

To enable the automatic image change mode, edit the file along the way `$HOME/.dwm/dwmscripts/walls.sh` by removing the "#" in lines 6-7 and set this character at the beginning of line 8. In line 13 (sleep), you can specify the time to change the wallpaper. Don't forget to upload your wallpapers to the `$HOME/.dwm/wallpapers` directory.

The basic set of packages and dependencies will be installed by the script. I use:
- ZSH
- slstatus (but there is dwmblocks)
- kitty
- rofi
- MegaSync
- Whatsie (Unofficial WhatsApp client)
- Telegram

And more.

# Installation
Remember, this will overwrite your previous configuration.

```
git clone https://github.com/3y6HuK/dwm-wallchanger.git && cd dwm-wallchanger && ./install.sh
```
