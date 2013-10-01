#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>
#include "disemvowel.h"

int is_vowel( char c){
  int result=0;
  if ( c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' ||  c == 'i' ||  c == 'O' ||  c == 'o' ||  c == 'U' ||  c == 'u'){
    result = 1;
  }
  return result;
}

char* disemvowel(char* str) {
  int counter = 0;
  int index = 0;
  int index2 = 0;
  int length =0;
  //for loop for counting length of string without vowels
  while( str[length] != '\0'){
    if ( is_vowel(str[length]) != 1){
      counter += 1;
    }
    length+=1;
  }
  char* new_string = calloc(counter+1, sizeof(char));
  // Transfer all non-vowel characters
  
  while(index<length){
    //if!=vowel
    if ( is_vowel(str[index]) != 1){
      //
      new_string[index2] = str[index];
      index2 += 1;
    }
    index += 1;
  }
  new_string[index2 + 1] = '\0';
  
  return new_string;
}


