#include "utility.h"

int isValidNumber(std::string str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), [](char d) { return (int)d >= (int)'0' && (int)d <= (int)'9'; });
}

int getInputOrder(std::string flag) {
    if (flag == "-rand")    return DATA_ORDER::RANDOM_DATA;
    if (flag == "-nsorted") return DATA_ORDER::NEARLY_SORTED_DATA;
    if (flag == "-sorted")  return DATA_ORDER::SORTED_DATA;
    if (flag == "-rev")     return DATA_ORDER::REVERSE_DATA;
    return NUMBER_DATA_ORDER;
}

int getTypeMeasure(std::string flag) {
    if (flag == "-time") return 1;
    if (flag == "-comp") return 2;
    if (flag == "-both") return 3;
    return 0;
}

std::string getInputOrderName(int inputOrderID) {
    std::string listName[] = {"Random data", "Nearly sorted data", "Sorted data", "Reverse data"};
    return listName[inputOrderID];
}

void readFile(int* &arr, int &n, std::string pathFile) {
    std::ifstream fin(pathFile.c_str());

    fin >> n;
    arr = new int[n];

    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }

    fin.close();
}

void writeFile(int arr[], int n, std::string pathFile) {
    std::ofstream fout(pathFile.c_str());

    fout << n << '\n';
    for (int i = 0; i < n; i++) {
        fout << arr[i] << ' ';
    }

    fout.close();
}