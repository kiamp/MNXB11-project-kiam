#include "../include/rain_given_day.h"
#include <iostream>
#include <fstream> //for reading the file
#include <numeric>

//for ROOT 
#include "TCanvas.h"
#include "TH1D.h"
#include "TF1.h"
#include "TLatex.h"

// default constructor - ROOT needs the default one where everything is set to 0
rain_given_day::rain_given_day() {}
//constructor
rain_given_day::rain_given_day(const std::string &filename) : inputFilename(filename) {} //this one is used in main

//just going through the file and appending years_1, rain_1, years_2, rain_2 if we are in the selected 50 year period and the date is 15.2
void rain_given_day::ReadFile() {
    std::ifstream file("../datasets/lund_cleaned_rain.txt"); //! needs to be changed if position of lund_cleaned.txt is moved 
    std::string date; //initialize variables
    double rain;

    std::string header; //gets first line 
    std::getline(file, header); //skips first line

    while (file >> date >> rain) { //iterates through file 
        int year = std::stoi(date.substr(0, 4)); //extracts the year from date 
        int month = std::stoi(date.substr(5, 2)); //extracts the month from date 
        int day = std::stoi(date.substr(8, 2)); //extracts the day from date 
        
        if ((month == 2) && (day == 15)) { //checking for our specific day
            if (year >= 1863 && year <= 1913) {
                years_1.push_back(year);
                rain_1.push_back(rain);
            } else if (year >= 1972 && year <= 2022) {
                years_2.push_back(year);
                rain_2.push_back(rain);
            }
        }

    }

    file.close();
};

void rain_given_day::CreateHistogram() {
    std::cout << "Period 1: " << rain_1.size() << " entries" << std::endl;
    std::cout << "Period 2: " << rain_2.size() << " entries" << std::endl;
    // first period
    auto *histogram_1 = new TH1D("histogram1", "Rainfall on 15/02 from 1863-1913 ;Rainfall [#circC];Entries", 50, -15, 15);
    histogram_1->SetFillColor(kBlue +1); //colour of bars is blue
    histogram_1->SetLineColor(kBlack); //outline black
    for (size_t i =0 ; i< years_1.size(); ++i) {
        histogram_1->Fill(rain_1[i]);
    }

    auto canvas1 = new TCanvas("canvas1","",800,600);
    histogram_1->Draw();

    TLatex text; //for printing on canvas
    text.SetNDC(); //normalized coordinates (0-1) starts in lower left corner
    text.SetTextSize(0.05);

    canvas1->SaveAs("rainfall_given_day_1.pdf");

    // repeat for second period
    auto *histogram_2 = new TH1D("histogram2", "Rainfall on 15/02 from 1972-2022 ;Rainfall [#circC];Entries", 50, -15, 15);
    histogram_2->SetFillColor(kBlue +1); //colour of bars is blue
    histogram_2->SetLineColor(kBlack); //outline black
    for (size_t j =0 ; j< years_2.size(); ++j) {
        histogram_2->Fill(rain_2[j]);
    }

    auto canvas2 = new TCanvas("canvas2","",800,600);
    histogram_2->Draw();

    TLatex text2; //for printing on canvas
    text2.SetNDC(); //normalized coordinates (0-1) starts in lower left corner
    text2.SetTextSize(0.05);

    canvas2->SaveAs("rainfall_given_day_2.pdf");
};