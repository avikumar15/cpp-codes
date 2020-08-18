#include<bits/stdc++.h>

using namespace std;

class Node  {  
    public: 
    int data;  
    Node* next;  
};  

void deleteList(Node** head_ref)  {

    Node* current = *head_ref;  
    Node* next;  
    
    while (current != NULL) {  
        next = current->next;  
        free(current);  
        current = next;  
    }  

    *head_ref = NULL;  
}  

int main() {

}