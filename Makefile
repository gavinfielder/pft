# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:19:45 by gfielder          #+#    #+#              #
#    Updated: 2019/03/23 21:18:04 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=clang
CFLAGS=-Wall -Wextra -g -Werror
INC=-I libft/includes -I inc -I ftbi/inc
LIB=-L libft/ -lft

SRC=src/api/ft_asprintf.c src/api/ft_printf.c src/api/ft_sbprintf.c \
	src/api/ft_snprintf.c src/api/ft_sprintf.c \
	src/api/ft_vdprintf.c src/api/ft_vsbprintf.c \
	src/api/ft_vsnprintf.c src/api/ft_vsprintf.c \
	src/api/ft_vprintf.c \
	src/backend/ftpf_expandler.c src/backend/ftpf_master.c \
	src/backend/checker_funcs/ftpf_checker_funcs_index.c \
	src/backend/checker_funcs/ftpf_checker_funcs_00_04.c \
	src/backend/checker_funcs/ftpf_checker_funcs_05_09.c \
	src/backend/checker_funcs/ftpf_checker_funcs_10_14.c \
	src/backend/checker_funcs/ftpf_checker_funcs_15_19.c \
	src/backend/checker_funcs/ftpf_checker_funcs_20_24.c \
	src/backend/checker_funcs/ftpf_checker_funcs_25_29.c \
	src/backend/expander_funcs/ftpf_percent_expander.c \
	src/backend/expander_funcs/ftpf_signed_int_expander.c \
	src/backend/expander_funcs/ftpf_unsigned_int_expander.c \
	src/backend/expander_funcs/ftpf_string_expander.c \
	src/backend/expander_funcs/ftpf_extension_expander.c \
	src/backend/expander_funcs/ftpf_hexlower_expander.c \
	src/backend/expander_funcs/ftpf_hexupper_expander.c \
	src/backend/expander_funcs/ftpf_octal_expander.c \
	src/backend/expander_funcs/ftpf_char_expander.c \
	src/backend/expander_funcs/ftpf_ptr_expander.c \
	src/backend/expander_funcs/ftpf_float_expander.c \
	src/backend/expander_funcs/ftpf_float_expander_utils.c \
	src/backend/expander_funcs/ftpf_floatl_expander.c \
	src/backend/expander_funcs/ftpf_floatl_expander_utils.c \
	src/backend/expander_funcs/ftpf_memory_and_binary_utils.c \
	src/backend/expander_funcs/ftpf_memory_expander.c \
	src/backend/expander_funcs/ftpf_binary_expander.c \
	src/backend/expander_funcs/ftpf_flt_expander_special.c \
	src/backend/getarg_funcs/ftpf_getarg_ints.c \
	src/backend/getarg_funcs/ftpf_getarg_main.c \
	src/backend/getarg_funcs/ftpf_getarg_other.c

OBJ:=$(shell echo $(SRC) | sed "s/\.c/\.o/g" | sed "s/src\//bin\//g" | sed "s/api\///g" | sed "s/backend\///g" | sed "s/expander_funcs\///g" | sed "s/checker_funcs\///g" | sed "s/getarg_funcs\///g")

all: $(NAME)

$(NAME): bin
	@make -C libft/ > /dev/null 2>&1
	@ar rs $(NAME) $(OBJ) libft/*.o > /dev/null 2>&1
	@echo "Libftprintf compiled."

bin: $(SRC)
	@mkdir -p bin
	@$(CC) -c $(CFLAGS) $(INC) $(SRC)
	@mv *.o bin/

clean:
	@make -C libft/ clean > /dev/null 2>&1
	@rm -rf bin
	@make clean-test
	@echo "libftprintf: Object files removed."

fclean:
	@make -C libft/ fclean > /dev/null 2>&1
	@rm -rf bin
	@rm -f $(NAME)
	@make fclean-test
	@echo "libftprintf: Object files and library removed."

re:
	@make fclean
	@make all


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    printftester2000 Makefile additions                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:19:45 by gfielder          #+#    #+#              #
#    Updated: 2019/03/23 20:46:31 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# User Options

TEST_ONAME=test
TEST_FAIL_LOGGING_MAXBYTES=100
TEST_RESULTS=test_results.txt
TEST_OUT_ACTUAL=src/testing/test.mine
TEST_OUT_EXPECTED=src/testing/test.libc

# End User Options

SRC_TEST=src/testing/main.c src/testing/test.c
UNIT_TEST_FILE=src/testing/unit_tests.c
INDEXED_TESTS=src/testing/unit_tests_indexed.c
TEST_DEFINES=-D OUT_ACTUAL="\"$(TEST_OUT_ACTUAL)\"" \
			 -D OUT_EXPECTED="\"$(TEST_OUT_EXPECTED)\"" \
			 -D TEST_OUTPUT_FILENAME="\"$(TEST_RESULTS)\"" \
			 -D MAX_FILE_COPY_SIZE=$(TEST_FAIL_LOGGING_MAXBYTES)

test_index: $(UNIT_TEST_FILE)
	@cp $(UNIT_TEST_FILE) $(INDEXED_TESTS)
	@echo "const t_unit_test g_unit_tests[] = {" >> $(INDEXED_TESTS)
	@cat $(UNIT_TEST_FILE) | grep -o "^int\s*[a-zA-Z0-9_]*(void)" | sed "s/^int\s*//g" | sed "s/(void)/,/g" | tr -d " \t\v\f" >> $(INDEXED_TESTS)
	@echo "NULL" >> $(INDEXED_TESTS)
	@echo "};" >> $(INDEXED_TESTS)
	@echo "" >> $(INDEXED_TESTS)
	@echo "const char *g_unit_test_names[] = {" >> $(INDEXED_TESTS)
	@cat $(UNIT_TEST_FILE) | grep -o "^int\s*[a-zA-Z0-9_]*(void)" | sed "s/^int\s*/\"/g    " | sed "s/(void)/\",/g" | tr -d " \t\v\f" >> $(INDEXED_TESTS)
	@echo "NULL" >> $(INDEXED_TESTS)
	@echo "};" >> $(INDEXED_TESTS)

test: $(NAME) $(SRC_TEST) test_index $(NAME)
	@rm -f $(TEST_OUT_ACTUAL)
	@rm -f $(TEST_OUT_EXPECTED)
	@rm -f $(TEST_RESULTS)
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(TEST_DEFINES) -o $(TEST_ONAME) libftprintf.a $(SRC_TEST) $(INDEXED_TESTS)

clean-test:
	@rm -f $(INDEXED_TESTS)
	@rm -f $(TEST_OUT_ACTUAL)
	@rm -f $(TEST_OUT_EXPECTED)
	@rm -f $(TEST_RESULTS)

fclean-test:
	@make clean-test
	@rm -rf $(TEST_ONAME).dSYM
	@rm -rf $(TEST_ONAME)
