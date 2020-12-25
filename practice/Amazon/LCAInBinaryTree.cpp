#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node() = default;
    Node(int _val) {
        val = _val;
        left = right = nullptr;
    }
};


Node* getLCA(Node* root, int val1, int val2) {
    if(root == nullptr)
        return root;
    if(root->val == val1 || root->val == val2)
        return root;
    Node *leftLCA = getLCA(root->left, val1, val2);
    Node *rightLCA = getLCA(root->right, val1, val2);
    if(leftLCA && rightLCA)
        return root;
    if(leftLCA)
        return leftLCA;
    return rightLCA;
}

int main()
{
    // tree, node1, node2
    Node *root;
    int val1, val2;
    Node* lca = getLCA(root, val1, val2);
}