#include <stdarg.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>

#include "mergesort.h"

void printArr(int size, int A[]){
  int i;
  for(i=0;i<size;i++){
    printf("%d", A[i]);
  }
}

void topDownMerge(int A[], int start, int middle, int end, int B[]){
  int x = start;
  int y = middle;
  int z = start;
  
  while (z < end){
    if (x < middle && ( y >= end || A[x] <= A[y])){
      B[z] = A[x];
      x += 1;
    }
    else{
      B[z] = A[y];
      y += 1;
    }
    z = z + 1;
  }
}

void copyArray (int A[], int B[], int start, int end){
  int index = start;
  while( index <= end ){
    A[index] = B[index];
    index += 1;
  }
}

void splitMerge(int A[], int start, int end, int B[]){
  if ((end - start) >= 2){
    int middle = (end + start) / 2;
    splitMerge(A, start, middle, B);
    printf("HEYYYYYYYYYYYYYYYYYYYY\n");
    splitMerge(A, middle, end, B);
    topDownMerge(A, start, middle, end, B);
    //B is the compleat sorted array
    copyArray(A, B, start, end);
  }  
}

void mergesort(int size, int values[]){
  int* working = malloc(size * sizeof(int));
  splitMerge(values, 0, size-1, working);
  free(working);
  printArr(size, values);
}
