#ifndef BUBBLE
#define BUBBLE
#include "sorter.h"

template<class ItemType>
class Bubble : public Sorter<ItemType>{
    private:
        int size;
        int compares = 0;
        int swaps = 0;
        ItemType data[SIZE];
    public: 
        Bubble(ItemType arr [], int size);
        int getCompares() override;
        int getSwaps() override;
        int* getArr();
        void sort() override; 
         ~Bubble() { } 
};  
#include "bubble.cpp"
#endif