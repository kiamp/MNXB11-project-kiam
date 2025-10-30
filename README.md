# MNXB11-project-template
# About
This project creates 9 pdf files including graphs that showcase weather data from Lund. 
There are two graphs on the average temperature each year from 1780 till 2022, one with and one without the std included. 
There is one graph on the average rainfall each year from 1863 till 2022. 
There are three graphs on the average temperature on 15/02 every year from 1863 till 2022. 
And lastly there are three graphs on teh rainfall on 15/02 every year from 1863 till 2022. 

# Directory structure

In the `include/` folder, there are four files that initiate four classes, and include the necessary guards. 
In the `src/` folder, there are four files that define the functions initiated in the classes. Every file includes a function that creates a graph.
Then in the base, there is a main.cxx file which calls all the functions creating graphs at once, so by running main all pdf's are created. 

We kept the three special files in the base of the repository that were in the template: [.gitignore](.gitignore), [.clang-format](.clang-format), [rootlogon.C](rootlogon.C)
 
# Building the project

To create the files, one needs to be in the MNXB11 Apptainer, and then one needs to run in the terminal (not in ROOT!):
```bash
make clean
make
./main
```

## Adding external software libraries

This project uses C++ 17 and ROOT for data analysis and plotting. 

Dependencies:
- g++ (at least 9.0)
- ROOT (at least 6.26)
- Make

