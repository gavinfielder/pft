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

function	route_select($script, $file, $mode, $arg1, $arg2 = "")
{
	system("php $script $file $arg1 $arg2 $mode", $ret);
	exit ($ret);
}

if ($argc < 3)
	exit_error("At least two arguments expected");
else if ($argc == 3)
{
	$mode = $argv[1];
	$file = $argv[2];
	$from = 0;
	$to = 2147483647;
	$script = preg_replace('/select_router/', 'select_numeric', $argv[0]);
	route_select($script, $file, $mode, $from, $to);
}
else if ($argc == 4 && is_numeric($argv[3]))
{
	$mode = $argv[1];
	$file = $argv[2];
	$from = $argv[3];
	$to = $argv[3];
	$script = preg_replace('/select_router/', 'select_numeric', $argv[0]);
	route_select($script, $file, $mode, $from, $to);
}
else if ($argc == 4)
{
	$mode = $argv[1];
	$file = $argv[2];
	$query = $argv[3];
	$script = preg_replace('/select_router/', 'select_query', $argv[0]);
	route_select($script, $file, $mode, $query);
}
else if ($argc == 5)
{
	$mode = $argv[1];
	$file = $argv[2];
	$from = $argv[3];
	$to = $argv[4];
	if (!is_numeric($from) || !is_numeric($to))
		exit_error("$from $to: two arguments expect numeric range");
	$script = preg_replace('/select_router/', 'select_numeric', $argv[0]);
	route_select($script, $file, $mode, $from, $to);
}
else
{
	exit_error("Too many arguments");
}

?>
