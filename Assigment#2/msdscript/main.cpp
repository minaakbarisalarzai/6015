//#define CATCH_CONFIG_RUNNER
//#include "catch.h"
#include "cmdline.hpp"
#include <iostream>
#include "Expr.hpp"


int main(int argc, char* argv[]) {
    //Catch::Session().run(1, argv);
    //Call use_arguments function
    use_arguments(argc, argv);
    std::cout<<"This is text in main that got printed."<<std::endl;
    return 0;
}
