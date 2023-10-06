#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }

private:
    int depth(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }

        int leftDepth = depth(node->left, diameter);
        int rightDepth = depth(node->right, diameter);

        // Calculate the current diameter
        diameter = max(diameter, leftDepth + rightDepth);

        // Return the depth of the current node
        return 1 + max(leftDepth, rightDepth);
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int treeDiameter = solution.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree is: " << treeDiameter << endl;

    return 0;
}
