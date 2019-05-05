# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    printftester2000 Makefile                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:19:45 by gfielder          #+#    #+#              #
#    Updated: 2019/05/04 20:35:14 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------------------------------------------------------------------------
#      Common User Options
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
DEFAULT_RUN_OPTIONS=AiKlrstx =nopf

# Sets the number of seconds for a test history to be considered 'outdated'
TEST_OUTDATED_TIME=900

# When 1, `make re` for this makefile also rebuilds libftprintf.a
MAKE_RE_ALSO_REBUILDS_LIBFTPRINTF=1

# ------------------------------------------------------------------------------
#      Advanced User Options
# ------------------------------------------------------------------------------

# Sets the command that's run when leaks test option is selected
LEAKS_TEST_CMD=system(\"leaks $(TEST_ONAME)\");

# When 1, removes test_history.csv whenever unit_tests.c is strictly newer
REMOVE_HISTORY_WHEN_TESTS_NEW=1

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
TEST_LOG=history.csv
TEST_RESULTS=results.txt
TEST_OUT_ACTUAL=test.mine
TEST_OUT_EXPECTED=test.libc
SRC_TEST=src/main.c src/test.c src/options.c src/utils.c \
		 src/help.c src/history.c src/vars.c src/print.c
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
			 -D TEST_OUTDATED_TIME=$(TEST_OUTDATED_TIME) \
			 -D LEAKS_TEST_CMD="$(LEAKS_TEST_CMD)"
ifeq ($(USE_SEPARATE_LIBFT),1)
LIB=$(LIBFT_DIR_PATH)/$(LIBFT_NAME)
else
LIB=
endif

TEST_HISTORY_MOD_TIME:=$(shell stat -r $(TEST_LOG) 2> /dev/null | awk '{ print $$9 }' 2> /dev/null)
UNIT_TESTS_MOD_TIME:=$(shell stat -r $(UNIT_TEST_FILE) 2> /dev/null | awk '{ print $$9 }' 2> /dev/null)
ifndef TEST_HISTORY_MOD_TIME
TEST_HISTORY_MOD_TIME:=0
endif

all: $(TEST_ONAME)

$(TEST_ONAME): $(SRC_TEST) $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME) $(LIB) test_index check_history_remove
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

.INTERMEDIATE: check_history_remove
check_history_remove:
	@if [ $(REMOVE_HISTORY_WHEN_TESTS_NEW) -eq 1 ] ; then \
		if [ $(UNIT_TESTS_MOD_TIME) -gt $(TEST_HISTORY_MOD_TIME) ] ; then \
			rm -rf $(TEST_LOG) ; \
		fi \
	fi

$(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME):
	@make -C $(LIBFTPRINTF_DIR) > /dev/null 2>&1

$(LIBFT_DIR_PATH)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR_PATH) > /dev/null 2>&1

clean:
	@rm -f $(INDEXED_TESTS)
	@rm -f $(TEST_OUT_ACTUAL)
	@rm -f $(TEST_OUT_EXPECTED)
	@rm -f $(TEST_RESULTS)
	@rm -f src/*.bak

fclean:
	@make clean
	@rm -rf $(TEST_ONAME).dSYM
	@rm -rf $(TEST_ONAME)

re:
	@if [ $(MAKE_RE_ALSO_REBUILDS_LIBFTPRINTF) -eq 1 ] ; then \
		make -C $(LIBFTPRINTF_DIR) fclean > /dev/null 2>&1 ; \
	fi
	@make fclean
	@make all
