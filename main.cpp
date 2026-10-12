#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert a node into BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

// Find kth largest element using reverse inorder traversal
int kthLargest(TreeNode* root, int& cnt) {
    if (root == nullptr) {
        return -1;
    }
    
    // Traverse right subtree first (larger elements)
    int right = kthLargest(root->right, cnt);
    if (cnt == 0) {
        return right;
    }
    
    // Process current node
    cnt--;
    if (cnt == 0) {
        return root->val;
    }
    
    // Traverse left subtree
    return kthLargest(root->left, cnt);
}

int main() {
    vector<int> nodes(7);
    for (int i = 0; i < 7; i++) {
        cin >> nodes[i];
    }
    
    int cnt;
    cin >> cnt;
    
    // Build BST from level-order input
    TreeNode* root = nullptr;
    for (int val : nodes) {
        root = insert(root, val);
    }
    
    // Find kth largest element
    int result = kthLargest(root, cnt);
    cout << result << endl;
    
    return 0;
}