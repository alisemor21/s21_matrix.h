CC=gcc -g
CFLAGS=-Wall -Werror -Wextra -std=c11

all: all_functions clean

C_FILES=$(wildcard s21_*.c)
O_FILES=*.o

s21_matrix.a: all_functions
	ar rc s21_matrix.a $(O_FILES)
	ranlib s21_matrix.a

test: clean s21_matrix.a
	$(CC) $(FLAGS) s21_matrix.a check.c tests/*.c -lcheck -o test

test_linux:
	$(CC) $(FLAGS) *.c tests/*.c -lcheck -lm -lsubunit -o test-linux

gcov_report:
	mkdir -p html
	$(CC) $(FLAGS) $(C_FILES) check.c tests/*.c -lcheck -o test --coverage
	./test
	rm check*.gcda check*.gcno tests*.gcda tests*.gcno s21_help*.gcda s21_help*.gcno 
	gcov -b -l -p -c s21_*.gcno
	gcovr -o html/gcov_report.html --html --html-details
	open html/gcov_report.html
	rm *.gcno *.gcda *.gcov

all_functions: $(C_FILES)
	gcc -c $(CFLAGS) $(C_FILES)
	# gcc $(CFLAGS) main.c $(C_FILES) -o func


main: $(C_FILES)
	gcc $(CFLAGS) main.c print.c $(C_FILES)

style: clean
	mv ../materials/linters/.clang-format .
	clang-format -i *.c
	clang-format -i *.h
	clang-format -style=google -i tests/*.c
	clang-format -style=google -i tests/*.h
	clang-format -style=google -n *.c
	clang-format -style=google -n *.h
	clang-format -style=google -n tests/*.c
	clang-format -style=google -n tests/*.h
	mv .clang-format ../materials/linters/

check_style:
	mv ../materials/linters/.clang-format .
	clang-format -style=google -n *.c
	clang-format -style=google -n *.h
	clang-format -style=google -n tests/*.c
	clang-format -style=google -n tests/*.h
	mv .clang-format ../materials/linters/

clean:
	rm -rf *.o *.a test func *.gcno *.gcda *.gcov *.html *.css html/*
	# rm -d html

rebuild:
	clean all
