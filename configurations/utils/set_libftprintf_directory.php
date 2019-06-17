#!/usr/bin/php
<?php

if ($argc != 2)
{
	fwrite(STDERR, "usage: set_project_directory.php path/to/ft_printf\n");
	exit(-1);
}

$ft_printf_dir = $argv[1];
$pft_root = dirname(__FILE__, 2);
$conf = file_get_contents($pft_root."/options-config.ini");
$conf = preg_replace('/LIBFTPRINTF_DIR=.*$/m', "LIBFTPRINTF_DIR=".$ft_printf_dir, $conf);
$fout = fopen($pft_root."/options-config.ini", "w");
fwrite($fout, $conf);
fclose($fout);

?>
