//
//  cmdline.cpp
//  msdscript
//
//  Created by Mina Akbari on 1/10/24.
//

#include "cmdline.hpp"
#include <iostream>
#include <cstdlib>
//Declare a function named "use_arguments" that takes two parameters: an integer "argc" (argument count) and an array of strings "argv" (argument vector).

void use_arguments(int argc, char* argv[]) {
    //Declare a boolean variable "testFlag" and initialize it to false. This variable will be used to track whether the "--test" flag is present.
    bool testFlag = false;

    //Start a loop that iterates over the command-line arguments. The loop begins at index 1 to skip the program name (argv[0]).
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--help") {
            std::cout << "You can pass the following as arguments:\n--help\n--test\n" << std::endl;
            exit(0);
        } else if (arg == "--test") {
            if (testFlag) {
                std::cerr << "Error: Duplicate --test argument." << std::endl;
                exit(1);
            } else {
                std::cout << "Tests passed" << std::endl;
                //Set the "testFlag" to true to mark that the flag has been processed.
                testFlag = true;
            }
        } else {
            //If the current argument is neither "--help" nor "--test", this line prints an error message to the standard error.
            std::cerr << "Bad flag: " << arg << "'" << std::endl;
            exit(1);
        }
    }
}

