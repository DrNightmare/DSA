#include "iostream"
#include "queue"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

struct node {
	int data;
	node *l;
	node *r;

	node(int x, node *left, node *right) {
		data = x;
		l = left;
		r = right;
	};
};

typedef node *link;

void insertIntoBST(link &root, int x) {
	if (root == NULL) {root = new node(x, NULL, NULL); return;}
	if (x == root->data) return;
	else if (x < root->data) insertIntoBST(root->l, x);
	else insertIntoBST(root->r, x);
}

void traverse(link h) {
	if (h == NULL) return;
	traverse(h->l);
	cout << h->data << ' ';
	traverse(h->r);
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

int main()
{
	/*
				6
			4		8
		2		5
			3

	*/
	link root = new node(6, NULL, NULL);
	int arr[] = {4, 8, 2, 5, 3};
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0; i < size; i++) insertIntoBST(root, arr[i]);
	traverse(root);
	cout << '\n';
	levelTraverse(root);
	cout << '\n';
	return 0;
}