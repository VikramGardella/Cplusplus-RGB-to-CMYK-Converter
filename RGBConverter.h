#ifndef RGBCONVERTER_H
#define RGBCONVERTER_H

#include <cstdlib>
#include <algorithm>
#include <string>
#include <math.h>

class RGBConverter {

public:
	//Constructor
	RGBConverter();

	//Functionalities
	int hexDigConvert(char digit);

	int redHexToDec(std::string inHex);
	int greenHexToDec(std::string inHex);
	int blueHexToDec(std::string inHex);

	std::string pixelCMYKtoRGB(std::string cmyk);
	std::string pixelRGBtoCMYK(std::string rgb);

};

#endif