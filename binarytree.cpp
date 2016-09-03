#include "iostream"

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

int main()
{
	/*
	  	 3 
	    / \
	   1   5
	  / \
	 0   7
	
	*/
	
	link root = new node(3, NULL, NULL);
	root->l = new node(1, NULL, NULL);
	root->r = new node(5, NULL, NULL);

	root->l->l = new node(0, NULL, NULL);
	root->l->r = new node(7, NULL, NULL);
	traverse(root);
	cout << '\n';
	return 0;
}