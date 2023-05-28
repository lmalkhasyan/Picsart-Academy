#ifndef BST_H
#define BST_H
#include <functional>
#include <stdexcept>
#include <iostream>
#include <string>
#include <cstring>

template <typename T, typename Compare=std::less<T>>
class BST
{
public:
    using value_type = T;
    using reference_type = value_type&;
    using const_reference = const value_type&;
    using key_compare = Compare;
    using size_type = std::size_t;

private:
    struct BST_node
    {
        using node_type = BST_node;
        using node_pointer = node_type *;
        value_type data;
        node_pointer left;
        node_pointer right;
        BST_node(value_type t = value_type(), node_pointer l = nullptr, node_pointer r = nullptr) 
        : data{t}, left{l}, right{r} {}
    };

public:
    using node_type = BST_node;
    using node_pointer = node_type *;

private:
    node_type *root;
    key_compare value_compare;
    size_type node_count;

public:
    BST() :root{nullptr}, value_compare{}, node_count{0} {}

    BST(const BST<T>& rhs) : root{nullptr}, node_count{0}
    {
        node_pointer temp = clone_help(rhs.root); 
        this->root = temp;
        this->node_count = rhs.node_count;
    }

    BST(BST<T>&& rhs) : root{nullptr}, node_count{0}
    {
        this->root = rhs.root;
        this->node_count = rhs.node_count;
        rhs.root = nullptr;
        rhs.node_count = 0;
    }
    ~BST()
    {
        destruct_tree(root);
        this->root = nullptr;
        this->node_count = 0;
    }

    BST& operator=(const BST<T>& rhs)
    {
        if(this != &rhs) 
        {
            BST tmp(rhs);
            this->swap(tmp);
        }
        return *this;
    }
  
    BST& operator=(BST<T>&& rhs)
    {
        if(this != &rhs)
        {
            BST tmp(std::move(rhs));
            this->swap(tmp);
        }
        return *this;
    }

    bool find(const_reference target) const
    {
        return find_help(root, target);
    }

    bool search_iterative(const_reference target) const
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

    bool empty() const noexcept
    {
        return !(this->root);
    }

    size_type getHeight() const
    {
        return getHeight_help(root);
    }

    void clear()
    {
        destruct_tree(root);
        root = nullptr;
        node_count = 0;
    }

    size_type size() const noexcept
    {
        return this->node_count;
    }

    bool insert(const_reference data)
    {
        try
        {
            root = insert_help(root, data);
            ++node_count;
            return true;
        }
        catch (...)
        {
            return false;
        }
    }

    void erase(const_reference data)
    {
        root = erase_help(root, data);
    }

    void swap(BST &other) noexcept
    {
        using std::swap;
        
        swap(this->root, other.root);
        swap(this->node_count, other.node_count);
    }

    bool contains(const_reference key) const
    {
        return find_help(root, key);
    }

    void preorder()
    {
        preorder_help(root);
    }

    void inorder()
    {
        inorder_help(root);
    }

    void postorder()
    {
        postorder_help(root);
    }

    std::string serialize() 
    {
        std::string result;
        preorder_serialize(root, result);
        return result;
    }

    void deserialize(const std::string &data) 
    {
        for (size_t i = 0; i < data.size(); i += sizeof(int)) 
        {
            value_type val;
            memcpy(&val, &data[i], sizeof(value_type));
            this->insert(val);
        }
    }


private: // helpers
    bool find_help(node_pointer root, const_reference target) const
    {
        if(!root)
            return false;
        if(value_compare(root->data,target))
        {
            return find_help(root->right, target);
        }
        else if(value_compare(target, root->data))
        {
            return find_help(root->left, target);
        }
        else 
            return true;
    }

    node_pointer getMin_help(node_pointer root) const
    {
        if(!root)
            return nullptr;
        if(root->left == nullptr)
        {
            return root;
        }
        return getMin_help(root->left);
    }

    node_pointer getMax_help(node_pointer root) const
    {
        if(!root)
            return nullptr;
        if(root->right == nullptr)
        {
            return root;
        }
        return getMax_help(root->right);
    }

    node_pointer getMin_iterative() const 
    {
        if(!root)
            return nullptr;
        node_pointer temp = root;
        while(temp->left)
        {
            temp = temp->left;
        }
        return temp;
    }

