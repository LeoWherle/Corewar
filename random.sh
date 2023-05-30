#!/bin/bash

# List of strings

##### ALL SHOULD BE SAME LENGTH #####
click=("clickpress.ogg" "clickpress.ogg" "clickpress.ogg")
clickrelease=("clickrelease.ogg" "clickrelease.ogg" "clickrelease.ogg")
Championfont=("Galaxy.ttf" "Galaxy.ttf" "Galaxy.ttf")
Textfont=("Starjedi.ttf" "Starjedi.ttf" "Starjedi.ttf")
logo=("logo.png" "logo.png" "logo.png")
music=("music.ogg" "music.ogg" "music.ogg")

##### GLOBAL FOR ALL #####
length=${#click[@]}
# generate a random index
index=$((RANDOM % length))

# get a random string
rand_click=${click[index]}
rand_clickrelease=${clickrelease[index]}
rand_Championfont=${Championfont[index]}
rand_Textfont=${Textfont[index]}
rand_logo=${logo[index]}
rand_music=${music[index]}


echo "make CLICK=$rand_click"

# make bonus CLICK=$rand_click
