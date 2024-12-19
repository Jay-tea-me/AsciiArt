#include <iostream>

#include "include/asciiArtGenerator.h"
#include "include/imageTransformer.h"
using namespace std;

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("Please provide image file path in arguments\n");
        return -1;
    }
    vector<vector<int>> grayPixelValues = getGrayPixelValues(argv[1]);
    asciiArtGenerator asciiArtGenerator(grayPixelValues, 15);
    cout << asciiArtGenerator.getAscii();
 
    return 0;
}
