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
    int ans = 0;

    void sumHelper(TreeNode* root,int num){
        if(root==NULL){
            return;
        }
        num = num*10 + root->val;
        if(root->left==NULL && root->right==NULL){
            ans = ans + num;
            return;
        }
        sumHelper(root->left,num);
        sumHelper(root->right,num);
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        sumHelper(root,0);
        return ans;
    }
};
