#include "/home/marheb/git/MNXB11-project/include/temp_vs_years.h"
#include <iostream>
#include <fstream> //for reading the file
#include <numeric>

//for ROOT 
#include "TCanvas.h"
#include "TH1D.h"
#include "TF1.h"
#include "TLatex.h"


// default constructor - ROOT needs the default one where everything is set to 0
temp_vs_years::temp_vs_years() {}
//constructor
temp_vs_years::temp_vs_years(const std::string &filename) : inputFilename(filename) {} //this one is used in main


void temp_vs_years::ReadFile() {
    std::ifstream file("/home/marheb/git/MNXB11-project/datasets/lund_cleaned.txt"); //! needs to be changed if position of lund_cleaned.txt is moved 
    std::string date, time; //initialize variables
    double degrees;

    std::string header; //gets first line 
    std::getline(file, header); //skips first line

    while (file >> date >> time >> degrees) { //iterates through file 
        int year = std::stoi(date.substr(0, 4)); //extracts the year from date 

        if (year>2022) break; //2023 not full, so we only want values until end of 2022

        years.push_back(year);
        temperatures.push_back(degrees);

    }

    file.close();
}

void temp_vs_years::GetYearlyAverage() {
    unique_years.clear(); //so that nothing from earlier is included 
    yearly_averages.clear();


    int current_year = 1780; //first year in dataset
    
    double sum = 0.0; //initialize sum and count
    int count = 0;

    for (size_t i=0; i < years.size(); i++) {
        if (years[i] == current_year) { //sums all temperatures from one year
            sum += temperatures[i];
            count++; //count the amount of entries from that year
        } else {
            yearly_averages.push_back(sum/count); //adds mean to yearly_averages
            unique_years.push_back(current_year);

            current_year = years[i]; //goes to next year
            count = 1; //count set back to 1 (not 0 because we are already in the loop)
            sum = temperatures[i]; //adds first temperature in new year to sum
        }
    }
    //last year needs to be added manually
    yearly_averages.push_back(sum/count);
    unique_years.push_back(current_year);
}


void temp_vs_years::CreateHistogram() {
    int nbins = unique_years.size(); //number of bins
    int min_year = unique_years.front(); //first year (1780)
    int max_year = unique_years.back() ; //last year (2022)

    TH1D *histogram = new TH1D("histogram", "Average yearly temperature over the years;Year; Temperature [#circC]", nbins, min_year -0.5, max_year+0.5);

    for (size_t i =0 ; i< unique_years.size(); ++i) {
        histogram->SetBinContent(i+1, yearly_averages[i]); //fill bins with values
    }
    
    //linear fit
    TF1* lin_fit = new TF1("lin_fit", "pol1", min_year +0.5, max_year +0.5); 
    histogram->Fit(lin_fit, "R");
    
    double slope = lin_fit->GetParameter(1); //gets slope of linear fit
    

    auto c1 = new TCanvas("c1","",800,600);
    histogram->Draw();
    lin_fit->Draw("same");

    TLatex text; //for printing on canvas
    text.SetNDC(); //normalized coordinates (0-1) starts in lower left corner
    text.SetTextSize(0.05);
    text.DrawLatex(0.2, 0.2, Form("slope: %.4f #circC/Year", slope));


    c1->SaveAs("temperature_vs_years.pdf");
}


