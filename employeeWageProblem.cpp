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

int main()
{
    cout << "Welcome to Employee-Wage-computation" << endl ;

    // attendence 
    markAttendence();    

    return 0;
}