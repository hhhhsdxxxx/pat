#include <iostream>
#include <vector>

using namespace std;

struct group{
	int num;
	int total;
};

class wjj{
	vector<group> v;
	int max;
	int index;
public:
	wjj(){
		max = -1;
		index = 0;
	}

	void add(int i, int score){
		group *ptr = Exist(i);
		if(ptr != NULL){
			ptr->total += score;
			if(ptr->total > max){
				max = ptr->total;
				index = ptr->num;
			}
		}
		else{
			group *p = new group;
			p->num = i;
			p->total = score;
			v.push_back(*p);
			if(p->total > max){
				max = p->total;
				index = i;
			}
		}

	}

	group *Exist(int i){
		for(vector<group>::iterator it = v.begin(); it < v.end(); it++)
			if(it->num == i)
				return &(*it);
		return NULL;	
	}

	void print_info(){
		if(index != 0)
			cout << index << " " << max << endl;
	}
};


int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	wjj whole;
	int num, score;
	while(N--){
		cin >> num >> score;
		whole.add(num, score);
	}
	whole.print_info();
	return 0;
}