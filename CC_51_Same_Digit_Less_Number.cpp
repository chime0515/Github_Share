#include <iostream>
#include <string>
using namespace std;

void display(struct node *head);
struct node{
	char data;
	node * next;
};


void ininode(struct node * head, int n){
	head->data = n;
	head->next = NULL;
}

void addnote(struct node * head, char n){
	node * newnode = new node;
	newnode->data = n;
	newnode->next = NULL;

	node * cur = head;
	while (cur){
		if (cur->next == NULL){
			cur->next = newnode;
			return;
		}
		cur = cur->next;
	}
}

void insertfront(struct node **head, char n){
	node * newnode = new node;
	newnode->data = n;
	newnode->next = *head;
	*head = newnode;
}

struct node * searchnode(struct node *head, char n){
	node * cur = head;
	while (cur){
		if (cur->data == n) return cur;
		cur = cur->next;
	}
	cout << "no node " << n << " in list.\n";
}

bool deletenode(struct node **head, node *ptrdel){
	node * cur = *head;
	if (ptrdel == *head){
		*head = cur->next;
		delete ptrdel;
		return true;
	}

	while (cur){
		if (cur->next == ptrdel){
			cur->next = ptrdel->next;
			delete ptrdel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

void display(struct node *head){
	node *list = head;
	while (list){
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}

void SORT(struct node * head){
	for (node *index = head; index->next != NULL; index = index->next) {
		for (node *selection = index->next; selection != NULL; selection = selection->next) {
			if (index->data > selection->data) {
				swap(index->data, selection->data);
			}
		}
	}
}

int getDecreasingChars(string number, struct node *decreasing){
	int firstDecreasing = number.length() - 1;
	for (; firstDecreasing > 0; --firstDecreasing){
		char curChar = number[firstDecreasing];
		char preChar = number[firstDecreasing - 1];
		if (firstDecreasing == number.length() - 1)
			ininode(decreasing, curChar);
		else
			addnote(decreasing,curChar);

		if (curChar > preChar){
			break;
		}
	}
	return firstDecreasing;
}

bool isGreatestNumber(int firstDecreasing){
	return firstDecreasing == 0;
}

char swapLeastGreater(struct node * chars, char target){
	node * head = chars;
	char find = '9';
	while (chars){
		char value = chars->data;
		if (value > target&&value < find){
			find = value;
		}
		chars = chars->next;
	}
	//cout << "find= " << find << endl;
	addnote(head, target);
	//display(head);
	deletenode(&head, searchnode(head,find));
	return find;

}

string getLeastGreaterNumber(string number){
	struct node * decreasingChars=new node;
	int firstDecreasing;
	firstDecreasing = getDecreasingChars(number, decreasingChars);
	//display(decreasingChars);
	
	if (isGreatestNumber(firstDecreasing)){
		return "";
	}

	string prefix = "";
	string stringbuiler = "";
	if (firstDecreasing > 1)
		prefix = number.substr(0, firstDecreasing - 1);
	//cout << "prefix = " << prefix << endl;
	char target = number[firstDecreasing - 1];
	//cout << "target = " << target << endl;
	char leastGreater = swapLeastGreater(decreasingChars, target);
	//cout << "leastGreater = " << leastGreater << endl;

	stringbuiler += leastGreater;
	//cout << "stringbuilder = " << stringbuiler << endl;
	SORT(decreasingChars);
	stringbuiler = prefix + stringbuiler;
	//cout << "stringbuilder = " << stringbuiler << endl;
	while (decreasingChars)
	{
		stringbuiler += decreasingChars->data;
		decreasingChars = decreasingChars->next;
	}
	return stringbuiler;
}



int main(){
	cout << "orignal number: 34722641\t" << endl;
	cout << "new number: \t"<<getLeastGreaterNumber("34722641") << endl;
	system("pause");
	return 0;
}
