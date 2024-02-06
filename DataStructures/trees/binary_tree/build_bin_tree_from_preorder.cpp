#include <iostream>
#include <stack>
#include <vector>

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
    if (root == NULL) { return; }
    std::stack<tree*> st;
    st.push(root);
    while (!st.empty()) {
        root = st.top();
        st.pop();
        std::cout << root->val << " ";
        if (root->right != NULL) {
            st.push(root->right);
        }
        if (root->left != NULL) {
            st.push(root->left);
        }
    }
}

tree* build_tree(const std::vector<int>& nodes, int& it) {
    it++;
    if (it >= nodes.size() || nodes[it] == -1) {
        // while incrementing the iterator if it goes out of bounds return NULL
        return NULL;
    }
    tree* newNode = new tree(nodes[it]);
    newNode->left = build_tree(nodes, it);
    newNode->right = build_tree(nodes, it);
    return newNode;
}

int main (int argc, char *argv[]) {
    // preorder list of a binary tree.
    std::vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int itr = -1;
    tree* root = build_tree(nodes,itr);
    preorder(root);
    return 0;
}
