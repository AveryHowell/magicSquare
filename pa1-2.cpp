//  Magic Squares Generator

#include <iostream>
#include "pa1.h"


int main(int argc, const char * argv[]) {
    //n is the user's input, uses checkMagicSize to get the user's choice for the magic square's size
    int n = checkMagicSize();
    
    
    //Calls in the createMagicSquare()
    createMagicSquare(n);
    

    return 0;
}

