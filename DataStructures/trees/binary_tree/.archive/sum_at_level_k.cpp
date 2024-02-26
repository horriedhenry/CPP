#include <iostream>
#include <queue>

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

int sum_at_k_level(tree* root, int level_K) {
    if (level_K < 0 || root == NULL) {
        return -1;
    }
    std::queue<tree*> q;
    int sum = 0;
    int curr_level = 0;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        tree* curr_node = q.front();
        q.pop();
        if (curr_node != NULL) {
            if (curr_level == level_K) {
                sum+= curr_node->val;
            }
            if (curr_node->left != NULL) {
                q.push(curr_node->left);
            }
            if (curr_node->right != NULL) {
                q.push(curr_node->right);
            }
        } 
        else if (!q.empty() && curr_node == NULL) {
            curr_level++;
            q.push(NULL);
        }
    }
    return sum;
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
    int level = 1;
    std::cout << sum_at_k_level(root, level);
    return 0;
}
