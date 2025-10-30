#include "../include/temp_given_day.h"
#include <iostream>
#include <fstream> //for reading the file
#include <numeric>

//for ROOT 
#include "TCanvas.h"
#include "TH1D.h"
#include "TF1.h"
#include "TLatex.h"
#include "TStyle.h"
#include "TLegend.h"


// default constructor - ROOT needs the default one where everything is set to 0
temp_given_day::temp_given_day() {}
//constructor
temp_given_day::temp_given_day(const std::string &filename) : inputFilename(filename) {} //this one is used in main


void temp_given_day::ReadFile() {
    std::ifstream file(inputFilename); //! needs to be changed if position of lund_cleaned.txt is moved 
    std::string date, time; //initialize variables
    double degrees;

    std::string header; //gets first line 
    std::getline(file, header); //skips first line

    while (file >> date >> time >> degrees) { //iterates through file 
        int year = std::stoi(date.substr(0, 4)); //extracts the year from date 
        int month = std::stoi(date.substr(5, 2)); //extracts the month from date 
        int day = std::stoi(date.substr(8, 2)); //extracts the day from date 
        
        if ((month == 2) && (day == 15)) {
            if (year >= 1863 && year <= 1913) {
                years_1.push_back(year);
                temperatures_1.push_back(degrees);
            } else if (year >= 1972 && year <= 2022) {
                years_2.push_back(year);
                temperatures_2.push_back(degrees);
            }
        }
    }
    file.close();
}

void temp_given_day::GetAverageTemp_1() {
    unique_years_1.clear(); //so that nothing from earlier is included 
    avg_temp_1.clear();
    
    double sum = 0.0; //initialize sum and count
    int count = 0;

    int first_year = 1863;

    for (size_t i=0; i < years_1.size(); i++) {
        if (years_1[i] == first_year) { //sums all temperatures from one year
            sum += temperatures_1[i];
            count++; //count the amount of entries from that year
        } 
        else {
            avg_temp_1.push_back(sum/count); //adds mean to avg_years_1
            unique_years_1.push_back(first_year);

            first_year = years_1[i]; //goes to next year
            count = 1; //count set back to 1 (not 0 because we are already in the loop)
            sum = temperatures_1[i]; //adds first temperature in new year to sum
        }
    }
    //last year needs to be added manually
    avg_temp_1.push_back(sum/count);
    unique_years_1.push_back(first_year);
}

void temp_given_day::GetAverageTemp_2() {
    
    unique_years_2.clear(); //so that nothing from earlier is included 
    avg_temp_2.clear();
    
    double sum = 0.0; //initialize sum and count
    int count = 0;

    int first_year = 1972;

    for (size_t i=0; i < years_2.size(); i++) {
        if (years_2[i] == first_year) { //sums all temperatures from one year
            sum += temperatures_2[i];
            count++; //count the amount of entries from that year
        } 
        else {
            avg_temp_2.push_back(sum/count); //adds mean to avg_years_1
            unique_years_2.push_back(first_year);

            first_year = years_2[i]; //goes to next year
            count = 1; //count set back to 1 (not 0 because we are already in the loop)
            sum = temperatures_2[i]; //adds first temperature in new year to sum
        }
    }
    //last year needs to be added manually
    avg_temp_2.push_back(sum/count);
    unique_years_2.push_back(first_year);
}

void temp_given_day::CreateHistogram() {
    std::cout << "Period 1: " << avg_temp_1.size() << " entries" << std::endl;
    std::cout << "Period 2: " << avg_temp_2.size() << " entries" << std::endl;
    // first period
    auto *histogram_1 = new TH1D("histogram1", "Temperature on 15/02 from 1863-1913 ;Temperature [#circC];Entries", 50, -15, 15);
    histogram_1->SetFillColorAlpha(kBlue +1, 0.4); //colour of bars is blue
     histogram_1->SetLineColor(kBlack); //outline black
    for (size_t i =0 ; i< unique_years_1.size(); ++i) {
        histogram_1->Fill(avg_temp_1[i]);
    }

    auto canvas1 = new TCanvas("canvas1","",800,600);
    histogram_1->Draw();

    TLatex text; //for printing on canvas
    text.SetNDC(); //normalized coordinates (0-1) starts in lower left corner
    text.SetTextSize(0.05);

    canvas1->SaveAs("temperature_given_day_1.pdf");

    // repeat for second period
    auto *histogram_2 = new TH1D("histogram2", "Temperature on 15/02 from 1972-2022 ;Temperature [#circC];Entries", 50, -15, 15);
    histogram_2->SetFillColorAlpha(kRed +1, 0.4); //colour of bars is blue
     histogram_2->SetLineColor(kBlack); //outline black
    for (size_t j =0 ; j< unique_years_2.size(); ++j) {
        histogram_2->Fill(avg_temp_2[j]);
    }

    auto canvas2 = new TCanvas("canvas2","",800,600);
    histogram_2->Draw();

    TLatex text2; //for printing on canvas
    text2.SetNDC(); //normalized coordinates (0-1) starts in lower left corner
    text2.SetTextSize(0.05);

    canvas2->SaveAs("temperature_given_day_2.pdf");

    // combined histogram
    gStyle->SetOptStat(0); // prevent new stats boxes
    auto canvas3 = new TCanvas("canvas3","", 800, 600);

    histogram_1->Draw();
    histogram_2->Draw("SAME");
    
    histogram_1->SetTitle(""); 
    histogram_2->SetTitle(""); //getting rid of the previous titles
    

    auto legend = new TLegend(0.65, 0.75, 0.9, 0.9);
    legend->AddEntry(histogram_1, "1863-1913", "f");
    legend->AddEntry(histogram_2, "1972-2022", "f");
    legend->Draw();

    TLatex text3; //for printing on canvas
    text3.SetNDC(); //normalized coordinates (0-1) starts in lower left corner
    text3.SetTextSize(0.05);
    text3.DrawLatex(0.15, 0.92, "Temperature on 15th of February");

    canvas3->SaveAs("combined_temperature_given_day.pdf");
}