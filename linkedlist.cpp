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

void printList(link start) {
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

// returns link to last node, so use like:
// link start = initCircularList(7)->next;
// to get link to the first node
link initCircularList(int n) {
	link circularList = new node(1, NULL);
	circularList->next = circularList;

	link x = circularList;
	for(int i = 2; i <= n; i++) x = (x->next = new node(i, circularList));
	return x;
}

void printCircularList(link start) {
	link temp = start;
	if (temp == NULL) return;
	while(temp->next != start) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << temp->data << ' ';
	cout << '\n';
}

int sizeOfCircularList(node *start) {
	link temp = start;

	int count = 1;
	while(temp->next != start) {
		count++;
		temp = temp->next;
	}
	return count;
}

int main()
{
	link head = createList(20);
	printList(head);

	link head2 = makeCopy(head);
	printList(head2);

	link circleStart = initCircularList(7)->next;
	printCircularList(circleStart);

	cout << sizeOfCircularList(circleStart) << '\n';

	return 0;
}