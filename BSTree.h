#include <iostream>
#include <algorithm>
template <typename T>
struct BSTNode
{
    struct BSTNode *left;
    struct BSTNode *right;
    T key;
    BSTNode(const T &x)
        : left(nullptr), right(nullptr), key(x)
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
            if (x < cur->key)
            {
                parent = cur;
                cur = cur->left;
            }
            else if (x > cur->key)
            {
                parent = cur;
                cur = cur->right;
            }
            else
            {
                return false;
            }
        }
        if (x < parent->key)
        {
            parent->left = new Node(x);
        }
        else
        {
            parent->right = new Node(x);
        }
        return true;
    }
    bool find(const T &x)
    {
        Node *cur = _root;
        while (cur)
        {
            if (x < cur->key)
            {
                cur = cur->left;
            }
            else if (x > cur->key)
            {
                cur = cur->right;
            }
            else
            {
                return true;
            }
        }
    }
    bool erase(const T &key)
    {
        Node *parent = nullptr;
        Node *cur = _root;
        while (cur)
        {
            if (key < cur->key)
            {
                parent = cur;
                cur = cur->left;
            }
            else if (key > cur->key)
            {
                parent = cur;
                cur = cur->right;
            }
            else
            {
                if (cur->left == nullptr)
                {
                    if (cur == _root)
                    {
                        _root = cur->right;
                    }
                    else
                    {
                        if (cur == parent->left)
                            parent->left = cur->right;
                        else
                            parent->right = cur->right;
                    }

                    delete cur;
                    cur = nullptr;
                }
                else if (cur->right == nullptr)
                {
                    if (cur == _root)
                    {
                        _root = cur->left;
                    }
                    else
                    {
                        if (cur == parent->left)
                            parent->left = cur->left;
                        else
                            parent->right = cur->left;
                    }

                    delete cur;
                    cur = nullptr;
                }
                else
                {
                    Node *rightMinParent = cur;
                    Node *rightMin = cur->right;
                    while (rightMin->left)
                    {
                        rightMinParent = rightMin;
                        rightMin = rightMin->left;
                    }
                    std::swap(rightMin->key, cur->key);
                    if (rightMin == rightMinParent->left)
                    {
                        rightMinParent->left = rightMin->right;
                    }
                    else
                    {
                        rightMinParent->right = rightMin->right;
                    }
                    delete rightMin;
                    rightMin = nullptr;
                }
                return true;
            }
        }
        return false;
    }
    void Inorder()
    {
        _InOrder(_root);
        std::cout << std::endl;
    }
    bool findR(const T &key)
    {
        return _findR(_root, key);
    }
    bool insertR(const T &key)
    {
        return _insertR(_root, key);
    }
    bool eraseR(const T &key)
    {
        return _eraseR(_root, key);
    }
    ~BSTree()
    {
        _destroy(_root);
    }
    BSTree(const BSTree<T>& tree){
        _root = _copy(tree._root);
    }
    BSTree& operator=(BSTree tree){
        std::swap(_root, tree._root);
        return *this;
    }
private:
    Node* _copy(Node* root){
        if(root == nullptr){
            return root;
        }
        Node *node = new Node(root->key);
        node->left = _copy(root->left);
        node->right = _copy(root->right);
        return node;
    }
    void _destroy(Node*& root){
        if(root == nullptr){
            return;
        }
        _destroy(root->left);
        _destroy(root->right);
        delete root;
        root = nullptr;
    }
    bool _eraseR(Node *&root, const T &key)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (key < root->key)
        {
            return _eraseR(root->left, key);
        }
        else if (key > root->key)
        {
            return _eraseR(root->right, key);
        }
        else
        {
            //是通过更改连接的方式进行删除，所以原结点需要进行保存删除
            Node *del = root;
            if (root->left == nullptr)
            {
                root = root->right;
            }
            else if (root->right == nullptr)
            {
                root = root->left;
            }
            else
            {
                //找到右树的最小结点进行替换
                Node *rightMin = root->right;
                while (rightMin->left)
                {
                    rightMin = rightMin->left;
                }
                std::swap(root->key, rightMin->key);
                //已将值交换至右树，故此递归删除右树的对应节点即可
                return _eraseR(root->right, key);
            }
            delete del;
            return true;
        }
    }
    bool _insertR(Node *&root, const T &key)
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return true;
        }
        if (key < root->key)
        {
            return _insertR(root->left, key);
        }
        else if (key > root->key)
        {
            return _insertR(root->right, key);
        }
        else
        {
            return false;
        }
    }
    bool _findR(Node *root, const T &key)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (key < root->key)
        {
            _findR(root->left);
        }
        else if (key > root->key)
        {
            _findR(root->right);
        }
        else
        {
            return true;
        }
    }
    void _InOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        _InOrder(root->left);
        std::cout << root->key << " ";
        _InOrder(root->right);
    }

private:
    Node *_root;
};
