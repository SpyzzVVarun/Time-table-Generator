                                ** Time Table Generator Project Input File details **

There are 2 input files: 
1. num_inputs.txt
2. courses.txt

num_inputs.txt has (spacee separated):
1. Number of Theory courses
2. Number of Lab Courses

courses.txt has (space separated):
1. Course Code
2. Year of Study (1,2,3,4 for BTech. 5,6 for Mtech 1st year and 2nd year. 7 for PHD)
3. prof code (integer starting from 1 till n/2)
4. is lab or not(0 for lecture and 1 for lab)

* Each Lecture has 3 days per week and each Lab has 3 hours per week
* Each lecture can happen only once a day
* There can be 2 labs in a day

DISCLAIMER: 
Code only tested in vscode. MakeFile not tested, if it doesnt work, code can be run using the usual:
g++ main.cpp
./a.exe