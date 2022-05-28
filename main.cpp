#include "FileProcessor.h"

int main(int argc, char **argv){
    // ensure correct amount of command line arguments
    if(argc != 1){
        cout << "Invalid number of arguments" << endl;
        cout << "Usage: ./assignment6.out" << endl;
        return -1;
    }
    FileProcessor *processor = new FileProcessor();
    // checks for facultyTable and studentTable in directory
    processor->processFile("./facultyTable", "./studentTable");
    delete processor;
    return 0;
}