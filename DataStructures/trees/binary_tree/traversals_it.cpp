#include <cstddef>
#include <iostream>
#include <stack>
#include <vector>

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

void preorder(tree* root, std::vector<int> traversal)
{
    if (root == NULL) {
        return;
    }

    std::stack<tree*> s;
    s.push(root);
    while (!s.empty()) {
        std::cout << "---- Begin Loop ----" << endl;
        tree* top = s.top();
        std::cout << "Popped : " << top->val << endl;
        s.pop();
        if (top->right != NULL) {
            std::cout << "---- Push ----" << endl;
            std::cout << "Pushed : " << top->right->val << endl;
            s.push(top->right);
        }
        if (top->left != NULL) {
            std::cout << "Pushed : " << top->left->val << endl;
            s.push(top->left);
        }
    }
}

void inorder(tree* root, std::vector<int>& traversal)
{
    if (root == NULL) {
        return;
    }

    std::stack<tree*> s;
    while (!s.empty() || root != NULL) {
        if (root != NULL) {
            s.push(root);
            std::cout << "---- Begin Loop ----" << endl;
            std::cout << "Pushed : " << root->val << " ; root set to travel left subtree" << endl;
            root = root->left;
        } else {
            tree* curr = s.top();
            std::cout << "---- Encountered NULL Node ----" << endl;
            std::cout << "Popped : " << curr->val << " ; and set root to " << curr->val << "->right" << endl;
            traversal.push_back(curr->val);
            s.pop();
            root = curr->right;
        }
    }
}

int main (int argc, char *argv[])
{

    /*
        1
       / \
      2   3
     / \ / \
    4  5 6  7
    */

    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    std::vector<int> traversal;

    preorder(root, traversal);

    std::cout << endl;
    for (auto it = traversal.begin(); it != traversal.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
