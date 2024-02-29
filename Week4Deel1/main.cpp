//
// Created by Kasper on 28/02/2024.
//

#include <iostream>
#include "Stack.h"
#include "readFile.h"

int main()
{
    Stack stack;
    readFile readFile;
    readFile.read(stack);
    return 0;
}