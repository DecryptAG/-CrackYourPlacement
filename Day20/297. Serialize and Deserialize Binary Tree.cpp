// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "#,";
        queue<TreeNode*> q;
        q.push(root);
        string ans = "";
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node==NULL)
                    ans+="#,";
                else
                {
                    ans+=to_string(node->val);
                    ans+=",";
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.length();
        string temp = "";
        int i = 0;
        while(data[i]!=',')
        {
            temp+=data[i];
            i++;
        }
        if(temp!="#")
        {
            TreeNode* root = new TreeNode(stoi(temp));
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                TreeNode* node = q.front();
                q.pop();

                temp = "";
                i++;
                while(data[i]!=',')
                {
                    temp+=data[i];
                    i++;
                }
                if(temp!="#")
                {   
                    TreeNode* l = new TreeNode(stoi(temp));
                    node->left = l;
                    q.push(l);
                }
                else
                {
                    node->left = NULL;
                }


                temp = "";
                i++;
                while(data[i]!=',')
                {
                    temp+=data[i];
                    i++;
                }
                if(temp!="#")
                {   
                    TreeNode* r = new TreeNode(stoi(temp));
                    node->right = r;
                    q.push(r);
                }
                else
                {
                    node->right = NULL;
                }
            }
            return root;
        }
        else
            return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));