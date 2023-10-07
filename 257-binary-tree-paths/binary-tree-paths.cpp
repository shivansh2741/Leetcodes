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
    void solve(TreeNode* root,string path,vector<string>& res){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            path += to_string(root->val);
            res.push_back(path);
        }

        path += to_string(root->val);
        path += "->";

        solve(root->right,path,res);
        solve(root->left,path,res);
        
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;

        solve(root,path,res);

        return res;    
    }
};