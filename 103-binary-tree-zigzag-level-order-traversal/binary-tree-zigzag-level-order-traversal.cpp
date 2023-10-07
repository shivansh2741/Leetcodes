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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){ 
        bool forward = true;

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        if(!root)return res;

        while(!q.empty()){
            int si = q.size();

            vector<int> level;
            while(si--){
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(!forward){
                reverse(level.begin() , level.end());
            }

            res.push_back(level);
            forward = !forward;
        }   
        return res;  
    }
};