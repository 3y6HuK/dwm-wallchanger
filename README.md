# Whats this?

Greetings, friends. This is my attempt to assemble the DWM environment in such a way that it can aesthetically satisfy those who would like the environment itself to change the color scheme depending on the photo on the desktop. It can work both in the automatic photo change mode and in the non-changing desktop mode. I chose the installation option for **Arch Linux** when the main system is already running, but there is no environment.

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

**ATTENTION! If suddenly the environment will freezes, put the "#" in `/usr/local/bin/startdwm.sh` before the word picom and let me know. Then I will test other versions of picom and add their installation to my script and configs.**

```
git clone https://github.com/3y6HuK/dwm-wallchanger.git && cd dwm-wallchanger && ./install.sh
```
If you do not want the computer to go into sleep mode, enter: 

```
sudo systemctl mask sleep.target suspend.target hibernate.target hybrid-sleep.target
```

**ATTENTION! This command is not in the installation script.** But it can be useful if the environment freezes after coming out of sleep mode. I have not yet found out the exact cause of this phenomenon. Perhaps this is due to the fault of one of the patches. Or because of picom.
