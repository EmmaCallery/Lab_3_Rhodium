#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "array_merge.h"


//find duplicate numbers in array
int findDuplicates(int A[]){

  return 0
}

//combines two arrays
int* mergeArr(int A[], int sizeA, int B[], int sizeB){
  int indexA=0;
  int indexB=0;
  int destination[]=calloc((sizeA+sizeB),sizeof(int));
  int indexD=0;
  while(indexA<sizeA){
    destination[indexD++]=A[indexA++];
  }
  while(indexB<sizeB){
    destination[indexD++]=A[indexB++];
  }
  
  return destination;
}

int* mergeAll(int num_arrays, int* sizes, int** values){
  int count=num_arrays;
  int totalSize;
  //gets total size of new array
  while(count>0){
    totalSize+=sizes[--count];
  }
  int newArr[]=calloc(totalSize,sizeof(int));
  int newArrIndex=0;
  while(num_arrays>0){
    int index=0;
    int currentArr=--num_arrays;
    int size=sizes[currentArr];
    while(index<size){
      newArr[newArrIndex++]=values[currentArr][--size];
    }
  }
  return newArr;

}

//num_arrays is the number of arrays in values

//sizes is an array of ints that should also have num_arrays entries
//, each of which is the length of the corresponding sub-array in values
int* array_merge(int num_arrays, int* sizes, int** values){
  


}
