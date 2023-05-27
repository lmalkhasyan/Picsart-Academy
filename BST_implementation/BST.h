#ifndef BST_H
#define BST_H
#include <functional>

template <typename T, typename Compare=std::less<T>>
class BST
{
public:
    using value_type = T;
    using referance_type = value_type&;
    using const_reference = const value_type&;
    using key_compare = Compare;
    using size_type = size_t;
private:
    struct BST_node
    {
        using node_type = BST_node;
        using node_pointer = node_type *;
        value_type data;
        node_pointer left;
        node_pointer right;
        BST_node(value_type t = value_type(), node_pointer l = nullptr, node_pointer r = nullptr) 
        : data{t}, left{f}, right{r} {}
    };

public:
    using node_type = BST_node;
    using node_pointer = node_type *;

private:
    node_type *root;
    key_compare value_compare;
    size_type size;

public:
    BST()
    :root{nullptr}, value_compare{}, size{} {}

    BST(const BST<T>& rhs) : root{nullptr}, size{0}
    {
        node_pointer temp = clone_help(rhs.root); 
        this->root = temp;
        this->size = rhs.size;
    }

    BST(BST<T>&& rhs) : root{nullptr}, size{}
    {
        this->root = rhs.root;
        this->size = rhs.size;
        rhs.root = nullptr;
        rhs.size = 0;
    }
    ~BST()
    {
        destruct_tree(root);
        this->root = nullptr;
        this->size = 0;
    }

    BST& operator=(const BST<T>& rhs)
    {
        if(this != &rhs) 
        {
            BST tmp(rhs);
            swap(*this, tmp);
        }
        return *this;
    }
    BST& operator=(BST<T>&& rhs)
    {
        if(this != &rhs)
        {
            BST tmp(std::move(rhs));
            swap(*this, tmp);
        }
        return *this;
    }

    bool find(const_reference target)
    {
        return find_help(root, target);
    }

    bool search_iterative(const_reference target)
    {
        if(!root)
            return false;
        node_pointer temp = root;
        while(temp != nullptr)
        {
            if(value_compare(target,temp->data))
            {
                temp = temp->left;
            }
            else if(value_compare(temp->data, target))
            {
                temp = temp->right;
            }
            else
                return true;
        }
        return false;
    }

    value_type getMin() // undefined if empty tree
    {
        return getMin_help(root)
    }

    value_type getMin_iterative() // undefined if empty tree
    {
        node_pointer temp = root;
        while(temp->left)
        {
            temp = temp->left;
        }
        return temp->data;
    }

    value_type getMax() // undefined if empty tree
    {
        return getMax_help(root)
    }

    value_type getMax_iterative() // undefined if empty tree
    {
        node_pointer temp = root;
        while(temp->right)
        {
            temp = temp->right;
        }
        return temp->data;
    }

    bool empty()
    {
        return this->root;
    }

    size_type getHeight()
    {
        return getHeight_help(root)
    }

    void clear()
    {
        destruct_tree(root);
        root = nullptr;
        size = 0;
    }

    size_type size()
    {
        return this->size;
    }

    bool insert(const value_type &data)
    {
        // todo;
    }

    bool erase(const value_type &data)
    {
        // todo;
    }

    void swap(BST &other)
    {
        using std::swap;
        
        swap(this->root, other.root);
        swap(this->size, other.size);
    }

    bool contains(value_type &key)
    {
        // todo
    }

    size_type count()
    {
        //todo
    }

private: // helpers
    bool find_help(node_pointer root, const_reference target)
    {
        if(!root)
            return false;
        if(value_compare(root->data,target))
        {
            return search_help(root->right, target);
        }
        else if(value_compare(target, root->data))
        {
            return search_help(root->left, target);
        }
        else 
            return true;
    }

    value_type getMin_help(node_pointer root) // undifined in empty tree;
    {
        if(root->left == nullptr)
        {
            return root->data;
        }
        return getMin_help(root->left);
    }

    value_type getMax_help(node_pointer root) // undifined in empty tree;
    {
        if(root->right == nullptr)
        {
            return root->data;
        }
        return getMax_help(root->right);
    }

    node_pointer clone_help(node_pointer root)
    {
        if (!root)
            return nullptr;
        return new TreeNode(root->val, clone_help(root->left), clone_help(root->right));

    }

    void destruct_tree(node_pointer root)
    {
        if(!root)
            return;
        destruct_tree(root->left);
        destruct_tree(root->right);
        delete(root);
        root = nullptr;
        size = 0;

    }

    node_pointer getSuccessor()
    {
        // todo
    }

    node_pointer getPredecessor()
    {
        // todo
    }

    size_type getHeight_help(node_pointer root)
    {
        if(!root)
            return -1;
        return 1 + std::max(getHeight_help(root->left), getHeight_help(root->right));
    }
};



template<class T, class Compare>
void swap( BST<T, Compare>& lhs, BST<T, Compare>& rhs )
{
    lhs.swap(rhs);
}


#endif