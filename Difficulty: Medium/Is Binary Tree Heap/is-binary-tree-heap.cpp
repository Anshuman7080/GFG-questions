//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/




class Solution {
public:
    int count(struct Node* root) {
        if (!root) {
            return 0;
        }
        return count(root->left) + count(root->right) + 1;
    }

    bool CBT(struct Node* root, int index, int size) {
        if (!root) {
            return true; 
        }
        if (index >= size) {
            return false;
        }
        bool left = CBT(root->left, 2 * index + 1, size);
        bool right = CBT(root->right, 2 * index + 2, size);
        return left && right;
    }

    bool maxHeap(struct Node* root) {
        if (root->left) {
            if (root->data < root->left->data) {
                return false;
            }
            if (!maxHeap(root->left)) {
                return false;
            }
        }
        if (root->right) {
            if (root->data < root->right->data) {
                return false;
            }
            return maxHeap(root->right);
        }
        return true;
    }

    bool isHeap(struct Node* tree) {
        int cnt = count(tree);
        if (!CBT(tree, 0, cnt)) {
            return false;
        }
        return maxHeap(tree);
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends