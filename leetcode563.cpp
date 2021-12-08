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
    void dfs(TreeNode* node,int &sum){
        if(node==NULL)
            return;
        sum += node->val;
        dfs(node->left,sum);
        dfs(node->right,sum);
    }
    int findTilt(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_sum =0, right_sum =0;
       
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int len = q.size();
            
            for(int i=0;i<len;i++){
                //cout << "123\n";
                TreeNode* node = q.front();
                q.pop();
                
                int l_sum=0, r_sum = 0;
                dfs(node->left,l_sum);
                dfs(node->right,r_sum);
                //cout << "node: " << node->val << " l " << l_sum << " r " << r_sum << endl;
                ans += abs(l_sum-r_sum);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
      
        return ans;
    }
};
