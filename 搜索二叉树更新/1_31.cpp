#include<iostream>
#include<vector>
#include<stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;

        int val = preorder.front();
        TreeNode* newnode = new TreeNode(val);
        auto it1 = preorder.begin() + 1;
        auto it2 = inorder.begin();
        int count = 0;
        while (*it2 != val)
        {
            ++it2;
            ++count;
        }
        it1 += count;
        vector<int> left1(preorder.begin() + 1, it1);
        vector<int> right1(it1, preorder.end());
        vector<int> left2(inorder.begin(), it2);
        vector<int> right2(it2 + 1, inorder.end());
        newnode->left = buildTree(left1, left2);
        newnode->right = buildTree(right1, right2);
        return newnode;
    }

    TreeNode* _buildTree2(vector<int>& preorder, vector<int>& inorder, int& rooti, int inbegin, int inend)
    {
        if (inbegin == inend)
        {
            ++rooti;
            return new TreeNode(inorder[inbegin]);
        }
        if (inbegin > inend)
            return nullptr;
        TreeNode* newnode = new TreeNode(preorder[rooti]);
        int inroot = inbegin;
        while (preorder[rooti] != inorder[inroot])
        {
            ++inroot;
        }
        ++rooti;
        newnode->left = _buildTree2(preorder, inorder, rooti, inbegin, inroot - 1);
        newnode->right = _buildTree2(preorder, inorder, rooti, inroot + 1, inend);
        return newnode;
    }

    TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        int rooti = 0;
        return _buildTree2(preorder, inorder, rooti, 0, preorder.size() - 1);
    }

    TreeNode* _buildTree3(vector<int>& inorder, vector<int>& postorder, int& rooti, int inbegin, int inend)
    {
        if (inbegin == inend)
        {
            --rooti;
            return new TreeNode(inorder[inbegin]);
        }
        if (inbegin > inend)
            return nullptr;
        TreeNode* newnode = new TreeNode(postorder[rooti]);
        int inroot = inbegin;
        while (postorder[rooti] != inorder[inroot])
        {
            ++inroot;
        }
        --rooti;
        newnode->right = _buildTree3(inorder, postorder, rooti, inroot + 1, inend);
        newnode->left = _buildTree3(inorder, postorder, rooti, inbegin, inroot - 1);       
        return newnode;
    }


    TreeNode* buildTree3(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty())
            return nullptr;
        int rooti = postorder.size() - 1;
        return _buildTree3(inorder, postorder, rooti, 0, postorder.size() - 1);
    }
};

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == nullptr)
            return v;
        stack<TreeNode*> st;
        st.push(root);
        int flag = 1;
        while (!st.empty())
        {
            TreeNode* top = st.top();
            if (flag && top->left)
            {
                st.push(top->left);
            }
            else
            {
                v.push_back(top->val);
                st.pop();
                flag = 0;
                if (top->right)
                {
                    st.push(top->right);
                    flag = 1;
                }
            }
        }
        return v;
    }

    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> v;
        if (root == nullptr)
            return v;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        int flag = 1;
        int flag2 = 1;
        while (cur || !st.empty())
        {
            while (cur && flag)
            {
                st.push(cur);               
                cur = cur->left;
            }
            
            TreeNode* top = st.top();
            if (flag2 && !top->right)
            {
                v.push_back(top->val);
                st.pop();
                cur = st.top();
                flag = 0;
            }
            else
            {
                flag = 1;
                cur = top->right;
            }
        }

    }
};


int main()
{
    vector<int> preorder;
    int arr1[] = { 5,1,2,3,4 };
    for (auto e : arr1)
    {
        preorder.push_back(e);
        ++e;
    }
    vector<int> inorder;
    int arr2[] = { 5,2,1,4,3 };
    for (auto e : arr2)
    {
        inorder.push_back(e);
        ++e;
    }
    TreeNode* ret = Solution().buildTree3(preorder, inorder);
    vector<int> v = Solution1().postorderTraversal(ret);
	return 0;
}