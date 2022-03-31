//Andy Tan
//3/28/2022
//HW5

//GRAPHS ARE WITHIN THE PNG FILES
//First list of values in csv are unsorted. Under the first average row are the sorted

//KNOWN ERRORS
    //Sorted and Unsorted are similar
    //at 100k the program freezes on my computer and can't output graphs(would love to know the reason why)

#include <stdlib.h>
#include <chrono>
#include "bubble.h"
#include "insert.h"
#include "merge.h"
#include "file.h"
#include <iostream>


//definitions for test numbers
#define tNum1 1000
#define tNum2 10000
#define tNum3 100000

//extra functions to help with resources and readability
void randArray(int size, int input[]);

void algoSet(int sortC, int[], int size);

int* bSort(int [],int size, File &fName);

void iSort(int [],int size, File &fName);

void mSort(int [],int size, File &fName);

int main(){
    int temp1[tNum1];
    int temp2[tNum2];
    int temp3[tNum3];
    randArray(1000,temp1);
    randArray(10000,temp2);
    randArray(100000,temp3);

    algoSet(1,temp1 ,tNum1);
    algoSet(1,temp2 , tNum2);
    // algoSet(1,temp3 , tNum3); //WORKS BUT VERY SLOW!! COMMENT OUT WHEN TESTING IF HW WORKS!
    algoSet(2,temp1 , tNum1);
    algoSet(2,temp2 , tNum2);
    // algoSet(2,temp3 , tNum3); //WORKS BUT VERY SLOW!! COMMENT OUT WHEN TESTING IF HW WORKS!
    algoSet(3,temp1 , tNum1);
    algoSet(3,temp2 , tNum2);
    // algoSet(3,temp3 , tNum3); //WORKS BUT VERY SLOW!! COMMENT OUT WHEN TESTING IF HW WORKS!


    //OLD WORKING CODE FOR DATA.
        // Bubble<int> bubly(temp1, tNum1);
        // File bubble("Test1k.csv");
        // int j = 0;
        // for(j; j < 2; j++){
        //     for(int i = 0; i < 10; i++){
        //         auto start = std::chrono::high_resolution_clock::now();
        //         bubly.sort();
        //         auto end = std::chrono:: high_resolution_clock:: now() ;
        //         auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
        //         bubble.append(duration.count(), bubly.getCompares(), bubly.getSwaps());
        //     }
        //     bubble.next();
        // }
    return 0;
}

//set random numbers
void randArray(int size1, int input[]){
    for(int i=0; i < size1 ; i++){
        srand(i);
        input[i]=(rand()%(int(1e+6)+1));
    }
}

//outputs a full set of data
void algoSet(int sortC, int arr[], int size){
    int i, j, k;
    std::string title;
    //choose title
    switch(sortC){
        case 1:
            title = "Bubble1_"+ std::to_string(size)+ ".csv";
            break;
        case 2:
            title = "Insert1_"+ std::to_string(size) + ".csv";
            break;
        case 3:
            title = "Merge1_"+ std::to_string(size) + ".csv";
            break;
    }
    File fname(title);
    int temp [size];
    for(i=0; i< size; i++){
        temp [i] = arr[i];
    }
    switch(sortC){
        case 1:
            //iterate for ten tests
            for(i = 0; i < 2; i++){
                for(j = 0; j < 10; j++){
                    if(i==1 && j ==9){
                        int* tempArr= bSort(temp,size,fname);
                        for(k =0; k < size;k++){
                            temp[k] = tempArr[k];
                            std::cout<< temp[k] << "  " <<tempArr[k] <<std::endl;
                        }
                    }else{
                        bSort(temp,size,fname);
                    }
                }
                fname.next();
            }
            break;
        // case 2:
        //     for(i = 0; i < 2; i++){
        //         for(j = 0; j < 10; j++){
        //             iSort(arr,size,fname);
        //         }
        //         fname.next();
        //     }
        //     break;
        // case 3:
        //     for(i = 0; i < 2; i++){
        //         for(j = 0; j < 10; j++){
        //             mSort(arr,size,fname);
        //         }
        //         fname.next();
        //     }
        //     break;
    }
}

//create object, start clock, sort, end clock, upload data
int* bSort(int arr[],int size, File &fName){
    Bubble<int> bubly(arr, size);
    auto start = std::chrono::high_resolution_clock::now();
    bubly.sort();
    auto end = std::chrono:: high_resolution_clock:: now() ;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    fName.append(duration.count(), bubly.getCompares(), bubly.getSwaps());
    return bubly.getArr();
};

void iSort(int arr[],int size, File &fName){
    Insert<int> sInsert(arr, size);
    auto start = std::chrono::high_resolution_clock::now();
    sInsert.sort();
    auto end = std::chrono:: high_resolution_clock:: now() ;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    fName.append(duration.count(), sInsert.getCompares(), sInsert.getSwaps());
};

void mSort(int arr[],int size, File &fName){
    Merge<int> sMerge(arr, size);
    auto start = std::chrono::high_resolution_clock::now();
    sMerge.sort();
    auto end = std::chrono:: high_resolution_clock:: now() ;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    fName.append(duration.count(), sMerge.getCompares(), sMerge.getSwaps());
};