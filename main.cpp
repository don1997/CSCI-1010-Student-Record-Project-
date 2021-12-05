//HEADER
//NAME:       Donald McLaughlin
//COURSE:     CSCI 1010
//ASSIGNMENT: Project 2 - Student Records Program
//SUMMARY:    Student records program that allows user to insert, delete, 
//            search, get grade statistics, and view all students that 
//            are recorded into the system. 
//

#include<iostream>
#include"includes/functions.h"
#include"includes/menuAndFormat.h"
using namespace std;


int main(void)
{

    //pointer Declaration
    Node* head = NULL;
    Node* last = NULL; 

    //VAR
    char choice;
    int id, grade,searchID, deleteID;
    string name;
    
    do{
        choice = menu();
            
        switch(choice)
        {

            case '1':   cout << "Enter students ID: ";
                        cin >> id;
                        cout << "Enter students Name: ";
                        cin >> name;
                        cout << "Enter students Grade: ";
                        cin >> grade;
                        insert(head, last, id, name, grade);
                        break;  
            case '2': cout <<"Enter Student ID to Search: ";
                      cin >> searchID;
                        
                      search(head, searchID);
                      break;
            case '3': cout << "The average is : " << stats(head) << endl;
                      cout << "The largest grade is:  " << largest(head) << endl;                   cout << "The smallest grade is: " << smallest(head) << endl;
                      break;
            case '4': cout << "Enter student ID you want to delete: ";
                      cin >> deleteID;
                      deleteNode(head, last, deleteID);
                      break;
            case '5': display(head);
                      break;
            default: cout << "SYSTEM EXIT" << endl;


        }//ENDSWITCH

    

    }while(choice != '6');
    

return 0;
}
