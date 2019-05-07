#!/usr/bin/php
<?php
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    select_router.php                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/04 19:16:36 by gfielder          #+#    #+#              #
#    Updated: 2019/05/04 19:16:36 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

function	exit_error($msg, $status = -1)
{
	global $argv;

	fwrite(STDERR, $argv[0].": ".$msg."\n");
	exit ($status);
}

function	route_select($script, $unit_test_file, $history_file, $config_file, $mode, $fnop, $arg1, $arg2 = "")
{
	system("php $script $unit_test_file $history_file $config_file $fnop $arg1 $arg2 $mode", $ret);
	exit ($ret);
}

function	unset_argv5()
{
	global $argc;
	global $argv;
	$fnop = "1111";

	$i = 5;
	while (isset($argv[$i + 1]))
	{
		$argv[$i] = $argv[$i + 1];
		$i++;
	}
	unset($argv[$i]);
	$argc--;
}

function	make_fnop_filter()
{
	global $argc;
	global $argv;
	$fnop = "1111";

	if ($argc < 6)
		return ($fnop);
	while ($argc >= 6 && ($argv[5][0] == '-' || $argv[5][0] == '=' || $argv[5][0] == '+'))
	{
		//Parse options
		$i = 0;
		while ($i < strlen($argv[5]))
		{
			$j = -1;
			if ($argv[5][$i] == '+')
			{
				$mode = "include";
				$j = -2;
			}
			else if ($argv[5][$i] == '=')
			{
				$fnop = "0000";
				$mode = "include";
				$j = -2;
			}
			else if ($argv[5][$i] == '-')
			{
				$mode = "exclude";
				$j = -2;
			}
			else if ($argv[5][$i] == 'f')
				$j = 0;
			else if ($argv[5][$i] == 'n')
				$j = 1;
			else if ($argv[5][$i] == 'o')
				$j = 2;
			else if ($argv[5][$i] == 'p')
				$j = 3;
			if ($j == -1)
				break ;
			if ($j >= 0 && $j <= 3 && isset($mode))
			{
				if ($mode == "include")
					$fnop[$j] = '1';
				else if ($mode == "exclude")
					$fnop[$j] = '0';
			}
			$i++;
		}
		unset_argv5();
	}
	return ($fnop);
}

//echo "before: argc=$argc\n";
//print_r($argv);

$fnop = make_fnop_filter();

//echo "after: argc=$argc and fnop=\"$fnop\"\n";
//print_r($argv);

if ($argc < 5)
	exit_error("Too few arguments");
else if ($argc == 5)
{
	$mode = $argv[1];
	$unit_test_file = $argv[2];
	$history_file = $argv[3];
	$config_file = $argv[4];
	$from = 0;
	$to = 2147483647;
	$script = preg_replace('/select_router/', 'select_numeric', $argv[0]);
	route_select($script, $unit_test_file, $history_file, $config_file, $mode, $fnop, $from, $to);
}
else if ($argc == 6 && is_numeric($argv[5]))
{
	$mode = $argv[1];
	$unit_test_file = $argv[2];
	$history_file = $argv[3];
	$config_file = $argv[4];
	$from = $argv[5];
	$to = $argv[5];
	$script = preg_replace('/select_router/', 'select_numeric', $argv[0]);
	route_select($script, $unit_test_file, $history_file, $config_file, $mode, $fnop, $from, $to);
}
else if ($argc == 6)
{
	$mode = $argv[1];
	$unit_test_file = $argv[2];
	$history_file = $argv[3];
	$config_file = $argv[4];
	$query = $argv[5];
	$script = preg_replace('/select_router/', 'select_query', $argv[0]);
	route_select($script, $unit_test_file, $history_file, $config_file, $mode, $fnop, $query);
}
else if ($argc == 7)
{
	$mode = $argv[1];
	$unit_test_file = $argv[2];
	$history_file = $argv[3];
	$config_file = $argv[4];
	$from = $argv[5];
	$to = $argv[6];
	if (!is_numeric($from) || !is_numeric($to))
		exit_error("$from $to: two arguments expect numeric range");
	$script = preg_replace('/select_router/', 'select_numeric', $argv[0]);
	route_select($script, $unit_test_file, $history_file, $config_file, $mode, $fnop, $from, $to);
}
else
{
	exit_error("Too many arguments");
}

?>
