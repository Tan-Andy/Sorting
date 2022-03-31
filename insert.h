#ifndef INSERT
#define INSERT
#include "sorter.h"

template<class ItemType>
class Insert : public Sorter<ItemType>{
    private:
        int size;
        int compares = 0;
        int swaps = 0;
        ItemType data[SIZE];
    public: 
        Insert(ItemType arr [], int size);
        int getCompares() override;
        int getSwaps() override;
        void sort() override; 
         ~Insert() { } 
};  
#include "insert.cpp"
#endif
