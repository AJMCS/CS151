/* EBinaryTree.cpp - Extend the functions in the BinaryTree class
* Author: Chris Merrill
* Module: 16
* Project: Modified version of demonstration BinaryTree class for this Lab
* Description: renamed the BinaryTree class to EBinaryTree and moved contents
* of BinaryTree.cpp into this file
*
* Public Functions:
* - constructor(value)
* - destructor() - calls destroySubtree
* - bool search(value) - no recursive version
* - bool insert(value) - calls recursive version
* - bool remove(value) - calls recursive version
* - void showPreorder() - calls recursive version
* - void showInorder() - calls recursive version
* - void showPostorder() - calls recursive version
* - vector<T> toVector() - cheap replacement for an iterator
*
* Functions defined outside of the class (private unless otherwise specified)
* - destroySubtree(Node *) - used by the destructor
* - insert(Node *, value) - recursive function to insert a node
* - search(value) - non-recursive function (public)
* - remove(Node *, value) - recursive function to remove a node
* - makeDelete(Node *) - remove the node
* - displayPreorder(Node *) - displays the subtree in preorder
sequence
* - displayInorder(Node *) - displays the subtree in inorder
sequence
* - displayPostorder(Node *) - displays the subtree in postorder
sequence
* - toVector(Node *) - builds a vector of values in the tree
*/
#include <iostream>
#include <vector>
using namespace std ;
template<class T>
class EBinaryTree {
private:
    // The TreeNode struct is used to build the tree. It is internal to the EBinaryTree
    // class and therefore does not need to be specified as <T> when used to define
    // functions
    struct TreeNode {
        T value;
        TreeNode *left;
        TreeNode *right;
        TreeNode(T value1, TreeNode *left1 = nullptr, TreeNode *right1 = nullptr) {
            value = value1;
            left = left1;
            right = right1;
        }
    };
    TreeNode *root; // Pointer to the root of the tree
    // Various helper member functions.
    bool insert(TreeNode *&, T);
    void destroySubtree(TreeNode *);
    void remove(TreeNode *&, T);
    void makeDeletion(TreeNode *&);
    void displayInorder(TreeNode *) const;
    void displayPreorder(TreeNode *) const;
    void displayPostorder(TreeNode *) const;
    void toVector(vector<T> *, TreeNode *) const;
    int getHeight(TreeNode *) const;
    int getDiameter(TreeNode *) const;
    int getSize(TreeNode *) const;

public:
    // These member functions are the public interface.
    EBinaryTree() { root = nullptr; } // Constructor
    ~EBinaryTree() { destroySubtree(root); } // Destructor
    bool insert(T data) { return insert(root, data); } // Add an item
    bool search(T) const;
    void remove(T num) { remove(root, num); } // Delete an item
    void showInorder(void) const {
        if (!root) {
            cout << "(empty)";
        } else {
            displayInorder(root);
        }
        cout << endl;
    }
    void showPreorder() const {
        if (!root) {
            cout << "(empty)";
        } else {
            displayPreorder(root);
        }
        cout << endl;
    }
    void showPostorder() const {
        if (!root) {
            cout << "(empty)";
        } else {
            displayPostorder(root);
        }
        cout << endl;
    }
    vector<T> * toVector() const {
        vector<T> *vect = new vector<T>();
        toVector(vect, root);
        return vect;
    }
    int getHeight() const;
    int getDiameter() const;
    int getSize() const;
};
//**************************************************
// destroySubTree is called by the destructor. It *
// deletes all nodes in the tree. *
// *
// It works by recursively going down to each leaf *
// (first left, then right subtrees), and deleting *
// from the bottom up. *
//**************************************************
template<typename T>
void EBinaryTree<T>::destroySubtree(TreeNode *tree) {
    if (!tree) { return; }
    destroySubtree(tree->left);
    destroySubtree(tree->right);
    // Delete the node at the root.
    delete tree;
}
//**************************************************
// Insert inserts a value into a given subtree of *
// the main binary search tree. *
//**************************************************
template<typename T>
bool EBinaryTree<T>::insert(TreeNode * &tree, T data) {
    // If the tree is empty, create a new node and make it
    // the root of the tree.
    if (!tree) {
        tree = new TreeNode(data);
        return true;
    }
    // If the value is already in tree: return.
    if (tree->value == data) { return false; }
    // The tree is not empty: insert the new node into the
    // left or right subtree.
    if (data < tree->value) {
        insert(tree->left, data);
    } else {
        insert(tree->right, data);
    }
    return true;
}
//***************************************************
// searchNode determines if a value is present in *
// the tree. If so, the function returns true. *
// Otherwise, it returns false. *
// *
// Recursion is NOT used in this function, since *
// it just traverses the appropriate subtrees (not *
// the entire tree) and stops once value is found *
//***************************************************
template<typename T>
bool EBinaryTree<T>::search(T data) const {
    TreeNode *tree = root; // start at the top
    while (tree) {
        if (tree->value == data) {
            return true;
        } else if (data < tree->value) { // look only at appropriate subtree
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return false;
}
//********************************************
// Deletes the node in the given tree that *
// has a value member the same as the *
// specified value. *
//********************************************
template<typename T>
void EBinaryTree<T>::remove(TreeNode *&tree, T data) {
    if (tree == nullptr) { return; } // not in the original tree
    if (data < tree->value) { // look in left subtree
        remove(tree->left, data);
    } else if (data > tree->value) { // look in right subtree
        remove(tree->right, data);
    } else {
        makeDeletion(tree); // found it -- delete this node
    }
}
//***********************************************************
// makeDeletion takes a reference to a tree whose root *
// is to be deleted. If the tree has a single child, the *
// the tree is replaced by the single child after the *
// removal of its root node. If the tree has two children *
// the left subtree of the deleted node is attached at *
// an appropriate point in the right subtree, and then *
// the right subtree replaces the original tree. *
//***********************************************************
template<typename T>
void EBinaryTree<T>::makeDeletion(TreeNode *&tree) {
    // Used to hold node that will be deleted.
    TreeNode *nodeToDelete = tree;
    // Used to locate the point where the left subtree is attached.
    TreeNode *attachPoint;
    if (tree->right == nullptr) {
        // Replace tree with its left subtree.
        tree = tree->left;
    } else if (tree->left == nullptr) {
        // Replace tree with its right subtree.
        tree = tree->right;
    } else {
        //The node has two children, so move to right subtree.
        attachPoint = tree->right;
        // Locate the smallest node in the right subtree
        // by moving as far to the left as possible.
        while (attachPoint->left != nullptr) {
            attachPoint = attachPoint->left;
        }
        // Attach the left subtree of the original tree
        // as the left subtree of the smallest node
        // in the right subtree.
        attachPoint->left = tree->left;
        // Replace the original tree with its right subtree.
        tree = tree->right;
    }
    // Delete root of original tree
    delete nodeToDelete;
}
//***************************************************
// Displays the values stored in inorder sequence. *
//***************************************************
template<typename T>
void EBinaryTree<T>::displayInorder(TreeNode *tree) const {
    if (tree) {
        displayInorder(tree->left);
        cout << tree->value << " ";
        displayInorder(tree->right);
    }
}
//****************************************************
// Displays the values stored in preorder sequence. *
//****************************************************
template<typename T>
void EBinaryTree<T>::displayPreorder(TreeNode *tree) const {
    if (tree) {
        cout << tree->value << " ";
        displayPreorder(tree->left);
        displayPreorder(tree->right);
    }
}
//****************************************************
// Displays the values stored in postorder sequence. *
//****************************************************
template<typename T>
void EBinaryTree<T>::displayPostorder(TreeNode *tree) const {
    if (tree) {
        displayPostorder(tree->left);
        displayPostorder(tree->right);
        cout << tree->value << " ";
    }
}
//*************************************************
// Returns a vector of values in the binary tree *
// using inorder sequence. *
//*************************************************
template<typename T>
void EBinaryTree<T>::toVector(vector<T> *vect, TreeNode *tree) const {
    if (tree) {
        toVector(vect, tree->left);
        vect->push_back(tree->value);
        toVector(vect, tree->right);
    }
}

//*************************************************
// Returns the height of a subtree starting at the given node
//*************************************************
template<typename T>
int EBinaryTree<T>::getHeight(TreeNode *tree) const {
    if (tree == nullptr || (tree->left == nullptr && tree->right == nullptr)) {
        return 0;
    }
    return 1 + max(getHeight(tree->left), getHeight(tree->right));
}

//*************************************************
// Returns the diameter of a subtree starting at the given node
//*************************************************
template<typename T>
int EBinaryTree<T>::getDiameter(TreeNode *tree) const {
    if (tree == nullptr) return 0;

    int left_height = getHeight(tree->left);
    int right_height = getHeight(tree->right);
    int left_diameter = getDiameter(tree->left);
    int right_diameter = getDiameter(tree->right);

    int edges = (tree->left != nullptr) + (tree->right != nullptr);
    return max(left_height + right_height + edges,
           max(left_diameter, right_diameter));
}

//*************************************************
// Returns the size (number of nodes) of a subtree starting at the given node
//*************************************************
template<typename T>
int EBinaryTree<T>::getSize(TreeNode *tree) const {
    if (tree == nullptr) return 0;
    return 1 + getSize(tree->left) + getSize(tree->right);
}

//*************************************************
// Public versions of the functions that call the private versions
//*************************************************
template<typename T>
int EBinaryTree<T>::getHeight() const {
    return getHeight(root);
}

template<typename T>
int EBinaryTree<T>::getDiameter() const {
    return getDiameter(root);
}

template<typename T>
int EBinaryTree<T>::getSize() const {
    return getSize(root);
}