#include "Driver.h"

Driver::Driver()
{
    //constructor;
}

Driver::~Driver()
{
    //deconstructor;
}

void Driver::run(std::string arg)
{
    std::ifstream inFile;
    inFile.open(arg);
    
    if(inFile.is_open())
    {
        while(inFile >> contents)
        {   
            if(contents == ",")
            {
                std::cout << " , ";
            }
            if(contents == ":")
            {
                std::cout << " : ";
            }
            std::cout << " " << contents << " ";
        }
        inFile.close();
    }  
    else
    {
        std::cout << "File cannot open." << std::endl;
    }
    
}