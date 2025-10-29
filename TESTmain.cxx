#include "rain_vs_years.h"
int main() {
    RainVsYears r_vs_y("./datasets/lund_cleaned_rain.txt")
    r_vs_y.ReadAndDraw();

    return 0;
}