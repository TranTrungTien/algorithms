// ref https://leetcode.com/problems/same-tree/
#include "iostream"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool isSameNode = true;
        bool isSameValue = true;
        inorder(p, q, isSameNode, isSameValue);
        std::cout << "isSameTree: " << isSameNode << std::endl;
        std::cout << "isSameValue: " << isSameValue << std::endl;
        return isSameNode == isSameValue;
    }

    void inorder(TreeNode *p, TreeNode *q, bool &isSameNode, bool &isSameVal)
    {
        if (p == nullptr && q == nullptr)
        {
            if (isSameNode)
                isSameNode = true;
            return;
        }
        else if (p == nullptr && q != nullptr)
        {
            isSameNode = false;
            return;
        }
        else if (p != nullptr && q == nullptr)
        {
            isSameNode = false;
            return;
        }
        else
        {
            inorder(p->left, q->left, isSameNode, isSameVal);
            if (isSameVal)
                isSameVal = isSameValue(p->val, q->val);
            inorder(p->right, q->right, isSameNode, isSameVal);
        }
    }
    bool isSameValue(const int firstNodeValue, const int secondNodeValue)
    {
        return firstNodeValue == secondNodeValue;
    }

    void display(const int value, const int value2)
    {
        std::cout << value << std::endl;
        std::cout << value2 << std::endl;
    }
};

int main(int argc, char **argv)
{

    TreeNode *pl = new TreeNode(-5);
    TreeNode *rootP = new TreeNode(0, pl, nullptr);
    TreeNode *ql = new TreeNode(-8);
    TreeNode *rootQ = new TreeNode(0, ql, nullptr);
    Solution *s = new Solution();
    std::cout << s->isSameTree(rootP, rootQ) << std::endl;

    delete pl;
    delete ql;
    delete rootP;
    delete rootQ;
    delete s;
    return 0;
}