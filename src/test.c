/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:53:02 by gfielder          #+#    #+#             */
/*   Updated: 2019/07/09 00:00:07 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/* ----------------------------------------------------------------------------
** Signal names, as strings
** --------------------------------------------------------------------------*/
const char *g_signal_strings[] = 
{
	"",
	"SIGHUP",
	"SIGINT",
	"SIGQUIT",
	"SIGILL",
	"SIGTRAP",
	"SIGABRT",
	"SIGEMT",
	"SIGFPE",
	"SIGKILL",
	"BUSERROR",
	"SEGFAULT",
	"SIGSYS",
	"SIGPIPE",
	"SIGALRM",
	"SIGTERM",
	"SIGURG",
	"SIGSTOP",
	"SIGTSTP",
	"SIGCONT",
	"SIGCHLD",
	"SIGTTIN",
	"SIGTTOU",
	"SIGIO",
	"SIGXCPU",
	"SIGXFSZ",
	"SIGVTALRM",
	"SIGPROF",
	"SIGWINCH",
	"SIGINFO",
	"SIGUSR1",
	"SIGUSR2"
};

/* ----------------------------------------------------------------------------
** Global flags for timeout function
** --------------------------------------------------------------------------*/

static int			timeout = 0;
static int			ready = 0;

/* ----------------------------------------------------------------------------
** Set to true if in non-forking mode and a test signaled out
** --------------------------------------------------------------------------*/

static int			signaled = 0;

/* ----------------------------------------------------------------------------
** Calls a unit test function and outputs the result to a file
** --------------------------------------------------------------------------*/
static int	output_to_file(char *filename, t_unit_test f)
{
	fpos_t		pos_stdout;
	fpos_t		pos_stderr;
	int			fd = dup(fileno(stdout));
	int			fd_err = dup(fileno(stderr));
	int			ret;

	//Set up redirection of stdout
	fgetpos(stdout, &pos_stdout);
	fgetpos(stderr, &pos_stderr);
	freopen(filename, "w+", stdout);
	freopen("/dev/null", "w+", stderr);
	//Call the test function
	ret = f();
	chmod(filename, 0644);
	//Clean up
	fflush(stdout);
	fflush(stderr);
	dup2(fd, fileno(stdout));
	dup2(fd_err, fileno(stderr));
	close(fd);
	close(fd_err);
	clearerr(stdout);
	clearerr(stderr);
	fsetpos(stdout, &pos_stdout);
	fsetpos(stderr, &pos_stderr);
	return (ret);
}

