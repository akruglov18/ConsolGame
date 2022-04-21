#!/bin/bash

THIS_PATH="$(realpath "$0")"
THIS_DIR="$(dirname "$THIS_PATH")"

for dir in "action" "animation" "creature" "equipment" "field" "game" "interfaces" "main" "resource_holder" "skills_graph" "tests" "utils"
do
    FILE_LIST="$(find "$THIS_DIR/$dir"| grep -E ".*(\.ino|\.cpp|\.c|\.h|\.hpp|\.hh)$")"
    echo -e "Files found to format = \n\"\"\"\n$FILE_LIST\n\"\"\""
    clang-format -i $FILE_LIST
    for file in $FILE_LIST
    do
        [ -n "$(tail -c1 $file)" ] && echo >> $file
    done
done
