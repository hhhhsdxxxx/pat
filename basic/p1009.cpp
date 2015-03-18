#include <iostream>
#include <string>

using namespace std;

class word{
public:
	string wd;
	word *next;
	word(){
		wd = "";
		next = NULL;
	}
};

class sentence{
	word *head;
public:
	sentence(word *head){
		this->head = head;
	}

	sentence(){
		head = NULL;
	}

	void addone(struct word *add){
		if(head == NULL)
			head = add;
		else{
			add->next = head;
			head = add;
		}
	}

	void showall(){
		word *ptr = head;
		if(ptr != NULL){
			cout << ptr->wd;
			ptr = ptr->next;
		}
		while(ptr != NULL){
			cout << " " << ptr->wd;
			ptr = ptr->next;
		}
	}
};

int main(){
	string str;
	word *p;
	sentence obj;
	while((cin >> str) != NULL){
		p = new word();
		p->wd = str;
		obj.addone(p);
	}
	obj.showall();
	return 0;
}