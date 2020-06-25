/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:15:57 by gfielder          #+#    #+#             */
/*   Updated: 2020/06/25 13:13:31 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winteger-overflow"
#pragma clang diagnostic ignored "-Wformat"

#include "test.h"

/* -----------------------------------------------------------------------------
** Add unit tests to this file
**
** A valid unit test is prototyped
**
**    int   foo(void)
**
** and includes a call to the function:
**
**    int    test(const char *fmt, ...)
**
** ---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
** unit tests that start with "nocrash_" will always pass
**     (provided it doesn't crash)
** ---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
** A unit test is ENABLED if it has no whitespace preceding it
** A unit test is DISABLED if it has whitespace preceding it
**
** scripts are provided to enable and disable tests by prefix
** ---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
** 						NO SPECIFIERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Tests with no specifiers
int nospec_no_specifier_test(void){return test("hello, world!");}
int nospec_empty_string(void){return test("");}
int nospec_some_escaped_chars(void){return test("\t\n\r\v\f\n");}
//Nospec tests with successive calls
int nospec_successive_5_5(void){return ( test("hello") + test("world"));}
int nospec_successive_2_9(void){return ( test("he") ^ test(" is alive"));}
int nospec_successive_8_3(void){return ( test("is alive") - test(" he"));}


/* -----------------------------------------------------------------------------
** 						%% PERCENTAGE TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//%% Tests
int pct_basic(void){return test("%%");}
int pct_5w(void){return test("%5%");}
int pct_5wlj(void){return test("%-5%");}
int pct_5wzp(void){return test("%05%");}
int pct_5wljzp(void){return test("%-05%");}
//Null specifier tests
int nocrash_notrequired_nullspec_basic(void){return test("%");}
int nocrash_notrequired_nullspec_5w(void){return test("%5");}
int nocrash_notrequired_nullspec_5wzp(void){return test("%05");}
int nocrash_notrequired_nullspec_5wzplj(void){return test("%-05");}
int nocrash_notrequired_nullspec_5wlj(void){return test("%-5");}


/* -----------------------------------------------------------------------------
** 						%c CHARS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Chars - Basic
int c_allprintable_combined(void){return test("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}

int c_1_31_combined(void){return test("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}

int c_128_255_combined(void){return test("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}

int c_allprintable_width(void){return test("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}

int c_1_31_width(void){return test("%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}

int c_128_255_width(void){return test("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}

int c_allprintable_width_lj(void){return test("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}

int c_1_31_width_lj(void){return test("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}

int c_128_255_width_lj(void){return test("%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}

int c_nullterm_basic(void){return test("%c", '\0');}
int c_nullterm_5w(void){return test("%5c", '\0');}
int c_nullterm_5wlj(void){return test("%-5c", '\0');}


/* -----------------------------------------------------------------------------
** 						%s STRING TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//String specifiers - no modifiers
int s_basic_string_expansion(void){return test("hello, %s.", "gavin");}
int s_only_string_expansion(void){return test("%s", "testing testing");}
int s_two_string_expansions(void){return test("%s%s", "hello", "world");}
int s_two_string_expansions2(void){return test("..%s stuff %s", "a", "b");}
int s_empty_string_expansion(void){return test("this %s is empty", "");}
int s_full_then_empty_string(void){return test("this %s is %s", "hello", "");}
int s_empty_then_full_string(void){return test("this %s is %s", "", "hello");}
int s_three_strings(void){return test("%s%s%s", "1", "2", "3's a charm");}
//String specifiers with field_width, space- or zero-padded
int s_space_padded_field_width(void){return test("%32s", "abc");}
int s_space_padded_field_width2(void){return test("%16s", "nark nark");}
int s_space_padded_over_field_width(void){return test("%5s", "goes over");}
//String specifiers with field_width, space- or zero-padded, left-justified
int s_space_padded_field_width_lj(void){return test("%-32s", "abc");}
int s_space_padded_field_width2_lj(void){return test("%-16s", "nark nark");}
int s_space_padded_over_field_width_lj(void){return test("%-5s", "goes over");}
//String specifiers with precision
int s_string_prec_notrunc(void){return test("%.7s", "hello");}
int s_string_prec_trunc(void){return test("%.3s", "hello");}
int s_string_prec_default(void){return test("%.s", "hello");}
int s_string_prec_zero(void){return test("%.0s", "hello");}
int s_two_strings_prec_2trunc(void){return test("%.3s%.2s", "holla", "bitch");}
int s_two_strings_prec_1trunc_a(void){return test("%.2s%.7s", "hello", "world");}
int s_two_strings_prec_1trunc_b(void){return test("%.7s%.2s", "hello", "world");}
int s_two_strings_prec_0trunc(void){return test("%.5s%7s", "yo", "boi");}
//String specifiers with both precision and field width
int s_string_prec_width_notrunc(void){return test("%7.5s", "yolo");}
int s_string_prec_width_trunc(void){return test("%7.5s", "bombastic");}
int s_string_prec_width_notrunc_lj(void){return test("%-7.5s", "yolo");}
int s_string_prec_width_trunc_lj(void){return test("%-7.5s", "tubular");}
int s_two_s_prec_width_2fit_0trunc(void){return test("%7.7s%7.7s", "hello", "world");}
int s_two_s_prec_width_1fit_a_0trunc(void){return test("%3.7s%7.7s", "hello", "world");}
int s_two_s_prec_width_1fit_b_0trunc(void){return test("%7.7s%3.7s", "hello", "world");}
int s_two_s_prec_width_0fit_0trunc(void){return test("%3.7s%3.7s", "hello", "world");}
int s_two_s_prec_width_2fit_1trunc_a(void){return test("%7.3s%7.7s", "hello", "world");}
int s_two_s_prec_width_1fit_a_1trunc_a(void){return test("%3.3s%7.7s", "hello", "world");}
int s_two_s_prec_width_1fit_b_1trunc_a(void){return test("%7.3s%3.7s", "hello", "world");}
int s_two_s_prec_width_0fit_1trunc_a(void){return test("%3.3s%3.7s", "hello", "world");}
int s_two_s_prec_width_2fit_1trunc_b(void){return test("%7.7s%7.3s", "hello", "world");}
int s_two_s_prec_width_1fit_a_1trunc_b(void){return test("%3.7s%7.3s", "hello", "world");}
int s_two_s_prec_width_1fit_b_1trunc_b(void){return test("%7.7s%3.3s", "hello", "world");}
int s_two_s_prec_width_0fit_1trunc_b(void){return test("%3.7s%3.3s", "hello", "world");}
int s_two_s_prec_width_2fit_2trunc(void){return test("%7.3s%7.3s", "hello", "world");}
int s_two_s_prec_width_1fit_a_2trunc(void){return test("%3.3s%7.3s", "hello", "world");}
int s_two_s_prec_width_1fit_b_2trunc(void){return test("%7.3s%3.3s", "hello", "world");}
int s_two_s_prec_width_0fit_2trunc(void){return test("%3.3s%3.3s", "hello", "world");}
int s_two_s_prec_width_2trunc(void){return test("%3s%3s", "hello", "world");}
//String specifiers, other tests
int s_two_strings_lj_and_rj(void){return test("%-7s%5s", "hello", "world");}
int s_two_strings_rj_and_lj(void){return test("%7s%-5s", "hello", "world");}
//String specifiers - NULL strings
int s_null_basic_string_expansion(void){return test("hello, %s.", NULL);}
int s_null_only_string_expansion(void){return test("%s", NULL);}
int s_null_space_padded_field_width(void){return test("%32s", NULL);}
int s_null_space_padded_over_field_width(void){return test("%2s", NULL);}
int s_null_space_padded_field_width_lj(void){return test("%-32s", NULL);}
int s_null_space_padded_field_width2_lj(void){return test("%-16s", NULL);}
int s_null_space_padded_over_field_width_lj(void){return test("%-3s", NULL);}
//String specifiers with precision
int s_null_string_prec_notrunc(void){return test("%.9s", "NULL");}
int s_null_string_prec_trunc(void){return test("%.3s", "NULL");}
int s_null_string_prec_default(void){return test("%.s", "NULL");}
int s_null_string_prec_zero(void){return test("%.0s", "NULL");}
//String s_hidden tests
static char *s_hidden = "hi low\0don't print me lol\0";
int s_basic_s_hidden(void){return test("%s", s_hidden);}
// width pad
int s_width_3_s_hidden(void){return test("%3s", s_hidden);}
int s_width_9_s_hidden(void){return test("%9s", s_hidden);}
// precision no width
int s_prec_no_width_s_hidden(void){return test("%.s", s_hidden);}
int s_prec_9_no_width_s_hidden(void){return test("%.9s", s_hidden);}
// precision  0 before number
int s_prec_03_no_width_s_hidden(void){return test("%.03s", s_hidden);}
int s_prec_09_no_width_s_hidden(void){return test("%.09s", s_hidden);}
int s_prec_03_no_width_s_null(void){return test("%.03s", NULL);}
int s_prec_09_no_width_s_null(void){return test("%.09s", NULL);}
int s_prec_00_no_width_s_nullchar(void){return test("%.00s", "\0");}
int s_prec_01_no_width_s_nullchar(void){return test("%.01s", "\0");}
int s_prec_03_no_width_s_nullchar(void){return test("%.03s", "\0");}
int s_prec_09_no_width_s_nullchar(void){return test("%.09s", "\0");}
// width  no precision
int s_prec_0_width_3_s_hidden(void){return test("%3.s", s_hidden);}
int s_prec_0_width_10_s_hidden(void){return test("%10.s", s_hidden);}
int s_prec_0_width_3_s_null(void){return test("%3.s", NULL);}
int s_prec_0_width_10_s_null(void){return test("%10.s", NULL);}
int s_prec_0_width_1_s_nullchar(void){return test("%1.s", "\0");}
int s_prec_0_width_2_s_nullchar(void){return test("%2.s", "\0");}
int s_prec_0_width_9_s_nullchar(void){return test("%9.s", "\0");}
// lj flag width  no precision
int s_prec_0_lj_width_3_s_hidden(void){return test("%-3.s", s_hidden);}
int s_prec_0_lj_width_8_s_hidden(void){return test("%-8.s", s_hidden);}
int s_prec_0_lj_width_3_s_null(void){return test("%-3.s", NULL);}
int s_prec_0_lj_width_8_s_null(void){return test("%-8.s", NULL);}
int s_prec_0_lj_width_1_s_nullchar(void){return test("%-1.s", "\0");}
int s_prec_0_lj_width_2_s_nullchar(void){return test("%-2.s", "\0");}
int s_prec_0_lj_width_6_s_nullchar(void){return test("%-6.s", "\0");}
// width  precision 1
int s_prec_1_width_3_s_hidden(void){return test("%3.1s", s_hidden);}
int s_prec_1_width_10_s_hidden(void){return test("%10.1s", s_hidden);}
int s_prec_1_width_3_s_null(void){return test("%3.1s", NULL);}
int s_prec_1_width_9_s_null(void){return test("%9.1s", NULL);}
// lj flag width  precision 1
int s_prec_1_lj_width_3_s_hidden(void){return test("%-3.1s", s_hidden);}
int s_prec_1_lj_width_10_s_hidden(void){return test("%-10.1s", s_hidden);}
int s_prec_1_lj_width_3_s_null(void){return test("%-3.1s", NULL);}
int s_prec_1_lj_width_9_s_null(void){return test("%-9.1s", NULL);}
int s_prec_1_lj_width_3_s_nullchar(void){return test("%-3.1s", "\0");}
int s_prec_1_lj_width_6_s_nullchar(void){return test("%-6.1s", "\0");}
// width  exact precision
int s_prec_perfect_width_3_s_hidden(void){return test("%3.6s", s_hidden);}
int s_prec_perfect_width_20_s_hidden(void){return test("%20.6s", s_hidden);}
int s_prec_perfect_width_3_s_null(void){return test("%3.6s", NULL);}
int s_prec_perfect_width_20_s_null(void){return test("%20.6s", NULL);}
int s_prec_perfect_width_3_s_nullchar(void){return test("%3.6s", "\0");}
int s_prec_perfect_width_6_s_nullchar(void){return test("%6.6s", "\0");}
// lj flag width exact precision
int s_prec_perfect_lj_width_3_s_hidden(void){return test("%-3.6s", s_hidden);}
int s_prec_perfect_lj_width_20_s_hidden(void){return test("%-20.6s", s_hidden);}
// lj flag width excess precision
int s_prec_8_lj_width_3_s_hidden(void){return test("%-3.8s", s_hidden);}
int s_prec_8_lj_width_10_s_hidden(void){return test("%-10.8s", s_hidden);}
int s_prec_8_lj_width_3_s_null(void){return test("%-3.8s", NULL);}
int s_prec_8_lj_width_10_s_null(void){return test("%-10.8s", NULL);}
// decoy lj flag
int s_prec_00_lj_s_hidden_trunc(void){return test("%-.00s", s_hidden);}
int s_prec_09_lj_s_hidden_notrunc(void){return test("%-.09s", s_hidden);}
// multiple flags diff order same width and precision
int notrequired_s_undefbehav_4_flags_diff_order_1(void){return test("%+- 06.06s", s_hidden);}
int notrequired_s_undefbehav_4_flags_diff_order_2(void){return test("% 0+-6.06s", s_hidden);}
int notrequired_s_undefbehav_4_flags_diff_order_3(void){return test("%0 +-6.06s", s_hidden);}
int notrequired_s_undefbehav_4_flags_diff_order_4(void){return test("%+-0 6.06s", s_hidden);}
int notrequired_s_undefbehav_4_flags_diff_order_5(void){return test("%-+ 06.06s", s_hidden);}
int notrequired_s_undefbehav_4_flags_diff_order_6(void){return test("% -+06.06s", s_hidden);}
// multiple flags diff order width > precision
int notrequired_s_undefbehav_4_flags_sp_padded_diff_order_1(void){return test("%+- 07.06s", s_hidden);}
int notrequired_s_undefbehav_4_flags_sp_padded_diff_order_2(void){return test("% 0+-8.06s", s_hidden);}
int notrequired_s_undefbehav_4_flags_sp_padded_diff_order_3(void){return test("%0 +-9.06s", s_hidden);}
int notrequired_s_undefbehav_4_flags_sp_padded_diff_order_4(void){return test("%+-0 10.06s", s_hidden);}
int notrequired_s_undefbehav_4_flags_sp_padded_diff_order_5(void){return test("%-+ 011.06s", s_hidden);}
int notrequired_s_undefbehav_4_flags_sp_padded_diff_order_6(void){return test("% -+012.06s", s_hidden);}
// multiple flags diff order width > precision, truncated string
int notrequired_s_undefbehav_4_flags_as_lj_sp_zero_trunc(void){return test("%+- 06.04s", s_hidden);}
int notrequired_s_undefbehav_4_flags_sp_zero_as_lj_trunc(void){return test("% 0+-6.04s", s_hidden);}
int notrequired_s_undefbehav_4_flags_zero_sp_as_lj_trunc(void){return test("%0 +-6.04s", s_hidden);}
int notrequired_s_undefbehav_4_flags_as_lj_zero_sp_trunc(void){return test("%+-0 6.04s", s_hidden);}
int notrequired_s_undefbehav_4_flags_lj_as_sp_zero_trunc(void){return test("%-+ 06.04s", s_hidden);}
int notrequired_s_undefbehav_4_flags_sp_zero_lj_as_trunc(void){return test("% 0-+6.04s", s_hidden);}
// multiple flags diff order width < precision, excess precision
int notrequired_s_undefbehav_4_flags_as_lj_sp_zero__pads(void){return test("%+- 06.09s", s_hidden);}
int notrequired_s_undefbehav_4_flags_sp_zero_as_lj__pads(void){return test("% 0+-6.09s", s_hidden);}
int notrequired_s_undefbehav_4_flags_zero_sp_as_lj__pads(void){return test("%0 +-6.09s", s_hidden);}
int notrequired_s_undefbehav_4_flags_as_lj_zero_sp__pads(void){return test("%+-0 6.09s", s_hidden);}
int notrequired_s_undefbehav_4_flags_lj_as_sp_zero__pads(void){return test("%-+ 06.09s", s_hidden);}
int notrequired_s_undefbehav_4_flags_sp_zero_lj_as__pads(void){return test("% 0-+6.09s", s_hidden);}
// multi zeros
int notrequired_s_undefbehav_0_2zero(void){return test("%00s", s_hidden);}
int notrequired_s_undefbehav_0_3zero(void){return test("%000s", s_hidden);}
int notrequired_s_undefbehav_0_4zero(void){return test("%0000s", s_hidden);}
int notrequired_s_undefbehav_0_lj_2zero(void){return test("%-00s", s_hidden);}
int notrequired_s_undefbehav_0_zero_lj_zero(void){return test("%0-0s", s_hidden);}
int notrequired_s_undefbehav_0_2zero_lj(void){return test("%00-s", s_hidden);}
// zero and width
int notrequired_s_undefbehav_0_width_3(void){return test("%03s", s_hidden);}
int notrequired_s_undefbehav_0_width_9(void){return test("%09s", s_hidden);}
// as and zero flags  width
int notrequired_s_undefbehav_as_0_width_3(void){return test("%+03s", s_hidden);}
int notrequired_s_undefbehav_as_0_width_9(void){return test("%+09s", s_hidden);}
// flag cancelling
int notrequired_s_undefbehav_lj_0_width_3(void){return test("%-03s", s_hidden);}
int notrequired_s_undefbehav_lj_0_width_9(void){return test("%-09s", s_hidden);}
int notrequired_s_undefbehav_as_sp_width_3(void){return test("%+ 3s", s_hidden);}
int notrequired_s_undefbehav_as_sp_width_6(void){return test("%+ 6s", s_hidden);}


/* -----------------------------------------------------------------------------
** 						%p POINTERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Pointers - Basic
static char	a01;
static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;

int p_null(void){return test("%p", NULL);}

int notrequired_p_ftfc_literal_9w_prec2_undefbehav(void){return test("%9.2p\n", 1234);}
int notrequired_p_ftfc_literal_2w_prec9_undefbehav(void){return test("%2.9p\n", 1234);}
int notrequired_p_ftfc_zero_prec5_undefbehav(void){return test("%.5p", 0);}
int notrequired_p_ftfc_zero_prec0_undefbehav(void){return test("%.0p", 0);}
int p_ftfc_5w_throwswarning(void){return test("%5p", 0);}

int p_basic(void){return test("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}

int p_width_fit(void){return test("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}

int p_width_nofit(void){return test("%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}

int p_width_16(void){return test("%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}

int p_width_8(void){return test("%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}

int p_width_32(void){return test("%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}

int p_width_fit_lj(void){return test("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}

int p_width_nofit_lj(void){return test("%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}

int p_width_16_lj(void){return test("%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}

int p_width_8_lj(void){return test("%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}

int p_width_32_lj(void){return test("%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


/* -----------------------------------------------------------------------------
** 						%d INTEGER TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Signed integers - no modifers
int d_basic_pos(void){return test("this %d number", 17);}
int d_basic_neg(void){return test("this %d number", -267);}
int d_basic_zero(void){return test("this %d number", 0);}
int d_basic_onlypos(void){return test("%d", 3);}
int d_basic_onlyneg(void){return test("%d", -1);}
int d_basic_onlyzero(void){return test("%d", 0);}
int d_intmax(void){return test("%d",  2147483647);}
int d_intmin(void){return test("%d", (int)(-2147483678));}
//Signed integers with field width
int d_width_pos_fits(void){return test("%7d", 33);}
int d_width_neg_fits(void){return test("%7d", -14);}
int d_width_zero_fits(void){return test("%3d", 0);}
int d_width_pos_exactfit(void){return test("%5d", 52625);}
int d_width_neg_exactfit(void){return test("%5d", -2562);}
int d_width_pos_nofit(void){return test("%4d", 94827);}
int d_width_neg_nofit(void){return test("%4d", -2464);}
int d_width_pos_fits_lj(void){return test("%-7d", 33);}
int d_width_neg_fits_lj(void){return test("%-7d", -14);}
int d_width_zero_fits_lj(void){return test("%-3d", 0);}
int d_width_pos_exactfit_lj(void){return test("%-5d", 52625);}
int d_width_neg_exactfit_lj(void){return test("%-5d", -2562);}
int d_width_pos_nofit_lj(void){return test("%-4d", 94827);}
int d_width_neg_nofit_lj(void){return test("%-4d", -2464);}
//signed integers with precision
int d_prec_fits_pos(void){return test("%.5d", 2);}
int d_prec_fits_neg(void){return test("%.6d", -3);}
int d_prec_fits_zero(void){return test("%.3d", 0);}
int d_prec_exactfit_pos(void){return test("%.4d", 5263);}
int d_prec_exactfit_neg(void){return test("%.4d", -2372);}
int d_prec_nofit_pos(void){return test("%.3d", 13862);}
int d_prec_nofit_neg(void){return test("%.3d",-23646);}
//Signed integers with zero field width padding
int d_zp_pos_fits(void){return test("%05d", 43);}
int d_zp_neg_fits(void){return test("%07d", -54);}
int d_zp_zero_fits(void){return test("%03d", 0);}
int d_zp_pos_exactfit(void){return test("%03d", 634);}
int d_zp_neg_exactfit(void){return test("%04d", -532);}
int d_zp_neg_minus1fit(void){return test("%04d", -4825);}
//Signed integers with field width and precision
int d_prec_width_fit_fit_pos(void){return test("%8.5d", 34);}
int d_prec_width_fit_fit_neg(void){return test("%10.5d", -216);}
int d_prec_width_fit_fit_zero(void){return test("%8.5d", 0);}
int d_prec_width_nofit_fit_pos(void){return test("%8.3d", 8375);}
int d_prec_width_nofit_fit_neg(void){return test("%8.3d", -8473);}
int d_prec_width_fit_nofit_pos(void){return test("%3.7d", 3267);}
int d_prec_width_fit_nofit_neg(void){return test("%3.7d", -2375);}
int d_prec_width_nofit_nofit_pos(void){return test("%3.3d", 6983);}
int d_prec_width_nofit_nofit_neg(void){return test("%3.3d", -8462);}
//Signed integers with field width and precision, left-justified
int d_prec_width_fit_fit_pos_lj(void){return test("%-8.5d", 34);}
int d_prec_width_fit_fit_neg_lj(void){return test("%-10.5d", -216);}
int d_prec_width_fit_fit_zero_lj(void){return test("%-8.5d", 0);}
int d_prec_width_nofit_fit_pos_lj(void){return test("%-8.3d", 8375);}
int d_prec_width_nofit_fit_neg_lj(void){return test("%-8.3d", -8473);}
int d_prec_width_fit_nofit_pos_lj(void){return test("%-3.7d", 3267);}
int d_prec_width_fit_nofit_neg_lj(void){return test("%-3.7d", -2375);}
int d_prec_width_nofit_nofit_pos_lj(void){return test("%-3.3d", 6983);}
int d_prec_width_nofit_nofit_neg_lj(void){return test("%-3.3d", -8462);}
//Signed integers with field width and precision with zeropadding
int d_prec_width_ff_pos_zp(void){return test("%08.5d", 34);}
int d_prec_width_ff_neg_zp(void){return test("%010.5d", -216);}
int d_prec_width_ff_zero_zp(void){return test("%08.5d", 0);}
int d_prec_width_nf_pos_zp(void){return test("%08.3d", 8375);}
int d_prec_width_nf_neg_zp(void){return test("%08.3d", -8473);}
int d_prec_width_fn_pos_zp(void){return test("%03.7d", 3267);}
int d_prec_width_fn_neg_zp(void){return test("%03.7d", -2375);}
int d_prec_width_nn_pos_zp(void){return test("%03.3d", 6983);}
int d_prec_width_nn_neg_zp(void){return test("%03.3d", -8462);}
//Signed integers with field width and precision, left-justified with zeropadding
int d_prec_width_ff_pos_lj_zp_ignoreflag(void){return test("%0-8.5d", 34);}
int d_prec_width_ff_neg_ljzp_ignoreflag(void){return test("%0-10.5d", -216);}
int d_prec_width_ff_zero_ljzp_ignoreflag(void){return test("%0-8.5d", 0);}
int d_prec_width_nf_pos_ljzp_ignoreflag(void){return test("%0-8.3d", 8375);}
int d_prec_width_nf_neg_ljzp_ignoreflag(void){return test("%0-8.3d", -8473);}
int d_prec_width_fn_pos_ljzp_ignoreflag(void){return test("%0-3.7d", 3267);}
int d_prec_width_fn_neg_ljzp_ignoreflag(void){return test("%0-3.7d", -2375);}
int d_prec_width_nn_pos_ljzp_ignoreflag(void){return test("%0-3.3d", 6983);}
int d_prec_width_nn_neg_ljzp_ignoreflag(void){return test("%0-3.3d", -8462);}
//Signed integers - zero precision zero value
int d_prec0val0_basic(void){return test("%.0d", 0);}
int d_prec0val0_implicit(void){return test("%.d", 0);}
int d_prec0val0_w(void){return test("%5.0d", 0);}
int d_prec0val0_w_impl(void){return test("%5.d", 0);}
int d_prec0val0_wlj(void){return test("%-5.0d", 0);}
int d_prec0val0_wlj_impl(void){return test("%-5.d", 0);}


/* -----------------------------------------------------------------------------
** 						%i INTEGER TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Signed integers - no modifers
int i_basic_pos(void){return test("this %i number", 17);}
int i_basic_neg(void){return test("this %i number", -267);}
int i_basic_zero(void){return test("this %i number", 0);}
int i_basic_onlypos(void){return test("%i", 3);}
int i_basic_onlyneg(void){return test("%i", -1);}
int i_basic_onlyzero(void){return test("%i", 0);}
int i_intmax(void){return test("%i",  2147483647);}
int i_intmin(void){return test("%i", (int)(-2147483678));}
//Signed integers  field width
int i_width_pos_fits(void){return test("%7i", 33);}
int i_width_neg_fits(void){return test("%7i", -14);}
int i_width_zero_fits(void){return test("%3i", 0);}
int i_width_pos_exactfit(void){return test("%5i", 52625);}
int i_width_neg_exactfit(void){return test("%5i", -2562);}
int i_width_pos_nofit(void){return test("%4i", 94827);}
int i_width_neg_nofit(void){return test("%4i", -2464);}
int i_width_pos_fits_lj(void){return test("%-7i", 33);}
int i_width_neg_fits_lj(void){return test("%-7i", -14);}
int i_width_zero_fits_lj(void){return test("%-3i", 0);}
int i_width_pos_exactfit_lj(void){return test("%-5i", 52625);}
int i_width_neg_exactfit_lj(void){return test("%-5i", -2562);}
int i_width_pos_nofit_lj(void){return test("%-4i", 94827);}
int i_width_neg_nofit_lj(void){return test("%-4i", -2464);}
//signed integers with precision
int i_prec_fits_pos(void){return test("%.5i", 2);}
int i_prec_fits_neg(void){return test("%.6i", -3);}
int i_prec_fits_zero(void){return test("%.3i", 0);}
int i_prec_exactfit_pos(void){return test("%.4i", 5263);}
int i_prec_exactfit_neg(void){return test("%.4i", -2372);}
int i_prec_nofit_pos(void){return test("%.3i", 13862);}
int i_prec_nofit_neg(void){return test("%.3i",-23646);}
//Signed integers with zero field width padding
int i_zp_pos_fits(void){return test("%05i", 43);}
int i_zp_neg_fits(void){return test("%07i", -54);}
int i_zp_zero_fits(void){return test("%03i", 0);}
int i_zp_pos_exactfit(void){return test("%03i", 634);}
int i_zp_neg_exactfit(void){return test("%04i", -532);}
int i_zp_neg_minus1fit(void){return test("%04i", -4825);}
//Signed integers with field width and precision
int i_prec_width_fit_fit_pos(void){return test("%8.5i", 34);}
int i_prec_width_fit_fit_neg(void){return test("%10.5i", -216);}
int i_prec_width_fit_fit_zero(void){return test("%8.5i", 0);}
int i_prec_width_nofit_fit_pos(void){return test("%8.3i", 8375);}
int i_prec_width_nofit_fit_neg(void){return test("%8.3i", -8473);}
int i_prec_width_fit_nofit_pos(void){return test("%3.7i", 3267);}
int i_prec_width_fit_nofit_neg(void){return test("%3.7i", -2375);}
int i_prec_width_nofit_nofit_pos(void){return test("%3.3i", 6983);}
int i_prec_width_nofit_nofit_neg(void){return test("%3.3i", -8462);}
//Signed integers with field width and precision, left-justified
int i_prec_width_fit_fit_pos_lj(void){return test("%-8.5i", 34);}
int i_prec_width_fit_fit_neg_lj(void){return test("%-10.5i", -216);}
int i_prec_width_fit_fit_zero_lj(void){return test("%-8.5i", 0);}
int i_prec_width_nofit_fit_pos_lj(void){return test("%-8.3i", 8375);}
int i_prec_width_nofit_fit_neg_lj(void){return test("%-8.3i", -8473);}
int i_prec_width_fit_nofit_pos_lj(void){return test("%-3.7i", 3267);}
int i_prec_width_fit_nofit_neg_lj(void){return test("%-3.7i", -2375);}
int i_prec_width_nofit_nofit_pos_lj(void){return test("%-3.3i", 6983);}
int i_prec_width_nofit_nofit_neg_lj(void){return test("%-3.3i", -8462);}
//Signed integers with field width and precision with zeropadding
int i_prec_width_ff_pos_zp(void){return test("%08.5i", 34);}
int i_prec_width_ff_neg_zp(void){return test("%010.5i", -216);}
int i_prec_width_ff_zero_zp(void){return test("%08.5i", 0);}
int i_prec_width_nf_pos_zp(void){return test("%08.3i", 8375);}
int i_prec_width_nf_neg_zp(void){return test("%08.3i", -8473);}
int i_prec_width_fn_pos_zp(void){return test("%03.7i", 3267);}
int i_prec_width_fn_neg_zp(void){return test("%03.7i", -2375);}
int i_prec_width_nn_pos_zp(void){return test("%03.3i", 6983);}
int i_prec_width_nn_neg_zp(void){return test("%03.3i", -8462);}
//Signed integers with field width and precision, left-justified with zeropadding
int i_prec_width_ff_pos_lj_zp_ignoreflag(void){return test("%0-8.5i", 34);}
int i_prec_width_ff_neg_ljzp_ignoreflag(void){return test("%0-10.5i", -216);}
int i_prec_width_ff_zero_ljzp_ignoreflag(void){return test("%0-8.5i", 0);}
int i_prec_width_nf_pos_ljzp_ignoreflag(void){return test("%0-8.3i", 8375);}
int i_prec_width_nf_neg_ljzp_ignoreflag(void){return test("%0-8.3i", -8473);}
int i_prec_width_fn_pos_ljzp_ignoreflag(void){return test("%0-3.7i", 3267);}
int i_prec_width_fn_neg_ljzp_ignoreflag(void){return test("%0-3.7i", -2375);}
int i_prec_width_nn_pos_ljzp_ignoreflag(void){return test("%0-3.3i", 6983);}
int i_prec_width_nn_neg_ljzp_ignoreflag(void){return test("%0-3.3i", -8462);}
//Signed integers - zero precision zero value
int i_prec0val0_basic(void){return test("%.0i", 0);}
int i_prec0val0_implicit(void){return test("%.i", 0);}
int i_prec0val0_w(void){return test("%5.0i", 0);}
int i_prec0val0_w_impl(void){return test("%5.i", 0);}
int i_prec0val0_wlj(void){return test("%-5.0i", 0);}
int i_prec0val0_wlj_impl(void){return test("%-5.i", 0);}


/* -----------------------------------------------------------------------------
** 						%u UNSIGNED INTEGERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Unsigned integers - no modifers
int u_basic_pos(void){return test("this %u number", 17);}
int u_basic_zero(void){return test("this %u number", 0);}
int u_basic_onlypos(void){return test("%u", 3);}
int u_uintmax(void){return test("%u", 4294967295u);}
//Unsigned integers with field width
int u_width_pos_fits(void){return test("%7u", 33);}
int u_width_zero_fits(void){return test("%3u", 0);}
int u_width_pos_exactfit(void){return test("%5u", 52625);}
int u_width_pos_nofit(void){return test("%4u", 94827);}
int u_width_pos_fits_lj(void){return test("%-7u", 33);}
int u_width_zero_fits_lj(void){return test("%-3u", 0);}
int u_width_pos_exactfit_lj(void){return test("%-5u", 52625);}
int u_width_pos_nofit_lj(void){return test("%-4u", 94827);}
//unsigned integers with precision
int u_prec_fits_pos(void){return test("%.5u", 2);}
int u_prec_fits_zero(void){return test("%.3u", 0);}
int u_prec_exactfit_pos(void){return test("%.4u", 5263);}
int u_prec_nofit_pos(void){return test("%.3u", 13862);}
//Unsigned integers with zero field width padding
int u_zp_pos_fits(void){return test("%05u", 43);}
int u_zp_zero_fits(void){return test("%03u", 0);}
int u_zp_pos_exactfit(void){return test("%03u", 634);}
//Unsigned integers with field width and precision
int u_prec_width_fit_fit_pos(void){return test("%8.5u", 34);}
int u_prec_width_fit_fit_zero(void){return test("%8.5u", 0);}
int u_prec_width_nofit_fit_pos(void){return test("%8.3u", 8375);}
int u_prec_width_fit_nofit_pos(void){return test("%3.7u", 3267);}
int u_prec_width_nofit_nofit_pos(void){return test("%3.3u", 6983);}
//Unsigned integers with field width and precision, left-justified
int u_prec_width_fit_fit_pos_lj(void){return test("%-8.5u", 34);}
int u_prec_width_fit_fit_zero_lj(void){return test("%-8.5u", 0);}
int u_prec_width_nofit_fit_pos_lj(void){return test("%-8.3u", 8375);}
int u_prec_width_fit_nofit_pos_lj(void){return test("%-3.7u", 3267);}
int u_prec_width_nofit_nofit_pos_lj(void){return test("%-3.3u", 6983);}
//Unsigned integers with field width and precision with zeropadding
int u_prec_width_ff_pos_zp(void){return test("%08.5u", 34);}
int u_prec_width_ff_zero_zp(void){return test("%08.5u", 0);}
int u_prec_width_nf_pos_zp(void){return test("%08.3u", 8375);}
int u_prec_width_fn_pos_zp(void){return test("%03.7u", 3267);}
int u_prec_width_nn_pos_zp(void){return test("%03.3u", 6983);}
//Unsigned integers with field width and precision, left-justified with zeropadding
int u_prec_width_ff_pos_ljzp_ignoreflag(void){return test("%0-8.5u", 34);}
int u_prec_width_ff_zero_ljzp_ignoreflag(void){return test("%0-8.5u", 0);}
int u_prec_width_nf_pos_ljzp_ignoreflag(void){return test("%0-8.3u", 8375);}
int u_prec_width_fn_pos_ljzp_ignoreflag(void){return test("%0-3.7u", 3267);}
int u_prec_width_nn_pos_ljzp_ignoreflag(void){return test("%0-3.3u", 6983);}
//Unsigned integers - zero precision zero value
int u_prec0val0_basic(void){return test("%.0u", 0);}
int u_prec0val0_implicit(void){return test("%.u", 0);}
int u_prec0val0_w(void){return test("%5.0u", 0);}
int u_prec0val0_w_impl(void){return test("%5.u", 0);}
int u_prec0val0_wlj(void){return test("%-5.0u", 0);}
int u_prec0val0_wlj_impl(void){return test("%-5.u", 0);}


/* -----------------------------------------------------------------------------
** 						%x HEXADECIMAL LOWERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Hexadecimal lowers - no modifers
int x_basic_pos(void){return test("this %x number", 17);}
int x_basic_zero(void){return test("this %x number", 0);}
int x_basic_onlypos(void){return test("%x", 3);}
int x_hexlmax(void){return test("%x", 4294967295u);}
//Hexadecimal lowers with field width
int x_width_pos_fits(void){return test("%7x", 33);}
int x_width_zero_fits(void){return test("%3x", 0);}
int x_width_pos_exactfit(void){return test("%5x", 52625);}
int x_width_pos_nofit(void){return test("%2x", 94827);}
int x_width_pos_fits_lj(void){return test("%-7x", 33);}
int x_width_zero_fits_lj(void){return test("%-3x", 0);}
int x_width_pos_exactfit_lj(void){return test("%-5x", 52625);}
int x_width_pos_nofit_lj(void){return test("%-4x", 9648627);}
//Hexadecimal lowers with precision
int x_prec_fits_pos(void){return test("%.5x", 21);}
int x_prec_fits_zero(void){return test("%.3x", 0);}
int x_prec_exactfit_pos(void){return test("%.4x", 5263);}
int x_prec_nofit_pos(void){return test("%.3x", 938862);}
//Hexadecimal lowers with zero field width padding
int x_zp_pos_fits(void){return test("%05x", 43);}
int x_zp_zero_fits(void){return test("%03x", 0);}
int x_zp_pos_exactfit(void){return test("%03x", 698334);}
//Hexadecimal lowers with field width and precision
int x_prec_width_fit_fit_pos(void){return test("%8.5x", 34);}
int x_prec_width_fit_fit_zero(void){return test("%8.5x", 0);}
int x_prec_width_nofit_fit_pos(void){return test("%8.3x", 8375);}
int x_prec_width_fit_nofit_pos(void){return test("%2.7x", 3267);}
int x_prec_width_nofit_nofit_pos(void){return test("%3.3x", 6983);}
//Hexadecimal lowers with field width and precision, left-justified
int x_prec_width_fit_fit_pos_lj(void){return test("%-8.5x", 34);}
int x_prec_width_fit_fit_zero_lj(void){return test("%-8.5x", 0);}
int x_prec_width_nofit_fit_pos_lj(void){return test("%-8.3x", 8375);}
int x_prec_width_fit_nofit_pos_lj(void){return test("%-2.7x", 3267);}
int x_prec_width_nofit_nofit_pos_lj(void){return test("%-3.3x", 6983);}
//Hexadecimal lowers with field width and precision with zeropadding
int x_prec_width_ff_pos_zp(void){return test("%08.5x", 34);}
int x_prec_width_ff_zero_zp(void){return test("%08.5x", 0);}
int x_prec_width_nf_pos_zp(void){return test("%08.3x", 8375);}
int x_prec_width_fn_pos_zp(void){return test("%02.7x", 3267);}
int x_prec_width_nn_pos_zp(void){return test("%03.3x", 6983);}
//Hexadecimal lowers with field width and precision, left-justified with zeropadding
int x_prec_width_ff_pos_ljzp_ignoreflag(void){return test("%0-8.5x", 34);}
int x_prec_width_ff_zero_ljzp_ignoreflag(void){return test("%0-8.5x", 0);}
int x_prec_width_nf_pos_ljzp_ignoreflag(void){return test("%0-8.3x", 8375);}
int x_prec_width_fn_pos_ljzp_ignoreflag(void){return test("%0-2.7x", 3267);}
int x_prec_width_nn_pos_ljzp_ignoreflag(void){return test("%0-3.3x", 6983);}
//Hexadecimal lower - zero precision zero value
int x_prec0val0_basic(void){return test("%.0x", 0);}
int x_prec0val0_implicit(void){return test("%.x", 0);}
int x_prec0val0_w(void){return test("%5.0x", 0);}
int x_prec0val0_w_impl(void){return test("%5.x", 0);}
int x_prec0val0_wlj(void){return test("%-5.0x", 0);}
int x_prec0val0_wlj_impl(void){return test("%-5.x", 0);}


/* -----------------------------------------------------------------------------
** 						%X HEXADECIMAL UPPERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Hexadecimal uppers - no modifers
int X_basic_hexu_pos(void){return test("this %X number", 17);}
int X_basic_hexu_zero(void){return test("this %X number", 0);}
int X_basic_hexu_onlypos(void){return test("%X", 3);}
int X_hexumax(void){return test("%X", 4294967295u);}
//Hexadecimal uppers with field width
int X_width_pos_fits(void){return test("%7X", 33);}
int X_width_zero_fits(void){return test("%3X", 0);}
int X_width_pos_exactfit(void){return test("%5X", 52625);}
int X_width_pos_nofit(void){return test("%2X", 94827);}
int X_width_pos_fits_lj(void){return test("%-7X", 33);}
int X_width_zero_fits_lj(void){return test("%-3X", 0);}
int X_width_pos_exactfit_lj(void){return test("%-5X", 52625);}
int X_width_pos_nofit_lj(void){return test("%-4X", 9648627);}
//Hexadecimal uppers with precision
int X_prec_fits_pos(void){return test("%.5X", 21);}
int X_prec_fits_zero(void){return test("%.3X", 0);}
int X_prec_exactfit_pos(void){return test("%.4X", 5263);}
int X_prec_nofit_pos(void){return test("%.3X", 938862);}
//Hexadecimal uppers with zero field width padding
int X_zp_pos_fits(void){return test("%05X", 43);}
int X_zp_zero_fits(void){return test("%03X", 0);}
int X_zp_pos_exactfit(void){return test("%03X", 698334);}
//Hexadecimal uppers with field width and precision
int X_prec_width_fit_fit_pos(void){return test("%8.5X", 34);}
int X_prec_width_fit_fit_zero(void){return test("%8.5X", 0);}
int X_prec_width_nofit_fit_pos(void){return test("%8.3X", 8375);}
int X_prec_width_fit_nofit_pos(void){return test("%2.7X", 3267);}
int X_prec_width_nofit_nofit_pos(void){return test("%3.3X", 6983);}
//Hexadecimal uppers with field width and precision, left-justified
int X_prec_width_fit_fit_pos_lj(void){return test("%-8.5X", 34);}
int X_prec_width_fit_fit_zero_lj(void){return test("%-8.5X", 0);}
int X_prec_width_nofit_fit_pos_lj(void){return test("%-8.3X", 8375);}
int X_prec_width_fit_nofit_pos_lj(void){return test("%-2.7X", 3267);}
int X_prec_width_nofit_nofit_pos_lj(void){return test("%-3.3X", 6983);}
//Hexadecimal uppers with field width and precision with zeropadding
int X_prec_width_ff_pos_zp(void){return test("%08.5X", 34);}
int X_prec_width_ff_zero_zp(void){return test("%08.5X", 0);}
int X_prec_width_nf_pos_zp(void){return test("%08.3X", 8375);}
int X_prec_width_fn_pos_zp(void){return test("%02.7X", 3267);}
int X_prec_width_nn_pos_zp(void){return test("%03.3X", 6983);}
//Hexadecimal uppers with field width and precision, left-justified with zeropadding
int X_prec_width_ff_pos_ljzp_ignoreflag(void){return test("%0-8.5X", 34);}
int X_prec_width_ff_zero_ljzp_ignoreflag(void){return test("%0-8.5X", 0);}
int X_prec_width_nf_pos_ljzp_ignoreflag(void){return test("%0-8.3X", 8375);}
int X_prec_width_fn_pos_ljzp_ignoreflag(void){return test("%0-2.7X", 3267);}
int X_prec_width_nn_pos_ljzp_ignoreflag(void){return test("%0-3.3X", 6983);}
//Hexadecimal uppers - zero precision zero value
int X_prec0val0_basic(void){return test("%.0X", 0);}
int X_prec0val0_implicit(void){return test("%.X", 0);}
int X_prec0val0_w(void){return test("%5.0X", 0);}
int X_prec0val0_w_impl(void){return test("%5.X", 0);}
int X_prec0val0_wlj(void){return test("%-5.0X", 0);}
int X_prec0val0_wlj_impl(void){return test("%-5.X", 0);}


/* -----------------------------------------------------------------------------
** 							STAR TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Taken from https://github.com/cclaude42/PFT_2019
int new2019_star_1(void){return test("%*s", 32, "abc");}
int new2019_star_2(void){return test("%-*s", 32, "abc");}
int new2019_star_3(void){return test("%*s", 3, "hello");}
int new2019_star_4(void){return test("%.*s", 3, "hello");}
int new2019_star_5(void){return test("%.*s", 0, "hello");}
int new2019_star_6(void){return test("%-*.*s", 7, 3, "yolo");}
int new2019_star_7(void){return test("%*i", 4, 94827);}
int new2019_star_8(void){return test("%*i", 14, 94827);}
int new2019_star_9(void){return test("%.*i", 6, -3);}
int new2019_star_10(void){return test("%0*i", 7, -54);}
int new2019_negstar_1(void){return test("%*s", -32, "abc");}
int new2019_negstar_2(void){return test("%-*s", -32, "abc");}
int new2019_negstar_3(void){return test("%*s", -3, "hello");}
int new2019_negstar_4(void){return test("%.*s", -3, "hello");}
int new2019_negstar_5(void){return test("%-*.*s", -7, -3, "yolo");}
int new2019_negstar_6(void){return test("%*i", -4, 94827);}
int new2019_negstar_7(void){return test("%*i", -14, 94827);}
int new2019_negstar_8(void){return test("%.*i", -6, -3);}
int new2019_negstar_9(void){return test("%0*i", -7, -54);}


/* -----------------------------------------------------------------------------
** 					NO CRASH / NO SEGFAULT TESTS (NOT REQUIRED)
** ---------------------------------------------------------------------------*/
//No-crash-no-segfault test
int nocrash_notrequired_noarg_1(void){return test("%1$"); }
int nocrash_notrequired_noarg_2(void){return test("%0"); }
int nocrash_notrequired_noarg_3(void){return test("% "); }
int nocrash_notrequired_noarg_5(void){return test("%-"); }
int nocrash_notrequired_noarg_6(void){return test("%+"); }
int nocrash_notrequired_noarg_9(void){return test("%23"); }
int nocrash_notrequired_noarg_10(void){return test("%."); }
int nocrash_notrequired_noarg_16(void){return test("%p"); }
int nocrash_notrequired_noarg_17(void){return test("%d"); }
int nocrash_notrequired_noarg_19(void){return test("%u"); }
int nocrash_notrequired_noarg_20(void){return test("%x"); }
int nocrash_notrequired_noarg_21(void){return test("%X"); }
int nocrash_notrequired_noarg_22(void){return test("%f"); }
int nocrash_notrequired_noarg_24(void){return test("%c"); }
int nocrash_notrequired_noarg_25(void){return test("%o"); }
int nocrash_notrequired_nullarg_1(void){return test("%1$s", NULL); }
int nocrash_notrequired_nullarg_2(void){return test("%0s", NULL); }
int nocrash_notrequired_nullarg_3(void){return test("% s", NULL); }
int nocrash_notrequired_nullarg_5(void){return test("%-s", NULL); }
int nocrash_notrequired_nullarg_6(void){return test("%+s", NULL); }
int nocrash_notrequired_nullarg_9(void){return test("%23s", NULL); }
int nocrash_notrequired_nullarg_10(void){return test("%.s", NULL); }
int nocrash_notrequired_nullarg_16(void){return test("%p", NULL); }
int nocrash_notrequired_nullarg_17(void){return test("%d", NULL); }
int nocrash_notrequired_nullarg_18(void){return test("%b", NULL); }
int nocrash_notrequired_nullarg_19(void){return test("%u", NULL); }
int nocrash_notrequired_nullarg_20(void){return test("%x", NULL); }
int nocrash_notrequired_nullarg_21(void){return test("%X", NULL); }
int nocrash_notrequired_nullarg_22(void){return test("%f", NULL); }
int nocrash_notrequired_nullarg_23(void){return test("%s", NULL); }
int nocrash_notrequired_nullarg_24(void){return test("%c", NULL); }
int nocrash_notrequired_nullarg_25(void){return test("%o", NULL); }
//nocrash tests adapted from tests contributed by phtruong
int nocrash_notrequired_dupflag_d_ljljw(void){return test("%--5d", 42);}
//nocrash tests that came about as part of the minimal specification
int nocrash_notrequired_c_prec_1(void){return test("%.4c", 'a');}
int nocrash_notrequired_c_prec_2(void){return test("%.c", 'a');}
int nocrash_notrequired_c_zp_1(void){return test("%05c", 'a');}
int nocrash_notrequired_c_zp_2(void){return test("%0c", 'a');}
int nocrash_notrequired_c_lj_nowidth(void){return test("%-c", 'a');}
int nocrash_notrequired_s_zp_1(void){return test("%05s", "hello");}
int nocrash_notrequired_s_zp_2(void){return test("%0s", "hello");}
int nocrash_notrequired_s_lj_nowidth(void){return test("%-s", "hello");}

static int ncm_p = 5;
int nocrash_notrequired_p_prec_1(void){return test("%.4p", &ncm_p);}
int nocrash_notrequired_p_prec_2(void){return test("%.p", &ncm_p);}
int nocrash_notrequired_p_zp_1(void){return test("%05p", &ncm_p);}
int nocrash_notrequired_p_zp_2(void){return test("%0p", &ncm_p);}
int nocrash_notrequired_p_lj_nowidth(void){return test("%-p", &ncm_p);}
int nocrash_notrequired_i_lj_nowidth(void){return test("%-i", 42);}
int nocrash_notrequired_u_lj_nowidth(void){return test("%-u", 42);}
int nocrash_notrequired_x_lj_nowidth(void){return test("%-x", 42);}
int nocrash_notrequired_f_lj_nowidth(void){return test("%-f", 42.5);}


/* -----------------------------------------------------------------------------
** 							MOULINETTE TESTS - MANDATORY
** ---------------------------------------------------------------------------*/

int moul_c_1(void){return test("%c", 42);}
int moul_c_2(void){return test("Kashim a %c histoires à raconter", 1001);}
int moul_c_3(void){return test("Il fait au moins %c\n", -8000);}
int moul_c_4(void){return test("%c", -0);}
int moul_c_5(void){return test("%c", 0);}
int moul_c_5b(void){return test("%c\n", INT_MAX);}
int moul_c_6(void){return test("%c\n", 'c');}
int moul_c_7(void){return test("%c\n", '\n');}
int moul_c_8(void){return test("%c", 'l');}
int moul_c_9(void){return test("%c", 'y');}
int moul_c_10(void){return test("%c", ' ');}
int moul_c_11(void){return test("%c", 'e');}
int moul_c_12(void){return test("%c", 's');}
int moul_c_13(void){return test("%c", 't');}
int moul_c_14(void){return test("%c", ' ');}
int moul_c_15(void){return test("%c", 'f');}
int moul_c_16(void){return test("%c", 'a');}
int moul_c_17(void){return test("%c", 'n');}
int moul_c_18(void){return test("%c", 't');}
int moul_c_19(void){return test("%c", 'a');}
int moul_c_20(void){return test("%c", 's');}
int moul_c_21(void){return test("%c", 't');}
int moul_c_22(void){return test("%c", 'i');}
int moul_c_23(void){return test("%c", 'q');}
int moul_c_24(void){return test("%c", 'u');}
int moul_c_25(void){return test("%c", 'e');}
int moul_c_26(void){return test("%c\n", '!');}
int moul_c_27(void){return test("%c\n", '\r');}
int moul_c_28(void){return test("%c\n", '\t');}

int moul_s_1(void){return test(" pouet %s !!", "camembert");}
int moul_s_2(void){return test("%s !", "Ceci n'est pas un \0 exercice !");}
int moul_s_3(void){return test("%s!", "Ceci n'est toujours pas un exercice !");}
int moul_s_4(void){char *str = NULL; return test("%s!", str);}

int moul_s_5_this_ones_a_doozy(void){return test("%s",
		"Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");}

int moul_d_1(void){return test("%d", 42);}
int moul_d_2(void){return test("Kashim a %d histoires à raconter", 1001);}
int moul_d_3(void){return test("Il fait au moins %d\n", -8000);}
int moul_d_4(void){return test("%d", -0);}
int moul_d_5(void){return test("%d", 0);}
int moul_d_6(void){return test("%d", INT_MAX);}
int moul_d_7(void){return test("%d", INT_MIN);}
int moul_d_8(void){return test("%d", INT_MIN - 1);}
int moul_d_9(void){return test("%d", INT_MAX + 1);}
int moul_d_10(void){return test("%%d 0000042 == |%d|\n", 0000042);}
int moul_d_11(void){return test("%%d \t == |%d|\n", '\t');}
int moul_d_12(void){return test("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');}

int moul_mix_1(void){int r00 = 0; return test("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", &r00);}

int moul_i_1(void){return test("%i", 42);}
int moul_i_2(void){return test("Kashim a %i histoires à raconter", 1001);}
int moul_i_3(void){return test("Il fait au moins %i\n", -8000);}
int moul_i_4(void){return test("%i", -0);}
int moul_i_5(void){return test("%i", 0);}
int moul_i_6(void){return test("%i", INT_MAX);}
int moul_i_7(void){return test("%i", INT_MIN);}
int moul_i_8(void){return test("%i", INT_MIN - 1);}
int moul_i_9(void){return test("%i", INT_MAX + 1);}
int moul_i_10(void){return test("%%i 0000042 == |%i|\n", 0000042);}
int moul_i_11(void){return test("%%i \t == |%i|\n", '\t');}
int moul_i_12(void){return test("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');}

int moul_u_1(void){return test("%u", 42);}
int moul_u_2(void){return test("Kashim a %u histoires à raconter", 1001);}
int moul_u_3(void){return test("Il fait au moins %u\n", -8000);}
int moul_u_4(void){return test("%u", -0);}
int moul_u_5(void){return test("%u", 0);}
int moul_u_6(void){return test("%u", INT_MAX);}
int moul_u_7(void){return test("%u", INT_MIN);}
int moul_u_8(void){return test("%u", INT_MIN - 1);}
int moul_u_9(void){return test("%u", INT_MAX + 1);}
int moul_u_10(void){return test("%%u 0000042 == |%u|\n", 0000042);}
int moul_u_11(void){return test("%%u \t == |%u|\n", '\t');}
int moul_u_12(void){return test("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');}

int moul_x_1(void){return test("%x", 42);}
int moul_x_2(void){return test("Kashim a %x histoires à raconter", 1001);}
int moul_x_3(void){return test("Il fait au moins %x\n", -8000);}
int moul_x_4(void){return test("%x", -0);}
int moul_x_5(void){return test("%x", 0);}
int moul_x_6(void){return test("%x", INT_MAX);}
int moul_x_7(void){return test("%x", INT_MIN);}
int moul_x_8(void){return test("%x", INT_MIN - 1);}
int moul_x_9(void){return test("%x", INT_MAX + 1);}
int moul_x_10(void){return test("%%x 0000042 == |%x|\n", 0000042);}
int moul_x_11(void){return test("%%x \t == |%x|\n", '\t');}
int moul_x_12(void){return test("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');}

int moul_prec_1(void){return test("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");}
int moul_prec_3(void){return test("%%04.5i 42 == |%04.5i|\n", 42);}
int moul_prec_4(void){return test("%%04.3i 42 == |%04.3i|\n", 42);}
int moul_prec_5(void){return test("%%04.2i 42 == |%04.2i|\n", 42);}

int moul_zeropad_1(void){return test("%%04i 42 == |%04i|\n", 42);}
int moul_zeropad_2(void){return test("%%05i 42 == |%05i|\n", 42);}
int moul_zeropad_3(void){return test("%%0i 42 == |%0i|\n", 42);}
int moul_zeropad_4(void){return test("%%0d 0000042 == |%0d|\n", 0000042);}

int moul_leftjusty_1(void){return test("%%-i 42 == %-i\n", 42);}
int moul_leftjusty_2(void){return test("%%-d 42 == %-d\n", INT_MIN);}
int moul_leftjusty_3(void){return test("%%-i -42 == %-i\n", -42);}
int moul_leftjusty_4(void){return test("%%-4d 42 == |%-4d|\n", 42);}
int moul_leftjusty_5(void){return test("%%-5d -42 == |%-5d|\n", -42);}
int moul_leftjusty_6(void){return test("|%3i|%-3i|\n", 42, 42);}
int moul_leftjusty_7(void){return test("%%-4i 42 == |%-4i|\n", 42);}

int moul_star_1(void){return test("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");}
int moul_star_2(void){return test("%% *.5i 42 == |% *.5i|\n", 4, 42);}
int moul_star_3(void){return test("%%*i 42 == |%*i|\n", 5, 42);}
int moul_star_4(void){return test("%%*i 42 == |%*i|\n", 3, 42);}
int moul_star_5(void){return test("%%*i 42 == |%*i|\n", 2, 42);}


/* -----------------------------------------------------------------------------
** 							MIXED TESTS - MANDATORY
** ---------------------------------------------------------------------------*/
//Mix tests
static unsigned int		mx_u = 235;
static char				mx_c = 'G';
static char			   *mx_s = "Hello, World!";
static int				mx_i = 42;

int		mix_test_0(void){return test(
			"  %u    %%    %p    %x    %s    %i  ",
			mx_u, &mx_i, mx_u, mx_s, mx_i);}
int		mix_test_1(void){return test(
			"  %x    %c    %X    %s    %u    %p  ",
			mx_u, mx_c, mx_u, mx_s, mx_u, &mx_i);}
int		mix_test_2(void){return test(
			"  %%    %i    %X    %p    %c    %s  ",
			mx_i, mx_u, &mx_i, mx_c, mx_s);}
int		mix_test_3(void){return test(
			"  %u    %%    %s    %c    %x    %X  ",
			mx_u, mx_s, mx_c, mx_u, mx_u);}
int		mix_test_4(void){return test(
			"  %i    %c    %x    %u    %%    %X  ",
			mx_i, mx_c, mx_u, mx_u, mx_u);}
int		mix_test_5(void){return test(
			"  %c    %X    %i    %%    %s    %p  ",
			mx_c, mx_u, mx_i, mx_s, &mx_i);}
int		mix_test_6(void){return test(
			"  %p    %x    %i    %c    %s    %u  ",
			&mx_i, mx_u, mx_i, mx_c, mx_s, mx_u);}
int		mix_test_7(void){return test(
			"  %i    %s    %%    %u    %c    %x  ",
			mx_i, mx_s, mx_u, mx_c, mx_u);}
int		mix_test_8(void){return test(
			"  %X    %p    %s    %%    %u    %x  ",
			mx_u, &mx_i, mx_s, mx_u, mx_u);}
int		mix_test_9(void){return test(
			"  %c    %%    %u    %i    %x    %X  ",
			mx_c, mx_u, mx_i, mx_u, mx_u);}
int		mix_test_10(void){return test(
			"  %i    %p    %X    %u    %s    %x  ",
			mx_i, &mx_i, mx_u, mx_u, mx_s, mx_u);}
int		mix_test_11(void){return test(
			"  %X    %c    %p    %x    %i    %u  ",
			mx_u, mx_c, &mx_i, mx_u, mx_i, mx_u);}
int		mix_test_12(void){return test(
			"  %%    %i    %u    %s    %c    %X  ",
			mx_i, mx_u, mx_s, mx_c, mx_u);}
int		mix_test_13(void){return test(
			"  %u    %c    %x    %s    %X    %i  ",
			mx_u, mx_c, mx_u, mx_s, mx_u, mx_i);}
int		mix_test_14(void){return test(
			"  %s    %p    %X    %c    %i    %x  ",
			mx_s, &mx_i, mx_u, mx_c, mx_i, mx_u);}
int		mix_test_15(void){return test(
			"  %u    %c    %X    %x    %p    %s  ",
			mx_u, mx_c, mx_u, mx_u, &mx_i, mx_s);}
int		mix_test_16(void){return test(
			"  %c    %%    %i    %X    %u    %x  ",
			mx_c, mx_i, mx_u, mx_u, mx_u);}
int		mix_test_17(void){return test(
			"  %s    %%    %x    %X    %c    %u  ",
			mx_s, mx_u, mx_u, mx_c, mx_u);}
int		mix_test_18(void){return test(
			"  %x    %s    %X    %%    %p    %i  ",
			mx_u, mx_s, mx_u, &mx_i, mx_i);}
int		mix_test_19(void){return test(
			"  %%    %p    %i    %c    %x    %X  ",
			&mx_i, mx_i, mx_c, mx_u, mx_u);}
int		mix_test_20(void){return test(
			"  %c    %s    %%    %u    %p    %x  ",
			mx_c, mx_s, mx_u, &mx_i, mx_u);}
int		mix_test_21(void){return test(
			"  %c    %i    %u    %s    %p    %x  ",
			mx_c, mx_i, mx_u, mx_s, &mx_i, mx_u);}
int		mix_test_22(void){return test(
			"  %X    %x    %s    %c    %i    %u  ",
			mx_u, mx_u, mx_s, mx_c, mx_i, mx_u);}
int		mix_test_23(void){return test(
			"  %x    %c    %X    %p    %s    %p  ",
			mx_u, mx_c, mx_u, &mx_i, mx_s, &mx_i);}
int		mix_test_24(void){return test(
			"  %X    %%    %i    %s    %p    %x  ",
			mx_u, mx_i, mx_s, &mx_i, mx_u);}
int		mix_test_25(void){return test(
			"  %i    %p    %x    %c    %X    %p  ",
			mx_i, &mx_i, mx_u, mx_c, mx_u, &mx_i);}
int		mix_test_26(void){return test(
			"  %X    %c    %i    %u    %x    %p  ",
			mx_u, mx_c, mx_i, mx_u, mx_u, &mx_i);}
int		mix_test_27(void){return test(
			"  %i    %u    %c    %%    %X    %p  ",
			mx_i, mx_u, mx_c, mx_u, &mx_i);}
int		mix_test_28(void){return test(
			"  %s    %i    %c    %p    %x    %u  ",
			mx_s, mx_i, mx_c, &mx_i, mx_u, mx_u);}
int		mix_test_29(void){return test(
			"  %p    %%    %x    %X    %i    %c  ",
			&mx_i, mx_u, mx_u, mx_i, mx_c);}
int		mix_test_30(void){return test(
			"  %X    %i    %s    %%    %u    %p  ",
			mx_u, mx_i, mx_s, mx_u, &mx_i);}
int		mix_test_31(void){return test(
			"  %%    %u    %p    %i    %X    %c  ",
			mx_u, &mx_i, mx_i, mx_u, mx_c);}
int		mix_test_32(void){return test(
			"  %x    %X    %p    %s    %i    %c  ",
			mx_u, mx_u, &mx_i, mx_s, mx_i, mx_c);}
int		mix_test_33(void){return test(
			"  %c    %%    %s    %X    %x    %p  ",
			mx_c, mx_s, mx_u, mx_u, &mx_i);}
int		mix_test_34(void){return test(
			"  %x    %X    %p    %s    %i    %u  ",
			mx_u, mx_u, &mx_i, mx_s, mx_i, mx_u);}
int		mix_test_35(void){return test(
			"  %p    %u    %s    %X    %c    %p  ",
			&mx_i, mx_u, mx_s, mx_u, mx_c, &mx_i);}
int		mix_test_36(void){return test(
			"  %X    %s    %x    %p    %%    %i  ",
			mx_u, mx_s, mx_u, &mx_i, mx_i);}
int		mix_test_37(void){return test(
			"  %x    %s    %%    %p    %i    %c  ",
			mx_u, mx_s, &mx_i, mx_i, mx_c);}
int		mix_test_38(void){return test(
			"  %s    %u    %x    %%    %i    %c  ",
			mx_s, mx_u, mx_u, mx_i, mx_c);}
int		mix_test_39(void){return test(
			"  %p    %i    %x    %%    %u    %X  ",
			&mx_i, mx_i, mx_u, mx_u, mx_u);}
int		mix_test_40(void){return test(
			"  %%    %c    %X    %p    %u    %x  ",
			mx_c, mx_u, &mx_i, mx_u, mx_u);}
int		mix_test_41(void){return test(
			"  %u    %c    %%    %p    %i    %s  ",
			mx_u, mx_c, &mx_i, mx_i, mx_s);}
int		mix_test_42(void){return test(
			"  %%    %i    %s    %u    %c    %X  ",
			mx_i, mx_s, mx_u, mx_c, mx_u);}
int		mix_test_43(void){return test(
			"  %%    %i    %u    %s    %X    %p  ",
			mx_i, mx_u, mx_s, mx_u, &mx_i);}
int		mix_test_44(void){return test(
			"  %s    %c    %X    %%    %i    %p  ",
			mx_s, mx_c, mx_u, mx_i, &mx_i);}
int		mix_test_45(void){return test(
			"  %x    %X    %u    %i    %%    %s  ",
			mx_u, mx_u, mx_u, mx_i, mx_s);}
int		mix_test_46(void){return test(
			"  %x    %u    %s    %i    %p    %p  ",
			mx_u, mx_u, mx_s, mx_i, &mx_i, &mx_i);}
int		mix_test_47(void){return test(
			"  %X    %i    %s    %x    %u    %p  ",
			mx_u, mx_i, mx_s, mx_u, mx_u, &mx_i);}
int		mix_test_48(void){return test(
			"  %c    %i    %%    %X    %p    %u  ",
			mx_c, mx_i, mx_u, &mx_i, mx_u);}
int		mix_test_49(void){return test(
			"  %s    %u    %i    %X    %%    %c  ",
			mx_s, mx_u, mx_i, mx_u, mx_c);}
int		mix_test_50(void){return test(
			"  %%    %p    %X    %i    %s    %x  ",
			&mx_i, mx_u, mx_i, mx_s, mx_u);}
int		mix_test_51(void){return test(
			"  %i    %x    %p    %c    %u    %X  ",
			mx_i, mx_u, &mx_i, mx_c, mx_u, mx_u);}
int		mix_test_52(void){return test(
			"  %X    %c    %%    %i    %x    %s  ",
			mx_u, mx_c, mx_i, mx_u, mx_s);}
int		mix_test_53(void){return test(
			"  %x    %c    %u    %X    %p    %p  ",
			mx_u, mx_c, mx_u, mx_u, &mx_i, &mx_i);}
int		mix_test_54(void){return test(
			"  %p    %u    %c    %s    %i    %p  ",
			&mx_i, mx_u, mx_c, mx_s, mx_i, &mx_i);}
int		mix_test_55(void){return test(
			"  %x    %p    %s    %u    %%    %c  ",
			mx_u, &mx_i, mx_s, mx_u, mx_c);}
int		mix_test_56(void){return test(
			"  %%    %i    %X    %p    %u    %s  ",
			mx_i, mx_u, &mx_i, mx_u, mx_s);}
int		mix_test_57(void){return test(
			"  %%    %u    %c    %s    %i    %x  ",
			mx_u, mx_c, mx_s, mx_i, mx_u);}
int		mix_test_58(void){return test(
			"  %c    %i    %u    %x    %s    %p  ",
			mx_c, mx_i, mx_u, mx_u, mx_s, &mx_i);}
int		mix_test_59(void){return test(
			"  %c    %i    %s    %u    %x    %p  ",
			mx_c, mx_i, mx_s, mx_u, mx_u, &mx_i);}
int		mix_test_60(void){return test(
			"  %u    %%    %x    %i    %X    %c  ",
			mx_u, mx_u, mx_i, mx_u, mx_c);}
int		mix_test_61(void){return test(
			"  %x    %s    %u    %i    %c    %X  ",
			mx_u, mx_s, mx_u, mx_i, mx_c, mx_u);}
int		mix_test_62(void){return test(
			"  %%    %c    %i    %p    %s    %X  ",
			mx_c, mx_i, &mx_i, mx_s, mx_u);}
int		mix_test_63(void){return test(
			"  %s    %x    %%    %X    %i    %c  ",
			mx_s, mx_u, mx_u, mx_i, mx_c);}
int		mix_test_64(void){return test(
			"  %x    %X    %u    %c    %%    %i  ",
			mx_u, mx_u, mx_u, mx_c, mx_i);}
int		mix_test_65(void){return test(
			"  %c    %%    %i    %p    %u    %X  ",
			mx_c, mx_i, &mx_i, mx_u, mx_u);}
int		mix_test_66(void){return test(
			"  %i    %c    %%    %u    %X    %p  ",
			mx_i, mx_c, mx_u, mx_u, &mx_i);}
int		mix_test_67(void){return test(
			"  %s    %i    %x    %u    %c    %p  ",
			mx_s, mx_i, mx_u, mx_u, mx_c, &mx_i);}
int		mix_test_68(void){return test(
			"  %s    %x    %c    %p    %u    %X  ",
			mx_s, mx_u, mx_c, &mx_i, mx_u, mx_u);}
int		mix_test_69(void){return test(
			"  %%    %s    %p    %i    %X    %c  ",
			mx_s, &mx_i, mx_i, mx_u, mx_c);}
int		mix_test_70(void){return test(
			"  %x    %X    %i    %%    %s    %u  ",
			mx_u, mx_u, mx_i, mx_s, mx_u);}
int		mix_test_71(void){return test(
			"  %s    %i    %X    %c    %%    %p  ",
			mx_s, mx_i, mx_u, mx_c, &mx_i);}
int		mix_test_72(void){return test(
			"  %x    %p    %c    %s    %X    %u  ",
			mx_u, &mx_i, mx_c, mx_s, mx_u, mx_u);}
int		mix_test_73(void){return test(
			"  %%    %X    %u    %x    %p    %c  ",
			mx_u, mx_u, mx_u, &mx_i, mx_c);}
int		mix_test_74(void){return test(
			"  %p    %c    %s    %u    %i    %x  ",
			&mx_i, mx_c, mx_s, mx_u, mx_i, mx_u);}
int		mix_test_75(void){return test(
			"  %i    %c    %%    %p    %u    %x  ",
			mx_i, mx_c, &mx_i, mx_u, mx_u);}
int		mix_test_76(void){return test(
			"  %X    %%    %u    %c    %p    %s  ",
			mx_u, mx_u, mx_c, &mx_i, mx_s);}
int		mix_test_77(void){return test(
			"  %X    %i    %c    %u    %p    %s  ",
			mx_u, mx_i, mx_c, mx_u, &mx_i, mx_s);}
int		mix_test_78(void){return test(
			"  %p    %%    %c    %X    %u    %i  ",
			&mx_i, mx_c, mx_u, mx_u, mx_i);}
int		mix_test_79(void){return test(
			"  %s    %c    %i    %%    %p    %X  ",
			mx_s, mx_c, mx_i, &mx_i, mx_u);}
int		mix_test_80(void){return test(
			"  %p    %%    %c    %u    %s    %X  ",
			&mx_i, mx_c, mx_u, mx_s, mx_u);}
int		mix_test_81(void){return test(
			"  %x    %c    %%    %s    %X    %i  ",
			mx_u, mx_c, mx_s, mx_u, mx_i);}
int		mix_test_82(void){return test(
			"  %%    %c    %i    %X    %s    %x  ",
			mx_c, mx_i, mx_u, mx_s, mx_u);}
int		mix_test_83(void){return test(
			"  %i    %X    %%    %c    %u    %s  ",
			mx_i, mx_u, mx_c, mx_u, mx_s);}
int		mix_test_84(void){return test(
			"  %p    %x    %c    %s    %u    %p  ",
			&mx_i, mx_u, mx_c, mx_s, mx_u, &mx_i);}
int		mix_test_85(void){return test(
			"  %u    %p    %c    %X    %s    %p  ",
			mx_u, &mx_i, mx_c, mx_u, mx_s, &mx_i);}
int		mix_test_86(void){return test(
			"  %p    %c    %u    %X    %s    %p  ",
			&mx_i, mx_c, mx_u, mx_u, mx_s, &mx_i);}
int		mix_test_87(void){return test(
			"  %i    %u    %X    %p    %c    %p  ",
			mx_i, mx_u, mx_u, &mx_i, mx_c, &mx_i);}
int		mix_test_88(void){return test(
			"  %i    %c    %p    %%    %X    %u  ",
			mx_i, mx_c, &mx_i, mx_u, mx_u);}
int		mix_test_89(void){return test(
			"  %s    %c    %i    %x    %p    %u  ",
			mx_s, mx_c, mx_i, mx_u, &mx_i, mx_u);}
int		mix_test_90(void){return test(
			"  %u    %s    %x    %p    %i    %c  ",
			mx_u, mx_s, mx_u, &mx_i, mx_i, mx_c);}
int		mix_test_91(void){return test(
			"  %u    %p    %X    %c    %%    %x  ",
			mx_u, &mx_i, mx_u, mx_c, mx_u);}
int		mix_test_92(void){return test(
			"  %c    %p    %X    %x    %%    %s  ",
			mx_c, &mx_i, mx_u, mx_u, mx_s);}
int		mix_test_93(void){return test(
			"  %x    %c    %s    %p    %u    %i  ",
			mx_u, mx_c, mx_s, &mx_i, mx_u, mx_i);}
int		mix_test_94(void){return test(
			"  %X    %p    %c    %%    %u    %i  ",
			mx_u, &mx_i, mx_c, mx_u, mx_i);}
int		mix_test_95(void){return test(
			"  %%    %i    %x    %p    %c    %s  ",
			mx_i, mx_u, &mx_i, mx_c, mx_s);}
int		mix_test_96(void){return test(
			"  %X    %p    %c    %s    %i    %u  ",
			mx_u, &mx_i, mx_c, mx_s, mx_i, mx_u);}
int		mix_test_97(void){return test(
			"  %u    %i    %p    %x    %s    %X  ",
			mx_u, mx_i, &mx_i, mx_u, mx_s, mx_u);}
int		mix_test_98(void){return test(
			"  %i    %s    %%    %p    %X    %c  ",
			mx_i, mx_s, &mx_i, mx_u, mx_c);}
int		mix_test_99(void){return test(
			"  %X    %p    %c    %u    %x    %i  ",
			mx_u, &mx_i, mx_c, mx_u, mx_u, mx_i);}

//This block was filtered by cclaude's work on the new curriculum--old tests were simply discarded
int		mix_successive_0(void){return ( test("%c", mx_c) + test("%u", mx_u));}

int		mix_successive_4(void){return ( test("%x", mx_u) + test("%i", mx_i));}

int		mix_successive_6(void){return ( test("%s", mx_s) + test("%c", mx_c));}

int		mix_successive_10(void){return ( test("%u", mx_u) + test("%s", mx_s));}

int		mix_successive_16(void){return ( test("%s", mx_s) + test("%x", mx_u));}

int		mix_successive_20(void){return ( test("%p", &mx_i) + test("%s", mx_s));}

int		mix_successive_21(void){return ( test("%X", mx_u) + test("%x", mx_u));}

int		mix_successive_28(void){return ( test("%i", mx_i) + test("%u", mx_u));}

int		mix_successive_30(void){return ( test("%s", mx_s) + test("%u", mx_u));}

int		mix_successive_31(void){return ( test("%X", mx_u) + test("%c", mx_c));}

int		mix_successive_32(void){return ( test("%x", mx_u) + test("%u", mx_u));}

int		mix_successive_39(void){return ( test("%i", mx_i) + test("%c", mx_c));}

int		mix_successive_40(void){return ( test("%c", mx_c) + test("%x", mx_u));}

int		mix_successive_42(void){return ( test("%x", mx_u) + test("%s", mx_s));}

int		mix_successive_43(void){return ( test("%u", mx_u) + test("%x", mx_u));}

int		mix_successive_45(void){return ( test("%s", mx_s) + test("%c", mx_c));}

int		mix_successive_46(void){return ( test("%i", mx_i) + test("%s", mx_s));}

int		mix_successive_61(void){return ( test("%p", &mx_i) + test("%c", mx_c));}

int		mix_successive_64(void){return ( test("%s", mx_s) + test("%c", mx_c));}


/* -----------------------------------------------------------------------------
** 						'+' FLAG (ALLSIGN) TESTS (BONUS)
** ---------------------------------------------------------------------------*/
//Signed integers with allsign ('+')
int bonus_as_d_pos(void){return test("%+d", 5);}
int bonus_as_d_neg(void){return test("%+d", -7);}
int bonus_as_d_intmax(void){return test("%+d", 2147483647);}
int bonus_as_d_prec_pos(void){return test("%+.7d", 234);}
int bonus_as_d_prec_neg(void){return test("%+.7d", -446);}
int bonus_as_d_prec_pos_nofit(void){return test("%+.3d", 3723);}
int bonus_as_d_width_pos(void){return test("%+5d", 35);}
int bonus_as_d_width_zero(void){return test("%+7d", 0);}
int bonus_as_d_width_intmax(void){return test("%+24d", 2147483647);}
int bonus_as_d_zp_fits(void){return test("%+05d", 432);}
int bonus_as_d_zp_zero(void){return test("%+04d", 0);}
//Signed integers with field width and precision with allsign
int bonus_as_d_prec0val0(void){return test("%+.0d", 0);}
int bonus_as_d_prec0val0_impl(void){return test("%+.d", 0);}
int bonus_as_d_prec_width_fit_fit_pos(void){return test("%+8.5d", 34);}
int bonus_as_d_prec_width_fit_fit_neg(void){return test("%+10.5d", -216);}
int bonus_as_d_prec_width_fit_fit_zero(void){return test("%+8.5d", 0);}
int bonus_as_d_prec_width_nofit_fit_pos(void){return test("%+8.3d", 8375);}
int bonus_as_d_prec_width_nofit_fit_neg(void){return test("%+8.3d", -8473);}
int bonus_as_d_prec_width_fit_nofit_pos(void){return test("%+3.7d", 3267);}
int bonus_as_d_prec_width_fit_nofit_neg(void){return test("%+3.7d", -2375);}
int bonus_as_d_prec_width_nofit_nofit_pos(void){return test("%+3.3d", 6983);}
int bonus_as_d_prec_width_nofit_nofit_neg(void){return test("%+3.3d", -8462);}
//Signed integers with field width and precision, left-justified with allsign
int bonus_as_d_prec_width_fit_fit_pos_ljas(void){return test("%+-8.5d", 34);}
int bonus_as_d_prec_width_fit_fit_neg_ljas(void){return test("%+-10.5d", -216);}
int bonus_as_d_prec_width_fit_fit_zero_ljas(void){return test("%+-8.5d", 0);}
int bonus_as_d_prec_width_nofit_fit_pos_ljas(void){return test("%+-8.3d", 8375);}
int bonus_as_d_prec_width_nofit_fit_neg_ljas(void){return test("%+-8.3d", -8473);}
int bonus_as_d_prec_width_fit_nofit_pos_ljas(void){return test("%+-3.7d", 3267);}
int bonus_as_d_prec_width_fit_nofit_neg_ljas(void){return test("%+-3.7d", -2375);}
int bonus_as_d_prec_width_nofit_nofit_pos_ljas(void){return test("%+-3.3d", 6983);}
int bonus_as_d_prec_width_nofit_nofit_neg_ljas(void){return test("%+-3.3d", -8462);}
//Signed integers with field width and precision with allsign with zeropadding
int bonus_as_d_prec_width_ff_pos_zp(void){return test("%0+8.5d", 34);}
int bonus_as_d_prec_width_ff_neg_zp(void){return test("%0+10.5d", -216);}
int bonus_as_d_prec_width_ff_zero_zp(void){return test("%0+8.5d", 0);}
int bonus_as_d_prec_width_nf_pos_zp(void){return test("%0+8.3d", 8375);}
int bonus_as_d_prec_width_nf_neg_zp(void){return test("%0+8.3d", -8473);}
int bonus_as_d_prec_width_fn_pos_zp(void){return test("%0+3.7d", 3267);}
int bonus_as_d_prec_width_fn_neg_zp(void){return test("%0+3.7d", -2375);}
int bonus_as_d_prec_width_nn_pos_zp(void){return test("%0+3.3d", 6983);}
int bonus_as_d_prec_width_nn_neg_zp(void){return test("%0+3.3d", -8462);}
//Signed integers with field width and precision, left-justified with allsign with zeropadding
int bonus_as_d_prec_width_ff_pos_ljaszp_ignoreflag(void){return test("%0+-8.5d", 34);}
int bonus_as_d_prec_width_ff_neg_ljaszp_ignoreflag(void){return test("%0+-10.5d", -216);}
int bonus_as_d_prec_width_ff_zero_ljaszp_ignoreflag(void){return test("%0+-8.5d", 0);}
int bonus_as_d_prec_width_nf_pos_ljaszp_ignoreflag(void){return test("%0+-8.3d", 8375);}
int bonus_as_d_prec_width_nf_neg_ljaszp_ignoreflag(void){return test("%0+-8.3d", -8473);}
int bonus_as_d_prec_width_fn_pos_ljaszp_ignoreflag(void){return test("%0+-3.7d", 3267);}
int bonus_as_d_prec_width_fn_neg_ljaszp_ignoreflag(void){return test("%0+-3.7d", -2375);}
int bonus_as_d_prec_width_nn_pos_ljaszp_ignoreflag(void){return test("%0+-3.3d", 6983);}
int bonus_as_d_prec_width_nn_neg_ljaszp_ignoreflag(void){return test("%0+-3.3d", -8462);}

//Signed integers  allsign ('+')
int bonus_as_i_pos(void){return test("%+i", 5);}
int bonus_as_i_neg(void){return test("%+i", -7);}
int bonus_as_i_intmax(void){return test("%+i", 2147483647);}
int bonus_as_i_zp_fits(void){return test("%+05i", 432);}
int bonus_as_i_zp_zero(void){return test("%+04i", 0);}
//signed integers  field width and allsign
int bonus_as_i_width_pos(void){return test("%+5i", 35);}
int bonus_as_i_width_zero(void){return test("%+7i", 0);}
int bonus_as_i_width_intmax(void){return test("%+24i", 2147483647);}
//signed integers with precision
int bonus_as_i_prec_pos(void){return test("%+.7i", 234);}
int bonus_as_i_prec_neg(void){return test("%+.7i", -446);}
int bonus_as_i_prec_pos_nofit(void){return test("%+.3i", 3723);}
int bonus_as_i_prec0val0(void){return test("%+.0i", 0);}
int bonus_as_i_prec0val0_impl(void){return test("%+.i", 0);}
int bonus_as_i_prec0val0_was(void){return test("%+5.0i", 0);}
int bonus_as_i_prec0val0_was_impl(void){return test("%+5.i", 0);}
int bonus_as_i_prec0val0_waslj(void){return test("%+-5.0i", 0);}
int bonus_as_i_prec0val0_waslj_impl(void){return test("%+-5.i", 0);}
//Signed integers with field width and precision with allsign
int bonus_as_i_prec_width_fit_fit_pos(void){return test("%+8.5i", 34);}
int bonus_as_i_prec_width_fit_fit_neg(void){return test("%+10.5i", -216);}
int bonus_as_i_prec_width_fit_fit_zero(void){return test("%+8.5i", 0);}
int bonus_as_i_prec_width_nofit_fit_pos(void){return test("%+8.3i", 8375);}
int bonus_as_i_prec_width_nofit_fit_neg(void){return test("%+8.3i", -8473);}
int bonus_as_i_prec_width_fit_nofit_pos(void){return test("%+3.7i", 3267);}
int bonus_as_i_prec_width_fit_nofit_neg(void){return test("%+3.7i", -2375);}
int bonus_as_i_prec_width_nofit_nofit_pos(void){return test("%+3.3i", 6983);}
int bonus_as_i_prec_width_nofit_nofit_neg(void){return test("%+3.3i", -8462);}
//Signed integers with field width and precision with allsign with zeropadding
int bonus_as_i_prec_width_ff_pos_zp(void){return test("%0+8.5i", 34);}
int bonus_as_i_prec_width_ff_neg_zp(void){return test("%0+10.5i", -216);}
int bonus_as_i_prec_width_ff_zero_zp(void){return test("%0+8.5i", 0);}
int bonus_as_i_prec_width_nf_pos_zp(void){return test("%0+8.3i", 8375);}
int bonus_as_i_prec_width_nf_neg_zp(void){return test("%0+8.3i", -8473);}
int bonus_as_i_prec_width_fn_pos_zp(void){return test("%0+3.7i", 3267);}
int bonus_as_i_prec_width_fn_neg_zp(void){return test("%0+3.7i", -2375);}
int bonus_as_i_prec_width_nn_pos_zp(void){return test("%0+3.3i", 6983);}
int bonus_as_i_prec_width_nn_neg_zp(void){return test("%0+3.3i", -8462);}
//Signed integers with field width and precision, left-justified with allsign
int bonus_as_i_prec_width_fit_fit_pos_ljas(void){return test("%+-8.5i", 34);}
int bonus_as_i_prec_width_fit_fit_neg_ljas(void){return test("%+-10.5i", -216);}
int bonus_as_i_prec_width_fit_fit_zero_ljas(void){return test("%+-8.5i", 0);}
int bonus_as_i_prec_width_nofit_fit_pos_ljas(void){return test("%+-8.3i", 8375);}
int bonus_as_i_prec_width_nofit_fit_neg_ljas(void){return test("%+-8.3i", -8473);}
int bonus_as_i_prec_width_fit_nofit_pos_ljas(void){return test("%+-3.7i", 3267);}
int bonus_as_i_prec_width_fit_nofit_neg_ljas(void){return test("%+-3.7i", -2375);}
int bonus_as_i_prec_width_nofit_nofit_pos_ljas(void){return test("%+-3.3i", 6983);}
int bonus_as_i_prec_width_nofit_nofit_neg_ljas(void){return test("%+-3.3i", -8462);}
//Signed integers with field width and precision, left-justified with allsign with zeropadding
int bonus_as_i_prec_width_ff_pos_ljaszp_ignoreflag(void){return test("%0+-8.5i", 34);}
int bonus_as_i_prec_width_ff_neg_ljaszp_ignoreflag(void){return test("%0+-10.5i", -216);}
int bonus_as_i_prec_width_ff_zero_ljaszp_ignoreflag(void){return test("%0+-8.5i", 0);}
int bonus_as_i_prec_width_nf_pos_ljaszp_ignoreflag(void){return test("%0+-8.3i", 8375);}
int bonus_as_i_prec_width_nf_neg_ljaszp_ignoreflag(void){return test("%0+-8.3i", -8473);}
int bonus_as_i_prec_width_fn_pos_ljaszp_ignoreflag(void){return test("%0+-3.7i", 3267);}
int bonus_as_i_prec_width_fn_neg_ljaszp_ignoreflag(void){return test("%0+-3.7i", -2375);}
int bonus_as_i_prec_width_nn_pos_ljaszp_ignoreflag(void){return test("%0+-3.3i", 6983);}
int bonus_as_i_prec_width_nn_neg_ljaszp_ignoreflag(void){return test("%0+-3.3i", -8462);}

//nocrash tests adapted from tests contributed by phtruong
int nocrash_notrequired_bonus_as_dupflag_d(void){return test("%++d", 42);}
int nocrash_notrequired_bonus_as_dupflag_d_ljasljw(void){return test("%-+-5d", 42);}
int nocrash_notrequired_bonus_as_c_1(void){return test("%+c", 'a');}
int nocrash_notrequired_bonus_as_c_2(void){return test("%+c", -42);}
int nocrash_notrequired_bonus_as_s_1(void){return test("%+s", "hello");}
int nocrash_notrequired_bonus_as_p_1(void){return test("%+p", &ncm_p);}
int nocrash_notrequired_bonus_as_p_2(void){return test("%+p", &ncm_p);}
int nocrash_notrequired_bonus_as_u(void){return test("%+u", 42);}
int nocrash_notrequired_bonus_as_x(void){return test("%+x", 42);}
int nocrash_notrequired_bonus_as_X(void){return test("%+X", 42);}


/* -----------------------------------------------------------------------------
** 						' ' FLAG (SPACE) TESTS (BONUS)
** ---------------------------------------------------------------------------*/
//Signed integers - space - no modifers
int bonus_sp_d_basic_i_pos(void){return test("this % d number", 17);}
int bonus_sp_d_basic_i_neg(void){return test("this % d number", -267);}
int bonus_sp_d_basic_i_zero(void){return test("this % d number", 0);}
int bonus_sp_d_basic_i_onlypos(void){return test("% d", 3);}
int bonus_sp_d_basic_i_onlyneg(void){return test("% d", -1);}
int bonus_sp_d_basic_i_onlyzero(void){return test("% d", 0);}
int bonus_sp_d_basic_i_pos_d(void){return test("this % d number", 17);}
int bonus_sp_d_basic_i_neg_d(void){return test("this % d number", -267);}
int bonus_sp_d_basic_i_zero_d(void){return test("this % d number", 0);}
int bonus_sp_d_intmax(void){return test("% d", 2147483647);}
int bonus_sp_d_intmin(void){return test("% d", (int)(-2147483678));}
//Signed integers - space with field width
int bonus_sp_d_width_pos_fits(void){return test("% 7d", 33);}
int bonus_sp_d_width_neg_fits(void){return test("% 7d", -14);}
int bonus_sp_d_width_zero_fits(void){return test("% 3d", 0);}
int bonus_sp_d_width_pos_exactfit(void){return test("% 5d", 52625);}
int bonus_sp_d_width_neg_exactfit(void){return test("% 5d", -2562);}
int bonus_sp_d_width_pos_nofit(void){return test("% 4d", 94827);}
int bonus_sp_d_width_neg_nofit(void){return test("% 4d", -2464);}
int bonus_sp_d_width_pos_fits_lj(void){return test("% -7d", 33);}
int bonus_sp_d_width_neg_fits_lj(void){return test("% -7d", -14);}
int bonus_sp_d_width_zero_fits_lj(void){return test("% -3d", 0);}
int bonus_sp_d_width_pos_exactfit_lj(void){return test("% -5d", 52625);}
int bonus_sp_d_width_neg_exactfit_lj(void){return test("% -5d", -2562);}
int bonus_sp_d_width_pos_nofit_lj(void){return test("% -4d", 94827);}
int bonus_sp_d_width_neg_nofit_lj(void){return test("% -4d", -2464);}
//signed integers with precision
int bonus_sp_d_prec_fits_pos(void){return test("% .5d", 2);}
int bonus_sp_d_prec_fits_neg(void){return test("% .6d", -3);}
int bonus_sp_d_prec_fits_zero(void){return test("% .3d", 0);}
int bonus_sp_d_prec_exactfit_pos(void){return test("% .4d", 5263);}
int bonus_sp_d_prec_exactfit_neg(void){return test("% .4d", -2372);}
int bonus_sp_d_prec_nofit_pos(void){return test("% .3d", 13862);}
int bonus_sp_d_prec_nofit_neg(void){return test("% .3d",-23646);}
//Signed integers - space with zero field width padding
int bonus_sp_d_zpsp_pos_fits(void){return test("% 05d", 43);}
int bonus_sp_d_zpsp_neg_fits(void){return test("% 07d", -54);}
int bonus_sp_d_zpsp_zero_fits(void){return test("% 03d", 0);}
int bonus_sp_d_zpsp_pos_exactfit(void){return test("% 03d", 634);}
int bonus_sp_d_zpsp_neg_exactfit(void){return test("% 04d", -532);}
int bonus_sp_d_zpsp_neg_minus1fit(void){return test("% 04d", -4825);}
//Signed integers - space with field width and precision
int bonus_sp_d_prec_width_fit_fit_pos(void){return test("% 8.5d", 34);}
int bonus_sp_d_prec_width_fit_fit_neg(void){return test("% 10.5d", -216);}
int bonus_sp_d_prec_width_fit_fit_zero(void){return test("% 8.5d", 0);}
int bonus_sp_d_prec_width_nofit_fit_pos(void){return test("% 8.3d", 8375);}
int bonus_sp_d_prec_width_nofit_fit_neg(void){return test("% 8.3d", -8473);}
int bonus_sp_d_prec_width_fit_nofit_pos(void){return test("% 3.7d", 3267);}
int bonus_sp_d_prec_width_fit_nofit_neg(void){return test("% 3.7d", -2375);}
int bonus_sp_d_prec_width_nofit_nofit_pos(void){return test("% 3.3d", 6983);}
int bonus_sp_d_prec_width_nofit_nofit_neg(void){return test("% 3.3d", -8462);}
//Signed integers - space with field width and precision, left-justified
int bonus_sp_d_prec_width_fit_fit_pos_lj(void){return test("% -8.5d", 34);}
int bonus_sp_d_prec_width_fit_fit_neg_lj(void){return test("% -10.5d", -216);}
int bonus_sp_d_prec_width_fit_fit_zero_lj(void){return test("% -8.5d", 0);}
int bonus_sp_d_prec_width_nofit_fit_pos_lj(void){return test("% -8.3d", 8375);}
int bonus_sp_d_prec_width_nofit_fit_neg_lj(void){return test("% -8.3d", -8473);}
int bonus_sp_d_prec_width_fit_nofit_pos_lj(void){return test("% -3.7d", 3267);}
int bonus_sp_d_prec_width_fit_nofit_neg_lj(void){return test("% -3.7d", -2375);}
int bonus_sp_d_prec_width_nofit_nofit_pos_lj(void){return test("% -3.3d", 6983);}
int bonus_sp_d_prec_width_nofit_nofit_neg_lj(void){return test("% -3.3d", -8462);}
//Signed integers - space with field width and precision with zeropadding
int bonus_sp_d_prec_width_ff_pos_zp(void){return test("% 08.5d", 34);}
int bonus_sp_d_prec_width_ff_neg_zp(void){return test("% 010.5d", -216);}
int bonus_sp_d_prec_width_ff_zero_zp(void){return test("% 08.5d", 0);}
int bonus_sp_d_prec_width_nf_pos_zp(void){return test("% 08.3d", 8375);}
int bonus_sp_d_prec_width_nf_neg_zp(void){return test("% 08.3d", -8473);}
int bonus_sp_d_prec_width_fn_pos_zp(void){return test("% 03.7d", 3267);}
int bonus_sp_d_prec_width_fn_neg_zp(void){return test("% 03.7d", -2375);}
int bonus_sp_d_prec_width_nn_pos_zp(void){return test("% 03.3d", 6983);}
int bonus_sp_d_prec_width_nn_neg_zp(void){return test("% 03.3d", -8462);}
//Signed integers - space with field width and precision, left-justified with zeropadding
int bonus_sp_d_prec_width_ff_pos_ljzpsp_ignoreflag(void){return test("% 0-8.5d", 34);}
int bonus_sp_d_prec_width_ff_neg_ljzpsp_ignoreflag(void){return test("% 0-10.5d", -216);}
int bonus_sp_d_prec_width_ff_zero_ljzpsp_ignoreflag(void){return test("% 0-8.5d", 0);}
int bonus_sp_d_prec_width_nf_pos_ljzpsp_ignoreflag(void){return test("% 0-8.3d", 8375);}
int bonus_sp_d_prec_width_nf_neg_ljzpsp_ignoreflag(void){return test("% 0-8.3d", -8473);}
int bonus_sp_d_prec_width_fn_pos_ljzpsp_ignoreflag(void){return test("% 0-3.7d", 3267);}
int bonus_sp_d_prec_width_fn_neg_ljzpsp_ignoreflag(void){return test("% 0-3.7d", -2375);}
int bonus_sp_d_prec_width_nn_pos_ljzpsp_ignoreflag(void){return test("% 0-3.3d", 6983);}
int bonus_sp_d_prec_width_nn_neg_ljzpsp_ignoreflag(void){return test("% 0-3.3d", -8462);}

//Signed integers - space - no modifers
int bonus_sp_i_basic_i_pos(void){return test("this % i number", 17);}
int bonus_sp_i_basic_i_neg(void){return test("this % i number", -267);}
int bonus_sp_i_basic_i_zero(void){return test("this % i number", 0);}
int bonus_sp_i_basic_i_onlypos(void){return test("% i", 3);}
int bonus_sp_i_basic_i_onlyneg(void){return test("% i", -1);}
int bonus_sp_i_basic_i_onlyzero(void){return test("% i", 0);}
int bonus_sp_i_basic_i_pos_d(void){return test("this % d number", 17);}
int bonus_sp_i_basic_i_neg_d(void){return test("this % d number", -267);}
int bonus_sp_i_basic_i_zero_d(void){return test("this % d number", 0);}
int bonus_sp_i_intmax(void){return test("% i", 2147483647);}
int bonus_sp_i_intmin(void){return test("% i", (int)(-2147483678));}
//Signed integers - space with field width
int bonus_sp_i_width_pos_fits(void){return test("% 7i", 33);}
int bonus_sp_i_width_neg_fits(void){return test("% 7i", -14);}
int bonus_sp_i_width_zero_fits(void){return test("% 3i", 0);}
int bonus_sp_i_width_pos_exactfit(void){return test("% 5i", 52625);}
int bonus_sp_i_width_neg_exactfit(void){return test("% 5i", -2562);}
int bonus_sp_i_width_pos_nofit(void){return test("% 4i", 94827);}
int bonus_sp_i_width_neg_nofit(void){return test("% 4i", -2464);}
int bonus_sp_i_width_pos_fits_lj(void){return test("% -7i", 33);}
int bonus_sp_i_width_neg_fits_lj(void){return test("% -7i", -14);}
int bonus_sp_i_width_zero_fits_lj(void){return test("% -3i", 0);}
int bonus_sp_i_width_pos_exactfit_lj(void){return test("% -5i", 52625);}
int bonus_sp_i_width_neg_exactfit_lj(void){return test("% -5i", -2562);}
int bonus_sp_i_width_pos_nofit_lj(void){return test("% -4i", 94827);}
int bonus_sp_i_width_neg_nofit_lj(void){return test("% -4i", -2464);}
//signed integers with precision
int bonus_sp_i_prec_fits_pos(void){return test("% .5i", 2);}
int bonus_sp_i_prec_fits_neg(void){return test("% .6i", -3);}
int bonus_sp_i_prec_fits_zero(void){return test("% .3i", 0);}
int bonus_sp_i_prec_exactfit_pos(void){return test("% .4i", 5263);}
int bonus_sp_i_prec_exactfit_neg(void){return test("% .4i", -2372);}
int bonus_sp_i_prec_nofit_pos(void){return test("% .3i", 13862);}
int bonus_sp_i_prec_nofit_neg(void){return test("% .3i",-23646);}
//Signed integers - space with zero field width padding
int bonus_sp_i_zpsp_pos_fits(void){return test("% 05i", 43);}
int bonus_sp_i_zpsp_neg_fits(void){return test("% 07i", -54);}
int bonus_sp_i_zpsp_zero_fits(void){return test("% 03i", 0);}
int bonus_sp_i_zpsp_pos_exactfit(void){return test("% 03i", 634);}
int bonus_sp_i_zpsp_neg_exactfit(void){return test("% 04i", -532);}
int bonus_sp_i_zpsp_neg_minus1fit(void){return test("% 04i", -4825);}
//Signed integers - space with field width and precision
int bonus_sp_i_prec_width_fit_fit_pos(void){return test("% 8.5i", 34);}
int bonus_sp_i_prec_width_fit_fit_neg(void){return test("% 10.5i", -216);}
int bonus_sp_i_prec_width_fit_fit_zero(void){return test("% 8.5i", 0);}
int bonus_sp_i_prec_width_nofit_fit_pos(void){return test("% 8.3i", 8375);}
int bonus_sp_i_prec_width_nofit_fit_neg(void){return test("% 8.3i", -8473);}
int bonus_sp_i_prec_width_fit_nofit_pos(void){return test("% 3.7i", 3267);}
int bonus_sp_i_prec_width_fit_nofit_neg(void){return test("% 3.7i", -2375);}
int bonus_sp_i_prec_width_nofit_nofit_pos(void){return test("% 3.3i", 6983);}
int bonus_sp_i_prec_width_nofit_nofit_neg(void){return test("% 3.3i", -8462);}
//Signed integers - space with field width and precision, left-justified
int bonus_sp_i_prec_width_fit_fit_pos_lj(void){return test("% -8.5i", 34);}
int bonus_sp_i_prec_width_fit_fit_neg_lj(void){return test("% -10.5i", -216);}
int bonus_sp_i_prec_width_fit_fit_zero_lj(void){return test("% -8.5i", 0);}
int bonus_sp_i_prec_width_nofit_fit_pos_lj(void){return test("% -8.3i", 8375);}
int bonus_sp_i_prec_width_nofit_fit_neg_lj(void){return test("% -8.3i", -8473);}
int bonus_sp_i_prec_width_fit_nofit_pos_lj(void){return test("% -3.7i", 3267);}
int bonus_sp_i_prec_width_fit_nofit_neg_lj(void){return test("% -3.7i", -2375);}
int bonus_sp_i_prec_width_nofit_nofit_pos_lj(void){return test("% -3.3i", 6983);}
int bonus_sp_i_prec_width_nofit_nofit_neg_lj(void){return test("% -3.3i", -8462);}
//Signed integers - space with field width and precision with zeropadding
int bonus_sp_i_prec_width_ff_pos_zp(void){return test("% 08.5i", 34);}
int bonus_sp_i_prec_width_ff_neg_zp(void){return test("% 010.5i", -216);}
int bonus_sp_i_prec_width_ff_zero_zp(void){return test("% 08.5i", 0);}
int bonus_sp_i_prec_width_nf_pos_zp(void){return test("% 08.3i", 8375);}
int bonus_sp_i_prec_width_nf_neg_zp(void){return test("% 08.3i", -8473);}
int bonus_sp_i_prec_width_fn_pos_zp(void){return test("% 03.7i", 3267);}
int bonus_sp_i_prec_width_fn_neg_zp(void){return test("% 03.7i", -2375);}
int bonus_sp_i_prec_width_nn_pos_zp(void){return test("% 03.3i", 6983);}
int bonus_sp_i_prec_width_nn_neg_zp(void){return test("% 03.3i", -8462);}
//Signed integers - space with field width and precision, left-justified with zeropadding
int bonus_sp_i_prec_width_ff_pos_ljzpsp_ignoreflag(void){return test("% 0-8.5i", 34);}
int bonus_sp_i_prec_width_ff_neg_ljzpsp_ignoreflag(void){return test("% 0-10.5i", -216);}
int bonus_sp_i_prec_width_ff_zero_ljzpsp_ignoreflag(void){return test("% 0-8.5i", 0);}
int bonus_sp_i_prec_width_nf_pos_ljzpsp_ignoreflag(void){return test("% 0-8.3i", 8375);}
int bonus_sp_i_prec_width_nf_neg_ljzpsp_ignoreflag(void){return test("% 0-8.3i", -8473);}
int bonus_sp_i_prec_width_fn_pos_ljzpsp_ignoreflag(void){return test("% 0-3.7i", 3267);}
int bonus_sp_i_prec_width_fn_neg_ljzpsp_ignoreflag(void){return test("% 0-3.7i", -2375);}
int bonus_sp_i_prec_width_nn_pos_ljzpsp_ignoreflag(void){return test("% 0-3.3i", 6983);}
int bonus_sp_i_prec_width_nn_neg_ljzpsp_ignoreflag(void){return test("% 0-3.3i", -8462);}

//nocrash tests adapted from tests contributed by phtruong
int nocrash_notrequired_bonus_sp_dupflag_d(void){return test("%  d", 42);}
//nocrash tests that came about as part of the minimal specification
int nocrash_notrequired_bonus_sp_c_1(void){return test("% c", 'a');}
int nocrash_notrequired_bonus_sp_c_2(void){return test("% c", -42);}
int nocrash_notrequired_bonus_sp_s_1(void){return test("% s", "hello");}
int nocrash_notrequired_bonus_sp_p_1(void){return test("% p", &ncm_p);}
int nocrash_notrequired_bonus_sp_p_2(void){return test("% p", &ncm_p);}
int nocrash_notrequired_bonus_sp_u(void){return test("% u", 42);}
int nocrash_notrequired_bonus_sp_x(void){return test("% x", 42);}
int nocrash_notrequired_bonus_sp_X(void){return test("% X", 42);}


/* -----------------------------------------------------------------------------
** 						'#' FLAG (ALTFORM) TESTS (BONUS)
** ---------------------------------------------------------------------------*/
//Hexadecimal lower (altform) - no modifers
int bonus_af_x_basic_pos(void){return test("this %#x number", 17);}
int bonus_af_x_basic_zero(void){return test("this %#x number", 0);}
int bonus_af_x_basic_onlypos(void){return test("%#x", 3);}
int bonus_af_x_hexlmax(void){return test("%#x", 4294967295u);}
//Hexadecimal lower (altform) with field width
int bonus_af_x_width_pos_fits(void){return test("%#7x", 33);}
int bonus_af_x_width_zero_fits(void){return test("%#3x", 0);}
int bonus_af_x_width_pos_exactfit(void){return test("%#5x", 52625);}
int bonus_af_x_width_pos_nofit(void){return test("%#2x", 94827);}
int bonus_af_x_width_pos_fits_lj(void){return test("%#-7x", 33);}
int bonus_af_x_width_zero_fits_lj(void){return test("%#-3x", 0);}
int bonus_af_x_width_pos_exactfit_lj(void){return test("%#-5x", 52625);}
int bonus_af_x_width_pos_nofit_lj(void){return test("%#-4x", 9648627);}
//Hexadecimal lower (altform) with precision
int bonus_af_x_prec_fits_pos(void){return test("%#.5x", 21);}
int bonus_af_x_prec_fits_zero(void){return test("%#.3x", 0);}
int bonus_af_x_prec_exactfit_pos(void){return test("%#.4x", 5263);}
int bonus_af_x_prec_nofit_pos(void){return test("%#.3x", 938862);}
int bonus_af_x_prec0val0(void){return test("%#.0x", 0);}
int bonus_af_x_prec0val0_impl(void){return test("%#.x", 0);}
int bonus_af_x_prec0val0_waf(void){return test("%#5.0x", 0);}
int bonus_af_x_prec0val0_waf_impl(void){return test("%#5.x", 0);}
int bonus_af_x_prec0val0_waflj(void){return test("%#-5.0x", 0);}
int bonus_af_x_prec0val0_waflj_impl(void){return test("%#-5.x", 0);}
//Hexadecimal lower (altform) with zero field width padding
int bonus_af_x_zp_pos_fits(void){return test("%#05x", 43);}
int bonus_af_x_zp_zero_fits(void){return test("%#03x", 0);}
int bonus_af_x_zp_pos_exactfit(void){return test("%#03x", 698334);}
//Hexadecimal lower (altform) with field width and precision
int bonus_af_x_prec_width_fit_fit_pos(void){return test("%#8.5x", 34);}
int bonus_af_x_prec_width_fit_fit_zero(void){return test("%#8.5x", 0);}
int bonus_af_x_prec_width_nofit_fit_pos(void){return test("%#8.3x", 8375);}
int bonus_af_x_prec_width_fit_nofit_pos(void){return test("%#2.7x", 3267);}
int bonus_af_x_prec_width_nofit_nofit_pos(void){return test("%#3.3x", 6983);}
//Hexadecimal lower (altform) with field width and precision, left-justified
int bonus_af_x_prec_width_fit_fit_pos_lj(void){return test("%#-8.5x", 34);}
int bonus_af_x_prec_width_fit_fit_zero_lj(void){return test("%#-8.5x", 0);}
int bonus_af_x_prec_width_nofit_fit_pos_lj(void){return test("%#-8.3x", 8375);}
int bonus_af_x_prec_width_fit_nofit_pos_lj(void){return test("%#-2.7x", 3267);}
int bonus_af_x_prec_width_nofit_nofit_pos_lj(void){return test("%#-3.3x", 6983);}
//Hexadecimal lower (altform) with field width and precision with zeropadding
int bonus_af_x_prec_width_ff_pos_zp(void){return test("%#08.5x", 34);}
int bonus_af_x_prec_width_ff_zero_zp(void){return test("%#08.5x", 0);}
int bonus_af_x_prec_width_nf_pos_zp(void){return test("%#08.3x", 8375);}
int bonus_af_x_prec_width_fn_pos_zp(void){return test("%#02.7x", 3267);}
int bonus_af_x_prec_width_nn_pos_zp(void){return test("%#03.3x", 6983);}
//Hexadecimal lower (altform) with field width and precision, left-justified with zeropadding
int bonus_af_x_prec_width_ff_pos_ljzpaf_ignoreflag(void){return test("%#0-8.5x", 34);}
int bonus_af_x_prec_width_ff_zero_ljzpaf_ignoreflag(void){return test("%#0-8.5x", 0);}
int bonus_af_x_prec_width_nf_pos_ljzpaf_ignoreflag(void){return test("%#0-8.3x", 8375);}
int bonus_af_x_prec_width_fn_pos_ljzpaf_ignoreflag(void){return test("%#0-2.7x", 3267);}
int bonus_af_x_prec_width_nn_pos_ljzpaf_ignoreflag(void){return test("%#0-3.3x", 6983);}

//Hex uppers (altform) - no modifers
int bonus_af_X_basic_hexu_pos(void){return test("this %#X number", 17);}
int bonus_af_X_basic_hexu_zero(void){return test("this %#X number", 0);}
int bonus_af_X_basic_hexu_onlypos(void){return test("%#X", 3);}
int bonus_af_X_hexumax(void){return test("%#X", 4294967295u);}
//Hex uppers (altform) with field width
int bonus_af_X_width_pos_fits(void){return test("%#7X", 33);}
int bonus_af_X_width_zero_fits(void){return test("%#3X", 0);}
int bonus_af_X_width_pos_exactfit(void){return test("%#7X", 52625);}
int bonus_af_X_width_pos_nofit(void){return test("%#2X", 94827);}
int bonus_af_X_width_pos_fits_lj(void){return test("%#-7X", 33);}
int bonus_af_X_width_zero_fits_lj(void){return test("%#-3X", 0);}
int bonus_af_X_width_pos_exactfit_lj(void){return test("%#-7X", 52625);}
int bonus_af_X_width_pos_nofit_lj(void){return test("%#-4X", 9648627);}
//Hex uppers (altform) with precision
int bonus_af_X_prec_fits_pos(void){return test("%#.5X", 21);}
int bonus_af_X_prec_fits_zero(void){return test("%#.3X", 0);}
int bonus_af_X_prec_exactfit_pos(void){return test("%#.4X", 5263);}
int bonus_af_X_prec_nofit_pos(void){return test("%#.3X", 938862);}
int bonus_af_X_prec0val0(void){return test("%#.0X", 0);}
int bonus_af_X_prec0val0_impl(void){return test("%#.X", 0);}
int bonus_af_X_prec0val0_waf(void){return test("%#5.0X", 0);}
int bonus_af_X_prec0val0_waf_impl(void){return test("%#5.X", 0);}
int bonus_af_X_prec0val0_waflj(void){return test("%#-5.0X", 0);}
int bonus_af_X_prec0val0_waflj_impl(void){return test("%#-5.X", 0);}
//Hex uppers (altform) with zero field width padding
int bonus_af_X_zp_pos_fits(void){return test("%#05X", 43);}
int bonus_af_X_zp_zero_fits(void){return test("%#03X", 0);}
int bonus_af_X_zp_pos_exactfit(void){return test("%#03X", 698334);}
//Hex uppers (altform) with field width and precision
int bonus_af_X_prec_width_fit_fit_pos(void){return test("%#8.5X", 34);}
int bonus_af_X_prec_width_fit_fit_zero(void){return test("%#8.5X", 0);}
int bonus_af_X_prec_width_nofit_fit_pos(void){return test("%#8.3X", 8375);}
int bonus_af_X_prec_width_fit_nofit_pos(void){return test("%#2.7X", 3267);}
int bonus_af_X_prec_width_nofit_nofit_pos(void){return test("%#3.3X", 6983);}
//Hex uppers (altform) with field width and precision, left-justified
int bonus_af_X_prec_width_fit_fit_pos_lj(void){return test("%#-8.5X", 34);}
int bonus_af_X_prec_width_fit_fit_zero_lj(void){return test("%#-8.5X", 0);}
int bonus_af_X_prec_width_nofit_fit_pos_lj(void){return test("%#-8.3X", 8375);}
int bonus_af_X_prec_width_fit_nofit_pos_lj(void){return test("%#-2.7X", 3267);}
int bonus_af_X_prec_width_nofit_nofit_pos_lj(void){return test("%#-3.3X", 6983);}
//Hex uppers (altform) with field width and precision with zeropadding
int bonus_af_X_prec_width_ff_pos_zp(void){return test("%#08.5X", 34);}
int bonus_af_X_prec_width_ff_zero_zp(void){return test("%#08.5X", 0);}
int bonus_af_X_prec_width_nf_pos_zp(void){return test("%#08.3X", 8375);}
int bonus_af_X_prec_width_fn_pos_zp(void){return test("%#02.7X", 3267);}
int bonus_af_X_prec_width_nn_pos_zp(void){return test("%#03.3X", 6983);}
//Hex uppers (altform) with field width and precision, left-justified with zeropadding
int bonus_af_X_prec_width_ff_pos_ljzpaf_ignoreflag(void){return test("%#0-8.5X", 34);}
int bonus_af_X_prec_width_ff_zero_ljzpaf_ignoreflag(void){return test("%#0-8.5X", 0);}
int bonus_af_X_prec_width_nf_pos_ljzpaf_ignoreflag(void){return test("%#0-8.3X", 8375);}
int bonus_af_X_prec_width_fn_pos_ljzpaf_ignoreflag(void){return test("%#0-2.7X", 3267);}
int bonus_af_X_prec_width_nn_pos_ljzpaf_ignoreflag(void){return test("%#0-3.3X", 6983);}

//No-crash-no-segfault test
int nocrash_notrequired_bonus_af_noarg_4(void){return test("%#"); }
int nocrash_notrequired_bonus_af_nullarg_4(void){return test("%#s", NULL); }
//nocrash tests adapted from tests contributed by phtruong
int nocrash_notrequired_bonus_af_dupflag_x(void){return test("%##x", 42);}
int nocrash_notrequired_bonus_af_dupflag_xasasljw(void){return test("%#++#-5x", 42);}
//nocrash tests that came about as part of the minimal specification
int nocrash_notrequired_bonus_af_c(void){return test("%#c", 'a');}
int nocrash_notrequired_bonus_af_s(void){return test("%#s", "hello");}
int nocrash_notrequired_bonus_af_p(void){return test("%#p", &ncm_p);}
int nocrash_notrequired_bonus_af_d(void){return test("%#d", 42);}
int nocrash_notrequired_bonus_af_i(void){return test("%#i", 42);}
int nocrash_notrequired_bonus_af_u(void){return test("%#u", 42);}


/* -----------------------------------------------------------------------------
** 						'# +' FLAGS TESTS (BONUS)
** ---------------------------------------------------------------------------*/

// SPACE WITH ALLSIGN - MIGHT BE UNDEFINED BEHAVIOR
//Signed integers - space with allsign ('+')
int bonus_assp_d_pos_ignoreflag(void){return test("% +d", 5);}
int bonus_assp_d_neg_ignoreflag(void){return test("% +d", -7);}
int bonus_assp_d_intmax_ignoreflag(void){return test("% +d", 2147483647);}
//signed integers with field width and allsign
int bonus_assp_d_width_pos_ignoreflag(void){return test("% +5d", 35);}
int bonus_assp_d_width_zero_ignoreflag(void){return test("% +7d", 0);}
int bonus_assp_d_width_intmax_ignoreflag(void){return test("% +24d", 2147483647);}
int bonus_assp_d_prec_pos_ignoreflag(void){return test("% +.7d", 234);}
int bonus_assp_d_prec_neg_ignoreflag(void){return test("% +.7d", -446);}
int bonus_assp_d_prec_pos_nofit_ignoreflag(void){return test("% +.3d", 3723);}
int bonus_assp_d_zpassp_as_fits_ignoreflag(void){return test("% +05d", 432);}
int bonus_assp_d_zpassp_zero_ignoreflag(void){return test("% +04d", 0);}
//Signed integers - space with field width and precision with allsign
int bonus_assp_d_prec_width_fit_fit_pos_ignoreflag(void){return test("% +8.5d", 34);}
int bonus_assp_d_prec_width_fit_fit_neg_ignoreflag(void){return test("% +10.5d", -216);}
int bonus_assp_d_prec_width_fit_fit_zero_ignoreflag(void){return test("% +8.5d", 0);}
int bonus_assp_d_prec_width_nofit_fit_pos_ignoreflag(void){return test("% +8.3d", 8375);}
int bonus_assp_d_prec_width_nofit_fit_neg_ignoreflag(void){return test("% +8.3d", -8473);}
int bonus_assp_d_prec_width_fit_nofit_pos_ignoreflag(void){return test("% +3.7d", 3267);}
int bonus_assp_d_prec_width_fit_nofit_neg_ignoreflag(void){return test("% +3.7d", -2375);}
int bonus_assp_d_prec_width_nofit_nofit_pos_ignoreflag(void){return test("% +3.3d", 6983);}
int bonus_assp_d_prec_width_nofit_nofit_neg_ignoreflag(void){return test("% +3.3d", -8462);}
int bonus_assp_d_prec0val0_was(void){return test("%+5.0d", 0);}
int bonus_assp_d_prec0val0_was_impl(void){return test("%+5.d", 0);}
int bonus_assp_d_prec0val0_waslj(void){return test("%+-5.0d", 0);}
int bonus_assp_d_prec0val0_waslj_impl(void){return test("%+-5.d", 0);}
//Signed integers - space with field width and precision, left-justified with allsign
int bonus_assp_d_prec_width_fit_fit_pos_lj_ignoreflag(void){return test("% +-8.5d", 34);}
int bonus_assp_d_prec_width_fit_fit_neg_lj_ignoreflag(void){return test("% +-10.5d", -216);}
int bonus_assp_d_prec_width_fit_fit_zero_lj_ignoreflag(void){return test("% +-8.5d", 0);}
int bonus_assp_d_prec_width_nofit_fit_pos_lj_ignoreflag(void){return test("% +-8.3d", 8375);}
int bonus_assp_d_prec_width_nofit_fit_neg_lj_ignoreflag(void){return test("% +-8.3d", -8473);}
int bonus_assp_d_prec_width_fit_nofit_pos_lj_ignoreflag(void){return test("% +-3.7d", 3267);}
int bonus_assp_d_prec_width_fit_nofit_neg_lj_ignoreflag(void){return test("% +-3.7d", -2375);}
int bonus_assp_d_prec_width_nofit_nofit_pos_lj_ignoreflag(void){return test("% +-3.3d", 6983);}
int bonus_assp_d_prec_width_nofit_nofit_neg_lj_ignoreflag(void){return test("% +-3.3d", -8462);}
//Signed integers - space with field width and precision with allsign with zeropadding
int bonus_assp_d_prec_width_ff_pos_aszpsp_ignoreflag(void){return test("% 0+8.5d", 34);}
int bonus_assp_d_prec_width_ff_neg_aszpsp_ignoreflag(void){return test("% 0+10.5d", -216);}
int bonus_assp_d_prec_width_ff_zero_aszpsp_ignoreflag(void){return test("% 0+8.5d", 0);}
int bonus_assp_d_prec_width_nf_pos_aszpsp_ignoreflag(void){return test("% 0+8.3d", 8375);}
int bonus_assp_d_prec_width_nf_neg_aszpsp_ignoreflag(void){return test("% 0+8.3d", -8473);}
int bonus_assp_d_prec_width_fn_pos_aszpsp_ignoreflag(void){return test("% 0+3.7d", 3267);}
int bonus_assp_d_prec_width_fn_neg_aszpsp_ignoreflag(void){return test("% 0+3.7d", -2375);}
int bonus_assp_d_prec_width_nn_pos_aszpsp_ignoreflag(void){return test("% 0+3.3d", 6983);}
int bonus_assp_d_prec_width_nn_neg_aszpsp_ignoreflag(void){return test("% 0+3.3d", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign with zeropadding
int bonus_assp_d_prec_width_ff_pos_ljaszpsp_ignoreflag(void){return test("% 0+-8.5d", 34);}
int bonus_assp_d_prec_width_ff_neg_ljaszpsp_ignoreflag(void){return test("% 0+-10.5d", -216);}
int bonus_assp_d_prec_width_ff_zero_ljaszpsp_ignoreflag(void){return test("% 0+-8.5d", 0);}
int bonus_assp_d_prec_width_nf_pos_ljaszpsp_ignoreflag(void){return test("% 0+-8.3d", 8375);}
int bonus_assp_d_prec_width_nf_neg_ljaszpsp_ignoreflag(void){return test("% 0+-8.3d", -8473);}
int bonus_assp_d_prec_width_fn_pos_ljaszpsp_ignoreflag(void){return test("% 0+-3.7d", 3267);}
int bonus_assp_d_prec_width_fn_neg_ljaszpsp_ignoreflag(void){return test("% 0+-3.7d", -2375);}
int bonus_assp_d_prec_width_nn_pos_ljaszpsp_ignoreflag(void){return test("% 0+-3.3d", 6983);}
int bonus_assp_d_prec_width_nn_neg_ljaszpsp_ignoreflag(void){return test("% 0+-3.3d", -8462);}
//Signed integers - space with allsign ('+')
int bonus_assp_i_pos_ignoreflag(void){return test("% +i", 5);}
int bonus_assp_i_neg_ignoreflag(void){return test("% +i", -7);}
int bonus_assp_i_intmax_ignoreflag(void){return test("% +i", 2147483647);}
//signed integers with field width and allsign
int bonus_assp_i_width_pos_ignoreflag(void){return test("% +5i", 35);}
int bonus_assp_i_width_zero_ignoreflag(void){return test("% +7i", 0);}
int bonus_assp_i_width_intmax_ignoreflag(void){return test("% +24i", 2147483647);}
int bonus_assp_i_prec_pos_ignoreflag(void){return test("% +.7i", 234);}
int bonus_assp_i_prec_neg_ignoreflag(void){return test("% +.7i", -446);}
int bonus_assp_i_prec_pos_nofit_ignoreflag(void){return test("% +.3i", 3723);}
int bonus_assp_i_zpassp_as_fits_ignoreflag(void){return test("% +05i", 432);}
int bonus_assp_i_zpassp_zero_ignoreflag(void){return test("% +04i", 0);}
//Signed integers - space with field width and precision with allsign
int bonus_assp_i_prec_width_fit_fit_pos_ignoreflag(void){return test("% +8.5i", 34);}
int bonus_assp_i_prec_width_fit_fit_neg_ignoreflag(void){return test("% +10.5i", -216);}
int bonus_assp_i_prec_width_fit_fit_zero_ignoreflag(void){return test("% +8.5i", 0);}
int bonus_assp_i_prec_width_nofit_fit_pos_ignoreflag(void){return test("% +8.3i", 8375);}
int bonus_assp_i_prec_width_nofit_fit_neg_ignoreflag(void){return test("% +8.3i", -8473);}
int bonus_assp_i_prec_width_fit_nofit_pos_ignoreflag(void){return test("% +3.7i", 3267);}
int bonus_assp_i_prec_width_fit_nofit_neg_ignoreflag(void){return test("% +3.7i", -2375);}
int bonus_assp_i_prec_width_nofit_nofit_pos_ignoreflag(void){return test("% +3.3i", 6983);}
int bonus_assp_i_prec_width_nofit_nofit_neg_ignoreflag(void){return test("% +3.3i", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign
int bonus_assp_i_prec_width_fit_fit_pos_lj_ignoreflag(void){return test("% +-8.5i", 34);}
int bonus_assp_i_prec_width_fit_fit_neg_lj_ignoreflag(void){return test("% +-10.5i", -216);}
int bonus_assp_i_prec_width_fit_fit_zero_lj_ignoreflag(void){return test("% +-8.5i", 0);}
int bonus_assp_i_prec_width_nofit_fit_pos_lj_ignoreflag(void){return test("% +-8.3i", 8375);}
int bonus_assp_i_prec_width_nofit_fit_neg_lj_ignoreflag(void){return test("% +-8.3i", -8473);}
int bonus_assp_i_prec_width_fit_nofit_pos_lj_ignoreflag(void){return test("% +-3.7i", 3267);}
int bonus_assp_i_prec_width_fit_nofit_neg_lj_ignoreflag(void){return test("% +-3.7i", -2375);}
int bonus_assp_i_prec_width_nofit_nofit_pos_lj_ignoreflag(void){return test("% +-3.3i", 6983);}
int bonus_assp_i_prec_width_nofit_nofit_neg_lj_ignoreflag(void){return test("% +-3.3i", -8462);}
//Signed integers - space with field width and precision with allsign with zeropadding
int bonus_assp_i_prec_width_ff_pos_aszpsp_ignoreflag(void){return test("% 0+8.5i", 34);}
int bonus_assp_i_prec_width_ff_neg_aszpsp_ignoreflag(void){return test("% 0+10.5i", -216);}
int bonus_assp_i_prec_width_ff_zero_aszpsp_ignoreflag(void){return test("% 0+8.5i", 0);}
int bonus_assp_i_prec_width_nf_pos_aszpsp_ignoreflag(void){return test("% 0+8.3i", 8375);}
int bonus_assp_i_prec_width_nf_neg_aszpsp_ignoreflag(void){return test("% 0+8.3i", -8473);}
int bonus_assp_i_prec_width_fn_pos_aszpsp_ignoreflag(void){return test("% 0+3.7i", 3267);}
int bonus_assp_i_prec_width_fn_neg_aszpsp_ignoreflag(void){return test("% 0+3.7i", -2375);}
int bonus_assp_i_prec_width_nn_pos_aszpsp_ignoreflag(void){return test("% 0+3.3i", 6983);}
int bonus_assp_i_prec_width_nn_neg_aszpsp_ignoreflag(void){return test("% 0+3.3i", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign with zeropadding
int bonus_assp_i_prec_width_ff_pos_ljaszpsp_ignoreflag(void){return test("% 0+-8.5i", 34);}
int bonus_assp_i_prec_width_ff_neg_ljaszpsp_ignoreflag(void){return test("% 0+-10.5i", -216);}
int bonus_assp_i_prec_width_ff_zero_ljaszpsp_ignoreflag(void){return test("% 0+-8.5i", 0);}
int bonus_assp_i_prec_width_nf_pos_ljaszpsp_ignoreflag(void){return test("% 0+-8.3i", 8375);}
int bonus_assp_i_prec_width_nf_neg_ljaszpsp_ignoreflag(void){return test("% 0+-8.3i", -8473);}
int bonus_assp_i_prec_width_fn_pos_ljaszpsp_ignoreflag(void){return test("% 0+-3.7i", 3267);}
int bonus_assp_i_prec_width_fn_neg_ljaszpsp_ignoreflag(void){return test("% 0+-3.7i", -2375);}
int bonus_assp_i_prec_width_nn_pos_ljaszpsp_ignoreflag(void){return test("% 0+-3.3i", 6983);}
int bonus_assp_i_prec_width_nn_neg_ljaszpsp_ignoreflag(void){return test("% 0+-3.3i", -8462);}

//nocrash tests adapted from tests contributed by phtruong
int nocrash_notrequired_bonus_assp_dupflag_d_spassp(void){return test("% + d", 42);}


/* -----------------------------------------------------------------------------
** 						'l ll h hh' FLAGS (LENGTH) TESTS (BONUS)
** ---------------------------------------------------------------------------*/

static char 		ch_pos_1 = 100, ch_neg_1 = -87;
static short		sh_pos_1 = 3047, sh_neg_1 = -8875;
static int			i_pos_1 = 878023;
static long			l_pos_1 = 22337203685477, l_neg_1 = -22337203685477;
static long long	ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
static long			lmax	= 9223372036854775807;
static long			lmin	= -9223372036854775807;
static long long	llmax = 9223372036854775807;
static long long	llmin = -9223372036854775807ll;
//Signed integers of varying size modifiers
int bonus_length_d_hh_pos_casted(void){return test("%hhd", (char)45);}
int bonus_length_d_hh_neg_casted(void){return test("%hhd", (char)-45);}
int bonus_length_d_h_pos_casted(void){return test("%hd", (short)385);}
int bonus_length_d_h_neg_casted(void){return test("%hd", (short)-385);}
int bonus_length_d_ll_pos_casted(void){return test("%lld", (long long)43);}
int bonus_length_d_ll_neg_casted(void){return test("%lld", (long long)-43);}
int bonus_length_d_l_pos_casted(void){return test("%ld", (long)32);}
int bonus_length_d_l_neg_casted(void){return test("%ld", (long)-32);}
int bonus_length_d_hh_pos_ref(void){return test("%hhd", ch_pos_1);}
int bonus_length_d_hh_neg_ref(void){return test("%hhd", ch_neg_1);}
int bonus_length_d_h_pos_ref(void){return test("%hd", sh_pos_1);}
int bonus_length_d_h_neg_ref(void){return test("%hd", sh_neg_1);}
int bonus_length_d_ll_pos_ref_llmax(void){return test("%lld", llmax);}
int bonus_length_d_ll_pos_ref(void){return test("%lld", ll_pos_1);}
int bonus_length_d_ll_neg_ref(void){return test("%lld", ll_neg_1);}
int bonus_length_d_l_pos_ref(void){return test("%ld", l_pos_1);}
int bonus_length_d_l_pos_ref_lmax(void){return test("%ld", lmax);}
int bonus_length_d_l_neg_ref(void){return test("%ld", l_neg_1);}
int bonus_length_d_ll_pos_big(void){return test("%lld", 522337203685470ll);}
int bonus_length_d_ll_neg_big(void){return test("%lld", -522337203685470ll);}
int bonus_length_d_l_pos_big(void){return test("%ld", 22337203685477);}
int bonus_length_d_l_neg_big(void){return test("%ld", -22337203685477);}
int bonus_length_d_l_pos_big_as(void){return test("%+ld", 22337203685477l);}
int bonus_length_d_llmax(void){return test("%lld", 9223372036854775807ll);}
int bonus_length_d_llmin(void){return test("%lld", llmin);}
int bonus_length_d_lmax(void){return test("%ld", 9223372036854775807l);}
int bonus_length_d_lmin(void){return test("%ld", lmin);}
int bonus_length_d_hmax(void){return test("%hd", (short)32767);}
int bonus_length_d_hmin(void){return test("%hd", (short)(-32768));}
int bonus_length_d_hhmax(void){return test("%hhd", (char)127);}
int bonus_length_d_hhmin(void){return test("%hhd", (char)(-128));}
//Signed integers of varying size modifiers with some other modifiers
int bonus_length_d_l_pos_big_zp(void){return test("%037ld", 22337203685477l);}
int bonus_length_d_l_neg_big_prec(void){return test("%.37ld", -22337203685477l);}
int bonus_length_d_ll_pos_big_width(void){return test("%37lld", 522337203685470ll);}
int bonus_length_d_ll_neg_big_lj(void){return test("%-37lld", -522337203685470ll);}
//Multiple signed integers in a row of varying sizes
int bonus_length_d_follows_i_i(void){return test("[%d] [%d]", i_pos_1, i_pos_1);}
int bonus_length_d_follows_i_l(void){return test("[%d] [%ld]", i_pos_1, l_pos_1);}
int bonus_length_d_follows_i_ll(void){return test("[%d] [%lld]", i_pos_1, ll_pos_1);}
int bonus_length_d_follows_i_h(void){return test("[%d] [%hd]", i_pos_1, sh_pos_1);}
int bonus_length_d_follows_i_hh(void){return test("[%d] [%hhd]", i_pos_1, ch_pos_1);}
int bonus_length_d_ll_hh_ll(void){return test("%lld%hhd%lld", ll_pos_1, ch_neg_1, ll_neg_1);}
int bonus_length_d_h_l_hh(void){return test("%hd%ld%hhd", sh_pos_1, l_neg_1, ch_neg_1);}
int bonus_length_d_l_hh_h(void){return test("%ld%hhd%hd", l_neg_1, ch_pos_1, sh_pos_1);}
int bonus_length_d_n_ll_hh(void){return test("%d%lld%hhd", i_pos_1, ll_neg_1, ch_pos_1);}
int bonus_length_d_ll_n_l(void){return test("%lli%d%ld", ll_neg_1, i_pos_1, l_pos_1);}
//Signed integers - space of varying size modifiers
int bonus_length_d_hh_pos_casted_sp(void){return test("% hhd", (char)45);}
int bonus_length_d_hh_neg_casted_sp(void){return test("% hhd", (char)-45);}
int bonus_length_d_h_pos_casted_sp(void){return test("% hd", (short)385);}
int bonus_length_d_h_neg_casted_sp(void){return test("% hd", (short)-385);}
int bonus_length_d_l_pos_casted_sp(void){return test("% ld", (long)32);}
int bonus_length_d_l_neg_casted_sp(void){return test("% ld", (long)-32);}
int bonus_length_d_ll_pos_casted_sp(void){return test("% lld", (long long)43);}
int bonus_length_d_ll_neg_casted_sp(void){return test("% lld", (long long)-43);}
int bonus_length_d_hh_pos_ref_sp(void){return test("% hhd", ch_pos_1);}
int bonus_length_d_hh_neg_ref_sp(void){return test("% hhd", ch_neg_1);}
int bonus_length_d_h_pos_ref_sp(void){return test("% hd", sh_pos_1);}
int bonus_length_d_h_neg_ref_sp(void){return test("% hd", sh_neg_1);}
int bonus_length_d_l_pos_ref_sp(void){return test("% ld", l_pos_1);}
int bonus_length_d_l_neg_ref_sp(void){return test("% ld", l_neg_1);}
int bonus_length_d_ll_pos_ref_sp(void){return test("% lld", ll_pos_1);}
int bonus_length_d_ll_neg_ref_sp(void){return test("% lld", ll_neg_1);}
int bonus_length_d_l_pos_big_sp(void){return test("% ld", 22337203685477l);}
int bonus_length_d_l_neg_big_sp(void){return test("% ld", -22337203685477l);}
int bonus_length_d_ll_pos_big_sp(void){return test("% lld", 522337203685470ll);}
int bonus_length_d_ll_neg_big_sp(void){return test("% lld", -522337203685470ll);}
int bonus_length_d_llmax_sp(void){return test("% lld", 9223372036854775807ll);}
int bonus_length_d_llmin_sp(void){return test("% lld", llmin);}
int bonus_length_d_lmax_sp(void){return test("% ld", 9223372036854775807l);}
int bonus_length_d_lmin_sp(void){return test("% ld", lmin);}
int bonus_length_d_hmax_sp(void){return test("% hd", (short)32767);}
int bonus_length_d_hmin_sp(void){return test("% hd", (short)(-32768));}
int bonus_length_d_hhmax_sp(void){return test("% hhd", (char)(127));}
int bonus_length_d_hhmin_sp(void){return test("% hhd", (char)(-128));}

//Signed integers of varying size modifiers
int bonus_length_i_hh_pos_casted(void){return test("%hhi", (char)45);}
int bonus_length_i_hh_neg_casted(void){return test("%hhi", (char)-45);}
int bonus_length_i_h_pos_casted(void){return test("%hi", (short)385);}
int bonus_length_i_h_neg_casted(void){return test("%hi", (short)-385);}
int bonus_length_i_l_pos_casted(void){return test("%li", (long)32);}
int bonus_length_i_l_neg_casted(void){return test("%li", (long)-32);}
int bonus_length_i_ll_pos_casted(void){return test("%lli", (long long)43);}
int bonus_length_i_ll_neg_casted(void){return test("%lli", (long long)-43);}
int bonus_length_i_hh_pos_ref(void){return test("%hhi", ch_pos_1);}
int bonus_length_i_hh_neg_ref(void){return test("%hhi", ch_neg_1);}
int bonus_length_i_h_pos_ref(void){return test("%hi", sh_pos_1);}
int bonus_length_i_h_neg_ref(void){return test("%hi", sh_neg_1);}
int bonus_length_i_l_pos_ref(void){return test("%li", l_pos_1);}
int bonus_length_i_l_pos_ref_lmax(void){return test("%li", lmax);}
int bonus_length_i_ll_pos_ref_llmax(void){return test("%lli", llmax);}
int bonus_length_i_l_neg_ref(void){return test("%li", l_neg_1);}
int bonus_length_i_ll_pos_ref(void){return test("%lli", ll_pos_1);}
int bonus_length_i_ll_neg_ref(void){return test("%lli", ll_neg_1);}
int bonus_length_i_l_pos_big(void){return test("%li", 22337203685477);}
int bonus_length_i_l_neg_big(void){return test("%li", -22337203685477);}
int bonus_length_i_ll_pos_big(void){return test("%lli", 522337203685470ll);}
int bonus_length_i_ll_neg_big(void){return test("%lli", -522337203685470ll);}
int bonus_length_i_llmax(void){return test("%lli", 9223372036854775807ll);}
int bonus_length_i_llmin(void){return test("%lli", llmin);}
int bonus_length_i_lmax(void){return test("%li", 9223372036854775807l);}
int bonus_length_i_lmin(void){return test("%li", lmin);}
int bonus_length_i_hmax(void){return test("%hi", (short)32767);}
int bonus_length_i_hmin(void){return test("%hi", (short)(-32768));}
int bonus_length_i_hhmax(void){return test("%hhi", (char)127);}
int bonus_length_i_hhmin(void){return test("%hhi", (char)(-128));}
//Signed integers of varying size modifiers with some other modifiers
int bonus_length_i_l_pos_big_zp(void){return test("%037li", 22337203685477l);}
int bonus_length_i_l_neg_big_prec(void){return test("%.37li", -22337203685477l);}
int bonus_length_i_ll_pos_big_width(void){return test("%37lli", 522337203685470ll);}
int bonus_length_i_ll_neg_big_lj(void){return test("%-37lli", -522337203685470ll);}
//Multiple signed integers in a row of varying sizes
int bonus_length_i_follows_i_i(void){return test("[%i] [%i]", i_pos_1, i_pos_1);}
int bonus_length_i_follows_i_l(void){return test("[%i] [%li]", i_pos_1, l_pos_1);}
int bonus_length_i_follows_i_ll(void){return test("[%i] [%lli]", i_pos_1, ll_pos_1);}
int bonus_length_i_follows_i_h(void){return test("[%i] [%hi]", i_pos_1, sh_pos_1);}
int bonus_length_i_follows_i_hh(void){return test("[%i] [%hhi]", i_pos_1, ch_pos_1);}
int bonus_length_i_ll_hh_ll(void){return test("%lli%hhi%lli", ll_pos_1, ch_neg_1, ll_neg_1);}
int bonus_length_i_h_l_hh(void){return test("%hi%li%hhi", sh_pos_1, l_neg_1, ch_neg_1);}
int bonus_length_i_l_hh_h(void){return test("%li%hhi%hi", l_neg_1, ch_pos_1, sh_pos_1);}
int bonus_length_i_n_ll_hh(void){return test("%i%lli%hhi", i_pos_1, ll_neg_1, ch_pos_1);}
int bonus_length_i_ll_n_l(void){return test("%lli%i%li", ll_neg_1, i_pos_1, l_pos_1);}
//Signed integers - space of varying size modifiers
int bonus_length_i_hh_pos_casted_sp(void){return test("% hhi", (char)45);}
int bonus_length_i_hh_neg_casted_sp(void){return test("% hhi", (char)-45);}
int bonus_length_i_h_pos_casted_sp(void){return test("% hi", (short)385);}
int bonus_length_i_h_neg_casted_sp(void){return test("% hi", (short)-385);}
int bonus_length_i_l_pos_casted_sp(void){return test("% li", (long)32);}
int bonus_length_i_l_neg_casted_sp(void){return test("% li", (long)-32);}
int bonus_length_i_ll_pos_casted_sp(void){return test("% lli", (long long)43);}
int bonus_length_i_ll_neg_casted_sp(void){return test("% lli", (long long)-43);}
int bonus_length_i_hh_pos_ref_sp(void){return test("% hhi", ch_pos_1);}
int bonus_length_i_hh_neg_ref_sp(void){return test("% hhi", ch_neg_1);}
int bonus_length_i_h_pos_ref_sp(void){return test("% hi", sh_pos_1);}
int bonus_length_i_h_neg_ref_sp(void){return test("% hi", sh_neg_1);}
int bonus_length_i_l_pos_ref_sp(void){return test("% li", l_pos_1);}
int bonus_length_i_l_neg_ref_sp(void){return test("% li", l_neg_1);}
int bonus_length_i_ll_pos_ref_sp(void){return test("% lli", ll_pos_1);}
int bonus_length_i_ll_neg_ref_sp(void){return test("% lli", ll_neg_1);}
int bonus_length_i_l_pos_big_sp(void){return test("% li", 22337203685477l);}
int bonus_length_i_l_neg_big_sp(void){return test("% li", -22337203685477l);}
int bonus_length_i_ll_pos_big_sp(void){return test("% lli", 522337203685470ll);}
int bonus_length_i_ll_neg_big_sp(void){return test("% lli", -522337203685470ll);}
int bonus_length_i_llmax_sp(void){return test("% lli", 9223372036854775807ll);}
int bonus_length_i_llmin_sp(void){return test("% lli", llmin);}
int bonus_length_i_lmax_sp(void){return test("% li", 9223372036854775807l);}
int bonus_length_i_lmin_sp(void){return test("% li", lmin);}
int bonus_length_i_hmax_sp(void){return test("% hi", (short)32767);}
int bonus_length_i_hmin_sp(void){return test("% hi", (short)(-32768));}
int bonus_length_i_hhmax_sp(void){return test("% hhi", (char)(127));}
int bonus_length_i_hhmin_sp(void){return test("% hhi", (char)(-128));}
int bonus_length_i_l_pos_big_as(void){return test("%+li", 22337203685477l);}

//Unsigned integers of varying size modifiers
static unsigned char 		uch_pos_1 = 100;
static unsigned short		ush_pos_1 = 3047;
static unsigned int		ui_pos_1 = 878023;
static unsigned long		ul_pos_1 = 22337203685477;
static unsigned long long	ull_pos_1 = 22337203685477;
static unsigned long long  ullmax = 9223372036854775807;
static unsigned long  		ulmax = 9223372036854775807;
int bonus_length_u_hh_pos_casted(void){return test("%hhu", (unsigned char)45);}
int bonus_length_u_h_pos_casted(void){return test("%hu", (unsigned short)385);}
int bonus_length_u_l_pos_casted(void){return test("%lu", (unsigned long)32);}
int bonus_length_u_ll_pos_casted(void){return test("%llu", (unsigned long long)43);}
int bonus_length_u_hh_pos_ref(void){return test("%hhu", uch_pos_1);}
int bonus_length_u_h_pos_ref(void){return test("%hu", ush_pos_1);}
int bonus_length_u_l_pos_ref(void){return test("%lu", ul_pos_1);}
int bonus_length_u_ll_pos_ref(void){return test("%llu", ull_pos_1);}
int bonus_length_u_l_pos_big(void){return test("%lu", 22337203685477ul);}
int bonus_length_u_ll_pos_big(void){return test("%llu", 522337203685470ull);}
int bonus_length_u_ullmax(void){return test("%llu", ullmax);}
int bonus_length_u_ulmax(void){return test("%lu", ulmax);}
int bonus_length_u_uhmax(void){return test("%hu", (unsigned short)65535);}
int bonus_length_u_uhhmax(void){return test("%hhu", (unsigned char)255);}
//Unsigned integers of varying size modifiers with some other modifiers
int bonus_length_u_l_pos_big_zp(void){return test("%037lu", 22337203685477ul);}
int bonus_length_u_ll_pos_big_width(void){return test("%37llu", 522337203685470ull);}
//Multiple unsigned integers in a row of varying sizes
int bonus_length_u_ll_hh_ll(void){return test("%llu%hhu%llu", ull_pos_1, uch_pos_1, ull_pos_1);}
int bonus_length_u_h_l_hh(void){return test("%hu%lu%hhu", ush_pos_1, ul_pos_1, uch_pos_1);}
int bonus_length_u_l_hh_h(void){return test("%lu%hhu%hu", ul_pos_1, uch_pos_1, ush_pos_1);}
int bonus_length_u_n_ll_hh(void){return test("%u%llu%hhu", ui_pos_1, ull_pos_1, uch_pos_1);}
int bonus_length_u_ll_n_l(void){return test("%llu%u%lu", ull_pos_1, ui_pos_1, ul_pos_1);}

//Hexadecimal lowers of varying size modifiers
int bonus_length_x_hh_pos_casted(void){return test("%hhx", (unsigned char)45);}
int bonus_length_x_h_pos_casted(void){return test("%hx", (unsigned short)385);}
int bonus_length_x_l_pos_casted(void){return test("%lx", (unsigned long)32);}
int bonus_length_x_ll_pos_casted(void){return test("%llx", (long long)43);}
int bonus_length_x_hh_pos_ref(void){return test("%hhx", uch_pos_1);}
int bonus_length_x_h_pos_ref(void){return test("%hx", ush_pos_1);}
int bonus_length_x_l_pos_ref(void){return test("%lx", ul_pos_1);}
int bonus_length_x_ll_pos_ref(void){return test("%llx", ull_pos_1);}
int bonus_length_x_l_pos_big(void){return test("%lx", 22337203685477ul);}
int bonus_length_x_ll_pos_big(void){return test("%llx", 522337203685470ull);}
int bonus_length_x_ullmax(void){return test("%llx", ullmax);}
int bonus_length_x_ulmax(void){return test("%lx", ulmax);}
int bonus_length_x_uhmax(void){return test("%hx", (unsigned short)65535);}
int bonus_length_x_uhhmax(void){return test("%hhx", (unsigned char)255);}
//Hexadecimal lowers of varying size modifiers with some other modifiers
int bonus_length_x_l_pos_big_zp(void){return test("%037lx", 22337203685477ul);}
int bonus_length_x_ll_pos_big_width(void){return test("%37llx", 522337203685470ull);}
//Multiple Hexadecimal lowers in a row of varying sizes
int bonus_length_x_ll_hh_ll(void){return test("%llu%hhu%llx", ull_pos_1, uch_pos_1, ull_pos_1);}
int bonus_length_x_h_l_hh(void){return test("%hu%lu%hhx", ush_pos_1, ul_pos_1, uch_pos_1);}
int bonus_length_x_l_hh_h(void){return test("%lu%hhu%hx", ul_pos_1, uch_pos_1, ush_pos_1);}
int bonus_length_x_n_ll_hh(void){return test("%u%llu%hhx", ui_pos_1, ull_pos_1, uch_pos_1);}
int bonus_length_x_ll_n_l(void){return test("%llu%u%lx", ull_pos_1, ui_pos_1, ul_pos_1);}

//Hexadecimal lower (altform) of varying size modifiers
int bonus_length_x_hh_pos_casted_af(void){return test("%#hhx", (unsigned char)45);}
int bonus_length_x_h_pos_casted_af(void){return test("%#hx", (unsigned short)385);}
int bonus_length_x_l_pos_casted_af(void){return test("%#lx", (unsigned long)32);}
int bonus_length_x_ll_pos_casted_af(void){return test("%#llx", (long long)43);}
int bonus_length_x_hh_pos_ref_af(void){return test("%#hhx", uch_pos_1);}
int bonus_length_x_h_pos_ref_af(void){return test("%#hx", ush_pos_1);}
int bonus_length_x_l_pos_ref_af(void){return test("%#lx", ul_pos_1);}
int bonus_length_x_ll_pos_ref_af(void){return test("%#llx", ull_pos_1);}
int bonus_length_x_l_pos_big_af(void){return test("%#lx", 22337203685477lu);}
int bonus_length_x_ll_pos_big_af(void){return test("%#llx", 522337203685470llu);}
int bonus_length_x_ullmax_af(void){return test("%#llx", ullmax);}
int bonus_length_x_ulmax_af(void){return test("%#lx", ulmax);}
int bonus_length_x_uhmax_af(void){return test("%#hx", (unsigned short)65535);}
int bonus_length_x_uhhmax_af(void){return test("%#hhx", (unsigned char)255);}
//Hexadecimal lower (altform) of varying size modifiers with some other modifiers
int bonus_length_x_l_pos_big_zp_af(void){return test("%#037lx", 22337203685477ul);}
int bonus_length_x_ll_pos_big_width_af(void){return test("%#37llx", 522337203685470ull);}
//Multiple Hexadecimal lower (altform) in a row of varying sizes
int bonus_length_x_ll_hh_ll_af(void){return test("%llu%hhu%#llx", ull_pos_1, uch_pos_1, ull_pos_1);}
int bonus_length_x_h_l_hh_af(void){return test("%hu%#lx%hhx", ush_pos_1, ul_pos_1, uch_pos_1);}
int bonus_length_x_l_hh_h_af(void){return test("%lu%hhu%#hx", ul_pos_1, uch_pos_1, ush_pos_1);}
int bonus_length_x_n_ll_hh_af(void){return test("%#x%llu%hhx", ui_pos_1, ull_pos_1, uch_pos_1);}
int bonus_length_x_ll_n_l_af(void){return test("%llu%u%#lx", ull_pos_1, ui_pos_1, ul_pos_1);}

//Hexadecimal uppers of varying size modifiers
int bonus_length_X_hh_pos_casted(void){return test("%hhX", (unsigned char)45);}
int bonus_length_X_h_pos_casted(void){return test("%hX", (unsigned short)385);}
int bonus_length_X_l_pos_casted(void){return test("%lX", (unsigned long)32);}
int bonus_length_X_ll_pos_casted(void){return test("%llX", (long long)43);}
int bonus_length_X_hh_pos_ref(void){return test("%hhX", uch_pos_1);}
int bonus_length_X_h_pos_ref(void){return test("%hX", ush_pos_1);}
int bonus_length_X_l_pos_ref(void){return test("%lX", ul_pos_1);}
int bonus_length_X_ll_pos_ref(void){return test("%llX", ull_pos_1);}
int bonus_length_X_l_pos_big(void){return test("%lX", 22337203685477ul);}
int bonus_length_X_ll_pos_big(void){return test("%llX", 522337203685470ull);}
int bonus_length_X_ullmax(void){return test("%llX", ullmax);}
int bonus_length_X_ulmax(void){return test("%lX", ulmax);}
int bonus_length_X_uhmax(void){return test("%hX", (unsigned short)65535);}
int bonus_length_X_uhhmax(void){return test("%hhX", (unsigned char)255);}
//Hexadecimal uppers of varying size modifiers with some other modifiers
int bonus_length_X_l_pos_big_zp(void){return test("%037lX", 22337203685477ul);}
int bonus_length_X_ll_pos_big_width(void){return test("%37llX", 522337203685470ull);}
//Multiple Hexadecimal uppers in a row of varying sizes
int bonus_length_X_ll_hh_ll(void){return test("%llu%hhu%llX", ull_pos_1, uch_pos_1, ull_pos_1);}
int bonus_length_X_h_l_hh(void){return test("%hu%lu%hhX", ush_pos_1, ul_pos_1, uch_pos_1);}
int bonus_length_X_l_hh_h(void){return test("%lu%hhu%hX", ul_pos_1, uch_pos_1, ush_pos_1);}
int bonus_length_X_n_ll_hh(void){return test("%u%llu%hhX", ui_pos_1, ull_pos_1, uch_pos_1);}
int bonus_length_X_ll_n_l(void){return test("%llu%u%lX", ull_pos_1, ui_pos_1, ul_pos_1);}

//Hex uppers (altform) of varying size modifiers
int bonus_length_X_hh_pos_casted_af(void){return test("%#hhX", (unsigned char)45);}
int bonus_length_X_h_pos_casted_af(void){return test("%#hX", (unsigned short)385);}
int bonus_length_X_l_pos_casted_af(void){return test("%#lX", (unsigned long)32);}
int bonus_length_X_ll_pos_casted_af(void){return test("%#llX", (long long)43);}
int bonus_length_X_hh_pos_ref_af(void){return test("%#hhX", uch_pos_1);}
int bonus_length_X_h_pos_ref_af(void){return test("%#hX", ush_pos_1);}
int bonus_length_X_l_pos_ref_af(void){return test("%#lX", ul_pos_1);}
int bonus_length_X_ll_pos_ref_af(void){return test("%#llX", ull_pos_1);}
int bonus_length_X_l_pos_big_af(void){return test("%#lX", 22337203685477ul);}
int bonus_length_X_ll_pos_big_af(void){return test("%#llX", 522337203685470ull);}
int bonus_length_X_ullmax_af(void){return test("%#llX", ullmax);}
int bonus_length_X_ulmax_af(void){return test("%#lX", ulmax);}
int bonus_length_X_uhmax_af(void){return test("%#hX", (unsigned short)65535);}
int bonus_length_X_uhhmax_af(void){return test("%#hhX", (unsigned char)255);}
//Hex uppers (altform) of varying size modifiers with some other modifiers
int bonus_length_X_l_pos_big_zp_af(void){return test("%#037lX", 22337203685477ul);}
int bonus_length_X_ll_pos_big_width_af(void){return test("%#37llX", 522337203685470ull);}
//Multiple Hex uppers (altform) in a row of varying sizes
int bonus_length_X_ll_hh_ll_af(void){return test("%llu%hhu%#llX", ull_pos_1, uch_pos_1, ull_pos_1);}
int bonus_length_X_h_l_hh_af(void){return test("%#hx%lu%#hhX", ush_pos_1, ul_pos_1, uch_pos_1);}
int bonus_length_X_l_hh_h_af(void){return test("%lu%hhu%#hX", ul_pos_1, uch_pos_1, ush_pos_1);}
int bonus_length_X_n_ll_hh_af(void){return test("%#x%llu%#hhX", ui_pos_1, ull_pos_1, uch_pos_1);}
int bonus_length_X_ll_n_l_af(void){return test("%#llx%u%#lX", ull_pos_1, ui_pos_1, ul_pos_1);}

//No-crash-no-segfault test
int nocrash_notrequired_bonus_length_noarg_11(void){return test("%hh"); }
int nocrash_notrequired_bonus_length_noarg_12(void){return test("%h"); }
int nocrash_notrequired_bonus_length_noarg_13(void){return test("%ll"); }
int nocrash_notrequired_bonus_length_noarg_14(void){return test("%l"); }
int nocrash_notrequired_bonus_length_nullarg_11(void){return test("%hhs", NULL); }
int nocrash_notrequired_bonus_length_nullarg_12(void){return test("%hs", NULL); }
int nocrash_notrequired_bonus_length_nullarg_13(void){return test("%lls", NULL); }
int nocrash_notrequired_bonus_length_nullarg_14(void){return test("%ls", NULL); }
int nocrash_notrequired_bonus_length_c_hh(void){return test("%hhc", 'a');}
int nocrash_notrequired_bonus_length_c_h(void){return test("%hc", 'a');}
int nocrash_notrequired_bonus_length_c_l(void){return test("%lc", 'a');}
int nocrash_notrequired_bonus_length_c_ll(void){return test("%llc", 'a');}
int nocrash_notrequired_bonus_length_s_hh(void){return test("%hhs", "hello");}
int nocrash_notrequired_bonus_length_s_h(void){return test("%hs", "hello");}
int nocrash_notrequired_bonus_length_s_l(void){return test("%s", "hello");}
int nocrash_notrequired_bonus_length_s_ll(void){return test("%lls", "hello");}
int nocrash_notrequired_bonus_length_p_hh(void){return test("%hhp", &ncm_p);}
int nocrash_notrequired_bonus_length_p_h(void){return test("%hp", &ncm_p);}
int nocrash_notrequired_bonus_length_p_l(void){return test("%lp", &ncm_p);}
int nocrash_notrequired_bonus_length_p_ll(void){return test("%llp", &ncm_p);}
int nocrash_notrequired_bonus_length_d_hhh(void){return test("%hhhd", 42);}
int nocrash_notrequired_bonus_length_d_hhhh(void){return test("%hhhhd", 42);}
int nocrash_notrequired_bonus_length_d_hhl(void){return test("%hhld", 42);}
int nocrash_notrequired_bonus_length_d_hhll(void){return test("%hhlld", 42);}
int nocrash_notrequired_bonus_length_d_llh(void){return test("%llhd", 42);}
int nocrash_notrequired_bonus_length_d_lll(void){return test("%llld", 42);}
int nocrash_notrequired_bonus_length_i_hhh(void){return test("%hhhi", 42);}
int nocrash_notrequired_bonus_length_u_hhh(void){return test("%hhhu", 42);}
int nocrash_notrequired_bonus_length_u_hhhh(void){return test("%hhhhu", 42);}
int nocrash_notrequired_bonus_length_u_hhl(void){return test("%hhlu", 42);}
int nocrash_notrequired_bonus_length_u_hhll(void){return test("%hhllu", 42);}
int nocrash_notrequired_bonus_length_u_llh(void){return test("%llhu", 42);}
int nocrash_notrequired_bonus_length_u_lll(void){return test("%lllu", 42);}
int nocrash_notrequired_bonus_length_x_hhh(void){return test("%hhhx", 42);}
int nocrash_notrequired_bonus_length_x_hhhh(void){return test("%hhhhx", 42);}
int nocrash_notrequired_bonus_length_x_hhl(void){return test("%hhlx", 42);}
int nocrash_notrequired_bonus_length_x_hhll(void){return test("%hhllx", 42);}
int nocrash_notrequired_bonus_length_x_llh(void){return test("%llhx", 42);}
int nocrash_notrequired_bonus_length_x_lll(void){return test("%lllx", 42);}
int nocrash_notrequired_bonus_length_X_hhh(void){return test("%hhhX", 42);}
int nocrash_notrequired_bonus_length_X_llh(void){return test("%llhX", 42);}
int nocrash_notrequired_bonus_length_f_hh(void){return test("%hhf", 42.5);}
int nocrash_notrequired_bonus_length_f_h(void){return test("%hf", 42.5);}
int nocrash_notrequired_bonus_length_f_ll(void){return test("%llf", 42.5);}
int nocrash_notrequired_bonus_length_f_lll(void){return test("%lllf", 42.5);}
int nocrash_notrequired_bonus_length_f_llll(void){return test("%llllf", 42.5);}


/* -----------------------------------------------------------------------------	
** 						%n NOTHING PRINTED TESTS (BONUS)	
** ---------------------------------------------------------------------------*/	
// To do


/* -----------------------------------------------------------------------------
** 						%f FLOATS TESTS (BONUS)
** ---------------------------------------------------------------------------*/
//Floats - Basic
int bonus_f_basic_1(void){return test("this %f float", 1.5);}
int bonus_f_basic_fltonly(void){return test("%f", 7.5);}
int bonus_f_basic_zero(void){return test("%f", 0.0);}
int bonus_f_basic_nzero(void){return test("%f", -0.0);}
int bonus_f_basic_whole(void){return test("%f", 1.0);}
int bonus_f_basic_negative(void){return test("%f", -3.85);}
int bonus_f_basic_positive_3_3(void){return test("%f", 573.924);}
int bonus_f_basic_negative_3_3(void){return test("%f", -958.125);}
int bonus_f_basic_positive_smallfpart(void){return test("%f", 23.00041);}
int bonus_f_basic_positive_allsmall(void){return test("%f", 0.000039);}
int bonus_f_basic_negative_smallfpart(void){return test("%f", -7.00036);}
int bonus_f_basic_negative_allsmall(void){return test("%f", -0.00032);}
int bonus_f_basic_limits_allsmall_pos(void){return test("%f", 0.000001);}
int bonus_f_basic_limits_allsmall_neg(void){return test("%f", -0.000001);}
int bonus_f_basic_limits_smallfpart_pos(void){return test("%f", 9873.000001);}
int bonus_f_basic_limits_smallfpart_neg(void){return test("%f", -875.000001);}
int bonus_f_basic_limits_allbig_pos(void){return test("%f", 999.999999);}
int bonus_f_basic_limits_allbig_neg(void){return test("%f", -99.999999);}
int bonus_f_basic_limits_bigfpart_pos(void){return test("%f", 0.999999);}
int bonus_f_basic_limits_bigfpart_neg(void){return test("%f", -0.999999);}
//Floats - Rounding with default precision
int bonus_f_rndd_pos(void){return test("%f", 23.375094499);}
int bonus_f_rndd_neg(void){return test("%f", -985.765426499);}
int bonus_f_rndu_pos(void){return test("%f", 0.0894255);}
int bonus_f_rndu_neg(void){return test("%f", -56.2012685);}
int bonus_f_rndu_multidigit_pos(void){return test("%f", 43.4399999);}
int bonus_f_rndu_multidigit_neg(void){return test("%f", -5.0299999);}
int bonus_f_rndd_multidigit_pos(void){return test("%f", 43.43999949);}
int bonus_f_rndd_multidigit_neg(void){return test("%f", -5.02999949);}
int bonus_f_rndd_wholnobump_pos(void){return test("%f", 1.99999949);}
int bonus_f_rndd_wholnobump_neg(void){return test("%f", -0.99999949);}
int bonus_f_rndu_bumpwhole_pos(void){return test("%f", 3.9999999);}
int bonus_f_rndu_bumpwhole_neg(void){return test("%f", -5.9999999);}
//Floats Prec 0
int bonus_f_prec0_zero(void){return test("%.0f", 0.0);}
int bonus_f_prec0_nzero(void){return test("%.0f", -0.0);}
int bonus_f_prec0_1(void){return test("this %.0f float", 1.6);}
int bonus_f_prec0_fltonly(void){return test("%.0f", 7.4);}
int bonus_f_prec0_whole(void){return test("%.0f", 1.0);}
int bonus_f_prec0_negative(void){return test("%.0f", -3.85);}
int bonus_f_prec0_positive_3_3(void){return test("%.0f", 573.924);}
int bonus_f_prec0_negative_3_3(void){return test("%.0f", -958.125);}
int bonus_f_prec0_positive_smallfpart(void){return test("%.0f", 23.00041);}
int bonus_f_prec0_positive_allsmall(void){return test("%.0f", 0.000039);}
int bonus_f_prec0_negative_smallfpart(void){return test("%.0f", -7.00036);}
int bonus_f_prec0_negative_allsmall(void){return test("%.0f", -0.00032);}
//Floats Prec 1
int bonus_f_prec1_zero(void){return test("%.1f", 0.0);}
int bonus_f_prec1_nzero(void){return test("%.1f", -0.0);}
int bonus_f_prec1_1(void){return test("this %.1f float", 1.5);}
int bonus_f_prec1_fltonly(void){return test("%.1f", 7.5);}
int bonus_f_prec1_whole(void){return test("%.1f", 1.0);}
int bonus_f_prec1_negative(void){return test("%.1f", -3.85);}
int bonus_f_prec1_positive_3_3(void){return test("%.1f", 573.924);}
int bonus_f_prec1_negative_3_3(void){return test("%.1f", -958.125);}
int bonus_f_prec1_positive_smallfpart(void){return test("%.1f", 23.00041);}
int bonus_f_prec1_positive_allsmall(void){return test("%.1f", 0.000039);}
int bonus_f_prec1_negative_smallfpart(void){return test("%.1f", -7.00036);}
int bonus_f_prec1_negative_allsmall(void){return test("%.1f", -0.00032);}
//Floats Prec 3
int bonus_f_prec3_zero(void){return test("%.3f", 0.0);}
int bonus_f_prec3_nzero(void){return test("%.3f", -0.0);}
int bonus_f_prec3_1(void){return test("this %.3f float", 1.5);}
int bonus_f_prec3_fltonly(void){return test("%.3f", 7.5);}
int bonus_f_prec3_whole(void){return test("%.3f", 1.0);}
int bonus_f_prec3_negative(void){return test("%.3f", -3.85);}
int bonus_f_prec3_positive_3_3(void){return test("%.3f", 573.924);}
int bonus_f_prec3_negative_3_3(void){return test("%.3f", -958.125);}
int bonus_f_prec3_positive_smallfpart(void){return test("%.3f", 23.00041);}
int bonus_f_prec3_positive_allsmall(void){return test("%.3f", 0.000039);}
int bonus_f_prec3_negative_smallfpart(void){return test("%.3f", -7.00036);}
int bonus_f_prec3_negative_allsmall(void){return test("%.3f", -0.00032);}
//Floats - Prec 7
int bonus_f_prec7_zero(void){return test("%.7f", 0.0);}
int bonus_f_prec7_nzero(void){return test("%.7f", -0.0);}
int bonus_f_prec7_1(void){return test("this %.7f float", 1.5);}
int bonus_f_prec7_fltonly(void){return test("%.7f", 7.5);}
int bonus_f_prec7_whole(void){return test("%.7f", 1.0);}
int bonus_f_prec7_negative(void){return test("%.7f", -3.85);}
int bonus_f_prec7_positive_3_3(void){return test("%.7f", 573.924);}
int bonus_f_prec7_negative_3_3(void){return test("%.7f", -958.125);}
int bonus_f_prec7_positive_smallfpart(void){return test("%.7f", 23.00041);}
int bonus_f_prec7_positive_allsmall(void){return test("%.7f", 0.0000039);}
int bonus_f_prec7_negative_smallfpart(void){return test("%.7f", -7.00036);}
int bonus_f_prec7_negative_allsmall(void){return test("%.7f", -0.000032);}
int bonus_f_prec7_limits_allsmall_pos(void){return test("%.7f", 0.0000001);}
int bonus_f_prec7_limits_allsmall_neg(void){return test("%.7f", -0.0000001);}
int bonus_f_prec7_limits_smallfpart_pos(void){return test("%.7f", 9873.000001);}
int bonus_f_prec7_limits_smallfpart_neg(void){return test("%.7f", -875.000001);}
int bonus_f_prec7_limits_allbig_pos(void){return test("%.7f", 999.9999999);}
int bonus_f_prec7_limits_allbig_neg(void){return test("%.7f", -99.9999999);}
int bonus_f_prec7_limits_bigfpart_pos(void){return test("%.7f", 0.999999);}
int bonus_f_prec7_limits_bigfpart_neg(void){return test("%.7f", -0.999999);}
//Floats - Prec 7 Rounding
int bonus_f_rnd_prec7_rndd_pos(void){return test("%.7f", 23.375094499);}
int bonus_f_rnd_prec7_rndd_neg(void){return test("%.7f", -985.765426499);}
int bonus_f_rnd_prec7_rndu_pos(void){return test("%.7f", 0.0894255);}
int bonus_f_rnd_prec7_rndu_neg(void){return test("%.7f", -56.2012685);}
int bonus_f_rnd_prec7_rndu_multidigit_pos(void){return test("%.7f", 43.4399999);}
int bonus_f_rnd_prec7_rndu_multidigit_neg(void){return test("%.7f", -5.0299999);}
int bonus_f_rnd_prec7_rndd_multidigit_pos(void){return test("%.7f", 43.43999949);}
int bonus_f_rnd_prec7_rndd_multidigit_neg(void){return test("%.7f", -5.02999949);}
int bonus_f_rnd_prec7_rndd_wholnobump_pos(void){return test("%.7f", 1.99999949);}
int bonus_f_rnd_prec7_rndd_wholnobump_neg(void){return test("%.7f", -0.99999949);}
int bonus_f_rnd_prec7_rndu_bumpwhole_pos(void){return test("%.7f", 3.9999999);}
//Floats - Prec 8
int bonus_f_prec8_zero(void){return test("%.8f", 0.0);}
int bonus_f_prec8_nzero(void){return test("%.8f", -0.0);}
int bonus_f_prec8_1(void){return test("this %.8f float", 1.5);}
int bonus_f_prec8_fltonly(void){return test("%.8f", 7.5);}
int bonus_f_prec8_whole(void){return test("%.8f", 1.0);}
int bonus_f_prec8_negative(void){return test("%.8f", -3.85);}
int bonus_f_prec8_positive_3_3(void){return test("%.8f", 573.924);}
int bonus_f_prec8_negative_3_3(void){return test("%.8f", -958.125);}
int bonus_f_prec8_positive_smallfpart(void){return test("%.8f", 23.00041);}
int bonus_f_prec8_positive_allsmall(void){return test("%.8f", 0.00000039);}
int bonus_f_prec8_negative_smallfpart(void){return test("%.8f", -7.00036);}
int bonus_f_prec8_negative_allsmall(void){return test("%.8f", -0.0000032);}
int bonus_f_prec8_limits_allsmall_pos(void){return test("%.8f", 0.00000001);}
int bonus_f_prec8_limits_allsmall_neg(void){return test("%.8f", -0.00000001);}
int bonus_f_prec8_limits_smallfpart_pos(void){return test("%.8f", 9873.000001);}
int bonus_f_prec8_limits_smallfpart_neg(void){return test("%.8f", -875.000001);}
int bonus_f_prec8_limits_allbig_pos(void){return test("%.8f", 999.9999999);}
int bonus_f_prec8_limits_allbig_neg(void){return test("%.8f", -99.99999999);}
int bonus_f_prec8_limits_bigfpart_pos(void){return test("%.8f", 0.999999);}
int bonus_f_prec8_limits_bigfpart_neg(void){return test("%.8f", -0.999999);}
//Floats - Prec 8 Rounding
int bonus_f_rnd_prec8_rndd_pos(void){return test("%.8f", 23.375094499);}
int bonus_f_rnd_prec8_rndd_neg(void){return test("%.8f", -985.765426499);}
int bonus_f_rnd_prec8_rndu_pos(void){return test("%.8f", 0.0894255);}
int bonus_f_rnd_prec8_rndu_neg(void){return test("%.8f", -56.2012685);}
int bonus_f_rnd_prec8_rndu_multidigit_pos(void){return test("%.8f", 43.4399999);}
int bonus_f_rnd_prec8_rndu_multidigit_neg(void){return test("%.8f", -5.0299999);}
int bonus_f_rnd_prec8_rndd_multidigit_pos(void){return test("%.8f", 43.43999949);}
int bonus_f_rnd_prec8_rndd_multidigit_neg(void){return test("%.8f", -5.02999949);}
int bonus_f_rnd_prec8_rndd_wholnobump_pos(void){return test("%.8f", 1.99999949);}
int bonus_f_rnd_prec8_rndd_wholnobump_neg(void){return test("%.8f", -0.99999949);}
int bonus_f_rnd_prec8_rndu_bumpwhole_pos(void){return test("%.8f", 3.9999999);}
//Floats - Prec 9
int bonus_f_prec9_zero(void){return test("%.9f", 0.0);}
int bonus_f_prec9_nzero(void){return test("%.9f", -0.0);}
int bonus_f_stress_prec9_1(void){return test("this %.9f float", 1.5);}
int bonus_f_stress_prec9_fltonly(void){return test("%.9f", 7.5);}
int bonus_f_stress_prec9_whole(void){return test("%.9f", 1.0);}
int bonus_f_stress_prec9_negative(void){return test("%.9f", -3.85);}
int bonus_f_stress_prec9_positive_3_3(void){return test("%.9f", 573.924);}
int bonus_f_stress_prec9_negative_3_3(void){return test("%.9f", -958.125);}
int bonus_f_stress_prec9_positive_smallfpart(void){return test("%.9f", 23.00041);}
int bonus_f_stress_prec9_positive_allsmall(void){return test("%.9f", 0.00000039);}
int bonus_f_stress_prec9_negative_smallfpart(void){return test("%.9f", -7.00036);}
int bonus_f_stress_prec9_negative_allsmall(void){return test("%.9f", -0.0000032);}
int bonus_f_stress_prec9_limits_allsmall_pos(void){return test("%.9f", 0.00000001);}
int bonus_f_stress_prec9_limits_allsmall_neg(void){return test("%.9f", -0.00000001);}
int bonus_f_stress_prec9_limits_smallfpart_pos(void){return test("%.9f", 9873.000001);}
int bonus_f_stress_prec9_limits_smallfpart_neg(void){return test("%.9f", -875.000001);}
int bonus_f_stress_prec9_limits_allbig_pos(void){return test("%.9f", 999.99999999);}
int bonus_f_stress_prec9_limits_allbig_neg(void){return test("%.9f", -99.99999999);}
int bonus_f_stress_prec9_limits_bigfpart_pos(void){return test("%.9f", 0.999999);}
int bonus_f_stress_prec9_limits_bigfpart_neg(void){return test("%.9f", -0.999999);}
//Floats - Prec 9 Rounding
int bonus_f_stress_prec9_rndd_pos(void){return test("%.9f", 23.375094499);}
int bonus_f_stress_prec9_rndd_neg(void){return test("%.9f", -985.765426499);}
int bonus_f_stress_prec9_rndu_pos(void){return test("%.9f", 0.0894255);}
int bonus_f_stress_prec9_rndu_neg(void){return test("%.9f", -56.2012685);}
int bonus_f_stress_prec9_rndu_multidigit_pos(void){return test("%.9f", 43.4399999);}
int bonus_f_stress_prec9_rndu_multidigit_neg(void){return test("%.9f", -5.0299999);}
int bonus_f_stress_prec9_rndd_multidigit_pos(void){return test("%.9f", 43.43999949);}
int bonus_f_stress_prec9_rndd_multidigit_neg(void){return test("%.9f", -5.02999949);}
int bonus_f_stress_prec9_rndd_wholnobump_pos(void){return test("%.9f", 1.99999949);}
int bonus_f_stress_prec9_rndd_wholnobump_neg(void){return test("%.9f", -0.99999949);}
int bonus_f_stress_prec9_rndu_bumpwhole_pos(void){return test("%.9f", 3.9999999);}
//Floats - Prec 10
int bonus_f_prec10_zero(void){return test("%.10f", 0.0);}
int bonus_f_prec10_nzero(void){return test("%.10f", -0.0);}
int bonus_f_stress_prec10_1(void){return test("this %.10f float", 1.5);}
int bonus_f_stress_prec10_fltonly(void){return test("%.10f", 7.5);}
int bonus_f_stress_prec10_whole(void){return test("%.10f", 1.0);}
int bonus_f_stress_prec10_negative(void){return test("%.10f", -3.85);}
int bonus_f_stress_prec10_positive_3_10(void){return test("%.10f", 573.924);}
int bonus_f_stress_prec10_negative_3_10(void){return test("%.10f", -958.125);}
int bonus_f_stress_prec10_pos(void){return test("%.10f", 23.8341375094);}
int bonus_f_stress_prec10_neg(void){return test("%.10f", -985.2459765426);}
int bonus_f_stress_prec10_rndd_pos(void){return test("%.10f", 23.8341375094499);}
int bonus_f_stress_prec10_rndd_neg(void){return test("%.10f", -985.2459765426499);}
int bonus_f_stress_prec10_rndu_pos(void){return test("%.10f", 0.87650894255);}
int bonus_f_stress_prec10_rndu_neg(void){return test("%.10f", -56.47852012685);}
int bonus_f_stress_prec10_positive_smallfpart(void){return test("%.10f", 23.000000041);}
int bonus_f_stress_prec10_positive_allsmall(void){return test("%.10f", 0.0000000039);}
int bonus_f_stress_prec10_negative_smallfpart(void){return test("%.10f", -7.000000036);}
int bonus_f_stress_prec10_negative_allsmall(void){return test("%.10f", -0.000000032);}
int bonus_f_stress_prec10_limits_allsmall_pos(void){return test("%.10f", 0.0000000001);}
int bonus_f_stress_prec10_limits_allsmall_neg(void){return test("%.10f", -0.0000000001);}
int bonus_f_stress_prec10_limits_smallfpart_pos(void){return test("%.10f", 9873.0000000001);}
int bonus_f_stress_prec10_limits_smallfpart_neg(void){return test("%.10f", -875.0000000001);}
int bonus_f_stress_prec10_limits_allbig_pos(void){return test("%.10f", 999.9999999999);}
int bonus_f_stress_prec10_limits_allbig_neg(void){return test("%.10f", -99.9999999999);}
int bonus_f_stress_prec10_limits_bigfpart_pos(void){return test("%.10f", 0.9999999999);}
int bonus_f_stress_prec10_limits_bigfpart_neg(void){return test("%.10f", -0.9999999999);}
//Floats - Prec 11
int bonus_f_stress_prec11_rndu(void){return test("%.11f",        1.025978541236587568);}
int bonus_f_stress_prec11_rndd(void){return test("%.11f",        1.025978548534310421);}
int bonus_f_stress_prec11_limits_tiny(void){return test("%.11f", 0.000000000010000000);}
int bonus_f_stress_prec11_limits_big(void){return test("%.11f", 99.999999999990000000);}
//Floats - Prec 12
int bonus_f_stress_prec12_rndu(void){return test("%.12f",        1.025978541236587568);}
int bonus_f_stress_prec12_rndd(void){return test("%.12f",        1.025978548534310421);}
int bonus_f_stress_prec12_limits_tiny(void){return test("%.12f", 0.000000000001000000);}
int bonus_f_stress_prec12_limits_big(void){return test("%.12f", 99.999999999999000000);}
//Floats - Prec 13
int bonus_f_stress_prec13_rndu(void){return test("%.13f",        1.025978541136587568);}
int bonus_f_stress_prec13_rndd(void){return test("%.13f",        1.025978548534310421);}
int bonus_f_stress_prec13_limits_tiny(void){return test("%.13f", 0.000000000000100000);}
int bonus_f_stress_prec13_limits_big(void){return test("%.13f", 99.999999999999900000);}
//Floats - Prec 14
int bonus_f_stress_prec14_rndu(void){return test("%.14f",        1.025978541436587568);}
int bonus_f_stress_prec14_rndd(void){return test("%.14f",        1.025978548534310421);}
int bonus_f_stress_prec14_limits_tiny(void){return test("%.14f", 0.000000000000010000);}
int bonus_f_stress_prec14_limits_big(void){return test("%.14f",  9.999999999999990000);}
//Floats - Prec 15
int bonus_f_stress_prec15_rndu(void){return test("%.15f",        1.025978542436587568);}
int bonus_f_stress_prec15_rndd(void){return test("%.15f",        1.025978548534310421);}
int bonus_f_stress_prec15_limits_tiny(void){return test("%.15f", 0.000000000000001000);}
int bonus_f_stress_prec15_limits_big(void){return test("%.15f",  0.999999999999999000);}
//Floats - Prec 16
int bonus_notrequired_f_stress_prec16_rndu(void){return test("%.16f",        1.025978542436587568);}
int bonus_notrequired_f_stress_prec16_rndd(void){return test("%.16f",        1.025978548534310421);}
int bonus_notrequired_f_stress_prec16_limits_tiny(void){return test("%.16f", 0.000000000000000100);}
int bonus_notrequired_f_stress_prec16_limits_big(void){return test("%.16f",  0.999999999999999900);}
//Floats - Prec 17
int bonus_notrequired_f_stress_prec17_rndu(void){return test("%.17f",        1.025978542436587568);}
int bonus_notrequired_f_stress_prec17_rndd(void){return test("%.17f",        1.025978548534310421);}
int bonus_notrequired_f_stress_prec17_limits_tiny(void){return test("%.17f", 0.000000000000000010);}
int bonus_notrequired_f_stress_prec17_limits_big(void){return test("%.17f",  0.999999999999999990);}
//Floats - Prec 18
int bonus_notrequired_f_stress_prec18_rndu(void){return test("%.18f",        0.125978542436587568);}
int bonus_notrequired_f_stress_prec18_rndd(void){return test("%.18f",        0.125978548534310421);}
//Floats with altform,~
int bonus_f_af_prec0_zero(void){return test("%#.0f", 0.0);}
int bonus_f_af_prec0_nzero(void){return test("%#.0f", -0.0);}
int bonus_f_af_prec1_zero(void){return test("%#.1f", 0.0);}
int bonus_f_af_prec1_nzero(void){return test("%#.1f", -0.0);}
int bonus_f_af_prec0p(void){return test("%#.0f", 7.4);}
int bonus_f_af_prec1p(void){return test("%#.1f", 7.3);}
int bonus_f_af_prec0n(void){return test("%#.0f", -7.4);}
int bonus_f_af_prec1n(void){return test("%#.1f", -7.3);}
//Floats with allsign,~
int bonus_f_as_prec0_zero(void){return test("%+.0f", 0.0);}
int bonus_f_as_prec0_nzero(void){return test("%+.0f", -0.0);}
int bonus_f_as_prec3_zero(void){return test("%+.3f", 0.0);}
int bonus_f_as_prec3_nzero(void){return test("%+.3f", -0.0);}
int bonus_f_as_prec0p_as(void){return test("%+.0f", 7.4);}
int bonus_f_as_prec3p_as(void){return test("%+.3f", 7.3);}
int bonus_f_as_prec0n_as(void){return test("%+.0f", -7.4);}
int bonus_f_as_prec3n_as(void){return test("%+.3f", -7.3);}
//Floats with field width,~
int bonus_f_wprec0p_zero(void){return test("%5.0f", 0.0);}
int bonus_f_wprec0p_nzero(void){return test("%5.0f", -0.0);}
int bonus_f_wprec3p_zero(void){return test("%5.3f", 0.0);}
int bonus_f_wprec3p_nzero(void){return test("%5.3f", -0.0);}
int bonus_f_wprec0p(void){return test("%5.0f", 7.3);}
int bonus_f_wprec1p(void){return test("%5.1f", 7.3);}
int bonus_f_wprec3p(void){return test("%5.3f", 7.3);}
int bonus_f_wprec6p(void){return test("%5.6f", 7.3);}
int bonus_f_wprec0n(void){return test("%5.0f", -7.3);}
int bonus_f_wprec1n(void){return test("%5.1f", -7.3);}
int bonus_f_wprec3n(void){return test("%5.3f", -7.3);}
int bonus_f_wprec6n(void){return test("%5.6f", -7.3);}
//Floats with field width and zero padding,~
int bonus_f_wzp_prec0p_zero(void){return test("%05.0f", 0.0);}
int bonus_f_wzp_prec0p_nzero(void){return test("%05.0f", -0.0);}
int bonus_f_wzp_prec3p_zero(void){return test("%05.3f", 0.0);}
int bonus_f_wzp_prec3p_nzero(void){return test("%05.3f", -0.0);}
int bonus_f_wzp_prec0p(void){return test("%05.0f", 7.3);}
int bonus_f_wzp_prec1p(void){return test("%05.1f", 7.3);}
int bonus_f_wzp_prec3p(void){return test("%05.3f", 7.3);}
int bonus_f_wzp_prec6p(void){return test("%05.6f", 7.3);}
int bonus_f_wzp_prec0n(void){return test("%05.0f", -7.3);}
int bonus_f_wzp_prec1n(void){return test("%05.1f", -7.3);}
int bonus_f_wzp_prec3n(void){return test("%05.3f", -7.3);}
int bonus_f_wzp_prec6n(void){return test("%05.6f", -7.3);}
//Floats with field width and left justify,~
int bonus_f_wlj_prec0p_zero(void){return test("%-5.0f", 0.0);}
int bonus_f_wlj_prec0p_nzero(void){return test("%-5.0f", -0.0);}
int bonus_f_wlj_prec3p_zero(void){return test("%-5.3f", 0.0);}
int bonus_f_wlj_prec3p_nzero(void){return test("%-5.3f", -0.0);}
int bonus_f_wlj_prec0p(void){return test("%-5.0f", 7.3);}
int bonus_f_wlj_prec1p(void){return test("%-5.1f", 7.3);}
int bonus_f_wlj_prec3p(void){return test("%-5.3f", 7.3);}
int bonus_f_wlj_prec6p(void){return test("%-5.6f", 7.3);}
int bonus_f_wlj_prec0n(void){return test("%-5.0f", -7.3);}
int bonus_f_wlj_prec1n(void){return test("%-5.1f", -7.3);}
int bonus_f_wlj_prec3n(void){return test("%-5.3f", -7.3);}
int bonus_f_wlj_prec6n(void){return test("%-5.6f", -7.3);}
//Floats with field width and zero padding and left justify,~
int bonus_f_wzplj_prec0p_ignoreflag_zero(void){return test("%-05.0f", 0.0);}
int bonus_f_wzplj_prec0p_ignoreflag_nzero(void){return test("%-05.0f", -0.0);}
int bonus_f_wzplj_prec3p_ignoreflag_zero(void){return test("%-05.3f", 0.0);}
int bonus_f_wzplj_prec3p_ignoreflag_nzero(void){return test("%-05.3f", -0.0);}
int bonus_f_wzplj_prec0p_ignoreflag(void){return test("%-05.0f", 7.3);}
int bonus_f_wzplj_prec1p_ignoreflag(void){return test("%-05.1f", 7.3);}
int bonus_f_wzplj_prec3p_ignoreflag(void){return test("%-05.3f", 7.3);}
int bonus_f_wzplj_prec6p_ignoreflag(void){return test("%-05.6f", 7.3);}
int bonus_f_wzplj_prec0n_ignoreflag(void){return test("%-05.0f", -7.3);}
int bonus_f_wzplj_prec1n_ignoreflag(void){return test("%-05.1f", -7.3);}
int bonus_f_wzplj_prec3n_ignoreflag(void){return test("%-05.3f", -7.3);}
int bonus_f_wzplj_prec6n_ignoreflag(void){return test("%-05.6f", -7.3);}
//Floats with field width and zero padding and left justify, rev f order,~
int bonus_f_wzpljr_prec0p_ignoreflag_zero(void){return test("%0-5.0f", 0.0);}
int bonus_f_wzpljr_prec0p_ignoreflag_nzero(void){return test("%0-5.0f", -0.0);}
int bonus_f_wzpljr_prec3p_ignoreflag_zero(void){return test("%0-5.3f", 0.0);}
int bonus_f_wzpljr_prec3p_ignoreflag_nzero(void){return test("%0-5.3f", -0.0);}
int bonus_f_wzpljr_prec0p_ignoreflag(void){return test("%0-5.0f", 7.3);}
int bonus_f_wzpljr_prec1p_ignoreflag(void){return test("%0-5.1f", 7.3);}
int bonus_f_wzpljr_prec3p_ignoreflag(void){return test("%0-5.3f", 7.3);}
int bonus_f_wzpljr_prec6p_ignoreflag(void){return test("%0-5.6f", 7.3);}
int bonus_f_wzpljr_prec0n_ignoreflag(void){return test("%0-5.0f", -7.3);}
int bonus_f_wzpljr_prec1n_ignoreflag(void){return test("%0-5.1f", -7.3);}
int bonus_f_wzpljr_prec3n_ignoreflag(void){return test("%0-5.3f", -7.3);}
int bonus_f_wzpljr_prec6n_ignoreflag(void){return test("%0-5.6f", -7.3);}
//Floats with field width and left justify and altform,~
int bonus_f_wzpljaf_prec0p_zero(void){return test("%#-5.0f", 0.0);}
int bonus_f_wzpljaf_prec0p_nzero(void){return test("%#-5.0f", -0.0);}
int bonus_f_wzpljaf_prec3p_zero(void){return test("%#-5.3f", 0.0);}
int bonus_f_wzpljaf_prec3p_nzero(void){return test("%#-5.3f", -0.0);}
int bonus_f_wzpljaf_prec0p(void){return test("%#-5.0f", 7.3);}
int bonus_f_wzpljaf_prec1p(void){return test("%#-5.1f", 7.3);}
int bonus_f_wzpljaf_prec3p(void){return test("%#-5.3f", 7.3);}
int bonus_f_wzpljaf_prec6p(void){return test("%#-5.6f", 7.3);}
int bonus_f_wzpljaf_prec0n(void){return test("%#-5.0f", -7.3);}
int bonus_f_wzpljaf_prec1n(void){return test("%#-5.1f", -7.3);}
int bonus_f_wzpljaf_prec3n(void){return test("%#-5.3f", -7.3);}
int bonus_f_wzpljaf_prec6n(void){return test("%#-5.6f", -7.3);}
//Floats with field width and allsign,~
int bonus_f_was_prec0p_zero(void){return test("%+5.0f", 0.0);}
int bonus_f_was_prec0p_nzero(void){return test("%+5.0f", -0.0);}
int bonus_f_was_prec3p_zero(void){return test("%+5.3f", 0.0);}
int bonus_f_was_prec3p_nzero(void){return test("%+5.3f", -0.0);}
int bonus_f_was_prec0p(void){return test("%+5.0f", 7.3);}
int bonus_f_was_prec1p(void){return test("%+5.1f", 7.3);}
int bonus_f_was_prec3p(void){return test("%+5.3f", 7.3);}
int bonus_f_was_prec6p(void){return test("%+5.6f", 7.3);}
int bonus_f_was_prec0n(void){return test("%+5.0f", -7.3);}
int bonus_f_was_prec1n(void){return test("%+5.1f", -7.3);}
int bonus_f_was_prec3n(void){return test("%+5.3f", -7.3);}
int bonus_f_was_prec6n(void){return test("%+5.6f", -7.3);}
//Floats with field width and zero padding and allsign,~
int bonus_f_wzpas_prec0p_zero(void){return test("%+05.0f", 0.0);}
int bonus_f_wzpas_prec0p_nzero(void){return test("%+05.0f", -0.0);}
int bonus_f_wzpas_prec3p_zero(void){return test("%+05.3f", 0.0);}
int bonus_f_wzpas_prec3p_nzero(void){return test("%+05.3f", -0.0);}
int bonus_f_wzpas_prec0p(void){return test("%+05.0f", 7.3);}
int bonus_f_wzpas_prec1p(void){return test("%+05.1f", 7.3);}
int bonus_f_wzpas_prec3p(void){return test("%+05.3f", 7.3);}
int bonus_f_wzpas_prec6p(void){return test("%+05.6f", 7.3);}
int bonus_f_wzpas_prec0n(void){return test("%+05.0f", -7.3);}
int bonus_f_wzpas_prec1n(void){return test("%+05.1f", -7.3);}
int bonus_f_wzpas_prec3n(void){return test("%+05.3f", -7.3);}
int bonus_f_wzpas_prec6n(void){return test("%+05.6f", -7.3);}
//Floats with field width and left justify and allsign,~
int bonus_f_wljas_prec0p_zero(void){return test("%+-5.0f", 0.0);}
int bonus_f_wljas_prec0p_nzero(void){return test("%+-5.0f", -0.0);}
int bonus_f_wljas_prec3p_zero(void){return test("%+-5.3f", 0.0);}
int bonus_f_wljas_prec3p_nzero(void){return test("%+-5.3f", -0.0);}
int bonus_f_wljas_prec0p(void){return test("%+-5.0f", 7.3);}
int bonus_f_wljas_prec1p(void){return test("%+-5.1f", 7.3);}
int bonus_f_wljas_prec3p(void){return test("%+-5.3f", 7.3);}
int bonus_f_wljas_prec6p(void){return test("%+-5.6f", 7.3);}
int bonus_f_wljas_prec0n(void){return test("%+-5.0f", -7.3);}
int bonus_f_wljas_prec1n(void){return test("%+-5.1f", -7.3);}
int bonus_f_wljas_prec3n(void){return test("%+-5.3f", -7.3);}
int bonus_f_wljas_prec6n(void){return test("%+-5.6f", -7.3);}
//Floats with field width and zero padding and left justify and allsign,~
int bonus_f_wzpljas_prec0p_ignoreflag_zero(void){return test("%+-05.0f", 0.0);}
int bonus_f_wzpljas_prec0p_ignoreflag_nzero(void){return test("%+-05.0f", -0.0);}
int bonus_f_wzpljas_prec3p_ignoreflag_zero(void){return test("%+-05.3f", 0.0);}
int bonus_f_wzpljas_prec3p_ignoreflag_nzero(void){return test("%+-05.3f", -0.0);}
int bonus_f_wzpljas_prec0p_ignoreflag(void){return test("%+-05.0f", 7.3);}
int bonus_f_wzpljas_prec1p_ignoreflag(void){return test("%+-05.1f", 7.3);}
int bonus_f_wzpljas_prec3p_ignoreflag(void){return test("%+-05.3f", 7.3);}
int bonus_f_wzpljas_prec6p_ignoreflag(void){return test("%+-05.6f", 7.3);}
int bonus_f_wzpljas_prec0n_ignoreflag(void){return test("%+-05.0f", -7.3);}
int bonus_f_wzpljas_prec1n_ignoreflag(void){return test("%+-05.1f", -7.3);}
int bonus_f_wzpljas_prec3n_ignoreflag(void){return test("%+-05.3f", -7.3);}
int bonus_f_wzpljas_prec6n_ignoreflag(void){return test("%+-05.6f", -7.3);}
//Floats with field width left justify, rev f order and allsign,~
int bonus_f_wzpljras_prec0p_zero(void){return test("%+-05.0f", 0.0);}
int bonus_f_wzpljras_prec0p_nzero(void){return test("%+-05.0f", -0.0);}
int bonus_f_wzpljras_prec3p_zero(void){return test("%+-05.3f", 0.0);}
int bonus_f_wzpljras_prec3p_nzero(void){return test("%+-05.3f", -0.0);}
int bonus_f_wzpljras_prec0p(void){return test("%-+5.0f", 7.3);}
int bonus_f_wzpljras_prec1p(void){return test("%-+5.1f", 7.3);}
int bonus_f_wzpljras_prec3p(void){return test("%-+5.3f", 7.3);}
int bonus_f_wzpljras_prec6p(void){return test("%-+5.6f", 7.3);}
int bonus_f_wzpljras_prec0n(void){return test("%-+5.0f", -7.3);}
int bonus_f_wzpljras_prec1n(void){return test("%-+5.1f", -7.3);}
int bonus_f_wzpljras_prec3n(void){return test("%-+5.3f", -7.3);}
int bonus_f_wzpljras_prec6n(void){return test("%-+5.6f", -7.3);}
//Floats with field width and left justify and altform and allsign,~
int bonus_f_wzpljafas_prec0p_zero(void){return test("%+#-05.0f", 0.0);}
int bonus_f_wzpljafas_prec0p_nzero(void){return test("%+#-05.0f", -0.0);}
int bonus_f_wzpljafas_prec3p_zero(void){return test("%+#-05.3f", 0.0);}
int bonus_f_wzpljafas_prec3p_nzero(void){return test("%+#-05.3f", -0.0);}
int bonus_f_wzpljafas_prec0p(void){return test("%+#-5.0f", 7.3);}
int bonus_f_wzpljafas_prec1p(void){return test("%+#-5.1f", 7.3);}
int bonus_f_wzpljafas_prec3p(void){return test("%+#-5.3f", 7.3);}
int bonus_f_wzpljafas_prec6p(void){return test("%+#-5.6f", 7.3);}
int bonus_f_wzpljafas_prec0n(void){return test("%+#-5.0f", -7.3);}
int bonus_f_wzpljafas_prec1n(void){return test("%+#-5.1f", -7.3);}
int bonus_f_wzpljafas_prec3n(void){return test("%+#-5.3f", -7.3);}
int bonus_f_wzpljafas_prec6n(void){return test("%+#-5.6f", -7.3);}
//Floats with field width and sp,~
int bonus_f_wsp_prec0p_zero(void){return test("% 5.0f", 0.0);}
int bonus_f_wsp_prec0p_nzero(void){return test("% 5.0f", -0.0);}
int bonus_f_wsp_prec3p_zero(void){return test("% 5.3f", 0.0);}
int bonus_f_wsp_prec3p_nzero(void){return test("% 5.3f", -0.0);}
int bonus_f_wsp_prec0p(void){return test("% 5.0f", 7.3);}
int bonus_f_wsp_prec1p(void){return test("% 5.1f", 7.3);}
int bonus_f_wsp_prec3p(void){return test("% 5.3f", 7.3);}
int bonus_f_wsp_prec6p(void){return test("% 5.6f", 7.3);}
int bonus_f_wsp_prec0n(void){return test("% 5.0f", -7.3);}
int bonus_f_wsp_prec1n(void){return test("% 5.1f", -7.3);}
int bonus_f_wsp_prec3n(void){return test("% 5.3f", -7.3);}
int bonus_f_wsp_prec6n(void){return test("% 5.6f", -7.3);}
//Floats with field width and zero padding and sp,~
int bonus_f_wzpsp_prec0p_zero(void){return test("% 05.0f", 0.0);}
int bonus_f_wzpsp_prec0p_nzero(void){return test("% 05.0f", -0.0);}
int bonus_f_wzpsp_prec3p_zero(void){return test("% 05.3f", 0.0);}
int bonus_f_wzpsp_prec3p_nzero(void){return test("% 05.3f", -0.0);}
int bonus_f_wzpsp_prec0p(void){return test("% 05.0f", 7.3);}
int bonus_f_wzpsp_prec1p(void){return test("% 05.1f", 7.3);}
int bonus_f_wzpsp_prec3p(void){return test("% 05.3f", 7.3);}
int bonus_f_wzpsp_prec6p(void){return test("% 05.6f", 7.3);}
int bonus_f_wzpsp_prec0n(void){return test("% 05.0f", -7.3);}
int bonus_f_wzpsp_prec1n(void){return test("% 05.1f", -7.3);}
int bonus_f_wzpsp_prec3n(void){return test("% 05.3f", -7.3);}
int bonus_f_wzpsp_prec6n(void){return test("% 05.6f", -7.3);}
//Floats with field width and left justify and sp,~
int bonus_f_wljsp_prec0p_zero(void){return test("% -5.0f", 0.0);}
int bonus_f_wljsp_prec0p_nzero(void){return test("% -5.0f", -0.0);}
int bonus_f_wljsp_prec3p_zero(void){return test("% -5.3f", 0.0);}
int bonus_f_wljsp_prec3p_nzero(void){return test("% -5.3f", -0.0);}
int bonus_f_wljsp_prec0p(void){return test("% -5.0f", 7.3);}
int bonus_f_wljsp_prec1p(void){return test("% -5.1f", 7.3);}
int bonus_f_wljsp_prec3p(void){return test("% -5.3f", 7.3);}
int bonus_f_wljsp_prec6p(void){return test("% -5.6f", 7.3);}
int bonus_f_wljsp_prec0n(void){return test("% -5.0f", -7.3);}
int bonus_f_wljsp_prec1n(void){return test("% -5.1f", -7.3);}
int bonus_f_wljsp_prec3n(void){return test("% -5.3f", -7.3);}
int bonus_f_wljsp_prec6n(void){return test("% -5.6f", -7.3);}
//Floats with field width and zero padding and left justify and sp,~
int bonus_f_wzpljsp_prec0p_zero(void){return test("% -05.0f", 0.0);}
int bonus_f_wzpljsp_prec0p_nzero(void){return test("% -05.0f", -0.0);}
int bonus_f_wzpljsp_prec3p_zero(void){return test("% -05.3f", 0.0);}
int bonus_f_wzpljsp_prec3p_nzero(void){return test("% -05.3f", -0.0);}
int bonus_f_wzpljsp_prec0p_ignoreflag(void){return test("% -05.0f", 7.3);}
int bonus_f_wzpljsp_prec1p_ignoreflag(void){return test("% -05.1f", 7.3);}
int bonus_f_wzpljsp_prec3p_ignoreflag(void){return test("% -05.3f", 7.3);}
int bonus_f_wzpljsp_prec6p_ignoreflag(void){return test("% -05.6f", 7.3);}
int bonus_f_wzpljsp_prec0n_ignoreflag(void){return test("% -05.0f", -7.3);}
int bonus_f_wzpljsp_prec1n_ignoreflag(void){return test("% -05.1f", -7.3);}
int bonus_f_wzpljsp_prec3n_ignoreflag(void){return test("% -05.3f", -7.3);}
int bonus_f_wzpljsp_prec6n_ignoreflag(void){return test("% -05.6f", -7.3);}
//Floats with field width left justify, rev f order and sp,~
int bonus_f_wzpljrsp_prec0p_zero(void){return test("%- 5.0f", 0.0);}
int bonus_f_wzpljrsp_prec0p_nzero(void){return test("%- 5.0f", -0.0);}
int bonus_f_wzpljrsp_prec3p_zero(void){return test("%- 5.3f", 0.0);}
int bonus_f_wzpljrsp_prec3p_nzero(void){return test("%- 5.3f", -0.0);}
int bonus_f_wzpljrsp_prec0p(void){return test("%- 5.0f", 7.3);}
int bonus_f_wzpljrsp_prec1p(void){return test("%- 5.1f", 7.3);}
int bonus_f_wzpljrsp_prec3p(void){return test("%- 5.3f", 7.3);}
int bonus_f_wzpljrsp_prec6p(void){return test("%- 5.6f", 7.3);}
int bonus_f_wzpljrsp_prec0n(void){return test("%- 5.0f", -7.3);}
int bonus_f_wzpljrsp_prec1n(void){return test("%- 5.1f", -7.3);}
int bonus_f_wzpljrsp_prec3n(void){return test("%- 5.3f", -7.3);}
int bonus_f_wzpljrsp_prec6n(void){return test("%- 5.6f", -7.3);}
//Floats with field width and left justify and altform and sp,~
int bonus_f_wzpljafsp_prec0p_zero(void){return test("% #-05.0f", 0.0);}
int bonus_f_wzpljafsp_prec0p_nzero(void){return test("% #-05.0f", -0.0);}
int bonus_f_wzpljafsp_prec3p_zero(void){return test("% #-05.3f", 0.0);}
int bonus_f_wzpljafsp_prec3p_nzero(void){return test("% #-05.3f", -0.0);}
int bonus_f_wzpljafsp_prec0p(void){return test("% #-5.0f", 7.3);}
int bonus_f_wzpljafsp_prec1p(void){return test("% #-5.1f", 7.3);}
int bonus_f_wzpljafsp_prec3p(void){return test("% #-5.3f", 7.3);}
int bonus_f_wzpljafsp_prec6p(void){return test("% #-5.6f", 7.3);}
int bonus_f_wzpljafsp_prec0n(void){return test("% #-5.0f", -7.3);}
int bonus_f_wzpljafsp_prec1n(void){return test("% #-5.1f", -7.3);}
int bonus_f_wzpljafsp_prec3n(void){return test("% #-5.3f", -7.3);}
int bonus_f_wzpljafsp_prec6n(void){return test("% #-5.6f", -7.3);}
//Floats with allsign and sp,~
int bonus_f_assp_prec0p_ignoreflag(void){return test("%+ .0f", 7.3);}
int bonus_f_assp_prec1p_ignoreflag(void){return test("%+ .1f", 7.3);}
int bonus_f_assp_prec3p_ignoreflag(void){return test("%+ .3f", 7.3);}
int bonus_f_assp_prec6p_ignoreflag(void){return test("%+ .6f", 7.3);}
int bonus_f_assp_prec0n_ignoreflag(void){return test("%+ .0f", -7.3);}
int bonus_f_assp_prec1n_ignoreflag(void){return test("%+ .1f", -7.3);}
int bonus_f_assp_prec3n_ignoreflag(void){return test("%+ .3f", -7.3);}
int bonus_f_assp_prec6n_ignoreflag(void){return test("%+ .6f", -7.3);}
//Floats with allsign and sp and rev flag order,~
int bonus_f_asspr_prec0p_ignoreflag(void){return test("% +.0f", 7.3);}
int bonus_f_asspr_prec1p_ignoreflag(void){return test("% +.1f", 7.3);}
int bonus_f_asspr_prec3p_ignoreflag(void){return test("% +.3f", 7.3);}
int bonus_f_asspr_prec6p_ignoreflag(void){return test("% +.6f", 7.3);}
int bonus_f_asspr_prec0n_ignoreflag(void){return test("% +.0f", -7.3);}
int bonus_f_asspr_prec1n_ignoreflag(void){return test("% +.1f", -7.3);}
int bonus_f_asspr_prec3n_ignoreflag(void){return test("% +.3f", -7.3);}
int bonus_f_asspr_prec6n_ignoreflag(void){return test("% +.6f", -7.3);}

//Floats whose precision exceeds their compiled literal precision
int bonus_notrequired_f_overprec_might_be_undefbehav_100(void){return test("%.100f", 0.237);}
int bonus_notrequired_f_overprec_might_be_undefbehav_32(void){return test("%.32f", 0.237);}
int bonus_notrequired_f_overprec_might_be_undefbehav_4(void){return test("%.4f", 0.237);}
int bonus_notrequired_f_overprec_might_be_undefbehav_1000(void){return test("%.4f", -0.106577568068517810765107851705167);}
int bonus_notrequired_f_overprec_might_be_undefbehav_10_from_0(void){return test("%.10f", 0.0);}
int bonus_notrequired_f_overprec_might_be_undefbehav_2000(void){return test("%.2000f", 623.28376510723481);}
int bonus_notrequired_f_overprec_might_be_undefbehav_dblmin(void){return test("%.2000f", DBL_MIN);}
int bonus_notrequired_f_overprec_might_be_undefbehav_ndblmin(void){return test("%.2000f", -DBL_MIN);}
//Floats at double max, double min
int bonus_notrequired_f_limits_dblmax_prec0(void){return test("%.0f", DBL_MAX);}
int bonus_notrequired_f_limits_dblmax_prec3(void){return test("%.3f", DBL_MAX);}
int bonus_notrequired_f_limits_dblmax_precd(void){return test("%f", DBL_MAX);}
int bonus_notrequired_f_limits_dblmax_prec8(void){return test("%.8f", DBL_MAX);}
int bonus_notrequired_f_stress_limits_dblmax_prec12(void){return test("%.12f", DBL_MAX);}
int bonus_notrequired_f_stress_limits_dblmax_prec16(void){return test("%.16f", DBL_MAX);}
int bonus_notrequired_f_stress_limits_dblmax_prec18(void){return test("%.18f", DBL_MAX);}
int bonus_notrequired_f_limits_ndblmax_prec0(void){return test("%.0f", -DBL_MAX);}
int bonus_notrequired_f_limits_ndblmax_prec3(void){return test("%.3f", -DBL_MAX);}
int bonus_notrequired_f_limits_ndblmax_precd(void){return test("%f", -DBL_MAX);}
int bonus_notrequired_f_limits_ndblmax_prec8(void){return test("%.8f", -DBL_MAX);}
int bonus_notrequired_f_stress_limits_ndblmax_prec12(void){return test("%.12f", -DBL_MAX);}
int bonus_notrequired_f_stress_limits_ndblmax_prec16(void){return test("%.16f", -DBL_MAX);}
int bonus_notrequired_f_stress_limits_ndblmax_prec18(void){return test("%.18f", -DBL_MAX);}
int bonus_notrequired_f_limits_dblmin_prec0(void){return test("%.0f", DBL_MIN);}
int bonus_notrequired_f_limits_dblmin_prec3(void){return test("%.3f", DBL_MIN);}
int bonus_notrequired_f_limits_dblmin_precd(void){return test("%f", DBL_MIN);}
int bonus_notrequired_f_limits_dblmin_prec8(void){return test("%.8f", DBL_MIN);}
int bonus_notrequired_f_stress_limits_dblmin_prec12(void){return test("%.12f", DBL_MIN);}
int bonus_notrequired_f_stress_limits_dblmin_prec16(void){return test("%.16f", DBL_MIN);}
int bonus_notrequired_f_stress_limits_dblmin_prec18(void){return test("%.18f", DBL_MIN);}
int bonus_notrequired_f_limits_ndblmin_prec0(void){return test("%.0f", -DBL_MIN);}
int bonus_notrequired_f_limits_ndblmin_prec3(void){return test("%.3f", -DBL_MIN);}
int bonus_notrequired_f_limits_ndblmin_precd(void){return test("%f", -DBL_MIN);}
int bonus_notrequired_f_limits_ndblmin_prec8(void){return test("%.8f", -DBL_MIN);}
int bonus_notrequired_f_stress_limits_ndblmin_prec12(void){return test("%.12f", -DBL_MIN);}
int bonus_notrequired_f_stress_limits_ndblmin_prec16(void){return test("%.16f", -DBL_MIN);}
int bonus_notrequired_f_stress_limits_ndblmin_prec18(void){return test("%.18f", -DBL_MIN);}
 //Floats of special values
int bonus_notrequired_f_reserved_values_inf(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%f", special);}
int bonus_notrequired_f_reserved_values_ninf(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%f", special);}
int bonus_notrequired_f_reserved_values_nan(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%f", special);}
int bonus_notrequired_f_reserved_values_pzero(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%f", special);}
int bonus_notrequired_f_reserved_values_nzero(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%f", special);}
int bonus_notrequired_f_reserved_values_inf_6w(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%6f", special);}
int bonus_notrequired_f_reserved_values_ninf_6w(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%6f", special);}
int bonus_notrequired_f_reserved_values_nan_6w(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%6f", special);}
int bonus_notrequired_f_reserved_values_pzero_6w(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%6f", special);}
int bonus_notrequired_f_reserved_values_nzero_6w(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%6f", special);}
int bonus_notrequired_f_reserved_values_inf_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%-6f", special);}
int bonus_notrequired_f_reserved_values_ninf_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%-6f", special);}
int bonus_notrequired_f_reserved_values_nan_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%-6f", special);}
int bonus_notrequired_f_reserved_values_pzero_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%-6f", special);}
int bonus_notrequired_f_reserved_values_nzero_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%-6f", special);}
int bonus_notrequired_f_reserved_values_inf_6was(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%+6f", special);}
int bonus_notrequired_f_reserved_values_ninf_6was(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%+6f", special);}
int bonus_notrequired_f_reserved_values_nan_6was(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%+6f", special);}
int bonus_notrequired_f_reserved_values_pzero_6was(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%+6f", special);}
int bonus_notrequired_f_reserved_values_nzero_6was(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%+6f", special);}
int bonus_notrequired_f_reserved_values_inf_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%10.7f", special);}
int bonus_notrequired_f_reserved_values_ninf_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%10.7f", special);}
int bonus_notrequired_f_reserved_values_nan_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%10.7f", special);}
int bonus_notrequired_f_reserved_values_pzero_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%10.7f", special);}
int bonus_notrequired_f_reserved_values_nzero_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%10.7f", special);}
int bonus_notrequired_f_reserved_values_inf_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("% .7f", special);}
int bonus_notrequired_f_reserved_values_ninf_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("% .7f", special);}
int bonus_notrequired_f_reserved_values_nan_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("% .7f", special);}
int bonus_notrequired_f_reserved_values_pzero_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("% .7f", special);}
int bonus_notrequired_f_reserved_values_nzero_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("% .7f", special);}
int bonus_notrequired_f_reserved_values_inf_sp(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("% f", special);}
int bonus_notrequired_f_reserved_values_ninf_sp(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("% f", special);}
int bonus_notrequired_f_reserved_values_nan_sp(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("% f", special);}
int bonus_notrequired_f_reserved_values_pzero_sp(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("% f", special);}
int bonus_notrequired_f_reserved_values_nzero_sp(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("% f", special);}
int bonus_notrequired_f_reserved_values_inf_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%06f", special);}
int bonus_notrequired_f_reserved_values_ninf_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%06f", special);}
int bonus_notrequired_f_reserved_values_nan_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%06f", special);}
int bonus_notrequired_f_reserved_values_pzero_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%06f", special);}
int bonus_notrequired_f_reserved_values_nzero_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%06f", special);}


/* -----------------------------------------------------------------------------
** 						%g GENERAL FORMAT TESTS (BONUS)
** ---------------------------------------------------------------------------*/
//General format - Basic
int bonus_g_basic_1(void){return test("this %g scientific notation", 1.5);}
int bonus_g_basic_fltonly(void){return test("%g", 7.5);}
int bonus_g_basic_zero(void){return test("%g", 0.0);}
int bonus_g_basic_nzero(void){return test("%g", -0.0);}
int bonus_g_basic_whole(void){return test("%g", 1.0);}
int bonus_g_basic_negative(void){return test("%g", -3.85);}
int bonus_g_basic_positive_3_3(void){return test("%g", 573.924);}
int bonus_g_basic_negative_3_3(void){return test("%g", -958.125);}
int bonus_g_basic_positive_smallfpart(void){return test("%g", 23.00041);}
int bonus_g_basic_positive_allsmall(void){return test("%g", 0.000039);}
int bonus_g_basic_negative_smallfpart(void){return test("%g", -7.00036);}
int bonus_g_basic_negative_allsmall(void){return test("%g", -0.00032);}
int bonus_g_basic_limits_allsmall_pos(void){return test("%g", 0.000001);}
int bonus_g_basic_limits_allsmall_neg(void){return test("%g", -0.000001);}
int bonus_g_basic_limits_smallfpart_pos(void){return test("%g", 9873.000001);}
int bonus_g_basic_limits_smallfpart_neg(void){return test("%g", -875.000001);}
int bonus_g_basic_limits_allbig_pos(void){return test("%g", 999.999999);}
int bonus_g_basic_limits_allbig_neg(void){return test("%g", -99.999999);}
int bonus_g_basic_limits_bigfpart_pos(void){return test("%g", 0.999999);}
int bonus_g_basic_limits_bigfpart_neg(void){return test("%g", -0.999999);}
//General format - Rounding with default precision
int bonus_g_rndd_pos(void){return test("%g", 23.375094499);}
int bonus_g_rndd_neg(void){return test("%g", -985.765426499);}
int bonus_g_rndu_pos(void){return test("%g", 0.0894255);}
int bonus_g_rndu_neg(void){return test("%g", -56.2012685);}
int bonus_g_rndu_multidigit_pos(void){return test("%g", 43.4399999);}
int bonus_g_rndu_multidigit_neg(void){return test("%g", -5.0299999);}
int bonus_g_rndd_multidigit_pos(void){return test("%g", 43.43999949);}
int bonus_g_rndd_multidigit_neg(void){return test("%g", -5.02999949);}
int bonus_g_rndd_wholnobump_pos(void){return test("%g", 1.99999949);}
int bonus_g_rndd_wholnobump_neg(void){return test("%g", -0.99999949);}
int bonus_g_rndu_bumpwhole_pos(void){return test("%g", 3.9999999);}
int bonus_g_rndu_bumpwhole_neg(void){return test("%g", -5.9999999);}
//General format Prec 0
int bonus_g_prec0_zero(void){return test("%.0g", 0.0);}
int bonus_g_prec0_nzero(void){return test("%.0g", -0.0);}
int bonus_g_prec0_1(void){return test("this %.0g scientific notation", 1.6);}
int bonus_g_prec0_fltonly(void){return test("%.0g", 7.4);}
int bonus_g_prec0_whole(void){return test("%.0g", 1.0);}
int bonus_g_prec0_negative(void){return test("%.0g", -3.85);}
int bonus_g_prec0_positive_3_3(void){return test("%.0g", 573.924);}
int bonus_g_prec0_negative_3_3(void){return test("%.0g", -958.125);}
int bonus_g_prec0_positive_smallfpart(void){return test("%.0g", 23.00041);}
int bonus_g_prec0_positive_allsmall(void){return test("%.0g", 0.000039);}
int bonus_g_prec0_negative_smallfpart(void){return test("%.0g", -7.00036);}
int bonus_g_prec0_negative_allsmall(void){return test("%.0g", -0.00032);}
//General format Prec 1
int bonus_g_prec1_zero(void){return test("%.1g", 0.0);}
int bonus_g_prec1_nzero(void){return test("%.1g", -0.0);}
int bonus_g_prec1_1(void){return test("this %.1g scientific notation", 1.5);}
int bonus_g_prec1_fltonly(void){return test("%.1g", 7.5);}
int bonus_g_prec1_whole(void){return test("%.1g", 1.0);}
int bonus_g_prec1_negative(void){return test("%.1g", -3.85);}
int bonus_g_prec1_positive_3_3(void){return test("%.1g", 573.924);}
int bonus_g_prec1_negative_3_3(void){return test("%.1g", -958.125);}
int bonus_g_prec1_positive_smallfpart(void){return test("%.1g", 23.00041);}
int bonus_g_prec1_positive_allsmall(void){return test("%.1g", 0.000039);}
int bonus_g_prec1_negative_smallfpart(void){return test("%.1g", -7.00036);}
int bonus_g_prec1_negative_allsmall(void){return test("%.1g", -0.00032);}
//General format Prec 3
int bonus_g_prec3_zero(void){return test("%.3g", 0.0);}
int bonus_g_prec3_nzero(void){return test("%.3g", -0.0);}
int bonus_g_prec3_1(void){return test("this %.3g scientific notation", 1.5);}
int bonus_g_prec3_fltonly(void){return test("%.3g", 7.5);}
int bonus_g_prec3_whole(void){return test("%.3g", 1.0);}
int bonus_g_prec3_negative(void){return test("%.3g", -3.85);}
int bonus_g_prec3_positive_3_3(void){return test("%.3g", 573.924);}
int bonus_g_prec3_negative_3_3(void){return test("%.3g", -958.125);}
int bonus_g_prec3_positive_smallfpart(void){return test("%.3g", 23.00041);}
int bonus_g_prec3_positive_allsmall(void){return test("%.3g", 0.000039);}
int bonus_g_prec3_negative_smallfpart(void){return test("%.3g", -7.00036);}
int bonus_g_prec3_negative_allsmall(void){return test("%.3g", -0.00032);}
//General format - Prec 7
int bonus_g_prec7_zero(void){return test("%.7g", 0.0);}
int bonus_g_prec7_nzero(void){return test("%.7g", -0.0);}
int bonus_g_prec7_1(void){return test("this %.7g scientific notation", 1.5);}
int bonus_g_prec7_fltonly(void){return test("%.7g", 7.5);}
int bonus_g_prec7_whole(void){return test("%.7g", 1.0);}
int bonus_g_prec7_negative(void){return test("%.7g", -3.85);}
int bonus_g_prec7_positive_3_3(void){return test("%.7g", 573.924);}
int bonus_g_prec7_negative_3_3(void){return test("%.7g", -958.125);}
int bonus_g_prec7_positive_smallfpart(void){return test("%.7g", 23.00041);}
int bonus_g_prec7_positive_allsmall(void){return test("%.7g", 0.0000039);}
int bonus_g_prec7_negative_smallfpart(void){return test("%.7g", -7.00036);}
int bonus_g_prec7_negative_allsmall(void){return test("%.7g", -0.000032);}
int bonus_g_prec7_limits_allsmall_pos(void){return test("%.7g", 0.0000001);}
int bonus_g_prec7_limits_allsmall_neg(void){return test("%.7g", -0.0000001);}
int bonus_g_prec7_limits_smallfpart_pos(void){return test("%.7g", 9873.000001);}
int bonus_g_prec7_limits_smallfpart_neg(void){return test("%.7g", -875.000001);}
int bonus_g_prec7_limits_allbig_pos(void){return test("%.7g", 999.9999999);}
int bonus_g_prec7_limits_allbig_neg(void){return test("%.7g", -99.9999999);}
int bonus_g_prec7_limits_bigfpart_pos(void){return test("%.7g", 0.999999);}
int bonus_g_prec7_limits_bigfpart_neg(void){return test("%.7g", -0.999999);}
//General format - Prec 7 Rounding
int bonus_g_rnd_prec7_rndd_pos(void){return test("%.7g", 23.375094499);}
int bonus_g_rnd_prec7_rndd_neg(void){return test("%.7g", -985.765426499);}
int bonus_g_rnd_prec7_rndu_pos(void){return test("%.7g", 0.0894255);}
int bonus_g_rnd_prec7_rndu_neg(void){return test("%.7g", -56.2012685);}
int bonus_g_rnd_prec7_rndu_multidigit_pos(void){return test("%.7g", 43.4399999);}
int bonus_g_rnd_prec7_rndu_multidigit_neg(void){return test("%.7g", -5.0299999);}
int bonus_g_rnd_prec7_rndd_multidigit_pos(void){return test("%.7g", 43.43999949);}
int bonus_g_rnd_prec7_rndd_multidigit_neg(void){return test("%.7g", -5.02999949);}
int bonus_g_rnd_prec7_rndd_wholnobump_pos(void){return test("%.7g", 1.99999949);}
int bonus_g_rnd_prec7_rndd_wholnobump_neg(void){return test("%.7g", -0.99999949);}
int bonus_g_rnd_prec7_rndu_bumpwhole_pos(void){return test("%.7g", 3.9999999);}
//General format - Prec 8
int bonus_g_prec8_zero(void){return test("%.8g", 0.0);}
int bonus_g_prec8_nzero(void){return test("%.8g", -0.0);}
int bonus_g_prec8_1(void){return test("this %.8g scientific notation", 1.5);}
int bonus_g_prec8_fltonly(void){return test("%.8g", 7.5);}
int bonus_g_prec8_whole(void){return test("%.8g", 1.0);}
int bonus_g_prec8_negative(void){return test("%.8g", -3.85);}
int bonus_g_prec8_positive_3_3(void){return test("%.8g", 573.924);}
int bonus_g_prec8_negative_3_3(void){return test("%.8g", -958.125);}
int bonus_g_prec8_positive_smallfpart(void){return test("%.8g", 23.00041);}
int bonus_g_prec8_positive_allsmall(void){return test("%.8g", 0.00000039);}
int bonus_g_prec8_negative_smallfpart(void){return test("%.8g", -7.00036);}
int bonus_g_prec8_negative_allsmall(void){return test("%.8g", -0.0000032);}
int bonus_g_prec8_limits_allsmall_pos(void){return test("%.8g", 0.00000001);}
int bonus_g_prec8_limits_allsmall_neg(void){return test("%.8g", -0.00000001);}
int bonus_g_prec8_limits_smallfpart_pos(void){return test("%.8g", 9873.000001);}
int bonus_g_prec8_limits_smallfpart_neg(void){return test("%.8g", -875.000001);}
int bonus_g_prec8_limits_allbig_pos(void){return test("%.8g", 999.9999999);}
int bonus_g_prec8_limits_allbig_neg(void){return test("%.8g", -99.99999999);}
int bonus_g_prec8_limits_bigfpart_pos(void){return test("%.8g", 0.999999);}
int bonus_g_prec8_limits_bigfpart_neg(void){return test("%.8g", -0.999999);}
//General format - Prec 8 Rounding
int bonus_g_rnd_prec8_rndd_pos(void){return test("%.8g", 23.375094499);}
int bonus_g_rnd_prec8_rndd_neg(void){return test("%.8g", -985.765426499);}
int bonus_g_rnd_prec8_rndu_pos(void){return test("%.8g", 0.0894255);}
int bonus_g_rnd_prec8_rndu_neg(void){return test("%.8g", -56.2012685);}
int bonus_g_rnd_prec8_rndu_multidigit_pos(void){return test("%.8g", 43.4399999);}
int bonus_g_rnd_prec8_rndu_multidigit_neg(void){return test("%.8g", -5.0299999);}
int bonus_g_rnd_prec8_rndd_multidigit_pos(void){return test("%.8g", 43.43999949);}
int bonus_g_rnd_prec8_rndd_multidigit_neg(void){return test("%.8g", -5.02999949);}
int bonus_g_rnd_prec8_rndd_wholnobump_pos(void){return test("%.8g", 1.99999949);}
int bonus_g_rnd_prec8_rndd_wholnobump_neg(void){return test("%.8g", -0.99999949);}
int bonus_g_rnd_prec8_rndu_bumpwhole_pos(void){return test("%.8g", 3.9999999);}
//General format - Prec 9
int bonus_g_prec9_zero(void){return test("%.9g", 0.0);}
int bonus_g_prec9_nzero(void){return test("%.9g", -0.0);}
int bonus_g_stress_prec9_1(void){return test("this %.9g scientific notation", 1.5);}
int bonus_g_stress_prec9_fltonly(void){return test("%.9g", 7.5);}
int bonus_g_stress_prec9_whole(void){return test("%.9g", 1.0);}
int bonus_g_stress_prec9_negative(void){return test("%.9g", -3.85);}
int bonus_g_stress_prec9_positive_3_3(void){return test("%.9g", 573.924);}
int bonus_g_stress_prec9_negative_3_3(void){return test("%.9g", -958.125);}
int bonus_g_stress_prec9_positive_smallfpart(void){return test("%.9g", 23.00041);}
int bonus_g_stress_prec9_positive_allsmall(void){return test("%.9g", 0.00000039);}
int bonus_g_stress_prec9_negative_smallfpart(void){return test("%.9g", -7.00036);}
int bonus_g_stress_prec9_negative_allsmall(void){return test("%.9g", -0.0000032);}
int bonus_g_stress_prec9_limits_allsmall_pos(void){return test("%.9g", 0.00000001);}
int bonus_g_stress_prec9_limits_allsmall_neg(void){return test("%.9g", -0.00000001);}
int bonus_g_stress_prec9_limits_smallfpart_pos(void){return test("%.9g", 9873.000001);}
int bonus_g_stress_prec9_limits_smallfpart_neg(void){return test("%.9g", -875.000001);}
int bonus_g_stress_prec9_limits_allbig_pos(void){return test("%.9g", 999.99999999);}
int bonus_g_stress_prec9_limits_allbig_neg(void){return test("%.9g", -99.99999999);}
int bonus_g_stress_prec9_limits_bigfpart_pos(void){return test("%.9g", 0.999999);}
int bonus_g_stress_prec9_limits_bigfpart_neg(void){return test("%.9g", -0.999999);}
//General format - Prec 9 Rounding
int bonus_g_stress_prec9_rndd_pos(void){return test("%.9g", 23.375094499);}
int bonus_g_stress_prec9_rndd_neg(void){return test("%.9g", -985.765426499);}
int bonus_g_stress_prec9_rndu_pos(void){return test("%.9g", 0.0894255);}
int bonus_g_stress_prec9_rndu_neg(void){return test("%.9g", -56.2012685);}
int bonus_g_stress_prec9_rndu_multidigit_pos(void){return test("%.9g", 43.4399999);}
int bonus_g_stress_prec9_rndu_multidigit_neg(void){return test("%.9g", -5.0299999);}
int bonus_g_stress_prec9_rndd_multidigit_pos(void){return test("%.9g", 43.43999949);}
int bonus_g_stress_prec9_rndd_multidigit_neg(void){return test("%.9g", -5.02999949);}
int bonus_g_stress_prec9_rndd_wholnobump_pos(void){return test("%.9g", 1.99999949);}
int bonus_g_stress_prec9_rndd_wholnobump_neg(void){return test("%.9g", -0.99999949);}
int bonus_g_stress_prec9_rndu_bumpwhole_pos(void){return test("%.9g", 3.9999999);}
//General format - Prec 10
int bonus_g_prec10_zero(void){return test("%.10g", 0.0);}
int bonus_g_prec10_nzero(void){return test("%.10g", -0.0);}
int bonus_g_stress_prec10_1(void){return test("this %.10g scientific notation", 1.5);}
int bonus_g_stress_prec10_fltonly(void){return test("%.10g", 7.5);}
int bonus_g_stress_prec10_whole(void){return test("%.10g", 1.0);}
int bonus_g_stress_prec10_negative(void){return test("%.10g", -3.85);}
int bonus_g_stress_prec10_positive_3_10(void){return test("%.10g", 573.924);}
int bonus_g_stress_prec10_negative_3_10(void){return test("%.10g", -958.125);}
int bonus_g_stress_prec10_pos(void){return test("%.10g", 23.8341375094);}
int bonus_g_stress_prec10_neg(void){return test("%.10g", -985.2459765426);}
int bonus_g_stress_prec10_rndd_pos(void){return test("%.10g", 23.8341375094499);}
int bonus_g_stress_prec10_rndd_neg(void){return test("%.10g", -985.2459765426499);}
int bonus_g_stress_prec10_rndu_pos(void){return test("%.10g", 0.87650894255);}
int bonus_g_stress_prec10_rndu_neg(void){return test("%.10g", -56.47852012685);}
int bonus_g_stress_prec10_positive_smallfpart(void){return test("%.10g", 23.000000041);}
int bonus_g_stress_prec10_positive_allsmall(void){return test("%.10g", 0.0000000039);}
int bonus_g_stress_prec10_negative_smallfpart(void){return test("%.10g", -7.000000036);}
int bonus_g_stress_prec10_negative_allsmall(void){return test("%.10g", -0.000000032);}
int bonus_g_stress_prec10_limits_allsmall_pos(void){return test("%.10g", 0.0000000001);}
int bonus_g_stress_prec10_limits_allsmall_neg(void){return test("%.10g", -0.0000000001);}
int bonus_g_stress_prec10_limits_smallfpart_pos(void){return test("%.10g", 9873.0000000001);}
int bonus_g_stress_prec10_limits_smallfpart_neg(void){return test("%.10g", -875.0000000001);}
int bonus_g_stress_prec10_limits_allbig_pos(void){return test("%.10g", 999.9999999999);}
int bonus_g_stress_prec10_limits_allbig_neg(void){return test("%.10g", -99.9999999999);}
int bonus_g_stress_prec10_limits_bigfpart_pos(void){return test("%.10g", 0.9999999999);}
int bonus_g_stress_prec10_limits_bigfpart_neg(void){return test("%.10g", -0.9999999999);}
//General format - Prec 11
int bonus_g_stress_prec11_rndu(void){return test("%.11g",        1.025978541236587568);}
int bonus_g_stress_prec11_rndd(void){return test("%.11g",        1.025978548534310421);}
int bonus_g_stress_prec11_limits_tiny(void){return test("%.11g", 0.000000000010000000);}
int bonus_g_stress_prec11_limits_big(void){return test("%.11g", 99.999999999990000000);}
//General format - Prec 12
int bonus_g_stress_prec12_rndu(void){return test("%.12g",        1.025978541236587568);}
int bonus_g_stress_prec12_rndd(void){return test("%.12g",        1.025978548534310421);}
int bonus_g_stress_prec12_limits_tiny(void){return test("%.12g", 0.000000000001000000);}
int bonus_g_stress_prec12_limits_big(void){return test("%.12g", 99.999999999999000000);}
//General format - Prec 13
int bonus_g_stress_prec13_rndu(void){return test("%.13g",        1.025978541136587568);}
int bonus_g_stress_prec13_rndd(void){return test("%.13g",        1.025978548534310421);}
int bonus_g_stress_prec13_limits_tiny(void){return test("%.13g", 0.000000000000100000);}
int bonus_g_stress_prec13_limits_big(void){return test("%.13g", 99.999999999999900000);}
//General format - Prec 14
int bonus_g_stress_prec14_rndu(void){return test("%.14g",        1.025978541436587568);}
int bonus_g_stress_prec14_rndd(void){return test("%.14g",        1.025978548534310421);}
int bonus_g_stress_prec14_limits_tiny(void){return test("%.14g", 0.000000000000010000);}
int bonus_g_stress_prec14_limits_big(void){return test("%.14g",  9.999999999999990000);}
//General format - Prec 15
int bonus_g_stress_prec15_rndu(void){return test("%.15g",        1.025978542436587568);}
int bonus_g_stress_prec15_rndd(void){return test("%.15g",        1.025978548534310421);}
int bonus_g_stress_prec15_limits_tiny(void){return test("%.15g", 0.000000000000001000);}
int bonus_g_stress_prec15_limits_big(void){return test("%.15g",  0.999999999999999000);}
 //General format - Prec 16
int bonus_notrequired_g_stress_prec16_rndu(void){return test("%.16g",        1.025978542436587568);}
int bonus_notrequired_g_stress_prec16_rndd(void){return test("%.16g",        1.025978548534310421);}
int bonus_notrequired_g_stress_prec16_limits_tiny(void){return test("%.16g", 0.000000000000000100);}
int bonus_notrequired_g_stress_prec16_limits_big(void){return test("%.16g",  0.999999999999999900);}
//General format - Prec 17
int bonus_notrequired_g_stress_prec17_rndu(void){return test("%.17g",        1.025978542436587568);}
int bonus_notrequired_g_stress_prec17_rndd(void){return test("%.17g",        1.025978548534310421);}
int bonus_notrequired_g_stress_prec17_limits_tiny(void){return test("%.17g", 0.000000000000000010);}
int bonus_notrequired_g_stress_prec17_limits_big(void){return test("%.17g",  0.999999999999999990);}
//General format - Prec 18
int bonus_notrequired_g_stress_prec18_rndu(void){return test("%.18g",        0.125978542436587568);}
int bonus_notrequired_g_stress_prec18_rndd(void){return test("%.18g",        0.125978548534310421);}
//General format with altform,~
int bonus_g_af_prec0_zero(void){return test("%#.0g", 0.0);}
int bonus_g_af_prec0_nzero(void){return test("%#.0g", -0.0);}
int bonus_g_af_prec1_zero(void){return test("%#.1g", 0.0);}
int bonus_g_af_prec1_nzero(void){return test("%#.1g", -0.0);}
int bonus_g_af_prec0p(void){return test("%#.0g", 7.4);}
int bonus_g_af_prec1p(void){return test("%#.1g", 7.3);}
int bonus_g_af_prec0n(void){return test("%#.0g", -7.4);}
int bonus_g_af_prec1n(void){return test("%#.1g", -7.3);}
//General format with allsign,~
int bonus_g_as_prec0_zero(void){return test("%+.0g", 0.0);}
int bonus_g_as_prec0_nzero(void){return test("%+.0g", -0.0);}
int bonus_g_as_prec3_zero(void){return test("%+.3g", 0.0);}
int bonus_g_as_prec3_nzero(void){return test("%+.3g", -0.0);}
int bonus_g_as_prec0p_as(void){return test("%+.0g", 7.4);}
int bonus_g_as_prec3p_as(void){return test("%+.3g", 7.3);}
int bonus_g_as_prec0n_as(void){return test("%+.0g", -7.4);}
int bonus_g_as_prec3n_as(void){return test("%+.3g", -7.3);}
//General format with field width,~
int bonus_g_wprec0p_zero(void){return test("%5.0g", 0.0);}
int bonus_g_wprec0p_nzero(void){return test("%5.0g", -0.0);}
int bonus_g_wprec3p_zero(void){return test("%5.3g", 0.0);}
int bonus_g_wprec3p_nzero(void){return test("%5.3g", -0.0);}
int bonus_g_wprec0p(void){return test("%5.0g", 7.3);}
int bonus_g_wprec1p(void){return test("%5.1g", 7.3);}
int bonus_g_wprec3p(void){return test("%5.3g", 7.3);}
int bonus_g_wprec6p(void){return test("%5.6g", 7.3);}
int bonus_g_wprec0n(void){return test("%5.0g", -7.3);}
int bonus_g_wprec1n(void){return test("%5.1g", -7.3);}
int bonus_g_wprec3n(void){return test("%5.3g", -7.3);}
int bonus_g_wprec6n(void){return test("%5.6g", -7.3);}
//General format with field width and zero padding,~
int bonus_g_wzp_prec0p_zero(void){return test("%05.0g", 0.0);}
int bonus_g_wzp_prec0p_nzero(void){return test("%05.0g", -0.0);}
int bonus_g_wzp_prec3p_zero(void){return test("%05.3g", 0.0);}
int bonus_g_wzp_prec3p_nzero(void){return test("%05.3g", -0.0);}
int bonus_g_wzp_prec0p(void){return test("%05.0g", 7.3);}
int bonus_g_wzp_prec1p(void){return test("%05.1g", 7.3);}
int bonus_g_wzp_prec3p(void){return test("%05.3g", 7.3);}
int bonus_g_wzp_prec6p(void){return test("%05.6g", 7.3);}
int bonus_g_wzp_prec0n(void){return test("%05.0g", -7.3);}
int bonus_g_wzp_prec1n(void){return test("%05.1g", -7.3);}
int bonus_g_wzp_prec3n(void){return test("%05.3g", -7.3);}
int bonus_g_wzp_prec6n(void){return test("%05.6g", -7.3);}
//General format with field width and left justify,~
int bonus_g_wlj_prec0p_zero(void){return test("%-5.0g", 0.0);}
int bonus_g_wlj_prec0p_nzero(void){return test("%-5.0g", -0.0);}
int bonus_g_wlj_prec3p_zero(void){return test("%-5.3g", 0.0);}
int bonus_g_wlj_prec3p_nzero(void){return test("%-5.3g", -0.0);}
int bonus_g_wlj_prec0p(void){return test("%-5.0g", 7.3);}
int bonus_g_wlj_prec1p(void){return test("%-5.1g", 7.3);}
int bonus_g_wlj_prec3p(void){return test("%-5.3g", 7.3);}
int bonus_g_wlj_prec6p(void){return test("%-5.6g", 7.3);}
int bonus_g_wlj_prec0n(void){return test("%-5.0g", -7.3);}
int bonus_g_wlj_prec1n(void){return test("%-5.1g", -7.3);}
int bonus_g_wlj_prec3n(void){return test("%-5.3g", -7.3);}
int bonus_g_wlj_prec6n(void){return test("%-5.6g", -7.3);}
//General format with field width and zero padding and left justify,~
int bonus_g_wzplj_prec0p_ignoreflag_zero(void){return test("%-05.0g", 0.0);}
int bonus_g_wzplj_prec0p_ignoreflag_nzero(void){return test("%-05.0g", -0.0);}
int bonus_g_wzplj_prec3p_ignoreflag_zero(void){return test("%-05.3g", 0.0);}
int bonus_g_wzplj_prec3p_ignoreflag_nzero(void){return test("%-05.3g", -0.0);}
int bonus_g_wzplj_prec0p_ignoreflag(void){return test("%-05.0g", 7.3);}
int bonus_g_wzplj_prec1p_ignoreflag(void){return test("%-05.1g", 7.3);}
int bonus_g_wzplj_prec3p_ignoreflag(void){return test("%-05.3g", 7.3);}
int bonus_g_wzplj_prec6p_ignoreflag(void){return test("%-05.6g", 7.3);}
int bonus_g_wzplj_prec0n_ignoreflag(void){return test("%-05.0g", -7.3);}
int bonus_g_wzplj_prec1n_ignoreflag(void){return test("%-05.1g", -7.3);}
int bonus_g_wzplj_prec3n_ignoreflag(void){return test("%-05.3g", -7.3);}
int bonus_g_wzplj_prec6n_ignoreflag(void){return test("%-05.6g", -7.3);}
//General format with field width and zero padding and left justify, rev f order,~
int bonus_g_wzpljr_prec0p_ignoreflag_zero(void){return test("%0-5.0g", 0.0);}
int bonus_g_wzpljr_prec0p_ignoreflag_nzero(void){return test("%0-5.0g", -0.0);}
int bonus_g_wzpljr_prec3p_ignoreflag_zero(void){return test("%0-5.3g", 0.0);}
int bonus_g_wzpljr_prec3p_ignoreflag_nzero(void){return test("%0-5.3g", -0.0);}
int bonus_g_wzpljr_prec0p_ignoreflag(void){return test("%0-5.0g", 7.3);}
int bonus_g_wzpljr_prec1p_ignoreflag(void){return test("%0-5.1g", 7.3);}
int bonus_g_wzpljr_prec3p_ignoreflag(void){return test("%0-5.3g", 7.3);}
int bonus_g_wzpljr_prec6p_ignoreflag(void){return test("%0-5.6g", 7.3);}
int bonus_g_wzpljr_prec0n_ignoreflag(void){return test("%0-5.0g", -7.3);}
int bonus_g_wzpljr_prec1n_ignoreflag(void){return test("%0-5.1g", -7.3);}
int bonus_g_wzpljr_prec3n_ignoreflag(void){return test("%0-5.3g", -7.3);}
int bonus_g_wzpljr_prec6n_ignoreflag(void){return test("%0-5.6g", -7.3);}
//General format with field width and left justify and altform,~
int bonus_g_wzpljaf_prec0p_zero(void){return test("%#-5.0g", 0.0);}
int bonus_g_wzpljaf_prec0p_nzero(void){return test("%#-5.0g", -0.0);}
int bonus_g_wzpljaf_prec3p_zero(void){return test("%#-5.3g", 0.0);}
int bonus_g_wzpljaf_prec3p_nzero(void){return test("%#-5.3g", -0.0);}
int bonus_g_wzpljaf_prec0p(void){return test("%#-5.0g", 7.3);}
int bonus_g_wzpljaf_prec1p(void){return test("%#-5.1g", 7.3);}
int bonus_g_wzpljaf_prec3p(void){return test("%#-5.3g", 7.3);}
int bonus_g_wzpljaf_prec6p(void){return test("%#-5.6g", 7.3);}
int bonus_g_wzpljaf_prec0n(void){return test("%#-5.0g", -7.3);}
int bonus_g_wzpljaf_prec1n(void){return test("%#-5.1g", -7.3);}
int bonus_g_wzpljaf_prec3n(void){return test("%#-5.3g", -7.3);}
int bonus_g_wzpljaf_prec6n(void){return test("%#-5.6g", -7.3);}
//General format with field width and allsign,~
int bonus_g_was_prec0p_zero(void){return test("%+5.0g", 0.0);}
int bonus_g_was_prec0p_nzero(void){return test("%+5.0g", -0.0);}
int bonus_g_was_prec3p_zero(void){return test("%+5.3g", 0.0);}
int bonus_g_was_prec3p_nzero(void){return test("%+5.3g", -0.0);}
int bonus_g_was_prec0p(void){return test("%+5.0g", 7.3);}
int bonus_g_was_prec1p(void){return test("%+5.1g", 7.3);}
int bonus_g_was_prec3p(void){return test("%+5.3g", 7.3);}
int bonus_g_was_prec6p(void){return test("%+5.6g", 7.3);}
int bonus_g_was_prec0n(void){return test("%+5.0g", -7.3);}
int bonus_g_was_prec1n(void){return test("%+5.1g", -7.3);}
int bonus_g_was_prec3n(void){return test("%+5.3g", -7.3);}
int bonus_g_was_prec6n(void){return test("%+5.6g", -7.3);}
//General format with field width and zero padding and allsign,~
int bonus_g_wzpas_prec0p_zero(void){return test("%+05.0g", 0.0);}
int bonus_g_wzpas_prec0p_nzero(void){return test("%+05.0g", -0.0);}
int bonus_g_wzpas_prec3p_zero(void){return test("%+05.3g", 0.0);}
int bonus_g_wzpas_prec3p_nzero(void){return test("%+05.3g", -0.0);}
int bonus_g_wzpas_prec0p(void){return test("%+05.0g", 7.3);}
int bonus_g_wzpas_prec1p(void){return test("%+05.1g", 7.3);}
int bonus_g_wzpas_prec3p(void){return test("%+05.3g", 7.3);}
int bonus_g_wzpas_prec6p(void){return test("%+05.6g", 7.3);}
int bonus_g_wzpas_prec0n(void){return test("%+05.0g", -7.3);}
int bonus_g_wzpas_prec1n(void){return test("%+05.1g", -7.3);}
int bonus_g_wzpas_prec3n(void){return test("%+05.3g", -7.3);}
int bonus_g_wzpas_prec6n(void){return test("%+05.6g", -7.3);}
//General format with field width and left justify and allsign,~
int bonus_g_wljas_prec0p_zero(void){return test("%+-5.0g", 0.0);}
int bonus_g_wljas_prec0p_nzero(void){return test("%+-5.0g", -0.0);}
int bonus_g_wljas_prec3p_zero(void){return test("%+-5.3g", 0.0);}
int bonus_g_wljas_prec3p_nzero(void){return test("%+-5.3g", -0.0);}
int bonus_g_wljas_prec0p(void){return test("%+-5.0g", 7.3);}
int bonus_g_wljas_prec1p(void){return test("%+-5.1g", 7.3);}
int bonus_g_wljas_prec3p(void){return test("%+-5.3g", 7.3);}
int bonus_g_wljas_prec6p(void){return test("%+-5.6g", 7.3);}
int bonus_g_wljas_prec0n(void){return test("%+-5.0g", -7.3);}
int bonus_g_wljas_prec1n(void){return test("%+-5.1g", -7.3);}
int bonus_g_wljas_prec3n(void){return test("%+-5.3g", -7.3);}
int bonus_g_wljas_prec6n(void){return test("%+-5.6g", -7.3);}
//General format with field width and zero padding and left justify and allsign,~
int bonus_g_wzpljas_prec0p_ignoreflag_zero(void){return test("%+-05.0g", 0.0);}
int bonus_g_wzpljas_prec0p_ignoreflag_nzero(void){return test("%+-05.0g", -0.0);}
int bonus_g_wzpljas_prec3p_ignoreflag_zero(void){return test("%+-05.3g", 0.0);}
int bonus_g_wzpljas_prec3p_ignoreflag_nzero(void){return test("%+-05.3g", -0.0);}
int bonus_g_wzpljas_prec0p_ignoreflag(void){return test("%+-05.0g", 7.3);}
int bonus_g_wzpljas_prec1p_ignoreflag(void){return test("%+-05.1g", 7.3);}
int bonus_g_wzpljas_prec3p_ignoreflag(void){return test("%+-05.3g", 7.3);}
int bonus_g_wzpljas_prec6p_ignoreflag(void){return test("%+-05.6g", 7.3);}
int bonus_g_wzpljas_prec0n_ignoreflag(void){return test("%+-05.0g", -7.3);}
int bonus_g_wzpljas_prec1n_ignoreflag(void){return test("%+-05.1g", -7.3);}
int bonus_g_wzpljas_prec3n_ignoreflag(void){return test("%+-05.3g", -7.3);}
int bonus_g_wzpljas_prec6n_ignoreflag(void){return test("%+-05.6g", -7.3);}
//General format with field width left justify, rev f order and allsign,~
int bonus_g_wzpljras_prec0p_zero(void){return test("%+-05.0g", 0.0);}
int bonus_g_wzpljras_prec0p_nzero(void){return test("%+-05.0g", -0.0);}
int bonus_g_wzpljras_prec3p_zero(void){return test("%+-05.3g", 0.0);}
int bonus_g_wzpljras_prec3p_nzero(void){return test("%+-05.3g", -0.0);}
int bonus_g_wzpljras_prec0p(void){return test("%-+5.0g", 7.3);}
int bonus_g_wzpljras_prec1p(void){return test("%-+5.1g", 7.3);}
int bonus_g_wzpljras_prec3p(void){return test("%-+5.3g", 7.3);}
int bonus_g_wzpljras_prec6p(void){return test("%-+5.6g", 7.3);}
int bonus_g_wzpljras_prec0n(void){return test("%-+5.0g", -7.3);}
int bonus_g_wzpljras_prec1n(void){return test("%-+5.1g", -7.3);}
int bonus_g_wzpljras_prec3n(void){return test("%-+5.3g", -7.3);}
int bonus_g_wzpljras_prec6n(void){return test("%-+5.6g", -7.3);}
//General format with field width and left justify and altform and allsign,~
int bonus_g_wzpljafas_prec0p_zero(void){return test("%+#-05.0g", 0.0);}
int bonus_g_wzpljafas_prec0p_nzero(void){return test("%+#-05.0g", -0.0);}
int bonus_g_wzpljafas_prec3p_zero(void){return test("%+#-05.3g", 0.0);}
int bonus_g_wzpljafas_prec3p_nzero(void){return test("%+#-05.3g", -0.0);}
int bonus_g_wzpljafas_prec0p(void){return test("%+#-5.0g", 7.3);}
int bonus_g_wzpljafas_prec1p(void){return test("%+#-5.1g", 7.3);}
int bonus_g_wzpljafas_prec3p(void){return test("%+#-5.3g", 7.3);}
int bonus_g_wzpljafas_prec6p(void){return test("%+#-5.6g", 7.3);}
int bonus_g_wzpljafas_prec0n(void){return test("%+#-5.0g", -7.3);}
int bonus_g_wzpljafas_prec1n(void){return test("%+#-5.1g", -7.3);}
int bonus_g_wzpljafas_prec3n(void){return test("%+#-5.3g", -7.3);}
int bonus_g_wzpljafas_prec6n(void){return test("%+#-5.6g", -7.3);}
//General format with field width and sp,~
int bonus_g_wsp_prec0p_zero(void){return test("% 5.0g", 0.0);}
int bonus_g_wsp_prec0p_nzero(void){return test("% 5.0g", -0.0);}
int bonus_g_wsp_prec3p_zero(void){return test("% 5.3g", 0.0);}
int bonus_g_wsp_prec3p_nzero(void){return test("% 5.3g", -0.0);}
int bonus_g_wsp_prec0p(void){return test("% 5.0g", 7.3);}
int bonus_g_wsp_prec1p(void){return test("% 5.1g", 7.3);}
int bonus_g_wsp_prec3p(void){return test("% 5.3g", 7.3);}
int bonus_g_wsp_prec6p(void){return test("% 5.6g", 7.3);}
int bonus_g_wsp_prec0n(void){return test("% 5.0g", -7.3);}
int bonus_g_wsp_prec1n(void){return test("% 5.1g", -7.3);}
int bonus_g_wsp_prec3n(void){return test("% 5.3g", -7.3);}
int bonus_g_wsp_prec6n(void){return test("% 5.6g", -7.3);}
//General format with field width and zero padding and sp,~
int bonus_g_wzpsp_prec0p_zero(void){return test("% 05.0g", 0.0);}
int bonus_g_wzpsp_prec0p_nzero(void){return test("% 05.0g", -0.0);}
int bonus_g_wzpsp_prec3p_zero(void){return test("% 05.3g", 0.0);}
int bonus_g_wzpsp_prec3p_nzero(void){return test("% 05.3g", -0.0);}
int bonus_g_wzpsp_prec0p(void){return test("% 05.0g", 7.3);}
int bonus_g_wzpsp_prec1p(void){return test("% 05.1g", 7.3);}
int bonus_g_wzpsp_prec3p(void){return test("% 05.3g", 7.3);}
int bonus_g_wzpsp_prec6p(void){return test("% 05.6g", 7.3);}
int bonus_g_wzpsp_prec0n(void){return test("% 05.0g", -7.3);}
int bonus_g_wzpsp_prec1n(void){return test("% 05.1g", -7.3);}
int bonus_g_wzpsp_prec3n(void){return test("% 05.3g", -7.3);}
int bonus_g_wzpsp_prec6n(void){return test("% 05.6g", -7.3);}
//General format with field width and left justify and sp,~
int bonus_g_wljsp_prec0p_zero(void){return test("% -5.0g", 0.0);}
int bonus_g_wljsp_prec0p_nzero(void){return test("% -5.0g", -0.0);}
int bonus_g_wljsp_prec3p_zero(void){return test("% -5.3g", 0.0);}
int bonus_g_wljsp_prec3p_nzero(void){return test("% -5.3g", -0.0);}
int bonus_g_wljsp_prec0p(void){return test("% -5.0g", 7.3);}
int bonus_g_wljsp_prec1p(void){return test("% -5.1g", 7.3);}
int bonus_g_wljsp_prec3p(void){return test("% -5.3g", 7.3);}
int bonus_g_wljsp_prec6p(void){return test("% -5.6g", 7.3);}
int bonus_g_wljsp_prec0n(void){return test("% -5.0g", -7.3);}
int bonus_g_wljsp_prec1n(void){return test("% -5.1g", -7.3);}
int bonus_g_wljsp_prec3n(void){return test("% -5.3g", -7.3);}
int bonus_g_wljsp_prec6n(void){return test("% -5.6g", -7.3);}
//General format with field width and zero padding and left justify and sp,~
int bonus_g_wzpljsp_prec0p_zero(void){return test("% -05.0g", 0.0);}
int bonus_g_wzpljsp_prec0p_nzero(void){return test("% -05.0g", -0.0);}
int bonus_g_wzpljsp_prec3p_zero(void){return test("% -05.3g", 0.0);}
int bonus_g_wzpljsp_prec3p_nzero(void){return test("% -05.3g", -0.0);}
int bonus_g_wzpljsp_prec0p_ignoreflag(void){return test("% -05.0g", 7.3);}
int bonus_g_wzpljsp_prec1p_ignoreflag(void){return test("% -05.1g", 7.3);}
int bonus_g_wzpljsp_prec3p_ignoreflag(void){return test("% -05.3g", 7.3);}
int bonus_g_wzpljsp_prec6p_ignoreflag(void){return test("% -05.6g", 7.3);}
int bonus_g_wzpljsp_prec0n_ignoreflag(void){return test("% -05.0g", -7.3);}
int bonus_g_wzpljsp_prec1n_ignoreflag(void){return test("% -05.1g", -7.3);}
int bonus_g_wzpljsp_prec3n_ignoreflag(void){return test("% -05.3g", -7.3);}
int bonus_g_wzpljsp_prec6n_ignoreflag(void){return test("% -05.6g", -7.3);}
//General format with field width left justify, rev f order and sp,~
int bonus_g_wzpljrsp_prec0p_zero(void){return test("%- 5.0g", 0.0);}
int bonus_g_wzpljrsp_prec0p_nzero(void){return test("%- 5.0g", -0.0);}
int bonus_g_wzpljrsp_prec3p_zero(void){return test("%- 5.3g", 0.0);}
int bonus_g_wzpljrsp_prec3p_nzero(void){return test("%- 5.3g", -0.0);}
int bonus_g_wzpljrsp_prec0p(void){return test("%- 5.0g", 7.3);}
int bonus_g_wzpljrsp_prec1p(void){return test("%- 5.1g", 7.3);}
int bonus_g_wzpljrsp_prec3p(void){return test("%- 5.3g", 7.3);}
int bonus_g_wzpljrsp_prec6p(void){return test("%- 5.6g", 7.3);}
int bonus_g_wzpljrsp_prec0n(void){return test("%- 5.0g", -7.3);}
int bonus_g_wzpljrsp_prec1n(void){return test("%- 5.1g", -7.3);}
int bonus_g_wzpljrsp_prec3n(void){return test("%- 5.3g", -7.3);}
int bonus_g_wzpljrsp_prec6n(void){return test("%- 5.6g", -7.3);}
//General format with field width and left justify and altform and sp,~
int bonus_g_wzpljafsp_prec0p_zero(void){return test("% #-05.0g", 0.0);}
int bonus_g_wzpljafsp_prec0p_nzero(void){return test("% #-05.0g", -0.0);}
int bonus_g_wzpljafsp_prec3p_zero(void){return test("% #-05.3g", 0.0);}
int bonus_g_wzpljafsp_prec3p_nzero(void){return test("% #-05.3g", -0.0);}
int bonus_g_wzpljafsp_prec0p(void){return test("% #-5.0g", 7.3);}
int bonus_g_wzpljafsp_prec1p(void){return test("% #-5.1g", 7.3);}
int bonus_g_wzpljafsp_prec3p(void){return test("% #-5.3g", 7.3);}
int bonus_g_wzpljafsp_prec6p(void){return test("% #-5.6g", 7.3);}
int bonus_g_wzpljafsp_prec0n(void){return test("% #-5.0g", -7.3);}
int bonus_g_wzpljafsp_prec1n(void){return test("% #-5.1g", -7.3);}
int bonus_g_wzpljafsp_prec3n(void){return test("% #-5.3g", -7.3);}
int bonus_g_wzpljafsp_prec6n(void){return test("% #-5.6g", -7.3);}
//General format with allsign and sp,~
int bonus_g_assp_prec0p_ignoreflag(void){return test("%+ .0g", 7.3);}
int bonus_g_assp_prec1p_ignoreflag(void){return test("%+ .1g", 7.3);}
int bonus_g_assp_prec3p_ignoreflag(void){return test("%+ .3g", 7.3);}
int bonus_g_assp_prec6p_ignoreflag(void){return test("%+ .6g", 7.3);}
int bonus_g_assp_prec0n_ignoreflag(void){return test("%+ .0g", -7.3);}
int bonus_g_assp_prec1n_ignoreflag(void){return test("%+ .1g", -7.3);}
int bonus_g_assp_prec3n_ignoreflag(void){return test("%+ .3g", -7.3);}
int bonus_g_assp_prec6n_ignoreflag(void){return test("%+ .6g", -7.3);}
//General format with allsign and sp and rev flag order,~
int bonus_g_asspr_prec0p_ignoreflag(void){return test("% +.0g", 7.3);}
int bonus_g_asspr_prec1p_ignoreflag(void){return test("% +.1g", 7.3);}
int bonus_g_asspr_prec3p_ignoreflag(void){return test("% +.3g", 7.3);}
int bonus_g_asspr_prec6p_ignoreflag(void){return test("% +.6g", 7.3);}
int bonus_g_asspr_prec0n_ignoreflag(void){return test("% +.0g", -7.3);}
int bonus_g_asspr_prec1n_ignoreflag(void){return test("% +.1g", -7.3);}
int bonus_g_asspr_prec3n_ignoreflag(void){return test("% +.3g", -7.3);}
int bonus_g_asspr_prec6n_ignoreflag(void){return test("% +.6g", -7.3);}

//General format whose precision exceeds their compiled literal precision
int bonus_notrequired_g_overprec_might_be_undefbehav_100(void){return test("%.100g", 0.237);}
int bonus_notrequired_g_overprec_might_be_undefbehav_32(void){return test("%.32g", 0.237);}
int bonus_notrequired_g_overprec_might_be_undefbehav_4(void){return test("%.4g", 0.237);}
int bonus_notrequired_g_overprec_might_be_undefbehav_1000(void){return test("%.4g", -0.106577568068517810765107851705167);}
int bonus_notrequired_g_overprec_might_be_undefbehav_10_from_0(void){return test("%.10g", 0.0);}
int bonus_notrequired_g_overprec_might_be_undefbehav_2000(void){return test("%.2000g", 623.28376510723481);}
int bonus_notrequired_g_overprec_might_be_undefbehav_dblmin(void){return test("%.2000g", DBL_MIN);}
int bonus_notrequired_g_overprec_might_be_undefbehav_ndblmin(void){return test("%.2000g", -DBL_MIN);}
//General format at double max, double min
int bonus_notrequired_g_limits_dblmax_prec0(void){return test("%.0g", DBL_MAX);}
int bonus_notrequired_g_limits_dblmax_prec3(void){return test("%.3g", DBL_MAX);}
int bonus_notrequired_g_limits_dblmax_precd(void){return test("%g", DBL_MAX);}
int bonus_notrequired_g_limits_dblmax_prec8(void){return test("%.8g", DBL_MAX);}
int bonus_notrequired_g_stress_limits_dblmax_prec12(void){return test("%.12g", DBL_MAX);}
int bonus_notrequired_g_stress_limits_dblmax_prec16(void){return test("%.16g", DBL_MAX);}
int bonus_notrequired_g_stress_limits_dblmax_prec18(void){return test("%.18g", DBL_MAX);}
int bonus_notrequired_g_limits_ndblmax_prec0(void){return test("%.0g", -DBL_MAX);}
int bonus_notrequired_g_limits_ndblmax_prec3(void){return test("%.3g", -DBL_MAX);}
int bonus_notrequired_g_limits_ndblmax_precd(void){return test("%g", -DBL_MAX);}
int bonus_notrequired_g_limits_ndblmax_prec8(void){return test("%.8g", -DBL_MAX);}
int bonus_notrequired_g_stress_limits_ndblmax_prec12(void){return test("%.12g", -DBL_MAX);}
int bonus_notrequired_g_stress_limits_ndblmax_prec16(void){return test("%.16g", -DBL_MAX);}
int bonus_notrequired_g_stress_limits_ndblmax_prec18(void){return test("%.18g", -DBL_MAX);}
int bonus_notrequired_g_limits_dblmin_prec0(void){return test("%.0g", DBL_MIN);}
int bonus_notrequired_g_limits_dblmin_prec3(void){return test("%.3g", DBL_MIN);}
int bonus_notrequired_g_limits_dblmin_precd(void){return test("%g", DBL_MIN);}
int bonus_notrequired_g_limits_dblmin_prec8(void){return test("%.8g", DBL_MIN);}
int bonus_notrequired_g_stress_limits_dblmin_prec12(void){return test("%.12g", DBL_MIN);}
int bonus_notrequired_g_stress_limits_dblmin_prec16(void){return test("%.16g", DBL_MIN);}
int bonus_notrequired_g_stress_limits_dblmin_prec18(void){return test("%.18g", DBL_MIN);}
int bonus_notrequired_g_limits_ndblmin_prec0(void){return test("%.0g", -DBL_MIN);}
int bonus_notrequired_g_limits_ndblmin_prec3(void){return test("%.3g", -DBL_MIN);}
int bonus_notrequired_g_limits_ndblmin_precd(void){return test("%g", -DBL_MIN);}
int bonus_notrequired_g_limits_ndblmin_prec8(void){return test("%.8g", -DBL_MIN);}
int bonus_notrequired_g_stress_limits_ndblmin_prec12(void){return test("%.12g", -DBL_MIN);}
int bonus_notrequired_g_stress_limits_ndblmin_prec16(void){return test("%.16g", -DBL_MIN);}
int bonus_notrequired_g_stress_limits_ndblmin_prec18(void){return test("%.18g", -DBL_MIN);}
 //General format of special values
int bonus_notrequired_g_reserved_values_inf(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%g", special);}
int bonus_notrequired_g_reserved_values_ninf(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%g", special);}
int bonus_notrequired_g_reserved_values_nan(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%g", special);}
int bonus_notrequired_g_reserved_values_pzero(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%g", special);}
int bonus_notrequired_g_reserved_values_nzero(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%g", special);}
int bonus_notrequired_g_reserved_values_inf_6w(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%6g", special);}
int bonus_notrequired_g_reserved_values_ninf_6w(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%6g", special);}
int bonus_notrequired_g_reserved_values_nan_6w(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%6g", special);}
int bonus_notrequired_g_reserved_values_pzero_6w(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%6g", special);}
int bonus_notrequired_g_reserved_values_nzero_6w(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%6g", special);}
int bonus_notrequired_g_reserved_values_inf_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%-6g", special);}
int bonus_notrequired_g_reserved_values_ninf_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%-6g", special);}
int bonus_notrequired_g_reserved_values_nan_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%-6g", special);}
int bonus_notrequired_g_reserved_values_pzero_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%-6g", special);}
int bonus_notrequired_g_reserved_values_nzero_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%-6g", special);}
int bonus_notrequired_g_reserved_values_inf_6was(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%+6g", special);}
int bonus_notrequired_g_reserved_values_ninf_6was(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%+6g", special);}
int bonus_notrequired_g_reserved_values_nan_6was(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%+6g", special);}
int bonus_notrequired_g_reserved_values_pzero_6was(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%+6g", special);}
int bonus_notrequired_g_reserved_values_nzero_6was(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%+6g", special);}
int bonus_notrequired_g_reserved_values_inf_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%10.7g", special);}
int bonus_notrequired_g_reserved_values_ninf_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%10.7g", special);}
int bonus_notrequired_g_reserved_values_nan_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%10.7g", special);}
int bonus_notrequired_g_reserved_values_pzero_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%10.7g", special);}
int bonus_notrequired_g_reserved_values_nzero_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%10.7g", special);}
int bonus_notrequired_g_reserved_values_inf_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("% .7g", special);}
int bonus_notrequired_g_reserved_values_ninf_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("% .7g", special);}
int bonus_notrequired_g_reserved_values_nan_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("% .7g", special);}
int bonus_notrequired_g_reserved_values_pzero_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("% .7g", special);}
int bonus_notrequired_g_reserved_values_nzero_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("% .7g", special);}
int bonus_notrequired_g_reserved_values_inf_sp(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("% g", special);}
int bonus_notrequired_g_reserved_values_ninf_sp(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("% g", special);}
int bonus_notrequired_g_reserved_values_nan_sp(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("% g", special);}
int bonus_notrequired_g_reserved_values_pzero_sp(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("% g", special);}
int bonus_notrequired_g_reserved_values_nzero_sp(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("% g", special);}
int bonus_notrequired_g_reserved_values_inf_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%06g", special);}
int bonus_notrequired_g_reserved_values_ninf_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%06g", special);}
int bonus_notrequired_g_reserved_values_nan_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%06g", special);}
int bonus_notrequired_g_reserved_values_pzero_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%06g", special);}
int bonus_notrequired_g_reserved_values_nzero_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%06g", special);}


/* -----------------------------------------------------------------------------
** 						%e SCIENTIFIC NOTATION TESTS (BONUS)
** ---------------------------------------------------------------------------*/
//Scientific notation - Basic
int bonus_e_basic_1(void){return test("this %e scientific notation", 1.5);}
int bonus_e_basic_fltonly(void){return test("%e", 7.5);}
int bonus_e_basic_zero(void){return test("%e", 0.0);}
int bonus_e_basic_nzero(void){return test("%e", -0.0);}
int bonus_e_basic_whole(void){return test("%e", 1.0);}
int bonus_e_basic_negative(void){return test("%e", -3.85);}
int bonus_e_basic_positive_3_3(void){return test("%e", 573.924);}
int bonus_e_basic_negative_3_3(void){return test("%e", -958.125);}
int bonus_e_basic_positive_smallfpart(void){return test("%e", 23.00041);}
int bonus_e_basic_positive_allsmall(void){return test("%e", 0.000039);}
int bonus_e_basic_negative_smallfpart(void){return test("%e", -7.00036);}
int bonus_e_basic_negative_allsmall(void){return test("%e", -0.00032);}
int bonus_e_basic_limits_allsmall_pos(void){return test("%e", 0.000001);}
int bonus_e_basic_limits_allsmall_neg(void){return test("%e", -0.000001);}
int bonus_e_basic_limits_smallfpart_pos(void){return test("%e", 9873.000001);}
int bonus_e_basic_limits_smallfpart_neg(void){return test("%e", -875.000001);}
int bonus_e_basic_limits_allbig_pos(void){return test("%e", 999.999999);}
int bonus_e_basic_limits_allbig_neg(void){return test("%e", -99.999999);}
int bonus_e_basic_limits_bigfpart_pos(void){return test("%e", 0.999999);}
int bonus_e_basic_limits_bigfpart_neg(void){return test("%e", -0.999999);}
//Scientific notation - Rounding with default precision
int bonus_e_rndd_pos(void){return test("%e", 23.375094499);}
int bonus_e_rndd_neg(void){return test("%e", -985.765426499);}
int bonus_e_rndu_pos(void){return test("%e", 0.0894255);}
int bonus_e_rndu_neg(void){return test("%e", -56.2012685);}
int bonus_e_rndu_multidigit_pos(void){return test("%e", 43.4399999);}
int bonus_e_rndu_multidigit_neg(void){return test("%e", -5.0299999);}
int bonus_e_rndd_multidigit_pos(void){return test("%e", 43.43999949);}
int bonus_e_rndd_multidigit_neg(void){return test("%e", -5.02999949);}
int bonus_e_rndd_wholnobump_pos(void){return test("%e", 1.99999949);}
int bonus_e_rndd_wholnobump_neg(void){return test("%e", -0.99999949);}
int bonus_e_rndu_bumpwhole_pos(void){return test("%e", 3.9999999);}
int bonus_e_rndu_bumpwhole_neg(void){return test("%e", -5.9999999);}
//Scientific notation Prec 0
int bonus_e_prec0_zero(void){return test("%.0e", 0.0);}
int bonus_e_prec0_nzero(void){return test("%.0e", -0.0);}
int bonus_e_prec0_1(void){return test("this %.0e scientific notation", 1.6);}
int bonus_e_prec0_fltonly(void){return test("%.0e", 7.4);}
int bonus_e_prec0_whole(void){return test("%.0e", 1.0);}
int bonus_e_prec0_negative(void){return test("%.0e", -3.85);}
int bonus_e_prec0_positive_3_3(void){return test("%.0e", 573.924);}
int bonus_e_prec0_negative_3_3(void){return test("%.0e", -958.125);}
int bonus_e_prec0_positive_smallfpart(void){return test("%.0e", 23.00041);}
int bonus_e_prec0_positive_allsmall(void){return test("%.0e", 0.000039);}
int bonus_e_prec0_negative_smallfpart(void){return test("%.0e", -7.00036);}
int bonus_e_prec0_negative_allsmall(void){return test("%.0e", -0.00032);}
//Scientific notation Prec 1
int bonus_e_prec1_zero(void){return test("%.1e", 0.0);}
int bonus_e_prec1_nzero(void){return test("%.1e", -0.0);}
int bonus_e_prec1_1(void){return test("this %.1e scientific notation", 1.5);}
int bonus_e_prec1_fltonly(void){return test("%.1e", 7.5);}
int bonus_e_prec1_whole(void){return test("%.1e", 1.0);}
int bonus_e_prec1_negative(void){return test("%.1e", -3.85);}
int bonus_e_prec1_positive_3_3(void){return test("%.1e", 573.924);}
int bonus_e_prec1_negative_3_3(void){return test("%.1e", -958.125);}
int bonus_e_prec1_positive_smallfpart(void){return test("%.1e", 23.00041);}
int bonus_e_prec1_positive_allsmall(void){return test("%.1e", 0.000039);}
int bonus_e_prec1_negative_smallfpart(void){return test("%.1e", -7.00036);}
int bonus_e_prec1_negative_allsmall(void){return test("%.1e", -0.00032);}
//Scientific notation Prec 3
int bonus_e_prec3_zero(void){return test("%.3e", 0.0);}
int bonus_e_prec3_nzero(void){return test("%.3e", -0.0);}
int bonus_e_prec3_1(void){return test("this %.3e scientific notation", 1.5);}
int bonus_e_prec3_fltonly(void){return test("%.3e", 7.5);}
int bonus_e_prec3_whole(void){return test("%.3e", 1.0);}
int bonus_e_prec3_negative(void){return test("%.3e", -3.85);}
int bonus_e_prec3_positive_3_3(void){return test("%.3e", 573.924);}
int bonus_e_prec3_negative_3_3(void){return test("%.3e", -958.125);}
int bonus_e_prec3_positive_smallfpart(void){return test("%.3e", 23.00041);}
int bonus_e_prec3_positive_allsmall(void){return test("%.3e", 0.000039);}
int bonus_e_prec3_negative_smallfpart(void){return test("%.3e", -7.00036);}
int bonus_e_prec3_negative_allsmall(void){return test("%.3e", -0.00032);}
//Scientific notation - Prec 7
int bonus_e_prec7_zero(void){return test("%.7e", 0.0);}
int bonus_e_prec7_nzero(void){return test("%.7e", -0.0);}
int bonus_e_prec7_1(void){return test("this %.7e scientific notation", 1.5);}
int bonus_e_prec7_fltonly(void){return test("%.7e", 7.5);}
int bonus_e_prec7_whole(void){return test("%.7e", 1.0);}
int bonus_e_prec7_negative(void){return test("%.7e", -3.85);}
int bonus_e_prec7_positive_3_3(void){return test("%.7e", 573.924);}
int bonus_e_prec7_negative_3_3(void){return test("%.7e", -958.125);}
int bonus_e_prec7_positive_smallfpart(void){return test("%.7e", 23.00041);}
int bonus_e_prec7_positive_allsmall(void){return test("%.7e", 0.0000039);}
int bonus_e_prec7_negative_smallfpart(void){return test("%.7e", -7.00036);}
int bonus_e_prec7_negative_allsmall(void){return test("%.7e", -0.000032);}
int bonus_e_prec7_limits_allsmall_pos(void){return test("%.7e", 0.0000001);}
int bonus_e_prec7_limits_allsmall_neg(void){return test("%.7e", -0.0000001);}
int bonus_e_prec7_limits_smallfpart_pos(void){return test("%.7e", 9873.000001);}
int bonus_e_prec7_limits_smallfpart_neg(void){return test("%.7e", -875.000001);}
int bonus_e_prec7_limits_allbig_pos(void){return test("%.7e", 999.9999999);}
int bonus_e_prec7_limits_allbig_neg(void){return test("%.7e", -99.9999999);}
int bonus_e_prec7_limits_bigfpart_pos(void){return test("%.7e", 0.999999);}
int bonus_e_prec7_limits_bigfpart_neg(void){return test("%.7e", -0.999999);}
//Scientific notation - Prec 7 Rounding
int bonus_e_rnd_prec7_rndd_pos(void){return test("%.7e", 23.375094499);}
int bonus_e_rnd_prec7_rndd_neg(void){return test("%.7e", -985.765426499);}
int bonus_e_rnd_prec7_rndu_pos(void){return test("%.7e", 0.0894255);}
int bonus_e_rnd_prec7_rndu_neg(void){return test("%.7e", -56.2012685);}
int bonus_e_rnd_prec7_rndu_multidigit_pos(void){return test("%.7e", 43.4399999);}
int bonus_e_rnd_prec7_rndu_multidigit_neg(void){return test("%.7e", -5.0299999);}
int bonus_e_rnd_prec7_rndd_multidigit_pos(void){return test("%.7e", 43.43999949);}
int bonus_e_rnd_prec7_rndd_multidigit_neg(void){return test("%.7e", -5.02999949);}
int bonus_e_rnd_prec7_rndd_wholnobump_pos(void){return test("%.7e", 1.99999949);}
int bonus_e_rnd_prec7_rndd_wholnobump_neg(void){return test("%.7e", -0.99999949);}
int bonus_e_rnd_prec7_rndu_bumpwhole_pos(void){return test("%.7e", 3.9999999);}
//Scientific notation - Prec 8
int bonus_e_prec8_zero(void){return test("%.8e", 0.0);}
int bonus_e_prec8_nzero(void){return test("%.8e", -0.0);}
int bonus_e_prec8_1(void){return test("this %.8e scientific notation", 1.5);}
int bonus_e_prec8_fltonly(void){return test("%.8e", 7.5);}
int bonus_e_prec8_whole(void){return test("%.8e", 1.0);}
int bonus_e_prec8_negative(void){return test("%.8e", -3.85);}
int bonus_e_prec8_positive_3_3(void){return test("%.8e", 573.924);}
int bonus_e_prec8_negative_3_3(void){return test("%.8e", -958.125);}
int bonus_e_prec8_positive_smallfpart(void){return test("%.8e", 23.00041);}
int bonus_e_prec8_positive_allsmall(void){return test("%.8e", 0.00000039);}
int bonus_e_prec8_negative_smallfpart(void){return test("%.8e", -7.00036);}
int bonus_e_prec8_negative_allsmall(void){return test("%.8e", -0.0000032);}
int bonus_e_prec8_limits_allsmall_pos(void){return test("%.8e", 0.00000001);}
int bonus_e_prec8_limits_allsmall_neg(void){return test("%.8e", -0.00000001);}
int bonus_e_prec8_limits_smallfpart_pos(void){return test("%.8e", 9873.000001);}
int bonus_e_prec8_limits_smallfpart_neg(void){return test("%.8e", -875.000001);}
int bonus_e_prec8_limits_allbig_pos(void){return test("%.8e", 999.9999999);}
int bonus_e_prec8_limits_allbig_neg(void){return test("%.8e", -99.99999999);}
int bonus_e_prec8_limits_bigfpart_pos(void){return test("%.8e", 0.999999);}
int bonus_e_prec8_limits_bigfpart_neg(void){return test("%.8e", -0.999999);}
//Scientific notation - Prec 8 Rounding
int bonus_e_rnd_prec8_rndd_pos(void){return test("%.8e", 23.375094499);}
int bonus_e_rnd_prec8_rndd_neg(void){return test("%.8e", -985.765426499);}
int bonus_e_rnd_prec8_rndu_pos(void){return test("%.8e", 0.0894255);}
int bonus_e_rnd_prec8_rndu_neg(void){return test("%.8e", -56.2012685);}
int bonus_e_rnd_prec8_rndu_multidigit_pos(void){return test("%.8e", 43.4399999);}
int bonus_e_rnd_prec8_rndu_multidigit_neg(void){return test("%.8e", -5.0299999);}
int bonus_e_rnd_prec8_rndd_multidigit_pos(void){return test("%.8e", 43.43999949);}
int bonus_e_rnd_prec8_rndd_multidigit_neg(void){return test("%.8e", -5.02999949);}
int bonus_e_rnd_prec8_rndd_wholnobump_pos(void){return test("%.8e", 1.99999949);}
int bonus_e_rnd_prec8_rndd_wholnobump_neg(void){return test("%.8e", -0.99999949);}
int bonus_e_rnd_prec8_rndu_bumpwhole_pos(void){return test("%.8e", 3.9999999);}
//Scientific notation - Prec 9
int bonus_e_prec9_zero(void){return test("%.9e", 0.0);}
int bonus_e_prec9_nzero(void){return test("%.9e", -0.0);}
int bonus_e_stress_prec9_1(void){return test("this %.9e scientific notation", 1.5);}
int bonus_e_stress_prec9_fltonly(void){return test("%.9e", 7.5);}
int bonus_e_stress_prec9_whole(void){return test("%.9e", 1.0);}
int bonus_e_stress_prec9_negative(void){return test("%.9e", -3.85);}
int bonus_e_stress_prec9_positive_3_3(void){return test("%.9e", 573.924);}
int bonus_e_stress_prec9_negative_3_3(void){return test("%.9e", -958.125);}
int bonus_e_stress_prec9_positive_smallfpart(void){return test("%.9e", 23.00041);}
int bonus_e_stress_prec9_positive_allsmall(void){return test("%.9e", 0.00000039);}
int bonus_e_stress_prec9_negative_smallfpart(void){return test("%.9e", -7.00036);}
int bonus_e_stress_prec9_negative_allsmall(void){return test("%.9e", -0.0000032);}
int bonus_e_stress_prec9_limits_allsmall_pos(void){return test("%.9e", 0.00000001);}
int bonus_e_stress_prec9_limits_allsmall_neg(void){return test("%.9e", -0.00000001);}
int bonus_e_stress_prec9_limits_smallfpart_pos(void){return test("%.9e", 9873.000001);}
int bonus_e_stress_prec9_limits_smallfpart_neg(void){return test("%.9e", -875.000001);}
int bonus_e_stress_prec9_limits_allbig_pos(void){return test("%.9e", 999.99999999);}
int bonus_e_stress_prec9_limits_allbig_neg(void){return test("%.9e", -99.99999999);}
int bonus_e_stress_prec9_limits_bigfpart_pos(void){return test("%.9e", 0.999999);}
int bonus_e_stress_prec9_limits_bigfpart_neg(void){return test("%.9e", -0.999999);}
//Scientific notation - Prec 9 Rounding
int bonus_e_stress_prec9_rndd_pos(void){return test("%.9e", 23.375094499);}
int bonus_e_stress_prec9_rndd_neg(void){return test("%.9e", -985.765426499);}
int bonus_e_stress_prec9_rndu_pos(void){return test("%.9e", 0.0894255);}
int bonus_e_stress_prec9_rndu_neg(void){return test("%.9e", -56.2012685);}
int bonus_e_stress_prec9_rndu_multidigit_pos(void){return test("%.9e", 43.4399999);}
int bonus_e_stress_prec9_rndu_multidigit_neg(void){return test("%.9e", -5.0299999);}
int bonus_e_stress_prec9_rndd_multidigit_pos(void){return test("%.9e", 43.43999949);}
int bonus_e_stress_prec9_rndd_multidigit_neg(void){return test("%.9e", -5.02999949);}
int bonus_e_stress_prec9_rndd_wholnobump_pos(void){return test("%.9e", 1.99999949);}
int bonus_e_stress_prec9_rndd_wholnobump_neg(void){return test("%.9e", -0.99999949);}
int bonus_e_stress_prec9_rndu_bumpwhole_pos(void){return test("%.9e", 3.9999999);}
//Scientific notation - Prec 10
int bonus_e_prec10_zero(void){return test("%.10e", 0.0);}
int bonus_e_prec10_nzero(void){return test("%.10e", -0.0);}
int bonus_e_stress_prec10_1(void){return test("this %.10e scientific notation", 1.5);}
int bonus_e_stress_prec10_fltonly(void){return test("%.10e", 7.5);}
int bonus_e_stress_prec10_whole(void){return test("%.10e", 1.0);}
int bonus_e_stress_prec10_negative(void){return test("%.10e", -3.85);}
int bonus_e_stress_prec10_positive_3_10(void){return test("%.10e", 573.924);}
int bonus_e_stress_prec10_negative_3_10(void){return test("%.10e", -958.125);}
int bonus_e_stress_prec10_pos(void){return test("%.10e", 23.8341375094);}
int bonus_e_stress_prec10_neg(void){return test("%.10e", -985.2459765426);}
int bonus_e_stress_prec10_rndd_pos(void){return test("%.10e", 23.8341375094499);}
int bonus_e_stress_prec10_rndd_neg(void){return test("%.10e", -985.2459765426499);}
int bonus_e_stress_prec10_rndu_pos(void){return test("%.10e", 0.87650894255);}
int bonus_e_stress_prec10_rndu_neg(void){return test("%.10e", -56.47852012685);}
int bonus_e_stress_prec10_positive_smallfpart(void){return test("%.10e", 23.000000041);}
int bonus_e_stress_prec10_positive_allsmall(void){return test("%.10e", 0.0000000039);}
int bonus_e_stress_prec10_negative_smallfpart(void){return test("%.10e", -7.000000036);}
int bonus_e_stress_prec10_negative_allsmall(void){return test("%.10e", -0.000000032);}
int bonus_e_stress_prec10_limits_allsmall_pos(void){return test("%.10e", 0.0000000001);}
int bonus_e_stress_prec10_limits_allsmall_neg(void){return test("%.10e", -0.0000000001);}
int bonus_e_stress_prec10_limits_smallfpart_pos(void){return test("%.10e", 9873.0000000001);}
int bonus_e_stress_prec10_limits_smallfpart_neg(void){return test("%.10e", -875.0000000001);}
int bonus_e_stress_prec10_limits_allbig_pos(void){return test("%.10e", 999.9999999999);}
int bonus_e_stress_prec10_limits_allbig_neg(void){return test("%.10e", -99.9999999999);}
int bonus_e_stress_prec10_limits_bigfpart_pos(void){return test("%.10e", 0.9999999999);}
int bonus_e_stress_prec10_limits_bigfpart_neg(void){return test("%.10e", -0.9999999999);}
//Scientific notation - Prec 11
int bonus_e_stress_prec11_rndu(void){return test("%.11e",        1.025978541236587568);}
int bonus_e_stress_prec11_rndd(void){return test("%.11e",        1.025978548534310421);}
int bonus_e_stress_prec11_limits_tiny(void){return test("%.11e", 0.000000000010000000);}
int bonus_e_stress_prec11_limits_big(void){return test("%.11e", 99.999999999990000000);}
//Scientific notation - Prec 12
int bonus_e_stress_prec12_rndu(void){return test("%.12e",        1.025978541236587568);}
int bonus_e_stress_prec12_rndd(void){return test("%.12e",        1.025978548534310421);}
int bonus_e_stress_prec12_limits_tiny(void){return test("%.12e", 0.000000000001000000);}
int bonus_e_stress_prec12_limits_big(void){return test("%.12e", 99.999999999999000000);}
//Scientific notation - Prec 13
int bonus_e_stress_prec13_rndu(void){return test("%.13e",        1.025978541136587568);}
int bonus_e_stress_prec13_rndd(void){return test("%.13e",        1.025978548534310421);}
int bonus_e_stress_prec13_limits_tiny(void){return test("%.13e", 0.000000000000100000);}
int bonus_e_stress_prec13_limits_big(void){return test("%.13e", 99.999999999999900000);}
//Scientific notation - Prec 14
int bonus_e_stress_prec14_rndu(void){return test("%.14e",        1.025978541436587568);}
int bonus_e_stress_prec14_rndd(void){return test("%.14e",        1.025978548534310421);}
int bonus_e_stress_prec14_limits_tiny(void){return test("%.14e", 0.000000000000010000);}
int bonus_e_stress_prec14_limits_big(void){return test("%.14e",  9.999999999999990000);}
//Scientific notation - Prec 15
int bonus_e_stress_prec15_rndu(void){return test("%.15e",        1.025978542436587568);}
int bonus_e_stress_prec15_rndd(void){return test("%.15e",        1.025978548534310421);}
int bonus_e_stress_prec15_limits_tiny(void){return test("%.15e", 0.000000000000001000);}
int bonus_e_stress_prec15_limits_big(void){return test("%.15e",  0.999999999999999000);}
 //Scientific notation - Prec 16
int bonus_notrequired_e_stress_prec16_rndu(void){return test("%.16e",        1.025978542436587568);}
int bonus_notrequired_e_stress_prec16_rndd(void){return test("%.16e",        1.025978548534310421);}
int bonus_notrequired_e_stress_prec16_limits_tiny(void){return test("%.16e", 0.000000000000000100);}
int bonus_notrequired_e_stress_prec16_limits_big(void){return test("%.16e",  0.999999999999999900);}
//Scientific notation - Prec 17
int bonus_notrequired_e_stress_prec17_rndu(void){return test("%.17e",        1.025978542436587568);}
int bonus_notrequired_e_stress_prec17_rndd(void){return test("%.17e",        1.025978548534310421);}
int bonus_notrequired_e_stress_prec17_limits_tiny(void){return test("%.17e", 0.000000000000000010);}
int bonus_notrequired_e_stress_prec17_limits_big(void){return test("%.17e",  0.999999999999999990);}
//Scientific notation - Prec 18
int bonus_notrequired_e_stress_prec18_rndu(void){return test("%.18e",        0.125978542436587568);}
int bonus_notrequired_e_stress_prec18_rndd(void){return test("%.18e",        0.125978548534310421);}
//Scientific notation with altform,~
int bonus_e_af_prec0_zero(void){return test("%#.0e", 0.0);}
int bonus_e_af_prec0_nzero(void){return test("%#.0e", -0.0);}
int bonus_e_af_prec1_zero(void){return test("%#.1e", 0.0);}
int bonus_e_af_prec1_nzero(void){return test("%#.1e", -0.0);}
int bonus_e_af_prec0p(void){return test("%#.0e", 7.4);}
int bonus_e_af_prec1p(void){return test("%#.1e", 7.3);}
int bonus_e_af_prec0n(void){return test("%#.0e", -7.4);}
int bonus_e_af_prec1n(void){return test("%#.1e", -7.3);}
//Scientific notation with allsign,~
int bonus_e_as_prec0_zero(void){return test("%+.0e", 0.0);}
int bonus_e_as_prec0_nzero(void){return test("%+.0e", -0.0);}
int bonus_e_as_prec3_zero(void){return test("%+.3e", 0.0);}
int bonus_e_as_prec3_nzero(void){return test("%+.3e", -0.0);}
int bonus_e_as_prec0p_as(void){return test("%+.0e", 7.4);}
int bonus_e_as_prec3p_as(void){return test("%+.3e", 7.3);}
int bonus_e_as_prec0n_as(void){return test("%+.0e", -7.4);}
int bonus_e_as_prec3n_as(void){return test("%+.3e", -7.3);}
//Scientific notation with field width,~
int bonus_e_wprec0p_zero(void){return test("%5.0e", 0.0);}
int bonus_e_wprec0p_nzero(void){return test("%5.0e", -0.0);}
int bonus_e_wprec3p_zero(void){return test("%5.3e", 0.0);}
int bonus_e_wprec3p_nzero(void){return test("%5.3e", -0.0);}
int bonus_e_wprec0p(void){return test("%5.0e", 7.3);}
int bonus_e_wprec1p(void){return test("%5.1e", 7.3);}
int bonus_e_wprec3p(void){return test("%5.3e", 7.3);}
int bonus_e_wprec6p(void){return test("%5.6e", 7.3);}
int bonus_e_wprec0n(void){return test("%5.0e", -7.3);}
int bonus_e_wprec1n(void){return test("%5.1e", -7.3);}
int bonus_e_wprec3n(void){return test("%5.3e", -7.3);}
int bonus_e_wprec6n(void){return test("%5.6e", -7.3);}
//Scientific notation with field width and zero padding,~
int bonus_e_wzp_prec0p_zero(void){return test("%05.0e", 0.0);}
int bonus_e_wzp_prec0p_nzero(void){return test("%05.0e", -0.0);}
int bonus_e_wzp_prec3p_zero(void){return test("%05.3e", 0.0);}
int bonus_e_wzp_prec3p_nzero(void){return test("%05.3e", -0.0);}
int bonus_e_wzp_prec0p(void){return test("%05.0e", 7.3);}
int bonus_e_wzp_prec1p(void){return test("%05.1e", 7.3);}
int bonus_e_wzp_prec3p(void){return test("%05.3e", 7.3);}
int bonus_e_wzp_prec6p(void){return test("%05.6e", 7.3);}
int bonus_e_wzp_prec0n(void){return test("%05.0e", -7.3);}
int bonus_e_wzp_prec1n(void){return test("%05.1e", -7.3);}
int bonus_e_wzp_prec3n(void){return test("%05.3e", -7.3);}
int bonus_e_wzp_prec6n(void){return test("%05.6e", -7.3);}
//Scientific notation with field width and left justify,~
int bonus_e_wlj_prec0p_zero(void){return test("%-5.0e", 0.0);}
int bonus_e_wlj_prec0p_nzero(void){return test("%-5.0e", -0.0);}
int bonus_e_wlj_prec3p_zero(void){return test("%-5.3e", 0.0);}
int bonus_e_wlj_prec3p_nzero(void){return test("%-5.3e", -0.0);}
int bonus_e_wlj_prec0p(void){return test("%-5.0e", 7.3);}
int bonus_e_wlj_prec1p(void){return test("%-5.1e", 7.3);}
int bonus_e_wlj_prec3p(void){return test("%-5.3e", 7.3);}
int bonus_e_wlj_prec6p(void){return test("%-5.6e", 7.3);}
int bonus_e_wlj_prec0n(void){return test("%-5.0e", -7.3);}
int bonus_e_wlj_prec1n(void){return test("%-5.1e", -7.3);}
int bonus_e_wlj_prec3n(void){return test("%-5.3e", -7.3);}
int bonus_e_wlj_prec6n(void){return test("%-5.6e", -7.3);}
//Scientific notation with field width and zero padding and left justify,~
int bonus_e_wzplj_prec0p_ignoreflag_zero(void){return test("%-05.0e", 0.0);}
int bonus_e_wzplj_prec0p_ignoreflag_nzero(void){return test("%-05.0e", -0.0);}
int bonus_e_wzplj_prec3p_ignoreflag_zero(void){return test("%-05.3e", 0.0);}
int bonus_e_wzplj_prec3p_ignoreflag_nzero(void){return test("%-05.3e", -0.0);}
int bonus_e_wzplj_prec0p_ignoreflag(void){return test("%-05.0e", 7.3);}
int bonus_e_wzplj_prec1p_ignoreflag(void){return test("%-05.1e", 7.3);}
int bonus_e_wzplj_prec3p_ignoreflag(void){return test("%-05.3e", 7.3);}
int bonus_e_wzplj_prec6p_ignoreflag(void){return test("%-05.6e", 7.3);}
int bonus_e_wzplj_prec0n_ignoreflag(void){return test("%-05.0e", -7.3);}
int bonus_e_wzplj_prec1n_ignoreflag(void){return test("%-05.1e", -7.3);}
int bonus_e_wzplj_prec3n_ignoreflag(void){return test("%-05.3e", -7.3);}
int bonus_e_wzplj_prec6n_ignoreflag(void){return test("%-05.6e", -7.3);}
//Scientific notation with field width and zero padding and left justify, rev f order,~
int bonus_e_wzpljr_prec0p_ignoreflag_zero(void){return test("%0-5.0e", 0.0);}
int bonus_e_wzpljr_prec0p_ignoreflag_nzero(void){return test("%0-5.0e", -0.0);}
int bonus_e_wzpljr_prec3p_ignoreflag_zero(void){return test("%0-5.3e", 0.0);}
int bonus_e_wzpljr_prec3p_ignoreflag_nzero(void){return test("%0-5.3e", -0.0);}
int bonus_e_wzpljr_prec0p_ignoreflag(void){return test("%0-5.0e", 7.3);}
int bonus_e_wzpljr_prec1p_ignoreflag(void){return test("%0-5.1e", 7.3);}
int bonus_e_wzpljr_prec3p_ignoreflag(void){return test("%0-5.3e", 7.3);}
int bonus_e_wzpljr_prec6p_ignoreflag(void){return test("%0-5.6e", 7.3);}
int bonus_e_wzpljr_prec0n_ignoreflag(void){return test("%0-5.0e", -7.3);}
int bonus_e_wzpljr_prec1n_ignoreflag(void){return test("%0-5.1e", -7.3);}
int bonus_e_wzpljr_prec3n_ignoreflag(void){return test("%0-5.3e", -7.3);}
int bonus_e_wzpljr_prec6n_ignoreflag(void){return test("%0-5.6e", -7.3);}
//Scientific notation with field width and left justify and altform,~
int bonus_e_wzpljaf_prec0p_zero(void){return test("%#-5.0e", 0.0);}
int bonus_e_wzpljaf_prec0p_nzero(void){return test("%#-5.0e", -0.0);}
int bonus_e_wzpljaf_prec3p_zero(void){return test("%#-5.3e", 0.0);}
int bonus_e_wzpljaf_prec3p_nzero(void){return test("%#-5.3e", -0.0);}
int bonus_e_wzpljaf_prec0p(void){return test("%#-5.0e", 7.3);}
int bonus_e_wzpljaf_prec1p(void){return test("%#-5.1e", 7.3);}
int bonus_e_wzpljaf_prec3p(void){return test("%#-5.3e", 7.3);}
int bonus_e_wzpljaf_prec6p(void){return test("%#-5.6e", 7.3);}
int bonus_e_wzpljaf_prec0n(void){return test("%#-5.0e", -7.3);}
int bonus_e_wzpljaf_prec1n(void){return test("%#-5.1e", -7.3);}
int bonus_e_wzpljaf_prec3n(void){return test("%#-5.3e", -7.3);}
int bonus_e_wzpljaf_prec6n(void){return test("%#-5.6e", -7.3);}
//Scientific notation with field width and allsign,~
int bonus_e_was_prec0p_zero(void){return test("%+5.0e", 0.0);}
int bonus_e_was_prec0p_nzero(void){return test("%+5.0e", -0.0);}
int bonus_e_was_prec3p_zero(void){return test("%+5.3e", 0.0);}
int bonus_e_was_prec3p_nzero(void){return test("%+5.3e", -0.0);}
int bonus_e_was_prec0p(void){return test("%+5.0e", 7.3);}
int bonus_e_was_prec1p(void){return test("%+5.1e", 7.3);}
int bonus_e_was_prec3p(void){return test("%+5.3e", 7.3);}
int bonus_e_was_prec6p(void){return test("%+5.6e", 7.3);}
int bonus_e_was_prec0n(void){return test("%+5.0e", -7.3);}
int bonus_e_was_prec1n(void){return test("%+5.1e", -7.3);}
int bonus_e_was_prec3n(void){return test("%+5.3e", -7.3);}
int bonus_e_was_prec6n(void){return test("%+5.6e", -7.3);}
//Scientific notation with field width and zero padding and allsign,~
int bonus_e_wzpas_prec0p_zero(void){return test("%+05.0e", 0.0);}
int bonus_e_wzpas_prec0p_nzero(void){return test("%+05.0e", -0.0);}
int bonus_e_wzpas_prec3p_zero(void){return test("%+05.3e", 0.0);}
int bonus_e_wzpas_prec3p_nzero(void){return test("%+05.3e", -0.0);}
int bonus_e_wzpas_prec0p(void){return test("%+05.0e", 7.3);}
int bonus_e_wzpas_prec1p(void){return test("%+05.1e", 7.3);}
int bonus_e_wzpas_prec3p(void){return test("%+05.3e", 7.3);}
int bonus_e_wzpas_prec6p(void){return test("%+05.6e", 7.3);}
int bonus_e_wzpas_prec0n(void){return test("%+05.0e", -7.3);}
int bonus_e_wzpas_prec1n(void){return test("%+05.1e", -7.3);}
int bonus_e_wzpas_prec3n(void){return test("%+05.3e", -7.3);}
int bonus_e_wzpas_prec6n(void){return test("%+05.6e", -7.3);}
//Scientific notation with field width and left justify and allsign,~
int bonus_e_wljas_prec0p_zero(void){return test("%+-5.0e", 0.0);}
int bonus_e_wljas_prec0p_nzero(void){return test("%+-5.0e", -0.0);}
int bonus_e_wljas_prec3p_zero(void){return test("%+-5.3e", 0.0);}
int bonus_e_wljas_prec3p_nzero(void){return test("%+-5.3e", -0.0);}
int bonus_e_wljas_prec0p(void){return test("%+-5.0e", 7.3);}
int bonus_e_wljas_prec1p(void){return test("%+-5.1e", 7.3);}
int bonus_e_wljas_prec3p(void){return test("%+-5.3e", 7.3);}
int bonus_e_wljas_prec6p(void){return test("%+-5.6e", 7.3);}
int bonus_e_wljas_prec0n(void){return test("%+-5.0e", -7.3);}
int bonus_e_wljas_prec1n(void){return test("%+-5.1e", -7.3);}
int bonus_e_wljas_prec3n(void){return test("%+-5.3e", -7.3);}
int bonus_e_wljas_prec6n(void){return test("%+-5.6e", -7.3);}
//Scientific notation with field width and zero padding and left justify and allsign,~
int bonus_e_wzpljas_prec0p_ignoreflag_zero(void){return test("%+-05.0e", 0.0);}
int bonus_e_wzpljas_prec0p_ignoreflag_nzero(void){return test("%+-05.0e", -0.0);}
int bonus_e_wzpljas_prec3p_ignoreflag_zero(void){return test("%+-05.3e", 0.0);}
int bonus_e_wzpljas_prec3p_ignoreflag_nzero(void){return test("%+-05.3e", -0.0);}
int bonus_e_wzpljas_prec0p_ignoreflag(void){return test("%+-05.0e", 7.3);}
int bonus_e_wzpljas_prec1p_ignoreflag(void){return test("%+-05.1e", 7.3);}
int bonus_e_wzpljas_prec3p_ignoreflag(void){return test("%+-05.3e", 7.3);}
int bonus_e_wzpljas_prec6p_ignoreflag(void){return test("%+-05.6e", 7.3);}
int bonus_e_wzpljas_prec0n_ignoreflag(void){return test("%+-05.0e", -7.3);}
int bonus_e_wzpljas_prec1n_ignoreflag(void){return test("%+-05.1e", -7.3);}
int bonus_e_wzpljas_prec3n_ignoreflag(void){return test("%+-05.3e", -7.3);}
int bonus_e_wzpljas_prec6n_ignoreflag(void){return test("%+-05.6e", -7.3);}
//Scientific notation with field width left justify, rev f order and allsign,~
int bonus_e_wzpljras_prec0p_zero(void){return test("%+-05.0e", 0.0);}
int bonus_e_wzpljras_prec0p_nzero(void){return test("%+-05.0e", -0.0);}
int bonus_e_wzpljras_prec3p_zero(void){return test("%+-05.3e", 0.0);}
int bonus_e_wzpljras_prec3p_nzero(void){return test("%+-05.3e", -0.0);}
int bonus_e_wzpljras_prec0p(void){return test("%-+5.0e", 7.3);}
int bonus_e_wzpljras_prec1p(void){return test("%-+5.1e", 7.3);}
int bonus_e_wzpljras_prec3p(void){return test("%-+5.3e", 7.3);}
int bonus_e_wzpljras_prec6p(void){return test("%-+5.6e", 7.3);}
int bonus_e_wzpljras_prec0n(void){return test("%-+5.0e", -7.3);}
int bonus_e_wzpljras_prec1n(void){return test("%-+5.1e", -7.3);}
int bonus_e_wzpljras_prec3n(void){return test("%-+5.3e", -7.3);}
int bonus_e_wzpljras_prec6n(void){return test("%-+5.6e", -7.3);}
//Scientific notation with field width and left justify and altform and allsign,~
int bonus_e_wzpljafas_prec0p_zero(void){return test("%+#-05.0e", 0.0);}
int bonus_e_wzpljafas_prec0p_nzero(void){return test("%+#-05.0e", -0.0);}
int bonus_e_wzpljafas_prec3p_zero(void){return test("%+#-05.3e", 0.0);}
int bonus_e_wzpljafas_prec3p_nzero(void){return test("%+#-05.3e", -0.0);}
int bonus_e_wzpljafas_prec0p(void){return test("%+#-5.0e", 7.3);}
int bonus_e_wzpljafas_prec1p(void){return test("%+#-5.1e", 7.3);}
int bonus_e_wzpljafas_prec3p(void){return test("%+#-5.3e", 7.3);}
int bonus_e_wzpljafas_prec6p(void){return test("%+#-5.6e", 7.3);}
int bonus_e_wzpljafas_prec0n(void){return test("%+#-5.0e", -7.3);}
int bonus_e_wzpljafas_prec1n(void){return test("%+#-5.1e", -7.3);}
int bonus_e_wzpljafas_prec3n(void){return test("%+#-5.3e", -7.3);}
int bonus_e_wzpljafas_prec6n(void){return test("%+#-5.6e", -7.3);}
//Scientific notation with field width and sp,~
int bonus_e_wsp_prec0p_zero(void){return test("% 5.0e", 0.0);}
int bonus_e_wsp_prec0p_nzero(void){return test("% 5.0e", -0.0);}
int bonus_e_wsp_prec3p_zero(void){return test("% 5.3e", 0.0);}
int bonus_e_wsp_prec3p_nzero(void){return test("% 5.3e", -0.0);}
int bonus_e_wsp_prec0p(void){return test("% 5.0e", 7.3);}
int bonus_e_wsp_prec1p(void){return test("% 5.1e", 7.3);}
int bonus_e_wsp_prec3p(void){return test("% 5.3e", 7.3);}
int bonus_e_wsp_prec6p(void){return test("% 5.6e", 7.3);}
int bonus_e_wsp_prec0n(void){return test("% 5.0e", -7.3);}
int bonus_e_wsp_prec1n(void){return test("% 5.1e", -7.3);}
int bonus_e_wsp_prec3n(void){return test("% 5.3e", -7.3);}
int bonus_e_wsp_prec6n(void){return test("% 5.6e", -7.3);}
//Scientific notation with field width and zero padding and sp,~
int bonus_e_wzpsp_prec0p_zero(void){return test("% 05.0e", 0.0);}
int bonus_e_wzpsp_prec0p_nzero(void){return test("% 05.0e", -0.0);}
int bonus_e_wzpsp_prec3p_zero(void){return test("% 05.3e", 0.0);}
int bonus_e_wzpsp_prec3p_nzero(void){return test("% 05.3e", -0.0);}
int bonus_e_wzpsp_prec0p(void){return test("% 05.0e", 7.3);}
int bonus_e_wzpsp_prec1p(void){return test("% 05.1e", 7.3);}
int bonus_e_wzpsp_prec3p(void){return test("% 05.3e", 7.3);}
int bonus_e_wzpsp_prec6p(void){return test("% 05.6e", 7.3);}
int bonus_e_wzpsp_prec0n(void){return test("% 05.0e", -7.3);}
int bonus_e_wzpsp_prec1n(void){return test("% 05.1e", -7.3);}
int bonus_e_wzpsp_prec3n(void){return test("% 05.3e", -7.3);}
int bonus_e_wzpsp_prec6n(void){return test("% 05.6e", -7.3);}
//Scientific notation with field width and left justify and sp,~
int bonus_e_wljsp_prec0p_zero(void){return test("% -5.0e", 0.0);}
int bonus_e_wljsp_prec0p_nzero(void){return test("% -5.0e", -0.0);}
int bonus_e_wljsp_prec3p_zero(void){return test("% -5.3e", 0.0);}
int bonus_e_wljsp_prec3p_nzero(void){return test("% -5.3e", -0.0);}
int bonus_e_wljsp_prec0p(void){return test("% -5.0e", 7.3);}
int bonus_e_wljsp_prec1p(void){return test("% -5.1e", 7.3);}
int bonus_e_wljsp_prec3p(void){return test("% -5.3e", 7.3);}
int bonus_e_wljsp_prec6p(void){return test("% -5.6e", 7.3);}
int bonus_e_wljsp_prec0n(void){return test("% -5.0e", -7.3);}
int bonus_e_wljsp_prec1n(void){return test("% -5.1e", -7.3);}
int bonus_e_wljsp_prec3n(void){return test("% -5.3e", -7.3);}
int bonus_e_wljsp_prec6n(void){return test("% -5.6e", -7.3);}
//Scientific notation with field width and zero padding and left justify and sp,~
int bonus_e_wzpljsp_prec0p_zero(void){return test("% -05.0e", 0.0);}
int bonus_e_wzpljsp_prec0p_nzero(void){return test("% -05.0e", -0.0);}
int bonus_e_wzpljsp_prec3p_zero(void){return test("% -05.3e", 0.0);}
int bonus_e_wzpljsp_prec3p_nzero(void){return test("% -05.3e", -0.0);}
int bonus_e_wzpljsp_prec0p_ignoreflag(void){return test("% -05.0e", 7.3);}
int bonus_e_wzpljsp_prec1p_ignoreflag(void){return test("% -05.1e", 7.3);}
int bonus_e_wzpljsp_prec3p_ignoreflag(void){return test("% -05.3e", 7.3);}
int bonus_e_wzpljsp_prec6p_ignoreflag(void){return test("% -05.6e", 7.3);}
int bonus_e_wzpljsp_prec0n_ignoreflag(void){return test("% -05.0e", -7.3);}
int bonus_e_wzpljsp_prec1n_ignoreflag(void){return test("% -05.1e", -7.3);}
int bonus_e_wzpljsp_prec3n_ignoreflag(void){return test("% -05.3e", -7.3);}
int bonus_e_wzpljsp_prec6n_ignoreflag(void){return test("% -05.6e", -7.3);}
//Scientific notation with field width left justify, rev f order and sp,~
int bonus_e_wzpljrsp_prec0p_zero(void){return test("%- 5.0e", 0.0);}
int bonus_e_wzpljrsp_prec0p_nzero(void){return test("%- 5.0e", -0.0);}
int bonus_e_wzpljrsp_prec3p_zero(void){return test("%- 5.3e", 0.0);}
int bonus_e_wzpljrsp_prec3p_nzero(void){return test("%- 5.3e", -0.0);}
int bonus_e_wzpljrsp_prec0p(void){return test("%- 5.0e", 7.3);}
int bonus_e_wzpljrsp_prec1p(void){return test("%- 5.1e", 7.3);}
int bonus_e_wzpljrsp_prec3p(void){return test("%- 5.3e", 7.3);}
int bonus_e_wzpljrsp_prec6p(void){return test("%- 5.6e", 7.3);}
int bonus_e_wzpljrsp_prec0n(void){return test("%- 5.0e", -7.3);}
int bonus_e_wzpljrsp_prec1n(void){return test("%- 5.1e", -7.3);}
int bonus_e_wzpljrsp_prec3n(void){return test("%- 5.3e", -7.3);}
int bonus_e_wzpljrsp_prec6n(void){return test("%- 5.6e", -7.3);}
//Scientific notation with field width and left justify and altform and sp,~
int bonus_e_wzpljafsp_prec0p_zero(void){return test("% #-05.0e", 0.0);}
int bonus_e_wzpljafsp_prec0p_nzero(void){return test("% #-05.0e", -0.0);}
int bonus_e_wzpljafsp_prec3p_zero(void){return test("% #-05.3e", 0.0);}
int bonus_e_wzpljafsp_prec3p_nzero(void){return test("% #-05.3e", -0.0);}
int bonus_e_wzpljafsp_prec0p(void){return test("% #-5.0e", 7.3);}
int bonus_e_wzpljafsp_prec1p(void){return test("% #-5.1e", 7.3);}
int bonus_e_wzpljafsp_prec3p(void){return test("% #-5.3e", 7.3);}
int bonus_e_wzpljafsp_prec6p(void){return test("% #-5.6e", 7.3);}
int bonus_e_wzpljafsp_prec0n(void){return test("% #-5.0e", -7.3);}
int bonus_e_wzpljafsp_prec1n(void){return test("% #-5.1e", -7.3);}
int bonus_e_wzpljafsp_prec3n(void){return test("% #-5.3e", -7.3);}
int bonus_e_wzpljafsp_prec6n(void){return test("% #-5.6e", -7.3);}
//Scientific notation with allsign and sp,~
int bonus_e_assp_prec0p_ignoreflag(void){return test("%+ .0e", 7.3);}
int bonus_e_assp_prec1p_ignoreflag(void){return test("%+ .1e", 7.3);}
int bonus_e_assp_prec3p_ignoreflag(void){return test("%+ .3e", 7.3);}
int bonus_e_assp_prec6p_ignoreflag(void){return test("%+ .6e", 7.3);}
int bonus_e_assp_prec0n_ignoreflag(void){return test("%+ .0e", -7.3);}
int bonus_e_assp_prec1n_ignoreflag(void){return test("%+ .1e", -7.3);}
int bonus_e_assp_prec3n_ignoreflag(void){return test("%+ .3e", -7.3);}
int bonus_e_assp_prec6n_ignoreflag(void){return test("%+ .6e", -7.3);}
//Scientific notation with allsign and sp and rev flag order,~
int bonus_e_asspr_prec0p_ignoreflag(void){return test("% +.0e", 7.3);}
int bonus_e_asspr_prec1p_ignoreflag(void){return test("% +.1e", 7.3);}
int bonus_e_asspr_prec3p_ignoreflag(void){return test("% +.3e", 7.3);}
int bonus_e_asspr_prec6p_ignoreflag(void){return test("% +.6e", 7.3);}
int bonus_e_asspr_prec0n_ignoreflag(void){return test("% +.0e", -7.3);}
int bonus_e_asspr_prec1n_ignoreflag(void){return test("% +.1e", -7.3);}
int bonus_e_asspr_prec3n_ignoreflag(void){return test("% +.3e", -7.3);}
int bonus_e_asspr_prec6n_ignoreflag(void){return test("% +.6e", -7.3);}

//Scientific notation whose precision exceeds their compiled literal precision
int bonus_notrequired_e_overprec_might_be_undefbehav_100(void){return test("%.100e", 0.237);}
int bonus_notrequired_e_overprec_might_be_undefbehav_32(void){return test("%.32e", 0.237);}
int bonus_notrequired_e_overprec_might_be_undefbehav_4(void){return test("%.4e", 0.237);}
int bonus_notrequired_e_overprec_might_be_undefbehav_1000(void){return test("%.4e", -0.106577568068517810765107851705167);}
int bonus_notrequired_e_overprec_might_be_undefbehav_10_from_0(void){return test("%.10e", 0.0);}
int bonus_notrequired_e_overprec_might_be_undefbehav_2000(void){return test("%.2000e", 623.28376510723481);}
int bonus_notrequired_e_overprec_might_be_undefbehav_dblmin(void){return test("%.2000e", DBL_MIN);}
int bonus_notrequired_e_overprec_might_be_undefbehav_ndblmin(void){return test("%.2000e", -DBL_MIN);}
//Scientific notation at double max, double min
int bonus_notrequired_e_limits_dblmax_prec0(void){return test("%.0e", DBL_MAX);}
int bonus_notrequired_e_limits_dblmax_prec3(void){return test("%.3e", DBL_MAX);}
int bonus_notrequired_e_limits_dblmax_precd(void){return test("%e", DBL_MAX);}
int bonus_notrequired_e_limits_dblmax_prec8(void){return test("%.8e", DBL_MAX);}
int bonus_notrequired_e_stress_limits_dblmax_prec12(void){return test("%.12e", DBL_MAX);}
int bonus_notrequired_e_stress_limits_dblmax_prec16(void){return test("%.16e", DBL_MAX);}
int bonus_notrequired_e_stress_limits_dblmax_prec18(void){return test("%.18e", DBL_MAX);}
int bonus_notrequired_e_limits_ndblmax_prec0(void){return test("%.0e", -DBL_MAX);}
int bonus_notrequired_e_limits_ndblmax_prec3(void){return test("%.3e", -DBL_MAX);}
int bonus_notrequired_e_limits_ndblmax_precd(void){return test("%e", -DBL_MAX);}
int bonus_notrequired_e_limits_ndblmax_prec8(void){return test("%.8e", -DBL_MAX);}
int bonus_notrequired_e_stress_limits_ndblmax_prec12(void){return test("%.12e", -DBL_MAX);}
int bonus_notrequired_e_stress_limits_ndblmax_prec16(void){return test("%.16e", -DBL_MAX);}
int bonus_notrequired_e_stress_limits_ndblmax_prec18(void){return test("%.18e", -DBL_MAX);}
int bonus_notrequired_e_limits_dblmin_prec0(void){return test("%.0e", DBL_MIN);}
int bonus_notrequired_e_limits_dblmin_prec3(void){return test("%.3e", DBL_MIN);}
int bonus_notrequired_e_limits_dblmin_precd(void){return test("%e", DBL_MIN);}
int bonus_notrequired_e_limits_dblmin_prec8(void){return test("%.8e", DBL_MIN);}
int bonus_notrequired_e_stress_limits_dblmin_prec12(void){return test("%.12e", DBL_MIN);}
int bonus_notrequired_e_stress_limits_dblmin_prec16(void){return test("%.16e", DBL_MIN);}
int bonus_notrequired_e_stress_limits_dblmin_prec18(void){return test("%.18e", DBL_MIN);}
int bonus_notrequired_e_limits_ndblmin_prec0(void){return test("%.0e", -DBL_MIN);}
int bonus_notrequired_e_limits_ndblmin_prec3(void){return test("%.3e", -DBL_MIN);}
int bonus_notrequired_e_limits_ndblmin_precd(void){return test("%e", -DBL_MIN);}
int bonus_notrequired_e_limits_ndblmin_prec8(void){return test("%.8e", -DBL_MIN);}
int bonus_notrequired_e_stress_limits_ndblmin_prec12(void){return test("%.12e", -DBL_MIN);}
int bonus_notrequired_e_stress_limits_ndblmin_prec16(void){return test("%.16e", -DBL_MIN);}
int bonus_notrequired_e_stress_limits_ndblmin_prec18(void){return test("%.18e", -DBL_MIN);}
 //Scientific notation of special values
int bonus_notrequired_e_reserved_values_inf(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%e", special);}
int bonus_notrequired_e_reserved_values_ninf(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%e", special);}
int bonus_notrequired_e_reserved_values_nan(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%e", special);}
int bonus_notrequired_e_reserved_values_pzero(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%e", special);}
int bonus_notrequired_e_reserved_values_nzero(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%e", special);}
int bonus_notrequired_e_reserved_values_inf_6w(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%6e", special);}
int bonus_notrequired_e_reserved_values_ninf_6w(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%6e", special);}
int bonus_notrequired_e_reserved_values_nan_6w(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%6e", special);}
int bonus_notrequired_e_reserved_values_pzero_6w(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%6e", special);}
int bonus_notrequired_e_reserved_values_nzero_6w(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%6e", special);}
int bonus_notrequired_e_reserved_values_inf_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%-6e", special);}
int bonus_notrequired_e_reserved_values_ninf_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%-6e", special);}
int bonus_notrequired_e_reserved_values_nan_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%-6e", special);}
int bonus_notrequired_e_reserved_values_pzero_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%-6e", special);}
int bonus_notrequired_e_reserved_values_nzero_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%-6e", special);}
int bonus_notrequired_e_reserved_values_inf_6was(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%+6e", special);}
int bonus_notrequired_e_reserved_values_ninf_6was(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%+6e", special);}
int bonus_notrequired_e_reserved_values_nan_6was(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%+6e", special);}
int bonus_notrequired_e_reserved_values_pzero_6was(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%+6e", special);}
int bonus_notrequired_e_reserved_values_nzero_6was(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%+6e", special);}
int bonus_notrequired_e_reserved_values_inf_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%10.7e", special);}
int bonus_notrequired_e_reserved_values_ninf_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%10.7e", special);}
int bonus_notrequired_e_reserved_values_nan_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%10.7e", special);}
int bonus_notrequired_e_reserved_values_pzero_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%10.7e", special);}
int bonus_notrequired_e_reserved_values_nzero_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%10.7e", special);}
int bonus_notrequired_e_reserved_values_inf_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("% .7e", special);}
int bonus_notrequired_e_reserved_values_ninf_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("% .7e", special);}
int bonus_notrequired_e_reserved_values_nan_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("% .7e", special);}
int bonus_notrequired_e_reserved_values_pzero_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("% .7e", special);}
int bonus_notrequired_e_reserved_values_nzero_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("% .7e", special);}
int bonus_notrequired_e_reserved_values_inf_sp(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("% e", special);}
int bonus_notrequired_e_reserved_values_ninf_sp(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("% e", special);}
int bonus_notrequired_e_reserved_values_nan_sp(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("% e", special);}
int bonus_notrequired_e_reserved_values_pzero_sp(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("% e", special);}
int bonus_notrequired_e_reserved_values_nzero_sp(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("% e", special);}
int bonus_notrequired_e_reserved_values_inf_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%06e", special);}
int bonus_notrequired_e_reserved_values_ninf_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%06e", special);}
int bonus_notrequired_e_reserved_values_nan_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%06e", special);}
int bonus_notrequired_e_reserved_values_pzero_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%06e", special);}
int bonus_notrequired_e_reserved_values_nzero_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%06e", special);}


/* -----------------------------------------------------------------------------
** 							MOULINETTE TESTS - BONUS
** ---------------------------------------------------------------------------*/

int bonus_moul_ld_1_throwswarning(void){return test("%ld", 42);}
int bonus_moul_ld_2_throwswarning(void){return test("Kashim a %ld histoires à raconter", 1001);}
int bonus_moul_ld_3_throwswarning(void){return test("Il fait au moins %ld\n", -8000);}
int bonus_moul_ld_4_throwswarning(void){return test("%ld", -0);}
int bonus_moul_ld_5_throwswarning(void){return test("%ld", 0);}
int bonus_moul_ld_6_throwswarning(void){return test("%ld", INT_MAX);}
int bonus_moul_ld_7_throwswarning(void){return test("%ld", INT_MIN);}
int bonus_moul_ld_8_throwswarning(void){return test("%ld", INT_MIN - 1);}
int bonus_moul_ld_9_throwswarning(void){return test("%ld", INT_MAX + 1);}
int bonus_moul_ld_10_throwswarning(void){return test("%%ld 0000042 == |%ld|\n", 0000042);}
int bonus_moul_ld_11_throwswarning(void){return test("%%ld \t == |%ld|\n", '\t');}
int bonus_moul_ld_12_throwswarning(void){return test("%%ld Lydie == |%ld|\n", 'L'+'y'+'d'+'i'+'e');}

int bonus_sp_moul_1(void){return test("%%      i 42 == |%      i|\n", 42);}
int bonus_sp_moul_2(void){return test("%% i -42 == |% i|\n", -42);}
int bonus_sp_moul_3(void){return test("%% 4i 42 == |% 4i|\n", 42);}
int bonus_sp_moul_prec_2(void){return test("%% 4.5i 42 == |% 4.5i|\n", 42);}

int bonus_as_moul_1(void){return test("%%+i 42 == %+i\n", 42);}
int bonus_as_moul_2(void){return test("%%+d 42 == %+d\n", INT_MAX);}
int bonus_as_moul_3(void){return test("%%+i -42 == %+i\n", -42);}
int bonus_as_moul_4(void){return test("%%+04d 42 == %0+04d\n", 42);}

int bonus_moul_hash_1(void){return test("%%#X 42 ==  %#X\n", 42);}
int bonus_moul_hash_2(void){return test("%%X 42 ==  %X\n", 42);}
int bonus_moul_hash_9(void){return test("%%#X INT_MIN ==  %#X\n", INT_MIN);}
int bonus_moul_hash_10(void){return test("%%X INT_MIN ==  %X\n", INT_MIN);}
int bonus_moul_hash_11(void){return test("%%#X INT_MAX ==  %#X\n", INT_MAX);}
int bonus_moul_hash_12(void){return test("%%X INT_MAX ==  %X\n", INT_MAX);}

int bonus_moul_f_1(void){return test("%f", (double)42);}
int bonus_moul_f_2(void){return test("Kashim a %f histoires à raconter", (double)1001);}
int bonus_moul_f_3(void){return test("Il fait au moins %f\n", (double)-8000);}
int bonus_moul_f_4(void){return test("%f", (double)-0);}
int bonus_moul_f_5(void){return test("%f", (double)0);}
int bonus_moul_f_6(void){return test("%f", (double)INT_MAX);}
int bonus_moul_f_7(void){return test("%f", (double)INT_MIN);}
int bonus_moul_f_7b(void){return test("%f", (double)INT_MIN - 1);}
int bonus_moul_f_8(void){return test("%f", (double)INT_MAX + 1);}
int bonus_moul_f_9(void){return test("%%f 0000042 == |%f|\n", (double)0000042);}
int bonus_moul_f_10(void){return test("%%f \t == |%f|\n", (double)'\t');}
int bonus_moul_f_11(void){return test("%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');}
int bonus_moul_f_12(void){return test("%%f 42.42 == |%f|\n", 42.42);}

int bonus_moul_g_1(void){return test("%g", (double)42);}
int bonus_moul_g_2(void){return test("Kashim a %g histoires à raconter", (double)1001);}
int bonus_moul_g_3(void){return test("Il fait au moins %g\n", (double)-8000);}
int bonus_moul_g_4(void){return test("%g", (double)-0);}
int bonus_moul_g_5(void){return test("%g", (double)0);}
int bonus_moul_g_6(void){return test("%g", (double)INT_MAX);}
int bonus_moul_g_7(void){return test("%g", (double)INT_MIN);}
int bonus_moul_g_8(void){return test("%g", (double)INT_MIN - 1);}
int bonus_moul_g_9(void){return test("%g", (double)INT_MAX + 1);}
int bonus_moul_g_10(void){return test("%%g 0000042 == |%g|\n", (double)0000042);}
int bonus_moul_g_11(void){return test("%%g \t == |%g|\n", (double)'\t');}
int bonus_moul_g_12(void){return test("%%g Lydie == |%g|\n", (double)'L'+'y'+'d'+'i'+'e');}
int bonus_moul_g_13(void){return test("%%g 42.42 == |%g|\n", 42.42);}

int bonus_moul_e_1(void){return test("%e", (double)42);}
int bonus_moul_e_2(void){return test("Kashim a %e histoires à raconter", (double)1001);}
int bonus_moul_e_3(void){return test("Il fait au moins %e\n", (double)-8000);}
int bonus_moul_e_4(void){return test("%e", (double)-0);}
int bonus_moul_e_5(void){return test("%e", (double)0);}
int bonus_moul_e_6(void){return test("%e", (double)INT_MAX);}
int bonus_moul_e_7(void){return test("%e", (double)INT_MIN);}
int bonus_moul_e_8(void){return test("%e", (double)INT_MIN - 1);}
int bonus_moul_e_9(void){return test("%e", (double)INT_MAX + 1);}
int bonus_moul_e_10(void){return test("%%e 0000042 == |%e|\n", (double)0000042);}
int bonus_moul_e_11(void){return test("%%e \t == |%e|\n", (double)'\t');}
int bonus_moul_e_12(void){return test("%%e Lydie == |%e|\n", (double)'L'+'y'+'d'+'i'+'e');}
int bonus_moul_e_13(void){return test("%%e 42.42 == |%e|\n", 42.42);}


/* -----------------------------------------------------------------------------
** 							MIXED TESTS - BONUS
** ---------------------------------------------------------------------------*/
//Switching between string and signed integers of various sizes
static char	str_1[] = "hello world", str_2[] = "panda", str_3[] = "this is a longer string";
static char	str_empty[] = "";
int bonus_mix_hhi_str_lli_str(void){return test("%hhi%s%lli%s", ch_pos_1, str_3, ll_neg_1, str_2);}
int bonus_mix_str_hi_str_li(void){return test("%s%hi%s%li", str_1, sh_neg_1, str_3, l_neg_1);}
int bonus_mix_str_hi_str_li_emptystr(void){return test("%s%hi%s%li", str_empty, sh_neg_1, str_3, l_neg_1);}
//Switching between string and unsigned integers of various sizes
int bonus_mix_hhu_str_llu_str(void){return test("%hhu%s%llu%s", uch_pos_1, str_3, ull_pos_1, str_2);}
int bonus_mix_str_hu_str_lu(void){return test("%s%hu%s%lu", str_1, ush_pos_1, str_3, ul_pos_1);}
//Mixing everything from all the tests so far
int bonus_mix_test_0001(void){return test(
		"%s%hihello%-17.14llu%lli%08hu%s%17ssomestuff%s%hi%i%.24lu%llu%u%.2s%li","abc",sh_neg_1,
		ull_pos_1,ll_neg_1,ush_pos_1,"wassup","nope","",(short)32767,0,ul_pos_1,0ull,ui_pos_1,"notall",l_pos_1);}

///Mix tests
static double			mx_f = 0.625;
static long				mx_li =  4223372036854775800;
static long long		mx_lli = 3223372036654775200;
static short			mx_hi = -3244;
static char				mx_hhi = 'F';

int bonus_mix_test_0(void){return test(
			"  %o    %u    %li    %s    %X    %lli  ",
			mx_u, mx_u, mx_li, mx_s, mx_u, mx_lli);}
int bonus_mix_test_1(void){return test(
			"  %li    %u    %s    %X    %x    %f  ",
			mx_li, mx_u, mx_s, mx_u, mx_u, mx_f);}
int bonus_mix_test_2(void){return test(
			"  %f    %p    %i    %li    %lli    %s  ",
			mx_f, &mx_i, mx_i, mx_li, mx_lli, mx_s);}
int bonus_mix_test_3(void){return test(
			"  %x    %s    %i    %p    %X    %f  ",
			mx_u, mx_s, mx_i, &mx_i, mx_u, mx_f);}
int bonus_mix_test_4(void){return test(
			"  %li    %hhi    %p    %o    %%    %f  ",
			mx_li, mx_c, &mx_i, mx_u, mx_f);}
int bonus_mix_test_5(void){return test(
			"  %hi    %u    %x    %s    %i    %X  ",
			mx_hi, mx_u, mx_u, mx_s, mx_i, mx_u);}
int bonus_mix_test_6(void){return test(
			"  %f    %li    %i    %p    %u    %hi  ",
			mx_f, mx_li, mx_i, &mx_i, mx_u, mx_hi);}
int bonus_mix_test_7(void){return test(
			"  %u    %hhi    %p    %li    %f    %X  ",
			mx_u, mx_c, &mx_i, mx_li, mx_f, mx_u);}
int bonus_mix_test_8(void){return test(
			"  %o    %f    %u    %li    %lli    %x  ",
			mx_u, mx_f, mx_u, mx_li, mx_lli, mx_u);}
int bonus_mix_test_9(void){return test(
			"  %f    %li    %s    %p    %x    %o  ",
			mx_f, mx_li, mx_s, &mx_i, mx_u, mx_u);}
int bonus_mix_test_10(void){return test(
			"  %hhi    %x    %s    %u    %i    %li  ",
			mx_c, mx_u, mx_s, mx_u, mx_i, mx_li);}
int bonus_mix_test_11(void){return test(
			"  %X    %li    %o    %s    %f    %u  ",
			mx_u, mx_li, mx_u, mx_s, mx_f, mx_u);}
int bonus_mix_test_12(void){return test(
			"  %o    %x    %i    %c    %hi    %f  ",
			mx_u, mx_u, mx_i, mx_c, mx_hi, mx_f);}
int bonus_mix_test_13(void){return test(
			"  %c    %i    %hi    %o    %x    %u  ",
			mx_c, mx_i, mx_hi, mx_u, mx_u, mx_u);}
int bonus_mix_test_14(void){return test(
			"  %i    %f    %li    %f    %X    %hhi  ",
			mx_i, mx_f, mx_li, mx_f, mx_u, mx_c);}
int bonus_mix_test_15(void){return test(
			"  %s    %u    %lli    %f    %f    %o  ",
			mx_s, mx_u, mx_lli, mx_f, mx_f, mx_u);}
int bonus_mix_test_16(void){return test(
			"  %hhi    %X    %u    %p    %x    %o  ",
			mx_c, mx_u, mx_u, &mx_i, mx_u, mx_u);}
int bonus_mix_test_17(void){return test(
			"  %X    %i    %c    %lli    %o    %p  ",
			mx_u, mx_i, mx_c, mx_lli, mx_u, &mx_i);}
int bonus_mix_test_18(void){return test(
			"  %X    %c    %x    %i    %hi    %s  ",
			mx_u, mx_c, mx_u, mx_i, mx_hi, mx_s);}
int bonus_mix_test_19(void){return test(
			"  %hhi    %li    %x    %hi    %lli    %s  ",
			mx_c, mx_li, mx_u, mx_hi, mx_lli, mx_s);}
int bonus_mix_test_20(void){return test(
			"  %f    %p    %lli    %hhi    %c    %f  ",
			mx_f, &mx_i, mx_lli, mx_c, mx_c, mx_f);}
int bonus_mix_test_21(void){return test(
			"  %hi    %s    %hhi    %p    %lli    %u  ",
			mx_hi, mx_s, mx_c, &mx_i, mx_lli, mx_u);}
int bonus_mix_test_22(void){return test(
			"  %p    %lli    %s    %X    %u    %hhi  ",
			&mx_i, mx_lli, mx_s, mx_u, mx_u, mx_c);}
int bonus_mix_test_23(void){return test(
			"  %hhi    %f    %x    %o    %i    %X  ",
			mx_c, mx_f, mx_u, mx_u, mx_i, mx_u);}
int bonus_mix_test_24(void){return test(
			"  %lli    %hhi    %hi    %i    %c    %o  ",
			mx_lli, mx_c, mx_hi, mx_i, mx_c, mx_u);}
int bonus_mix_test_25(void){return test(
			"  %s    %f    %p    %c    %X    %x  ",
			mx_s, mx_f, &mx_i, mx_c, mx_u, mx_u);}
int bonus_mix_test_26(void){return test(
			"  %lli    %i    %u    %p    %o    %c  ",
			mx_lli, mx_i, mx_u, &mx_i, mx_u, mx_c);}
int bonus_mix_test_27(void){return test(
			"  %i    %p    %hhi    %X    %f    %lli  ",
			mx_i, &mx_i, mx_c, mx_u, mx_f, mx_lli);}
int bonus_mix_test_28(void){return test(
			"  %f    %i    %p    %li    %o    %x  ",
			mx_f, mx_i, &mx_i, mx_li, mx_u, mx_u);}
int bonus_mix_test_29(void){return test(
			"  %li    %lli    %f    %X    %o    %s  ",
			mx_li, mx_lli, mx_f, mx_u, mx_u, mx_s);}
int bonus_mix_test_30(void){return test(
			"  %f    %hi    %p    %hhi    %li    %u  ",
			mx_f, mx_hi, &mx_i, mx_c, mx_li, mx_u);}
int bonus_mix_test_31(void){return test(
			"  %s    %x    %u    %li    %o    %hi  ",
			mx_s, mx_u, mx_u, mx_li, mx_u, mx_hi);}
int bonus_mix_test_32(void){return test(
			"  %u    %lli    %X    %i    %o    %f  ",
			mx_u, mx_lli, mx_u, mx_i, mx_u, mx_f);}
int bonus_mix_test_33(void){return test(
			"  %o    %X    %u    %c    %lli    %hi  ",
			mx_u, mx_u, mx_u, mx_c, mx_lli, mx_hi);}
int bonus_mix_test_34(void){return test(
			"  %hi    %X    %f    %s    %o    %x  ",
			mx_hi, mx_u, mx_f, mx_s, mx_u, mx_u);}
int bonus_mix_test_35(void){return test(
			"  %X    %p    %o    %hi    %s    %lli  ",
			mx_u, &mx_i, mx_u, mx_hi, mx_s, mx_lli);}
int bonus_mix_test_36(void){return test(
			"  %li    %p    %f    %f    %x    %lli  ",
			mx_li, &mx_i, mx_f, mx_f, mx_u, mx_lli);}
int bonus_mix_test_37(void){return test(
			"  %i    %li    %X    %p    %hi    %o  ",
			mx_i, mx_li, mx_u, &mx_i, mx_hi, mx_u);}
int bonus_mix_test_38(void){return test(
			"  %f    %u    %p    %hi    %hhi    %s  ",
			mx_f, mx_u, &mx_i, mx_hi, mx_c, mx_s);}
int bonus_mix_test_39(void){return test(
			"  %o    %c    %li    %p    %hi    %f  ",
			mx_u, mx_c, mx_li, &mx_i, mx_hi, mx_f);}
int bonus_mix_test_40(void){return test(
			"  %u    %X    %f    %hhi    %s    %o  ",
			mx_u, mx_u, mx_f, mx_c, mx_s, mx_u);}
int bonus_mix_test_41(void){return test(
			"  %li    %x    %hhi    %X    %s    %lli  ",
			mx_li, mx_u, mx_c, mx_u, mx_s, mx_lli);}
int bonus_mix_test_42(void){return test(
			"  %hi    %x    %i    %c    %hhi    %li  ",
			mx_hi, mx_u, mx_i, mx_c, mx_c, mx_li);}
int bonus_mix_test_43(void){return test(
			"  %x    %X    %o    %s    %lli    %hhi  ",
			mx_u, mx_u, mx_u, mx_s, mx_lli, mx_c);}
int bonus_mix_test_44(void){return test(
			"  %f    %x    %o    %hi    %li    %u  ",
			mx_f, mx_u, mx_u, mx_hi, mx_li, mx_u);}
int bonus_mix_test_45(void){return test(
			"  %f    %hhi    %c    %X    %lli    %s  ",
			mx_f, mx_c, mx_c, mx_u, mx_lli, mx_s);}
int bonus_mix_test_46(void){return test(
			"  %lli    %i    %hhi    %hi    %li    %f  ",
			mx_lli, mx_i, mx_c, mx_hi, mx_li, mx_f);}
int bonus_mix_test_47(void){return test(
			"  %f    %c    %lli    %s    %hhi    %p  ",
			mx_f, mx_c, mx_lli, mx_s, mx_c, &mx_i);}
int bonus_mix_test_48(void){return test(
			"  %f    %hhi    %li    %lli    %x    %p  ",
			mx_f, mx_c, mx_li, mx_lli, mx_u, &mx_i);}
int bonus_mix_test_49(void){return test(
			"  %o    %lli    %hi    %f    %X    %hhi  ",
			mx_u, mx_lli, mx_hi, mx_f, mx_u, mx_c);}
int bonus_mix_test_50(void){return test(
			"  %o    %u    %f    %i    %x    %hhi  ",
			mx_u, mx_u, mx_f, mx_i, mx_u, mx_c);}
int bonus_mix_test_51(void){return test(
			"  %x    %u    %f    %hi    %o    %X  ",
			mx_u, mx_u, mx_f, mx_hi, mx_u, mx_u);}
int bonus_mix_test_52(void){return test(
			"  %u    %f    %hi    %li    %X    %hhi  ",
			mx_u, mx_f, mx_hi, mx_li, mx_u, mx_c);}
int bonus_mix_test_53(void){return test(
			"  %o    %c    %f    %hi    %s    %p  ",
			mx_u, mx_c, mx_f, mx_hi, mx_s, &mx_i);}
int bonus_mix_test_54(void){return test(
			"  %s    %hhi    %X    %lli    %x    %u  ",
			mx_s, mx_c, mx_u, mx_lli, mx_u, mx_u);}
int bonus_mix_test_55(void){return test(
			"  %x    %X    %o    %lli    %c    %u  ",
			mx_u, mx_u, mx_u, mx_lli, mx_c, mx_u);}
int bonus_mix_test_56(void){return test(
			"  %hi    %u    %i    %x    %c    %s  ",
			mx_hi, mx_u, mx_i, mx_u, mx_c, mx_s);}
int bonus_mix_test_57(void){return test(
			"  %hi    %s    %i    %X    %u    %li  ",
			mx_hi, mx_s, mx_i, mx_u, mx_u, mx_li);}
int bonus_mix_test_58(void){return test(
			"  %c    %X    %li    %hi    %f    %p  ",
			mx_c, mx_u, mx_li, mx_hi, mx_f, &mx_i);}
int bonus_mix_test_59(void){return test(
			"  %f    %hi    %c    %u    %hhi    %li  ",
			mx_f, mx_hi, mx_c, mx_u, mx_c, mx_li);}
int bonus_mix_test_60(void){return test(
			"  %li    %p    %s    %hi    %u    %lli  ",
			mx_li, &mx_i, mx_s, mx_hi, mx_u, mx_lli);}
int bonus_mix_test_61(void){return test(
			"  %li    %X    %f    %s    %c    %lli  ",
			mx_li, mx_u, mx_f, mx_s, mx_c, mx_lli);}
int bonus_mix_test_62(void){return test(
			"  %lli    %hhi    %f    %o    %s    %X  ",
			mx_lli, mx_c, mx_f, mx_u, mx_s, mx_u);}
int bonus_mix_test_63(void){return test(
			"  %x    %X    %u    %s    %li    %f  ",
			mx_u, mx_u, mx_u, mx_s, mx_li, mx_f);}
int bonus_mix_test_64(void){return test(
			"  %hhi    %X    %u    %o    %f    %s  ",
			mx_c, mx_u, mx_u, mx_u, mx_f, mx_s);}
int bonus_mix_test_65(void){return test(
			"  %li    %u    %x    %o    %lli    %s  ",
			mx_li, mx_u, mx_u, mx_u, mx_lli, mx_s);}
int bonus_mix_test_66(void){return test(
			"  %hi    %f    %hhi    %u    %i    %p  ",
			mx_hi, mx_f, mx_c, mx_u, mx_i, &mx_i);}
int bonus_mix_test_67(void){return test(
			"  %i    %c    %f    %hi    %s    %o  ",
			mx_i, mx_c, mx_f, mx_hi, mx_s, mx_u);}
int bonus_mix_test_68(void){return test(
			"  %li    %s    %p    %f    %f    %X  ",
			mx_li, mx_s, &mx_i, mx_f, mx_f, mx_u);}
int bonus_mix_test_69(void){return test(
			"  %s    %p    %f    %lli    %x    %o  ",
			mx_s, &mx_i, mx_f, mx_lli, mx_u, mx_u);}
int bonus_mix_test_70(void){return test(
			"  %hhi    %hi    %f    %c    %x    %lli  ",
			mx_c, mx_hi, mx_f, mx_c, mx_u, mx_lli);}
int bonus_mix_test_71(void){return test(
			"  %p    %u    %lli    %c    %f    %X  ",
			&mx_i, mx_u, mx_lli, mx_c, mx_f, mx_u);}
int bonus_mix_test_72(void){return test(
			"  %X    %p    %f    %c    %o    %li  ",
			mx_u, &mx_i, mx_f, mx_c, mx_u, mx_li);}
int bonus_mix_test_73(void){return test(
			"  %p    %c    %li    %lli    %x    %f  ",
			&mx_i, mx_c, mx_li, mx_lli, mx_u, mx_f);}
int bonus_mix_test_74(void){return test(
			"  %u    %c    %li    %p    %o    %s  ",
			mx_u, mx_c, mx_li, &mx_i, mx_u, mx_s);}
int bonus_mix_test_75(void){return test(
			"  %hhi    %lli    %s    %li    %hi    %c  ",
			mx_c, mx_lli, mx_s, mx_li, mx_hi, mx_c);}
int bonus_mix_test_76(void){return test(
			"  %u    %x    %lli    %hi    %i    %hhi  ",
			mx_u, mx_u, mx_lli, mx_hi, mx_i, mx_c);}
int bonus_mix_test_77(void){return test(
			"  %li    %hi    %f    %c    %o    %lli  ",
			mx_li, mx_hi, mx_f, mx_c, mx_u, mx_lli);}
int bonus_mix_test_78(void){return test(
			"  %u    %i    %c    %p    %o    %f  ",
			mx_u, mx_i, mx_c, &mx_i, mx_u, mx_f);}
int bonus_mix_test_79(void){return test(
			"  %f    %X    %p    %hhi    %c    %s  ",
			mx_f, mx_u, &mx_i, mx_c, mx_c, mx_s);}
int bonus_mix_test_80(void){return test(
			"  %c    %hi    %u    %i    %f    %X  ",
			mx_c, mx_hi, mx_u, mx_i, mx_f, mx_u);}
int bonus_mix_test_81(void){return test(
			"  %s    %p    %u    %f    %hhi    %li  ",
			mx_s, &mx_i, mx_u, mx_f, mx_c, mx_li);}
int bonus_mix_test_82(void){return test(
			"  %X    %x    %i    %c    %f    %li  ",
			mx_u, mx_u, mx_i, mx_c, mx_f, mx_li);}
int bonus_mix_test_83(void){return test(
			"  %X    %hi    %x    %u    %c    %o  ",
			mx_u, mx_hi, mx_u, mx_u, mx_c, mx_u);}
int bonus_mix_test_84(void){return test(
			"  %hi    %f    %hhi    %li    %s    %lli  ",
			mx_hi, mx_f, mx_c, mx_li, mx_s, mx_lli);}
int bonus_mix_test_85(void){return test(
			"  %f    %o    %f    %u    %X    %li  ",
			mx_f, mx_u, mx_f, mx_u, mx_u, mx_li);}
int bonus_mix_test_86(void){return test(
			"  %f    %i    %lli    %hi    %u    %o  ",
			mx_f, mx_i, mx_lli, mx_hi, mx_u, mx_u);}
int bonus_mix_test_87(void){return test(
			"  %i    %x    %lli    %c    %hi    %f  ",
			mx_i, mx_u, mx_lli, mx_c, mx_hi, mx_f);}
int bonus_mix_test_88(void){return test(
			"  %u    %c    %x    %f    %p    %X  ",
			mx_u, mx_c, mx_u, mx_f, &mx_i, mx_u);}
int bonus_mix_test_89(void){return test(
			"  %li    %c    %o    %f    %u    %lli  ",
			mx_li, mx_c, mx_u, mx_f, mx_u, mx_lli);}
int bonus_mix_test_90(void){return test(
			"  %f    %o    %f    %li    %p    %s  ",
			mx_f, mx_u, mx_f, mx_li, &mx_i, mx_s);}
int bonus_mix_test_91(void){return test(
			"  %X    %c    %p    %s    %i    %f  ",
			mx_u, mx_c, &mx_i, mx_s, mx_i, mx_f);}
int bonus_mix_test_92(void){return test(
			"  %c    %hhi    %o    %X    %s    %lli  ",
			mx_c, mx_c, mx_u, mx_u, mx_s, mx_lli);}
int bonus_mix_test_93(void){return test(
			"  %f    %hi    %c    %hhi    %s    %f  ",
			mx_f, mx_hi, mx_c, mx_c, mx_s, mx_f);}
int bonus_mix_test_94(void){return test(
			"  %c    %u    %x    %lli    %hi    %s  ",
			mx_c, mx_u, mx_u, mx_lli, mx_hi, mx_s);}
int bonus_mix_test_95(void){return test(
			"  %f    %u    %c    %x    %lli    %li  ",
			mx_f, mx_u, mx_c, mx_u, mx_lli, mx_li);}
int bonus_mix_test_96(void){return test(
			"  %f    %hi    %li    %c    %x    %X  ",
			mx_f, mx_hi, mx_li, mx_c, mx_u, mx_u);}
int bonus_mix_test_97(void){return test(
			"  %u    %f    %i    %f    %hhi    %hi  ",
			mx_u, mx_f, mx_i, mx_f, mx_c, mx_hi);}
int bonus_mix_test_98(void){return test(
			"  %f    %s    %hi    %i    %f    %x  ",
			mx_f, mx_s, mx_hi, mx_i, mx_f, mx_u);}
int bonus_mix_test_99(void){return test(
			"  %u    %f    %X    %c    %lli    %p  ",
			mx_u, mx_f, mx_u, mx_c, mx_lli, &mx_i);}
int bonus_mix_test_100(void){return test(
			"  %X    %li    %f    %s    %hhi    %x  ",
			mx_u, mx_li, mx_f, mx_s, mx_c, mx_u);}
int bonus_mix_test_101(void){return test(
			"  %o    %p    %s    %f    %X    %x  ",
			mx_u, &mx_i, mx_s, mx_f, mx_u, mx_u);}
int bonus_mix_test_102(void){return test(
			"  %hhi    %c    %f    %x    %hi    %li  ",
			mx_c, mx_c, mx_f, mx_u, mx_hi, mx_li);}
int bonus_mix_test_103(void){return test(
			"  %p    %f    %x    %X    %f    %s  ",
			&mx_i, mx_f, mx_u, mx_u, mx_f, mx_s);}
int bonus_mix_test_104(void){return test(
			"  %s    %x    %lli    %i    %o    %p  ",
			mx_s, mx_u, mx_lli, mx_i, mx_u, &mx_i);}
int bonus_mix_test_105(void){return test(
			"  %X    %s    %f    %p    %lli    %x  ",
			mx_u, mx_s, mx_f, &mx_i, mx_lli, mx_u);}
int bonus_mix_test_106(void){return test(
			"  %c    %hhi    %hi    %x    %u    %li  ",
			mx_c, mx_c, mx_hi, mx_u, mx_u, mx_li);}
int bonus_mix_test_107(void){return test(
			"  %li    %X    %s    %f    %f    %hhi  ",
			mx_li, mx_u, mx_s, mx_f, mx_f, mx_c);}
int bonus_mix_test_108(void){return test(
			"  %u    %hhi    %s    %c    %p    %f  ",
			mx_u, mx_c, mx_s, mx_c, &mx_i, mx_f);}
int bonus_mix_test_109(void){return test(
			"  %f    %s    %u    %f    %i    %X  ",
			mx_f, mx_s, mx_u, mx_f, mx_i, mx_u);}
int bonus_mix_test_110(void){return test(
			"  %i    %p    %hi    %c    %f    %s  ",
			mx_i, &mx_i, mx_hi, mx_c, mx_f, mx_s);}
int bonus_mix_test_111(void){return test(
			"  %p    %X    %lli    %hi    %f    %f  ",
			&mx_i, mx_u, mx_lli, mx_hi, mx_f, mx_f);}
int bonus_mix_test_112(void){return test(
			"  %u    %c    %f    %lli    %o    %hhi  ",
			mx_u, mx_c, mx_f, mx_lli, mx_u, mx_c);}
int bonus_mix_test_113(void){return test(
			"  %X    %i    %x    %c    %p    %s  ",
			mx_u, mx_i, mx_u, mx_c, &mx_i, mx_s);}
int bonus_mix_test_114(void){return test(
			"  %x    %p    %f    %u    %hi    %o  ",
			mx_u, &mx_i, mx_f, mx_u, mx_hi, mx_u);}
int bonus_mix_test_115(void){return test(
			"  %X    %hhi    %lli    %p    %li    %hi  ",
			mx_u, mx_c, mx_lli, &mx_i, mx_li, mx_hi);}
int bonus_mix_test_116(void){return test(
			"  %lli    %c    %li    %o    %f    %x  ",
			mx_lli, mx_c, mx_li, mx_u, mx_f, mx_u);}
int bonus_mix_test_117(void){return test(
			"  %lli    %s    %i    %f    %hhi    %x  ",
			mx_lli, mx_s, mx_i, mx_f, mx_c, mx_u);}
int bonus_mix_test_118(void){return test(
			"  %o    %f    %f    %x    %p    %hhi  ",
			mx_u, mx_f, mx_f, mx_u, &mx_i, mx_c);}
int bonus_mix_test_119(void){return test(
			"  %hhi    %p    %i    %hi    %o    %c  ",
			mx_c, &mx_i, mx_i, mx_hi, mx_u, mx_c);}
int bonus_mix_test_120(void){return test(
			"  %X    %lli    %o    %li    %x    %p  ",
			mx_u, mx_lli, mx_u, mx_li, mx_u, &mx_i);}
int bonus_mix_test_121(void){return test(
			"  %X    %s    %hi    %li    %c    %x  ",
			mx_u, mx_s, mx_hi, mx_li, mx_c, mx_u);}
int bonus_mix_test_122(void){return test(
			"  %lli    %s    %f    %i    %f    %u  ",
			mx_lli, mx_s, mx_f, mx_i, mx_f, mx_u);}
int bonus_mix_test_123(void){return test(
			"  %f    %lli    %x    %f    %o    %p  ",
			mx_f, mx_lli, mx_u, mx_f, mx_u, &mx_i);}
int bonus_mix_test_124(void){return test(
			"  %hhi    %u    %lli    %x    %hi    %f  ",
			mx_c, mx_u, mx_lli, mx_u, mx_hi, mx_f);}
int bonus_mix_test_125(void){return test(
			"  %c    %x    %hhi    %i    %f    %p  ",
			mx_c, mx_u, mx_c, mx_i, mx_f, &mx_i);}
int bonus_mix_test_126(void){return test(
			"  %c    %f    %X    %x    %u    %i  ",
			mx_c, mx_f, mx_u, mx_u, mx_u, mx_i);}
int bonus_mix_test_127(void){return test(
			"  %i    %p    %f    %o    %li    %f  ",
			mx_i, &mx_i, mx_f, mx_u, mx_li, mx_f);}
int bonus_mix_test_128(void){return test(
			"  %hi    %o    %i    %f    %lli    %p  ",
			mx_hi, mx_u, mx_i, mx_f, mx_lli, &mx_i);}
int bonus_mix_test_129(void){return test(
			"  %u    %c    %s    %lli    %X    %x  ",
			mx_u, mx_c, mx_s, mx_lli, mx_u, mx_u);}
int bonus_mix_test_130(void){return test(
			"  %li    %f    %p    %hhi    %i    %u  ",
			mx_li, mx_f, &mx_i, mx_c, mx_i, mx_u);}
int bonus_mix_test_131(void){return test(
			"  %u    %c    %p    %o    %hhi    %f  ",
			mx_u, mx_c, &mx_i, mx_u, mx_c, mx_f);}
int bonus_mix_test_132(void){return test(
			"  %u    %f    %lli    %i    %f    %hi  ",
			mx_u, mx_f, mx_lli, mx_i, mx_f, mx_hi);}
int bonus_mix_test_133(void){return test(
			"  %x    %s    %i    %hhi    %f    %li  ",
			mx_u, mx_s, mx_i, mx_c, mx_f, mx_li);}
int bonus_mix_test_134(void){return test(
			"  %f    %p    %o    %hi    %x    %li  ",
			mx_f, &mx_i, mx_u, mx_hi, mx_u, mx_li);}
int bonus_mix_test_135(void){return test(
			"  %p    %X    %s    %li    %u    %c  ",
			&mx_i, mx_u, mx_s, mx_li, mx_u, mx_c);}
int bonus_mix_test_136(void){return test(
			"  %hhi    %o    %X    %p    %s    %li  ",
			mx_c, mx_u, mx_u, &mx_i, mx_s, mx_li);}
int bonus_mix_test_137(void){return test(
			"  %p    %hhi    %i    %x    %X    %f  ",
			&mx_i, mx_c, mx_i, mx_u, mx_u, mx_f);}
int bonus_mix_test_138(void){return test(
			"  %s    %li    %i    %x    %p    %o  ",
			mx_s, mx_li, mx_i, mx_u, &mx_i, mx_u);}
int bonus_mix_test_139(void){return test(
			"  %i    %X    %lli    %u    %s    %hhi  ",
			mx_i, mx_u, mx_lli, mx_u, mx_s, mx_c);}
int bonus_mix_test_140(void){return test(
			"  %p    %c    %x    %hi    %lli    %u  ",
			&mx_i, mx_c, mx_u, mx_hi, mx_lli, mx_u);}
int bonus_mix_test_141(void){return test(
			"  %lli    %li    %x    %f    %s    %u  ",
			mx_lli, mx_li, mx_u, mx_f, mx_s, mx_u);}
int bonus_mix_test_142(void){return test(
			"  %hhi    %o    %hi    %c    %s    %li  ",
			mx_c, mx_u, mx_hi, mx_c, mx_s, mx_li);}
int bonus_mix_test_143(void){return test(
			"  %p    %hhi    %lli    %s    %c    %u  ",
			&mx_i, mx_c, mx_lli, mx_s, mx_c, mx_u);}
int bonus_mix_test_144(void){return test(
			"  %x    %p    %i    %f    %u    %s  ",
			mx_u, &mx_i, mx_i, mx_f, mx_u, mx_s);}
int bonus_mix_test_145(void){return test(
			"  %li    %hhi    %u    %i    %X    %o  ",
			mx_li, mx_c, mx_u, mx_i, mx_u, mx_u);}
int bonus_mix_test_146(void){return test(
			"  %u    %c    %p    %hhi    %X    %f  ",
			mx_u, mx_c, &mx_i, mx_c, mx_u, mx_f);}
int bonus_mix_test_147(void){return test(
			"  %hhi    %li    %p    %s    %f    %o  ",
			mx_c, mx_li, &mx_i, mx_s, mx_f, mx_u);}
int bonus_mix_test_148(void){return test(
			"  %lli    %s    %X    %i    %hi    %c  ",
			mx_lli, mx_s, mx_u, mx_i, mx_hi, mx_c);}
int bonus_mix_test_149(void){return test(
			"  %c    %p    %li    %X    %s    %lli  ",
			mx_c, &mx_i, mx_li, mx_u, mx_s, mx_lli);}
int bonus_mix_test_150(void){return test(
			"  %X    %lli    %c    %i    %f    %u  ",
			mx_u, mx_lli, mx_c, mx_i, mx_f, mx_u);}
int bonus_mix_test_151(void){return test(
			"  %f    %c    %hhi    %u    %hi    %x  ",
			mx_f, mx_c, mx_c, mx_u, mx_hi, mx_u);}
int bonus_mix_test_152(void){return test(
			"  %li    %hi    %o    %s    %lli    %hhi  ",
			mx_li, mx_hi, mx_u, mx_s, mx_lli, mx_c);}
int bonus_mix_test_153(void){return test(
			"  %f    %li    %hhi    %s    %p    %c  ",
			mx_f, mx_li, mx_c, mx_s, &mx_i, mx_c);}
int bonus_mix_test_154(void){return test(
			"  %p    %X    %o    %u    %lli    %li  ",
			&mx_i, mx_u, mx_u, mx_u, mx_lli, mx_li);}
int bonus_mix_test_155(void){return test(
			"  %li    %X    %u    %i    %f    %hi  ",
			mx_li, mx_u, mx_u, mx_i, mx_f, mx_hi);}
int bonus_mix_test_156(void){return test(
			"  %f    %i    %X    %c    %hhi    %f  ",
			mx_f, mx_i, mx_u, mx_c, mx_c, mx_f);}
int bonus_mix_test_157(void){return test(
			"  %p    %i    %f    %c    %li    %X  ",
			&mx_i, mx_i, mx_f, mx_c, mx_li, mx_u);}
int bonus_mix_test_158(void){return test(
			"  %i    %p    %c    %f    %x    %li  ",
			mx_i, &mx_i, mx_c, mx_f, mx_u, mx_li);}
int bonus_mix_test_159(void){return test(
			"  %li    %X    %f    %o    %s    %f  ",
			mx_li, mx_u, mx_f, mx_u, mx_s, mx_f);}
int bonus_mix_test_160(void){return test(
			"  %li    %hi    %hhi    %lli    %f    %p  ",
			mx_li, mx_hi, mx_c, mx_lli, mx_f, &mx_i);}
int bonus_mix_test_161(void){return test(
			"  %f    %hhi    %li    %c    %X    %hi  ",
			mx_f, mx_c, mx_li, mx_c, mx_u, mx_hi);}
int bonus_mix_test_162(void){return test(
			"  %lli    %c    %o    %li    %u    %i  ",
			mx_lli, mx_c, mx_u, mx_li, mx_u, mx_i);}
int bonus_mix_test_163(void){return test(
			"  %f    %li    %i    %lli    %hi    %c  ",
			mx_f, mx_li, mx_i, mx_lli, mx_hi, mx_c);}
int bonus_mix_test_164(void){return test(
			"  %p    %lli    %hi    %x    %li    %f  ",
			&mx_i, mx_lli, mx_hi, mx_u, mx_li, mx_f);}
int bonus_mix_test_165(void){return test(
			"  %u    %hhi    %p    %lli    %hi    %x  ",
			mx_u, mx_c, &mx_i, mx_lli, mx_hi, mx_u);}
int bonus_mix_test_166(void){return test(
			"  %p    %hhi    %s    %li    %f    %hi  ",
			&mx_i, mx_c, mx_s, mx_li, mx_f, mx_hi);}
int bonus_mix_test_167(void){return test(
			"  %s    %lli    %p    %i    %u    %hhi  ",
			mx_s, mx_lli, &mx_i, mx_i, mx_u, mx_c);}
int bonus_mix_test_168(void){return test(
			"  %p    %o    %f    %X    %c    %u  ",
			&mx_i, mx_u, mx_f, mx_u, mx_c, mx_u);}
int bonus_mix_test_169(void){return test(
			"  %p    %i    %X    %lli    %c    %hhi  ",
			&mx_i, mx_i, mx_u, mx_lli, mx_c, mx_c);}
int bonus_mix_test_170(void){return test(
			"  %i    %lli    %p    %o    %X    %f  ",
			mx_i, mx_lli, &mx_i, mx_u, mx_u, mx_f);}
int bonus_mix_test_171(void){return test(
			"  %f    %p    %c    %hi    %li    %i  ",
			mx_f, &mx_i, mx_c, mx_hi, mx_li, mx_i);}
int bonus_mix_test_172(void){return test(
			"  %lli    %o    %i    %hhi    %c    %X  ",
			mx_lli, mx_u, mx_i, mx_c, mx_c, mx_u);}
int bonus_mix_test_173(void){return test(
			"  %p    %hi    %lli    %X    %x    %o  ",
			&mx_i, mx_hi, mx_lli, mx_u, mx_u, mx_u);}
int bonus_mix_test_174(void){return test(
			"  %hhi    %X    %u    %p    %x    %lli  ",
			mx_c, mx_u, mx_u, &mx_i, mx_u, mx_lli);}
int bonus_mix_test_175(void){return test(
			"  %s    %f    %f    %hhi    %x    %o  ",
			mx_s, mx_f, mx_f, mx_c, mx_u, mx_u);}
int bonus_mix_test_176(void){return test(
			"  %X    %f    %x    %o    %hi    %u  ",
			mx_u, mx_f, mx_u, mx_u, mx_hi, mx_u);}
int bonus_mix_test_177(void){return test(
			"  %u    %hhi    %p    %o    %X    %x  ",
			mx_u, mx_c, &mx_i, mx_u, mx_u, mx_u);}
int bonus_mix_test_178(void){return test(
			"  %f    %i    %lli    %o    %X    %c  ",
			mx_f, mx_i, mx_lli, mx_u, mx_u, mx_c);}
int bonus_mix_test_179(void){return test(
			"  %lli    %o    %li    %X    %p    %c  ",
			mx_lli, mx_u, mx_li, mx_u, &mx_i, mx_c);}
int bonus_mix_test_180(void){return test(
			"  %hi    %x    %i    %o    %c    %hhi  ",
			mx_hi, mx_u, mx_i, mx_u, mx_c, mx_c);}
int bonus_mix_test_181(void){return test(
			"  %hi    %X    %hhi    %s    %lli    %c  ",
			mx_hi, mx_u, mx_c, mx_s, mx_lli, mx_c);}
int bonus_mix_test_182(void){return test(
			"  %hhi    %c    %f    %f    %li    %i  ",
			mx_c, mx_c, mx_f, mx_f, mx_li, mx_i);}
int bonus_mix_test_183(void){return test(
			"  %lli    %x    %hi    %c    %hhi    %i  ",
			mx_lli, mx_u, mx_hi, mx_c, mx_c, mx_i);}
int bonus_mix_test_184(void){return test(
			"  %s    %X    %f    %x    %hi    %i  ",
			mx_s, mx_u, mx_f, mx_u, mx_hi, mx_i);}
int bonus_mix_test_185(void){return test(
			"  %li    %hhi    %f    %f    %c    %o  ",
			mx_li, mx_c, mx_f, mx_f, mx_c, mx_u);}
int bonus_mix_test_186(void){return test(
			"  %f    %i    %li    %u    %X    %hhi  ",
			mx_f, mx_i, mx_li, mx_u, mx_u, mx_c);}
int bonus_mix_test_187(void){return test(
			"  %hi    %f    %f    %o    %s    %hhi  ",
			mx_hi, mx_f, mx_f, mx_u, mx_s, mx_c);}
int bonus_mix_test_188(void){return test(
			"  %u    %x    %hi    %f    %lli    %X  ",
			mx_u, mx_u, mx_hi, mx_f, mx_lli, mx_u);}
int bonus_mix_test_189(void){return test(
			"  %o    %u    %X    %s    %i    %hi  ",
			mx_u, mx_u, mx_u, mx_s, mx_i, mx_hi);}
int bonus_mix_test_190(void){return test(
			"  %X    %s    %hhi    %u    %o    %lli  ",
			mx_u, mx_s, mx_c, mx_u, mx_u, mx_lli);}
int bonus_mix_test_191(void){return test(
			"  %c    %f    %x    %lli    %u    %o  ",
			mx_c, mx_f, mx_u, mx_lli, mx_u, mx_u);}
int bonus_mix_test_192(void){return test(
			"  %f    %u    %li    %x    %c    %hhi  ",
			mx_f, mx_u, mx_li, mx_u, mx_c, mx_c);}
int bonus_mix_test_193(void){return test(
			"  %o    %i    %hi    %x    %hhi    %li  ",
			mx_u, mx_i, mx_hi, mx_u, mx_c, mx_li);}
int bonus_mix_test_194(void){return test(
			"  %f    %s    %i    %c    %X    %li  ",
			mx_f, mx_s, mx_i, mx_c, mx_u, mx_li);}
int bonus_mix_test_195(void){return test(
			"  %li    %s    %X    %o    %lli    %f  ",
			mx_li, mx_s, mx_u, mx_u, mx_lli, mx_f);}
int bonus_mix_test_196(void){return test(
			"  %c    %o    %f    %f    %lli    %X  ",
			mx_c, mx_u, mx_f, mx_f, mx_lli, mx_u);}
int bonus_mix_test_197(void){return test(
			"  %hi    %o    %i    %f    %li    %x  ",
			mx_hi, mx_u, mx_i, mx_f, mx_li, mx_u);}
int bonus_mix_test_198(void){return test(
			"  %p    %i    %x    %f    %u    %o  ",
			&mx_i, mx_i, mx_u, mx_f, mx_u, mx_u);}
int bonus_mix_test_199(void){return test(
			"  %f    %f    %c    %hi    %hhi    %li  ",
			mx_f, mx_f, mx_c, mx_hi, mx_c, mx_li);}

int bonus_mix_test_extra_1(void){return test(
			"  %o    %f    %i    %%    %hhi    %f  ",
			mx_u, mx_f, mx_i, mx_c, mx_f);}
int bonus_mix_test_extra_2(void){return test(
			"  %li    %f    %f    %i    %lli    %c  ",
			mx_li, mx_f, mx_f, mx_i, mx_lli, mx_c);}
int bonus_mix_test_extra_3(void){return test(
			"  %li    %%    %f    %i    %lli    %c  ",
			mx_li, mx_f, mx_i, mx_lli, mx_c);}
int bonus_mix_test_extra_4(void){return test(
			"  %%    %f    %f    %i    %%    %c  ",
			mx_f, mx_f, mx_i, mx_c);}
int bonus_mix_test_extra_5(void){return test(
			"  %li    %f    %f    %%    %lli    %%  ",
			mx_li, mx_f, mx_f, mx_lli);}
int bonus_mix_test_extra_6(void){return test(
			"  %li    %f    %f    %i    %lli    %c  ",
			mx_li, mx_f, mx_f, mx_i, mx_lli, mx_c);}
int bonus_mix_test_extra_7(void){return test(
			"  %%    %f    %%    %i    %lli    %c  ",
			mx_f, mx_i, mx_lli, mx_c);}
int bonus_mix_test_extra_8(void){return test(
			"  %%    %u    %hhi    %li    %hi    %x  ",
			mx_u, mx_c, mx_li, mx_hi, mx_u);}
int bonus_mix_test_extra_9(void){return test(
			"  %c    %u    %hhi    %%    %hi    %x  ",
			mx_c, mx_u, mx_c, mx_hi, mx_u);}
int bonus_mix_test_extra_10(void){return test(
			"  %c    %%    %hhi    %p    %hi    %x  ",
			mx_c, mx_hhi, &mx_c, mx_hi, mx_u);}

int bonus_mix_successive_0(void){return ( test("%c", mx_c) + test("%u", mx_u));}
int bonus_mix_successive_1(void){return ( test("%o", mx_u) + test("%%"));}
int bonus_mix_successive_2(void){return ( test("%s", mx_s) + test("%f", mx_f));}
int bonus_mix_successive_3(void){return ( test("%f", mx_f) + test("%hhi", mx_c));}
int bonus_mix_successive_4(void){return ( test("%x", mx_u) + test("%i", mx_i));}
int bonus_mix_successive_5(void){return ( test("%x", mx_u) + test("%o", mx_u));}
int bonus_mix_successive_6(void){return ( test("%s", mx_s) + test("%c", mx_c));}
int bonus_mix_successive_7(void){return ( test("%p", &mx_i) + test("%hi", mx_hi));}
int bonus_mix_successive_8(void){return ( test("%f", mx_f) + test("%p", &mx_i));}
int bonus_mix_successive_9(void){return ( test("%hi", mx_hi) + test("%u", mx_u));}
int bonus_mix_successive_10(void){return ( test("%u", mx_u) + test("%s", mx_s));}
int bonus_mix_successive_11(void){return ( test("%f", mx_f) + test("%p", &mx_i));}
int bonus_mix_successive_12(void){return ( test("%f", mx_f) + test("%hhi", mx_c));}
int bonus_mix_successive_13(void){return ( test("%X", mx_u) + test("%hhi", mx_c));}
int bonus_mix_successive_14(void){return ( test("%X", mx_u) + test("%f", mx_f));}
int bonus_mix_successive_15(void){return ( test("%hhi", mx_c) + test("%X", mx_u));}
int bonus_mix_successive_16(void){return ( test("%s", mx_s) + test("%x", mx_u));}
int bonus_mix_successive_17(void){return ( test("%lli", mx_lli) + test("%i", mx_i));}
int bonus_mix_successive_18(void){return ( test("%s", mx_s) + test("%o", mx_u));}
int bonus_mix_successive_19(void){return ( test("%hhi", mx_c) + test("%X", mx_u));}
int bonus_mix_successive_20(void){return ( test("%p", &mx_i) + test("%s", mx_s));}
int bonus_mix_successive_21(void){return ( test("%X", mx_u) + test("%x", mx_u));}
int bonus_mix_successive_22(void){return ( test("%p", &mx_i) + test("%lli", mx_lli));}
int bonus_mix_successive_23(void){return ( test("%s", mx_s) + test("%f", mx_f));}
int bonus_mix_successive_24(void){return ( test("%c", mx_c) + test("%hhi", mx_c));}
int bonus_mix_successive_25(void){return ( test("%x", mx_u) + test("%f", mx_f));}
int bonus_mix_successive_26(void){return ( test("%s", mx_s) + test("%li", mx_li));}
int bonus_mix_successive_27(void){return ( test("%f", mx_f) + test("%f", mx_f));}
int bonus_mix_successive_28(void){return ( test("%i", mx_i) + test("%u", mx_u));}
int bonus_mix_successive_29(void){return ( test("%o", mx_u) + test("%li", mx_li));}
int bonus_mix_successive_30(void){return ( test("%s", mx_s) + test("%u", mx_u));}
int bonus_mix_successive_31(void){return ( test("%X", mx_u) + test("%c", mx_c));}
int bonus_mix_successive_32(void){return ( test("%x", mx_u) + test("%u", mx_u));}
int bonus_mix_successive_33(void){return ( test("%f", mx_f) + test("%s", mx_s));}
int bonus_mix_successive_34(void){return ( test("%hhi", mx_c) + test("%u", mx_u));}
int bonus_mix_successive_35(void){return ( test("%p", &mx_i) + test("%f", mx_f));}
int bonus_mix_successive_36(void){return ( test("%li", mx_li) + test("%o", mx_u));}
int bonus_mix_successive_37(void){return ( test("%s", mx_s) + test("%li", mx_li));}
int bonus_mix_successive_38(void){return ( test("%o", mx_u) + test("%lli", mx_lli));}
int bonus_mix_successive_39(void){return ( test("%i", mx_i) + test("%c", mx_c));}
int bonus_mix_successive_40(void){return ( test("%c", mx_c) + test("%x", mx_u));}
int bonus_mix_successive_41(void){return ( test("%hhi", mx_c) + test("%x", mx_u));}
int bonus_mix_successive_42(void){return ( test("%x", mx_u) + test("%s", mx_s));}
int bonus_mix_successive_43(void){return ( test("%u", mx_u) + test("%x", mx_u));}
int bonus_mix_successive_44(void){return ( test("%i", mx_i) + test("%f", mx_f));}
int bonus_mix_successive_45(void){return ( test("%s", mx_s) + test("%c", mx_c));}
int bonus_mix_successive_46(void){return ( test("%i", mx_i) + test("%s", mx_s));}
int bonus_mix_successive_47(void){return ( test("%u", mx_u) + test("%hhi", mx_c));}
int bonus_mix_successive_48(void){return ( test("%hi", mx_hi) + test("%o", mx_u));}
int bonus_mix_successive_49(void){return ( test("%i", mx_i) + test("%hi", mx_hi));}
int bonus_mix_successive_50(void){return ( test("%o", mx_u) + test("%f", mx_f));}
int bonus_mix_successive_51(void){return ( test("%li", mx_li) + test("%hhi", mx_c));}
int bonus_mix_successive_52(void){return ( test("%hi", mx_hi) + test("%hhi", mx_c));}
int bonus_mix_successive_53(void){return ( test("%f", mx_f) + test("%x", mx_u));}
int bonus_mix_successive_54(void){return ( test("%c", mx_c) + test("%hi", mx_hi));}
int bonus_mix_successive_55(void){return ( test("%hi", mx_hi) + test("%s", mx_s));}
int bonus_mix_successive_56(void){return ( test("%i", mx_i) + test("%lli", mx_lli));}
int bonus_mix_successive_57(void){return ( test("%c", mx_c) + test("%f", mx_f));}
int bonus_mix_successive_58(void){return ( test("%f", mx_f) + test("%x", mx_u));}
int bonus_mix_successive_59(void){return ( test("%s", mx_s) + test("%li", mx_li));}
int bonus_mix_successive_60(void){return ( test("%hhi", mx_c) + test("%s", mx_s));}
int bonus_mix_successive_61(void){return ( test("%p", &mx_i) + test("%c", mx_c));}
int bonus_mix_successive_62(void){return ( test("%lli", mx_lli) + test("%u", mx_u));}
int bonus_mix_successive_63(void){return ( test("%x", mx_u) + test("%o", mx_u));}
int bonus_mix_successive_64(void){return ( test("%s", mx_s) + test("%c", mx_c));}
int bonus_mix_successive_65(void){return ( test("%i", mx_i) + test("%lli", mx_lli));}
int bonus_mix_successive_66(void){return ( test("%li", mx_li) + test("%f", mx_f));}
int bonus_mix_successive_67(void){return ( test("%hi", mx_hi) + test("%x", mx_u));}
int bonus_mix_successive_68(void){return ( test("%i", mx_i) + test("%hi", mx_hi));}
int bonus_mix_successive_69(void){return ( test("%f", mx_f) + test("%li", mx_li));}
int bonus_mix_successive_70(void){return ( test("%o", mx_u) + test("%li", mx_li));}


/* -----------------------------------------------------------------------------
** 				ARBITRARY ARGUMENT NUMBERS TESTS - NOT REQUIRED
** ---------------------------------------------------------------------------*/
int argnum_notinsubject_simple_swap(void){return test("%2$s, %1$s!", "world", "hello");} //CAN-SEGFAULT
int argnum_notinsubject_swap_around_pct(void){return test("%2$s %% %1$s!", "world", "hello");} //CAN-SEGFAULT
int argnum_notinsubject_swap_strfloat(void){return test("%2$f, %1$s!", "world", 5.75);} //CAN-SEGFAULT
int argnum_notinsubject_swap_floatstr(void){return test("%2$s, %1$f!", 5.75, "abc");} //CAN-SEGFAULT
int argnum_notinsubject_swap_ldblstr(void){return test("%2$s, %1$Lf!", 5.75L, "abc");} //CAN-SEGFAULT
int argnum_notinsubject_swap_strldbl(void){return test("%2$Lf, %1$s!", "world", 5.75L);} //CAN-SEGFAULT
int argnum_notinsubject_swap_ldblchar(void){return test("%2$c, %1$Lf!", 5.75L, 'c');} //CAN-SEGFAULT
int argnum_notinsubject_swap_charldbl(void){return test("%2$Lf, %1$c!", 'c', 5.75L);} //CAN-SEGFAULT
int argnum_notinsubject_swap_floatstr_around_pct(void){return test("%2$s %% %1$f!", 5.75, "abc");} //CAN-SEGFAULT
int argnum_notinsubject_swap_strfloat_around_pct(void){return test("%2$f %% %1$s!", "world", 5.75);} //CAN-SEGFAULT
int argnum_notinsubject_loopback_throwswarning(void){return test("%i %i %1$i %i %i", 1, 2, 3);} //CAN-SEGFAULT
int argnum_notinsubject_onlyone(void){return test("%1$s %1$s %1$s %1$s %1$s %1$s %1$s %1$s.", "buffalo");} //CAN-SEGFAULT
int argnum_notinsubject_start2thentofloatthen1_throwswarning(void){return test("%2$s %f %1$i", 5, "abc", 5.75f);} //CAN-SEGFAULT
int argnum_notinsubject_ultimate_1_throwswarning(void){return test("%2$s %f %1$i %s %f %2$s %1$i %s %1$i %3$f %1$i %s %f %2$s", 5, "abc", 5.75);} //CAN-SEGFAULT
int argnum_notinsubject_ultimate_2_throwswarning(void){return test("%4$.5s %.4i %lli %1$Lf %c %7$20.6s %5$i %2$c %1$.2Lf %c %i", //CAN-SEGFAULT
			5.75l, 'c', -17, "Atlanta, GA", 54, 9879879879879ll, "baby shark");}
int argnum_notinsubject_ultimate_2_with_pct_throwswarning(void){return test("%% %4$.5s %.4i %lli %% %1$Lf %c %7$20.6s %5$i %% %2$c %1$.2Lf %c %i", //CAN-SEGFAULT
			5.75l, 'c', -17, "Atlanta, GA", 54, 9879879879879ll, "baby shark");}


/* -----------------------------------------------------------------------------
** 					%Lf LONG DOUBLES TESTS (NOT IN THE SUBJECT)
** ---------------------------------------------------------------------------*/
//Long Doubles - Basic
int notinsubject_f_L_basic_1(void){return test("this %Lf float", 1.5l);}
int notinsubject_f_L_basic_fltonly(void){return test("%Lf", 7.5l);}
int notinsubject_f_L_basic_whole(void){return test("%Lf", 1.0l);}
int notinsubject_f_L_basic_negative(void){return test("%Lf", -3.85l);}
int notinsubject_f_L_basic_positive_3_3(void){return test("%Lf", 573.924l);}
int notinsubject_f_L_basic_negative_3_3(void){return test("%Lf", -958.125l);}
int notinsubject_f_L_basic_positive_smallfpart(void){return test("%Lf", 23.00041l);}
int notinsubject_f_L_basic_positive_allsmall(void){return test("%Lf", 0.000039l);}
int notinsubject_f_L_basic_negative_smallfpart(void){return test("%Lf", -7.00036l);}
int notinsubject_f_L_basic_negative_allsmall(void){return test("%Lf", -0.00032l);}
int notinsubject_f_L_basic_limits_allsmall_pos(void){return test("%Lf", 0.000001l);}
int notinsubject_f_L_basic_limits_allsmall_neg(void){return test("%Lf", -0.000001l);}
int notinsubject_f_L_basic_limits_smallfpart_pos(void){return test("%Lf", 9873.000001l);}
int notinsubject_f_L_basic_limits_smallfpart_neg(void){return test("%Lf", -875.000001l);}
int notinsubject_f_L_basic_limits_allbig_pos(void){return test("%Lf", 999.999999l);}
int notinsubject_f_L_basic_limits_allbig_neg(void){return test("%Lf", -99.999999l);}
int notinsubject_f_L_basic_limits_bigfpart_pos(void){return test("%Lf", 0.999999l);}
int notinsubject_f_L_basic_limits_bigfpart_neg(void){return test("%Lf", -0.999999l);}
//Long Doubles - Rounding with default precision
int notinsubject_f_L_rndd_pos(void){return test("%Lf", 23.375094499l);}
int notinsubject_f_L_rndd_neg(void){return test("%Lf", -985.765426499l);}
int notinsubject_f_L_rndu_pos(void){return test("%Lf", 0.08942555l);}
int notinsubject_f_L_rndu_neg(void){return test("%Lf", -56.2012685l);}
int notinsubject_f_L_rndu_multidigit_pos(void){return test("%Lf", 43.4399999l);}
int notinsubject_f_L_rndu_multidigit_neg(void){return test("%Lf", -5.0299999l);}
int notinsubject_f_L_rndd_multidigit_pos(void){return test("%Lf", 43.43999949l);}
int notinsubject_f_L_rndd_multidigit_neg(void){return test("%Lf", -5.02999949l);}
int notinsubject_f_L_rndd_wholnobump_pos(void){return test("%Lf", 1.99999949l);}
int notinsubject_f_L_rndd_wholnobump_neg(void){return test("%Lf", -0.99999949l);}
int notinsubject_f_L_rndu_bumpwhole_pos(void){return test("%Lf", 3.9999999l);}
int notinsubject_f_L_rndu_bumpwhole_neg(void){return test("%Lf", -5.9999999l);}
//Long Doubles - Prec 7
int notinsubject_f_L_prec7_1(void){return test("this %.7Lf float", 1.5l);}
int notinsubject_f_L_prec7_fltonly(void){return test("%.7Lf", 7.5l);}
int notinsubject_f_L_prec7_whole(void){return test("%.7Lf", 1.0l);}
int notinsubject_f_L_prec7_negative(void){return test("%.7Lf", -3.85l);}
int notinsubject_f_L_prec7_positive_3_3(void){return test("%.7Lf", 573.924l);}
int notinsubject_f_L_prec7_negative_3_3(void){return test("%.7Lf", -958.125l);}
int notinsubject_f_L_prec7_positive_smallfpart(void){return test("%.7Lf", 23.00041l);}
int notinsubject_f_L_prec7_positive_allsmall(void){return test("%.7Lf", 0.0000039l);}
int notinsubject_f_L_prec7_negative_smallfpart(void){return test("%.7Lf", -7.00036l);}
int notinsubject_f_L_prec7_negative_allsmall(void){return test("%.7Lf", -0.000032l);}
int notinsubject_f_L_prec7_limits_allsmall_pos(void){return test("%.7Lf", 0.0000001l);}
int notinsubject_f_L_prec7_limits_allsmall_neg(void){return test("%.7Lf", -0.0000001l);}
int notinsubject_f_L_prec7_limits_smallfpart_pos(void){return test("%.7Lf", 9873.000001l);}
int notinsubject_f_L_prec7_limits_smallfpart_neg(void){return test("%.7Lf", -875.000001l);}
int notinsubject_f_L_prec7_limits_allbig_pos(void){return test("%.7Lf", 999.9999999l);}
int notinsubject_f_L_prec7_limits_allbig_neg(void){return test("%.7Lf", -99.9999999l);}
int notinsubject_f_L_prec7_limits_bigfpart_pos(void){return test("%.7Lf", 0.999999l);}
int notinsubject_f_L_prec7_limits_bigfpart_neg(void){return test("%.7Lf", -0.999999l);}
//Long Doubles - Prec 7 Rounding
int notinsubject_f_L_rnd_prec7_rndd_pos(void){return test("%.7Lf", 23.375094499l);}
int notinsubject_f_L_rnd_prec7_rndd_neg(void){return test("%.7Lf", -985.765426499l);}
int notinsubject_f_L_rnd_prec7_rndu_pos(void){return test("%.7Lf", 0.0894255l);}
int notinsubject_f_L_rnd_prec7_rndu_neg(void){return test("%.7Lf", -56.2012685l);}
int notinsubject_f_L_rnd_prec7_rndu_multidigit_pos(void){return test("%.7Lf", 43.4399999l);}
int notinsubject_f_L_rnd_prec7_rndu_multidigit_neg(void){return test("%.7Lf", -5.0299999l);}
int notinsubject_f_L_rnd_prec7_rndd_multidigit_pos(void){return test("%.7Lf", 43.43999949l);}
int notinsubject_f_L_rnd_prec7_rndd_multidigit_neg(void){return test("%.7Lf", -5.02999949l);}
int notinsubject_f_L_rnd_prec7_rndd_wholnobump_pos(void){return test("%.7Lf", 1.99999949l);}
int notinsubject_f_L_rnd_prec7_rndd_wholnobump_neg(void){return test("%.7Lf", -0.99999949l);}
int notinsubject_f_L_rnd_prec7_rndu_bumpwhole_pos(void){return test("%.7Lf", 3.9999999l);}
//Long Doubles - Prec 8
int notinsubject_f_L_prec8_1(void){return test("this %.8Lf float", 1.5l);}
int notinsubject_f_L_prec8_fltonly(void){return test("%.8Lf", 7.5l);}
int notinsubject_f_L_prec8_whole(void){return test("%.8Lf", 1.0l);}
int notinsubject_f_L_prec8_negative(void){return test("%.8Lf", -3.85l);}
int notinsubject_f_L_prec8_positive_3_3(void){return test("%.8Lf", 573.924l);}
int notinsubject_f_L_prec8_negative_3_3(void){return test("%.8Lf", -958.125l);}
int notinsubject_f_L_prec8_positive_smallfpart(void){return test("%.8Lf", 23.00041l);}
int notinsubject_f_L_prec8_positive_allsmall(void){return test("%.8Lf", 0.00000039l);}
int notinsubject_f_L_prec8_negative_smallfpart(void){return test("%.8Lf", -7.00036l);}
int notinsubject_f_L_prec8_negative_allsmall(void){return test("%.8Lf", -0.0000032l);}
int notinsubject_f_L_prec8_limits_allsmall_pos(void){return test("%.8Lf", 0.00000001l);}
int notinsubject_f_L_prec8_limits_allsmall_neg(void){return test("%.8Lf", -0.00000001l);}
int notinsubject_f_L_prec8_limits_smallfpart_pos(void){return test("%.8Lf", 9873.000001l);}
int notinsubject_f_L_prec8_limits_smallfpart_neg(void){return test("%.8Lf", -875.000001l);}
int notinsubject_f_L_prec8_limits_allbig_pos(void){return test("%.8Lf", 999.9999999l);}
int notinsubject_f_L_prec8_limits_allbig_neg(void){return test("%.8Lf", -99.99999999l);}
int notinsubject_f_L_prec8_limits_bigfpart_pos(void){return test("%.8Lf", 0.999999l);}
int notinsubject_f_L_prec8_limits_bigfpart_neg(void){return test("%.8Lf", -0.999999l);}
//Long Doubles - Prec 8 Rounding
int notinsubject_f_L_rnd_prec8_rndd_pos(void){return test("%.8Lf", 23.375094499l);}
int notinsubject_f_L_rnd_prec8_rndd_neg(void){return test("%.8Lf", -985.765426499l);}
int notinsubject_f_L_rnd_prec8_rndu_pos(void){return test("%.8Lf", 0.0894255l);}
int notinsubject_f_L_rnd_prec8_rndu_neg(void){return test("%.8Lf", -56.2012685l);}
int notinsubject_f_L_rnd_prec8_rndu_multidigit_pos(void){return test("%.8Lf", 43.4399999l);}
int notinsubject_f_L_rnd_prec8_rndu_multidigit_neg(void){return test("%.8Lf", -5.0299999l);}
int notinsubject_f_L_rnd_prec8_rndd_multidigit_pos(void){return test("%.8Lf", 43.43999949l);}
int notinsubject_f_L_rnd_prec8_rndd_multidigit_neg(void){return test("%.8Lf", -5.02999949l);}
int notinsubject_f_L_rnd_prec8_rndd_wholnobump_pos(void){return test("%.8Lf", 1.99999949l);}
int notinsubject_f_L_rnd_prec8_rndd_wholnobump_neg(void){return test("%.8Lf", -0.99999949l);}
int notinsubject_f_L_rnd_prec8_rndu_bumpwhole_pos(void){return test("%.8Lf", 3.9999999l);}
//Long Doubles - Prec 9
int notinsubject_f_L_prec9_1(void){return test("this %.9Lf float", 1.5l);}
int notinsubject_f_L_prec9_fltonly(void){return test("%.9Lf", 7.5l);}
int notinsubject_f_L_prec9_whole(void){return test("%.9Lf", 1.0l);}
int notinsubject_f_L_prec9_negative(void){return test("%.9Lf", -3.85l);}
int notinsubject_f_L_prec9_positive_3_3(void){return test("%.9Lf", 573.924l);}
int notinsubject_f_L_prec9_negative_3_3(void){return test("%.9Lf", -958.125l);}
int notinsubject_f_L_prec9_positive_smallfpart(void){return test("%.9Lf", 23.00041l);}
int notinsubject_f_L_prec9_positive_allsmall(void){return test("%.9Lf", 0.00000039l);}
int notinsubject_f_L_prec9_negative_smallfpart(void){return test("%.9Lf", -7.00036l);}
int notinsubject_f_L_prec9_negative_allsmall(void){return test("%.9Lf", -0.0000032l);}
int notinsubject_f_L_prec9_limits_allsmall_pos(void){return test("%.9Lf", 0.00000001l);}
int notinsubject_f_L_prec9_limits_allsmall_neg(void){return test("%.9Lf", -0.00000001l);}
int notinsubject_f_L_prec9_limits_smallfpart_pos(void){return test("%.9Lf", 9873.000001l);}
int notinsubject_f_L_prec9_limits_smallfpart_neg(void){return test("%.9Lf", -875.000001l);}
int notinsubject_f_L_prec9_limits_allbig_pos(void){return test("%.9Lf", 999.99999999l);}
int notinsubject_f_L_prec9_limits_allbig_neg(void){return test("%.9Lf", -99.99999999l);}
int notinsubject_f_L_prec9_limits_bigfpart_pos(void){return test("%.9Lf", 0.999999l);}
int notinsubject_f_L_prec9_limits_bigfpart_neg(void){return test("%.9Lf", -0.999999l);}
//Long Doubles - Prec 9 Rounding
int notinsubject_f_L_rnd_prec9_rndd_pos(void){return test("%.9Lf", 23.375094499l);}
int notinsubject_f_L_rnd_prec9_rndd_neg(void){return test("%.9Lf", -985.765426499l);}
int notinsubject_f_L_rnd_prec9_rndu_pos(void){return test("%.9Lf", 0.0894255l);}
int notinsubject_f_L_rnd_prec9_rndu_neg(void){return test("%.9Lf", -56.2012685l);}
int notinsubject_f_L_rnd_prec9_rndu_multidigit_pos(void){return test("%.9Lf", 43.4399999l);}
int notinsubject_f_L_rnd_prec9_rndu_multidigit_neg(void){return test("%.9Lf", -5.0299999l);}
int notinsubject_f_L_rnd_prec9_rndd_multidigit_pos(void){return test("%.9Lf", 43.43999949l);}
int notinsubject_f_L_rnd_prec9_rndd_multidigit_neg(void){return test("%.9Lf", -5.02999949l);}
int notinsubject_f_L_rnd_prec9_rndd_wholnobump_pos(void){return test("%.9Lf", 1.99999949l);}
int notinsubject_f_L_rnd_prec9_rndd_wholnobump_neg(void){return test("%.9Lf", -0.99999949l);}
int notinsubject_f_L_rnd_prec9_rndu_bumpwhole_pos(void){return test("%.9Lf", 3.9999999l);}
//Long Doubles - Prec 10
int notinsubject_f_L_stress_prec10_1(void){return test("this %.10Lf float", 1.5l);}
int notinsubject_f_L_stress_prec10_fltonly(void){return test("%.10Lf", 7.5l);}
int notinsubject_f_L_stress_prec10_whole(void){return test("%.10Lf", 1.0l);}
int notinsubject_f_L_stress_prec10_negative(void){return test("%.10Lf", -3.85l);}
int notinsubject_f_L_stress_prec10_positive_3_10(void){return test("%.10Lf", 573.924l);}
int notinsubject_f_L_stress_prec10_negative_3_10(void){return test("%.10Lf", -958.125l);}
int notinsubject_f_L_stress_prec10_pos(void){return test("%.10Lf", 23.8341375094l);}
int notinsubject_f_L_stress_prec10_neg(void){return test("%.10Lf", -985.2459765426l);}
int notinsubject_f_L_stress_prec10_rndd_pos(void){return test("%.10Lf", 23.8341375094499l);}
int notinsubject_f_L_stress_prec10_rndd_neg(void){return test("%.10Lf", -985.2459765426499l);}
int notinsubject_f_L_stress_prec10_rndu_pos(void){return test("%.10Lf", 0.87650894255l);}
int notinsubject_f_L_stress_prec10_rndu_neg(void){return test("%.10Lf", -56.47852012685l);}
int notinsubject_f_L_stress_prec10_positive_smallfpart(void){return test("%.10Lf", 23.000000041l);}
int notinsubject_f_L_stress_prec10_positive_allsmall(void){return test("%.10Lf", 0.0000000039l);}
int notinsubject_f_L_stress_prec10_negative_smallfpart(void){return test("%.10Lf", -7.000000036l);}
int notinsubject_f_L_stress_prec10_negative_allsmall(void){return test("%.10Lf", -0.000000032l);}
int notinsubject_f_L_stress_prec10_limits_allsmall_pos(void){return test("%.10Lf", 0.0000000001l);}
int notinsubject_f_L_stress_prec10_limits_allsmall_neg(void){return test("%.10Lf", -0.0000000001l);}
int notinsubject_f_L_stress_prec10_limits_smallfpart_pos(void){return test("%.10Lf", 9873.0000000001l);}
int notinsubject_f_L_stress_prec10_limits_smallfpart_neg(void){return test("%.10Lf", -875.0000000001l);}
int notinsubject_f_L_stress_prec10_limits_allbig_pos(void){return test("%.10Lf", 999.9999999999l);}
int notinsubject_f_L_stress_prec10_limits_allbig_neg(void){return test("%.10Lf", -99.9999999999l);}
int notinsubject_f_L_stress_prec10_limits_bigfpart_pos(void){return test("%.10Lf", 0.9999999999l);}
int notinsubject_f_L_stress_prec10_limits_bigfpart_neg(void){return test("%.10Lf", -0.9999999999l);}
//Long Doubles - Prec 12
int notinsubject_f_L_stress_prec12_rndu(void){return test("%.12f",        1.025978542436587568678);}
int notinsubject_f_L_stress_prec12_rndd(void){return test("%.12f",        1.025978548534310421434);}
int notinsubject_f_L_stress_prec12_limits_tiny(void){return test("%.12f", 0.000000000001000000000);}
int notinsubject_f_L_stress_prec12_limits_big(void){return test("%.12f",  0.999999999999000000000);}
//Long Doubles - Prec 14
int notinsubject_f_L_stress_prec14_rndu(void){return test("%.14f",        1.025978542436587568678);}
int notinsubject_f_L_stress_prec14_rndd(void){return test("%.14f",        1.025978548534310421434);}
int notinsubject_f_L_stress_prec14_limits_tiny(void){return test("%.14f", 0.000000000000010000000);}
int notinsubject_f_L_stress_prec14_limits_big(void){return test("%.14f",  0.999999999999990000000);}
//Long Doubles - Prec 16
int notinsubject_f_L_stress_prec16_rndu(void){return test("%.16f",        1.025978542436587568678);}
int notinsubject_f_L_stress_prec16_rndd(void){return test("%.16f",        1.025978548534310421634);}
int notinsubject_f_L_stress_prec16_limits_tiny(void){return test("%.16f", 0.000000000000000100000);}
int notinsubject_f_L_stress_prec16_limits_big(void){return test("%.16f",  0.999999999999999900000);}
//Long Doubles - Prec 17
int notinsubject_f_L_stress_prec17_rndu(void){return test("%.17f",        1.025978542436587568678);}
int notinsubject_f_L_stress_prec17_rndd(void){return test("%.17f",        1.025978548534310421734);}
int notinsubject_f_L_stress_prec17_limits_tiny(void){return test("%.17f", 0.000000000000000010000);}
int notinsubject_f_L_stress_prec17_limits_big(void){return test("%.17f",  0.999999999999999990000);}
//Long Doubles - Prec 18
int notinsubject_f_L_stress_prec18_rndu(void){return test("%.18f",        1.025978542436587568678);}
int notinsubject_f_L_stress_prec18_rndd(void){return test("%.18f",        1.025978548534310421834);}
int notinsubject_f_L_stress_prec18_limits_tiny(void){return test("%.18f", 0.000000000000000001000);}
int notinsubject_f_L_stress_prec18_limits_big(void){return test("%.18f",  0.999999999999999999000);}
//Long Doubles - Prec 19
int notinsubject_f_L_stress_prec19_rndu(void){return test("%.19f",        1.025978542436587568678);}
int notinsubject_f_L_stress_prec19_rndd(void){return test("%.19f",        1.025978548534310421934);}
int notinsubject_f_L_stress_prec19_limits_tiny(void){return test("%.19f", 0.000000000000000000100);}
int notinsubject_f_L_stress_prec19_limits_big(void){return test("%.19f",  0.999999999999999999900);}
//Long Doubles - Prec 20
int notinsubject_f_L_stress_prec20_rndu(void){return test("%.20f",        1.025978542436587568678);}
int notinsubject_f_L_stress_prec20_rndd(void){return test("%.20f",        1.025978548534310422034);}
int notinsubject_f_L_stress_prec20_limits_tiny(void){return test("%.20f", 0.000000000000000000010);}
int notinsubject_f_L_stress_prec20_limits_big(void){return test("%.20f",  0.999999999999999999990);}
//Long Doubles of special values
int notinsubject_f_L_reserved_values_inf(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("%Lf", special);}
int notinsubject_f_L_reserved_values_ninf(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%Lf", special);}
int notinsubject_f_L_reserved_values_nan(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%Lf", special);}
int notinsubject_f_L_reserved_values_pzero(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%Lf", special);}
int notinsubject_f_L_reserved_values_nzero(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%Lf", special);}
int notinsubject_f_L_reserved_values_inf_6w(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("%6Lf", special);}
int notinsubject_f_L_reserved_values_ninf_6w(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%6Lf", special);}
int notinsubject_f_L_reserved_values_nan_6w(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%6Lf", special);}
int notinsubject_f_L_reserved_values_pzero_6w(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%6Lf", special);}
int notinsubject_f_L_reserved_values_nzero_6w(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%6Lf", special);}
int notinsubject_f_L_reserved_values_inf_6wlj(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("%-6Lf", special);}
int notinsubject_f_L_reserved_values_ninf_6wlj(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%-6Lf", special);}
int notinsubject_f_L_reserved_values_nan_6wlj(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%-6Lf", special);}
int notinsubject_f_L_reserved_values_pzero_6wlj(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%-6Lf", special);}
int notinsubject_f_L_reserved_values_nzero_6wlj(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%-6Lf", special);}
int notinsubject_f_L_reserved_values_inf_6was(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("%+6Lf", special);}
int notinsubject_f_L_reserved_values_ninf_6was(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%+6Lf", special);}
int notinsubject_f_L_reserved_values_nan_6was(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%+6Lf", special);}
int notinsubject_f_L_reserved_values_pzero_6was(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%+6Lf", special);}
int notinsubject_f_L_reserved_values_nzero_6was(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%+6Lf", special);}
int notinsubject_f_L_reserved_values_inf_10w_prec7(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;  FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("%10.7Lf", special);}
int notinsubject_f_L_reserved_values_ninf_10w_prec7(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%10.7Lf", special);}
int notinsubject_f_L_reserved_values_nan_10w_prec7(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%10.7Lf", special);}
int notinsubject_f_L_reserved_values_pzero_10w_prec7(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%10.7Lf", special);}
int notinsubject_f_L_reserved_values_nzero_10w_prec7(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%10.7Lf", special);}
int notinsubject_f_L_reserved_values_inf_sp_prec7(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;  FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("% .7Lf", special);}
int notinsubject_f_L_reserved_values_ninf_sp_prec7(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("% .7Lf", special);}
int notinsubject_f_L_reserved_values_nan_sp_prec7(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("% .7Lf", special);}
int notinsubject_f_L_reserved_values_pzero_sp_prec7(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("% .7Lf", special);}
int notinsubject_f_L_reserved_values_nzero_sp_prec7(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("% .7Lf", special);}
int notinsubject_f_L_reserved_values_inf_sp(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("% Lf", special);}
int notinsubject_f_L_reserved_values_ninf_sp(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("% Lf", special);}
int notinsubject_f_L_reserved_values_nan_sp(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("% Lf", special);}
int notinsubject_f_L_reserved_values_pzero_sp(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("% Lf", special);}
int notinsubject_f_L_reserved_values_nzero_sp(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("% Lf", special);}
int notinsubject_f_L_reserved_values_inf_6wzp(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("%06Lf", special);}
int notinsubject_f_L_reserved_values_ninf_6wzp(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%06Lf", special);}
int notinsubject_f_L_reserved_values_nan_6wzp(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%06Lf", special);}
int notinsubject_f_L_reserved_values_pzero_6wzp(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%06Lf", special);}
int notinsubject_f_L_reserved_values_nzero_6wzp(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%06Lf", special);}
///Long double Floats whose precision exceeds their compiled literal precision
int notinsubject_f_L_overprec_might_be_undefbehav_100(void){return test("%.100Lf", 0.237l);}
int notinsubject_f_L_overprec_might_be_undefbehav_32(void){return test("%.32Lf", 0.237l);}
int notinsubject_f_L_overprec_might_be_undefbehav_4(void){return test("%.4Lf", 0.237l);}
int notinsubject_f_L_overprec_might_be_undefbehav_1000(void){return test("%.4Lf", -0.106577568068517810765107851705167l);}
int notinsubject_f_L_overprec_might_be_undefbehav_10_from_0(void){return test("%.10Lf", 0.0l);}
int notinsubject_f_L_overprec_might_be_undefbehav_2000(void){return test("%.2000Lf", 623.28376510723481l);}
int notinsubject_f_L_overprec_might_be_undefbehav_dblmin(void){return test("%.2000Lf", LDBL_MIN);}
int notinsubject_f_L_overprec_might_be_undefbehav_ndblmin(void){return test("%.2000Lf", -LDBL_MIN);}
//Long double floats at double max, double min
int notinsubject_f_L_limits_dblmax_prec0(void){return test("%.0Lf", LDBL_MAX);}
int notinsubject_f_L_limits_dblmax_prec3(void){return test("%.3Lf", LDBL_MAX);}
int notinsubject_f_L_limits_dblmax_precd(void){return test("%Lf", LDBL_MAX);}
int notinsubject_f_L_limits_dblmax_prec8(void){return test("%.8Lf", LDBL_MAX);}
int notinsubject_f_L_stress_limits_dblmax_prec12(void){return test("%.12Lf", LDBL_MAX);}
int notinsubject_f_L_stress_limits_dblmax_prec16(void){return test("%.16Lf", LDBL_MAX);}
int notinsubject_f_L_stress_limits_dblmax_prec18(void){return test("%.18Lf", LDBL_MAX);}
int notinsubject_f_L_limits_ndblmax_prec0(void){return test("%.0Lf", -LDBL_MAX);}
int notinsubject_f_L_limits_ndblmax_prec3(void){return test("%.3Lf", -LDBL_MAX);}
int notinsubject_f_L_limits_ndblmax_precd(void){return test("%Lf", -LDBL_MAX);}
int notinsubject_f_L_limits_ndblmax_prec8(void){return test("%.8Lf", -LDBL_MAX);}
int notinsubject_f_L_stress_limits_ndblmax_prec12(void){return test("%.12Lf", -LDBL_MAX);}
int notinsubject_f_L_stress_limits_ndblmax_prec16(void){return test("%.16Lf", -LDBL_MAX);}
int notinsubject_f_L_stress_limits_ndblmax_prec18(void){return test("%.18Lf", -LDBL_MAX);}
int notinsubject_f_L_limits_dblmin_prec0(void){return test("%.0Lf", LDBL_MIN);}
int notinsubject_f_L_limits_dblmin_prec3(void){return test("%.3Lf", LDBL_MIN);}
int notinsubject_f_L_limits_dblmin_precd(void){return test("%Lf", LDBL_MIN);}
int notinsubject_f_L_limits_dblmin_prec8(void){return test("%.8Lf", LDBL_MIN);}
int notinsubject_f_L_stress_limits_dblmin_prec12(void){return test("%.12Lf", LDBL_MIN);}
int notinsubject_f_L_stress_limits_dblmin_prec16(void){return test("%.16Lf", LDBL_MIN);}
int notinsubject_f_L_stress_limits_dblmin_prec18(void){return test("%.18Lf", LDBL_MIN);}
int notinsubject_f_L_limits_ndblmin_prec0(void){return test("%.0Lf", -LDBL_MIN);}
int notinsubject_f_L_limits_ndblmin_prec3(void){return test("%.3Lf", -LDBL_MIN);}
int notinsubject_f_L_limits_ndblmin_precd(void){return test("%Lf", -LDBL_MIN);}
int notinsubject_f_L_limits_ndblmin_prec8(void){return test("%.8Lf", -LDBL_MIN);}
int notinsubject_f_L_stress_limits_ndblmin_prec12(void){return test("%.12Lf", -LDBL_MIN);}
int notinsubject_f_L_stress_limits_ndblmin_prec16(void){return test("%.16Lf", -LDBL_MIN);}
int notinsubject_f_L_stress_limits_ndblmin_prec18(void){return test("%.18Lf", -LDBL_MIN);}


/* -----------------------------------------------------------------------------
** 					%a %A HEXADECIMAL FLOATS (NOT IN THE SUBJECT)
** ---------------------------------------------------------------------------*/
int notinsubject_moul_a_1(void){return test("%a", (double)42);}
int notinsubject_moul_a_2(void){return test("Kashim a %a histoires à raconter", (double)1001);}
int notinsubject_moul_a_3(void){return test("Il fait au moins %a\n", (double)-8000);}
int notinsubject_moul_a_4(void){return test("%a", (double)-0);}
int notinsubject_moul_a_5(void){return test("%a", (double)0);}
int notinsubject_moul_a_6(void){return test("%a", (double)INT_MAX);}
int notinsubject_moul_a_7(void){return test("%a", (double)INT_MIN);}
int notinsubject_moul_a_8(void){return test("%a", (double)INT_MIN - 1);}
int notinsubject_moul_a_9(void){return test("%a", (double)INT_MAX + 1);}
int notinsubject_moul_a_11(void){return test("%%a 0000042 == |%a|\n", (double)0000042);}
int notinsubject_moul_a_12(void){return test("%%a \t == |%a|\n", (double)'\t');}
int notinsubject_moul_a_13(void){return test("%%a Lydie == |%a|\n", (double)'L'+'y'+'d'+'i'+'e');}
int notinsubject_moul_a_14(void){return test("%%a 42.42 == |%a|\n", 42.42);}
int notinsubject_moul_a_15(void){return test("%A", (double)42);}
int notinsubject_moul_a_16(void){return test("Kashim a %A histoires à raconter", (double)1001);}
int notinsubject_moul_a_17(void){return test("Il fait au moins %A\n", (double)-8000);}
int notinsubject_moul_a_18(void){return test("%A", (double)-0);}
int notinsubject_moul_a_19(void){return test("%A", (double)0);}
int notinsubject_moul_a_20(void){return test("%A", (double)INT_MAX);}
int notinsubject_moul_a_21(void){return test("%A", (double)INT_MIN);}
int notinsubject_moul_a_22(void){return test("%A", (double)INT_MIN - 1);}
int notinsubject_moul_a_23(void){return test("%A", (double)INT_MAX + 1);}
int notinsubject_moul_a_24(void){return test("%%A 0000042 == |%A|\n", (double)0000042);}
int notinsubject_moul_a_25(void){return test("%%A \t == |%A|\n", (double)'\t');}
int notinsubject_moul_a_26(void){return test("%%A Lydie == |%A|\n", (double)'L'+'y'+'d'+'i'+'e');}
int notinsubject_moul_a_27(void){return test("%%A 42.42 == |%A|\n", 42.42);}
int notinsubject_moul_a_28(void){return test("%%A 42.42 == |%.2A|\n", 42.42);}


/* -----------------------------------------------------------------------------
** 						%o OCTALS TESTS (NOT IN THE SUBJECT)
** ---------------------------------------------------------------------------*/
//Octals - no modifers
int notinsubject_o_basic_octl_pos(void){return test("this %o number", 17);}
int notinsubject_o_basic_octl_zero(void){return test("this %o number", 0);}
int notinsubject_o_basic_octl_onlypos(void){return test("%o", 3);}
int notinsubject_o_octlmax(void){return test("%o", 4294967295u);}
//Octals with field width
int notinsubject_o_width_pos_fits(void){return test("%7o", 33);}
int notinsubject_o_width_zero_fits(void){return test("%3o", 0);}
int notinsubject_o_width_pos_exactfit(void){return test("%6o", 52625);}
int notinsubject_o_width_pos_nofit(void){return test("%2o", 94827);}
int notinsubject_o_width_pos_fits_lj(void){return test("%-7o", 33);}
int notinsubject_o_width_zero_fits_lj(void){return test("%-3o", 0);}
int notinsubject_o_width_pos_exactfit_lj(void){return test("%-6o", 52625);}
int notinsubject_o_width_pos_nofit_lj(void){return test("%-4o", 9648627);}
//Octals with precision
int notinsubject_o_prec_fits_pos(void){return test("%.5o", 21);}
int notinsubject_o_prec_fits_zero(void){return test("%.3o", 0);}
int notinsubject_o_prec_exactfit_pos(void){return test("%.5o", 5263);}
int notinsubject_o_prec_nofit_pos(void){return test("%.3o", 938862);}
//Octals with zero field width padding
int notinsubject_o_zp_pos_fits(void){return test("%05o", 43);}
int notinsubject_o_zp_zero_fits(void){return test("%03o", 0);}
int notinsubject_o_zp_pos_exactfit(void){return test("%07o", 698334);}
//Octals with field width and precision
int notinsubject_o_prec_width_fit_fit_pos(void){return test("%8.5o", 34);}
int notinsubject_o_prec_width_fit_fit_zero(void){return test("%8.5o", 0);}
int notinsubject_o_prec_width_nofit_fit_pos(void){return test("%8.3o", 8375);}
int notinsubject_o_prec_width_fit_nofit_pos(void){return test("%2.7o", 3267);}
int notinsubject_o_prec_width_nofit_nofit_pos(void){return test("%3.3o", 6983);}
//Octals with field width and precision, left-justified
int notinsubject_o_prec_width_fit_fit_pos_lj(void){return test("%-8.5o", 34);}
int notinsubject_o_prec_width_fit_fit_zero_lj(void){return test("%-8.5o", 0);}
int notinsubject_o_prec_width_nofit_fit_pos_lj(void){return test("%-8.3o", 8375);}
int notinsubject_o_prec_width_fit_nofit_pos_lj(void){return test("%-2.7o", 3267);}
int notinsubject_o_prec_width_nofit_nofit_pos_lj(void){return test("%-3.3o", 6983);}
//Octals with field width and precision with zeropadding
int notinsubject_o_prec_width_ff_pos_zp(void){return test("%08.5o", 34);}
int notinsubject_o_prec_width_ff_zero_zp(void){return test("%08.5o", 0);}
int notinsubject_o_prec_width_nf_pos_zp(void){return test("%08.3o", 8375);}
int notinsubject_o_prec_width_fn_pos_zp(void){return test("%02.7o", 3267);}
int notinsubject_o_prec_width_nn_pos_zp(void){return test("%03.3o", 6983);}
//Octals with field width and precision, left-justified with zeropadding
int notinsubject_o_prec_width_ff_pos_ljzp_ignoreflag(void){return test("%0-8.5o", 34);}
int notinsubject_o_prec_width_ff_zero_ljzp_ignoreflag(void){return test("%0-8.5o", 0);}
int notinsubject_o_prec_width_nf_pos_ljzp_ignoreflag(void){return test("%0-8.3o", 8375);}
int notinsubject_o_prec_width_fn_pos_ljzp_ignoreflag(void){return test("%0-2.7o", 3267);}
int notinsubject_o_prec_width_nn_pos_ljzp_ignoreflag(void){return test("%0-3.3o", 6983);}
//Octals of varying size modifiers
int notinsubject_o_hh_pos_casted(void){return test("%hho", (unsigned char)45);}
int notinsubject_o_h_pos_casted(void){return test("%ho", (unsigned short)385);}
int notinsubject_o_l_pos_casted(void){return test("%lo", (unsigned long)32);}
int notinsubject_o_ll_pos_casted(void){return test("%llo", (long long)43);}
int notinsubject_o_hh_pos_ref(void){return test("%hho", uch_pos_1);}
int notinsubject_o_h_pos_ref(void){return test("%ho", ush_pos_1);}
int notinsubject_o_l_pos_ref(void){return test("%lo", ul_pos_1);}
int notinsubject_o_ll_pos_ref(void){return test("%llo", ull_pos_1);}
int notinsubject_o_l_pos_big(void){return test("%lo", 22337203685477ul);}
int notinsubject_o_ll_pos_big(void){return test("%llo", 522337203685470ull);}
int notinsubject_o_ullmax(void){return test("%llo", ullmax);}
int notinsubject_o_ulmax(void){return test("%lo", ulmax);}
int notinsubject_o_uhmax(void){return test("%ho", (unsigned short)65535);}
int notinsubject_o_uhhmax(void){return test("%hho", (unsigned char)255);}
//Octals of varying size modifiers with some other modifiers
int notinsubject_o_l_pos_big_zp(void){return test("%037lo", 22337203685477ul);}
int notinsubject_o_ll_pos_big_width(void){return test("%37llo", 522337203685470ull);}
//Multiple Octals in a row of varying sizes
int notinsubject_o_ll_hh_ll(void){return test("%llu%hhu%llo", ull_pos_1, uch_pos_1, ull_pos_1);}
int notinsubject_o_h_l_hh(void){return test("%hu%lu%hho", ush_pos_1, ul_pos_1, uch_pos_1);}
int notinsubject_o_l_hh_h(void){return test("%lu%hhu%ho", ul_pos_1, uch_pos_1, ush_pos_1);}
int notinsubject_o_n_ll_hh(void){return test("%u%llu%hho", ui_pos_1, ull_pos_1, uch_pos_1);}
int notinsubject_o_ll_n_l(void){return test("%llu%u%lo", ull_pos_1, ui_pos_1, ul_pos_1);}
//Octal (Altform)s - no modifers
int notinsubject_o_basic_octl_pos_af(void){return test("this %#o number", 17);}
int notinsubject_o_basic_octl_zero_af(void){return test("this %#o number", 0);}
int notinsubject_o_basic_octl_onlypos_af(void){return test("%#o", 3);}
int notinsubject_o_octlmax_af(void){return test("%#o", 4294967295u);}
//Octal (Altform)s with field width
int notinsubject_o_width_pos_fits_af(void){return test("%#7o", 33);}
int notinsubject_o_width_zero_fits_af(void){return test("%#3o", 0);}
int notinsubject_o_width_pos_exactfit_af(void){return test("%#6o", 52625);}
int notinsubject_o_width_pos_nofit_af(void){return test("%#2o", 94827);}
int notinsubject_o_width_pos_fits_lj_af(void){return test("%#-7o", 33);}
int notinsubject_o_width_zero_fits_lj_af(void){return test("%#-3o", 0);}
int notinsubject_o_width_pos_exactfit_lj_af(void){return test("%#-6o", 52625);}
int notinsubject_o_width_pos_nofit_lj_af(void){return test("%#-4o", 9648627);}
//Octal (Altform)s with precision
int notinsubject_o_prec_fits_pos_af(void){return test("%#.5o", 21);}
int notinsubject_o_prec_fits_zero_af(void){return test("%#.3o", 0);}
int notinsubject_o_prec_exactfit_pos_af(void){return test("%#.5o", 5263);}
int notinsubject_o_prec_nofit_pos_af(void){return test("%#.3o", 938862);}
//Octal (Altform)s with zero field width padding
int notinsubject_o_zp_pos_fits_af(void){return test("%#05o", 43);}
int notinsubject_o_zp_zero_fits_af(void){return test("%#03o", 0);}
int notinsubject_o_zp_pos_exactfit_af(void){return test("%#07o", 698334);}
//Octal (Altform)s with field width and precision
int notinsubject_o_prec_width_fit_fit_pos_af(void){return test("%#8.5o", 34);}
int notinsubject_o_prec_width_fit_fit_zero_af(void){return test("%#8.5o", 0);}
int notinsubject_o_prec_width_nofit_fit_pos_af(void){return test("%#8.3o", 8375);}
int notinsubject_o_prec_width_fit_nofit_pos_af(void){return test("%#2.7o", 3267);}
int notinsubject_o_prec_width_nofit_nofit_pos_af(void){return test("%#3.3o", 6983);}
//Octal (Altform)s with field width and precision, left-justified
int notinsubject_o_prec_width_fit_fit_pos_lj_af(void){return test("%#-8.5o", 34);}
int notinsubject_o_prec_width_fit_fit_zero_lj_af(void){return test("%#-8.5o", 0);}
int notinsubject_o_prec_width_nofit_fit_pos_lj_af(void){return test("%#-8.3o", 8375);}
int notinsubject_o_prec_width_fit_nofit_pos_lj_af(void){return test("%#-2.7o", 3267);}
int notinsubject_o_prec_width_nofit_nofit_pos_lj_af(void){return test("%#-3.3o", 6983);}
//Octal (Altform)s with field width and precision with zeropadding
int notinsubject_o_prec_width_ff_pos_zp_af(void){return test("%#08.5o", 34);}
int notinsubject_o_prec_width_ff_zero_zp_af(void){return test("%#08.5o", 0);}
int notinsubject_o_prec_width_nf_pos_zp_af(void){return test("%#08.3o", 8375);}
int notinsubject_o_prec_width_fn_pos_zp_af(void){return test("%#02.7o", 3267);}
int notinsubject_o_prec_width_nn_pos_zp_af(void){return test("%#03.3o", 6983);}
//Octal (Altform)s with field width and precision, left-justified with zeropadding
int notinsubject_o_prec_width_ff_pos_ljzpaf_ignoreflag(void){return test("%#0-8.5o", 34);}
int notinsubject_o_prec_width_ff_zero_ljzpaf_ignoreflag(void){return test("%#0-8.5o", 0);}
int notinsubject_o_prec_width_nf_pos_ljzpaf_ignoreflag(void){return test("%#0-8.3o", 8375);}
int notinsubject_o_prec_width_fn_pos_ljzpaf_ignoreflag(void){return test("%#0-2.7o", 3267);}
int notinsubject_o_prec_width_nn_pos_ljzpaf_ignoreflag(void){return test("%#0-3.3o", 6983);}
//Octal (Altform)s of varying size modifiers
int notinsubject_o_hh_pos_casted_af(void){return test("%#hho", (unsigned char)45);}
int notinsubject_o_h_pos_casted_af(void){return test("%#ho", (unsigned short)385);}
int notinsubject_o_l_pos_casted_af(void){return test("%#lo", (unsigned long)32);}
int notinsubject_o_ll_pos_casted_af(void){return test("%#llo", (long long)43);}
int notinsubject_o_hh_pos_ref_af(void){return test("%#hho", uch_pos_1);}
int notinsubject_o_h_pos_ref_af(void){return test("%#ho", ush_pos_1);}
int notinsubject_o_l_pos_ref_af(void){return test("%#lo", ul_pos_1);}
int notinsubject_o_ll_pos_ref_af(void){return test("%#llo", ull_pos_1);}
int notinsubject_o_l_pos_big_af(void){return test("%#lo", 22337203685477ul);}
int notinsubject_o_ll_pos_big_af(void){return test("%#llo", 522337203685470ull);}
int notinsubject_o_ullmax_af(void){return test("%#llo", ullmax);}
int notinsubject_o_ulmax_af(void){return test("%#lo", ulmax);}
int notinsubject_o_uhmax_af(void){return test("%#ho", (unsigned short)65535);}
int notinsubject_o_uhhmax_af(void){return test("%#hho", (unsigned char)255);}
//Octal (Altform)s of varying size modifiers with some other modifiers
int notinsubject_o_l_pos_big_zp_af(void){return test("%#037lo", 22337203685477ul);}
int notinsubject_o_ll_pos_big_width_af(void){return test("%#37llo", 522337203685470ull);}
//Multiple Octal (Altform)s in a row of varying sizes
int notinsubject_o_ll_hh_ll_af(void){return test("%llu%hhu%#llo", ull_pos_1, uch_pos_1, ull_pos_1);}
int notinsubject_o_h_l_hh_af(void){return test("%hu%lu%#hho", ush_pos_1, ul_pos_1, uch_pos_1);}
int notinsubject_o_l_hh_h_af(void){return test("%#lo%hhu%#ho", ul_pos_1, uch_pos_1, ush_pos_1);}
int notinsubject_o_n_ll_hh_af(void){return test("%#o%llu%hho", ui_pos_1, ull_pos_1, uch_pos_1);}
int notinsubject_o_ll_n_l_af(void){return test("%#llo%u%#lo", ull_pos_1, ui_pos_1, ul_pos_1);}
//Octals - zero precision zero value
int notinsubject_o_prec0val0_basic(void){return test("%.0o", 0);}
int notinsubject_o_prec0val0_implicit(void){return test("%.o", 0);}
int notinsubject_o_prec0val0_w(void){return test("%5.0o", 0);}
int notinsubject_o_prec0val0_w_impl(void){return test("%5.o", 0);}
int notinsubject_o_prec0val0_wlj(void){return test("%-5.0o", 0);}
int notinsubject_o_prec0val0_wlj_impl(void){return test("%-5.o", 0);}
int notinsubject_o_prec0val0_af(void){return test("%#.0o", 0);}
int notinsubject_o_prec0val0_af_impl(void){return test("%#.o", 0);}
int notinsubject_o_prec0val0_waf(void){return test("%#5.0o", 0);}
int notinsubject_o_prec0val0_waf_impl(void){return test("%#5.o", 0);}
int notinsubject_o_prec0val0_waflj(void){return test("%#-5.0o", 0);}
int notinsubject_o_prec0val0_waflj_impl(void){return test("%#-5.o", 0);}

int nocrash_notinsubject_notrequired_o_sp(void){return test("% o", 42);}
int nocrash_notinsubject_notrequired_o_hhh(void){return test("%hhho", 42);}
int nocrash_notinsubject_notrequired_o_hhhh(void){return test("%hhhho", 42);}
int nocrash_notinsubject_notrequired_o_hhl(void){return test("%hhlo", 42);}
int nocrash_notinsubject_notrequired_o_hhll(void){return test("%hhllo", 42);}
int nocrash_notinsubject_notrequired_o_llh(void){return test("%llho", 42);}
int nocrash_notinsubject_notrequired_o_lll(void){return test("%lllo", 42);}
int nocrash_notinsubject_notrequired_o_lj_nowidth(void){return test("%-o", 42);}
int nocrash_notinsubject_notrequired_o_as(void){return test("%+o", 42);}

int notinsubject_moul_o_1(void){return test("%o", 42);}
int notinsubject_moul_o_2(void){return test("Kashim a %o histoires à raconter", 1001);}
int notinsubject_moul_o_3(void){return test("Il fait au moins %o\n", -8000);}
int notinsubject_moul_o_4(void){return test("%o", -0);}
int notinsubject_moul_o_5(void){return test("%o", 0);}
int notinsubject_moul_o_6(void){return test("%o", INT_MAX);}
int notinsubject_moul_o_7(void){return test("%o", INT_MIN);}
int notinsubject_moul_o_8(void){return test("%o", INT_MIN - 1);}
int notinsubject_moul_o_9(void){return test("%o", INT_MAX + 1);}
int notinsubject_moul_o_10(void){return test("%%o 0000042 == |%o|\n", 0000042);}
int notinsubject_moul_o_11(void){return test("%%o \t == |%o|\n", '\t');}
int notinsubject_moul_o_12(void){return test("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');}
int notinsubject_moul_o_hash_3(void){return test("%%#o 0 ==  %#o\n", 0);}
int notinsubject_moul_o_hash_4(void){return test("%%o 0 ==  %o\n", 0);}
int notinsubject_moul_o_hash_5(void){return test("%%#o INT_MAX ==  %#o\n", INT_MAX);}
int notinsubject_moul_o_hash_6(void){return test("%%o INT_MAX ==  %o\n", INT_MAX);}
int notinsubject_moul_o_hash_7(void){return test("%%#o INT_MIN ==  %#o\n", INT_MIN);}
int notinsubject_moul_o_hash_8(void){return test("%%o INT_MIN ==  %o\n", INT_MIN);}

 /* -----------------------------------------------------------------------------
** 						OTHER NOT IN THE SUBJECT
** ---------------------------------------------------------------------------*/
//General format uppercase - Moulinette
int notinsubject_moul_G_1(void){return test("%G", (double)42);}
int notinsubject_moul_G_2(void){return test("Kashim a %G histoires à raconter", (double)1001);}
int notinsubject_moul_G_3(void){return test("Il fait au moins %G\n", (double)-8000);}
int notinsubject_moul_G_4(void){return test("%G", (double)-0);}
int notinsubject_moul_G_5(void){return test("%G", (double)0);}
int notinsubject_moul_G_6(void){return test("%G", (double)INT_MAX);}
int notinsubject_moul_G_7(void){return test("%G", (double)INT_MIN);}
int notinsubject_moul_G_8(void){return test("%G", (double)INT_MIN - 1);}
int notinsubject_moul_G_9(void){return test("%G", (double)INT_MAX + 1);}
int notinsubject_moul_G_10(void){return test("%%G 0000042 == |%G|\n", (double)0000042);}
int notinsubject_moul_G_11(void){return test("%%G \t == |%G|\n", (double)'\t');}
int notinsubject_moul_G_12(void){return test("%%G Lydie == |%G|\n", (double)'L'+'y'+'d'+'i'+'e');}
int notinsubject_moul_G_13(void){return test("%%G 42.42 == |%G|\n", 42.42);}
int notinsubject_moul_G_14(void){return test("%%G 42.42 == |%.2G|\n", 42.42);}
 //Scientific notation uppercase - Moulinette
int notinsubject_moul_e_14(void){return test("%E", (double)42);}
int notinsubject_moul_e_15(void){return test("Kashim a %E histoires à raconter", (double)1001);}
int notinsubject_moul_e_16(void){return test("Il fait au moins %E\n", (double)-8000);}
int notinsubject_moul_e_17(void){return test("%E", (double)-0);}
int notinsubject_moul_e_18(void){return test("%E", (double)0);}
int notinsubject_moul_e_19(void){return test("%E", (double)INT_MAX);}
int notinsubject_moul_e_20(void){return test("%E", (double)INT_MIN);}
int notinsubject_moul_e_21(void){return test("%E", (double)INT_MIN - 1);}
int notinsubject_moul_e_22(void){return test("%E", (double)INT_MAX + 1);}
int notinsubject_moul_e_23(void){return test("%%E 0000042 == |%E|\n", (double)0000042);}
int notinsubject_moul_e_24(void){return test("%%E \t == |%E|\n", (double)'\t');}
int notinsubject_moul_e_25(void){return test("%%E Lydie == |%E|\n", (double)'L'+'y'+'d'+'i'+'e');}
int notinsubject_moul_e_26(void){return test("%%E 42.42 == |%E|\n", 42.42);}
int notinsubject_moul_e_27(void){return test("%%E 42.42 == |%.2E|\n", 42.42);}
 //Widechar
int notinsubject_moul_widechar_mix2_throwswarning(void){return test("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");}
int notinsubject_moul_widechar_basic1(void){wchar_t c = L'\x82'; return test("%C\n", c);}
int notinsubject_moul_widechar_basic2(void){return test("%C\n", L'ø');}
int notinsubject_moul_widestr_basic2(void){wchar_t wz[3] = L"@@"; return test("%ls", wz);}
 //D - Moulinette
int notinsubject_moul_D_1_notmandatory(void){return test("%D", 42);}
int notinsubject_moul_D_2_notmandatory(void){return test("Kashim a %D histoires à raconter", 1001);}
int notinsubject_moul_D_3_notmandatory(void){return test("Il fait au moins %D\n", -8000);}
int notinsubject_moul_D_4_notmandatory(void){return test("%D", -0);}
int notinsubject_moul_D_5_notmandatory(void){return test("%D", 0);}
int notinsubject_moul_D_6_notmandatory(void){return test("%D", INT_MAX);}
int notinsubject_moul_D_7_notmandatory(void){return test("%D", INT_MIN);}
int notinsubject_moul_D_8_notmandatory(void){return test("%D", INT_MIN - 1);}
int notinsubject_moul_D_9_notmandatory(void){return test("%D", INT_MAX + 1);}
int notinsubject_moul_D_10_notmandatory(void){return test("%%D 0000042 == |%D|\n", 0000042);}
int notinsubject_moul_D_11_notmandatory(void){return test("%%D \t == |%D|\n", '\t');}
int notinsubject_moul_D_12_notmandatory(void){return test("%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');}

/* -----------------------------------------------------------------------------
** 						ROUND HALF TO EVEN
** ---------------------------------------------------------------------------*/
// %f round half to even
int bonus_f_rnd_half_to_even_01(void){return test("%.0f", -5.5);}
int bonus_f_rnd_half_to_even_02(void){return test("%.0f", -4.5);}
int bonus_f_rnd_half_to_even_03(void){return test("%.0f", -3.5);}
int bonus_f_rnd_half_to_even_04(void){return test("%.0f", -2.5);}
int bonus_f_rnd_half_to_even_05(void){return test("%.0f", -1.5);}
int bonus_f_rnd_half_to_even_06(void){return test("%.0f", -0.5);}
int bonus_f_rnd_half_to_even_07(void){return test("%.0f", 0.5);}
int bonus_f_rnd_half_to_even_08(void){return test("%.0f", 1.5);}
int bonus_f_rnd_half_to_even_09(void){return test("%.0f", 2.5);}
int bonus_f_rnd_half_to_even_10(void){return test("%.0f", 3.5);}
int bonus_f_rnd_half_to_even_11(void){return test("%.0f", 4.5);}
int bonus_f_rnd_half_to_even_12(void){return test("%.0f", 5.5);}
int bonus_f_rnd_half_to_even_13(void){return test("%.3f", -1.2305);}
int bonus_f_rnd_half_to_even_14(void){return test("%.3f", -1.2315);}
int bonus_f_rnd_half_to_even_15(void){return test("%.3f", -1.2325);}
int bonus_f_rnd_half_to_even_16(void){return test("%.3f", -1.2335);}
int bonus_f_rnd_half_to_even_17(void){return test("%.3f", -1.2345);}
int bonus_f_rnd_half_to_even_18(void){return test("%.3f", -1.2355);}
int bonus_f_rnd_half_to_even_19(void){return test("%.3f", -1.2365);}
int bonus_f_rnd_half_to_even_20(void){return test("%.3f", -1.2375);}
int bonus_f_rnd_half_to_even_21(void){return test("%.3f", -1.2385);}
int bonus_f_rnd_half_to_even_22(void){return test("%.3f", -1.2395);}
int bonus_f_rnd_half_to_even_24(void){return test("%.3f", 1.2305);}
int bonus_f_rnd_half_to_even_25(void){return test("%.3f", 1.2315);}
int bonus_f_rnd_half_to_even_26(void){return test("%.3f", 1.2325);}
int bonus_f_rnd_half_to_even_27(void){return test("%.3f", 1.2335);}
int bonus_f_rnd_half_to_even_28(void){return test("%.3f", 1.2345);}
int bonus_f_rnd_half_to_even_29(void){return test("%.3f", 1.2355);}
int bonus_f_rnd_half_to_even_30(void){return test("%.3f", 1.2365);}
int bonus_f_rnd_half_to_even_31(void){return test("%.3f", 1.2375);}
int bonus_f_rnd_half_to_even_32(void){return test("%.3f", 1.2385);}
int bonus_f_rnd_half_to_even_33(void){return test("%.3f", 1.2395);}
// %e round half to even
int bonus_e_rnd_half_to_even_01(void){return test("%.0e", -5.5);}
int bonus_e_rnd_half_to_even_02(void){return test("%.0e", -4.5);}
int bonus_e_rnd_half_to_even_03(void){return test("%.0e", -3.5);}
int bonus_e_rnd_half_to_even_04(void){return test("%.0e", -2.5);}
int bonus_e_rnd_half_to_even_05(void){return test("%.0e", -1.5);}
int bonus_e_rnd_half_to_even_06(void){return test("%.0e", -0.5);}
int bonus_e_rnd_half_to_even_07(void){return test("%.0e", 0.5);}
int bonus_e_rnd_half_to_even_08(void){return test("%.0e", 1.5);}
int bonus_e_rnd_half_to_even_09(void){return test("%.0e", 2.5);}
int bonus_e_rnd_half_to_even_10(void){return test("%.0e", 3.5);}
int bonus_e_rnd_half_to_even_11(void){return test("%.0e", 4.5);}
int bonus_e_rnd_half_to_even_12(void){return test("%.0e", 5.5);}
int bonus_e_rnd_half_to_even_13(void){return test("%.3e", -1.2305);}
int bonus_e_rnd_half_to_even_14(void){return test("%.3e", -1.2315);}
int bonus_e_rnd_half_to_even_15(void){return test("%.3e", -1.2325);}
int bonus_e_rnd_half_to_even_16(void){return test("%.3e", -1.2335);}
int bonus_e_rnd_half_to_even_17(void){return test("%.3e", -1.2345);}
int bonus_e_rnd_half_to_even_18(void){return test("%.3e", -1.2355);}
int bonus_e_rnd_half_to_even_19(void){return test("%.3e", -1.2365);}
int bonus_e_rnd_half_to_even_20(void){return test("%.3e", -1.2375);}
int bonus_e_rnd_half_to_even_21(void){return test("%.3e", -1.2385);}
int bonus_e_rnd_half_to_even_22(void){return test("%.3e", -1.2395);}
int bonus_e_rnd_half_to_even_24(void){return test("%.3e", 1.2305);}
int bonus_e_rnd_half_to_even_25(void){return test("%.3e", 1.2315);}
int bonus_e_rnd_half_to_even_26(void){return test("%.3e", 1.2325);}
int bonus_e_rnd_half_to_even_27(void){return test("%.3e", 1.2335);}
int bonus_e_rnd_half_to_even_28(void){return test("%.3e", 1.2345);}
int bonus_e_rnd_half_to_even_29(void){return test("%.3e", 1.2355);}
int bonus_e_rnd_half_to_even_30(void){return test("%.3e", 1.2365);}
int bonus_e_rnd_half_to_even_31(void){return test("%.3e", 1.2375);}
int bonus_e_rnd_half_to_even_32(void){return test("%.3e", 1.2385);}
int bonus_e_rnd_half_to_even_33(void){return test("%.3e", 1.2395);}
// %g round half to even
int bonus_g_rnd_half_to_even_01(void){return test("%.0g", -5.5);}
int bonus_g_rnd_half_to_even_02(void){return test("%.0g", -4.5);}
int bonus_g_rnd_half_to_even_03(void){return test("%.0g", -3.5);}
int bonus_g_rnd_half_to_even_04(void){return test("%.0g", -2.5);}
int bonus_g_rnd_half_to_even_05(void){return test("%.0g", -1.5);}
int bonus_g_rnd_half_to_even_06(void){return test("%.0g", -0.5);}
int bonus_g_rnd_half_to_even_07(void){return test("%.0g", 0.5);}
int bonus_g_rnd_half_to_even_08(void){return test("%.0g", 1.5);}
int bonus_g_rnd_half_to_even_09(void){return test("%.0g", 2.5);}
int bonus_g_rnd_half_to_even_10(void){return test("%.0g", 3.5);}
int bonus_g_rnd_half_to_even_11(void){return test("%.0g", 4.5);}
int bonus_g_rnd_half_to_even_12(void){return test("%.0g", 5.5);}
int bonus_g_rnd_half_to_even_13(void){return test("%.3g", -1.2305);}
int bonus_g_rnd_half_to_even_14(void){return test("%.3g", -1.2315);}
int bonus_g_rnd_half_to_even_15(void){return test("%.3g", -1.2325);}
int bonus_g_rnd_half_to_even_16(void){return test("%.3g", -1.2335);}
int bonus_g_rnd_half_to_even_17(void){return test("%.3g", -1.2345);}
int bonus_g_rnd_half_to_even_18(void){return test("%.3g", -1.2355);}
int bonus_g_rnd_half_to_even_19(void){return test("%.3g", -1.2365);}
int bonus_g_rnd_half_to_even_20(void){return test("%.3g", -1.2375);}
int bonus_g_rnd_half_to_even_21(void){return test("%.3g", -1.2385);}
int bonus_g_rnd_half_to_even_22(void){return test("%.3g", -1.2395);}
int bonus_g_rnd_half_to_even_24(void){return test("%.3g", 1.2305);}
int bonus_g_rnd_half_to_even_25(void){return test("%.3g", 1.2315);}
int bonus_g_rnd_half_to_even_26(void){return test("%.3g", 1.2325);}
int bonus_g_rnd_half_to_even_27(void){return test("%.3g", 1.2335);}
int bonus_g_rnd_half_to_even_28(void){return test("%.3g", 1.2345);}
int bonus_g_rnd_half_to_even_29(void){return test("%.3g", 1.2355);}
int bonus_g_rnd_half_to_even_30(void){return test("%.3g", 1.2365);}
int bonus_g_rnd_half_to_even_31(void){return test("%.3g", 1.2375);}
int bonus_g_rnd_half_to_even_32(void){return test("%.3g", 1.2385);}
int bonus_g_rnd_half_to_even_33(void){return test("%.3g", 1.2395);}
int bonus_g_rnd_half_to_even_34(void){return test("%.4g", -1.2305);}
int bonus_g_rnd_half_to_even_35(void){return test("%.4g", -1.2315);}
int bonus_g_rnd_half_to_even_36(void){return test("%.4g", -1.2325);}
int bonus_g_rnd_half_to_even_37(void){return test("%.4g", -1.2335);}
int bonus_g_rnd_half_to_even_38(void){return test("%.4g", -1.2345);}
int bonus_g_rnd_half_to_even_39(void){return test("%.4g", -1.2355);}
int bonus_g_rnd_half_to_even_40(void){return test("%.4g", -1.2365);}
int bonus_g_rnd_half_to_even_41(void){return test("%.4g", -1.2375);}
int bonus_g_rnd_half_to_even_42(void){return test("%.4g", -1.2385);}
int bonus_g_rnd_half_to_even_43(void){return test("%.4g", -1.2395);}
int bonus_g_rnd_half_to_even_44(void){return test("%.4g", 1.2305);}
int bonus_g_rnd_half_to_even_45(void){return test("%.4g", 1.2315);}
int bonus_g_rnd_half_to_even_46(void){return test("%.4g", 1.2325);}
int bonus_g_rnd_half_to_even_47(void){return test("%.4g", 1.2335);}
int bonus_g_rnd_half_to_even_48(void){return test("%.4g", 1.2345);}
int bonus_g_rnd_half_to_even_49(void){return test("%.4g", 1.2355);}
int bonus_g_rnd_half_to_even_50(void){return test("%.4g", 1.2365);}
int bonus_g_rnd_half_to_even_51(void){return test("%.4g", 1.2375);}
int bonus_g_rnd_half_to_even_52(void){return test("%.4g", 1.2385);}
int bonus_g_rnd_half_to_even_53(void){return test("%.4g", 1.2395);}

/* -----------------------------------------------------------------------------
** 						ROUND 9.999
** ---------------------------------------------------------------------------*/
// %f round 9.999
int bonus_f_rnd_9999_01(void){return test("%.0f", -9.0);}
int bonus_f_rnd_9999_02(void){return test("%.1f", -9.0);}
int bonus_f_rnd_9999_03(void){return test("%.0f", -9.9);}
int bonus_f_rnd_9999_04(void){return test("%.1f", -9.9);}
int bonus_f_rnd_9999_05(void){return test("%.0f", -9.999);}
int bonus_f_rnd_9999_06(void){return test("%.1f", -9.999);}
int bonus_f_rnd_9999_07(void){return test("%.0f", -0.999);}
int bonus_f_rnd_9999_08(void){return test("%.1f", -0.999);}
int bonus_f_rnd_9999_09(void){return test("%.0f", -0.099);}
int bonus_f_rnd_9999_10(void){return test("%.1f", -0.099);}
int bonus_f_rnd_9999_11(void){return test("%.0f", -9.0);}
int bonus_f_rnd_9999_12(void){return test("%.1f", -9.0);}
int bonus_f_rnd_9999_13(void){return test("%.0f", -9.9);}
int bonus_f_rnd_9999_14(void){return test("%.1f", -9.9);}
int bonus_f_rnd_9999_15(void){return test("%.0f", -9.999);}
int bonus_f_rnd_9999_16(void){return test("%.1f", -9.999);}
int bonus_f_rnd_9999_17(void){return test("%.0f", -0.999);}
int bonus_f_rnd_9999_18(void){return test("%.1f", -0.999);}
int bonus_f_rnd_9999_19(void){return test("%.0f", -0.099);}
int bonus_f_rnd_9999_20(void){return test("%.1f", -0.099);}
// %e round 9.999
int bonus_e_rnd_9999_01(void){return test("%.0e", -9.0);}
int bonus_e_rnd_9999_02(void){return test("%.1e", -9.0);}
int bonus_e_rnd_9999_03(void){return test("%.0e", -9.9);}
int bonus_e_rnd_9999_04(void){return test("%.1e", -9.9);}
int bonus_e_rnd_9999_05(void){return test("%.0e", -9.999);}
int bonus_e_rnd_9999_06(void){return test("%.1e", -9.999);}
int bonus_e_rnd_9999_07(void){return test("%.0e", -0.999);}
int bonus_e_rnd_9999_08(void){return test("%.1e", -0.999);}
int bonus_e_rnd_9999_09(void){return test("%.0e", -0.099);}
int bonus_e_rnd_9999_10(void){return test("%.1e", -0.099);}
int bonus_e_rnd_9999_11(void){return test("%.0e", -9.0);}
int bonus_e_rnd_9999_12(void){return test("%.1e", -9.0);}
int bonus_e_rnd_9999_13(void){return test("%.0e", -9.9);}
int bonus_e_rnd_9999_14(void){return test("%.1e", -9.9);}
int bonus_e_rnd_9999_15(void){return test("%.0e", -9.999);}
int bonus_e_rnd_9999_16(void){return test("%.1e", -9.999);}
int bonus_e_rnd_9999_17(void){return test("%.0e", -0.999);}
int bonus_e_rnd_9999_18(void){return test("%.1e", -0.999);}
int bonus_e_rnd_9999_19(void){return test("%.0e", -0.099);}
int bonus_e_rnd_9999_20(void){return test("%.1e", -0.099);}
// %g round 9.999
int bonus_g_rnd_9999_01(void){return test("%.0g", -9.0);}
int bonus_g_rnd_9999_02(void){return test("%.1g", -9.0);}
int bonus_g_rnd_9999_03(void){return test("%.0g", -9.9);}
int bonus_g_rnd_9999_04(void){return test("%.1g", -9.9);}
int bonus_g_rnd_9999_05(void){return test("%.0g", -9.999);}
int bonus_g_rnd_9999_06(void){return test("%.1g", -9.999);}
int bonus_g_rnd_9999_07(void){return test("%.0g", -0.999);}
int bonus_g_rnd_9999_08(void){return test("%.1g", -0.999);}
int bonus_g_rnd_9999_09(void){return test("%.0g", -0.099);}
int bonus_g_rnd_9999_10(void){return test("%.1g", -0.099);}
int bonus_g_rnd_9999_11(void){return test("%.0g", -9.0);}
int bonus_g_rnd_9999_12(void){return test("%.1g", -9.0);}
int bonus_g_rnd_9999_13(void){return test("%.0g", -9.9);}
int bonus_g_rnd_9999_14(void){return test("%.1g", -9.9);}
int bonus_g_rnd_9999_15(void){return test("%.0g", -9.999);}
int bonus_g_rnd_9999_16(void){return test("%.1g", -9.999);}
int bonus_g_rnd_9999_17(void){return test("%.0g", -0.999);}
int bonus_g_rnd_9999_18(void){return test("%.1g", -0.999);}
int bonus_g_rnd_9999_19(void){return test("%.0g", -0.099);}
int bonus_g_rnd_9999_20(void){return test("%.1g", -0.099);}

/* -----------------------------------------------------------------------------
** 						NEGATIVE PRECISION
** ---------------------------------------------------------------------------*/
// %f negative precision
int bonus_f_neg_prec_star_01(void){return test("%.*f", -3, 3.1415926535);}
int bonus_f_neg_prec_star_02(void){return test("%.*f", -1, 3.1415926535);}
int bonus_f_neg_prec_star_03(void){return test("%.*f", -1, 0.0);}
// %e negative precision
int bonus_e_neg_prec_star_01(void){return test("%.*e", -3, 3.1415926535);}
int bonus_e_neg_prec_star_02(void){return test("%.*e", -1, 3.1415926535);}
int bonus_e_neg_prec_star_03(void){return test("%.*e", -1, 0.0);}
// %g negative precision
int bonus_g_neg_prec_star_01(void){return test("%.*g", -3, 3.1415926535);}
int bonus_g_neg_prec_star_02(void){return test("%.*g", -1, 3.1415926535);}
int bonus_g_neg_prec_star_03(void){return test("%.*g", -1, 0.0);}
// %d negative precision
int d_neg_prec_star_01(void){return test("%.*d", -3, 12345);}
int d_neg_prec_star_02(void){return test("%.*d", -1, 12345);}
int d_neg_prec_star_03(void){return test("%.*d", -1, 0);}
// %u negative precision
int u_neg_prec_star_01(void){return test("%.*u", -3, 12345);}
int u_neg_prec_star_02(void){return test("%.*u", -1, 12345);}
int u_neg_prec_star_03(void){return test("%.*u", -1, 0);}
// %o negative precision
int notintsubject_o_neg_prec_star_01(void){return test("%.*o", -3, 12345);}
int notintsubject_o_neg_prec_star_02(void){return test("%.*o", -1, 12345);}
int notintsubject_o_neg_prec_star_03(void){return test("%.*o", -1, 0);}
// %x negative precision
int x_neg_prec_star_01(void){return test("%.*x", -3, 12345);}
int x_neg_prec_star_02(void){return test("%.*x", -1, 12345);}
int x_neg_prec_star_03(void){return test("%.*x", -1, 0);}
// %X negative precision
int X_neg_prec_star_01(void){return test("%.*X", -3, 12345);}
int X_neg_prec_star_02(void){return test("%.*X", -1, 12345);}
int X_neg_prec_star_03(void){return test("%.*X", -1, 0);}
static char *s_hello = "hello world";
// %s negative precision
int s_neg_prec_star_01(void){return test("%.*s", -3, 0);}
int s_neg_prec_star_02(void){return test("%.*s", -1, 0);}
// %p negative precision
int p_neg_prec_star_01(void){return test("%.*p", -3, s_hello);}
int p_neg_prec_star_02(void){return test("%.*p", -1, s_hello);}
int p_neg_prec_star_03(void){return test("%.*p", -3, 0);}
int p_neg_prec_star_04(void){return test("%.*p", -1, 0);}


/* -----------------------------------------------------------------------------
** 						%n format only test cases
** ---------------------------------------------------------------------------*/
// %p negative precision
int n;
int bonus_n_format_only(void){return test("pft%ntest", &n); (void)n;} 
int bonus_n_format_only_sp(void){return test("pft% ntest", &n); (void)n;} 
int bonus_n_format_only_af(void){return test("pft%#ntest", &n); (void)n;} 
int bonus_n_format_only_zp(void){return test("pft%0ntest", &n); (void)n;} 
int bonus_n_format_only_lj(void){return test("pft%-ntest", &n); (void)n;} 
int bonus_n_format_only_as(void){return test("pft%+ntest", &n); (void)n;} 
int bonus_n_format_only_w(void){return test("pft%5ntest", &n); (void)n;} 
int bonus_n_format_only_prec(void){return test("pft%.5ntest", &n); (void)n;} 
int bonus_n_format_only_w_prec(void){return test("pft%5.5ntest", &n); (void)n;} 
int bonus_n_format_only_prec_star(void){return test("pft%.*ntest%d", 5, &n, 123); (void)n;}
int bonus_n_format_only_w_star(void){return test("pft%*.ntest%d", 5, &n, 123); (void)n;}
int bonus_n_format_only_wprec_star(void){return test("pft%*.*ntest%d", 5, 5, &n, 123); (void)n;}

#pragma clang diagnostic pop
