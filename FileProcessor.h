#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "Simulation.h"
#include <unistd.h>

class FileProcessor{
    public:
        FileProcessor();
        ~FileProcessor();
        
        void processFile(string facultyInput, string studentInput);     // checks if facultyTable and studentTable are in current directory, builds BSTs for them
};

#endif