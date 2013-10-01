#include <stdarg.h>
#include <setjmp.h>
#include <stdlib.h>
#include<stdio.h>


#include "../include/cmockery.h"
#include "disemvowel.h"

void test_empty_str(void) {
  char* test = disemvowel("");
  printf("\nEMPTY STRING\n");
  printf(test);
  assert_string_equal("", test);
  free(test);
}

void test_no_vowels(void) {
  char* test = disemvowel("pqrst");
  printf("\nNO VOWELS\n");
  printf("Test=%s",test);
  assert_string_equal("pqrst",test);
  free(test);
}


void test_only_vowels(void) {
  char* test = disemvowel("aeiouAEIOUOIEAuoiea");
  printf("ONLY VOWELS!\n");
  printf(test);
  assert_string_equal("", test);
  free(test);
}

void test_my_name(void) {
  char* test = disemvowel("Nicholas Freitag McPhee");
  printf("\nTEST MY NAME\n");
  printf(test);  
  assert_string_equal("Nchls Frtg McPh",test);
  free(test);
}

void test_punctuation(void) {
  char* test= disemvowel("An (Unexplained) Elephant!");
  assert_string_equal("n (nxplnd) lphnt!",test);
  free(test);
}

void test_long_string(void) {
  char* str;
  int size;
  int i;

  size = 50000;
  str = calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  char* test = disemvowel(str);
  assert_string_equal("xyz", test);
  free(test);
  free(str);
}

int main(int argc, char* argv[]) {
  UnitTest tests[] = {
    unit_test(test_empty_str),
    unit_test(test_no_vowels),
    unit_test(test_only_vowels),
    unit_test(test_my_name),
    unit_test(test_punctuation),
    unit_test(test_long_string)
  };
  return run_tests(tests);
}
