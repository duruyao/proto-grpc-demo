// author : duruyao
// date   : 2021.06.01
// file   : try to compile a binary file that can run on the ARM platform

#include <cstdio>
#include <cstdlib>

#include <string>
#include <iostream>

int main(int argc, char **argv) {

    fprintf(stdout, "fprintf(\"Hello C++!\");\n");
    std::cout << "std::cout<< \"Hello C++!\";" << std::endl;
    return 0;
}

