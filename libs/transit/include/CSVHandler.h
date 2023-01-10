#ifndef LIBS_TRANSIT_INCLUDE_CSVHANDLER_H_
#define LIBS_TRANSIT_INCLUDE_CSVHANDLER_H_

#include <string>
#include <fstream>
#include "util/json.h"
/**
 * @brief Singleton csv class that handles csv output of data
 */
class CSVHandler {
 public:
        static CSVHandler* GetInstance();
        /**
         * @brief Writes data from a finished trip to the csv
         * 
         * @param obj information about the csv
         * @param endTime
         * @param strategyName
         * @param distanceTraveled
         */
        void writeData(const JsonObject& obj, double endTime,
            std::string strategyName, float distanceTraveled);
 private:
        CSVHandler();
        static CSVHandler* instance;
        std::string fileName;
};

#endif  //  LIBS_TRANSIT_INCLUDE_CSVHANDLER_H_
