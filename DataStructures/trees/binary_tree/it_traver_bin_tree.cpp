#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stack>

#define endl std::endl

typedef struct tree {
    int val;
    struct tree* left;
    struct tree* right;
    tree(int data) {
        // constructor
        val = data;
        left = NULL;
        right = NULL;
    }
} tree;

void preorder(tree* root) {
    if (root == NULL) {
        return;
    }
    std::stack<tree*> st;
    st.push(root);
    while (!st.empty()) {
        root = st.top();
        std::cout << root->val << " ";
        st.pop();
        if (root->right != NULL) {
            st.push(root->right);
        }
        if (root->left != NULL) {
            st.push(root->left);
        }
    }
}

void inorder(tree* root) {
    if (root == NULL) {
        return;
    }
    std::stack<tree*> st;
    while(!st.empty() || root != NULL) {
        if(root != NULL) {
            st.push(root);
            root = root->left;
        } else {
            tree *print = st.top();
            st.pop();
            std::cout << print->val << " ";
            root = print->right;
        }
    }
}

int main (int argc, char *argv[]) {
    // tree
    /*
         1   
       /   \
      2     3
     / \   / \ 
    4   5  6  7

    */
    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);
    std::cout << "preorder  : ";
    preorder(root);
    std::cout << endl;
    std::cout << "inorder   : ";
    inorder(root);
    std::cout << endl;
    return 0;
}
