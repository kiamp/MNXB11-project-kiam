#comments marked with !, something needs to be done.
#! before running: type "python -m pip install pandas" in the terminal
import pandas as pd
from io import StringIO

#! this path needs to be changed if someone else runs the code
with open("/home/marheb/git/MNXB11-project/datasets/smhi-opendata_1_53430_20231007_155558_Lund.csv", encoding="utf-8") as data_file:
    all_lines = data_file.readlines()

start_index = 12 #! change depending on ducument. Where the important data starts. 
#note that index is one less than line index. 
data_lines = all_lines[start_index:]
#converting list to string for pandas:
data_string = "".join(data_lines)
#converts it such that pandas can be used for cleanup
panda_frame = pd.read_csv(StringIO(data_string), sep=";")

cleaned_data = panda_frame[["Datum", "Tid (UTC)", "Lufttemperatur"]].copy()
cleaned_data.columns = ["date", "time", "degrees"] #rename
cleaned_data["degrees"] = pd.to_numeric(cleaned_data["degrees"], errors="coerce") #change to numeric values
cleaned_data = cleaned_data.dropna() #drops empty rows

output_path = "/home/marheb/git/MNXB11-project/datasets/lund_cleaned.txt"
cleaned_data.to_csv(output_path, sep=" ", index=False)


