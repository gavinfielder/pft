
<img align="right"  src="https://i.imgur.com/tpVSrBr.png" width="45%" />  

# PFT

This is a unit test library and configurable tester for the 42 project ft\_printf.  

By default, it can check if your *completed* printf is pretty good or not pretty good.   

It's **more** useful as a production tool while you're developing ft\_prinf, because it lets you enable and disable entire blocks of tests at once, search and run tests by name, category, and previous run history, and in general perform quick regression testing. It's quick and easy to add your own tests, which I recommend on principle. It's built to be flexible and highly configurable, so you can use it how you wish.   

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

# Usage
 - `./test s` runs all the tests that start with a string, in this case 's'. As you might guess, the `%s` tests start with 's'. Tests for the other specifiers (`%d`, `%f`, etc.) can be selected the same way.
 - `./test 42` runs test #42
 - `./test 42 84` runs all the enabled tests from #42 to #84
 - `./test` runs all the enabled tests
 - `./test help` shows examples and other help information.

You can also run specific types of tests by using [Wildcard Search](https://github.com/gavinfielder/pft/wiki/Wildcard-Search). See also [Test Naming Conventions](https://github.com/gavinfielder/pft/wiki/Test-Naming-Conventions).


<p align="center">
  <img src="https://i.imgur.com/uk5L1Hy.png" width="55%" />
</p>

When you fail a test, the file `results.txt` will show the results of the test including the first line of code for the test (most of them are one line anyway), the return values, what printf printed, and what ft\_printf printed.

<p align="center">
  <img src="https://i.imgur.com/6MtOZJR.png" width="65%" />
</p>


## Enabling and Disabling tests

I have provided scripts that make it easy to enable and disable tests. These scripts accept the same queries as the `./test` executable.  

 - `./disable-test s` Disables all tests that start with 's'
 - `./enable-test nocrash` Enables all tests that start with 'nocrash'
 - `./disable-test 42 84` Disables all tests from #42 to #84
 - `./disable-test && ./enable-test s` Disables all tests except tests that start with 's'.

You **can** call `./enable-test` (with no arguments) to enable all tests, but keep in mind that some tests are disabled by default because if you have not implemented certain bonuses, your ft\_printf will segfault.  

## Using PFT with LLDB or other debuggers

[Debugger compatibility mode](https://github.com/gavinfielder/pft/wiki/Debugger-Compatibility-Mode) ( `-d` ) is automatically turned on for single tests:   

`lldb ./test 42`   

# Known Issues

Fork mode (`-x`) used in conjunction with `IGNORE_RETURN_VALUE=0` is currently not properly reporting expected return value in results.txt for many tests ([issue #11](https://github.com/gavinfielder/pft/issues/11)). This bug does not affect the pass/fail result of a test. Running in non-fork mode (`-X`) will show the correct return values. The default configuration has been set to `IGNORE_RETURN_VALUE=1`. If this issue might affect you, a warning will be printed in results.txt.

# How it works, in Brief

The Makefile creates two versions of each unit test function, one that uses ft\_printf, and one that uses printf. For each test, it redirects stdout to a file, calls the function. Once each version returns, it opens both files and reads each one byte by byte until *both* reach EOF. If any single byte differs, the test fails.  

# What's NOT Covered
Feel free to contribute tests for these bonuses:

 - Size modifiers `t`, `z`, `j`, and `q`.
 - `%n`
 - `'` (thousands separator flag)
 - `$` for dynamic precision. (`$` for argument selection is covered under `argnum_`)
### What's not covered very well
 - `*` (4 tests)
 - `%g`, `%e`, `%a` (some tests exist in the `moul` block, but they are not rigorously tested with flag combinations like the other tests)

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

The test method itself was adapted from outdated moulinette test files a buddy gave me, from which the author was ly@42.fr. The vast majority of code was written by me. The tests prefixed moul\_ were adapted from the moulinette test files, the tests with \_ftfc\_ were adapted from 42FileChecker. The vast majority of tests were written by me; some tests were contributed by [phtruong](https://github.com/nkone), [akharrou](https://github.com/akharrou), and [robbie](https://github.com/rpeepz).

Also thanks to:
- [rwright](https://github.com/wright08)
- [osfally](https://github.com/shaparder)
- [dfonarev](https://github.com/ruv1nce)  
for various suggestions and feature motivations.
