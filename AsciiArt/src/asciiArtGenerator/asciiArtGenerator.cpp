//
// Created by Justine Wright on 2024/12/18.
//

#include <asciiArtGenerator.h>

asciiArtGenerator::asciiArtGenerator(std::vector<std::vector<int>> grayPixels, int blockSize) {
    asciiArtGenerator::grayPixels = grayPixels;
    asciiArtGenerator::blockSize = blockSize;
    rows = grayPixels.size();
    cols = grayPixels[0].size();
}

std::string asciiArtGenerator::getAscii() {
    const std::string map = " .,:;ox%#@";
    std::string asciiArt;
    for (int r = 0; r < rows; r+=blockSize) {
        for (int c = 0; c < cols; c+=blockSize) {
            int pixelAreaIntensity = calculatePixelAreaIntensity(r, c);
            char asciiChar = map[(255-pixelAreaIntensity)*map.size()/256];
            asciiArt += asciiChar;
        }
        asciiArt += "\n";
    }
    return asciiArt;
}

int asciiArtGenerator::calculatePixelAreaIntensity(int row, int col) const {
    const int startRowIndex = row;
    const int endRowIndex = (row + blockSize) > rows ? rows : (row + blockSize);
    const int startColIndex = col;
    const int endColIndex = (col + blockSize) > cols ? cols : (col + blockSize);
    int pixelCount = 0;
    int totalPixelAreaIntensity = 0;
    for (int r=startRowIndex; r < endRowIndex; r++) {
        for (int c=startColIndex; c < endColIndex; c++) {
            pixelCount ++;
            totalPixelAreaIntensity += grayPixels[r][c];
        }
    }
    return totalPixelAreaIntensity/pixelCount;
}



