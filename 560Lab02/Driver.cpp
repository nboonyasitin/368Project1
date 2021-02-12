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
    std::cout << std::endl;

    menu(); 
}

void Driver::menu()
{
    int input;
    do
    {
        std::cout << "\nPlease choose one of the following commands: \n";
        std::cout << "1- AddStudent\n2- RemoveStudent\n3- PrintStudentList\n4- FindStudent\n5- Exit\n\n";
        std::cout << ">Input: ";
        std::cin >> input;

        if(input == 1)
        {
            std::cout << ">Enter the record to be inserted:\n";
        }

        if(input == 2)
        {
            std::cout << ">Enter a record to be removed:\n";
        }

        if(input == 3)
        {
            std::cout << ">Printing student list...\n";
        }
        
        if(input == 4)
        {
            std::cout << ">Enter the student to be found:\n";
        }

    } while(input!=5);

    if(input == 5)
    {
        std::cout << ">Bye bye!\n";
    }
}    

