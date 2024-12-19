//
// Created by Justine Wright on 2024/12/18.
//

#ifndef ASCIIARTGENERATOR_H
#define ASCIIARTGENERATOR_H
#include <vector>


class asciiArtGenerator {
public:
    asciiArtGenerator(std::vector<std::vector<int>> grayPixels, int blockSize);
    std::string getAscii();
private:
    int calculatePixelAreaIntensity(int row, int col) const;
    std::vector<std::vector<int>> grayPixels;
    int blockSize;
    int rows;
    int cols;
};



#endif //ASCIIARTGENERATOR_H
