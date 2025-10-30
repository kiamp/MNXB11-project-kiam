# Workplan for MNXB11 project

Team number: 2  

Team members:   
Dominique de Boer  
Marie-Philine Lieselotte Hebel  
Kiam Persson  
Ivana Varsányiová

# Plan
### Data Preparation and extraction using python: Marie-Philine, Ivana
On Lund temperature and Lund rain dataset 

### Data analysis and figure creation:  
- Average temperature of the year, in Lund, for every year: Marie-Philine
- The temperature of a given day (average of first 50 years and last 50 years) in Lund : Dominique
- Average amount of rain on a given day from first 50 years and last 50 years, in Lund : Ivana
- Average amount of rain of the year, in Lund, over multiple years : Kiam

### Average temperature per year from 1780 till 2022 (Marie-Philine)

The goal is to look at possible average temperature changes over time. The general trend will then be studied by fitting the data.
A class temp_vs_years will be created and equipped with different functions. One function will read the cleaned data (ReadFile), another will compute the yearly average (GetYearlyAverage) and a third will create the histogram (CreateHistogram). This function will also create a fit by employing the ROOT class TF1. 
To compute the yearly average we will iterate through each entry. All the temperatures for one year will be summed and divided by their number count to find yearly average. 
A standard deviation will also be included which gives a measure for the spread of the values in each year. If the temperature differences in one year changed over the years, this might be visible in the standard deviation. 
