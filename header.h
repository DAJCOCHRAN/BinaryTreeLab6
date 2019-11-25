#include<iostream>
#include<string>
using namespace std;
typedef char ItemType;

/*struct Node{
    ItemType value;
    Node * next = nullptr;
};
*/
//place character inside of tree
struct TreeNode{
    ItemType Info = ' ';
    TreeNode * right = nullptr;
    TreeNode * left = nullptr;
    TreeNode * ancestor = nullptr;
    };

class TreeType{
    private:
        TreeNode * root;

    public:
    // select the root
    int setRoot(string input);
    //check the tree is full or not
    void fillTree(string input, int ignore);
    void IsFullTree(const TreeNode &head);
    //check if tree organization is correct
    void IsBST(const TreeNode &head);
    //get the count of all nodes in the tree
    void getLength(const TreeNode &head);
    //get nodes at current level
    void getNodesAtLevel(const TreeNode &head, int level);
    //prints ancestor of given node
    void printAncestor(const TreeNode &currentNode, int level);
    TreeType();
    ~TreeType();
    
    friend void charValue();
};