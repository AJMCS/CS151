/* main.cpp - Tester for height, diameter, and size of binary trees using EBinaryTree
* Author: AJ McDaniel
* Lab: 16
* Project 01: Tree Properties
* Problem statement: Build five binary search trees and compute their height, diameter, and size recusively.
* 
*
* Algorithm: 
* 1. Create a templated EBinaryTree class that supports:
 *    - Insertion of nodes in BST order
 *    - Recursive functions to compute height, diameter, and size
 *    - Traversal (preorder, inorder, postorder)
 * 2. In main.cpp:
 *    - Build five trees with different structures and contents
 *    - For each tree:
 *      • Display traversal orders
 *      • Compute and print height, diameter, and size
 */

#include <iostream>
#include <string>
#include "EBinaryTree.cpp"
using namespace std;

// prototypes
void printTreeInfo(const EBinaryTree<string>& tree, const string& name);
void insertMinimalHeight(EBinaryTree<string>& tree, string arr[], int start, int end);

int main() {
    // Names for trees 1-3
    string names[] = {"Albert", "Barbara", "Cesar", "Dexter", "Eduardo", "Frank", "Georgio", "Heather"};

    // Tree 1: Alphabetic order
    EBinaryTree<string> tree1;
    for (int i = 0; i < 8; ++i) tree1.insert(names[i]);
    printTreeInfo(tree1, "Alphabetic Order");

    // Tree 2: Reverse alphabetic order
    EBinaryTree<string> tree2;
    for (int i = 7; i >= 0; --i) tree2.insert(names[i]);
    printTreeInfo(tree2, "Reverse Alphabetic Order");

    // Tree 3: Level-by-level for the given structure
    EBinaryTree<string> tree3;
    tree3.insert("Cesar");      // Level 1
    tree3.insert("Barbara");    // Level 2
    tree3.insert("Eduardo");    // Level 2
    tree3.insert("Albert");     // Level 3
    tree3.insert("Dexter");     // Level 3
    tree3.insert("Georgio");    // Level 3
    tree3.insert("Frank");      // Level 4
    tree3.insert("Heather");    // Level 4
    printTreeInfo(tree3, "Level-by-Level Structure");

    // Tree 4: Height 5, diameter 8, size 13
    string names4[] = {"G", "C", "K", "A", "E", "I", "M", "B", "D", "F", "H", "J", "L"};
    EBinaryTree<string> tree4;
    for (auto& n : names4) tree4.insert(n);
    printTreeInfo(tree4, "Custom Tree (size 13, diameter 8)");

    // Tree 5: Height 5, diameter 8, size 15
    string names5[] = {"H", "D", "L", "B", "F", "J", "N", "A", "C", "E", "G", "I", "K", "M", "O"};
    EBinaryTree<string> tree5;
    for (auto& n : names5) tree5.insert(n);
    printTreeInfo(tree5, "Custom Tree (size 15, diameter 8)");

    // Minimal Height Tree (balanced BST)
    EBinaryTree<string> minHeightTree;
    insertMinimalHeight(minHeightTree, names, 0, 7);
    printTreeInfo(minHeightTree, "Minimal Height Tree (Recursive)");

    return 0;
}

// Helper function to print tree info
void printTreeInfo(const EBinaryTree<string>& tree, const string& name) {
    cout << "\nTree: " << name << endl;
    cout << "Inorder: "; tree.showInorder();
    cout << "Preorder: "; tree.showPreorder();
    cout << "Postorder: "; tree.showPostorder();
    cout << "Height: " << tree.getHeight() << endl;
    cout << "Diameter: " << tree.getDiameter() << endl;
    cout << "Size: " << tree.getSize() << endl;
}

void insertMinimalHeight(EBinaryTree<string>& tree, string arr[], int start, int end) {
    if (start > end) return;
    int mid = (start + end) / 2;
    tree.insert(arr[mid]);
    insertMinimalHeight(tree, arr, start, mid - 1);
    insertMinimalHeight(tree, arr, mid + 1, end);
} 