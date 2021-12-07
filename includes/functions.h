#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>

class Node{
public:
    int id; 
    std::string name;
    int grade;

    Node* next;

};

//checks if linked list is empty
bool isEmpty(Node*);

void insertAsFirst(Node*&, Node*&, int, std::string, int);

void insert(Node*&, Node*&, int, std::string, int);

void deleteNode(Node*&, Node*&, int);

void display(Node*);

void search(Node*, int);

#endif
