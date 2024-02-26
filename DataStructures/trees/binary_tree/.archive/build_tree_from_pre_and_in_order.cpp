#include <iostream>
#include <vector>

typedef struct tree {
    int val;
    struct tree* left;
    struct tree* right;
    tree(int data) {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
} tree;

void preorder_traversal(tree* root) {
    if (root == NULL) {
        return;
    }
    std::cout << root->val << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(tree* root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    std::cout << root->val << " ";
    inorder_traversal(root->right);
}

int search(std::vector<int>& inorder, int start, int end, int key) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == key) {
            return i;
        }
    }
    return -1;
}

tree* build_tree(std::vector<int>& preorder, std::vector<int>& inorder, int start, int end) {
    static int preorder_index = 0;
    if (start > end) {
        return NULL;
    }
    int curr_root_ele = preorder[preorder_index];
    preorder_index++;
    tree* root = new tree(curr_root_ele);
    if (start == end) {
        return root;
    }
    int pos = search(inorder, start, end, curr_root_ele);
    root->left = build_tree(preorder, inorder, start, pos - 1);
    root->right = build_tree(preorder, inorder, pos + 1, end);
    return root;
}

int main (int argc, char *argv[]) {
    std::vector<int> preorder = {1,2,4,3,5};
    std::vector<int> inorder = {4,2,1,5,3};
    tree* root = build_tree(preorder, inorder, 0, preorder.size() - 1);
    preorder_traversal(root);
    std::cout << std::endl;
    return 0;
}
