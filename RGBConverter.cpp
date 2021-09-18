#include "RGBConverter.h"

RGBConverter::RGBConverter(){}

int RGBConverter::hexDigConvert(char digit) {
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

int RGBConverter::redHexToDec(std::string inHex) {
    int ans = 0;
    int leftDig = hexDigConvert(inHex[0]);
    int rightDig = hexDigConvert(inHex[1]);
    ans = 16 * leftDig + rightDig;
    return ans;
}

int RGBConverter::greenHexToDec(std::string inHex) {
    int ans = 0;
    int leftDig = hexDigConvert(inHex[2]);
    int rightDig = hexDigConvert(inHex[3]);
    ans = 16 * leftDig + rightDig;
    return ans;
}

int RGBConverter::blueHexToDec(std::string inHex) {
    int ans = 0;
    int leftDig = hexDigConvert(inHex[4]);
    int rightDig = hexDigConvert(inHex[5]);
    ans = 16 * leftDig + rightDig;
    return ans;
}

std::string RGBConverter::pixelCMYKtoRGB(std::string cmyk) {
    std::string rgbRes = "answer to be returned";

    return rgbRes;
}

std::string RGBConverter::pixelRGBtoCMYK(std::string rgb) {
    int redValDec = redHexToDec(rgb);
    int greenValDec = greenHexToDec(rgb);
    int blueValDec = blueHexToDec(rgb);

    int cyanValue = (255 - redValDec);
    int magValue = (255 - greenValDec);
    int yelValue = (255 - blueValDec);
    int keyValue = std::min(std::min(cyanValue, magValue), yelValue);

    std::string ans = "(" + std::to_string(cyanValue) + "," + std::to_string(magValue) + "," + std::to_string(yelValue) + "," + std::to_string(keyValue) + ")";
    return ans;
}
