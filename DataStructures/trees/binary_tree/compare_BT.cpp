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


bool compare(tree* root1, tree* root2)
{
    // structural check
    if (root1 == NULL && root2 == NULL) {
        // leaf node
        return true;
    }

    // structural check
    if (root1 == NULL || root2 == NULL) {
        // if any of the above conditions are true then return false
        return false;
    }

    // value check
    if (root1->val != root2->val) {
        // Even though the structure is similar but the values aren't return false.
        return false;
    }

    std::cout << "root1 : " << root1->val << " , root2 : " << root2->val << " ; going left"<< endl;
    bool left_subtree = compare(root1->left, root2->left);
    std::cout << "root1 : " << root1->val << " , root2 : " << root2->val << " ; going right"<< endl;
    bool right_subtree = compare(root1->right, root2->right);
    if (left_subtree && right_subtree) {
        std::cout << "root1 : " << root1->val << " , root2 : " << root2->val << " ; done traversing left & right subtree and ret true; backtrack"<< endl;
        std::cout << endl;
    } else {
        std::cout << "root1 : " << root1->val << " , root2 : " << root2->val << " ; done traversing left & right subtree and ret false; backtrack"<< endl;
        std::cout << endl;
    }
    return left_subtree && right_subtree;
}

int main (int argc, char *argv[])
{

    tree* root1 = new tree(1);
    root1->left = new tree(2);
    root1->right = new tree(3);
    root1->left->left = new tree(4);
    root1->left->right = new tree(5);
    root1->right->left = new tree(6);
    root1->right->right = new tree(7);

    tree* root2 = new tree(1);
    root2->left = new tree(2);
    root2->right = new tree(3);
    root2->left->left = new tree(4);
    root2->left->right = new tree(5);
    root2->right->left = new tree(6);
    root2->right->right = new tree(7);

    if (compare(root1, root2)) {
        std::cout << "Both trees are similar structurally and have similar values" << endl;
    } else {
        std::cout << "trees are not similar" << endl;
    }

    return 0;
}
