/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // if(root == nullptr)
        // {
        //     return 0;
        // }
        // return 1 + max(maxDepth(root->left),maxDepth(root->right));

        stack<pair<TreeNode*,int>> s;
        s.push({root,1});
        int res = 0;
        while(!s.empty())
        {
            pair<TreeNode*,int> node = s.top();
            s.pop();
            TreeNode* Node = node.first;
            int depth = node.second;
            if(Node != nullptr)
            {
                res = max(res,depth);
                s.push({Node->left,depth + 1});
                s.push({Node->right,depth + 1});
            }

        }
        return res;
    }
};
