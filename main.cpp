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
bool isEmpty(Node *head){

    if(head == NULL){

        return true;    

    }
    else{

        return false;

    }
}

void insertAsFirst(Node *&head, Node *&last, int id, string name, int grade){


    Node *temp  = new Node;
    
    temp ->id = id;
    temp ->name = name;
    temp ->grade = grade;

    temp ->next = NULL;

    head = temp;
    last = temp;
}

void insert(Node *&head, Node *&last, int id, string name, int grade){

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

void deleteNode(Node *&head, Node *&last, int studentID){

    if(isEmpty(head)){
            
        cout << "The list is empty.\n";

    }//ENDIF
    
    Node * currNode = head;

    if(head->id == studentID){

        head = head->next;
        delete currNode;

    }

    else{

            Node * prev = NULL; 
            while(currNode != NULL && currNode->id != studentID){
                prev = currNode;
                currNode = currNode->next;
            }//ENDWHILE
    
        if(currNode != NULL){

            prev->next = currNode->next;
            delete currNode;

        }

        
    }//ENDELSE
}//ENDFUNC


//Displays current list
void display(Node *current)
{

    if(isEmpty(current)){
        
        cout << "The list is empty.\n";

    }//ENDIF
    else{

        lines();
        cout << "|ID\tNAME\tGRADE|" << endl;

        while(current != NULL){
        cout <<"|" << current->id << "\t";
        cout << current->name << "\t";
        cout << current->grade << "   |" << endl;
        current = current->next;
        }//ENDWHILE                                                               

    }//ENDELSE


}//ENDFUNC


void search(Node *current, int StudentID){
    
    if(isEmpty(current)){
        cout << "List is empty." << endl;
    }
    else{
        
        while(current != NULL){

            if( current->id == StudentID){
                cout << current->id << endl;
                cout << current->name << endl;
                cout << current->grade << endl;
                break;

            }//ENDIF
            
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
    cout << "|--->> ";
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
            case '3': //stats();
                      break;
            case '4': cout << "Enter student ID you want to delete: ";
                      cin >> deleteID;
                      deleteNode(head, last, deleteID);
                      break;
            case '5': display(head);
                      break;
            default: cout << "SYSTEM EXIT" << endl;


        }//ENDSWITCH

    

    }while(choice != 6);
    

return 0;
}
