CC = gcc
CFLAGS = -Wall -Werror -Wextra
SANITIZER = -fsanitize=address

all: cg_cat

cg_cat: cg_cat.h
	$(CC) $(CFLAGS) cg_cat.c -o cg_cat
	
test: cg_cat
	./test.sh	
	
check:
	@cppcheck *.c
	@cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	$(CC) $(CFLAGS) cg_cat.c $(SANITIZER) -o cg_cat
	@leaks --atExit -- ./cg_cat -T ../common/t1
	@rm -rf ./CPPLINT*

	
clean:
	rm -rf cg_cat
	rm -rf cg_test
	rm -rf cat_test

rebuild: clean cg_cat