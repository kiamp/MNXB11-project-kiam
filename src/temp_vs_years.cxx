#include "../include/temp_vs_years.h"
#include <iostream>
#include <fstream> //for reading the file
#include <numeric>
#include <vector>
#include <cmath>

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
    std::ifstream file(inputFilename); //! needs to be changed if position of lund_cleaned.txt is moved 
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
    
    std::vector<double> temps_year; //for standard deviation

    for (size_t i=0; i < years.size(); i++) {
        if (years[i] == current_year) { //sums all temperatures from one year 
            sum += temperatures[i];
            temps_year.push_back(temperatures[i]);
            count++; //count the amount of entries from that year
        } else {
            double mean = sum/count;
            yearly_averages.push_back(mean); //adds mean to yearly_averages
            unique_years.push_back(current_year);

            //standard deviation
            double st_sum = 0.0;
            for (double t : temps_year) {
                st_sum += (t - mean)*(t - mean);
            }
            double variance = st_sum/count;
            st_dev.push_back(std::sqrt(variance));

            current_year = years[i]; //goes to next year
            count = 1; //count set back to 1 (not 0 because we are already in the loop)
            sum = temperatures[i]; //adds first temperature in new year to sum
            temps_year.clear();
            temps_year.push_back(temperatures[i]);
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

    TH1D *histogram = new TH1D("histogram", "Average yearly temperature over the years;Year; Average Temperature [#circC]", nbins, min_year -0.5, max_year+0.5);

    for (size_t i =0 ; i< unique_years.size(); ++i) {
        histogram->SetBinContent(i+1, yearly_averages[i]); //fill bins with values, bin count starts at 1
        histogram->SetBinError(i+1, st_dev[i]);
    }
    
    //linear fit
    TF1* lin_fit = new TF1("lin_fit", "pol1", min_year +0.5, max_year +0.5); 
    histogram->Fit(lin_fit, "R"); // R=used specified range of histogram for fitting
    
    double slope = lin_fit->GetParameter(1); //gets slope of linear fit
    

    auto c1 = new TCanvas("c1","",800,600);
    //c1->SetTopMargin(0.15);
    histogram->SetTitle("Average yearly temperature from 1780-2022;Year;Average Temperature [#circC]");
    histogram->Draw(); 
    lin_fit->Draw("same");

    /*
    TLatex title; //for printing on canvas
    title.SetNDC(); //normalized coordinates (0-1) starts in lower left corner
    title.SetTextSize(0.05);
    title.DrawLatex(0.21, 0.92, "Average yearly temperature from 1780 - 2022.");
    */
    TLatex text; 
    text.SetNDC(); 
    text.SetTextSize(0.05);
    text.DrawLatex(0.2, 0.2, Form("slope: %.4f #circC/Year", slope));


    c1->SaveAs("temperature_vs_years_stdev.pdf");
}


