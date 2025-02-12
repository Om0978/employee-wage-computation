#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ComputeEmployee
{
private:
    const int totalDays = 20;       // Total working days of the month
    const int wagePerHour = 20;     // Wage per hour
    const int maxWorkingHours = 100;
    int totalFullTimeEmployeeWage = 0;
    int totalPartTimeEmployeeWage = 0;
    int totalWorkingHours = 0;

    // Function to calculate employee attendance
    int markAttendance()
    {
        return rand() % 2;
    }

    // Function to calculate employee wage
    int calculateDailyWages(int workingHour)
    {
        return wagePerHour * workingHour;
    }

    // Function to get random working hours for part-time employee
    int getRandomWorkingHour()
    {
        return rand() % 8 + 1;
    }

public:
    ComputeEmployee()
    {
        srand(time(0)); // Seed for randomization
    }

    // function to compute employee wages
    void computeWage()
    {
        for (int i = 1; i <= totalDays; i++)
        {
            // Attendance
            int attendance = markAttendance();
            int dailyWage = 0;
            int workingHour = 0;
            int partTimeWage = 0;

            if (totalWorkingHours >= maxWorkingHours)
            {
                cout << "Max working hours reached" << endl;
                break;
            }

            switch (attendance)
            {
            case 0: // Employee is absent
                break;
            case 1: // Employee is present
                int fullTimeWorkingHr = 8;
                workingHour = getRandomWorkingHour(); // For part-time employee

                if (totalWorkingHours + fullTimeWorkingHr > maxWorkingHours)
                {
                    fullTimeWorkingHr = maxWorkingHours - totalWorkingHours;
                }

                if (totalWorkingHours < maxWorkingHours - 8)
                {
                    dailyWage = calculateDailyWages(fullTimeWorkingHr);
                    totalWorkingHours += fullTimeWorkingHr;
                }

                if (totalWorkingHours < maxWorkingHours - workingHour)
                {
                    totalWorkingHours += workingHour;
                    partTimeWage = calculateDailyWages(workingHour);
                }

                totalFullTimeEmployeeWage += dailyWage;
                totalPartTimeEmployeeWage += partTimeWage;
                break;
            }
        }
    }

    // function to display final wages
    void displayWages()
    {
        cout << "Full-time employee monthly wage: " << totalFullTimeEmployeeWage << endl;
        cout << "Part-time employee monthly wage: " << totalPartTimeEmployeeWage << endl;
        cout << "Total monthly wage: " << totalFullTimeEmployeeWage + totalPartTimeEmployeeWage << endl;
    }
};

int main()
{
    cout << "Welcome to Employee-Wage Computation" << endl;
    ComputeEmployee emp;
    emp.computeWage();
    emp.displayWages();
    return 0;
}
