#pragma once //everything will be created only once
#include <TObject.h> //neccesary for root classes
#include <vector>
#include <string>

class rain_given_day: public TObject{
public:
    rain_given_day(); //basic constructor
    rain_given_day(const std::string &filename); //constructor;
    virtual ~rain_given_day() {}; //destructor

    void ReadFile(); //function to extract important data from lund_cleaned_rain.txt
    void CreateHistogram(); //creates, plots and saves a histogram 

    std::vector<double> rain_1; //rain in first period (1863-1913)
    std::vector<int> years_1; //years from lund_cleaned_rain.txt in first period
    std::vector<double> rain_2; //rain in second period (1972-2022)
    std::vector<int> years_2; //years from lund_cleaned_rain.txt  in second period
private:
    std::string inputFilename;
};
