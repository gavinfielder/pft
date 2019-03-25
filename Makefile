# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    printftester2000 Makefile                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:19:45 by gfielder          #+#    #+#              #
#    Updated: 2019/03/25 10:55:40 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# #######################
#      User Options
# #######################

# Name of the test executable
TEST_ONAME=test

# Maximum size of output strings to see in the test results file
TEST_FAIL_LOGGING_MAXBYTES=100

# Specify the root of your repo, where your Makefile is and where your libftprinf.a will be
LIBFTPRINTF_DIR=..

# The compile flags the tester is built with
CFLAGS=-Wall -Wextra -g -Wformat=0

# #######################
#    End User Options
# #######################

LIBFTPRINTF_NAME=libftprintf.a
CC=clang
LIB=
INC=-I.
TEST_RESULTS=test_results.txt
TEST_OUT_ACTUAL=test.mine
TEST_OUT_EXPECTED=test.libc
SRC_TEST=main.c test.c
UNIT_TEST_FILE=unit_tests.c
INDEXED_TESTS=unit_tests_indexed.c
INDEXED_BENCH=unit_tests_benched.c
TEST_DEFINES=-D OUT_ACTUAL="\"$(TEST_OUT_ACTUAL)\"" \
			 -D OUT_EXPECTED="\"$(TEST_OUT_EXPECTED)\"" \
			 -D TEST_OUTPUT_FILENAME="\"$(TEST_RESULTS)\"" \
			 -D MAX_FILE_COPY_SIZE=$(TEST_FAIL_LOGGING_MAXBYTES)

all: $(TEST_ONAME)

$(TEST_ONAME): $(SRC_TEST) $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME) test_index
	@rm -f $(TEST_OUT_ACTUAL)
	@rm -f $(TEST_OUT_EXPECTED)
	@rm -f $(TEST_RESULTS)
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(TEST_DEFINES) -o $(TEST_ONAME) $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME) $(SRC_TEST) $(INDEXED_TESTS) $(INDEXED_BENCH)
	@echo "\x1B[0;32mSuccessfully made printftester2000. Directions:\x1B[0;0m\n    ./test [from] [[to]]   for a range of tests by number,\n    ./test [string]        to run all tests starting with [string],\n    ./test                 to run all tests."

$(INDEXED_TESTS): test_index

$(INDEXED_BENCH): test_index

.INTERMEDIATE: test_index
test_index: $(UNIT_TEST_FILE)
	@echo "\x1B[33mIndexing tests..."
	@cp $(UNIT_TEST_FILE) $(INDEXED_TESTS)
	@sed -i .bak "s/return test(/return ft_printf(/g" $(INDEXED_TESTS)
	@echo "const t_unit_test g_unit_tests[] = {" >> $(INDEXED_TESTS)
	@cat $(UNIT_TEST_FILE) | grep -o "^int\s*[a-zA-Z0-9_]*(void)" | sed "s/^int\s*//g" | sed "s/(void)/,/g" | tr -d " \t\v\f" >> $(INDEXED_TESTS)
	@echo "NULL" >> $(INDEXED_TESTS)
	@echo "};" >> $(INDEXED_TESTS)
	@echo "" >> $(INDEXED_TESTS)
	@echo "const char *g_unit_test_names[] = {" >> $(INDEXED_TESTS)
	@cat $(UNIT_TEST_FILE) | grep -o "^int\s*[a-zA-Z0-9_]*(void)" | sed "s/^int\s*/\"/g    " | sed "s/(void)/\",/g" | tr -d " \t\v\f" >> $(INDEXED_TESTS)
	@echo "NULL" >> $(INDEXED_TESTS)
	@echo "};" >> $(INDEXED_TESTS)
	@echo "\x1B[33mTests indexed. Creating bench tests..."
	@cp $(UNIT_TEST_FILE) $(INDEXED_BENCH)
	@sed -i .bak "s/return test(/return printf(/g" $(INDEXED_BENCH)
	@sed -i .bak "s/(void)/_bench(void)/g" $(INDEXED_BENCH)
	@echo "const t_unit_test g_bench[] = {" >> $(INDEXED_BENCH)
	@cat $(INDEXED_BENCH) | grep -o "^int\s*[a-zA-Z0-9_]*(void)" | sed "s/^int\s*//g" | sed "s/(void)/,/g" | tr -d " \t\v\f" >> $(INDEXED_BENCH)
	@echo "NULL" >> $(INDEXED_BENCH)
	@echo "};" >> $(INDEXED_BENCH)
	@echo "" >> $(INDEXED_BENCH)
	@echo "\x1B[33mTest index and bench tests created. \x1B[1;36m$(shell cat $(UNIT_TEST_FILE) | grep -c "^int\s*[a-zA-Z0-9_]*(void)" | tr -d " \n\t") \x1B[0;33mout of $(shell cat $(UNIT_TEST_FILE) | grep -c "^\s*int\s*[a-zA-Z0-9_]*(void)" | tr -d " \n\t") tests are enabled.\x1B[0;0;0m"
	@rm -f *.bak

$(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME):
	@make -C $(LIBFTPRINTF_DIR) > /dev/null 2>&1

clean:
	@rm -f $(INDEXED_TESTS)
	@rm -f $(INDEXED_BENCH)
	@rm -f $(TEST_OUT_ACTUAL)
	@rm -f $(TEST_OUT_EXPECTED)
	@rm -f $(TEST_RESULTS)
	@rm -f *.bak

fclean:
	@make clean
	@rm -rf $(TEST_ONAME).dSYM
	@rm -rf $(TEST_ONAME)

re:
	@make fclean
	@make all
