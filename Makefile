# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    printftester2000 Makefile                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:19:45 by gfielder          #+#    #+#              #
#    Updated: 2019/07/08 22:40:24 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
#      User options are now in options-config.ini
# ------------------------------------------------------------------------------

OVERRIDE_EXISTS=$(shell find options-config.ini.override 2>/dev/null | grep -c ".*")

ifeq ($(OVERRIDE_EXISTS),0)
include options-config.ini
else
include options-config.ini.override
endif

CC=clang
INC=-I src
TEST_LOG=history.csv
TEST_OUT_ACTUAL=test.mine
TEST_OUT_EXPECTED=test.libc
SRC_TEST=src/main.c src/test.c src/options.c src/utils.c \
		 src/help.c src/history.c src/print.c src/help_conf.c
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
			 -D LEAKS_TEST_CMD="$(LEAKS_TEST_CMD)" \
			 -D FORCE_TEST_LOG=$(FORCE_TEST_LOG)
ifeq ($(USE_SEPARATE_LIBFT),1)
LIB=$(LIBFT_DIR_PATH)/$(LIBFT_NAME)
else
LIB=
endif
ifeq ($(INCLUDE_LIBPTHREAD),1)
LIB +=	-lpthread
endif

TEST_HISTORY_MOD_TIME:=$(shell stat -r $(TEST_LOG) 2> /dev/null | awk '{ print $$9 }' 2> /dev/null)
UNIT_TESTS_MOD_TIME:=$(shell stat -r $(UNIT_TEST_FILE) 2> /dev/null | awk '{ print $$9 }' 2> /dev/null)
ifndef TEST_HISTORY_MOD_TIME
TEST_HISTORY_MOD_TIME:=0
endif

# testing:
	# @echo "$(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME)"

all: $(TEST_ONAME)

$(TEST_ONAME): $(SRC_TEST) $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME) $(LIB) test_index check_history_remove
	@rm -f $(TEST_OUT_ACTUAL)
	@rm -f $(TEST_OUT_EXPECTED)
	@rm -f $(TEST_RESULTS)
	@$(CC) $(CFLAGS) $(INC) $(TEST_DEFINES) -o $(TEST_ONAME) $(LIB)  $(SRC_TEST) $(INDEXED_TESTS) $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME)
	@./src/usage_statistics.php &>/dev/null &
	@echo "\x1B[32m=============================================================\x1B[0m"
	@echo "\x1B[32m  printftester2000 (aka PFT)\x1B[0m - \x1B[2mmade by gfielder@42.us.org\x1B[0m"
	@echo "\x1B[32m=============================================================\x1B[0m"
	@echo "  \x1B[1;36m$(shell cat $(UNIT_TEST_FILE) | grep -c "^int\s*[a-zA-Z0-9_]*(void)" | tr -d " \n\t") \x1B[0mout of \x1B[1;33m$(shell cat $(UNIT_TEST_FILE) | grep -c "^\s*int\s*[a-zA-Z0-9_]*(void)" | tr -d " \n\t")\x1B[0m tests are enabled.\x1B[0;0;0m"
	@echo "  \x1B[4mDirections\x1B[0m:"
	@echo "    \x1B[36m./test [query]\x1B[0m          to run tests"
	@echo "    \x1B[36m./test help\x1B[0m             to see examples and other help"


$(INDEXED_TESTS): test_index

.INTERMEDIATE: test_index
test_index: $(UNIT_TEST_FILE)
	@php src/create_index.php $(UNIT_TEST_FILE) $(INDEXED_TESTS)

.INTERMEDIATE: check_history_remove
check_history_remove:
	@if [ $(REMOVE_HISTORY_WHEN_TESTS_NEW) -eq 1 ] ; then \
        if ! [ -z "$(UNIT_TESTS_MOD_TIME)" ] ; then \
    		if [ $(UNIT_TESTS_MOD_TIME) -gt $(TEST_HISTORY_MOD_TIME) ] ; then \
    			rm -rf $(TEST_LOG) ; \
    		fi \
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
	@rm -rf src/show_disabled_postprocess
	@rm -f src/*.bak

fclean:
	@make clean
	@rm -rf $(TEST_ONAME).dSYM
	@rm -rf $(TEST_ONAME)
	@rm -rf src/show_disabled_postprocess

re:
	@if [ $(MAKE_RE_ALSO_REBUILDS_LIBFTPRINTF) -eq 1 ] ; then \
		make -C $(LIBFTPRINTF_DIR) fclean > /dev/null 2>&1 ; \
	fi
	@make fclean
	@make all
