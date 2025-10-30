
#include <iostream>
#include "./include/temp_vs_years.h"
#include "./include/temp_given_day.h"
#include "./include/rain_vs_years.h"
#include "./include/rain_given_day.h"


int main() {
  //average yearly temperature vs years_____________________________
  temp_vs_years t_vs_y("./datasets/lund_cleaned.txt");
  t_vs_y.ReadFile();
  t_vs_y.GetYearlyAverage();
  t_vs_y.CreateHistogram();

  //rain on a given day over the years
  rain_given_day r_vs_e("./datasets/lund_cleaned_rain.txt");
  r_vs_e.ReadFile();
  r_vs_e.CreateHistogram();
  return 0;

  //temperature on a given day over the years.
  temp_given_day t_vs_e("./datasets/lund_cleaned.txt");
  t_vs_e.ReadFile();
  t_vs_e.GetAverageTemp_1();
  t_vs_e.GetAverageTemp_2();
  t_vs_e.CreateHistogram();

  //average yearly rainfall vs years
  RainVsYears r_vs_y("./datasets/lund_cleaned_rain.txt");
  r_vs_y.ReadAndDraw();
    
  
 }



