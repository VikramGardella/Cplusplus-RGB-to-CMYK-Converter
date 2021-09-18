#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <math.h>
#include "RGBConverter.h"

using namespace std;


void printHexRGBPixelsInVectorizedFormat(string toPrint[3][4]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << toPrint[row][col] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printDecimalRGBPixelsInVectorizedFormat(string toPrint[3][4], RGBConverter conv) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << "(" << conv.redHexToDec(toPrint[row][col]) << "," << conv.greenHexToDec(toPrint[row][col]) << "," << conv.blueHexToDec(toPrint[row][col]) << ")" << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printCMYKPixelsInVectorizedFormat(string toPrint[3][4], RGBConverter conv) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << conv.pixelRGBtoCMYK(toPrint[row][col]) << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){

    RGBConverter converty = RGBConverter();

    /*Starting off as RGB values where:

    "ff0000" = a red pixel,
    "00ff00" = a green pixel,
    "0000ff" = a blue pixel,
    "ff00ff" = a purple pixel,
    "ffffff" = a white pixel,
    "000000" = a black pixel, etc.

    Assume the image is 4 pixels wide by 3 pixels tall and vectorized:*/
    string rowsOfPixels[3][4] = {
        { "ff00ff","00ff00","000000","ffffff" },
        { "880022","220088","444444","00aa77" },
        { "ff0000","00ff00","0000ff","553355" }
    };

    cout << "Pixels making up the 4x3 pixel jpeg after being vectorized(RGB Hex):\n" << endl;
    printHexRGBPixelsInVectorizedFormat(rowsOfPixels);

    cout << "\nPixels in 4x3 2-dimensional array (Decimal RGB values: 0-255):\n" << endl;
    printDecimalRGBPixelsInVectorizedFormat(rowsOfPixels, converty);

    cout << "\nPixels in 4x3 2-dimensional array (CMYK values):\n" << endl;
    printCMYKPixelsInVectorizedFormat(rowsOfPixels, converty);

	return 0;
}