//HEADER
//
//
//
//
//
//
//
//
//

#include<iostream>

using namespace std;

struct Node{

    int id;
    string name;
    int grade;

    Node* next;

};





void testIN()
{

    cout << "Test input" << endl;


}

void lines(){
 
    for(int i = 0; i < 20; i++){
    
        cout << "-";
    
    }
    cout << "\n";


}

//checks if linked list is empty
bool ifempty(Node *head){

    if(head == NULL){

        return true;    

    }
    else{

        return false;

    }
}

void insertAsFirst(Node *head, Node *last, int id, string name, int grade){


    Node *temp  = new Node;
    
    temp ->id = id;
    temp ->name = name;
    temp ->grade = grade;

    temp ->next = NULL;

    head = temp;
    last = temp;
}


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
    cout << "|--->>";
    cin >> choice;
    return choice;
}







int main(void)
{

    //pointer Declaration
    Node* head = NULL;
    Node* last = NULL; 

    //VAR
    char choice;
    int num;
    
    do{
        choice = menu();
            
        switch(choice)
        {

            case '1': //insert();
              
            case '2': //search();
                
            case '3': //stats();
            
            case '4': //remove();
                
            case '5': //display();
                 
            default: cout << "SYSTEM EXIT" << endl;


        }//ENDSWITCH

    

    }while(choice != 6);
    

return 0;
}
