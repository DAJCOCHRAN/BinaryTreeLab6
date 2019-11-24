#include"header.h"
//main funcitons

void assignList(string myString, Node * &node){
    //start position zero
    static int pos = 1;
    //conditional recursion for beginning node
    //base case
    if(!myString[pos]){
        cout << "statement has been placed in linked list" << endl;
        return;
    }
    else{
        //allocate memory for linked list
        Node * n = new Node;
        node->next = n;
        n->value = myString[pos];
        //position shifts
        pos++;
        assignList(myString, n);
    }
}

void printList(Node * &node){
    if(node->next == NULL){
        cout << node->value << endl;
    }
    else{
        cout << node->value <<endl;
        printList(node->next);
    }
}

void deleteList(Node * &node){ 
    if(node->next==NULL){
        delete node;
        cout << "All items from list have been deleted" << endl;
        return;
    }
    else{
        Node * nextNode = node->next;
        delete node;
        deleteList(nextNode);
    }
}

//class functions
//void charValue(){
//   cout << ""
//}

//void::createTree(Node * &node){

//}


