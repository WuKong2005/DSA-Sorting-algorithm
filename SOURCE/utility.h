#pragma once

#include <iostream>
#include "sortExecute.h"
#include "DataGenerator.h"
#include "fstream"

int isValidNumber(std::string str);
int getInputOrder(std::string flag);
int getTypeMeasure(std::string flag);
std::string getInputOrderName(int inputOrderID);

void readFile(int* &arr, int &n, std::string pathFile);
void writeFile(int arr[], int n, std::string pathFile);