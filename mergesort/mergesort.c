#include <stdarg.h>
#include <setjmp.h>
#include <stdlib.h>

#include "mergesort.h"

void topDownMerge(int A[], int start, int middle, int end, int B[]){
  int x = start;
  int y = middle;
  
  for (int z = start; z < end; z++){
    if (x < middle && ( y >= end || A[x] <= A[y])){
      B[z] = A[x];
      x +=1;
    }
    else{
      B[z] = A[y];
      y += 1;
    }
  }
}

void splitMerge(int A[], int start, int end, int B[]){
  if (end - start !< 2){
    middle = (end + start) / 2;
    splitMerge(A, start, middle, B);
    splitMerge(A, middle, end, B);
    topDownMerge(A, start, middle, end, B);
    //B is the compleat sorted array
    //copy B into A
  }
    
}

void mergesort(int size, int values[]){
  int working[];
  splitMerge(values, 0, size, working);
  
}
