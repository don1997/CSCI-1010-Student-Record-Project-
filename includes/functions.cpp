#include<iostream>
#include "functions.h"
#include "menuAndFormat.h"

using namespace std;

//checks if linked list is empty
bool isEmpty(Node *head){

    if(head == NULL){

        return true;    

    }
    else{

        return false;

    }
}

//INSERT First Node
void insertAsFirst(Node *&head, Node *&last, int id, string name, int grade){

    Node *temp  = new Node;
    
    temp ->id = id;
    temp ->name = name;
    temp ->grade = grade;

    temp ->next = NULL;

    head = temp;
    last = temp;
}

//INSERT Node after first
void insert(Node *&head, Node *&last, int id, string name, int grade){
    
    //IF EMPTY LIST
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

//DELETE Node
void deleteNode(Node *&head, Node *&last, int studentID){
    
    //IF EMPTY LIST
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
        else{

            cout << "ID does not exist." << endl;
        
    
        }
        
    }//ENDELSE
}//ENDFUNC

//Displays current list
void display(Node *current)
{

    //IF EMPTY LIST
    if(isEmpty(current)){
        
        cout << "The list is empty.\n";

    }//ENDIF
    else{

        lines();
        cout << "|ID\t\t\tNAME\t\t\tGRADE|" << endl;

        while(current != NULL){
        cout <<"|" << current->id << "\t\t\t";
        cout << current->name << "\t\t\t";
        cout << current->grade << "   |" << endl;
        current = current->next;
        }//ENDWHILE                                                               

    }//ENDELSE


}//ENDFUNC

//SEARCH student by ID and DISPLAY
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
            else{
            
                cout << "ID does not exist." << endl;
                break;

            }
            current = current->next;

        }//ENDWHILE
    }//ENDELSE
}//ENDFUNC

