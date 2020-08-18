#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* push(Node* head, int a) {
    if(head==NULL) {
        head=new Node;
        head->next=NULL;
        head->data=a;

        return head;
    }
    Node *t=head;
    while(t->next!=NULL)
        t=t->next;
    Node *temp = new Node;
    temp->data=a;
    temp->next=NULL;
    t->next=temp;

    return head;
}

Node* actualSolve(Node *head, int n) {
    
    Node *t1,*t2;
    t1=head;
    t2=head;
    int cnt=0;
    
    if(head==NULL)
        return NULL;
        
    while(t1->next!=NULL) {
        t1=t1->next;
    //    cnt++;
    }
    
    
    Node *prev=NULL;
    Node *t2update=t2;
    Node *first=NULL;
    
    while(cnt<n) {
        if(t2update->data%2==0) {
            prev=t2update;
            t2update=t2update->next;
            t2=t2->next;
            if(first==NULL)
                first=prev;
        } else {
            if(prev==NULL) {
                t1->next=t2;
                t2update=t2->next;
                t2->next=NULL;
                t1=t2;
                t2=t2update;
            } else {
                t1->next=t2;
                t2update=t2->next;
                prev->next=t2update;
                t2->next=NULL;
                t1=t2;
                t2=t2update;
            }
        }
        cnt++;
    }
    
    return first;
    
}

void solve(){
    int n;
    cin>>n;
    Node* hd=NULL;
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        hd=push(hd,temp);
    }
    
    hd=actualSolve(hd,n);
    
    while(hd!=NULL) {
        cout<<hd->data<<" ";
        hd=hd->next;
    }
    cout<<endl;
}

int main() {
	
	int t;
	cin>>t;
	while(t--) {
	    solve();
	}
	return 0;
}
