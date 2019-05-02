
<img align="right"  src="https://i.imgur.com/tpVSrBr.png" width="45%" />  

# PFT

This is a unit test library and tester for ft\_printf.  

By default, it can check if your *completed* printf is pretty good or not pretty good.   

It's **more** useful as a production tool while you're developing ft\_prinf, because it lets you enable and disable entire blocks of tests at once, search and run tests by name and category, and in general perform quick regression testing. It's quick and easy to add your own tests, which I recommend on principle. It's built to be flexible, so you can use it how you wish.   

<p align="center">
  <img src="https://i.imgur.com/Iwsvc2Y.png" width="50%" />
</p>

## Requirements

You have to have a Makefile in your project directory that will compile libftprintf.a as the default make option, and your libftprintf.a has to have ft\_printf inside.

Other than this, it should be completely general to all ft\_printf projects.  

# Installation

In the root of your repo, run this command:

```
git clone https://github.com/gavinfielder/pft.git testing && echo "testing/" >> .gitignore
```

***If your libft.a is separate from libftprintf.a:***   
If you include all required .o files (including your libft) in libftprintf.a, this is not necessary. If you do NOT, and require your libft separate, you must set `USE_SEPARATE_LIBFT=1` in PFT's Makefile. See the PFT Makefile, and it should be self-explanatory.  

# Usage
 - `./test help` shows some help text and usage examples  
 - `./test help all` shows more help text  

The executable accepts the following as queries:
 - `./test moul` runs all the enabled tests whose name starts with a string, in this case 'moul'
 - `./test "d_*prec"` is a wildcard search; this one runs all the enabled tests that have start with 'd\_' and have 'prec' in the name.
 - `./test 42 84` runs (enabled) test #42 through test #84
 - `./test 42` runs test #42 (also turns on debugger compatibility mode.)
 - `./test` runs all the enabled tests
 - `./test -d [any of the above queries]` runs the selected test(s) in debugger compatibility mode.

Wildcard-based searches have an implict '\*' at the end. For example, `./test "*zeropad"` runs all the tests that have 'zeropad' anywhere in the name.

## Test Naming Conventions
These are the naming conventions currently used in the included unit\_tests.c.   
 - d, i, o, u, x, X, c, s, p, f tests start with `d_`, `i_`, `o_`, etc.
 - `%%` tests start with `pct_`
 - hh, h, l, ll tests usually have '`size`' in the name
 - L (long double) tests start with `f_L_`
 - `#` tests usually have '`af`' in the name (or '`altform`')
 - 0 (zero padding) tests usually have '`zp`' in the name
 - `-` (left justify) tests usually have '`lj`' in the name
 - `+` tests usually have '`as`' or '`allsign`' in the name
 - ' ' (space padding) tests usually have '`sp`' in the name
 - Precision tests usually have '`prec`' in the name
 - Field width tests usually have '`width`' or just '`w`' in the name
 - Simple tests usually have '`basic`' in the name
 - Tests taken from moulinette files start with `moul_`
 - The `moul_` block has subgroups `moul_d_`, `moul_i_`, `moul_o_`, etc.
 - Tests adapated from 42FileChecker have '`ftfc`' in the name   

These naming conventions are ***usually*** followed. There's a lot of tests, so making it more consistent is a huge task for another day. The first rule plus the `moul_` block are the two that most users care about, and they're both consistent.  

## Disclaimer about the `moul_` tests

They are outdated. At the very least, they were taken from before the subject recently changed. ***IN ADDITION*** more tests were added to moulinette to more sections than just `%f`. Do not think that by simply passing the `moul_` block, you will pass moulinette. Multiple people have already tried this and failed.  

## Workflow with PFT

unit\_tests.c shows you all the tests that are available. Failing a test means that your output and/or return value was not the same as the libc printf. When this happens, there will be a new file, 'test\_results.txt', that holds information about the failed test, the first line of code for the test (most of them are one line anyway), what printf printed, and what ft\_printf printed.  

### Adding Tests   

You can add your own tests to unit\_tests.c, following the same format. You do not need to do anything except write the function in this file and re-make. The new tests will be included in the test index and can be queried the same way.    

