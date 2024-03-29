#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <queue>

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
    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(tree* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

void postorder(tree* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << " ";
}

void level_order(tree* root) {
    std::queue<tree*> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        tree* curr = q.front();
        q.pop();
        if (curr != NULL) {
            std::cout << curr->val << " ";
            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        else if (!q.empty()) {
            // level_order :
            // 1
            // 2 3
            // 4 5 6 7
            // NULL == 1 level is complete
            std::cout << endl;
            q.push(NULL);
        }
    }
}

int main (int argc, char *argv[]) {
    tree* root = new tree(1);
    tree* root_left = new tree(2);
    tree* root_right = new tree(3);
    tree* root_left_left = new tree(4);
    tree* root_left_right = new tree(5);
    tree* root_right_left = new tree(6);
    tree* root_right_right = new tree(7);

    // build this tree
    /*

         1   
       /   \
      2     3
     / \   / \ 
    4   5  6  7

    */
    root->left = root_left;
    root->right = root_right;
    root->left->left = root_left_left;
    root->left->right = root_left_right;
    root->right->left = root_right_left;
    root->right->right = root_right_right;

    // Traversals...
    // TODO : Traversal (iterative approach).
    std::cout << "preorder  : ";
    preorder(root);
    std::cout << endl;
    std::cout << "inorder   : ";
    inorder(root);
    std::cout << endl;
    std::cout << "postorder : ";
    postorder(root);
    std::cout << endl;
    std::cout << "level_order : " << endl;
    level_order(root);
    std::cout << endl;

    // or .. another method would be
    // tree* root = new tree(1);
    // root->left = new tree(2);
    // root->right = new tree(3);
    // root->left->left = new tree(4);
    // root->left->right = new tree(5);
    // root->left->left->right = new tree(6);

    // std::cout << root->val << std::endl; // 1
    // std::cout << root->left->val << std::endl; // 2
    // std::cout << root->right->val << std::endl; // 3
    // std::cout << root->left->left->val << std::endl; // 4
    // std::cout << root->left->right->val << std::endl; // 5
    // std::cout << root->left->left->right->val << std::endl; // 6
    return 0;
}
