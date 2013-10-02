#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "array_merge.h"
#include "mergesort.h"

int countDistE(int A[],int size){
  int index=0;
  int count=0;
  while(index<size){
    count++;
    if(index!=size-1){
      while(A[index]==A[index+1]){
	index++;
      }
    }
    index++;
  }
  return count;
}



int* removeDup(int A[], int size){
  mergesort(size,A);
  int tempSize=countDistE(A,size);
  int* temp=calloc(tempSize+1,sizeof(int));
  int indexTemp=0;
  int indexA=0;
  
  //Add arr size at index 0
  temp[indexTemp++]=tempSize;
  //add the rest of the elements
  while(indexTemp<(tempSize+1)){  
    temp[indexTemp++]=A[indexA];
    //increment indexA untill the next int is distinct
    if(indexA!=size-1){
      while(A[indexA]==A[indexA+1]){
	indexA++;
      }
    }
    indexA++;
  }
  return temp;
}

//sizeAll is the all the sizes added up
int* mergeAll(int num_arrays, int* sizes, int** values, int sizeAll){
  int currentArr=0;
  int* designation=calloc(sizeAll+1,sizeof(int));
  int desIndex=0;
  while(currentArr<num_arrays){
    int index=0;
    while(index<sizes[currentArr]){
      designation[desIndex++]=values[currentArr][index++];
    }
    currentArr++;
  }
  return designation;
}


int* array_merge(int num_arrays, int* sizes, int** values){
  int numArrIndex = num_arrays;
  int size=0;
  int* allMerged;
  int* tempArr;
  
  //add up sizes
  while(numArrIndex>0){
    size += sizes[--numArrIndex];
  }
  //if only one array dont need to call mergeAll
  if(num_arrays==1){
    tempArr=removeDup(values[0],size);
  }else{
    allMerged = mergeAll(num_arrays, sizes, values,size);
    tempArr=removeDup(allMerged,size);
    free(allMerged);
  }


  return tempArr;
}
