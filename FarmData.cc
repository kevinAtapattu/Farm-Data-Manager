#include "FarmData.h"

//ctr
FarmData::FarmData() {
    ifstream file("farmdata/farmdata.txt");
    if (!file) {
        cerr << "Error opening farm data file." << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string region, animalName;
        int numFarms, numAnimals;
        getline(ss, region, '\t');
        getline(ss, animalName, '\t');
        ss >> numFarms >> numAnimals;
        allData.emplace_back(make_tuple(region, animalName, numFarms, numAnimals));
    }
}

//dtr
FarmData::~FarmData() {}

// methods
void FarmData::setProvince(const string& province) {
    currentData.clear();
    copy_if(allData.begin(), allData.end(), back_inserter(currentData),[&province](const auto& record) {
                return get<0>(record) == province;
            });
}

void FarmData::sortByAnimalName() {
    sort(currentData.begin(), currentData.end(), [](const auto& a, const auto& b) {
        return get<1>(a) < get<1>(b);
    });
}

void FarmData::sortByNumberOfFarms() {
    sort(currentData.begin(), currentData.end(), [](const auto& a, const auto& b) {
        return get<2>(a) > get<2>(b);
    });
}

void FarmData::sortByNumberOfAnimals() {
    sort(currentData.begin(), currentData.end(), [](const auto& a, const auto& b) {
        return get<3>(a) > get<3>(b);
    });
}

void FarmData::printAllData() {
    for (const auto& record : allData) {
        cout << get<0>(record) << "\t" << get<1>(record) << "\t"
             << get<2>(record) << "\t" << get<3>(record) << endl;
    }
}

void FarmData::printCurrentData() {
    for (const auto& record : currentData) {
        cout << get<0>(record) << "\t" << get<1>(record) << "\t"
             << get<2>(record) << "\t" << get<3>(record) << endl;
    }
}