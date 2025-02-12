#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to calculate employee attenedence
int markAttendance()
{
    srand(time(0));
    int random = rand() % 2;
    return random;
}

// Function to calculate employee wage
int calculateDailyWages(int wagePerHour, int workingHour)
{
    return wagePerHour * workingHour;
}

// Function to get random working hours for part-time employee
int getRandomWorkingHour()
{
    int r = rand() % 8 + 1;
    return r;
}

int main()
{
    cout << "Welcome to Employee-Wage-computation" << endl;

    const int totalDays = 20; // total working-days of month
    int totalFullTimeEmployeeWage = 0;
    int totalPartTimeEmployeeWage = 0;
    int maxWorkingHours = 100;
    int totalWorkingHours = 0;


    for (int i = 1; i <= totalDays; i++)
    {

        // attendence
        int attendance = markAttendance();

        const int wagePerHour = 20;
        int dailyWage = 0;
        int workingHour = 0;
        int partTimeWage = 0;

        if(totalWorkingHours>=maxWorkingHours){
            cout<<"max working hours reached";
            break;
        }
        switch (attendance)
        {
        case 0: // employee is absent
            //cout << "employee is absent " << endl;
            break;

        case 1: // employee is present

            // calculate daily wages
            int fullTimeWorkingHr=8;
            workingHour = getRandomWorkingHour(); // for partTime employee

            if(totalWorkingHours+fullTimeWorkingHr>maxWorkingHours){ // calculate wage for remaining days 
                fullTimeWorkingHr=maxWorkingHours-totalWorkingHours;
                dailyWage = calculateDailyWages(wagePerHour, fullTimeWorkingHr);
                break;
            }

            if(totalWorkingHours<maxWorkingHours-8){
                dailyWage = calculateDailyWages(wagePerHour, fullTimeWorkingHr); // for fullTime employee
                totalWorkingHours+=8;
                // cout << "daily wage of fullTime employee is :" << dailyWage << endl;
            }

            if(totalWorkingHours<maxWorkingHours-workingHour){
                totalWorkingHours+=workingHour;
                partTimeWage = calculateDailyWages(wagePerHour, workingHour);
                // cout << "partTime employee work for " << workingHour << "hr" << endl;
                // cout << "partTime wage of employee is : " << partTimeWage << endl;
            }

            totalFullTimeEmployeeWage+=dailyWage;
            totalPartTimeEmployeeWage+=partTimeWage;
            break;
        }

    }

    cout<<"full-time employee monthly wage is :"<<totalFullTimeEmployeeWage<<endl;
    cout<<"part-time employee monthly wage is :"<<totalPartTimeEmployeeWage<<endl;
    cout<<"total month waige is : "<<totalFullTimeEmployeeWage+totalPartTimeEmployeeWage<<endl;

    return 0;
}