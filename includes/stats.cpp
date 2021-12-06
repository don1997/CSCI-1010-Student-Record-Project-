#include<iostream>
#include "functions.h"

using namespace std;

//GET AVERAGE grade
int stats(Node* current){
    int sum = 0, kounter = 0;
    float avg = 0.0;
    while(current != NULL){
       kounter++;
       
       sum = sum + current->grade;
       
       
       avg = sum / kounter;
       
       current = current->next;
    }

return avg;

}//ENDFUNC


//FIND LARGEST
int largest(Node* current){

    //VAR
    int largestGrade;
   
    largestGrade  = current->grade;
     

    while(current != NULL){

        if(current->grade > largestGrade){

            largestGrade = current->grade;

        }
        
        current = current->next;

    }
    
    return largestGrade;

}

//FIND SMALLEST
int smallest(Node* current){

    //VAR
    int smallestGrade;
   
    smallestGrade  = current->grade;
         

    while(current != NULL){

        if(current->grade < smallestGrade){

            smallestGrade = current->grade;

        }   
            
        current = current->next;

    }   
        
    return smallestGrade;

}