#include <iostream>
template <typename T>
struct BSTNode
{
    struct BSTNode *left;
    struct BSTNode *right;
    T val;
    BSTNode(const T &x)
        : left(nullptr), right(nullptr), val(x)
    {
    }
};

template <typename T>
class BSTree
{
    typedef struct BSTNode<T> Node;

public:
    BSTree()
        : _root(nullptr)
    {
    }
    bool insert(const T &x)
    {
        if (_root == nullptr)
        {
            _root = new Node(x);
            return true;
        }
        Node *cur = _root;
        Node *parent = nullptr;
        while (cur)
        {
            parent = cur;
            if (x < cur->val)
            {
                cur = cur->left;
            }
            else if (x > cur->val)
            {
                cur = cur->right;
            }
            else
            {
                return false;
            }
        }
        if (x < parent->val)
        {
            parent->left = new Node(x);
        }
        else
        {
            parent->right = new Node(x);
        }
        return true;
    }
    bool find(const T& val){
        Node *cur = _root;
        while (cur)
        {
            if (x < cur->val)
            {
                cur = cur->left;
            }
            else if (x > cur->val)
            {
                cur = cur->right;
            }
            else
            {
                return true;
            }
        }
    }
    bool erase(const T& val){
        
    }
    void Inorder()
    {
        _InOrder(_root);
    }

private:
    void _InOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        _InOrder(root->left);
        std::cout << root->val << std::endl;
        _InOrder(root->right);
    }

private:
    Node *_root;
};
