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

### Average rainfall per year from 1963 till 2022 (Kiam)
The goal is to examine the amount of rainfall from different years in Lund. We want to see if the amount of rain each year has increased or decreased by fitting a linear function. We also want to see if there is a relationship between a year’s average temperature and rainfall.  
  
A struct will be created with a member-function that will read a datafile containing the date and its rainfall, and with the data draw a histogram using ROOT. The histogram will have an X-axis with the years 1863-2022. The Y-axis will show the daily average rainfall for each year.  
  
We will create a std::map where the key is the year, and the value is a std:.pair containing the sum of the rainfall that year, and the number of days that have been added to each year’s rainfall. With those numbers, we do sum/entries, (or year’s total rainfall/days) to get each year’s average daily rainfall. We will then fill a histogram and draw it using ROOT’s TH1D class and its functions. Using ROOT we will also do a linear fit to the histogram using TF1, and calculate the slope.  
