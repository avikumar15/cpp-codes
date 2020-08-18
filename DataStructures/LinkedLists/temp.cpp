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
    
    Node *start=head, *end=head, *prev=NULL, *first, *firstOdd;
    int f=1;
    
    while(end->next!=NULL)
        end=end->next;
    
    first=end;

    while(start!=NULL) {
        if(start==first)
            break;
        if(start->data%2==0) {
            end->next=start;
            start=start->next;
            end=end->next;
            end->next=NULL;
            if(prev)
                prev->next=start;
            continue;
        } else if(f==1) {
            firstOdd=start;
            f=0;
        }
        prev=start;
        start=start->next;
    }
    
    return firstOdd;
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
