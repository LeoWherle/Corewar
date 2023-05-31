#!/bin/bash

if [ $# \< 2 ]
then
    echo "not enough champions"
    echo "USAGE"
    echo "    ./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...\n"
    echo "DESCRIPTION"
    echo "    -dump nbr_cycle dumps the memory after the nbr_cycle execution (if the round isn't already over) with the following format: 32 bytes/line"
    echo "    in hexadecimal (A0BCDEFE1DD3...)"
    echo "    -n prog_number sets the next program's number. By default, the first free number in the parameter order"
    echo "    -a load_address sets the next program's loading address. When no address is specified, optimize the addresses so that the processes are as far away from each other as possible. The addresses are MEM_SIZE modulo."
else
    theme_list=("NICO" "defaultstarwars" "ETIPECH" "FIGHTER" "MINECRAFT" "FF7")

    length=${#theme_list[@]}
    # generate a random index
    index=$((RANDOM % length))

    # get a random string
    flag=${theme_list[index]}

    make random-build THEME=-D\"$flag\"
    ./bonus/bonus $@
fi
