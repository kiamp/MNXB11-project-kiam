#pragma once

#include <TObject.h>  // root classes inherit from TObject
#include <vector>
#include <string>

class temp_vs_years : public TObject {
public:
    temp_vs_years(); //basic constructor
    temp_vs_years(const std::string &filename); //constructor
    virtual ~temp_vs_years() {} //destructor

    void ReadFile(); //function to extract important data from lund_cleaned.txt
    void GetYearlyAverage(); //computes yearly average temperature
    void CreateHistogram(); //creates, plots and saves a histogram 

    std::vector<double> temperatures; //all temperatures
    std::vector<int> years; //all years in lund_cleaned.txt 
    std::vector<double> yearly_averages; //computed yearly avarages
    std::vector<int> unique_years; //each year only once 
    std::vector<double> st_dev;
    
    
    double slope = 0.0; //initializing slope of linear fit

private:
    std::string inputFilename;
};