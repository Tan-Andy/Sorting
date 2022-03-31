#include "file.h"

File::File(std::string txtFile): txtFile(txtFile), outFile(txtFile){
    outFile << ", Run Time, Comparisons, Swaps \n";
};
void File::titlePrinter(){
    //std::ofstream outFile (txtFile);
    outFile << ", Run Time, Comparisons, Swaps \n";

}
void File::append(int runT, int comp, int swap){
    std::string tempStr = "," + std::to_string(runT) + "," + std::to_string(comp)  + "," + std::to_string(swap) + "\n";
    runData.push_back(runT);
    compData.push_back(comp);
    swapData.push_back(swap);
    outFile << tempStr;
}
void File::next(){
    int rSum = 0, compSum = 0, swapSum = 0;
    int size = runData.size();
    while(runData.size() != 0){
        rSum += runData.back();
        compSum += compData.back();
        swapSum += swapData.back();
        runData.pop_back();
        compData.pop_back();
        swapData.pop_back();
    }
    std::string tempStr = "Average," + std::to_string(rSum/size) + "," + std::to_string(compSum/size)  + "," + std::to_string(swapSum/size) + "\n";
    outFile << tempStr;
}