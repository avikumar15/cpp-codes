// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool check(Node* node);

// Driver program to test size function
int main()
{
    int t;
    cin>> t;
    getchar();
    while (t--)
    {
        string s;
        getline( cin, s );
        Node* head = buildTree( s );
        
        cout << check(head) << endl;
    }
    return 0;
}
// } Driver Code Ends


/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
int height(Node* node) {
    if(node==NULL)
        return 0;
    return (max(height(node->left),height(node->right))+1);
}
void populate(Node* node, map<int,vector<Node*>>& mmap, int level) {
    if(node==NULL)
        return;
    mmap[level].push_back(node);
    populate(node->left, mmap, level+1);
    populate(node->right, mmap, level+1);
    
}

bool check(Node* node) {
    
    map<int,vector<Node*>> mmap;
    populate(node, mmap, 0);
    int h = height(node);
    
    int l=-1;
    vector<int> vec;
    
    for(int i=0; i<h; i++) {
        for(int k=0; k<mmap[i].size(); k++) {
            if(mmap[i][k]->left==NULL && mmap[i][k]->right==NULL)
            vec.push_back(i);
        }
    }
    
    l=vec[0];
    for(int i=0; i<vec.size(); i++) {
        if(l!=vec[i])
            return false;
    }
    
    return true;
}
