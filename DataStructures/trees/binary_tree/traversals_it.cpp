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

typedef struct Node
{
    tree* root;
    bool visit_left = false;
    bool visit_right = false;
} Node;

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

void postorder(tree* root)
{
    std::stack<tree*> call_stack;
    std::stack<tree*> result_stack;
    call_stack.push(root);
    while (!call_stack.empty()) {
        tree* top = call_stack.top();
        call_stack.pop();
        result_stack.push(top);
        if (top->left != NULL) {
            call_stack.push(top->left);
        }
        if (top->right != NULL) {
            call_stack.push(top->right);
        }
    }

    while (!result_stack.empty()) {
        std::cout << result_stack.top()->val << " ";
        result_stack.pop();
    }
}

void postorder_(tree* root)
{
    if (root == NULL) {
        return;
    }
    std::stack<tree*> s;
    s.push(root);
    while(!s.empty()) {
        tree* top = s.top();
        if (top == NULL) {
            s.pop();
            std::cout << s.top()->val << " ";
            s.pop();
            continue; // Question for chatgpt : will this indicate that just continue looping and dont execute anything after this current
            // if (top == NULL) statement
        }

        s.push(NULL);

        if (top->right != NULL) {
            s.push(top->right);
        }
        if (top->left != NULL) {
            s.push(top->left);
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

    postorder_(root);

    std::cout << endl;
    for (auto it = traversal.begin(); it != traversal.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
