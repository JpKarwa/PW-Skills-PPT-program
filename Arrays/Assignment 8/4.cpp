/*
You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.
You always start to construct the **left** child node of the parent first if it exists.

**Input:** s = "4(2(3)(1))(6(5))"

**Output:** [4,2,6,3,1,5]
*/


#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int findIndex(string str, int si, int ei)
{
	if (si > ei)
		return -1;

	stack<char> s;

	for (int i = si; i <= ei; i++) {
		if (str[i] == '(')
			s.push(str[i]);
		else if (str[i] == ')') {
			if (s.top() == '(') {
				s.pop();
				if (s.empty())
					return i;
			}
		}
	}
	return -1;
}

Node* treeFromString(string str, int si, int ei)
{
	// Base case
	if (si > ei)
		return NULL;

	
	int num = 0;
	while(si <= ei && str[si] >= '0' && str[si] <= '9')
	{
	num *= 10;
	num += (str[si] - '0');
	si++;
	}

	Node* root = newNode(num);
	int index = -1;

	if (si <= ei && str[si] == '(')
		index = findIndex(str, si, ei);

	if (index != -1) {
		root->left = treeFromString(str, si + 1, index - 1);
		root->right = treeFromString(str, index + 2, ei - 1);
	}
	return root;
}

int main()
{
	string str = "4(2(3)(1))(6(5))";
	Node* root = treeFromString(str, 0, str.length() - 1);
	preOrder(root);
}
