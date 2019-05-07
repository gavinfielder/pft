<?php
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    select_history.php                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 10:48:11 by gfielder          #+#    #+#              #
#    Updated: 2019/05/06 10:48:11 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

//fnop
//
// f = 0
// n = 1
// o = 2
// p = 3

function	get_test_outdated_time()
{
	static $test_outdated_time = -1;
	global $argv;
	global $config_file;

	if ($test_outdated_time == -1)
	{
		//$config = preg_replace('/select_.*?\.php/', '../config.ini', $argv[0]);
		if (file_exists($config_file))
		{
			$line = shell_exec("grep -e \"^TEST_OUTDATED_TIME\" $config_file");
			$split = explode("=", $line);
			$test_outdated_time = intval($split[1]);
			//echo "Read: TEST_OUTDATED_TIME=$test_outdated_time\n";
		}
		else
			return (-1);
	}
	return ($test_outdated_time);
}

function	get_test_status($test_name)
{
	global $history_file;
	global $argv;

	//echo "getting history for \"$test_name\"... \n";
	if (!file_exists($history_file))
	{
		//echo "returning 49: 1\n";
		return (1);
	}
	$line = shell_exec("grep \"$test_name,\" $history_file");
	if (!$line || !(strlen($line) > 0))
	{
		//echo "returning 55: 1\n";
		return (1);
	}
	$split = explode(",", $line);
	$pass_time = intval($split[2]);
	$fail_time = intval($split[3]);
	if ($pass_time > $fail_time)
	{
		$test_time = $pass_time;
		$status = 3;
	}
	else
	{
		$test_time = $fail_time;
		$status = 0;
	}
	$test_outdated_time = get_test_outdated_time();
	if ($test_outdated_time == -1)
	{
		fwrite(STDERR, $argv[0].": Could not read test outdated time from config.ini. Ignoring history\n");
		//echo "returning 75: 1\n";
		return (1);
	}
	$outdated_time = $test_time + $test_outdated_time;
	if ($outdated_time < time())
	{
		//echo "returning 81: 2\n";
		return (2);
	}
	else
	{
		//echo "returning 86: $status\n";
		return ($status);
	}
}

?>
