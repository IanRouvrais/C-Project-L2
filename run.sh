
getPath () {
    functionReturn=(`ls $1`)

    echo $functionReturn

}

function compile {
    local 
    getPath "src"
    n=0
    files=()
    for c in "${!functionReturn[@]}"; do 
        echo "$c"
    done
    echo "Compiling... c files [${functionReturn}]"

}


compile
