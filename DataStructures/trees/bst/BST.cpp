#include <iostream>

#define endl std::endl

typedef struct tree 
{
    int val;
    struct tree *left;
    struct tree *right;
    tree(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
} tree;

bool search(tree* root, int needle)
{
    if (root == NULL) {
        return false;
    }

    if (root->val == needle) {
        return true;
    }

    if (needle > root->val) {
        return search(root->right, needle);
    }
    else {
        // BST follow :
        // right_subtree.val should be > root.val
        // left_subtree.val should be <= root.val
        return search(root->left, needle);
    }
}

int main (int argc, char *argv[])
{
    tree* root = new tree(17);
    root->left = new tree(15);
    root->right = new tree(50);
    root->left->left = new tree(2);
    root->left->right = new tree(16);
    root->right->left = new tree(25);
    root->right->right = new tree(100);

    int needle = 100;

    if (search(root, needle)) {
        std::cout << "Found" << endl;
    } else {
        std::cout << "Not Found" << endl;
    }

    return 0;
}
