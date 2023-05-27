# Cat_grep_on_my_own
## This repository contains the cat and grep commands
There are linux commands for handling files


## Cat command
The cat command reads the contents of files sequentially, orders them in the file parameter, and writes them to standard output.
To compile you need to go into the cat directory and write make in the terminal.
```
~/Cat_grep_on_my_own/cat$ make
```
After you make ./cg_cat `[<option>`] `<filename1`> `[<filename2>`]

### Example
./cg_cat ../common/t1



## Grep command
This command finds strings that match the pattern.
To compile you need to go into the grep directory and write make in the terminal.
```
~/Cat_grep_on_my_own/grep$ make
```
After you make ./cg_grep `[<option>`] `<template`> `[<filename>`] 

### Example
./cg_grep -e nec ../common/t1