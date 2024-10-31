#!/bin/bash

cd ~/ && git clone https://aur.archlinux.org/yay-bin.git && cd yay-bin && makepkg -si

yay -Sy xorg-server xorg-xinit xorg-drivers python-pywal python-pywalfox xdotool kitty feh flameshot atool imagemagick perl-image-exiftool ueberzug alsa-utils dmenu rofi rofi-themes-collection-git xorg-xsetroot twmn-git ranger pipewire pipewire-alsa pipewire-jack pipewire-pulse pavucontrol pcmanfm numlockx betterlockscreen ttf-jetbrains-mono-nerd ttf-unifont ttf-liberation ttf-dejavu libev uthash libconfig telegram-desktop obs-studio thunderbird libxinerama ttf-nerd-fonts-symbols cppcheck neovim meson ninja picom-simpleanims-netx-git whatsapp-for-linux polkit-gnome tokyonight-gtk-theme-git kora-icon-theme nwg-look zsh zsh-syntax-highlighting zsh-autosuggestions  oh-my-zsh-git zsh-fast-syntax-highlighting-git imlib2 npm make cmake btop gamemode icoutils firefox firefox-adblock-plus firefox-i18n-ru discord cherrytree paccache-hook grub-hook megasync-bin --noconfirm

cp -r ~/dwm-wallchanger/.dwm ~/
cp -r ~/dwm-wallchanger/.zshrc ~/
cp -r ~/dwm-wallchanger/.config ~/
sudo cp ~/dwm-wallchanger/startdwm.sh /usr/local/bin/
sudo echo "exec /usr/local/bin/startdwm.sh" > ~/.xinitrc
sudo chmod +x /usr/local/bin/startdwm.sh

cd ~/.dwm && sudo make clean install
cd ~/.dwm/slstatus && sudo make clean install

cd ~/dwm-wallchanger && ./change_name.sh

chsh -s /bin/zsh
sudo chsh -s /bin/zsh

startx
