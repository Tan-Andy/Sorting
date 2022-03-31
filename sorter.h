#ifndef SORTER
#define SORTER
#define SIZE 100000

//sorter abstract templated class
template<class ItemType>
class Sorter{
    private:
        int size;
        int compares = 0;
        int swaps = 0;
        ItemType data[SIZE];
    public: 
        virtual int getCompares() = 0;
        virtual int getSwaps() = 0;
        virtual void sort() = 0; 
        virtual ~Sorter() { } 
};  

#endif