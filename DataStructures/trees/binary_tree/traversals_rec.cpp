#include <iostream>
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

std::vector<int> process;

void preorder(tree* root) 
{
    if (root == NULL) {
        return;
    }
    process.push_back(root->val);
    std::cout << "Current root : " << root->val << " ; processing root; going left"<< endl;
    preorder(root->left);
    std::cout << "Current root : " << root->val << " ; done traversing left subtree; going right"<< endl;
    preorder(root->right);
    std::cout << "Current root : "<< root->val << " ; done traversing left and right subtree ; backtrack" << endl;
}


void inorder(tree* root) 
{
    if (root == NULL) {
        return;
    }
    std::cout << "Current root : " << root->val << " ; going left" << endl;
    inorder(root->left);
    process.push_back(root->val);
    std::cout << "Process root : " << root->val << " ; done traversing left subtree; going right" << endl;
    inorder(root->right);
    std::cout << "Current root : " << root->val << " ; done processing left and right subtree " << endl;
}

void postorder(tree* root) 
{
    if (root == NULL) {
        return;
    }
    std::cout << "Current root : " << root->val << " ; going left" << endl;
    postorder(root->left);
    std::cout << "Current root : " << root->val << " ; going right" << endl;
    postorder(root->right);
    process.push_back(root->val);
    std::cout << "Current root : " << root->val << " ; done traversing left and right subtree; processing root " << endl;
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

    postorder(root);

    std::cout << endl;
    for (auto it = process.begin(); it != process.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
