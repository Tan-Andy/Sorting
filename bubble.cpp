#include "bubble.h"

#include <iostream>
template<class ItemType> 
Bubble<ItemType>::Bubble(ItemType arr[], int size): size (size){
    for (int i = 0; i < size ; i++){
        data[i] = arr[i];
    }
};

template<class ItemType>
void Bubble<ItemType>::sort(){
    compares =0;
    swaps = 0;
    for (int i=0; i < (size-1); i++){
        for(int j = 0; j < (size-1); j++){
            if(data[j] > data[j+1]){
                ItemType temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
                swaps++;
            }
            compares++;
        }
    }
};

template<class ItemType>
int* Bubble<ItemType>::getArr(){
    return data;
}

template<class ItemType>
int Bubble<ItemType>::getCompares(){
    return compares;
}

template<class ItemType>
int Bubble<ItemType>::getSwaps(){
    return swaps;
}