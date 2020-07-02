//Breadth first search (BFS) -> level order traversal

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(!root)       // corner case
            return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            int size = q.size();
            vector<int> level;
            while(size--)          // traverse to all nodes in this level before moving to next level
            {
                TreeNode *curr = q.front() ;    
				q.pop();
                level.push_back(curr->val);
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans.push_back(level);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
