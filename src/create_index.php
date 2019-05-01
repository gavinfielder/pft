#!/usr/bin/php
<?php
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    create_index.php                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 03:57:40 by gfielder          #+#    #+#              #
#    Updated: 2019/05/01 03:57:40 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if ($argc != 3)
	exit(-1);
$unit_tests_file = $argv[1];
$output_indexed = $argv[2];


$fout = fopen($output_indexed, "w");
$test_file_contents = file_get_contents($unit_tests_file);

/* ---------------------------------------------------------------------- *
 * Create Unit tests
 * ---------------------------------------------------------------------- */

$pattern[0] = '/\stest\(/';
$replace[0] = ' ft_printf(';
$out = preg_replace($pattern, $replace, $test_file_contents);
fwrite($fout, $out);
unset($out);

/* ---------------------------------------------------------------------- *
 * Create Bench tests
 * ---------------------------------------------------------------------- */

$pattern[0] = '/^\s*(int\s+[a-zA-Z0-9_]+)\(void\)/m';
$replace[0] = '${1}_bench(void)';
$pattern[1] = '/\stest\(/';
$replace[1] = ' printf(';
$pattern[2] = '/^.*?static.*?$/m';
$replace[2] = '';
$out = preg_replace($pattern, $replace, $test_file_contents);
fwrite($fout, $out);
unset($out);

/* ---------------------------------------------------------------------- *
 * Get the test index
 * ---------------------------------------------------------------------- */
$test_index = "const t_test_entry g_unit_tests[] = {\n";
$fin = fopen($unit_tests_file, "r");
$i = 0;
$num_enabled = 0;
$num_disabled = 0;
while ($line = fgets($fin))
{
	preg_match('/^\s*int\s+([a-zA-Z0-9_]+)\(void\)(.*$)/', $line, $matches);
	if (!isset($matches[1]))
		continue ;
	$test_index .= "\t{";
	if (preg_match('/^int\s+([a-zA-Z0-9_]+)\(void\)/', $line) === 0)
	{
		$test_index .= "0, ";
		$num_disabled++;
	}
	else
	{
		$test_index .= "1, ";
		$num_enabled++;
	}
	$test_index .= ($i++) . ", ";
	$test_index .= "\"$matches[1]\"" . ", ";
	$test_index .= $matches[1] . ", ";
	$test_index .= $matches[1] . "_bench, ";
	$tmp = preg_replace('/\\"/', 'TEMP_ESCAPED_QUOTE', $matches[2]);
	$tmp = preg_replace('/"/', '\\"', $tmp);
	$tmp = preg_replace('/TEMP_ESCAPED_QUOTE/', '\\\\"', $tmp);
	$test_index .= "\"$tmp\"";
	$test_index .= "},\n";
}
$test_index .= "\t{0, 2147483647, NULL, NULL, NULL, NULL}\n};\n\n";
fclose($fin);
$number_of_tests = $i;

fwrite($fout, $test_index);
unset($test_index);

fclose($fout);

exit(0);

?>
