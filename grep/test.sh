#!/bin/bash

test_1=../common/t1
test_2=../common/t2
test_3=../common/t3
header=../common/header.h
flags=(e i v c l n h o)

for flag in ${flags[*]} 
do
    echo ---test $flag---
    ./cg_grep -$flag nec $test_1 > cg_test
    grep -$flag nec $test_1 > grep_test
    if diff cg_test grep_test; then
        echo "SUCCESS"
    else
        echo "FAIL"
    fi
done

echo ---test f---
./cg_grep -f $test_3 $header > cg_test
grep -f $test_3 $header > grep_test
if diff cg_test grep_test; then
    echo "SUCCESS"
else
    echo "FAIL" 
fi

echo ---test s---
./cg_grep -s $test_3 $header.qwer > cg_test
grep -s $test_3 $header.qwer > grep_test
if diff cg_test grep_test; then
    echo "SUCCESS"
else
    echo "FAIL" 
fi

echo ---test i with n---
./cg_grep -in qwe $test_1 $test_2 > cg_test
grep -in qwe $test_1 $test_2 > grep_test
if diff cg_test grep_test; then
    echo "SUCCESS"
else
    echo "FAIL" 
fi

echo ---test i with e---
./cg_grep -ie qwe $test_1 $test_2 > cg_test
grep -ie qwe $test_1 $test_2 > grep_test
if diff cg_test grep_test; then
    echo "SUCCESS"
else
    echo "FAIL" 
fi

echo ---test n with c---
./cg_grep -nc qwe $test_1 $test_2 > cg_test
grep -nc qwe $test_1 $test_2 > grep_test
if diff cg_test grep_test; then
    echo "SUCCESS"
else
    echo "FAIL" 
fi

echo ---test n with v---
./cg_grep -nv qwe $test_1 $test_2 > cg_test
grep -nv qwe $test_1 $test_2 > grep_test
if diff cg_test grep_test; then
    echo "SUCCESS"
else
    echo "FAIL" 
fi