/* ----------------------------------------------------------------------------
** Logs a failed test to the test results file
** --------------------------------------------------------------------------*/
void	log_failed_test(int test_number, int expected, int actual,
			const char *signal_terminated, int timed_out)
{
	char	issue_11_warning[] = "WARNING: The return values reported here may be bugged on some systems.\n          See https://github.com/gavinfielder/pft/issues/11\n          Run in non-fork mode (-X) to ensure accurate return value\n          reporting, set IGNORE_RETURN_VALUE=1 in options-config.ini,\n          or run test_pipes.sh to see if your system has this bug.\n          This bug does not affect the pass/fail result of a test, nor\n          the function output--only the reported return value.\n\n\n";
	static int issue_11_warning_printed = 0;
	char	buff1[MAX_FILE_COPY_SIZE + 1];
	char	buff2[MAX_FILE_COPY_SIZE + 1];
	buff1[MAX_FILE_COPY_SIZE] = '\0';
	buff2[MAX_FILE_COPY_SIZE] = '\0';
	int bytes, buff1_len, buff2_len;

	int				nocrash = 0;
	nocrash = (strncmp(g_unit_tests[test_number].name, "nocrash_", 8) == 0);

	//Open files
	int finmine = open(OUT_ACTUAL, O_RDONLY);
	int finlibc = open(OUT_EXPECTED, O_RDONLY);
	int fout = open(TEST_OUTPUT_FILENAME, O_CREAT | O_WRONLY | O_APPEND,
				S_IRWXU | S_IRWXG | S_IRWXO);
	if (fout < 0)
	{
		close(finlibc);
		close(finmine);
		log_msg("error: An error occurred opening the test results file");
		return ;
	}

	//Print issue 11 warning
	if (!IGNORE_RETURN_VALUE && options.run_test == run_test_fork && issue_11_warning_printed == 0) {
		write(fout, issue_11_warning, strlen(issue_11_warning));
		issue_11_warning_printed = 1;
	}

	//Write to test results file

	snprintf(buff1, MAX_FILE_COPY_SIZE, "Test %3i (%s) : FAILED.\n", test_number, g_unit_tests[test_number].name);
	write(fout, buff1, strlen(buff1));
	if (nocrash)
	{
		snprintf(buff1, MAX_FILE_COPY_SIZE,
			"    (nocrash test: automatically passes provided no unexpected failure)\n");
		write(fout, buff1, strlen(buff1));
	}
	snprintf(buff1, MAX_FILE_COPY_SIZE, "    First line of code: %s\n", g_unit_tests[test_number].first_line);
	write(fout, buff1, strlen(buff1));
	if (timed_out)
		write(fout, "    Timed out\n", 14);
	else if (!signal_terminated)
	{
		buff1_len = -1;
		buff2_len = -1;
        if (!IGNORE_RETURN_VALUE) {
    		snprintf(buff1, MAX_FILE_COPY_SIZE, "      expected return value : %i\n      your return value     : %i", expected, actual);
		    write(fout, buff1, strlen(buff1));
	    	write(fout, "\n", 1);
        }
		snprintf(buff1, MAX_FILE_COPY_SIZE, "      expected output : \"");
		write(fout, buff1, strlen(buff1));
		if (finlibc > 0)
		{
			bytes = read(finlibc, buff1, MAX_FILE_COPY_SIZE);
			if (bytes > 0)
				write(fout, buff1, bytes);
			buff1_len = bytes;
		}
		else
			write(fout, "(output doesn't exist or an error occurred)", 43);
		snprintf(buff2, MAX_FILE_COPY_SIZE, "\"\n      your output     : \"");
		write(fout, buff2, strlen(buff2));
		if (finmine > 0)
		{
			bytes = read(finmine, buff2, MAX_FILE_COPY_SIZE);
			if (bytes > 0)
				write(fout, buff2, bytes);
			buff2_len = bytes;
		}
		else
			write(fout, "(output doesn't exist or an error occurred)", 43);
		write(fout, "\"\n", 2);
		//Print nonprintable hex output
		if (buff1_len >= 0)
		{
			write(fout, "      expected (nonprintable as hex) : \"", 40);
			my_putnchar_np_hex_fd(fout, buff1, buff1_len);
			write(fout, "\"\n", 2);
		}
		if (buff2_len >= 0)
		{
			write(fout, "      actual   (nonprintable as hex) : \"", 40);
			my_putnchar_np_hex_fd(fout, buff2, buff2_len);
			write(fout, "\"\n", 2);
		}
	}
	else
	{
		write(fout, "    ", 4);
		write(fout, signal_terminated, strlen(signal_terminated));
		write(fout, "\n", 1);
	}
	write(fout, "\n", 1);
	//close files
	close(finlibc);
	close(finmine);
	close(fout);
}

/* ----------------------------------------------------------------------------
** Signal Handlers for segfault, bus error, etc.
** --------------------------------------------------------------------------*/
static void failsafe_recover(void)
{
	//Go to the next test
	failsafe_args_recover->current++;
	failsafe_args_recover->num_fails++;
	failsafe_args_recover->num_run++;
	//Cleanup stdout
	fflush(stdout);
	fflush(stderr);
	//Recover stdout from the args failsafe
	dup2(failsafe_args_recover->fd_stdout_dup, fileno(stdout));
}
static void	handle_sigsegv(int sigval)
{
	(void)sigval;
	signaled = 1;
	failsafe_recover();
	log_failed_test(failsafe_args_recover->current - 1, -6, -6,
			"Segmentation Fault", 0);
	printf(FAULT "SEGFAULT" RESET "]\n");
	failsafe_args_recover->run(failsafe_args_recover);
}
static void	handle_sigbus(int sigval)
{
	(void)sigval;
	signaled = 1;
	failsafe_recover();
	log_failed_test(failsafe_args_recover->current - 1, -6, -6,
			"Bus Error", 0);
	printf(FAULT "BUSERROR" RESET "]\n");
	failsafe_args_recover->run(failsafe_args_recover);
}
static void handle_sigabrt(int sigval)
{
	(void)sigval;
	signaled = 1;
	failsafe_recover();
	log_failed_test(failsafe_args_recover->current - 1, -6, -6,
			"Abort Signal (SIGABRT)", 0);
	printf(FAULT "SIGABRT" RESET "]\n");
	failsafe_args_recover->run(failsafe_args_recover);
}
static void handle_sigill(int sigval)
{
	(void)sigval;
	signaled = 1;
	failsafe_recover();
	log_failed_test(failsafe_args_recover->current - 1, -6, -6,
			"Illegal Instruction (SIGILL)", 0);
	printf(FAULT "SIGILL" RESET "]\n");
	failsafe_args_recover->run(failsafe_args_recover);
}
/*
static void	handle_timeout_signal(int sigval)
{
	(void)sigval;
	signaled = 1;
	failsafe_recover();
	log_failed_test(failsafe_args_recover->current - 1, -7, -7,
			"Test timed out", 1);
	printf(FAULT "TIMEOUT" RESET "]\n");
	failsafe_args_recover->run(failsafe_args_recover);
}
*/

