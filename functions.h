// Modules and Packages
#include "global.h"

// Struct to store schedule of students of different years as well as the different professors
struct week
{
    char schedule[40];
    string course_name[40];
};

// Struct to store the details of each course
struct course
{
    string course_name;
    int prof_name;
    int student_year;
    int index[3];
    int is_lab;
};

// Function Declaration
int getSlot(int is_lab, struct week * student,struct week * prof);
struct course get_course_from_file(ifstream *fp);
int check_index_alt(int a,int b);
void print_tt(int year,struct week * student);

// Assign slot to a course making sure there is no clash for any student or prof
int getSlot(int is_lab, struct week * student,struct week * prof)
{
    int index = (rand()%40)+1;
    if (is_lab==1)
    {
        if ((index == 0) || (index == 1) || (index == 4) || (index ==5) ||(index == 8) || (index == 9) || (index == 12) || (index ==13) ||(index == 16) || (index == 17) || (index == 20) || (index ==21) ||(index == 24) || (index == 25) || (index == 28) || (index ==29) ||(index == 32) || (index == 33) || (index == 36) || (index ==37) )
        {
            if ((student->schedule[index]=='f') && (student->schedule[index+1]=='f') && (student->schedule[index+2]=='f')
            && (prof->schedule[index]=='f') && (prof->schedule[index+1]=='f') && (prof->schedule[index+2]=='f'))
            {
                return index;
            }
            else
            {
                return getSlot(1,student,prof);
            }
        }
        else
        {
            return getSlot(1, student,prof);
        }
    }
    else if (is_lab ==0)
    {
        if ((student->schedule[index]=='f') && (prof->schedule[index]=='f'))
        {
            return index;
        }
        else
        {
            return getSlot(0,student,prof);
        }
    }
    return -1;
}

// Get all course details from the txt file
struct course get_course_from_file(ifstream * fp)
{
    struct course t;
    string course_name;
    int prof_name,student_year,index,is_lab;
    char ch;
    *fp >> course_name;
    *fp >> student_year;
    *fp >> prof_name;
    *fp >> is_lab;
    t.course_name = course_name;
    t.student_year = student_year;
    t.prof_name = prof_name;
    t.is_lab = is_lab;
    return t;
}

// Making sure that a lecture class is not repeated the same day
int check_index_alt(int a,int b)
{
    int upper = 7,lower = 0,flag=0;
    do
    {
        if ((a<=upper) && (a>=lower))
        {
            if ((b<=upper) && (b>=lower))
            {
                flag = 1;
                return 0;
            }
            else 
            {
                flag = 1;
                return 1;
            }
        }
        else
        {
            upper += 8;
            lower +=8;
        }
    } while ((flag!=1));
    return 1;
}

// Function to print the time table for a given year
void print_tt(int year,struct week * student)
{
    cout<<endl;
    int j,i;
    cout << "---------------------------------------------------------------";
    cout << endl;
    cout << "|                     Time Table";
    cout << " (";
    cout << year;
    if (year==2)
    {
        cout << "nd Year";
    }
    else if (year == 3)
    {
        cout << "rd Year";
    }
    else if ((year == 4) || (year ==5))
    {
        cout << "th Year";
    }
    cout << ")                    |";
    cout << endl;
    cout << "---------------------------------------------------------------";
    cout << endl;
    cout << "|08-09 | 09-10 | 10-11 | 11-12 | 14-15 | 15-16 | 16-17 | 17-18 |";
    // cout <<"|                               ";
    // cout << "                              |";
    cout <<endl;
    cout << "---------------------------------------------------------------";
    cout << endl;
    cout <<"|";
    for (i=0;i<40;i++)
    {
        if (((student+year-1)->course_name[i] == (student+year-1)->course_name[i+1]) && ((student+year-1)->course_name[i] != "-----"))
        {
            cout << "        ";
            cout << (student+year-1)->course_name[i];
            cout << " (L)    ";
            i +=2;
            cout << " | ";
        }
        else
        {
            cout << (student+year-1)->course_name[i];
            cout << " | ";
        }
        if ((i==7) || (i==15) || (i==23) || (i==31))
        {
            cout << endl ;
            cout <<"|";
        }
        if (i==39)
        {
            cout << endl ;
        }
    }
    cout << "---------------------------------------------------------------";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}