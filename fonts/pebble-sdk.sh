#!/bin/sh

while true
do

    #reset
    echo "\n______________________"
    echo "***** Pebble SDK *****"
    echo "Projects:"
    echo "  1 - edgy-cl"
    echo "  2 - simple-analog"
    read project

    if [ $project -eq 1 ]; then
        path='/home/albert/pebble-projects/edgy-cl'
        cd $path
    elif [ $project -eq 2 ]; then
        path='/home/albert/pebble-projects/simple-analog'
        cd $path
    fi

    echo "**********************"
    echo "Select mode:"
    echo "  Build - 1\n  Run   - 2"
    read mode
    echo "**********************"

    if [ $mode -eq 1 ]; then
        echo "building..."
        eval pebble build


    elif [ $mode -eq 2 ]; then
        echo "Select hardware:"
        echo "  Alpite  - 1\n  Basalt  - 2\n  Chalk   - 3\n  Diorite - 4"
        read emul
        echo "**********************"
        if [ $emul -eq 1 ]; then
            echo "starting alpite emu..."
            eval pebble build
            eval pebble install --emulator aplite
        elif [ $emul -eq 2 ]; then
            echo "starting basalt emu..."
            eval pebble build
            eval pebble install --emulator basalt
        elif [ $emul -eq 3 ]; then
            echo "starting chalk emu..."
            eval pebble build
            eval pebble install --emulator chalk
        elif [ $emul -eq 4 ]; then
            echo "starting diorite emu..."
            eval pebble build
            eval pebble install --emulator diorite
        fi
    fi

done
