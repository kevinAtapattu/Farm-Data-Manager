#ifndef FARMING_H
#define FARMING_H


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iterator>

using namespace std;

struct Record {
    std::string year;
    std::string region;
    std::string animalName;
    int numFarms;
    int numAnimals;

    Record(const std::string& yr, const std::string& reg, const std::string& animal, int farms, int animals)
        : year(yr), region(reg), animalName(animal), numFarms(farms), numAnimals(animals) {}
};

class FarmData
{
    public:
        FarmData();
        ~FarmData();
        void loadData(const std::string& filename);
        void setProvince(const string& province);
        void sortByAnimalName();
        void sortByNumberOfFarms();
        void sortByNumberOfAnimals();
        void printAllData();
        void printCurrentData();

    private:
        std::vector<Record> allData;
        std::vector<Record> currentData;
};

#endif