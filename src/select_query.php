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
#    Updated: 2019/05/06 16:57:55 by gfielder         ###   ########.fr        #
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

//echo $argv[0].": arguments given:\n";
//print_r($argv);

if ($argc != 7)
	exit_error("Wrong number of arguments given");
$unit_test_file = $argv[1];
$history_file = $argv[2];
$config_file = $argv[3];
$fnop = $argv[4];
$query = get_regex($argv[5]);
$mode = $argv[6];
if ($mode != "enable" && $mode != "disable")
	exit_error("Improper action given");

if ($fnop != "1111")
{
	try
	{
		include "src/select_history.php";
	}
	catch (Exception $e)
	{
		try
		{
			include "select_history.php";
		}
		catch (Exception $e2)
		{
			fwrite(STDERR, argv[0]." select_history.php not found. Ignoring history filters.");
			$fnop = "1111";
		}
	}
}

# ------------------------------------------------------------------------------
# Main
# ------------------------------------------------------------------------------

$fout = fopen($unit_test_file.".new", "w");
$fin = fopen($unit_test_file, "r");

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
				$disable = true;
				if ($fnop != "1111")
				{
					preg_match('/^\s*int\s+([a-zA-Z0-9_]+)\(void\).*$/', $line, $m2);
					if ($fnop[get_test_status($m2[1])] == '0')
						$disable = false;
				}
				if ($disable)
				{
					$line = " ".$line;
					$num++;
				}
			}
			else if (preg_match("/^\s*(int\s+".$query."\(void\).*)\$/", $line) === 1
				&& $line[0] != 'i' && $mode == "enable")
			{
				$enable = true;
				if ($fnop != "1111")
				{
					preg_match('/^\s*int\s+([a-zA-Z0-9_]+)\(void\).*$/', $line, $m2);
					if ($fnop[get_test_status($m2[1])] == '0')
						$enable = false;
				}
				if ($enable)
				{
					$line = $matches[1]."\n";
					$num++;
				}
			}
		}
		fwrite($fout, $line);
	}
	fwrite(STDOUT, $argv[0].": ".$mode."d ".$num." tests with names matching \"".$query."\"");
	if ($fnop != "1111")
	{
		$i = 0;
		echo " with history: ";
		if ($fnop[3])
		{
			if ($i > 0)
				echo ", ";
			$i++;
			echo "recently passed";
		}
		if ($fnop[0])
		{
			if ($i > 0)
				echo ", ";
			$i++;
			echo "recently failed";
		}
		if ($fnop[2])
		{
			if ($i > 0)
				echo ", ";
			$i++;
			echo "outdated";
		}
		if ($fnop[1])
		{
			if ($i > 0)
				echo ", ";
			$i++;
			echo "no history";
		}
	}
	echo "\n";


}
catch (Exception $e)
{
	fclose($fout);
	fclose($fin);
	unlink($unit_test_file.".new");
	exit_error("An error occurred. No changes were made. Error message: \"".($e->getMessage())."\"\n");
}
fclose($fout);
fclose($fin);
rename($unit_test_file.".new", $unit_test_file);

?>
