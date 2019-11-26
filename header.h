#include<iostream>
#include<string>
#include<cmath>
using namespace std;
typedef char ItemType;

/*struct Node{
    ItemType value;
    Node * next = nullptr;
};
*/
//place character inside of tree
struct List{
    ItemType value;
    List * next = nullptr;
};
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
    TreeNode * getRoot();
    void fillTree(string input, int ignore);
    void IsFullTree(TreeNode * &root, int requirement);
    //check if tree organization is correct
    void IsBST(const TreeNode &head);
    //get the count of all nodes in the tree
    void getLength(const TreeNode &head);
    //get nodes at current level
    string getNodesAtLevel(TreeNode * &head, int level);
    //prints ancestor of given node
    void printAncestor(const TreeNode &currentNode, int level);
    TreeType();
    ~TreeType();
    
    friend void charValue();
};