/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 06:47:42 by gfielder          #+#    #+#             */
/*   Updated: 2019/05/01 08:08:56 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "test.h"
#include <stdio.h>

static t_test_log_entry		*head = NULL;
static t_test_log_entry		*tail = NULL;

void		add_log_entry(const t_test_entry *test, int failed)
{
	t_test_log_entry	*ent = malloc(sizeof(t_test_log_entry));
	if (!ent)
		return ;

	ent->test = test;
	if (failed)
	{
		ent->timestamp_fail = time(NULL);
		ent->timestamp_pass = 0;
	}
	else
	{
		ent->timestamp_fail = 0;
		ent->timestamp_pass = time(NULL);
	}
	ent->next = NULL;

	if (!head)
	{
		head = ent;
		tail = ent;
	}
	else
	{
		tail->next = ent;
		tail = tail->next;
	}
}

void		write_head_to_log(FILE *fp_out, int test_last_passed,
				int test_last_failed)
{
	fprintf(fp_out, "%i,%s,%li,%li\n",
		head->test->number, head->test->name,
		(test_last_passed < head->timestamp_pass
			? head->timestamp_pass : test_last_passed),
		(test_last_failed < head->timestamp_fail
		 	? head->timestamp_fail : test_last_failed));
	t_test_log_entry *tmp = head->next;
	free(head);
	head = tmp;
}

void		new_log(void)
{
	FILE* fp = fopen(TEST_LOG, "w");
	if (fp)
	{
		while (head)
			write_head_to_log(fp, 0, 0);
	}
	fclose(fp);
}

void		write_log(void)
{
	FILE	*fp_in = NULL;
	FILE	*fp_out = NULL;
	size_t	size = 0;
	char	*line = NULL;
	int		test_number;
	char	**split;
	char	*test_name;
	time_t	test_last_passed;
	time_t	test_last_failed;

	if (!head)
		return ;
	fp_in = fopen(TEST_LOG, "r");
	if (!fp_in)
	{
		new_log();
		return ;
	}
	fp_out = fopen("log_new.temp", "w");
	while (getline(&line, &size, fp_in) > 0)
	{
		split = my_strsplit(line, ',');
		test_number = atoi(split[0]);
		test_name = split[1];
		test_last_passed = (time_t)atol(split[2]);
		test_last_failed = (time_t)atol(split[3]);
		while (head && head->test->number < test_number)
			write_head_to_log(fp_out, 0, 0);
		if (head && strcmp(test_name, head->test->name) == 0)
			write_head_to_log(fp_out, test_last_passed, test_last_failed);
		else
			fprintf(fp_out, "%s", line);
		ft_destroy_nullterm_ptrarray((void ***)(&split));
	}
	while (head)
		write_head_to_log(fp_out, 0, 0);
	fclose(fp_in);
	fclose(fp_out);
	char *cmd = NULL; asprintf(&cmd, "mv log_new.temp %s", TEST_LOG);
	system(cmd);
	free(cmd);
}































