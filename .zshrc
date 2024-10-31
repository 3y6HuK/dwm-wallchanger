#!/usr/bin/sh

[[ -z $DISPLAY && $XDG_VTNR -eq 1 ]] && exec startx

ZSH=/usr/share/oh-my-zsh/

# ZSH_THEME="robbyrussell"
# ZSH_THEME="oxide"
# ZSH_THEME="refined"
ZSH_THEME="af-magic"
DISABLE_AUTO_UPDATE="true"
plugins=(
)
export PATH=$HOME/.bin:$HOME/.bin/popup:$HOME/.local/bin:/usr/local/bin:$PATH
ZSH_CACHE_DIR=$HOME/.cache/oh-my-zsh
[[ ! -d $ZSH_CACHE_DIR ]] && mkdir $ZSH_CACHE_DIR
source $ZSH/oh-my-zsh.sh
source /usr/share/zsh/plugins/fast-syntax-highlighting/fast-syntax-highlighting.plugin.zsh
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
# ZSH_AUTOSUGGEST_HIGHLIGHT_STYLE="fg=white"

# fzf & fd
[[ -e "/usr/share/fzf/fzf-extras.zsh" ]] && source /usr/share/fzf/fzf-extras.zsh
export FZF_DEFAULT_COMMAND="fd --type file --color=always --follow --hidden --exclude .git"
export FZF_CTRL_T_COMMAND="$FZF_DEFAULT_COMMAND"
# export FZF_DEFAULT_OPTS="--ansi"
export FZF_DEFAULT_OPTS="--height 50% --layout=reverse --border --preview 'file {}' --preview-window down:1"
export FZF_COMPLETION_TRIGGER="~~"

# export TERM="xterm-kitty"
# export TERM="rxvt-unicode"
# export TERM="rxvt-unicode-256color"
export TERM="xterm-256color"
export EDITOR="$(if [[ -n $DISPLAY ]]; then echo 'subl3'; else echo 'nano'; fi)"
export BROWSER="firefox"
export SSH_KEY_PATH="~/.ssh/dsa_id"
export XDG_CONFIG_HOME="$HOME/.config"

[[ -f ~/.alias_zsh ]] && . ~/.alias_zsh

export PF_INFO="ascii os kernel wm shell pkgs memory palette"

export PATH=$HOME/.gem/ruby/2.6.0/bin:$PATH
# export PATH="$PATH:`yarn global bin`"
# export NVM_DIR="$HOME/.config/nvm"
# [ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
# [ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

ctrl_l() {
          builtin print -rn -- $'\r\e[0J\e[H\e[22J' >"$TTY"
          builtin zle .reset-prompt
          builtin zle -R
      }
      zle -N ctrl_l
      bindkey '^l' ctrl_l

# Import colorscheme from 'wal' asynchronously
# &   # Run the process in the background.
# ( ) # Hide shell job control messages.
(cat ~/.cache/wal/sequences &)

# Alternative (blocks terminal for 0-3ms)
cat ~/.cache/wal/sequences

# To add support for TTYs this line can be optionally added.
source ~/.cache/wal/colors-tty.sh

HISTCONTROL=ignorespace

fastfetch
df -h /
alias ex='export DISPLAY=:0.0'
alias pm='sudo pm-suspend'
alias gu='sudo grub-mkconfig -o /boot/grub/grub.cfg'
alias cl1='pacman -Qdt'
alias cl2='sudo pacman -Rsn $(pacman -Qdtq)'
alias cl3='paccache -rk2'
alias res='sudo systemctl restart sddm'
alias rf='sudo reboot -f'
alias rec='ffmpeg -f alsa -i pulse -f x11grab -r 25 -s 1920x1080 -i :0+0,60 -acodec pcm_s16le -vcodec libx264 -threads 0 output.mkv'
alias yun='yay -Syu --noconfirm'
alias yu='yay -Syu'
alias gt='gpgtar_v3.sh'
alias dssh='delete_line_from_file.sh'
alias dis='xset dpms force standby'
alias ipi='curl smart-ip.net/myip'
alias ipmy='curl eth0.me'
alias moon="curl 'wttr.in/Moon'"
alias tcs='sudo torctl start'
alias tcr='sudo torctl restart'
alias tcstop='sudo torctl stop'
alias swap='sudo swapoff -a && sudo swapon -a && systemctl start /dev/zram0'
alias mrec='arecord -f cd output_stereo.wav'
alias ipi='curl smart-ip.net/myip'
alias wtr='wget -O - wttr.in/"Khabarovsk" -q'
alias yt='ytfzf -t'
alias nano='sudo nano'
alias list="qlist -I | grep"
alias kino='sh /home/freedomsky/INSTALL/Torrserver/kino_test.sh'
alias sr='sudo ranger'
alias rr='ranger'
alias pw='pywalfox update'
alias kb='setxkbmap -model pc105 -layout us,ru -option grp:alt_shift_toggle'
alias v='nvim'
alias sv='sudo nvim'
alias m='micro'
alias sm='sudo micro'

# Очистка терминала
alias c='clear'

# Обновление системы

alias up='sudo pacman -Syyuu'

#Для VPN torctl (ставится из репозитория blackarch)

alias tstart='sudo torctl start' 
alias tstop='sudo torctl stop' 
alias trestart='sudo torctl restart' 

#Обновление grub
alias upgrub='sudo grub-mkconfig -o /boot/grub/grub.cfg'

#Файловый менеджер MC
alias mcr='sudo mc'

#Установка через pacman
alias ins='sudo pacman -Sy'
alias inss='sudo pacman -Ss'
alias rem='sudo pacman -R'
alias remc='sudo pacman -Rc'
alias remd='sudo pacman -Rns'
alias vidup='sudo pacman -S nvidia nvidia-utils lib32-nvidia-utils nvidia-settings nvidia-dkms'
alias zst='sudo pacman -U'
alias wget='wget -c -T 5'

#Выключение и перезагрузка
alias r='reboot'
alias s='shutdown -h now'

#Доступ по shh

alias sshon='systemctl start sshd'
alias sshoff='systemctl stop sshd'

#Обвноение зеркал

alias ref='sudo reflector -c ru,jp,cn,hk,kr -p https --sort rate -a 12 -l 10 --save /etc/pacman.d/mirrorlist'
alias upm='rankmirrors -t /etc/pacman.d/mirrorlist'

alias kws='sh "/home/freedomsky/MEGA/INSTALL/KillWineServer.sh"'

#Запись консоли
alias arec='asciinema rec'

#Установка ядра Xanmod
alias xanmod='yay -S linux-xanmod linux-xanmod-headers'

