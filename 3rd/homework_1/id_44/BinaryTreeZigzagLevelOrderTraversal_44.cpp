/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<stack<TreeNode*>> stks{{},{}};
        int stk_idx = 0;
        auto curr_stk = &stks[stk_idx];
        curr_stk->push(root);
        while (curr_stk->size()) {
            vector<int> layer;
            stk_idx = 1 - stk_idx;
            auto next_stk = &stks[stk_idx];
            while (!curr_stk->empty()) {
                auto p_node = curr_stk->top();
                auto p_ch1 = stk_idx ? p_node->left : p_node->right;
                if (p_ch1)
                    next_stk->push(p_ch1);
                auto p_ch2 = stk_idx ? p_node->right : p_node->left;
                if (p_ch2)
                    next_stk->push(p_ch2);
                layer.push_back(p_node->val);
                curr_stk->pop();
            }
            res.push_back(layer);
            curr_stk = next_stk;
        }
        return res;
    }
};
