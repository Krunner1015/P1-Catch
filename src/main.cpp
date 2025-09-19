#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "AVLTree.h"
using namespace std;

bool validName(const string &name) { //check for name to be letters or spaces
    for (char c : name) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    AVLTree tree; //BST
    vector<string> args; //vector to store inputs
    for (int i = 1; i < argc; i++) {
        args.push_back(argv[i]);
    }
    int commands = stoi(args[0]); //number of commands in total from input
    int count = 0; //number of commands completed
    int i = 1; //current command accessed from inputs vector
    while (count < commands && i < args.size()) {
        if (args[i] == "insert") { //handle insert command
            if (i + 2 >= args.size()) {
                cout << "unsuccessful" << endl;
                i++; //move to the next command
            } else {
                string name = args[i+1];
                string id = args[i+2];
                //check for valid name and id
                if (validName(name) && id.size() == 8 && all_of(id.begin(), id.end(), ::isdigit)) {
                    tree.insertStudent(name, stoi(id));
                } else {
                    cout << "unsuccessful" << endl;
                }
                i += 3; // move to the next command
            }
            count++;
        } else if (args[i] == "remove") { //handle remove command
            if (i + 1 >= args.size()) {
                cout << "unsuccessful" << endl;
                i++; //move to the next command
            } else {
                string id = args[i+1];
                //check for valid id
                if (id.size() == 8 && all_of(id.begin(), id.end(), ::isdigit)) {
                    tree.remove(stoi(id));
                } else {
                    cout << "unsuccessful" << endl;
                }
                i += 2; //move to the next command
            }
            count++;
        } else if (args[i] == "search") { //handle search command
            if (i + 1 >= args.size()) {
                cout << "unsuccessful" << endl;
                i++; //move to the next command
            } else {
                string srch = args[i+1];
                //search by ID if input is 8 digit number
                if (!srch.empty() && all_of(srch.begin(), srch.end(), ::isdigit) && srch.size() == 8) {
                    tree.searchID(stoi(srch));
                } else if (validName(srch)) { //search by name if input is a valid name
                    tree.searchName(srch);
                } else {
                    cout << "unsuccessful" << endl;
                }
                i += 2; //move to the next command
            }
            count++;
        } else if (args[i] == "printInorder") { //print tree in inorder traversal
            tree.printInorder();
            i++; //move to the next command
            count++;
        } else if (args[i] == "printPreorder") { //print tree in preorder traversal
            tree.printPreorder();
            i++; //move to the next command
            count++;
        } else if (args[i] == "printPostorder") { //print tree in postorder traversal
            tree.printPostorder();
            i++; //move to the next command
            count++;
        } else if (args[i] == "printLevelCount") { //prints the number of levels
            tree.printLevelCount();
            i++; //move to the next command
            count++;
        } else if (args[i] == "removeInorder") { //handle the removeInorder command
            if (i + 1 >= args.size()) {
                cout << "unsuccessful" << endl;
                i++;
            } else {
                string num = args[i+1];
                //check that the input is a number
                if (all_of(num.begin(), num.end(), ::isdigit)) {
                    tree.removeInorder(stoi(num));
                } else {
                    cout << "unsuccessful" << endl;
                }
                i += 2; //move to the next command
            }
            count++;
        } else { //handle invalid commands
            cout << "unsuccessful" << endl;
            i++; //move to the next command
        }
    }
    return 0; //exit
}