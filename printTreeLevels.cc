#include <iostream>
#include <queue>
#include <unordered_map>
#include <cassert>
using namespace std;

// Definitions from class
struct Node {
    string key;
    string stuff;
    Node* left;
    Node* right;
};

typedef Node* BST;

void BST_init (BST& root)
{
    root = nullptr;
}

void BST_insert (BST& root, string key, string stuff)
{
    if (nullptr == root)
    {
        root = new Node;
        root->key = key;
        root->stuff = stuff;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (key < root->key)
    {
        BST_insert(root->left, key, stuff);
    }
    else
    {
        BST_insert(root->right, key, stuff);
    }
}

void BST_print (const BST& root)
{
    if (nullptr != root)
    {
        BST_print (root->left);
        cout << root->key << endl;
        BST_print (root->right);
    }
}

int level = 1;

void recurse(BST& root, queue<string>& q, unordered_map<string, int>& levelMap) {
    if (root == nullptr && q.empty()) {
        return;
    }
    else {
        while (!q.empty()) {
            int currLevel = levelMap[q.front()];
            if (currLevel > level) {
                level = currLevel;
                cout << endl << q.front();
                q.pop();
            } else {
                cout << q.front();
                q.pop();
            }
        }

        if (root != nullptr) {
            if (root->left != nullptr) {
                if (root->key == "f") {
                    cout<<"here1"<<endl;
                }
                q.push(root->left->key);
                levelMap[root->left->key] = levelMap[root->key] + 1;
            }
            if (root->right != nullptr) {

                q.push(root->right->key);
                levelMap[root->right->key] = levelMap[root->key] + 1;
            }

            queue<string> empty;
            if (root->left != nullptr) {
                recurse(root->left, q, levelMap);
                recurse(root->right, empty, levelMap);
            }
            else if (root->right != nullptr) {
                recurse(root->left, empty, levelMap);
                recurse(root->right, q, levelMap);
            }
        }
    }
}

void printQueue(queue<string>& q, unordered_map<string, int>& levelMap) {
    while (!q.empty()) {
        int currLevel = levelMap[q.front()];
        if (currLevel > level) {
            level = currLevel;
            cout << endl << q.front();
            q.pop();
        } else {
            cout << q.front();
            q.pop();
        }
    }
}

void printLevels(BST& root) {
    std::queue<string> q;
    unordered_map<string, int> levelMap;

    if (root != nullptr) {
        q.push(root->key);
        levelMap[root->key] = 1;
        recurse(root, q, levelMap);
        cout << endl;
        // printQueue(q, levelMap);
    }
}

int main (int argc, char* argv[])
{
    BST tree;
    BST_init(tree);
    BST_insert(tree, "d", "stuff");
    BST_insert(tree, "b", "stuff");
    BST_insert(tree, "f", "stuff");
    BST_insert(tree, "a", "stuff");
    BST_insert(tree, "c", "stuff");
    BST_insert(tree, "g", "stuff");
    
    /*
     *              d
     *            /   \
     *           b     f
     *          / \     \
     *         a   c     g
     */
    
    printLevels(tree);
}
