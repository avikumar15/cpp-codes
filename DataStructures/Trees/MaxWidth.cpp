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

int getMaxWidth(Node* root);

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string inp;
        getline(cin, inp);
        Node* root = buildTree(inp);
        
        cout << getMaxWidth(root) <<endl;
    }
    return 0;
}


// } Driver Code Ends


/*  Structure of a Binary Tree 

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

int height(Node *node) {
    if(node==NULL)
        return 0;
    return max(height(node->left),height(node->right))+1;
}

int getWidth(Node *node, int level) {
    if(node==NULL)
        return 0;
        
    if(level==1)
        return 1;
        
    return getWidth(node->left,level-1)+getWidth(node->right,level-1);
}

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root) {
    int mx=height(root);
    int ans=0;
    for(int i=1; i<=mx; i++) {
        ans=max(ans,getWidth(root,i));
    }
    return ans;
}

// ALTERNATE:

// void populate(Node* root, map<int,vector<Node*>>& mmap, int level) {
//     if(root==NULL)
//         return;
//     mmap[level].push_back(root);
//     populate(root->left, mmap, level+1);
//     populate(root->right, mmap, level+1);
// }

// /* Function to get the maximum width of a binary tree*/
// int getMaxWidth(Node* root) {
    
//     map<int,vector<Node*>> mmap;
//     populate(root,mmap,0);
//     int mx=INT_MIN;
    
//     for(auto i:mmap) {
//         vector<Node*> vec=i.second;
//         mx=max(mx,(int)vec.size());
//     }
    
//     return mx;
// }

// ALTERNATE:

// int getMaxWidth(Node* root) {
    
//     if(root==NULL)
//         return 0;
        
//     queue<Node*> q;
//     q.push(root);
//     int mx=1;
    
//     while(!q.empty()) {
        
//         int s=q.size();
        
//         mx=max(mx,s);
        
//         while(s--) {
//             Node* f = q.front();
//             q.pop();
            
//             if(f->left!=NULL) 
//                 q.push(f->left);
                
//             if(f->right!=NULL)
//                 q.push(f->right);
                
//             //cout<<f->data<<" ";
//         }
        
//     }
    
//     return mx;
// }
