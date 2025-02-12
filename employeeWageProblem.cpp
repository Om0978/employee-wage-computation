#include<iostream>

using namespace std;

// Function to calculate employee attenedence 
bool markAttendence(){
    srand(time(0));
    int random = rand() % 2 ;
    return random;
}

int calculateDailyWages(int wagePerHour , int workingHour){
    return wagePerHour*workingHour;
}

int getRandomWorkingHour(){
    int r = rand()%8+1;
    return r;
}

int main()
{
    cout << "Welcome to Employee-Wage-computation" << endl ;

    // attendence 
    if(markAttendence()){ 

        // calculate daily wages
        int wagePerHour = 20;
        int workingHour = getRandomWorkingHour();

            int dailyWage = calculateDailyWages(wagePerHour,8);
            cout<< "daily wage of fullTime employee is :"<<dailyWage<<endl;
            int partTimeWage = calculateDailyWages(wagePerHour,workingHour);
            cout<<"partTime employee work for "<<workingHour<<"hr"<<endl;
            cout<<"partTime wage of employee is : "<<partTimeWage<<endl;
    }
    else {
        cout << "Employee is absent " << endl ;
    }
    
    return 0;
}