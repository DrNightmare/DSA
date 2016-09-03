#include "iostream"
#include "stack"
#include "queue"

#define REP(i, n) for(int i = 0; i < n; i++)

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

	cout << countNodes(root);
	cout << '\n';

	cout << getHeight(root);
	cout << '\n';
	return 0;
}