#include<iostream>
#include "functions.h"
#include "stats.h"

using namespace std;

//GET AVERAGE grade
void stats(Node* current){
    int sum = 0, kounter = 0;
    float avg = 0.0;
    
    //IF EMPTY LIST break out of a function.
    if(isEmpty(current)){
            
        cout << "The list is empty.\n";
        return ;

    }//ENDIF
    while(current != NULL){
       kounter++;
       
       sum = sum + current->grade;
       
       
       avg = sum / kounter;
       
       current = current->next;
    }

    cout << "The average is: " << avg << endl;

}//ENDFUNC


//FIND LARGEST
void largest(Node* current){

    //VAR
    int largestGrade;
    //IF EMPTY LIST break out of a function.
    if(isEmpty(current)){
            
        
        return ;

    }//ENDIF
    
    largestGrade  = current->grade;
     

    while(current != NULL){

        if(current->grade > largestGrade){

            largestGrade = current->grade;

        }
        
        current = current->next;

    }
    
    cout << "The largest grade is: " << largestGrade << endl;

}

//FIND SMALLEST
void smallest(Node* current){

    //VAR
    int smallestGrade;
    //IF EMPTY LIST break out of a function.
    if(isEmpty(current)){
            
        
        return ;

    }//ENDIF
    smallestGrade  = current->grade;
         

    while(current != NULL){

        if(current->grade < smallestGrade){

            smallestGrade = current->grade;

        }   
            
        current = current->next;

    }   
        
    cout << "The smallest grade is: " << smallestGrade << endl;

}