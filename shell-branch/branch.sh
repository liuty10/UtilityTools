#!/bin/bash

[ -r ./folder ] || (echo "No folder" && echo "exit")
[ -r ./folder ] || mkdir folder

[ -r ./folder ] && echo "cd folder"

