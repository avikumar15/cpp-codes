#include<bits/stdc++.h>

using namespace std;

class Node{
    int data;
    Node *left,*right;
};

// void inorder(Node* root, vector<int>& res) {
//     if(root) {
//         inorder(root->left,res);
//         res.push_back(root->data);
//         inorder(root->right,res);
//     }
// }

// vector<int> inOrder(Node* root) {
//     vector<int> res;
//     inorder(root, res);
//     return res;
// }

// void postOrder(Node* root, vector<int>& res) {
//     if(root) {
//         postOrder(root->left,res);
//         postOrder(root->right,res);
//         res.push_back(root->data);
//     }
// }

// vector<int> postOrder(Node* root) {
//     vector<int> res;
//     postOrder(root, res);
//     return res;
// }

// void preorder(Node* root, vector<int>& res) {
//     if(root) {
//         res.push_back(root->data);
//         preorder(root->left,res);
//         preorder(root->right,res);
//     }
// }

// vector<int> preorder(Node* root) {
//     vector<int> res;
//     preorder(root, res);
//     return res;
// }
