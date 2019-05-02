# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    printftester2000 Makefile                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:19:45 by gfielder          #+#    #+#              #
#    Updated: 2019/05/02 01:51:14 by gfielder         ###   ########.fr        #
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

# Set the number of seconds to timeout on each test, when timeout is used
TIMEOUT_SECONDS=0.75

# Sets default program behavior; can be overridden with command line arguments
DEFAULT_RUN_OPTIONS=Aflopstx

# Sets the number of seconds for a test history to be considered 'outdated'
TEST_OUTDATED_TIME=900

# Name of the test executable
TEST_ONAME=test

# Maximum size of output strings to see in the test results file
TEST_FAIL_LOGGING_MAXBYTES=150

# The compile flags the tester is built with
CFLAGS=-Wall -Wextra -g

# Specify the root of your repo, where your Makefile is and where your libftprinf.a will be
LIBFTPRINTF_DIR=..

# This is the name required by the subject, so I doubt you'd want to change it
LIBFTPRINTF_NAME=libftprintf.a

# When 1, ./test 824 runs test 824 only. When 0, ./test 824 runs 824-[end]
SINGLE_NUMBER_SINGLE_TEST=1

#     Note setting the option above to 0 disables the next option:

# When 1, ./test 824 runs the test in LLDB compatibility mode by default
SINGLE_TEST_TURNS_ON_LLDB_COMPAT_MODE=1

# ------------------------------------------------------------------------------
#      End User Options
# ------------------------------------------------------------------------------

CC=clang
INC=-I src
TEST_LOG=test_history.csv
TEST_RESULTS=test_results.txt
TEST_OUT_ACTUAL=test.mine
TEST_OUT_EXPECTED=test.libc
SRC_TEST=src/main.c src/test.c src/test_print_and_utils.c src/ft_options.c \
		 src/help.c src/ft_destroy_nullterm_ptrarray.c src/ft_strsplit.c \
		 src/history.c
UNIT_TEST_FILE=unit_tests.c
INDEXED_TESTS=src/unit_tests_indexed.c
NUMBER_OF_TESTS=$(shell cat $(UNIT_TEST_FILE) | grep -c "^\s*int\s*[a-zA-Z0-9_]*(void)" | tr -d " \n\t")
TEST_DEFINES=-D OUT_ACTUAL="\"$(TEST_OUT_ACTUAL)\"" \
			 -D OUT_EXPECTED="\"$(TEST_OUT_EXPECTED)\"" \
			 -D TEST_OUTPUT_FILENAME="\"$(TEST_RESULTS)\"" \
			 -D MAX_FILE_COPY_SIZE=$(TEST_FAIL_LOGGING_MAXBYTES) \
			 -D IGNORE_RETURN_VALUE=$(IGNORE_RETURN_VALUE) \
			 -D DEFAULT_RUN_OPTIONS="\"$(DEFAULT_RUN_OPTIONS)\"" \
			 -D TIMEOUT_SECONDS=$(TIMEOUT_SECONDS) \
			 -D SINGLE_NUMBER_SINGLE_TEST=$(SINGLE_NUMBER_SINGLE_TEST) \
			 -D SINGLE_TEST_TURNS_ON_LLDB_COMPAT_MODE=$(SINGLE_TEST_TURNS_ON_LLDB_COMPAT_MODE) \
			 -D TEST_LOG="\"$(TEST_LOG)\"" \
			 -D NUMBER_OF_TESTS=$(NUMBER_OF_TESTS) \
			 -D TEST_OUTDATED_TIME=$(TEST_OUTDATED_TIME)
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
	@$(CC) $(CFLAGS) $(INC) $(TEST_DEFINES) -o $(TEST_ONAME) $(LIB) $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME) $(SRC_TEST) $(INDEXED_TESTS)
	@echo "\x1B[32m=============================================================\x1B[0m"
	@echo "\x1B[32m  printftester2000 (aka PFT)\x1B[0m - \x1B[2mmade by gfielder@42.us.org\x1B[0m"
	@echo "\x1B[32m=============================================================\x1B[0m"
	@echo "  \x1B[1;36m$(shell cat $(UNIT_TEST_FILE) | grep -c "^int\s*[a-zA-Z0-9_]*(void)" | tr -d " \n\t") \x1B[0mout of \x1B[1;33m$(shell cat $(UNIT_TEST_FILE) | grep -c "^\s*int\s*[a-zA-Z0-9_]*(void)" | tr -d " \n\t")\x1B[0m tests are enabled.\x1B[0;0;0m"
	@echo "  \x1B[4mDirections\x1B[0m:"
	@echo "    \x1B[36m./test [query]\x1B[0m          to run tests"
	@echo "    \x1B[36m./test help\x1B[0m             to see examples"
	@echo "    \x1B[36m./test help all\x1B[0m         to see extended help information"


$(INDEXED_TESTS): test_index

.INTERMEDIATE: test_index
test_index: $(UNIT_TEST_FILE)
	@php src/create_index.php $(UNIT_TEST_FILE) $(INDEXED_TESTS)

$(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME):
	@make -C $(LIBFTPRINTF_DIR) > /dev/null 2>&1

$(LIBFT_DIR_PATH)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR_PATH) > /dev/null 2>&1

clean:
	@rm -f $(INDEXED_TESTS)
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
