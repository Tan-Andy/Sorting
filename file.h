#include <string>
#include <ostream>
#include <fstream>
#include <vector>
class File{
    private:
        std::string txtFile;
        void titlePrinter();
        std::vector <int> runData;
        std::vector <int> compData;
        std::vector <int> swapData;
        std::ofstream outFile;
    public:
        File(std::string);
        void append(int, int, int);
        void next();
};