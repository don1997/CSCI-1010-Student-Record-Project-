#include<iostream>
#include "menuAndFormat.h"

using namespace std;

//Loops Lines 
void lines(){
 
    for(int i = 0; i < 20; i++){
        
        cout << "-";
        
    }   
    cout << "\n";


}

//loops lines for student display table
void linesTable(){

    for(int i = 0; i < 54; i++){
        
        cout << "-";
    
    }
    
    cout << "\n";
}

//DISPLAYS Menu and returns Choice
char menu(){

    char choice;

    cout << "---- CSCI 1010 Student Information Management System ----\n";
    cout << "1. Add Student" << endl;
    cout << "2. Search By ID" << endl;
    cout << "3. Grade Statistics" << endl;
    cout << "4. Remove a Student" << endl;
    cout << "5. Print all students" << endl;
    cout << "6. Exit the system\n\n" << endl;
    lines();
    cout << "|--->> ";
    cin >> choice;
    return choice;
}                                                                           
