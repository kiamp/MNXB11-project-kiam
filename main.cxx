
#include <iostream>
#include "/home/deboer/git/MNXB11-project/include/temp_vs_years.h"
#include "/home/deboer/git/MNXB11-project/include/temp_given_day.h"

// int main() {

//   temp_vs_years t_vs_y("/home/deboer/git/MNXB11-project/datasets/lund_cleaned.txt");
//   t_vs_y.ReadFile();
//   t_vs_y.GetYearlyAverage();
//   t_vs_y.CreateHistogram();
//   return 0;
// }

int main() {

  temp_given_day t_vs_e("/home/deboer/git/MNXB11-project/datasets/lund_cleaned.txt");
  t_vs_e.ReadFile();
  t_vs_e.GetAverageTemp_1();
  t_vs_e.CreateHistogram();

  return 0;
}
