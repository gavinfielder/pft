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
If you include all required .o files (including your libft) in libftprintf.a, this is not necessary. If you do NOT, and require your libft separate, you must set `USE_SEPARATE_LIBFT=1` in PFT's Makefile.   

# Usage
 - `./test help` shows some help text and usage examples  
 - `./test help all` shows more help text  

The executable accepts the following as queries:
 - `./test moul` runs all the enabled tests whose name starts with a string, in this case 'moul'
 - `./test "*prec"` runs all the enabled tests that have 'prec' in the name.
 - `./test 42 84` runs (enabled) test number 42 through test 84
 - `./test 42` runs enabled tests 42 onward
 - `./test` runs all the enabled tests

Wildcard-based searches have an implict '\*' at the end. For example, `./test "*zeropad"` runs all the tests that have 'zeropad' anywhere in the name.

## Test Naming Conventions
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

## A Note on Wildcard Searching

For almost all shell terminals, the `*` needs to be escaped--usually, putting a string in double quotes is sufficient, but some terminals still treat it as a shell `*` even then. You can either escape it manually '`\*`', or, to make this feature compatible with all shells, I've made **any character not valid for a C function name (alphanumeric + underscore) is now considered a wildcard**. This means instead of `\*`, you can also use `@`, or anything else your terminal doesn't recognize as a special character. The same is true for the enable-test and disable-test scripts.

## Workflow with PFT

unit\_tests.c shows you all the tests that are available. Failing a test means that your output and/or return value was not the same as the libc printf. When this happens, there will be a new file, 'test\_results.txt', that holds information about the failed test, the first line of code for the test (most of them are one line anyway), what printf printed, and what ft\_printf printed.  

You can add your own tests to unit\_tests.c, following the same format. You do not need to do anything except write the function in this file and remake. The new tests will be included in the test index and can be queried the same way.  

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

# Troubleshooting

If something goes wrong--slack me @gfielder. I like testing, like people using good testing, and want to make this easier to use, so don't hesitate to contact me.  

# Contributing
I encourage everyone to contribute to this, even if it's just adding tests to the library. To do this, fork and make pull requests.   

Before making pull requests, please:

```bash
./enable-test && ./disable-test argnum && ./disable-test moul_notmandatory \
&& ./disable-test nocrash && ./disable-test moul_D && ./disable-test moul_F \
&& ./disable-test f_l_reserved_value && ./disable-test f_L_reserved_value
```
*and if you add non-mandatory test cases or tests that can segfault, modify this block in the readme*

# How it works
### ...for those who want knowledge and power (or maybe just want to use it to do something specific)

When you run make, the first thing that happens is the test index is created. Two copies of unit\_tests.c are created. In the copy unit\_tests\_indexed.c, the test() function is replaced with ft\_printf(). In the copy unit\_tests\_benched.c, the test() function is replaced with printf() and '\_bench' is added to all the function names. Next, in both files, an array of function pointers is created at the end of the file pointing to all the enabled unit tests.   An array will also be created holding the names of all the functions as string literals.  

When you call `./test s_`, main.c will see alpha input and call run\_search\_tests, which does a match comparison on each position in the array of function names, and when it finds a function name starting with 's\_', it calls run\_test() on that test.  

run\_test() runs a particular test. The way the test works is that it redirects stdout to a file, calls the ft\_printf version (through the array of function pointers that was created on `make`), and does the same with the printf version. It compares the return value and the content of the files, and if either is different, the test is failed. This is very essentially the same way moulinette tests printf (though I suspect moulinette doesn't check return value). The diff is logged to file and a red FAIL is printed instead of a pretty green PASS.  

There are some user options in the makefile, you can explore them yourself.

# Possible Future Features

I have a few ideas how to improve this:

- disable-test could be able to disable a numeric range of tests, or a specific test by number
- Could add a more generalized unit test framework alongside the current one that gives you more control in coming up with unit tests
- Could add tests for the thousands separator optional format flag.
- Could add tests for the `n` specifier.

Feel free to give me suggestions, or code them yourself and make a pull request.  

# Credits

Some code was adapted from moulinette test files a buddy gave me, from which the author was ly@42.fr. The vast majority of code was written by me. The tests prefixed moul\_ were adapted from the moulinette test files, the tests with \_ftfc\_ were adapted from 42FileChecker, and all other tests (so far) were written by me.

Thanks to rwright for giving valuable feedback on improving the features.
