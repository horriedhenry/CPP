#include <iostream>
#include <queue>

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

void bfs_traversal(tree* root)
{
    // Alias : Level Order Traversal
    if (root == NULL) {
        return;
    }

    std::queue<tree*> q;
    q.push(root);
    while (!q.empty()) {
        tree* curr_root = q.front();
        q.pop();
        std::cout << curr_root->val << " ";
        if (curr_root->left != NULL) {
            q.push(curr_root->left);
        }
        if (curr_root->right != NULL) {
            q.push(curr_root->right);
        }
    }
}

bool bfs_search(tree* root, int key) {
    if (root == NULL) {
        return false;
    }
    std::queue<tree*> q;
    q.push(root);
    while (!q.empty()) {
        tree* curr_node = q.front();
        q.pop();

        if (curr_node->val == key) {
            return true;
        }

        if (curr_node->left != NULL) {
            q.push(curr_node->left);
        } 
        if (curr_node->right != NULL) {
            q.push(curr_node->right);
        }
    }
    return false;
}

int main (int argc, char *argv[])
{

    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    bfs_traversal(root);
    std::cout << endl;

    if (bfs_search(root, 9) == true) {
        std::cout << "Found" << endl;
    } else {
        std::cout << "Not Found" << endl;
    }

    return 0;
}
