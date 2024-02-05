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
        // process the top node from stack, and then to indicate that it's processed pop it from stack
        st.pop();
        std::cout << root->val << " ";
        // after processing the top node check if it has a right node, because when we are done with the left sub-tree we need the right sub tree
        // so push the root node of the right sub-tree to the stack first and then the root of the left sub-tree
        // and the top node on the stack will be the root node of left sub-tree and that's what's required.
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
    while (!st.empty() || root != NULL) {
        if (root != NULL) {
            // when root or current node is not NULL traverse the left part
            st.push(root);
            root = root->left;
        } else {
            // when root or current node is NULL process the top node from stack
            // and then traverse the right sub-tree part of current node
            // and if the right node is not NULL it will be pushed to stack in the above if statement
            tree* process = st.top();
            st.pop();
            std::cout << process->val << " ";
            root = process->right;
        }
    }
}

void postorder(tree* root) {
    // process the left sub-tree of the root node first and then the right sub-tree and then process the root node.
    // TODO : iterative approach
    if (root == NULL) {
        return;
    }
    // postorder(root->left);
    // postorder(root->right);
    // std::cout << root->val << " ";
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
