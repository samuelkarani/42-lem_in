#!/bin/bash
FILES=./maps/*
for f in $FILES
do
    echo $f
    ./lem_in < $f
    echo ""
done