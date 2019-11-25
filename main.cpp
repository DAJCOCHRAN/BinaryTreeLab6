#include"header.h"
#include<cctype>
void assignList(string myString);

string toUpper(string input);

int main(){
    //prompt string input
    string input;
    int posToIgnore = 0;
    cout << "What is the statement that you want loaded into the binary tree?" << endl;
    cin >> input;
    input = toUpper(input);
    TreeType tree;
    posToIgnore = tree.setRoot(input);
    cout << posToIgnore <<endl;
    TreeNode * null = nullptr;
    tree.fillTree(input, posToIgnore);
    //menu
    return 0;
}