#include"header.h"
#include<cctype>
void assignList(string myString);

string toUpper(string input);
int powerTwoCheck(int inputLength);

int main(){
    //prompt string input
    char input;
    string statement;
    int nodesAtLevel;
    TreeType tree;
    TreeNode * root = tree.getRoot();
    TreeNode * mostLeft;
    ItemType ancestorChar;
    int posToIgnore = 0;
    int inputLevel = 0;
    int currLevel = 0;
    int nodeCount = 0;
    int pos = 0;
    int statementLength = 0;
    bool powerCheck = false;
    ItemType myArr[50]; 
    //CHECK FUNCTION INSTRUCTIONS FOR BEST GRADE
    while(input != 'q'){
    cout<<"--------------MENU--------------------" <<endl;
    //fillTree()
    cout<<"f)Fill the tree with Nodes (BALANCED NOT GUARANTEED)"<< endl;
    //full tree 2 level combo: mdajrqt
    cout<<"b)Fill the tree with Nodes (BALANCED GUARANTEED)"<<endl;
    //IsFullTree()
    cout<<"1) Is the tree full?"<<endl;
    //IsBST()
    cout<<"2) Check that tree is orgainized"<<endl;
    //GetNodesAtLevel
    cout<<"3) Get Node count at a certain level from 0 to N level"<<endl;
    //PringAncestors
    cout<<"4) Print Node ancestors" <<endl;
    //GetSmallest()
    cout<<"5) Print smallest element of the tree"<<endl;
    //DeleteNode()
    cout<<"6) Delete a node"<<endl;
    cout<<"q) Quit"<<endl;
    cout<<"~---------------------------------------~"<<endl << endl;
    cout<<"What would you like to do?"<<endl;
    cin>>input;
    switch(input){
        case 'f': 
            cout << "What is the statement that you want loaded into the binary tree?" << endl;
            cin >> statement;
            statement = toUpper(statement);
            //posToIgnore for element used as root
            posToIgnore = tree.setRoot(statement);
            tree.fillTree(root, statement, posToIgnore);
            break;
        case 'b':
            cout<<"what statement would you like in a perfectly balanced tree?" <<endl;
            cin>>statement;
            sort(statement.begin(), statement.end());
            statementLength = statement.length();
            powerCheck = powerTwoCheck(statementLength);
            if(!powerCheck){
                cout<<"This input is not a perfect tree"<<endl;
            }

            cout << "ordered: "<< statement <<endl;
                break;
        case '1':
            tree.IsFullTree(root, statement.length());
            break;
        case '3':
            cout<<"what level would you like to check"<<endl;
            cin >> inputLevel;
            //find first most left valid
            nodeCount = tree.getNodesAtLevel(root, inputLevel, myArr);
            cout<<"Node Count is " << nodeCount<< endl;
            cout<<"at level " << inputLevel << endl;
            break;
        case '4':
            cout<<"What character would you like to find the ancestors of?"<<endl;
            cin>>ancestorChar;
            ancestorChar = toupper(ancestorChar);
            tree.printAncestor(root, ancestorChar);
            break;
        case '5':
            mostLeft = tree.getSmallest(root);
            cout << "smallest element of tree is "<< mostLeft->Info << endl; 
            break;
        case 'q':
            tree.DeleteTree(root);
            return 0;
        default: 
            cout<< "mistake has been made, try again" <<endl;
    }
    }
    //menu
    return 0;
}