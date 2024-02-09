#include <algorithm>
#include <iostream>

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

tree* build_tree() {
    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);
    root->right->right->right = new tree(8);
    root->right->right->right->right = new tree(9);
    return root;
}

int count_nodes(tree* root) {
    if (root == NULL) {
        return 0;
    }
    int left_sub_tree_sum = count_nodes(root->left);
    int right_sub_tree_sum = count_nodes(root->right);
    int add_root_sum = 1;
    return left_sub_tree_sum + right_sub_tree_sum + add_root_sum;
}

int sum_of_all_nodes(tree* root) {
    if (root == NULL) {
        return 0;
    }
    int add_left_sub_tree_value = sum_of_all_nodes(root->left);
    int add_right_sub_tree_value = sum_of_all_nodes(root->right);
    int add_root_val = root->val;
    return add_left_sub_tree_value + add_right_sub_tree_value + add_root_val;
}

int height(tree* root) {
    if (root == NULL) {
        return 0;
    }
    int height_of_left_subtree = height(root->left);
    int height_of_right_subtree = height(root->right);
    int add_root_height = 1;
    return std::max(height_of_left_subtree, height_of_right_subtree) + 1;
    // if left sub-tree returns a height 3 and right return 2 consider 3
    // because that sub-tree has the deepest node.
}

int diameter(tree* root) {
    // https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/
    // TODO
    return 1;
}

int main (int argc, char *argv[]) {
    // tree
    /*

         1   
       /   \
      2     3
     / \   / \ 
    4   5  6  7
               \
                8
                 \
                  9

    */

    tree* root = build_tree();
    std::cout << diameter(root) << endl;
    return 0;
}
