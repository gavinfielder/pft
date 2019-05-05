#!/usr/bin/php
<?php
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    select_query.php                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/04 16:57:55 by gfielder          #+#    #+#              #
#    Updated: 2019/05/04 16:57:55 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# Error checking and initial setup
# ------------------------------------------------------------------------------

function	exit_error($msg, $status = -1)
{
	global $argv;

	fwrite(STDERR, $argv[0].": ".$msg."\n");
	exit ($status);
}

function	get_regex($query)
{
	$ret = preg_replace('/[^a-zA-Z0-9_]/', '.*', $query);
	return ($ret.'.*');
}

if ($argc != 4)
	exit_error("Wrong number of arguments given");
$filename = $argv[1];
$query = get_regex($argv[2]);
$mode = $argv[3];
if ($mode != "enable" && $mode != "disable")
	exit_error("Improper action given");

# ------------------------------------------------------------------------------
# Main
# ------------------------------------------------------------------------------

$fout = fopen($filename.".new", "w");
$fin = fopen($filename, "r");

$num = 0;

try
{
	while ($line = fgets($fin))
	{
		if (preg_match('/^\s*(int\s+[a-zA-Z0-9_]+\(void\).*)$/', $line, $matches))
		{
			//found test line
			if (preg_match("/^\s*(int\s+".$query."\(void\).*)\$/", $line) === 1
				&& $line[0] == 'i' && $mode == "disable")
			{
				$line = " ".$line;
				$num++;
			}
			else if (preg_match("/^\s*(int\s+".$query."\(void\).*)\$/", $line) === 1
				&& $line[0] != 'i' && $mode == "enable")
			{
				$line = $matches[1]."\n";
				$num++;
			}
		}
		fwrite($fout, $line);
	}
	fwrite(STDOUT, $argv[0].": ".$mode."d ".$num." tests with names matching \"".$query."\"\n");
}
catch (Exception $e)
{
	fclose($fout);
	fclose($fin);
	unlink($filename.".new");
	exit_error("An error occurred. No changes were made. Error message: \"".($e->getMessage())."\"\n");
}
fclose($fout);
fclose($fin);
rename($filename.".new", $filename);

?>
