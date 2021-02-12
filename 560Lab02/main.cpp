#include<iostream>
#include "Driver.h"

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Incorrect number of parameters. Enter sample you are trying to read it with executable." << std::endl;
    }
    else
    {
        Driver myDriver;
        myDriver.run(argv[1]);
    }
}