
#include <iostream>
#include "/home/marheb/git/MNXB11-project/include/temp_vs_years.h"

int main() {

  temp_vs_years t_vs_y("/home/marheb/git/MNXB11-project/datasets/lund_cleaned.txt");
  t_vs_y.ReadFile();
  t_vs_y.GetYearlyAverage();
  t_vs_y.CreateHistogram();
  return 0;
}
