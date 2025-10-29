#pragma once
#include <TObject.h>
#include <fstream>
#include <TH1.h>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <TCanvas.h>
#include <TAttLine.h>

struct RainVsYears : public TObject {
    RainVsYears();
    RainVsYears(const std::string &fileName);
    ~RainVsYears(){}

    void ReadAndDraw();

    std::string date;
    double rainfall;
    
    int firstYear;
    int lastYear;

    private:
        std::string dataFile;
};