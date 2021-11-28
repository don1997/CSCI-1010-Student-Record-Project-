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
    char name;
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
bool isEmpty(Node *head){

    if(head == NULL){

        return true;    

    }
    else{

        return false;

    }
}

void insertAsFirst(Node *head, Node *last, int id, char name, int grade){


    Node *temp  = new Node;
    
    temp ->id = id;
    temp ->name = name;
    temp ->grade = grade;

    temp ->next = NULL;

    head = temp;
    last = temp;
}

void insert(Node *head, Node *last, int id, char name, int grade){

    if(isEmpty(head)){

        insertAsFirst(head, last, id, name, grade);

    }

    else{


    Node *temp = new Node;
    
    temp->id = id;
    temp->name = name;
    temp->grade = grade;
    temp->next = NULL;
    
    last->next = temp;

    last = temp;


    }


}

//Displays current list
void display(Node *current)
{

    if(isEmpty(current)){
        
        cout << "The list is empty.\n";

    }//ENDIF
    else{

        cout << "The list contains: \n";
        while(current != NULL){

            cout << current->id << endl;
            current = current->next;

        }//ENDWHILE                                                               

    }//ENDELSE

}//ENDFUNC


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
    int id, grade;
    char name;
    
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
            case '2': //search();
                      break;
            case '3': //stats();
                      break;
            case '4': //remove();
                      break;
            case '5': display(head);
                      break;
            default: cout << "SYSTEM EXIT" << endl;


        }//ENDSWITCH

    

    }while(choice != 6);
    

return 0;
}
