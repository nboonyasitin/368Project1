#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

#ifndef DRIVER_H
#define DRIVER_H

class Driver
{
    private: 
        std::string contents;
        std::string name;
        int id = 0;

    public:
        Driver();
        ~Driver();
        void run(std::string arg);

};
#endif




