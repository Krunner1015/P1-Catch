#ifndef PROJECT1_AVLTREE_H
#define PROJECT1_AVLTREE_H

#include <vector>
#include <string>
#include "Student.h"
using namespace std;

class AVLTree {
public:
    Student* root;
    AVLTree() : root(nullptr) {}
    AVLTree(Student* root) : root(root) {}

    void insertStudent(const string &name, int id) {
        if (!name.empty()) {
            Student *node = new Student(name, id);
            root = insert(root, node);
        } else {
            root = nullptr;
        }
    }
    void remove(int id) {
        root = remove(root, id);
    }

    void searchID(int id) {
        vector<Student*> studs;
        inorderToVector(root, studs);
        for (int i = 0; i < static_cast<int>(studs.size()); i++) {
            if (studs[i]->ID == id) {
                cout << studs[i]->name << endl;
                return;
            }
        }
        cout << "Unsuccessful" << endl;
    }
    void searchName(const string &name) {
        vector<Student*> studs;
        preorderToVector(root, studs);
        int found = 0;
        for (int i = 0; i < static_cast<int>(studs.size()); i++) {
            if (studs[i]->name == name) {
                cout << studs[i]->ID << endl;
                found++;
            }
        }
        if (found == 0) {
            cout << "Unsuccessful" << endl;
        }
    }

    void printInorder() {
        vector<Student*> studs;
        inorderToVector(root, studs);
        for (int i = 0; i < static_cast<int>(studs.size()); i++) {
            cout << studs[i]->name;
            if (i != static_cast<int>(studs.size()) - 1) cout << ", ";
        }
        cout << endl;
    }
    void printPreorder() {
        vector<Student*> studs;
        preorderToVector(root, studs);
        for (int i = 0; i < static_cast<int>(studs.size()); i++) {
            cout << studs[i]->name;
            if (i != static_cast<int>(studs.size()) - 1) cout << ", ";
        }
        cout << endl;
    }
    void printPostorder() {
        vector<Student*> studs;
        postorderToVector(root, studs);
        for (int i = 0; i < static_cast<int>(studs.size()); i++) {
            cout << studs[i]->name;
            if (i != static_cast<int>(studs.size()) - 1) cout << ", ";
        }
        cout << endl;
    }
    void printLevelCount() {
        if (root == nullptr) {
            cout << "0" << endl;
            return;
        }
        cout << height(root) << endl;
    }
    void removeInorder(int n) {
        vector<Student*> studs;
        inorderToVector(root, studs);
        if (n < 0 || n >= static_cast<int>(studs.size())) {
            cout << "Unsuccessful" << endl;
            return;
        }
        remove(studs[n]->ID);
    }
    void getInorder(Student *node, vector<Student*> &studs) {
        inorderToVector(node, studs);
    }
    void getPreorder(Student *node, vector<Student*> &studs) {
        preorderToVector(node, studs);
    }
    void getPostorder(Student *node, vector<Student*> &studs) {
        postorderToVector(node, studs);
    }
    int getHeight() {
        return height(root);
    }
private:
    int height(Student *node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    int getBalance(Student *node) {
        if (!node) return 0;
        return height(node->left) - height(node->right);
    }

    Student *rotateLeft(Student *node) {
        Student *newRoot = node->right;
        Student *newRootLeft = newRoot->left;
        newRoot->left = node;
        node->right = newRootLeft;
        return newRoot;
    }
    Student *rotateRight(Student *node) {
        Student *newRoot = node->left;
        Student *newRootRight = newRoot->right;
        newRoot->right = node;
        node->left = newRootRight;
        return newRoot;
    }
    Student *insert(Student *parent, Student *node) {
        if (node == nullptr) {
            cout << "Unsuccessful" << endl;
            return parent;
        }
        if (parent == nullptr) {
            cout << "Successful" << endl;
            return node;
        }

        if (node->ID < parent->ID) {
            parent->left = insert(parent->left, node);
        } else if (node->ID > parent->ID) {
            parent->right = insert(parent->right, node);
        } else {
            cout << "Unsuccessful" << endl;
            return parent;
        }

        int balance = getBalance(parent);

        if (balance > 1) {
            if (node->ID < parent->left->ID) {
                return rotateRight(parent);
            } else {
                parent->left = rotateLeft(parent->left);
                return rotateRight(parent);
            }
        }
        if (balance < -1) {
            if (node->ID > parent->right->ID) {
                return rotateLeft(parent);
            } else {
                parent->right = rotateRight(parent->right);
                return rotateLeft(parent);
            }
        }
        return parent;
    }
    Student *remove(Student *node, int id) {
        if (node == nullptr) {
            cout << "Unsuccessful" << endl;
            return node;
        }
        if (id < node->ID) {
            node->left = remove(node->left, id);
        } else if (id > node->ID) {
            node->right = remove(node->right, id);
        } else {
            if (node->left == nullptr && node->right == nullptr) { //none
                delete node;
                cout << "Successful" << endl;
                return nullptr;
            } else if (node->left == nullptr || node->right == nullptr) { //one
                if (node->left != nullptr) {
                    Student *left = node->left;
                    delete node;
                    cout << "Successful" << endl;
                    return left;
                } else {
                    Student *right = node->right;
                    delete node;
                    cout << "Successful" << endl;
                    return right;
                }
            } else { //two
                Student *newRoot = node->right;
                while (newRoot->left != nullptr) {newRoot = newRoot->left;}
                node->ID = newRoot->ID;
                node->name = newRoot->name;
                node->balance = newRoot->balance;
                node->right = remove(node->right, newRoot->ID);
            }
        }
        return node;
    }

    void inorderToVector(Student *node, vector<Student*> &studs) {
        if (node == nullptr) return;
        inorderToVector(node->left, studs);
        studs.push_back(node);
        inorderToVector(node->right, studs);
    }
    void preorderToVector(Student *node, vector<Student*> &studs) {
        if (node == nullptr) return;
        studs.push_back(node);
        preorderToVector(node->left, studs);
        preorderToVector(node->right, studs);
    }
    void postorderToVector(Student *node, vector<Student*> &studs) {
        if (node == nullptr) return;
        postorderToVector(node->left, studs);
        postorderToVector(node->right, studs);
        studs.push_back(node);
    }
};

#endif // PROJECT1_AVLTREE_H