/* ----------------------------------------------------------------------------
** Runs the pair of a test function and its bench and outputs to file
** --------------------------------------------------------------------------*/
static t_retvals	output_test(int test_number)
{
	t_retvals		retvals;
	int				nocrash = 0;

	bzero(&retvals, sizeof(t_retvals));
	nocrash = (strncmp(g_unit_tests[test_number].name, "nocrash_", 8) == 0);
	retvals.ret_val_mine = output_to_file(OUT_ACTUAL, g_unit_tests[test_number].test);
	if (!nocrash)
		retvals.ret_val_libc = output_to_file(OUT_EXPECTED, g_unit_tests[test_number].bench);
	else
		retvals.ret_val_libc = -2;
	return (retvals);
}

/* ----------------------------------------------------------------------------
** Opens OUT_ACTUAL and OUT_EXPECTED, handling any errors
** --------------------------------------------------------------------------*/
static int	get_and_validate_test_fp(FILE **fpmine, FILE **fplibc)
{
	*fpmine = fopen(OUT_ACTUAL, "r");
	if (!(*fpmine))
	{
		*fpmine = fopen(OUT_ACTUAL, "w+");
		if ((*fpmine))
			fputs("(No output was generated)", (*fpmine));
		else
		{
			log_msg("error: Error opening output file. Contact gfielder about this error.)");
			return (-1);
		}
		if (fclose((*fpmine)) < 0)
		{
			log_msg("error: Error closing output file. Contact gfielder about this error.)");
			return (-1);
		}
		*fpmine = fopen(OUT_ACTUAL, "r");
		if (!(*fpmine))
		{
			log_msg("error: Error opening test file--contact gfielder about this error");
			return (-1);
		}
	}
	*fplibc = fopen(OUT_EXPECTED, "r");
	if (!(*fplibc))
	{
		*fplibc = fopen(OUT_EXPECTED, "w");
		if ((*fplibc))
			fputs("(No bench output was generated. Contact gfielder about this error.)", (*fpmine));
		else
		{
			fclose((*fpmine));
			log_msg("error: Error opening bench file. Contact gfielder about this error.)");
			return (-1);
		}
		if (fclose((*fplibc)) < 0)
		{
			fclose((*fpmine));
			log_msg("error: Error closing bench file. Contact gfielder about this error.)");
			return (-1);
		}
		*fpmine = fopen(OUT_ACTUAL, "r");
		if (!(*fpmine))
		{
			fclose((*fpmine));
			log_msg("error: Error opening test file--contact gfielder about this error");
			return (-1);
		}
	}
	return (1);
}

