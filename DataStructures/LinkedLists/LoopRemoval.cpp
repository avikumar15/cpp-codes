// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void removeLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

void removeLoop(Node* head) {
    
    Node* t1=head;
    Node* t2=head;
    bool ans=false;
    
    while(t1!=NULL) {
        if(t1->next==NULL) {
            ans=false;
            break;
        } else {
            t1=t1->next->next;
            t2=t2->next;
            
            if(t1==t2) {
                ans=true;
                break;
            }
        }
    }
    
    // 0->1->2
    //    |  |
    //    4<-3
    // meet at 4
    
    if(ans) {
        t2=head;
        int flag=true;
        if(t1==t2) {
            flag=false;
            while(t1->next!=head) {
                t1=t1->next;
            }
            t1->next=NULL;
            
        }
        
        while(flag) {
            
            Node* last = t1;
            
            t1=t1->next;
            t2=t2->next;
            
            if(t1==t2) {
                last->next=NULL;
                break;
            }
            
        }
    } else {
        //
    }
    
    
}
