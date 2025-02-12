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

int getPartTimeWorkingHour(){
    int r = rand()%8+1;
    return r;
}

int main()
{
    cout << "Welcome to Employee-Wage-computation" << endl ;

    // attendence 
    markAttendence();    

    // calculate daily wages
    int wagePerHour = 20;
    int workingHour = 8;
    int partTimeWorkingHour = getPartTimeWorkingHour();
    int dailyWage = calculateDailyWages(wagePerHour,workingHour);
    cout<< "daily wage of employee is :"<<dailyWage<<endl;
    int partTimeWorkingWage = calculateDailyWages(wagePerHour,partTimeWorkingHour);
    cout<<"partTime wage of employee is : "<<partTimeWorkingWage<<endl;
    cout<<"total wage of employee is : "<<dailyWage+partTimeWorkingWage<<endl;

    return 0;
}