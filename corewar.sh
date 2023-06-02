#!/bin/bash

BLACK="\033[0;30m"
RED="\033[1;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
MAGENTA="\033[1;35m"
CYAN="\033[0;36m"
WHITE="\033[1;37m"
RESET="\033[0m"

if [ $# \< 2 ]
then
    printf $RED"Error:$RESET not enough champions\n"
    printf $WHITE"USAGE\n"$RESET
    printf "    ./corewar [$GREEN-dump$RESET nbr_cycle] $MAGENTA[$RESET[$GREEN-n$RESET prog_number] [$GREEN-a$RESET load_address] prog_name$MAGENTA]$RESET ...\n"
    printf $WHITE"DESCRIPTION\n"$RESET
    printf "   $GREEN -dump$RESET nbr_cycle dumps the memory after the nbr_cycle execution (if the round isn't already over) with the following format: 32 bytes/line\n"
    echo "    in hexadecimal (A0BCDEFE1DD3...)"
    printf "   $GREEN -n$RESET prog_number sets the next program's number. By default, the first free number in the parameter order\n"
    printf "   $GREEN -a$RESET load_address sets the next program's loading address. When no address is specified, optimize the addresses so that the processes are as far away from each other as possible. The addresses are MEM_SIZE modulo.\n"
else
    theme_list=("NICO" "defaultstarwars" "ETIPECH" "FIGHTER" "MINECRAFT" "FF7" "THUG" "AVENGERS" "MARIO" "JESUS" "PERSONA")

    length=${#theme_list[@]}
    # generate a random index
    index=$((RANDOM % length))

    # get a random string
    flag=${theme_list[index]}

    make random-build THEME=-D\"$flag\"
    ./bonus/bonus $@
fi
