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
Node * lca(Node* root,int n1,int n2);
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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        cout<<lca(root,a,b)->data<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* A binary tree node

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

// Alternate
struct Node *findLCA(struct Node* root, int n1, int n2)  { 
    // Base case 
    if (root == NULL) return NULL; 
  
    // If either n1 or n2 matches with root's key, report 
    // the presence by returning root (Note that if a key is 
    // ancestor of other, then the ancestor key becomes LCA 
    if (root->data == n1 || root->data == n2) 
        return root; 
  
    // Look for keys in left and right subtrees 
    Node *left_lca  = findLCA(root->left, n1, n2); 
    Node *right_lca = findLCA(root->right, n1, n2); 
  
    // If both of the above calls return Non-NULL, then one key 
    // is present in once subtree and other is present in other, 
    // So this node is the LCA 
    if (left_lca && right_lca)  return root; 
  
    // Otherwise check if left subtree or right subtree is LCA 
    return (left_lca != NULL)? left_lca: right_lca; 
} 


/* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return 
   NULL. Else if left subtree contains any 
   of them return pointer to left.*/

void populate(Node* node, map<int,vector<Node*>>& mmap,vector<Node*> nodes) {
    
    if(node==NULL)
        return;
    
    nodes.push_back(node);
    mmap[node->data]=nodes;
    
    populate(node->left,mmap,nodes);
    populate(node->right,mmap,nodes);

}

Node* lca(Node* root ,int n1 ,int n2 ) {
    
    map<int,vector<Node*>> mmap;
    vector<Node*> nodes;
    
    populate(root,mmap,nodes);
    
    int s=min(mmap[n1].size()-1,mmap[n2].size()-1);
    
    for(;s>=0;s--) {
        if(mmap[n1][s]==mmap[n2][s])
            break;
    }
    
    return mmap[n1][s];
}

// ALTERNATE:
// Node* lca(Node* root ,int n1 ,int n2 ) {
    
//     if(root==NULL)
//         return NULL;
    
//     if(root->data==n1 || root->data==n2) {
//         return root;
//     }
    
//     Node* left=lca(root->left,n1,n2);
//     Node* right=lca(root->right,n1,n2);
    
//     if(left&&right)
//         return root;
        
//     if(left)
//         return left;
//     if(right)
//         return right;
// }
