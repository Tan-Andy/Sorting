#include "insert.h"

#include <iostream>
template<class ItemType> 
Insert<ItemType>::Insert(ItemType arr[], int size): size (size){
    for (int i = 0; i < size ; i++){
        data[i] = arr[i];
    }
};

template<class ItemType>
void Insert<ItemType>::sort(){
    compares =0;
    swaps = 0;
    int j;
    for (int i=0; i < (size-1); i++){
        j = i;
        while(j>0 && (data[j] < data[j-1])){
            ItemType temp = data[j];
            data[j] = data[j-1];
            data[j-1] = temp;
            j--;
            swaps++;
        }
        compares++;
    }
}

template<class ItemType>
int Insert<ItemType>::getCompares(){
    return compares;
}

template<class ItemType>
int Insert<ItemType>::getSwaps(){
    return swaps;
}