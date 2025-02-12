#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to calculate employee attenedence 
int markAttendance(){
     srand(time(0));
    int random = rand() % 2 ;
    return random;
}

// Function to calculate employee wage 
int calculateDailyWages(int wagePerHour , int workingHour){
    return wagePerHour*workingHour;
}

// Function to get random working hours for part-time employee
int getRandomWorkingHour(){
    int r = rand()%8+1;
    return r;
}

int main()
{
    cout << "Welcome to Employee-Wage-computation" << endl ;

    // attendence 
    int attendance = markAttendance();

    int wagePerHour = 20; 
    int dailyWage =0;
    int workingHour = 0;
    int partTimeWage = 0;

    switch(attendance){
        case 0: // employee is absent
            cout << "employee is absent " << endl ;
            break;
        
        case 1: // employee is present
        
            // calculate daily wages
            dailyWage = calculateDailyWages(wagePerHour,8); // for fullTime employee
            cout<< "daily wage of fullTime employee is :"<<dailyWage<<endl;
            workingHour = getRandomWorkingHour(); // for partTime employee
            partTimeWage = calculateDailyWages(wagePerHour,workingHour);
            cout<<"partTime employee work for "<<workingHour<<"hr"<<endl;
            cout<<"partTime wage of employee is : "<<partTimeWage<<endl;
            break;
        default:
            cout<<"invalid attendance value";
            break;
    }
    
    return 0;
}