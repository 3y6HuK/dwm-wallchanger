#!/bin/bash

# Получение текущего имени пользователя
currentUser=$(whoami)

# Замена слова в файле
fileContents=$(cat $HOME/.dwm/dwmscripts/colors2x.py)
fileContents=$(echo "$fileContents" | sed "s/user/$currentUser/g")

# Запись обновлённого файла
echo "$fileContents" > $HOME/.dwm/dwmscripts/colors2x.py
