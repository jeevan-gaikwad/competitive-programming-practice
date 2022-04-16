// Trees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <istream>
#include <sstream>

using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



    // Function to Build Tree
    Node* buildTree(string str)
    {
        // Corner Case
        if (str.length() == 0 || str[0] == 'N')
            return NULL;

        // Creating vector of strings from input
        // string after spliting by space
        vector<string> ip;

        istringstream iss(str);
        for (string str; iss >> str; )
            ip.push_back(str);

        // Create the root of the tree
        Node* root = newNode(stoi(ip[0]));

        // Push the root to the queue
        queue<Node*> queue;
        queue.push(root);

        // Starting from the second element
        int i = 1;
        while (!queue.empty() && i < ip.size()) {

            // Get and remove the front of the queue
            Node* currNode = queue.front();
            queue.pop();

            // Get the current node's value from the string
            string currVal = ip[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = newNode(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= ip.size())
                break;
            currVal = ip[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = newNode(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->right);
            }
            i++;
        }

        return root;
    }









    // } Driver Code Ends
   /* A binary tree Node
   struct Node
   {
       int data;
       Node* left, * right;
   }; */

    class Solution {
    public:

        void traverseLeftBoundry(Node* node, std::vector<int>& leftBoundrySol) {
            //skip leaf node
            if (node == nullptr || node->left == nullptr && node->right == nullptr) {
                return; //break
            }

            leftBoundrySol.push_back(node->data);
            if (node->left != nullptr) {
                traverseLeftBoundry(node->left, leftBoundrySol);
            }
            else {
                traverseLeftBoundry(node->right, leftBoundrySol);
            }
        }

        void traverseRightBoundry(Node* node, std::stack<int>& rightBoundrySol) {
            if (node == nullptr || node->left == nullptr && node->right == nullptr) {
                return; //break
            }
            rightBoundrySol.push(node->data);
            if (node->right != nullptr) {
                traverseRightBoundry(node->right, rightBoundrySol);
            }
            else { //check for left
                traverseRightBoundry(node->left, rightBoundrySol);
            }
        }

        void traverseToLeafNodes(Node* node, Node* root, std::vector<int>& leafBoundrySol) {
            if (node != root && node != nullptr && node->left == nullptr && node->right == nullptr) {
                //leaft node
                leafBoundrySol.push_back(node->data);
            }
            else if (node == nullptr) {
                return; //break
            }
            //check left subtree tree
            traverseToLeafNodes(node->left, root, leafBoundrySol);
            //check right subtree
            traverseToLeafNodes(node->right, root, leafBoundrySol);
        }

        vector <int> boundary(Node* root)
        {
            std::vector<int> sol;
            //first figure out left side nodes

            if (root == nullptr) {
                return {};//empty
            }
            std::vector<int> leftBoundry;
            std::stack<int> rightBoundry;

            leftBoundry.push_back(root->data);

            traverseLeftBoundry(root->left, leftBoundry);
            //cout<<"Checked left boundry"<<endl;
            traverseToLeafNodes(root, root, leftBoundry);
            //cout<<"Checked leaf nodes"<<endl;
            traverseRightBoundry(root->right, rightBoundry);
            //cout<<"Checked right nodes"<<endl;
            while (rightBoundry.size() > 0) {
                leftBoundry.push_back(rightBoundry.top());
                rightBoundry.pop();
            }
            return leftBoundry;
        }
    };


struct IsBst {
    int size;
    int min;
    int max;
};
class Solution {
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    IsBst _isBst(Node* node) {
        if (node == nullptr) {
            return { 0, INT_MAX, INT_MIN };
        }

        auto leftBst = _isBst(node->left);
        auto rightBst = _isBst(node->right);

        //bool isMySelfBst = leftBst.isBst && rightBst.isBst;
        bool isMySelfBst = true;

        if (node->left != nullptr && leftBst.max >= node->data) {
            isMySelfBst = false;
        }
        if (node->right != nullptr && rightBst.min <= node->data) {
            isMySelfBst = false;
        }

        if (!isMySelfBst) {
            return { max(leftBst.size, rightBst.size), INT_MIN, INT_MAX };
        }
        else { // I'm following BST prop
            int minVal = INT_MAX;
            if (node->left != nullptr) {
                minVal = min(leftBst.min, node->left->data);
            }
            else {
                minVal = node->data;
            }
            int maxVal = INT_MIN;
            if (node->right != nullptr) {
                maxVal = max(rightBst.max, node->right->data);
            }
            else {
                maxVal = node->data;
            }
            return { leftBst.size + rightBst.size + 1,
                minVal, maxVal };

        }


    }
    int largestBst(Node* root)
    {
        //Your code here
        return _isBst(root).size;
    }
};
typedef struct Node node_t;
bool _isSymmetric(node_t* node1, node_t* node2) {
    if (node1 == nullptr && node2 == nullptr) {
        return true;
    }
    if (node1 == nullptr || node2 == nullptr) {
        return false;
    }
    //cout<<"Now checking node1:" << node1->data<<" and node2:"<<node2->data
    //<<endl;
    if (node1->data == node2->data) {
        return _isSymmetric(node1->right, node2->left) &&
            _isSymmetric(node1->left, node2->right);
    }
    else {
        // cout<<"Returning false"<<endl;
        return false;
    }
}
bool isSymmetric(struct Node* root)
{
    if (root == nullptr) {
        return true;
    }
    return _isSymmetric(root->left, root->right);
}

int main()
{
    std::cout << "Hello World!\n";
}
