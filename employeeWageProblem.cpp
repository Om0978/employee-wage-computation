#include<iostream>

using namespace std;

// Function to calculate employee attenedence 
void markAttendence(){
    srand(time(0));
    int random = rand() % 2 ;
    
    if(random == 0) 
    {
        cout << "Employee is absent . " << endl ;
    }
    else
    {
        cout << "Employee is present . " << endl ;
    }
}

int calculateDailyWages(int wagePerHour , int workingHour){
    return wagePerHour*workingHour;
}

int main()
{
    cout << "Welcome to Employee-Wage-computation" << endl ;

    // attendence 
    markAttendence();    

    // calculate daily wages
    int wagePerHour = 20;
    int workingHour = 8;
    int dailyWage = calculateDailyWages(wagePerHour,workingHour);
    cout<< "daily wage of employee is :"<<dailyWage<<endl;

    return 0;
}