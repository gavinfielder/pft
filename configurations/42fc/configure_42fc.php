#!/usr/bin/php
<?php

if ($argc != 2)
{
	fwrite(STDERR, "usage: configure_42fc.php path/to/ft_printf\n");
	exit(-1);
}
$pft_root = dirname(__FILE__, 3);
$conf42fc_root = dirname(__FILE__, 1);

//Get ft_printf directory passed from 42FileChecker
$ft_printf_dir = $argv[1];

//Write ft_printf directory to an override config file based on 42fc configuration
$conf = file_get_contents($conf42fc_root."/42fc.conf");
$conf = preg_replace('/LIBFTPRINTF_DIR=.*$/m', "LIBFTPRINTF_DIR=".$ft_printf_dir, $conf);
$fout = fopen($pft_root."/options-config.ini.override", "w");
fwrite($fout, $conf);
fclose($fout);

//Copy the 42fc unit tests file to the root directory
system("cp ".$conf42fc_root."/unit_tests.42fc.c ".$pft_root."/unit_tests.42fc.c");

?>
