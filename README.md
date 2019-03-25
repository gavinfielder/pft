<img align="right"  src="https://i.imgur.com/yngNuS4.png" width="40%" />  

# PFT
*aka Printftester2000*

This is a unit test library and tester for ft\_printf.  

By default, it can check if your *completed* printf is pretty good or not pretty good.   

It's **more** useful as a production tool while you're developing ft\_prinf, because it lets you enable and disable entire blocks of tests at once, search and run tests by name and category, and in general perform quick regression testing. It's quick and easy to add your own tests, which I recommend on principle. It's built to be flexible, so you can use it how you wish.  

# Installation

In the root of your repo, run this command:

```
git clone https://github.com/gavinfielder/pft.git testing && echo "testing/" >> .gitignore
```

# Usage, the short version

Inside testing/:  
`make`  
`./test`  

# Usage, the long version

There are four options:
 - `./test prefix` runs all the enabled tests whose name starts with 'prefix'
 - `./test 42 84` runs (enabled) test number 42 through test 84
 - `./test 42` runs enabled tests from 42 to the end of all the enabled tests
 - `./test` runs all the enabled tests

### Some good prefixes to try
s, i, d, u, x, X, o, p, c, f, f\_L, mix, nocrash, moul

```
If the prefix stuff doesn't make sense, look at unit_tests.c and then run ./test nospec
You should easily pass 3 tests, and have an idea of how to use this program. 
```
Note: tests with prefix `nocrash_` are specifically handled by the tester--instead of benching against printf, they just return automatic pass (assuming, of course, ft\_printf doesn't crash). They are disabled by default (see below for how to enable); I also encourage you to write your own nocrash\_ tests.

## Workflow with PFT

unit\_tests.c shows you all the tests that are available. Failing a test means that your output and/or return value was not the same as the libc printf. When this happens, there will be a new file, 'test\_results.txt', that holds information about the failed test, what the expected output was, and what your output was. You can then find the test in unit\_tests.c to see what code was run that produced an error.  

```
vim trick: In the command line, type `/test-name` and hit enter. This takes you to a particular test.
```

You can add your own tests to this unit\_tests.c, following the same format. You do not need to do anything except write the function in this file and remake.   

## Enabling and Disabling tests

I have provided scripts that make it easy to enable and disable tests by prefix. Example:

```bash
./disable-test s                         # All the tests that start with 's' are disabled
./enable-test s_null_                    # All the tests that start with 's_null_' are enabled
./disable-test "" && ./enable-test s     # Disables all tests except tests that start with 's'
```

While you **can** call `./enable-test ""` to enable all tests, I do not recommend it. Some tests are disabled by default because if you have not implemented certain bonuses, your ft\_printf will segfault.   

# Troubleshooting

If something goes wrong--slack me @gfielder. I like testing, like people using good testing, and want to make this easier to use, so don't hesitate to contact me.  

# Contributing
Feel free to fork the repo and make pull requests.

A big thing that needs to be done is simply just changing test names so that they're grouped better for using the prefix search. I wrote these tests as I was developing my printf, and searching by prefix was an afterthought to all of it, so some of them are a little scattered.  

Adding additional tests would be great as well.  

Before making pull requests, please:

```bash
./enable-test "" && ./disable-test argnum && ./disable-test moul_notmandatory \
&& ./disable-test nocrash && ./disable-test moul_D && ./disable-test moul_F
```
*and if you add tests that can segfault in any way, modify this block in the readme*

# How it works
### ...for those who want knowledge and power (or maybe just want to use it to do something specific)

When you run make, the first thing that happens is the test index is created. Two copies of unit\_tests.c are created. In the copy unit\_tests\_indexed.c, the test() function is replaced with ft\_printf(). In the copy unit\_tests\_benched.c, the test() function is replaced with printf() and '\_bench' is added to all the function names. Next, in both files, an array of function pointers is created at the end of the file pointing to all the enabled unit tests.   An array will also be created holding the names of all the functions as string literals.  

When you call `./test s_`, main.c will see alpha input and call run\_search\_tests, which does strncmp on each position in the array of function names, and when it finds a function name starting with 's\_', it calls run\_test() on that test.  

run\_test() runs a particular test. The way the test works is that it redirects stdout to a file, calls the ft\_printf version (through the array of function pointers that was created on `make`), and does the same with the printf version. It compares the return value and the content of the files, and if either is different, the test is failed. This is very essentially the same way moulinette tests printf. The diff is logged to file and a red FAIL is printed instead of a pretty green PASS.  

There are some user options in the makefile, you can explore them yourself.

# Possible Future Features

I have a few ideas how to improve this:

- disable-test could be able to disable a numeric range of tests.
- enable-test could have an option -o to enable only what is specified.
- Could add a more generalized unit test framework alongside the current one that gives you more control in coming up with unit tests
- Could add tests for the thousands separator optional format flag.
- Could add tests for the `n` specifier.

Feel free to give me suggestions, or code them yourself and make a pull request.  

# Credits

All code was written by me. All the tests were written by me, except the ones prefixed moul\_. The moulinette files I got a hold of (which are now outdated since the printf subject change) had 'ly' as the author in the header.
