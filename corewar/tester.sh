#!/bin/bash

# execute the program ./corewar -dump 1 ../assets/champions/ebola.cor ../assets/champions/ebola.cor ../assets/champions/ebola.cor ../assets/champions/ebola.cor

#take first argument and store it in a variable
nb_arg=$# #number of arguments
#take second argument and store it in a variable

ebola=../assets/champions/tyron.cor

if [ $nb_arg -eq 1 ]
then
    ./corewar -dump 9999 ${ebola} -a 1000 ${ebola} ${ebola} ${ebola}
else
    ./corewar -dump 1 ${ebola} ${ebola} ${ebola} ${ebola}
fi
