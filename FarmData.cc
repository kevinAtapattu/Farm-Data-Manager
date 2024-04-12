#include "FarmData.h"

//ctr
FarmData::FarmData() {
    ifstream file("farmdata/farmdata.txt");
    if (!file) {
        cerr << "Error opening farm data file." << endl;
        return;  // Exit if file not opened successfully
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;  // Skip any empty lines

        istringstream ss(line);
        string year, region, animalName;
        int numFarms, numAnimals;
        
        getline(ss, year, '\t');
        getline(ss, region, '\t');
        getline(ss, animalName, '\t');
        ss >> numFarms >> numAnimals;

        // Check for reading errors or corrupted data
        if (ss.fail()) {
            cerr << "Failed to parse line: " << line << endl;
            continue;  // Skip corrupted lines
        }

        allData.emplace_back(year, region, animalName, numFarms, numAnimals);
        cout << "Loaded: " << year << " " << region << " " << animalName << " " << numFarms << " " << numAnimals << endl;
    }
}

//dtr
FarmData::~FarmData() {}

// methods
void FarmData::loadData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    } else {
        std::cout << "File opened successfully." << std::endl;
    }
    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        count++;
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
        std::cout << "Loaded record #" << count << ": " << year << ", " << region << ", " << animalName << ", " << numFarms << ", " << numAnimals << std::endl;
    }
    std::cout << "Total records loaded: " << allData.size() << std::endl;
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
    std::cout << "Attempting to print data..." << std::endl;
    for (const auto& rec : allData) {
        std::cout << rec.year << "\t" << rec.region << "\t"
                  << rec.animalName << "\t" << rec.numFarms << "\t" << rec.numAnimals << std::endl;
    }
}

void FarmData::printCurrentData() {
    std::cout << "Attempting to print data..." << std::endl;
    for (const auto& rec : currentData) {
        std::cout << rec.year << "\t" << rec.region << "\t"
                  << rec.animalName << "\t" << rec.numFarms << "\t" << rec.numAnimals << std::endl;
    }
}