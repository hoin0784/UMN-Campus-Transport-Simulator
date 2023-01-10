#include "CSVHandler.h"
#include <string>


CSVHandler::CSVHandler() { fileName = "csv_data/output.csv"; }

CSVHandler* CSVHandler::GetInstance() {
    if (instance == NULL) {
        instance = new CSVHandler();
    }
    return instance;
}

void CSVHandler::writeData(
    const JsonObject& obj, double endTime,
    std::string strategyName, float distanceTraveled) {

    std::ofstream file(fileName, std::ios::app);    // open file for append

    file <<  obj["name"] << ',' << strategyName << ','
    << int(obj["speed"]) << ',' << endTime  << ','
    << distanceTraveled <<std::endl;
}
