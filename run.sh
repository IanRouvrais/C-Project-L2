#!/bin/bash


declare -A ascii_colors
ascii_colors[red]="\e[31m"
ascii_colors[green]="\e[32m"
ascii_colors[yellow]="\e[33m"
ascii_colors[blue]="\e[34m"
ascii_colors[magenta]="\e[35m"
ascii_colors[cyan]="\e[36m"
ascii_colors[white]="\e[37m"
ascii_colors[reset]="\e[0m"

function print {
    echo -e "${ascii_colors[$2]}$1${ascii_colors[reset]}"
}

function compile {
    for folder in "${folders[@]}"
    do
        print "-----------------------" blue
        echo -e "Compiling $(print "$folder" blue)"
        print "-----------------------" blue
        for file in "$folder"/*.c
        do
            echo -e "Compiling $(print "$file" blue)"
            gcc -c "$file" \
                -o "out/parts/$(basename "$file").o" \
                -Wall \
                -pedantic \
                -std=c99 \
                -O3
        done
    done
    print "-----------------------" blue
}

function link {
    print "Linking object files" green
    gcc out/parts/*.o \
        -o out/main.o \
        -Wall \
        -pedantic \
        -std=c99 \
        -O3
    print "-----------------------" green
}

function run {
    print "Running executable" green
    print "-----------------------\n" green
    time ./out/main.o
    print "-----------------------" reset
}

function clean {
    print "Cleaning up" green
    rm out/parts/*.o
    rm out/main.o
    print "-----------------------\n" green
}

function main {
    compile "${folders[@]}"
    link
    run
    clean
}

clear
folders=("src")
main