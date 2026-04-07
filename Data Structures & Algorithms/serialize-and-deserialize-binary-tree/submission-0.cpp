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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        vector<string> res;
        dfsSerialize(root, res);
        return join(res,",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<string> ser = split(data,',');
        int i = 0;
      return  dfsDeserialize(ser,i);
    }

    private:
    void dfsSerialize(TreeNode* root,vector<string>& res)
    {
        if(!root)
        {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(root->val));
        dfsSerialize(root->left,res);
        dfsSerialize(root->right,res);
    }

    TreeNode* dfsDeserialize(vector<string> &val,int& i)
    {
        if(val[i] == "N")
        {
            i++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(val[i]));
        i++;
        node->left = dfsDeserialize(val,i);
        node->right = dfsDeserialize(val,i);
        return node;
    }

    vector<string> split(const string &data,char delim)
    {
        vector<string> ele;
        stringstream ss(data);
        string item;
        while(getline(ss,item,delim))
        {
            ele.push_back(item);
        }

        return ele;
    }

    string join(vector<string>& res,const string &delim)
    {
        ostringstream s;

        for(const auto &i : res)
        {
            if(&i != &res[0])
            {
                s << delim;
            }
            s << i;
        }

        return s.str();
    }
};
