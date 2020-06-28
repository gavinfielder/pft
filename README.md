<img align="right"  src="https://i.imgur.com/tpVSrBr.png" width="45%" />  

# PFT

This is a unit test library and configurable tester for the 42 project ft\_printf.  

It is designed to be a regression testing utility--that is, it is meant to be used while you are developing. It lets you select specific tests and test groups to run, enable and disable entire blocks of tests at once, or even select tests based on previous run/pass/fail history. It's quick and easy to add your own tests, which I must recommend for the principle of it--but its original name (printftester2000) reflected that there are over 2000 tests available already. Regardless, it's built to be flexible and highly configurable, so you can use it how you wish.   

<p align="center">
  <img src="https://i.imgur.com/oFAc9EQ.png" width="60%" />
</p>

## Requirements

You have to have a Makefile in your project directory that will compile libftprintf.a as the default make option, and your libftprintf.a has to have ft\_printf inside.

Other than this, it should be completely general to all ft\_printf projects.  

### System Requirements (for computers outside the lab)
Requires PHP. All 42 lab computers should have PHP installed. See also [Compatibility with Other Systems](https://github.com/gavinfielder/pft/wiki/Compatibility-with-Other-Systems).

# Installation

In the root of your repo, run this command:

```
git clone https://github.com/gavinfielder/pft.git pft && echo "pft/" >> .gitignore
```
For most users, that is all that is required.  

### If your libft.a is separate from libftprintf.a   
If you include all required .o files (including your libft) in libftprintf.a, this is not necessary. If you do NOT, and require your libft separate, you must set `USE_SEPARATE_LIBFT=1` in options-config.ini, and make sure the path is correct. See options-config.ini, and it should be self-explanatory.  

For non-standard installation options, see [Installation](https://github.com/gavinfielder/pft/wiki/Installation).

### If you are running on Linux
Change `INCLUDE_LIBPTHREAD=0` in `options-config.ini` to `INCLUDE_LIBPTHREAD=1`.  

This could apply to other systems--if you get a make error with undefined refrences to `pthread_` functions, make this change and it will work.

# Usage

Every test has a name and a number. You select tests or groups of tests to run based on either a name search or a number range. Name searches will look for tests that start with the given string. Groups of tests are organized with their names so that they can be selected easily in this way.  

 - `./test s` runs all the tests that start with 's'. As you might guess, the `%s` tests start with 's'. Tests for the other specifiers (`%d`, `%p`, etc.) can be selected the same way.
 - `./test 42` runs test #42 only
 - `./test 42 84` runs all the enabled tests from #42 to #84
 - `./test` runs all the enabled tests
 - `./test help` shows examples and other help information.

You can also run specific types of tests by using [Wildcard Search](https://github.com/gavinfielder/pft/wiki/Wildcard-Search), for example `./test "d*prec"` will run all the `%d` tests that have `prec` in their name, which selects `%d` tests that use precision (`.`). See [Test Naming Conventions](https://github.com/gavinfielder/pft/wiki/Test-Naming-Conventions) for a reference on selecting tests in more detail.  


<p align="center">
  <img src="https://i.imgur.com/uk5L1Hy.png" width="55%" />
</p>

When you fail a test, the file `results.txt` will show the results of the test including the first line of code for the test (most of them are one line anyway), the return values, what printf printed, and what ft\_printf printed.

<p align="center">
  <img src="https://i.imgur.com/6MtOZJR.png" width="65%" />
</p>


## Enabling and Disabling tests

I have provided scripts that make it easy to enable and disable tests. "Disabled" tests mean they will never run unless you force them to with `-a`. These enable-test and disable-test scripts accept the same queries as the `./test` executable, that is, querying on the name or using a numeric range.  

 - `./disable-test s` Disables all tests that start with 's'
 - `./enable-test nocrash` Enables all tests that start with 'nocrash'
 - `./disable-test 42 84` Disables all tests from #42 to #84
 - `./disable-test && ./enable-test s` Disables all tests except tests that start with 's'.

You **can** call `./enable-test` (with no arguments) to enable all tests, but since you are probably not crazy enough to actually implement everything that the test library can possibly test, that is generally a bad idea.  

If you want to reset to the default state of enabled tests, `./reset-to-default-enabled-tests`  

## Enabling Bonus Tests (and others)

 - `./enable-test bonus` will enable all tests that test bonuses  
 - `./enable-test bonus && ./disable-test bonus_notrequired` will enable bonus tests, but not tests that are not necessary to pass for moulinette to validate the bonus  
 - `./enable-test "bonus*_f_"` will enable `%f` tests. (Similarly for `%g` and `%e`)  
 - `./enable-test bonus_length` will enable tests for `l` `ll` `h` `hh`  
 - `./enable-test bonus_af` will enable tests for `#` (`af` is short for alternate form)  
 - `./enable-test bonus_sp` will enable tests for ` ` (`sp` is short for space padding)  
 - `./enable-test bonus_as` will enable tests for `+` (`as` is short for always sign)  
 - `./enable-test nocrash` will enable tests that test your `ft_printf`'s ability to handle bad input (will pass as long as it doesn't crash) While they are disabled by default and may be irrelevant to moulinette, I suggest that handling bad input is in fact a mandatory requirement of the subject which evaluators may opt to grade you on, so I personally recommend that everyone enable these.  

There are many tests not covered by the above examples.  

 - `./show-disabled-tests` will print a list of all tests currently disabled. This may help to know what non-mandatory tests are available, which you can use the enable- and disable-test scripts to select by name or wildcard search as in the above examples. See also [Test Naming Conventions](https://github.com/gavinfielder/pft/wiki/Test-Naming-Conventions).  

## Using PFT with LLDB or other debuggers

[Debugger compatibility mode](https://github.com/gavinfielder/pft/wiki/Debugger-Compatibility-Mode) ( `-d` ) is automatically turned on for single tests:   

`lldb ./test 42`   

# Known Issues

The 2020 update added `*` tests to the required features. Tests were added from https://github.com/cclaude42/PFT_2019, but these tests don't include enough combinations with other flags--looking for current 42 students to add such tests.  
  
Fork mode (`-x`) used in conjunction with `IGNORE_RETURN_VALUE=0` is currently not properly reporting expected return value in results.txt for many tests ([issue #11](https://github.com/gavinfielder/pft/issues/11)). This bug does not affect the pass/fail result of a test. Running in non-fork mode (`-X`) will show the correct return values. The default configuration has been set to `IGNORE_RETURN_VALUE=1`. If this issue might affect you, a warning will be printed in results.txt.

# How it works, in Brief

The Makefile creates two versions of each unit test function, one that uses ft\_printf, and one that uses printf. For each test, it redirects stdout to a file, calls the function. Once each version returns, it opens both files and reads each one byte by byte until *both* reach EOF. If any single byte differs, the test fails. If `IGNORE_RETURN_VALUE` is set to `0`, the test will also fail if the return values between printf and ft\_printf differ.  

Tests starting with `nocrash` are handled differently: these tests will pass as long as ft\_printf does not crash while executing them.  

# What's NOT Covered
Feel free to contribute tests for these:

 - Size modifiers `t`, `z`, `j`, and `q`.
 - `%n`
 - `'` (thousands separator flag)
 - `$` for dynamic precision. (`$` for argument selection is covered under `argnum_`)
 ### What's not covered very well
 - `*` (There are some tests, but not many combinations with other flags)
 - `%a` (some tests exist in the `moul` block, but they are not rigorously tested with flag combinations like the other tests)

### Note on coverage for OS differences
There are differences between printf(3) between systems. One common difference is the printing of null pointers--there can be others.   

ft\_printf is now being developed on other systems due to 42 working remotely as it deals with the Covid-19 pandemic. Moulinette tests your ft\_printf against its own system's printf. That makes the project system-dependent and since PFT uses the same testing method as moulinette, it will not be able to tell you if your ft\_printf will fail because you neglected to test on lab computers. 

You must test on your lab's computers prior to submission.   

# Other Documentation

The full documentation is available in the [Wiki](https://github.com/gavinfielder/pft/wiki). Here are some quick links:

 - [Installation](https://github.com/gavinfielder/pft/wiki/Installation)
 - [Usage](https://github.com/gavinfielder/pft/wiki/Usage)
   - [Wildcard Search](https://github.com/gavinfielder/pft/wiki/Wildcard-Search)
   - [Test Naming Conventions](https://github.com/gavinfielder/pft/wiki/Test-Naming-Conventions)
 - [What's Not Covered](https://github.com/gavinfielder/pft/wiki/What's-Not-Covered)
 - Workflow with PFT
   - [Enabling and Disabling Tests](https://github.com/gavinfielder/pft/wiki/Enabling-and-Disabling-Tests)
   - [Adding Tests](https://github.com/gavinfielder/pft/wiki/Adding-Tests)
 - Options and Configuration
   - [Run Options](https://github.com/gavinfielder/pft/wiki/Run-Options)
   - [Configuration Options](https://github.com/gavinfielder/pft/wiki/Configuration-Options)
   - [Configuration Guide](https://github.com/gavinfielder/pft/wiki/Configuration-Guide)
 - Additional Features
   - [Debugger Compatibility Mode](https://github.com/gavinfielder/pft/wiki/Debugger-Compatibility-Mode)
   - [Test History Logging](https://github.com/gavinfielder/pft/wiki/Test-History-Logging)
   - [Leaks Test (BETA)](https://github.com/gavinfielder/pft/wiki/Leaks-Test-(BETA))
 - [Troubleshooting](https://github.com/gavinfielder/pft/wiki/Troubleshooting)
 - [Compatibility With Other Systems](https://github.com/gavinfielder/pft/wiki/Compatibility-with-Other-Systems)
 - [Contributing to this repo (and possible future features)](https://github.com/gavinfielder/pft/wiki/Contributing-(and-possible-future-features))
 
## Todo List for the Unit Test Library
I occasionally get suggestions for the unit test library. I keep this list to keep track of what I want to do the next time I modify unit\_tests.c  
[Todo List for the Unit Test Library](https://github.com/gavinfielder/pft/issues/2)

# Usage Statistics

By default, PFT collects some usage statistics on every `make`. The full list of data collected is:
 - A SHA-1 hash of your `whoami` username.
 - Whether you're on the Fremont, Paris, or Moscow campus, or your `hostname` if none of those.
 - Whether it is a first install or a re-make.
 - The name of your configuration (`CONFIG_NAME` in options-config.ini)  

You can disable this behavior in options-config.ini, and/or see exactly what the script does in src/usage\_statistics.php. My reason in doing this is to have real usage data to show recruiters and hiring managers. If you're a 42 student and want to know more or see the collected data, feel free to message me on slack.

# Credits

The test method itself was adapted from outdated moulinette test files a buddy gave me, from which the author was ly@42.fr. The vast majority of code was written by me. The tests prefixed moul\_ were adapted from the moulinette test files, the tests with \_ftfc\_ were adapted from 42FileChecker. Many tests were written by me; tests were contributed by [phtruong](https://github.com/nkone), [akharrou](https://github.com/akharrou), [robbie](https://github.com/rpeepz), and [mgiraldo](https://github.com/michaelgiraldo). Big thanks to [cclaude](https://github.com/cclaude42) for doing the first update for the new curriculum, and bigger to [apuchill](https://github.com/appinha) for reorganizing the test library and adding tests for the new curriculum.  


Also thanks to:
- [rwright](https://github.com/wright08)
- [osfally](https://github.com/shaparder)
- [dfonarev](https://github.com/ruv1nce)  
for various suggestions and feature motivations.
