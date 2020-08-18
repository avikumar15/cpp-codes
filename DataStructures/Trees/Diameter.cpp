// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
/* Function to get diameter of a binary tree */
int diameter(struct Node* tree);

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        cout << diameter(root) << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

int height(Node* node, map<Node*,int>& mmap) {
    if(node==NULL)
        return 0;
    if(mmap.find(node)!=mmap.end())
        return mmap[node];
        
    int l=height(node->left,mmap);
    int r=height(node->right,mmap);
    
    mmap[node]=max(l,r)+1;
    return mmap[node];
}

int diameterActually(Node* node, map<Node*, int> mmap) {
    if(node==NULL)
        return 0;
    
    int mxl=diameterActually(node->left,mmap);
    int mxr=diameterActually(node->right,mmap);
    int mxd=max(mxl,mxr);
    int hh=mmap[node->left]+mmap[node->right]+1;
    
    return max(mxd,hh);
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    
    map<Node*,int> mmap;
    int h=height(node,mmap);
    h*=6969;
    
    return diameterActually(node,mmap);
    
}

// SIMPLER VERSION WHICH MIGHT GIVE TLE:

// int height(Node* node) {
//     if(node==NULL)
//         return 0;
//     return max(height(node->left),height(node->right))+1;
// }

// /* Computes the diameter of binary tree with given root.  */
// int diameter(Node* node) {
    
//     if(node==NULL)
//         return 0;
        
//     return max({diameter(node->left),diameter(node->right),(height(node->left)+height(node->right)+1)});
    
// }