    node_pointer getMax_iterative() const
    {
        if(!root)
            return nullptr;
        node_pointer temp = root;
        while(temp->right)
        {
            temp = temp->right;
        }
        return temp;
    }

    node_pointer clone_help(node_pointer root) const
    {
        if (!root)
            return nullptr;
        return new node_type(root->data, clone_help(root->left), clone_help(root->right));

    }

    void destruct_tree(node_pointer root)
    {
        if(!root)
            return;
        destruct_tree(root->left);
        destruct_tree(root->right);
        delete(root);
        root = nullptr;
    }

    node_pointer getSuccessor(node_pointer root, node_pointer target) const
    {
        if(!root)
            return nullptr;
        if(target->right != nullptr)
            return getMin_help(target->right);

        node_pointer succ = nullptr;
        node_pointer curr = root;
        while(curr != nullptr)
        {
            if(value_compare(target->data, curr->data))
            {
                succ = curr;
                curr = curr->left;
            }
            else if(value_compare(curr->data, target->data))
            {
                curr = curr->right;
            }
            else
            {
                break;
            }
        }
        return succ;
    }

    node_pointer getPredecessor(node_pointer root, node_pointer target) const
    {
        if(!root)
            return nullptr;
        if(target->left != nullptr)
            return getMax_help(target->left);

        node_pointer pred = nullptr;
        node_pointer curr = root;
        while(curr != nullptr)
        {
            if(value_compare(target->data, curr->data))
            {
                curr = curr->left;
            }
            else if(value_compare(curr->data, target->data))
            {
                pred = curr;
                curr = curr->right;
            }
            else
            {
                break;
            }
        }
        return pred;
    }

    size_type getHeight_help(node_pointer root) const
    {
        if(!root)
            return 0;
        return 1 + std::max(getHeight_help(root->left), getHeight_help(root->right));
    }

    node_pointer insert_help(node_pointer root, const_reference data)
    {
        if(!root)
            return new node_type(data);
        if(value_compare(root->data, data))
        {
            root->right = insert_help(root->right, data);
        }
        else if (value_compare(data, root->data))
        {
            root->left = insert_help(root->left, data);
        }
        else
        {
            throw std::runtime_error("Duplicate value"); 
        }
        return root;
    }

    node_pointer erase_help(node_pointer root, const_reference data)
    {
        if(!root)
            return nullptr;
        
        if(value_compare(root->data, data))
        {
            root->right = erase_help(root->right, data);
        }
        else if(value_compare(data, root->data))
        {
            root->left = erase_help(root->left, data);
        }
        else
        {
            if(!root->left && !root->right)
            {
                delete root;
                --node_count;
                return nullptr;
            }
            else if(root->left == nullptr)
            {
                node_pointer temp = root->right;
                --node_count;
                delete root;
                return temp;
            }
            else if(root->right == nullptr)
            {
                node_pointer temp = root->left;
                delete root;
                --node_count;
                return temp;
            }
            node_pointer successor = getMin_help(root->right);
            root->data = successor->data;
            root->right = erase_help(root->right, successor->data);
        }
        return root;
    }

    void preorder_help(node_pointer root)
    {
        if(!root)
            return;
        std::cout << root->data << " ";
        preorder_help(root->left);
        preorder_help(root->right);
    }

    void inorder_help(node_pointer root)
    {
        if(!root)
            return;
        inorder_help(root->left);
        std::cout << root->data << " ";
        inorder_help(root->right);

    }

    void postorder_help(node_pointer root)
    {
        if(!root)
            return;
        postorder_help(root->left);
        postorder_help(root->right);
        std::cout << root->data << " ";

    }
    
    void preorder_serialize(node_pointer root, std::string &result)    
    {
        if(!root)
            return ;
        char *ptr = (char *)&root->data;
        for(int i = 0; i < sizeof(value_type); ++i)
        {
            result.push_back(*(ptr + i));
        }
        preorder_serialize(root->left, result);
        preorder_serialize(root->right, result);

    }   
};

template<class T, class Compare>
void swap(BST<T, Compare>& lhs, BST<T, Compare>& rhs) noexcept
{
    lhs.swap(rhs);
}




#endif