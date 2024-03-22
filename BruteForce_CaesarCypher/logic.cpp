#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include "logic.h"
#include <windows.h>



void readDistribution(std::vector<float>& distribution, std::string filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Could not open file " << filename << std::endl;
		exit(1);
	}
	float value;
	while (file >> value) {
		distribution.push_back(value);
	}
	file.close();
}

void computeHistogram(std::vector<float>& histogram, std::string text)
{
	//initialize the histogram with 0s
	histogram = std::vector<float>(26, 0);
	//compute the histogram
	for (char c : text) {
		if (c >= 'a' && c <= 'z') {
			histogram[c - 'a']++;
		}
		else if (c >= 'A' && c <= 'Z') {
			histogram[c - 'A']++;
		}
	}
	//normalize the histogram
	int n = 0;
	for (float value : histogram) {
		n += value;
	}
	for (float& value : histogram) {
		value /= n;
	}
}

float chiSquareDistance(const std::vector<float>& histogram1, const std::vector<float>& histogram2)
{
	float distance = 0;
	for (int i = 0; i < 25; i++)
	{
		//x^2(C, E) = sum(i from a to z(0-24))(C[i] - E[i])^2 / E[i]
		distance += pow((histogram1[i] - histogram2[i]), 2) / histogram2[i];
	}
	return distance;
}

int bruteForceCaesarCypher(const std::vector<float>& distribution, std::string encryptedText, std::string& decryptedText, int& key)
{
	//initialize the minimum distance with a large value
	float minDistance = 1000000;
	//initialize the decrypted text
	decryptedText = "";
	//initialize the key
	key = 0;
	//iterate through all the possible keys
	for (int i = 0; i < 26; i++)
	{
		//decrypt the text
		std::string decryptedTextAux = "";
		for (char c : encryptedText)
		{
			if (c >= 'a' && c <= 'z')
			{
				decryptedTextAux += 'a' + (c - 'a' - i + 26) % 26;
			}
			else if (c >= 'A' && c <= 'Z')
			{
				decryptedTextAux += 'A' + (c - 'A' - i + 26) % 26;
			}
			else
			{
				decryptedTextAux += c;
			}
		}
		//compute the histogram of the decrypted text
		std::vector<float> histogram;
		computeHistogram(histogram, decryptedTextAux);
		//compute the distance between the histogram of the decrypted text and the distribution
		float distance = chiSquareDistance(histogram, distribution);
		//if the distance is smaller than the minimum distance, update the minimum distance, the decrypted text and the key
		if (distance < minDistance)
		{
			minDistance = distance;
			decryptedText = decryptedTextAux;
			key = i;
		}
	}
	//return the key
	return key;
}

void UI()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 36);
	while (true)
	{
		std::cout << "";
	}
}