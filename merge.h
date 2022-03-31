#ifndef MERGE
#define MERGE
#include "sorter.h"

template<class ItemType>
class Merge : public Sorter<ItemType>{
    private:
        int size;
        int compares = 0;
        int swaps = 0;
        ItemType data[SIZE];
        ItemType final[SIZE];
        void mergeSort(int left, int right);
        void merger(int,int,int);
    public: 
        Merge(ItemType arr [], int size);
        int getCompares() override;
        int getSwaps() override;
        void sort() override;

         ~Merge() { } 
};  
#include "merge.cpp"

#endif