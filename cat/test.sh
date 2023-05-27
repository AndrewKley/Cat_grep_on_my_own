#!/bin/bash

echo ---Test 1---
./cg_cat ../common/t1 > cg_test
cat ../common/t1 > cat_test
diff -q cg_test cat_test

echo ---Test 2---
./cg_cat ../common/t1 ../common/t2 > cg_test
cat ../common/t1 ../common/t2 > cat_test
diff -q cg_test cat_test

echo ---Test 3---
./cg_cat -b ../common/t1 > cg_test
cat -b ../common/t1 > cat_test
diff -q cg_test cat_test

echo ---Test 4---
./cg_cat -b ../common/t1 ../common/t2 > cg_test
cat -b ../common/t1 ../common/t2 > cat_test
diff -q cg_test cat_test

echo ---Test 5---
./cg_cat -e -v ../common/t1 > cg_test
cat -e -v ../common/t1 > cat_test
diff -q cg_test cat_test

echo ---Test 6---
./cg_cat -e -v ../common/t1 ../common/t2 > cg_test
cat -e -v ../common/t1 ../common/t2 > cat_test
diff -q cg_test cat_test

echo ---Test 7---
./cg_cat -n ../common/t1 > cg_test
cat -n ../common/t1 > cat_test
diff -q cg_test cat_test

echo ---Test 8---
./cg_cat -n ../common/t1 ../common/t2 > cg_test
cat -n ../common/t1 ../common/t2 > cat_test
diff -q cg_test cat_test

echo ---Test 9---
./cg_cat -s ../common/t1 > cg_test
cat -s ../common/t1 > cat_test
diff -q cg_test cat_test

echo ---Test 10---
./cg_cat -s ../common/t1 ../common/t2 > cg_test
cat -s ../common/t1 ../common/t2 > cat_test
diff -q cg_test cat_test

echo ---Test 11---
./cg_cat -t -v ../common/t1 > cg_test
cat -t -v ../common/t1 > cat_test
diff -q cg_test cat_test

echo ---Test 12---
./cg_cat -t -v ../common/t1 ../common/t2 > cg_test
cat -t ../common/t1 ../common/t2 > cat_test
diff -q cg_test cat_test

echo ---Test 13---
./cg_cat -v ../common/t1 ../common/t2 > cg_test
cat -v ../common/t1 ../common/t2 > cat_test
diff -q cg_test cat_test

echo ---Test 14---
./cg_cat -E ../common/t1 ../common/t2 > cg_test
cat -e ../common/t1 ../common/t2 > cat_test
diff -q cg_test cat_test

echo ---Test 15---
./cg_cat -T ../common/t1 ../common/t2 > cg_test
cat -t ../common/t1 ../common/t2 > cat_test
diff -q cg_test cat_test

echo ---Test 16---
./cg_cat --number ../common/t1 ../common/t2 > cg_test
cat -n ../common/t1 ../common/t2 > cat_test
diff -q cg_test cat_test

echo ---Test 17---
./cg_cat --number-nonblank ../common/t1 ../common/t2 > cg_test
cat -b ../common/t1 ../common/t2 > cat_test
diff -q cg_test cat_test

echo ---Test 18---
./cg_cat --squeeze-blank ../common/t1 ../common/t2 > cg_test
cat  -s ../common/t1 ../common/t2 > cat_test
diff -q cg_test cat_test
