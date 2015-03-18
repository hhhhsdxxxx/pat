/*
***注意点：
***整数的比较远快于字符串
***可能存在多余的节点（很小的细节，占比分数比较小）
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

struct node{
	int address;
	int data;
	int naddress;
};

class LinkedList{
private:
	node *head;
	int headstr;
	int size;
	int r;
public:
	LinkedList(){
		head = NULL;
		size = 0;
	}

	LinkedList(int size, int r, int headstr){
		head = new node[size];
		this->size = size;
		this->r = r;
		this->headstr = headstr;
	}

	void getAllnode(){
		for(int i = 0; i < size; i++)
			cin >> head[i].address >> head[i].data >> head[i].naddress;
	}

	void swap(int i, int j){
		int temp;
		temp = head[i].address;
		head[i].address = head[j].address;
		head[j].address = temp;
		temp = head[i].data;
		head[i].data = head[j].data;
		head[j].data = temp;
		temp = head[i].naddress;
		head[i].naddress = head[j].naddress;
		head[j].naddress = temp;
	}

	void sort(){
		for(int i = 0; i < size; i++)
			if(head[i].address == headstr){
				swap(i, 0);
				break;
			}
		int k = 1;
		while(k < (size-1)){
			for(int i = k; i < size; i++){
				if(head[k-1].naddress == head[i].address){
					swap(i, k);
					break;
				}
			}
			k++;
		}
		for(size = 0; head[size].naddress != -1; size++);
		size++;	
	}

	void print_info(){
		int next = 0;
		for(int i = 0; i+r-1 < size; i += r){
			next = i+r;
			int d = r;
			while(d--){
				printf("%05d %d ", head[i+d].address, head[i+d].data);
				if(d == 0){
					if((i+r) < size){
						if((i+r+r) <= size)
							printf("%05d\n", head[i+r+r-1].address);
						else{
							printf("%05d\n", head[i+r].address);
						}
					}
					else
						cout << "-1" << endl;
				}
				else
					printf("%05d\n", head[i+d-1].address);
			}
		}
		for(; next < size-1; next++)
			printf("%05d %d %05d\n", head[next].address, head[next].data, head[next].naddress);
		if(next < size)
			printf("%05d %d -1\n", head[next].address, head[next].data);
	}
};

int main(int argc, char const *argv[])
{
	int address;
	int N, K;
	cin >> address >> N >> K;
	LinkedList my(N, K, address);
	my.getAllnode();
	if(address == -1){
		cout << "-1" << endl;
		return 0;
	}
	my.sort();
	my.print_info();
	return 0;
}