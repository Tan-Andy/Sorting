#include "merge.h"

#include <iostream>
template<class ItemType> 
Merge<ItemType>::Merge(ItemType arr[], int size): size (size){
    //copy array
    for (int i = 0; i < size ; i++){
        data[i] = arr[i];
    }
};

template<class ItemType>
void Merge<ItemType>::sort(){
    compares =0;
    swaps = 0;
    mergeSort(0,size-1);
}

//code pulled from book pseudocode and slides
template<class ItemType>
void Merge<ItemType>::merger(int begin, int mid, int end){
    int i = begin, j = mid+1, k = begin;
    while(i <= mid && j <= end){
        if (data[i] <= data[j]){
            final[k] = data[i];
            i++;
        }else{
            final[k] = data[j];
            j++;
            swaps++;
        }
        k++;
        compares++;
    }
    while(i <= mid){
        final[k] = data[i];
        i++;
        k++;
    }
    while(j <= end){
        final[k] = data[j];
        j++;
        k++;
    }
    for(int i = begin; i <= end;i++){ //you need to update the array again everytime because merge sort expects already sorted arrays before sorting more
        data[i] = final[i];
    }
}

template<class ItemType>
void Merge<ItemType>::mergeSort(int left, int right){
    if(right > left){
        int mid = left + ((right-left)/2);
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merger(left, mid, right);
    }else{
        return;
    }
}

template<class ItemType>
int Merge<ItemType>::getCompares(){
    return compares;
}

template<class ItemType>
int Merge<ItemType>::getSwaps(){
    return swaps;
}