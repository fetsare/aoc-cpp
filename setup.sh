#!/bin/bash

mkdir -p bin src

for day in {1..25}; do
    DAY=$(printf "%02d" $day)
    DAY_DIR="src/day$DAY"
    
    echo "creating $DAY_DIR..."
    mkdir -p "$DAY_DIR"
    
    sed "s/DAY/$DAY/g" template.cpp > "$DAY_DIR/solution.cpp"
    
    touch "$DAY_DIR/test_input.txt"
    touch "$DAY_DIR/input.txt"
done