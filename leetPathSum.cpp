/*
437. Path Sum III

https://leetcode.com/problems/path-sum-iii/

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11



root = 

[10,5,-3,3,2,null,11,null,-2,null,1]

sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
   \   \
   -2   1

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {

    	int count = 0;

    	count = visitTree(root, sum);

        return count;

    	/*
        vector<int> bran;
        queue<TreeNode*> qNode;
        
        if (root == nullptr) {
            return 0;
        }
        
        qNode.push(root);
        bran.push_back(root->val);
        
        // create a root to leave branch, so that to calculate
        //    the sum in each branch.        
        
        TreeNode* currNode = root;
        
        while (1)  {
            if (currNode->left != nullptr) {
                currNode = currNode->left;
                bran.push_back(currNode->val);
                qNode.push(currNode);    
            }
            else if (currNode->right != nullptr) {
                currNode = currNode->right;
                bran.push_back(currNode->val);
                qNode.push(currNode);    
            }
            else {
                break;
            }
        }
        */
        
    }


int visitTree(TreeNode* root, int sum) {
		int count = 0;
        vector<int> trace;
        stack<TreeNode*> qNode;

        TreeNode* curr = root;

        qNode.push(curr);
        trace.push_back(curr->val);

        while (!qNode.empty()) {
            if (curr->left != NULL) {
                curr = curr->left;
                qNode.push(curr);
                trace.push_back(curr->val);
            }
            else if (curr->right != NULL) {
                curr = curr->right;
                qNode.push(curr);
                trace.push_back(curr->val);
            }
            else {

            	//Debug code to print the path from root to leaf.
            	/*
                for (auto x: trace) {
                    cout<<x<<" ";
                }
                cout<<endl;
                */
                // Now vector<int> trace hold the 
                count += vCalc(trace, sum);

                while (!qNode.empty()) {
                    TreeNode* rmNode = qNode.top();
                    qNode.pop();
                    if (qNode.empty()) {
                        break;
                    }
                    //cout<<"Pop "<<rmNode->val<<endl;
                    trace.pop_back();
                    TreeNode* parent = qNode.top();

                    if (rmNode == parent->left) {
                        if (parent->right != NULL) {
                            curr = parent->right;
                            qNode.push(curr);
                            trace.push_back(curr->val);
                            break;
                        }
                    }
                    else if (rmNode == parent->right) {
                    	count += vCalc(trace, sum);
                    }

                }
                
            }
        }

        return count;
    }

    int vCalc(vector<int>& trace, int sum) {
    	int n = trace.size();

    	int curr = 0;
    	int count = 0;

    	for (int i=n; i>0; i--) {
    		curr += trace[i-1];
    		if (curr == sum) {
    			count++;
    		}
    	}

    	return count;
    }


};



void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int sum = stringToInteger(line);
        
        int ret = Solution().pathSum(root, sum);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}