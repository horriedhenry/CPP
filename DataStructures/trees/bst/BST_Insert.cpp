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

void inorder(tree* root)
{
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

void insert(tree* root, int ins_val)
{
    if (root->val < ins_val) {
        if (root->right == NULL) {
            root->right = new tree(ins_val);
            return;
        }
        insert(root->right, ins_val);
    } else if (root->val >= ins_val) {
        if (root->left == NULL) {
            root->left = new tree(ins_val);
            return;
        }
        insert(root->left, ins_val);
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

    insert(root, 10);
    insert(root, 10);
    insert(root, 17);
    insert(root, 17);
    insert(root, 17);
    insert(root, 200);
    inorder(root);

    return 0;
}
