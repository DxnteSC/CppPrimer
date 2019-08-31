#include <string>

class TreeNode
{
public:
    TreeNode(const std::string& s, int i, TreeNode& t): value(s), count(i), left(t.left), right(t.right) {}
    TreeNode(const TreeNode& tn)
    {
        value = tn.value;
        count = tn.count;
        left = tn.left;
        right = tn.right;
    }
    TreeNode& operator=(const TreeNode&);
private:
    std::string value;
    int count;
    TreeNode* left;
    TreeNode* right;
};

TreeNode& TreeNode::operator=(const TreeNode& rhs)
{
    value = rhs.value;
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    return *this;
}

class BinStrTree {
public:
    BinStrTree() : root(new TreeNode()) { }
    BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)) { }
    BinStrTree& operator=(const BinStrTree&);
    ~BinStrTree() { delete root; }
private:
    TreeNode* root;
};

BinStrTree& BinStrTree::operator=(const BinStrTree& rhs)
{
    auto temp = rhs.root;
    delete root;
    root = temp;
    return *this;
}