### Using PFT with LLDB or other debuggers
PFT compiles with debugging symbols by default, and also by default, running a single test e.g. `./test 42` turns on debugger compatibility mode. You can force all tests to run in debugger compatibility mode by using the `-d` command line option e.g. `./test -d nospec`. You can read more about command line options and debugger compatibility mode under [Advanced Options](#advanced-options).   

tl;dr: To use PFT with lldb, use it like this: `lldb ./test 42`.  

Of course, in order for lldb to read your own libftprintf.a, you must also use the `-g` flag in your own Makefile...

## Enabling and Disabling tests

I have provided scripts that make it easy to enable and disable tests by a search pattern. Example:

```bash
Simple prefix-based search:
 ./disable-test s                         # All the tests that start with 's' are disabled
 ./enable-test s_null_                    # All the tests that start with 's_null_' are enabled
 ./disable-test && ./enable-test s        # Disables all tests except tests that start with 's'

Wildcard search:
 ./disable-test "*zeropad"      # Disables all the tests that have 'zeropad' anywhere in the name
 ./enable-test "*null*prec"     # Enables all the tests that have a 'null' followed by a 'prec'
 ./enable-test "s_*prec"        # Enables all tests that start with 's_' and have a 'prec' in the name
```

You **can** call `./enable-test` (with no arguments) to enable all tests, but keep in mind that some tests are disabled by default because if you have not implemented certain bonuses, your ft\_printf will segfault.  

## Disabling Return Value Check

The PFT Makefile includes an option to ignore return value checking. I included this because at the time of writing this, moulinette does not check return value, and from what I've seen, the return value is the #1 reason people fail a lot of PFT tests. I don't encourage ignoring the return value, but it is an option if you would like to.  

# How it works, in Brief

The Makefile creates two copies of unit\_tests.c, one that uses ft\_printf, and one that uses printf. For each test, it redirects stdout to a file, then compares their return value. If the return value is identical, it opens both files and reads each one byte by byte until *both* reach EOF. If any single byte differs, the test fails.

# Advanced Options

These options are selected either in the PFT Makefile (to set the default run options) and/or as command line options. See below for a description of each optional feature.

| Option                          |  On  |  Off  | Note                                       |
|---------------------------------|------|-------|--------------------------------------------|
| Debugger compatibility Mode     | `-d` |       | default on for single tests, off otherwise |
| Timeout                         | `-t` | `-T`  | default on                                 |
| Test history logging            | `-l` | `-L`  | default on                                 |
| Do not write new test history   |      | `-W`  |                                            |
| Include recently failed tests   | `-f` | `-F`  | default on                                 |
| Test ONLY recently failed       | `-r` |       | default off                                |
| Include recently passed tests   | `-p` | `-P`  | default on                                 |
| Include outdated tests          | `-o` | `-O`  | default on                                 |
| Test ONLY outdated tests        | `-u` |       | default off                                |
| Include tests with no history   | `-n` | `-N`  | default on                                 |
| Test disabled tests             | `-a` | `-A`  | default off                                |
| Leaks test (BETA)               | `-k` | `-K`  | default off; turns off fork mode           |
| Fork mode                       | `-x` | `-X`  | default on                                 |
| Handle Signals                  | `-s` | `-S`  | default on (non-fork mode only)            |

### Debugger Compatibility Mode
Debuggers tend to only work well on single-threaded single processes, so "debugger compatibility mode" means "disable forking and multithreading". It also disables signal handling. `-d` is identical to `-XTS`. By default, debugger compatibility mode is turned on when running a single test e.g. `./test 42`.
### Timeout
Fails tests after a specified time interval. The timeout duration can be set in the PFT Makefile. Only available in fork mode.
### Test History Logging
test\_history.csv is a CSV file of records composed of test number, test name, timestamp of last pass, timestamp of lass fail. Turning this option on means that the test history will be read on start, will be written on completion (unless `-W` is specified), and that the options `-p`, `-f`, `-o`, and their negatives can filter which tests are run. The Makefile option `TEST_OUTDATED_TIME` determines how much time passes before tests become 'outdated'.  

The PFT Makefile removes test\_history.csv whenever unit\_tests.c is strictly newer, as this feature only remains coherent when the test numbers do not change. By default the enable-test and disable-test scripts, as they modify unit\_tests.c, will trigger such removal of test\_history.csv.

There is an option in the makefile to disable the history removal behavior, as well as an option in each of these scripts to touch test\_history.csv to prevent the removal trigger. 

### Leaks Test (BETA)
When this option is on, a leaks test command will run after all tests are completed. This disables fork mode. Leaks test will not run when any test segfaulted or otherwise terminated abnormally (as in this case leaks can come from PFT).
### Fork Mode
By default, PFT calls ft\_printf only on forked child processes to improve stability. Turning this option off means that tests will run in a single process and a single thread. Timeout is not available when fork mode is off.
### Handle Signals
(only applies to non-fork mode) When this option is off, signals will not be caught by PFT and PFT will stop immediately when a test aborts abnormally. When this option is on, abnormal terminations by certain signals will be caught by PFT and tests will continue running.    

## Options in Makefile
 - `TIMEOUT_SECONDS=(float)` (default 0.75) sets the number of seconds before any particular test times out.
- `DEFAULT_RUN_OPTIONS` (default `AfKloptx`) specifies the command-line options that are selected by default. These are overridden by any command line options given at execution time.
 - `IGNORE_RETURN_VALUE` (default 0) If this option is `0`, Tests fail if ft\_printf and printf do not have the same return value. If this option is `1`, the return value is ignored.
 - `REMOVE_HISTORY_WHEN_TESTS_NEW` (default 1) If this option is 1, the makefile will remove test\_history.csv whenever unit\_tests.c is strictly newer.
 - `LEAKS_TEST_CMD` The command to run when the leaks test (`-k`) is selected. The default value is  `system(\"leaks $(TEST_ONAME)\");`. 
 - `SINGLE_NUMBER_SINGLE_TEST` (default 1) When this option is 1, single numeric arguments given will run only the specified test number. When this option is 0 it makes it such that `./test 42` runs test #42 to the end of all enabled tests. This is a legacy feature, but could still be useful if you are using only your own tests and are writing them as you develop.  
 - `SINGLE_TEST_TURNS_ON_LLDB_COMPAT_MODE` (default 1) When this option is 1, (and `SINGLE_NUMBER_SINGLE_TEST`) is also 1, single tests also turn on debugger compatibility mode unless overridden at the command line.

# Troubleshooting

**I tried making and got a bunch of "undefined symbol" errors**  
Are these your libft functions? If so, you probably need to follow the installation directions under 'Installation' in order to include your libft.a separately from libftprintf.a  

**Help! Wildcard search isn't working!**  
For almost all shell terminals, the `*` needs to be escaped--usually, putting a string in double quotes is sufficient, but some terminals still treat it as a shell `*` even then. You can either escape it manually '`\*`', or, to make this feature compatible with all shells, I've made **any character not valid for a C function name (alphanumeric + underscore) is now considered a wildcard**. This means instead of `\*`, you can also use `@`, or anything else your terminal doesn't recognize as a special character. The same is true for the enable-test and disable-test scripts.

### Other Issues

If something goes wrong--slack me @gfielder. I like testing, like people using good testing, and want to make this easier to use, so don't hesitate to contact me.    

# Contributing

I encourage everyone to contribute to this, even if it's just adding tests to the library. To do this, fork and make pull requests.   

Before making pull requests, please:

```bash
./enable-test && ./disable-test argnum && ./disable-test moul_notmandatory \
&& ./disable-test nocrash && ./disable-test moul_D && ./disable-test moul_F \
&& ./disable-test f_reserved_values_ && ./disable-test f_L_reserved_values_
```
*and if you add non-mandatory test cases or tests that can segfault, modify this block in the readme*

# Possible Future Features

I have a few ideas how to improve this:

- The unit test library could stand to be a little more consistent and concise with naming conventions. 
- There are very few tests for the `*` bonus.  
- Could add tests for the thousands separator optional format flag.
- Could add tests for the `n` specifier.

Feel free to give me suggestions, or code them yourself and make a pull request.  

# Credits

The test method itself was adapted from outdated moulinette test files a buddy gave me, from which the author was ly@42.fr. The vast majority of code was written by me. The tests prefixed moul\_ were adapted from the moulinette test files, the tests with \_ftfc\_ were adapted from 42FileChecker, and all other tests (so far) were written by me.

Also thanks to:
- [rwright](https://github.com/wright08)
- phtruong
- [osfally](https://github.com/shaparder)
- [dfonarev](https://github.com/ruv1nce)  
for various suggestions and feature motivations.


