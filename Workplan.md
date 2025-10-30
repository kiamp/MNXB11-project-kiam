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

### Average temperature and rainfall on February 15th from 1863 till 1913 and 1972 till 2022 (Dominique and Ivana)
We wish to find out the temperature and rain of a given day, set at February 15th, for two different periods, in order to see the possible effects of climate change on the mean temperature and mean rainfall on this day.
The first period will be 1863 till 1913 and the second one 1973 till 2023, because these periods have data available in the datasets for both temperature and rainfall.
We need to create two lists containing the data on 15/02 for these two periods separately. This can be done by using an if statement while iterating to find 15/02 and another if statement to ensure that the years are those from the chosen period, using && to ensure that they’re all true at the same time. Then we will use the push_back function to add them to the vectors that will be initialized in the header file.
In the case of the temperature data, there are occasionally multiple measurements on the same date, but at different times. On those occurrences, we will take the average temperature of the day. This is done by iterating through the two created lists, and if we find that one year occurs more often, we gather the temperatures, compute the average and replace them in the list.
Then we want to create histograms of the two (averaged) lists, and a third one with both periods in it. This can be done with TH1D and creating three canvasses.


### Average rainfall per year from 1963 till 2022 (Kiam)
The goal is to examine the amount of rainfall from different years in Lund. We want to see if the amount of rain each year has increased or decreased by fitting a linear function. We also want to see if there is a relationship between a year’s average temperature and rainfall.  
  
A struct will be created with a member-function that will read a datafile containing the date and its rainfall, and with the data draw a histogram using ROOT. The histogram will have an X-axis with the years 1863-2022. The Y-axis will show the daily average rainfall for each year.  
  
We will create a std::map where the key is the year, and the value is a std:.pair containing the sum of the rainfall that year, and the number of days that have been added to each year’s rainfall. With those numbers, we do sum/entries, (or year’s total rainfall/days) to get each year’s average daily rainfall. We will then fill a histogram and draw it using ROOT’s TH1D class and its functions. Using ROOT we will also do a linear fit to the histogram using TF1, and calculate the slope.  
