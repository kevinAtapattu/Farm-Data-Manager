#include "FarmData.h"

//ctr
FarmData::FarmData() {}

//dtr
FarmData::~FarmData() {}

// methods
void FarmData::loadData(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string year, region, animalName, farmsStr, animalsStr;
        int numFarms, numAnimals;

        std::getline(ss, year, '\t');
        std::getline(ss, region, '\t');
        std::getline(ss, animalName, '\t');
        std::getline(ss, farmsStr, '\t');
        std::getline(ss, animalsStr);

        numFarms = std::stoi(farmsStr);
        numAnimals = std::stoi(animalsStr);

        allData.emplace_back(year, region, animalName, numFarms, numAnimals);
    }
}

void FarmData::setProvince(const std::string& province) {
    currentData.clear();
    std::copy_if(allData.begin(), allData.end(), std::back_inserter(currentData),
                 [&province](const Record& rec) {
                     return rec.region == province;
                 });
}

void FarmData::sortByAnimalName() {
    std::sort(currentData.begin(), currentData.end(),
              [](const Record& a, const Record& b) {
                  return a.animalName < b.animalName;
              });
}

void FarmData::sortByNumberOfFarms() {
    std::sort(currentData.begin(), currentData.end(),
              [](const Record& a, const Record& b) {
                  return a.numFarms > b.numFarms;
              });
}

void FarmData::sortByNumberOfAnimals() {
    std::sort(currentData.begin(), currentData.end(),
              [](const Record& a, const Record& b) {
                  return a.numAnimals > b.numAnimals;
              });
}

void FarmData::printAllData() {
    for (const auto& rec : allData) {
        std::cout << rec.year << "\t" << rec.region << "\t"
                  << rec.animalName << "\t" << rec.numFarms << "\t" << rec.numAnimals << std::endl;
    }
}

void FarmData::printCurrentData() {
    for (const auto& rec : currentData) {
        std::cout << rec.year << "\t" << rec.region << "\t"
                  << rec.animalName << "\t" << rec.numFarms << "\t" << rec.numAnimals << std::endl;
    }
}