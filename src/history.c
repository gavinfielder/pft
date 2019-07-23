/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 06:47:42 by gfielder          #+#    #+#             */
/*   Updated: 2019/05/06 19:40:46 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <time.h>
#include <string.h>
#include "test.h"
#include <stdio.h>

/* ----------------------------------------------------------------------------
** Global variable that holds the test history from the log
** --------------------------------------------------------------------------*/

t_test_history			test_history[NUMBER_OF_TESTS + 4];

/* ----------------------------------------------------------------------------
** Linked list for all the tests that ran and need writing to the log
** --------------------------------------------------------------------------*/

static t_test_log_entry		*head = NULL;
static t_test_log_entry		*tail = NULL;

/* ----------------------------------------------------------------------------
** Time of run
** --------------------------------------------------------------------------*/

time_t		now = 0;

/* ----------------------------------------------------------------------------
** Populate the test_history array
** --------------------------------------------------------------------------*/
void		load_history(void)
{
	FILE	*fp_in = NULL;
	size_t	size = 0;
	char	*line = NULL;
	int		test_number;
	char	**split;
	time_t	test_last_passed;
	time_t	test_last_failed;

	bzero(test_history, sizeof(t_test_history) * (NUMBER_OF_TESTS + 4));
	now = time(NULL);

	fp_in = fopen(TEST_LOG, "r");
	if (!fp_in)
		return ;
	while (getline(&line, &size, fp_in) > 0)
	{
		split = my_strsplit(line, ',');
		test_number = atoi(split[0]);
		test_last_passed = (time_t)atol(split[2]);
		test_last_failed = (time_t)atol(split[3]);
		if (now < test_last_failed + TEST_OUTDATED_TIME && test_last_failed > test_last_passed)
			test_history[test_number].type = RECENTLY_FAILED;
		else if (now < test_last_passed + TEST_OUTDATED_TIME && test_last_passed > test_last_failed)
			test_history[test_number].type = RECENTLY_PASSED;
		else
			test_history[test_number].type = OUTDATED;
		test_history[test_number].timestamp = 
			(test_last_passed >= test_last_failed ?
				test_last_passed : test_last_failed);
		my_destroy_nullterm_ptrarray((void ***)(&split));
	}
	if (line)
		free(line);
	fclose(fp_in);
}

/* ----------------------------------------------------------------------------
** Adds an entry to the linked list for later write to the log
** --------------------------------------------------------------------------*/
void		add_log_entry(const t_test_entry *test, int failed)
{
	t_test_log_entry	*ent = malloc(sizeof(t_test_log_entry));
	if (!ent)
		return ;

	ent->test = test;
	if (failed)
	{
		ent->timestamp_fail = now;
		ent->timestamp_pass = 0;
	}
	else
	{
		ent->timestamp_fail = 0;
		ent->timestamp_pass = now;
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

/* ----------------------------------------------------------------------------
** Writes the current head to the log
** --------------------------------------------------------------------------*/
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
	if (!head)
		tail = NULL;
}

/* ----------------------------------------------------------------------------
** Deletes all the log entries waiting to be written
** --------------------------------------------------------------------------*/
void		flush_all_log_entries(void)
{
	t_test_log_entry *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	tail = NULL;
}

/* ----------------------------------------------------------------------------
** Writes a fresh log with all the log entries waiting to be written
** --------------------------------------------------------------------------*/
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

/* ----------------------------------------------------------------------------
** Re-writes the log, merging existing data and new data
** --------------------------------------------------------------------------*/
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
	if (get_option_writelog() == 0)
	{
		flush_all_log_entries();
		return ;
	}
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
		my_destroy_nullterm_ptrarray((void ***)(&split));
	}
	while (head)
		write_head_to_log(fp_out, 0, 0);
	fclose(fp_in);
	fclose(fp_out);
	if (line)
		free(line);
	char *cmd = NULL; asprintf(&cmd, "mv log_new.temp %s", TEST_LOG);
	system(cmd);
	free(cmd);
}

