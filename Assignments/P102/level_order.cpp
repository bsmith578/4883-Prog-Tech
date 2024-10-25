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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //Container for each level's values
        vector<vector<int>> order;

        //If the tree is empty, return an empty list
        if(root == nullptr)
            return order;

        /* BFS starting at root */
        //Queue to hold unvisited nodes, starts with root
        queue<TreeNode*> q;
        q.push(root);
        
        //Search through the tree placing each new node as we come across it
        while(!q.empty()) {
            //Get queue size for each iteration. Determines number of nodes on each level
            int qs = q.size();
            //Temp vector to hold the values of each level
            vector<int> level;

            //Loop n times where n is the number of nodes at each level
            for(int i = 0; i < qs; i++) {
                //Temp node to point at each current node, pop current from q when it is visited
                TreeNode* temp = q.front();
                q.pop();

                //Check if the left and right children have values, if so place them in the queue
                if(temp->left != nullptr)
                    q.push(temp->left);
                
                if(temp->right != nullptr)
                    q.push(temp->right);
                
                //Push the current node's value onto the temp vector
                level.push_back(temp->val);
            }

            //Push level vector, containing all values form current level, onto order vector
            order.push_back(level);
        }

        return order;
    }
};