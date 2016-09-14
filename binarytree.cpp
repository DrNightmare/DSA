#include "iostream"
#include "stack"
#include "queue"
#include "iomanip"
#include "cstdlib"

#define REP(i, n) for(int i = 0; i < n; i++)
#define MIN -100
#define MAX 100

using namespace std;

struct node {
	int data;
	node *l, *r;

	node(int x, node *left, node *right) {
		data = x;
		l = left;
		r = right;
	};
};

typedef node *link;

void prettyPrint(link p, int indent=4)
{
    if(p != NULL) {
        if(p->r) {
            prettyPrint(p->r, indent+4);
        }
        if (indent) {
            cout << setw(indent) << ' ';
        }
        if (p->r) cout<<" /\n" << setw(indent) << ' ';
        cout<< p->data << "\n ";
        if(p->l) {
            cout << setw(indent) << ' ' <<" \\\n";
            prettyPrint(p->l, indent+4);
        }
    }
}

void traverse(link h) {
	if (h == NULL) return;
	traverse(h->l);
	cout << h->data << ' ';
	traverse(h->r);
}

// traverse using stack
void traverse2(link h) {
	if (h == NULL) return;
	stack<link> s;
	s.push(h);

	while(!s.empty()) {
		h = s.top();
		cout << h->data << ' ';
		s.pop();
		if (h->r != NULL) s.push(h->r);
		if (h->l != NULL) s.push(h->l);
	}
}

void levelTraverse(link h) {
	if (h == NULL) return;
	queue<link> q;
	q.push(h);
	while(!q.empty()) {
		h = q.front();
		cout << h->data << ' ';
		q.pop();
		if (h->l != NULL) q.push(h->l);
		if (h->r != NULL) q.push(h->r);
	}
}

int countNodes(link h) {
	if (h == NULL) return 0;
	return 1 + countNodes(h->l) + countNodes(h->r);
}

int getHeight(link h) {
	if (h == NULL) return -1;
	int u = getHeight(h->l);
	int v = getHeight(h->r);
	if (u > v) return u + 1;
	else return v + 1;
}

int countLeaves(link h) {
	if (h == NULL) return 0;
	if (h->l == NULL && h->r == NULL) return 1;
	return countLeaves(h->l) + countLeaves(h->r);
}

bool isBST(link h, int min, int max) {
	if (h == NULL) return true;

	if (h->data < min || h->data > max)	return false;
	
	return isBST(h->l, min, h->data - 1) && isBST(h->r, h->data + 1, max); 
}

// selects random node from the tree using reservoir sampling
link selectRandomNode(link h) {
	int nodeCount = 1;
	link selected = NULL;
	if (h == NULL) return h;
	stack<link> s;
	s.push(h);

	while(!s.empty()) {
		h = s.top();
		if (rand() % nodeCount == nodeCount - 1) selected = h;
		nodeCount++;
		s.pop();
		if (h->r != NULL) s.push(h->r);
		if (h->l != NULL) s.push(h->l);
	}

	return selected;
}

int main()
{
	/*
	  	 3 
	    / \
	   1   5
	  / \
	 0   7
	
	*/
	
	// create the above tree
	link root = new node(3, NULL, NULL);
	root->l = new node(1, NULL, NULL);
	root->r = new node(5, NULL, NULL);

	root->l->l = new node(0, NULL, NULL);
	root->l->r = new node(7, NULL, NULL);

	levelTraverse(root);
	cout << '\n';

	cout << "Number of nodes : " << countNodes(root) << '\n';
	cout << "Height of tree : " << getHeight(root) << '\n';
	cout << "Number of leaves : " << countLeaves(root) << '\n';
	cout << '\n';
	prettyPrint(root);

	cout << isBST(root, MIN, MAX) << '\n';

	// generate random seed
	srand(time(0));
	cout << selectRandomNode(root)->data << '\n';
	return 0;
}