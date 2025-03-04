CC=gcc
LIBS = -lgtest
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
GCCFLAGS = -Wall -Werror -Wextra -std=c++17 -pedantic
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

TARGET= s21_matrix_oop.a

SRC=$(wildcard s21_*.cc)
TEST_SRC=$(wildcard ./unit_tests/*.cc)
OBJ=$(patsubst %.cc,%.o, $(SRC))

OS= $(shell uname -s)

all: $(TARGET)

$(TARGET):
	@$(CC) $(GCCFLAGS) -c $(SRC)
	@ar rcs s21_matrix_oop.a $(OBJ)
	@ranlib s21_matrix_oop.a

test: clean $(TARGET)
ifeq ($(OS), Darwin)
	@$(CC) $(GCCFLAGS) $(GCOV_FLAGS) $(SRC) $(TEST_SRC) -o test $(LIBS) -lstdc++
else
	@$(CC) $(GCCFLAGS) $(GCOV_FLAGS) $(SRC) $(TEST_SRC) -o test $(LIBS) $(LINUX_FLAGS) -lstdc++
endif
	@./test

gcov_report: test
	@lcov -t "./gcov" -o report.info -c -d . --ignore-errors format,unsupported,inconsistent
	@lcov --remove report.info \
		"/usr/local/include/gtest/*" \
		"*v1/*" \
		--ignore-errors format -o report_filtered.info
	@genhtml --ignore-errors format,inconsistent,corrupt,category -o report/ report_filtered.info
	@open ./report/index.html

clang:
	@clang-format -i *.cc *.h
	@clang-format -i ./unit_tests/*.cc ./unit_tests/*.h

leaks: test
	@CK_FORK=no leaks --atExit -- ./test

clean:
	@rm -rf test *.o *.a *.gcda *.gcno *.info report
