class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        uint16_t leftH = maxDepth(root->left);
        uint16_t rightH = maxDepth(root->right);
        return leftH > rightH ? ++leftH : ++rightH;
    }
};