/* ----------------------------------------------------------------------------
** Evaluates results from the recently run test
** --------------------------------------------------------------------------*/
static int	evaluate_test_results(t_retvals retvals, int test_number)
{
	int				failed = 0;
	FILE			*fpmine, *fplibc;
	int				cmine, clibc;
	int				nocrash;
	int				run_comparison = 1;

	nocrash = (strncmp(g_unit_tests[test_number].name, "nocrash_", 8) == 0);
	if (nocrash)
	{
		if (retvals.stat_loc == 0)
			failed = 0;
		else if ((WIFEXITED(retvals.stat_loc))
				&& (WEXITSTATUS(retvals.stat_loc) == 0))
			failed = 0;
		else if (WIFSIGNALED(retvals.stat_loc))
			failed = 1;
		else if (WIFSTOPPED(retvals.stat_loc))
			failed = 1;
		else
			failed = 1;
		if (timeout)
			failed = 1;
		run_comparison = 0;
	}
	else if (timeout)
		failed = 1;
	else if (retvals.stat_loc != 0)
	{
		if ((WIFEXITED(retvals.stat_loc))
				&& (WEXITSTATUS(retvals.stat_loc) != 0))
			failed = 1;
		else if (WIFSIGNALED(retvals.stat_loc))
			failed = 1;
		else if (WIFSTOPPED(retvals.stat_loc))
			failed = 1;
	}
	if (run_comparison)
	{
		if (get_and_validate_test_fp(&fpmine, &fplibc) < 0)
		{
			log_msg("error: test results could not be evaluated: failed to open file(s)");
			return (1);
		}
		//Evaluate test results
		if (retvals.ret_val_mine != retvals.ret_val_libc && !(IGNORE_RETURN_VALUE))
			failed = 1;
		else
		{
			//Get characters from files in loop
			cmine = getc(fpmine);
			clibc = getc(fplibc);
			while ((cmine != EOF) && (clibc != EOF) && (clibc == cmine)) {
				cmine = getc(fpmine);
				clibc = getc(fplibc);
			}
			if (cmine != clibc)
				failed = 1;
		}
		fclose(fpmine);
		fclose(fplibc);
	}

	if (failed || FORCE_TEST_LOG)
	{
		log_failed_test(test_number, retvals.ret_val_libc,
				retvals.ret_val_mine,
				((WIFSIGNALED(retvals.stat_loc)) ?
				g_signal_strings[WTERMSIG(retvals.stat_loc)] : NULL),
				timeout);
	}

	if (options.log_history)
		add_log_entry(&(g_unit_tests[test_number]), failed);

	return failed;
}

/* ----------------------------------------------------------------------------
** Starts a timeout timer
** --------------------------------------------------------------------------*/
static void		catch_ok_signal(int sigval)
{
	(void)sigval;
}
static void		*timeout_thread(void *args_void)
{
	t_timeout_args	*args = (t_timeout_args *)args_void;
	signal(SIGUSR1, catch_ok_signal);
	//usleep fails if a signal was caught
	if (usleep((unsigned int)(((float)TIMEOUT_SECONDS) * (1000000.0f))) < 0)
		pthread_exit(NULL);
	timeout = 1;
	if (args->pid > 0) //calling thread requested a process killed on timeout
		kill(args->pid, SIGKILL);
	if (args->signal) //calling thread requested a signal be sent to it
		pthread_kill(args->mainthread, args->signal);
	return (NULL);
}

static void		start_timeout(pid_t pid, int signal, pthread_t *thread, pthread_t mainthread)
{
	t_timeout_args	*args = (t_timeout_args *)malloc(sizeof(t_timeout_args));

	args->pid = pid;
	args->signal = signal;
	args->mainthread = mainthread;
	timeout = 0;
	pthread_create(thread, NULL, timeout_thread, (void *)(args));

}

/* ----------------------------------------------------------------------------
** Runs a specific test
** --------------------------------------------------------------------------*/
int				run_test_nofork(int test_number)
{
	t_retvals		retvals;
	int				failed = 0;

	remove(OUT_ACTUAL);
	remove(OUT_EXPECTED);
	print_test_start(test_number);
	retvals = output_test(test_number);
	failed = evaluate_test_results(retvals, test_number);
	print_test_end(test_number, failed, 0, 0, 0);

	return failed;
}

/* ----------------------------------------------------------------------------
** Writes the return values to given pipe
** --------------------------------------------------------------------------*/
static void		write_retvals_pipe(int fd, t_retvals retvals)
{
	my_putnbr_fd(retvals.ret_val_mine, fd);
	write(fd, ";", 1);
	my_putnbr_fd(retvals.ret_val_libc, fd);
	write(fd, ";", 1);
}

