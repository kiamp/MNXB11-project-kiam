#include <iostream>
#include <fstream> //for reading the file
#include <numeric>

void temp_given_day::ReadFile() {
    std::ifstream file("/home/marheb/git/MNXB11-project/datasets/lund_cleaned.txt"); //! needs to be changed if position of lund_cleaned.txt is moved 
    std::string date, time; //initialize variables
    double degrees;

    std::string header; //gets first line 
    std::getline(file, header); //skips first line

    while (file >> date >> time >> degrees) { //iterates through file 
        int year = std::stoi(date.substr(0, 4)); //extracts the year from date 
        int month = std::stoi(date.substr(0, 4)); //extracts the month from date 
        int day = std::stoi(date.substr(0, 4)); //extracts the day from date 
        std::cout << year, month, day;
    }
} 