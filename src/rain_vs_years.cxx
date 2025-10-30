#include "rain_vs_years.h"

RainVsYears::RainVsYears() {}
RainVsYears::RainVsYears(const std::string &fileName) : dataFile(fileName) {}

          void RainVsYears::ReadAndDraw() {
  std::ifstream file(dataFile);
  std::string line;          // will hold the line that is read
  std::getline(file, line);  // reads and ignores first line(column describer)

  std::map<int, std::pair<double, int>>
      yearly_data;  // map. key= int year, pair= double yearly rainfall sum and
                    // int entries(days)

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    double rainfall;

    if (!(ss >> date >> rainfall)) //read file, assign value to date and rainfall
      continue;  // if line can't be extracted, continue still

    int year =
        std::stoi(date.substr(0, 4));  // extract the year, convet to integer

    if (year > 2022)
      break;  // only doing until 2022 to match the temperature dataset

    yearly_data[year].first += rainfall;  // sum up the total yearly rainfall
    yearly_data[year].second++;           // count the number of entries(days)
  }

  file.close();

  int nYears = yearly_data.size();  // count keys in map
  std::vector<double> years, avgRains;
  years.reserve(nYears);  // vector must have space to contain n years
  avgRains.reserve(nYears);

  for (const auto& [year, value] :
       yearly_data) {  // unpacks the value pair into two variables. ChatGPT
                       // helped with formulating
    double avg = value.first / value.second;  // calculate average rainfall
    years.push_back(year);
    avgRains.push_back(avg);
  }

  firstYear = years.front();
  lastYear = years.back();

  // DRAWING HISTOGRAM

  TH1D* hist =
      new TH1D("hist", "Average rain each year;Year;Avg daily rainfall(mm)",
               nYears, firstYear, lastYear + 1);

  for (int i = 0; i < nYears; i++) {
    hist->Fill(years[i], avgRains[i]);
  }

  hist->SetLineColor(38);

  TCanvas* c1 = new TCanvas("c1", "Average rainfall", 800, 600);
  hist->Draw("HIST c");
  c1->SaveAs("rain_vs_years.pdf");
}
