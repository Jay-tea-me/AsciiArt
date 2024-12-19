//
// Created by Justine Wright on 2024/12/18.
//


#include <gtest/gtest.h>
#include <asciiArtGenerator.h>


// Demonstrate some basic assertions.
TEST(AsciiArtGenerator, GetGrayPixelsValuesReturnsExpectedAsciiCharacter) {
    const int blockSize = 2;
    std::vector<std::vector<int>> pixels = {{255, 255,125, 130, 0, 0},{255, 255, 125, 130, 0, 0}};
    std::string expectedAscii = " o@\n";
    asciiArtGenerator iut(pixels, blockSize);
    std::string actualAscii = iut.getAscii();
    EXPECT_STREQ(actualAscii.c_str(), expectedAscii.c_str());
}

TEST(AsciiArtGenerator, GetGrayPixelsValues_ColsWidthDoesNotDivideByBlockSize_LastCharacterDeterminedBySmallerBlockSize) {
    const int blockSize = 2;
    std::vector<std::vector<int>> pixels = {{255, 255,125, 130, 0},{255, 255, 125, 130, 0}, {0, 0,0, 0, 0}, {0, 0,0, 0, 0}};
    std::string expectedAscii = " o@\n@@@\n";
    asciiArtGenerator iut(pixels, blockSize);
    std::string actualAscii = iut.getAscii();
    EXPECT_STREQ(actualAscii.c_str(), expectedAscii.c_str());
}