/* ----------------------------------------------------------------------------
** Reads the return values from the given pipe
** --------------------------------------------------------------------------*/
static void		catch_timeout_signal(int sigval)
{
	(void)sigval;
}
static void		*read_retvals_pipe(void *args_void)
{
	t_retval_pipe_args	*args = (t_retval_pipe_args *)args_void;
	char			c;
	int				sign_mine = 1;
	int				sign_libc = 1;
	int				init_mine = 0;
	int				init_libc = 0;

	//if timeout, use this to abort
	signal(SIGUSR2, catch_timeout_signal);
	siginterrupt(SIGUSR2, 1);

	bzero(&(args->retvals), sizeof(t_retvals));

	while (read(args->fd, &c, 1) > 0)
	{
		init_mine = 1;
		if (c == ';')
			break ;
		if (c == '-')
			sign_mine = -1;
		else if (c >= '0' && c <= '9')
			args->retvals.ret_val_mine += (args->retvals.ret_val_mine * 10)
				+ (sign_mine * (c - '0'));
	}
	if (timeout)
		pthread_exit(NULL);
	if (!init_mine)
		args->retvals.ret_val_mine = -5;
	signal(SIGUSR2, catch_timeout_signal);
	siginterrupt(SIGUSR2, 1);

	while (read(args->fd, &c, 1) > 0)
	{
		init_libc = 1;
		if (c == ';')
			break ;
		if (c == '-')
			sign_libc = -1;
		else if (c >= '0' && c <= '9')
			args->retvals.ret_val_libc += (args->retvals.ret_val_libc * 10)
				+ (sign_libc * (c - '0'));
	}
	if (timeout)
		pthread_exit(NULL);
	if (!init_libc)
		args->retvals.ret_val_libc = -5;
	ready = 1;
	return (args_void);
}

static pthread_t	read_retvals_pipe_async(t_retval_pipe_args *args)
{
	pthread_t	thread;
	ready = 0;
	pthread_create(&thread, NULL, read_retvals_pipe, (void *)args);
	return (thread);
}

/* ----------------------------------------------------------------------------
** Run a test using fork
** --------------------------------------------------------------------------*/
int			run_test_fork(int test_number)
{
	pthread_t	timeout_thread;
	pthread_t	read_thread;
	pthread_t	this_thread = pthread_self();
	t_retvals	retvals;
	t_retval_pipe_args	args;
	pid_t		pid;
	int			failed = 0;
	int			stat_loc;
	int			pipe_fd[2];
	
	remove(OUT_ACTUAL);
	remove(OUT_EXPECTED);
	print_test_start(test_number);
	if (pipe(pipe_fd) < 0)
	{
		pipe_fd[0] = -3;
		pipe_fd[1] = -3;
	}
	fflush(stdout);
	pid = fork();
	if (pid == 0)
	{
		//Inside child process
		pid = getppid();
		//close(2);
		retvals = output_test(test_number);
		if (pipe_fd[1] > 0)
			write_retvals_pipe(pipe_fd[1], retvals);
		exit(0);
		//Exit child process
	}
	else
	{
		if (options.use_timeout)
			start_timeout(pid, 0, &timeout_thread, this_thread);
		//Waiting for child process to complete
		waitpid(pid, &stat_loc, WUNTRACED);
		if (WIFEXITED(stat_loc) && WEXITSTATUS(stat_loc) == 0 && pipe_fd[0] > 0)
		{
			args.fd = pipe_fd[0];
			read_thread = read_retvals_pipe_async(&args);
			//Wait for either timeout or done reading
			while (!timeout && !ready);
			if (ready)
			{
				//finished reading
				retvals = args.retvals;
				if (options.use_timeout)
					pthread_kill(timeout_thread, SIGUSR1);
			}
			else
			{
				//timed out
				pthread_kill(read_thread, SIGUSR2);
				retvals.ret_val_mine = -8;
				retvals.ret_val_libc = -8;
				pthread_join(timeout_thread, NULL);
			}
		}
		else
		{
			if (options.use_timeout && !timeout)
				pthread_kill(timeout_thread, SIGUSR1);
			retvals.ret_val_mine = -4;
			retvals.ret_val_libc = -4;
		}
		retvals.stat_loc = stat_loc;
	}
	if (pipe_fd[0] > 0)
		close(pipe_fd[0]);
	if (pipe_fd[1] > 0)
		close(pipe_fd[1]);
	failed = evaluate_test_results(retvals, test_number);
	print_test_end(test_number, failed, retvals.stat_loc, timeout, 0);
	return (failed);
}

