//HEADER
//NAME:       Donald McLaughlin
//COURSE:     CSCI 1010
//ASSIGNMENT: Project 2 - Student Records Program
//SUMMARY:    Student records program that allows user to insert, delete, 
//            search, get grade statistics, and view all students that 
//            are recorded into the system. 

#include<iostream>

using namespace std;



//NODE FUNCTIONS START///////////////////////

class Node{
public:
    int id; 
    std::string name;
    int grade;

    Node* next;

};


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
    
    //IF EMPTY LIST break out of a function.
    if(isEmpty(head)){
            
        cout << "The list is empty.\n";
        return;

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

//loops lines for student display table
//Needs to be for function below
void linesTable(){

    for(int i = 0; i < 54; i++){                                                  
            
        cout << "-";
        
    }   
        
    cout << "\n";
}

//Displays current list
void display(Node *current)
{

    //IF EMPTY LIST
    if(isEmpty(current)){
        
        cout << "The list is empty.\n";

    }//ENDIF
    else{

        linesTable();
        cout << "|ID\t\tNAME\t\t\t\tGRADE|" << endl;
        linesTable();

        while(current != NULL){
        cout <<"|" << current->id << "\t\t";
        cout << current->name << "\t\t\t";
        cout << current->grade << "   |" << endl;
        current = current->next;
        linesTable();
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
                cout << "ID: " << current->id << endl;
                cout << "Name: " << current->name << endl;
                cout << "Grade: " << current->grade << endl;
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

//NODE FUNCTIONS END//////////////////

//STATS FUNCTIONS START//////////////
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
//STATS FUNCTIONS END//////////////

//FORMAT FUNCTIONS///////////////
//Loops Lines 
void lines(){
 
    for(int i = 0; i < 20; i++){
        
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
//FORMAT FUNCTIONS END////////////////


//MAIN START///////////////////////////////////////////
int main(void)
{

    //pointer Declaration
    Node* head = NULL;
    Node* last = NULL; 

    //VAR
    char choice;
    int id, grade,searchID, deleteID;
    string name;

    id = 0;
  

    //MENU    
    do{
        choice = menu();
            
        switch(choice)
        {

            case '1':   id = id + 1;
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
            case '3': stats(head);
                      largest(head);                 
                      smallest(head);
                      break;
            case '4': cout << "Enter student ID you want to delete: ";
                      cin >> deleteID;
                      deleteNode(head, last, deleteID);
                      break;
            case '5': display(head);
                      break;
            default: cout << "SYSTEM EXIT" << endl;


        }//ENDSWITCH

    

    }while(choice != '6');//ENDLOOP
    

return 0;
}
//MAIN END//////////////////////////////////////////////
