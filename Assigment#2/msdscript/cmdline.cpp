#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include "cmdline.hpp"
#include <iostream>
#include <cstdlib>

//Declare a function named "use_arguments" that takes two parameters: an integer "argc" and an array of strings "argv".

void use_arguments(int argc, char* argv[]) {
    //Declare a boolean variable "testFlag" and initialize it to false. This variable will be used to track whether the "--test" flag is present.
    bool testFlag = false;

    //Start a loop that iterates over the command-line arguments. The loop begins at index 1 to skip the program name (argv[0]).
    //++i will increment the value of i, and then return the incremented value.
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
// Catch::Session().run returns 0 on success, non-zero on failure.
                int result = Catch::Session().run(1, argv);
                    if (result != 0) {
// Exit immediately with exit(1) if tests fail.
                        exit(1);
                    }
                testFlag = true;
            }
        } else {
            //If the current argument is neither "--help" nor "--test", this line prints an error message to the standard error.
            std::cerr << "Bad flag: " << arg << "'" << std::endl;
            exit(1);
        }
    }
}

