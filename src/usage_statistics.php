#!/usr/bin/php
<?php

/*
 * This script sends a hash of your username and which campus you are on.
 * If the campus is not Fremont or Paris, your hostname is sent instead.
 * The google forms request also logs the timestamp. You can disable this by
 * setting SEND_USAGE_STATISTICS=0 in options-config.ini
 */

define("PFT_ROOT", dirname(__FILE__, 2));
if (file_exists(PFT_ROOT."/options-config.ini.override"))
	define("CONFIG_FILE", PFT_ROOT."/options-config.ini.override");
else
	define("CONFIG_FILE", PFT_ROOT."/options-config.ini");

$enabled = intval(trim(shell_exec("cat ".CONFIG_FILE." | grep 'SEND_USAGE_STATISTICS' | cut -d '=' -f 2")));

//If the above command failed, this will also evaluate true and exit
if (!($enabled))
	exit(0);

//Get the current configuration name
$config_name = rawurlencode(trim(shell_exec("cat ".CONFIG_FILE." | grep 'CONFIG_NAME' | cut -d '=' -f 2")));

//Detect if this is a first-time install or a re-make
if (file_exists(PFT_ROOT."/src/usage_statistics_installed.txt"))
	$install = "no";
else
{
	$install = "yes";
	shell_exec("echo \"The existence of this file is used to detect whether a make is a first make or a re-make.\" > ".PFT_ROOT."/src/usage_statistics_installed.txt");
}

$hostname = shell_exec("hostname");
if ($hostname == NULL)
	$hostname = rawurlencode("Could not get host name");

//Attempt to resolve campus from hostname
if (strpos($hostname, "42.us.org") > 0)
	$location = "Fremont";
else if (strpos($hostname, "42.fr") > 0)
	$location = "Paris";
else if (strpos($hostname, ".21-school.ru") > 0)
	$location = "Moscow";
else
	$location = $hostname;

//Get a hash of username
$username = shell_exec("whoami");
if ($username == NULL)
	$username_hash = rawurlencode("Could not get username");
else
	$username_hash = sha1($username);

//Remove username and hostname data
unset($username);
unset($hostname);

//Submit google form with this data
$url = "https://docs.google.com/forms/d/e/1FAIpQLSdwJSs9uPo93TYhyHH7PLZacAntDB4HsHq1vI2Bntxa13xCbw/formResponse?entry.1758027586=$username_hash&entry.1838934565=$location&entry.417295195=$install&entry.1646729038=$config_name&submit=Submit";

file_get_contents($url);

?>
