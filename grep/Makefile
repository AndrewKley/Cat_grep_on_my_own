CC = gcc
CFLAGS = -Wall -Werror -Wextra
SANITIZER = -fsanitize=address

all: cg_grep

cg_grep: cg_grep.h
	$(CC) $(CFLAGS) cg_grep.c -o cg_grep
	
test: cg_grep
	./test.sh	
	
check:
	@cppcheck *.c
	@cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	$(CC) $(CFLAGS) cg_grep.c $(SANITIZER) -o cg_grep
	@leaks --atExit -- ./cg_grep -T ../common/t1
	@rm -rf ./CPPLINT*

	
clean:
	rm -rf cg_grep
	rm -rf cg_test
	rm -rf grep_test

rebuild: clean cg_grep