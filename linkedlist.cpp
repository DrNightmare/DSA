#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

struct node {
	int data;
	node *next;

	// constructor to initialize data at the new node
	node (int x, node *t) {
		data = x;
		next = t;
	};
};

typedef node *link;

void printList(node *start) {
	link temp = start;
	while(temp != NULL) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << '\n';
}

link createList(int n) {
	link head = new node(1, NULL);
	link x = head;
	for(int i = 2; i <= n; i++) x = (x->next = new node(i, NULL));
	return head;	
}

int main()
{
	link head = createList(20);
	printList(head);

	return 0;
}