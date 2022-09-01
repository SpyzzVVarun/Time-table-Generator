<h1 align = "center">Time Table Generator Project</h1>

3rd Sem DSA course welcome project.

<b>Problem:</b> Everyone in the class is to design a TIME TABLE generator for "N" theory courses, "L" Lab Classes for the UG (all four years) and PG+PhD (first year only) students. Here "L < N". There are "P" faculty members, where "P = N/2".

<b>Rules for developing the TIME TABLE Generator:</b>
* Every lecture is of ONE hour.
* Lectures begin at 8.00AM and ends at 6.00PM from Monday to Friday.
* 12.00PM to 2.00PM is the lunch time.
* Each Lecture has 3 days per week and each Lab has 3 hours per week
* Each lecture can happen only once a day
* There can be 2 labs in a day

<h2 align = "center">Time Table Generator Project Input File details</h2>

<b>There are 2 input files:</b> 
1. num_inputs.txt
2. courses.txt

<b>num_inputs.txt has (space separated):</b>
1. Number of Theory courses
2. Number of Lab Courses

<b>courses.txt has (space separated):</b>
1. Course Code
2. Year of Study (1,2,3,4 for BTech. 5 for PG+PhD)
3. prof code (integer starting from 1 till n/2)
4. is lab or not(0 for lecture and 1 for lab)

<b>DISCLAIMER:</b> 
Code only tested in vscode. MakeFile not tested, if it doesnt work, code can be run using the usual:<br>
&#62;&#62; g++ main.cpp<br>
&#62;&#62; ./a.exe
