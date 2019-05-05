#!/usr/bin/php
<?php
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    select_numeric.php                                 :+:      :+:    :+:    #
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

try
{
	if ($argc != 5)
		exit_error("Wrong number of arguments given");
	$filename = $argv[1];
	if (!is_numeric($argv[2]) || !is_numeric($argv[3]))
		exit_error("Numeric arguments expected");
	$from = intval($argv[2]);
	$to = intval($argv[3]);
	$mode = $argv[4];
	if ($mode != "enable" && $mode != "disable")
		exit_error("Improper action given");

	$fout = fopen($filename.".new", "w");
	$fin = fopen($filename, "r");

	$i = 0;
	$num = 0;
}
catch (Exception $e)
{
	if (isset($fout))
		fclose($fout);
	if (isset($fin))
		fclose($fin);
	if (file_exists($filename.".new"))
		unlink($filename.".new");
	exit_error("An error occurred. No changes were made. Error message: \"".($e->getMessage())."\"\n");
}

# ------------------------------------------------------------------------------
# Main
# ------------------------------------------------------------------------------

try
{
	while ($line = fgets($fin))
	{
		if (preg_match('/^\s*(int\s+[a-zA-Z0-9_]+\(void\).*)$/', $line, $matches))
		{
			//found test line
			if ($i >= $from && $i <= $to
				&& $line[0] == 'i' && $mode == "disable")
			{
				$line = " ".$line;
				$num++;
			}
			else if ($i >= $from && $i <= $to
				&& $line[0] != 'i' && $mode == "enable")
			{
				$line = $matches[1]."\n";
				$num++;
			}
			$i++;
		}
		fwrite($fout, $line);
	}
	if ($to > $i - 1)
		$to = $i - 1;
	fwrite(STDOUT, $argv[0].": ".$mode."d $num tests from $from to $to.\n");
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
