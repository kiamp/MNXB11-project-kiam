
#include <iostream>
#include "./include/temp_vs_years.h"
#include "./include/temp_given_day.h"
#include "./include/rain_vs_years.h"
#include "./include/rain_given_day.h"

/*
int main() {
   temp_vs_years t_vs_y("./datasets/lund_cleaned.txt");
   t_vs_y.ReadFile();
   t_vs_y.GetYearlyAverage();
   t_vs_y.CreateHistogram();
   return 0;
 }

int main() {

  temp_given_day t_vs_e("./datasets/lund_cleaned.txt");
  t_vs_e.ReadFile();
  t_vs_e.GetAverageTemp_1();
  t_vs_e.GetAverageTemp_2();
  t_vs_e.CreateHistogram();

  return 0;
}*/

int main() {
    RainVsYears r_vs_y("./datasets/lund_cleaned_rain.txt");
    r_vs_y.ReadAndDraw();
    return 0;
}

/*int main() {

  rain_given_day r_vs_e("./datasets/lund_cleaned_rain.txt");
  r_vs_e.ReadFile();
  r_vs_e.CreateHistogram();

  return 0;
}*/