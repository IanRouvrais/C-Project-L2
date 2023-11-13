#!/bin/bash

``` 
    This script is used to compile and run the program.
    It is also used to clean up the object files and the executable.
```

# Ascii code for colors in echo
declare -A ascii_colors
ascii_colors[red]="\e[31m"
ascii_colors[green]="\e[32m"
ascii_colors[yellow]="\e[33m"
ascii_colors[blue]="\e[34m"
ascii_colors[magenta]="\e[35m"
ascii_colors[cyan]="\e[36m"
ascii_colors[white]="\e[37m"
ascii_colors[black]="\e[30m"
ascii_colors[gray]="\e[90m"
ascii_colors[reset]="\e[0m"

ascii_colors[bold]="\e[1m"
ascii_colors[underline]="\e[4m"
ascii_colors[reversed]="\e[7m"

ascii_colors[bg_yellow]="\e[43m"
ascii_colors[bg_green]="\e[42m"
ascii_colors[bg_blue]="\e[44m"
ascii_colors[bg_magenta]="\e[45m"
ascii_colors[bg_cyan]="\e[46m"
ascii_colors[bg_white]="\e[47m"
ascii_colors[bg_black]="\e[40m"



# Function to print stylised text
function print {
    local text="$1${ascii_colors[reset]}"
    shift
    local color
    for color in "$@"
    do
        text="${ascii_colors[$color]}$text"
    done
    echo -e "$text"
}

function log {
    echo -e "$(print "[$(date +%F_%T)]" gray) $1"
}

function separate {
    print "·-------------------·" gray bold
}

# Function to compile all files separately in a folder
function compile {
    for folder in "${folders[@]}"
    do
        separate
        log "Compiling $(print "$folder" blue)"
        separate
        for file in "$folder"/*.c
        do
            log "Compiling $(print "$file" blue)"
            gcc -c "$file" \
                -o "out/parts/$(basename "$file").o" \
                -Wall \
                -pedantic \
                -std=c99 \
                -O3
        done
    done
    print $(separate) blue
}
# Function to link all object files into one executable
function link {
    log $(print "Linking object files" green)
    gcc out/parts/*.o \
        -o out/main.exe \
        -Wall \
        -pedantic \
        -std=c99 \
        -O3
    separate
}

# Function to run the executable
function run {
    log $(print "Running executable" green)
    separate
    echo ""
    time ./out/main.exe
    separate
}

# Function to clean up all object files and the executable
function clean {
    log $(print "Cleaning up" green)
    rm out/parts/*.o
    rm out/main.exe
    separate
}

# Main function
function main {
    clear
    sleep 0.2
    compile "${folders[@]}"
    link
    run
    clean
}




folders=("src")
main
