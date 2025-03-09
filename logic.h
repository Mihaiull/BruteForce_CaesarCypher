#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>


/*
A function that reads the distribution of letters from a file
and stores it in a vector
*/
void readDistribution(std::vector<float>& distribution, std::string filename);

/*
A function that computes th normalised frequency of each character(a histogram) in a text
*/
void computeHistogram(std::vector<float>& histogram, std::string text);

/*
A function that computes the Chi square distance between two histograms(invata iar analiza de pe sem 1 boule)
*/
float chiSquareDistance(const std::vector<float>& histogram1, const std::vector<float>& histogram2);

/*
A function that breaks the Caesar’s cipher using frequency analysis: iteratively shifts
the encrypted code through all the possible permutations, computes the Chi-square
distance between each permutation and the approximate distribution of letters in English,
and returns the permutation with the least Chi squared distance as the solution.
*/
int bruteForceCaesarCypher(const std::vector<float>& distribution, std::string encryptedText, std::string& decryptedText, int& key);

/*
A minimal UI that offers the users a few choices like:
- display the key
- exit
*/
void UI();