/* ----------------------------------------------------------------------------
** Returns 1 if options allow test to run, 0 if it is filtered out
** --------------------------------------------------------------------------*/
int		filter(int test_number)
{
	int		ret = 1;

	if (g_unit_tests[test_number].enabled == 0 && options.filter_run_disabled == 0)
		return (0);
	if (options.log_history)
	{
		switch (test_history[test_number].type)
		{
			case OUTDATED:
				ret &= options.filter_run_outdated;
				break;
			case RECENTLY_PASSED:
				ret &= options.filter_run_passing;
				break;
			case RECENTLY_FAILED:
				ret &= options.filter_run_failing;
				break;
			case NO_HISTORY:
				ret &= options.filter_run_nohistory;
				break;
		}
	}
	return (ret);
}


/* ----------------------------------------------------------------------------
** Runs before either test runner function runs
** --------------------------------------------------------------------------*/
void	run_init(void)
{
	if (options.log_history)
		load_history();
	if (options.run_test == run_test_nofork && options.handle_signals)
	{
		signal(SIGSEGV, handle_sigsegv);
		signal(SIGBUS, handle_sigbus);
		signal(SIGABRT, handle_sigabrt);
		signal(SIGILL, handle_sigill);
	}
	if (options.refresh_results)
	{
		remove(TEST_OUTPUT_FILENAME);
	}
}

/* ----------------------------------------------------------------------------
** Removes temporary files created by a test run
** --------------------------------------------------------------------------*/
void	cleanup_temp_files()
{
	unlink(OUT_ACTUAL);
	unlink(OUT_EXPECTED);
}

/* ----------------------------------------------------------------------------
** Runs all the tests that match the search pattern
** --------------------------------------------------------------------------*/
void	run_search_tests(t_unit_tester_args *args)
{
	int fail = 0;
	
	//Append a * onto pattern so we don't have to modify the piscine's ft_match
	size_t len = strlen(args->pattern) + 2;
	char *pattern = (char *)malloc(len);
	pattern[len - 1] = '\0';
	for (size_t i = 0; i < len - 2; i++)
		pattern[i] = args->pattern[i];
	pattern[len - 2] = '*';

	//Convert all invalid characters for function names into wildcards
	convert_nonalphanum_to_wildcard(pattern);

	//Search tests
	while (g_unit_tests[args->current].test != NULL)
	{
		if (ft_match(g_unit_tests[args->current].name, pattern)
				&& (filter(args->current)))
		{
			fail = options.run_test(args->current);
			args->num_fails += fail;
			args->num_run++;
		}
		args->current++;
	}
	print_end_test_message(args->num_run, args->num_run - args->num_fails);
	free(pattern);
	if (options.log_history)
		write_log();
	if (options.run_leaks_test)
	{
		if (signaled)
			printf("One or more tests terminated abnormally. Skipping leaks test.\n");
		else
		{
			fflush(stdout);
			LEAKS_TEST_CMD;
		}
	}
	if (get_options().cleanup)
		cleanup_temp_files();
	exit(0); //needed in non-fork mode in case a test segfaulted
}

/* ----------------------------------------------------------------------------
** Runs a range of tests
** --------------------------------------------------------------------------*/
void	run_test_range(t_unit_tester_args *args)
{
	int	fail = 0;

	while (args->current <= args->to && g_unit_tests[args->current].test != NULL)
	{
		if (filter(args->current))
		{
			fail = options.run_test(args->current);
			args->num_fails += fail;
			args->num_run++;
		}
		args->current++;
	}
	print_end_test_message(args->num_run, args->num_run - args->num_fails);
	if (options.log_history)
		write_log();
	if (options.run_leaks_test)
	{
		if (signaled)
			printf("One or more tests terminated abnormally. Skipping leaks test.\n");
		else
		{
			fflush(stdout);
			LEAKS_TEST_CMD;
		}
	}
	if (get_options().cleanup)
		cleanup_temp_files();
	exit(0); //needed in non-fork mode in case a test segfaulted
}
