#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int hexDigConvert(char digit) {
    int ans = -1;
    if (digit == 'a' || digit == 'A') {
        ans = 10;
    }
    else if (digit == 'b' || digit == 'B') {
        ans = 11;
    }
    else if (digit == 'c' || digit == 'C') {
        ans = 12;
    }
    else if (digit == 'd' || digit == 'D') {
        ans = 13;
    }
    else if (digit == 'e' || digit == 'E') {
        ans = 14;
    }
    else if (digit == 'f' || digit == 'F') {
        ans = 15;
    }
    else {
        ans = (digit - 48);
    }

    return ans;
}

int redHexToDec(string inHex) {
    int ans = 0;
    int leftDig = hexDigConvert(inHex[0]);
    int rightDig = hexDigConvert(inHex[1]);
    ans = 16 * leftDig + rightDig;
    return ans;
}

int greenHexToDec(string inHex) {
    int ans = 0;
    int leftDig = hexDigConvert(inHex[2]);
    int rightDig = hexDigConvert(inHex[3]);
    ans = 16 * leftDig + rightDig;
    return ans;
}

int blueHexToDec(string inHex) {
    int ans = 0;
    int leftDig = hexDigConvert(inHex[4]);
    int rightDig = hexDigConvert(inHex[5]);
    ans = 16 * leftDig + rightDig;
    return ans;
}

string CMYKtoRGB(string cmyk) {
    string rgbRes = "answer to be returned";

    return rgbRes;
}

string pixelRGBtoCMYK(string rgb) {
    int redValDec = redHexToDec(rgb);
    int greenValDec = greenHexToDec(rgb);
    int blueValDec = blueHexToDec(rgb);

    int cyanValue = (255 - redValDec);
    int magValue = (255 - greenValDec);
    int yelValue = (255 - blueValDec);
    int keyValue = min(min(cyanValue, magValue), yelValue);

    string ans = "(" + to_string(cyanValue) + "," + to_string(magValue) + "," + to_string(yelValue) + "," + to_string(keyValue) + ")";
    return ans;
}

void printHexRGBPixelsInVectorizedFormat(string toPrint[3][4]){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 4; col++){
            cout << toPrint[row][col] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printDecimalRGBPixelsInVectorizedFormat(string toPrint[3][4]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << "(" << redHexToDec(toPrint[row][col]) << "," << greenHexToDec(toPrint[row][col]) << "," << blueHexToDec(toPrint[row][col]) << ")" << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printCMYKPixelsInVectorizedFormat(string toPrint[3][4]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << pixelRGBtoCMYK(toPrint[row][col]) << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
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
    printDecimalRGBPixelsInVectorizedFormat(rowsOfPixels);

    cout << "\nPixels in 4x3 2-dimensional array (CMYK values):\n" << endl;
    printCMYKPixelsInVectorizedFormat(rowsOfPixels);
   
    return 0;
}
