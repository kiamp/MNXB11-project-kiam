#pragma once

#include <TObject.h>  // root classes inherit from TObject
#include <vector>
#include <string>

class temp_given_day : public TObject {
public:
    temp_given_day(); //basic constructor
    temp_given_day(const std::string &filename); //constructor
    virtual ~temp_given_day() {} //destructor

    void ReadFile(); //function to extract data from lund_cleaned.txt
    void GetAverageTemp_1(); //computes average if multiple measurments
    void GetAverageTemp_2(); //computes average if multiple measurments
    void CreateHistogram(); //creates, plots and saves a histogram 

    std::vector<double> temperatures_1; //temperatures in first period
    std::vector<int> years_1; //years from lund_cleaned.txt in first period
    std::vector<double> temperatures_2; //temperatures in second period
    std::vector<int> years_2; //years from lund_cleaned.txt  in second period
    std::vector<double> avg_temp_1; //computed yearly avarages
    std::vector<double> avg_temp_2;
    std::vector<int> unique_years_1; //each year only once 
    std::vector<int> unique_years_2;
    

private:
    std::string inputFilename;
};