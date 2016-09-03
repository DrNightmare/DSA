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

link makeCopy(link start) {
	link temp = start;
	link head = temp;
	link x = NULL;
	link prev = NULL;
	while(temp != NULL) {
		x = new node(temp->data, NULL);
		if (prev != NULL) prev->next = x;
		prev = x;
		temp = temp->next;
	}
	return head;
}

int main()
{
	link head = createList(20);
	printList(head);

	link head2 = makeCopy(head);
	printList(head2);

	return 0;
}