#include "functions.h"

int main()
{
    // Ensures proper functioning of rand() in the slot assigning function
    srand(time(NULL));
    int n,l,p,i;
    // Getting the number of theory courses and lab courses
    ifstream fps;
    fps.open("num_inputs.txt");
    fps >> n;
    fps >> l;
    fps.close();
    struct week student[5], prof[n];
    struct course courses[n+l];

    // Initializing the student's and prof's schedule
    for (i=0;i<5;i++)
    {
        for (int j=0;j<40;j++)
        { 
            student[i].schedule[j] = 'f';
            student[i].course_name[j] = "-----";
        }
    }

    for (i=0;i<n;i++)
    {
        for (int j=0;j<40;j++)
        {
            prof[i].schedule[j] = 'f';
            prof[i].course_name[j] = "-----";
        }
    }

    ifstream fp;
    fp.open("courses.txt");

    int year,prof_name;
    int is_lab;
    int index = 0;

    // Assigning slots and setting the schedule for everyone
    for (i=0;i<n+l;i++)
    {
        courses[i] = get_course_from_file(&fp);
        year = courses[i].student_year;
        prof_name = courses[i].prof_name;
        is_lab = courses[i].is_lab;
        if (is_lab==1)
        {
            index = getSlot(is_lab,student+year-1,prof+prof_name-1);
            courses[i].index[0] = index;
            student[year-1].schedule[index] = 'b';
            student[year-1].schedule[index+1] = 'b';
            student[year-1].schedule[index+2] = 'b';
            prof[prof_name-1].schedule[index] = 'b';
            prof[prof_name-1].schedule[index+1] = 'b';
            prof[prof_name-1].schedule[index+2] = 'b';
            student[year-1].course_name[index] = courses[i].course_name;
            student[year-1].course_name[index+1] = courses[i].course_name;
            student[year-1].course_name[index+2] = courses[i].course_name;
            prof[prof_name-1].course_name[index] = courses[i].course_name;
            prof[prof_name-1].course_name[index+1] = courses[i].course_name;
            prof[prof_name-1].course_name[index+2] = courses[i].course_name;
            index +=3;
        }
        else
        {
            int j;
            for (j=0;j<3;j++)
            {
                if (j==0)
                {
                    index = getSlot(is_lab,student+year-1,prof+prof_name-1);
                    courses[i].index[j] = index;
                }
                else
                {
                    do
                    {
                        index = getSlot(is_lab,student+year-1,prof+prof_name-1);
                    } while (check_index_alt(courses[i].index[j-1],index)==0);
                    courses[i].index[j] = index;
                }

                student[year-1].schedule[index] = 'b';
                prof[prof_name-1].schedule[index] = 'b';
                student[year-1].course_name[index] = courses[i].course_name;
                prof[prof_name-1].course_name[index] = courses[i].course_name;
                index++;
            }
        }
    }
    fp.close();
    
    // Menu driven program to print the generated time table
    while (1)
    {
        int choice,year;
        cout << "--------------------------------------------------------------";
        cout << endl;
        cout << endl;
        cout << "                       Time Table Generator                   ";
        cout << endl;
        cout << endl;
        cout << "---------------------------------------------------------------";
        cout <<endl;
        cout<<"1.Generate Time Table"<<endl;
        cout<<"2.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter Year: ";
            cin >> year;
            print_tt(year,student);
            break;
        case 2:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}

