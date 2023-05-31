#!/bin/bash

if [ $# \< 2 ]
then
    echo "not enough champions"
else
    theme_list=("NICO" "defaultstarwars" "ETIPECH" "FIGHTER" "MINECRAFT")

    length=${#theme_list[@]}
    # generate a random index
    index=$((RANDOM % length))

    # get a random string
    flag=${theme_list[index]}

    make random-build THEME=-D\"$flag\"
    ./bonus/bonus $@
fi
