#include <cstddef>
#include <cstdlib>
#include <iostream>

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

int main (int argc, char *argv[]) {
    tree* root = new tree(1);
    tree* root_left = new tree(2);
    tree* root_right = new tree(3);
    tree* root_left_left = new tree(4);
    tree* root_left_right = new tree(5);
    tree* root_left_left_right = new tree(6);

    // build this tree
    /*
        1
       / \
      2   3
     / \
    4   5
     \
      6

    */
    root->left = root_left;
    root->right = root_right;
    root->left->left = root_left_left;
    root->left->right = root_left_right;
    root->left->left->right = root_left_left_right;

    // or .. another method would be
    // tree* root = new tree(1);
    // root->left = new tree(2);
    // root->right = new tree(3);
    // root->left->left = new tree(4);
    // root->left->right = new tree(5);
    // root->left->left->right = new tree(6);

    std::cout << root->val << std::endl; // 1
    std::cout << root->left->val << std::endl; // 2
    std::cout << root->right->val << std::endl; // 3
    std::cout << root->left->left->val << std::endl; // 4
    std::cout << root->left->right->val << std::endl; // 5
    std::cout << root->left->left->right->val << std::endl; // 6
    return 0;
}
