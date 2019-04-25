# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    printftester2000 Makefile                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:19:45 by gfielder          #+#    #+#              #
#    Updated: 2019/04/25 16:49:21 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------------------------------------------------------------------------
#      User Options
# ------------------------------------------------------------------------------

# Set to 1 if you do not include your libft .o's in your libftprintf
USE_SEPARATE_LIBFT=0
LIBFT_DIR_PATH=../libft
LIBFT_NAME=libft.a

# Set to 1 to ignore return value
IGNORE_RETURN_VALUE=0

# Name of the test executable
TEST_ONAME=test

# Maximum size of output strings to see in the test results file
TEST_FAIL_LOGGING_MAXBYTES=150

# Specify the root of your repo, where your Makefile is and where your libftprinf.a will be
LIBFTPRINTF_DIR=..

# The compile flags the tester is built with
CFLAGS=-Wall -Wextra -g

# ------------------------------------------------------------------------------
#      End User Options
# ------------------------------------------------------------------------------

LIBFTPRINTF_NAME=libftprintf.a
CC=clang
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
			 -D MAX_FILE_COPY_SIZE=$(TEST_FAIL_LOGGING_MAXBYTES) \
			 -D IGNORE_RETURN_VALUE=$(IGNORE_RETURN_VALUE)
ifeq ($(USE_SEPARATE_LIBFT),1)
LIB=$(LIBFT_DIR_PATH)/$(LIBFT_NAME)
else
LIB=
endif

all: $(TEST_ONAME)

$(TEST_ONAME): $(SRC_TEST) $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME) $(LIB) test_index
	@rm -f $(TEST_OUT_ACTUAL)
	@rm -f $(TEST_OUT_EXPECTED)
	@rm -f $(TEST_RESULTS)
	@$(CC) $(CFLAGS) $(INC) $(TEST_DEFINES) -o $(TEST_ONAME) $(LIB) $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME) $(SRC_TEST) $(INDEXED_TESTS) $(INDEXED_BENCH)
	@echo "\x1B[32m=============================================================\x1B[0m"
	@echo "\x1B[32m  printftester2000 (aka PFT)\x1B[0m - \x1B[2mmade by gfielder@42.us.org\x1B[0m"
	@echo "\x1B[32m=============================================================\x1B[0m"
	@echo "  \x1B[1;36m$(shell cat $(UNIT_TEST_FILE) | grep -c "^int\s*[a-zA-Z0-9_]*(void)" | tr -d " \n\t") \x1B[0mout of \x1B[1;33m$(shell cat $(UNIT_TEST_FILE) | grep -c "^\s*int\s*[a-zA-Z0-9_]*(void)" | tr -d " \n\t")\x1B[0m tests are enabled.\x1B[0;0;0m"
	@echo "  \x1B[4mDirections\x1B[0m:"
	@echo "    \x1B[36m./test [query]\x1B[0m          to run tests"
	@echo "    \x1B[36m./test help\x1B[0m             to see examples"
	@echo "    \x1B[36m./test help all\x1B[0m         to see extended help information"


$(INDEXED_TESTS): test_index

$(INDEXED_BENCH): test_index

.INTERMEDIATE: test_index
test_index: $(UNIT_TEST_FILE)
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
	@echo "const char *g_unit_test_first_lines[] = {" >> $(INDEXED_TESTS)
	@cat $(UNIT_TEST_FILE) | grep "^int\s*[a-zA-Z0-9_]*(void)" | sed "s/int\s*.*(void){//g" | sed "s/}//g" | sed "s/\"/\\\\\"/g" | sed "s/\\\\\\\\\"/\\\\\"/g" | sed "s/\(.*\)/\"\1\",/g" >> $(INDEXED_TESTS)
	@echo "NULL" >> $(INDEXED_TESTS)
	@echo "};" >> $(INDEXED_TESTS)
	@cp $(UNIT_TEST_FILE) $(INDEXED_BENCH)
	@sed -i .bak "s/return test(/return printf(/g" $(INDEXED_BENCH)
	@sed -i .bak "s/(void)/_bench(void)/g" $(INDEXED_BENCH)
	@echo "const t_unit_test g_bench[] = {" >> $(INDEXED_BENCH)
	@cat $(INDEXED_BENCH) | grep -o "^int\s*[a-zA-Z0-9_]*(void)" | sed "s/^int\s*//g" | sed "s/(void)/,/g" | tr -d " \t\v\f" >> $(INDEXED_BENCH)
	@echo "NULL" >> $(INDEXED_BENCH)
	@echo "};" >> $(INDEXED_BENCH)
	@echo "" >> $(INDEXED_BENCH)
	@rm -f *.bak

$(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME):
	@make -C $(LIBFTPRINTF_DIR) > /dev/null 2>&1

$(LIBFT_DIR_PATH)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR_PATH) > /dev/null 2>&1

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
	@make -C $(LIBFTPRINTF_DIR) fclean > /dev/null 2>&1
	@make fclean
	@make all
