#include <iostream>
#include <exception>
#include <functional>


template <typename T>
class BST {
private:

    struct Node {
        Node *left;
        Node *right;
        Node *parent;
        int size; // Subtree node count

        T val;

        Node () : left(nullptr), right(nullptr), parent(nullptr), val(0), size(1) {}
        Node (Node* left, Node *right, Node *parent, T val) :
                left(left), right(right), parent(parent), val(val), size(1) {}
    };

    Node *sentinel;

    Node *_Search(T element) {
        Node *node = sentinel->left;

        while (node) {
            if (element < node->val) {
                node = node->left;
            } else if (element > node->val) {
                node = node->right;
            } else {
                return node;
            }
        }
        
        return node;
    }

    void _OutputSorted(Node *node) {
        if (!node) {
            return;
        }

        _OutputSorted(node->left);

        std::cout << node->val << ' ';

        _OutputSorted(node->right);
    }

    Node *_Min (Node *node) {
        if (!node) {
            throw std::runtime_error("Cannot call _Min on empty tree");
        }
        
        while (node->left) {
            node = node->left;
        }

        return node;
    }
    
    Node *_Max (Node *node) {
        if (!node) {
            throw std::runtime_error("Cannot call _Max on empty tree");
        }
        
        while (node->right) {
            node = node->right;
        }

        return node;
    }

    void _BubbleSize(Node *node, int delta) {
        while (node) {
            node->size += delta;
            node = node->parent;
        }
    }

    Node *_Select(Node *node, int i) {
        int j = 0;
        if (node->left) {
            j = node->left->size;
        }
        
        if (i == j) {
            return node;
        }

        if (i < j) {
            return _Select(node->left, i);
        }

        return _Select(node->right, i - j - 1);
    }

public:
    
    BST () : sentinel(new Node()) {}

    T *Search (T element) {
        Node *node = _Search(element);

        return node ? &node->val : nullptr;
    }

    T *Min () {
        return &_Min(sentinel->left)->val;
    }
    
    T *Max () {
        return &_Max(sentinel->left)->val;
    }

    T *Predecessor (T element) {
        Node *node = _Search(element);

        if (!node) {
            return nullptr;
        }

        /*
            2 cases:
            - node has left subtree --> predecessor is Max(leftChild)
            - node doesn't have left subtree --> predecessor is an ancestor (parent, grandparent, ...)
        */
        // 1st case
        if (node->left) {
            return &_Max(node->left)->val;
        }

        // 2nd case
        Node *p = node->parent;

        while (p && p != sentinel) {
            if (p->right == node) {
                return &p->val;
            }
            node = p;
            p = p->parent;
        }
        
        return nullptr;
    }

    T *Successor (T element) {
        Node *node = _Search(element);

        if (!node) {
            return nullptr;
        }

        /*
            2 cases:
            - node has right subtree --> sucessor is Min(rightChild)
            - node doesn't have right subtree --> successor is ancestor (parent, grandparent, ...)
        */
        // 1st case
        if (node->right) {
            return &_Min(node->right)->val;
        }

        // 2nd case
        Node *p = node->parent;

        while (p && p != sentinel) {
            if (p->left == node) {
                return &p->val;
            }
            node = p;
            p = p->parent;
        }

        return nullptr;
    }

    void OutputSorted () {
        std::cout << "Elements: ";
        _OutputSorted(sentinel->left);
    }

    void Insert (T element) {
        Node *newNode = new Node(nullptr, nullptr, nullptr, element);

        if (!sentinel->left) {
            sentinel->left = newNode;
            sentinel->left->parent = sentinel;
            return;
        }

        Node *node = sentinel->left;

        for(;;) {
            if (element < node->val) {
                if (node->left) {
                    node = node->left;
                } else {
                    node->left = newNode;
                    _BubbleSize(node, 1);
                    break;
                }
            } else {
                if (node->right) {
                    node = node->right;
                } else {
                    node->right = newNode;
                    _BubbleSize(node, 1);
                    break;
                }
            }
        }
        
        newNode->parent = node;
    }

    void Delete (T element) {
        Node *node = _Search(element);

        if (!node) {
            return;
        }

        /*
            2 cases:
            - node has 2 children
            - node doesn't have 2 children
        
            FIXME handle node being deleted as root
        */

        if (!node->left && !node->right) {
            if (node->parent->left == node) {
                node->parent->left = nullptr;
            } else {
                node->parent->right = nullptr;
            }

            _BubbleSize(node->parent, -1);
        }
        
        else if (!node->left) {
            if (node->parent->left == node) {
                node->parent->left = node->right;
            } else {
                node->parent->right = node->right;
            }
            node->right->parent = node->parent;

            _BubbleSize(node->parent, -1);
        }

        else if (!node->right) {
            if (node->parent->left == node) {
                node->parent->left = node->left;
            } else {
                node->parent->right = node->left;
            }
            node->left->parent = node->parent;

            _BubbleSize(node->parent, -1);
        }

        else {
            Node *leftMax = _Max(node->left);

            _BubbleSize(leftMax, -1);

            // Delete leftMax (only has 1 child at most)
            Node *leftMaxChild = leftMax->left ? leftMax->left : leftMax->right;
            
            if (leftMaxChild) {
                leftMaxChild->parent = leftMax->parent;
            }

            if (leftMax->parent->left == leftMax) {
                leftMax->parent->left = leftMaxChild;
            } else {
                leftMax->parent->right = leftMaxChild;
            }

            // Replace node with leftMax
            if (node->parent->left == node) {
                node->parent->left = leftMax;
            } else {
                node->parent->right = leftMax;
            }
            leftMax->parent = node->parent;

            if (node->left) {
                node->left->parent = leftMax;
            }
            leftMax->left = node->left;

            if (node->right) {
                node->right->parent = leftMax;
            }
            leftMax->right = node->right;
            leftMax->size = node->size;
        }
        
        delete node;
    }

    T *Select(int i) {
        if (!sentinel->left) {
            throw std::runtime_error("Cannot Select(): Empty tree");
        }

        if (i < 0 || i >= sentinel->left->size) {
            throw std::runtime_error("Cannot Select(): i out of range");
        }

        return &_Select(sentinel->left, i)->val;
    }

    ~BST() {
        std::function<void(Node*)> PostOrder = [&](Node *root) {
            if (!root) {
                return;
            }

            if (!root->left && !root->right) {
                delete root;
                return;
            }

            PostOrder(root->left);
            PostOrder(root->right);

            delete root;
        };

        PostOrder(sentinel);
    }

};

