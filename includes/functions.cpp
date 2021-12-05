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




//Displays current list
void display(Node *current)
{

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

