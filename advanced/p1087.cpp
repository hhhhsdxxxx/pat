#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> s_path;
int b_happ = 0, rom, cnt = 0;

struct city_happins{
	string cn;
	int happiness, mpath;
	bool isview;
	vector<int> before;

	city_happins():cn(""),happiness(0),mpath(-1),isview(false){}

};

int find_small(city_happins *citys, int N){
	int smallest = -1, index = 0;
	for(int i = 1; i < N; ++i){
		if(citys[i].mpath != -1 && !citys[i].isview){
			if(smallest == -1 || smallest > citys[i].mpath){
				smallest = citys[i].mpath;
				index = i;
			}
		}
	}
	return index;
}

void make_sign(int **path, city_happins *citys, int pos, int N){
	for(int i = 0; i < N; ++i){
		if(pos != i && path[pos][i] != -1){
			if(citys[pos].mpath+path[pos][i] <= citys[i].mpath || citys[i].mpath == -1){
				if(citys[pos].mpath+path[pos][i] < citys[i].mpath)
					(citys[i].before).clear();
				citys[i].before.push_back(pos);
				citys[i].mpath = citys[pos].mpath+path[pos][i];
			}
		}
	}
	citys[pos].isview = true;
}

void search(city_happins *citys, vector<int> &p, int happ, int pos){
	p.push_back(pos);
	if(pos == 0){
		cnt++;
		if(happ > b_happ){
			b_happ = happ;
			s_path.clear();
			s_path.assign(p.begin(), p.end());
		}
		else if(happ == b_happ){
			if(p.size() < s_path.size()){
				s_path.clear();
				s_path.assign(p.begin(), p.end());
			}
		}
	}
	if(citys[pos].before.empty()){
		p.pop_back();
		return;
	}
	for(unsigned int i = 0; i < citys[pos].before.size(); ++i)
		search(citys, p, happ+citys[pos].happiness, citys[pos].before.at(i));
	p.pop_back();
}

void find_way(int **path, city_happins *citys, int N){
	make_sign(path, citys, 0, N);
	int k = find_small(citys, N);
	while(k){
		make_sign(path, citys, k, N);
		k = find_small(citys, N);
	}
	if((citys[rom].before).empty())
		return;
	vector<int> tmp;
	search(citys, tmp, 0, rom);
}

int main(int argc, char const *argv[])
{
	int N, K, **path;
	string s_city;
	cin >> N >> K >> s_city;
	path = new int*[N];
	for(int i = 0; i < N; ++i)
		path[i] = new int[N];
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			path[i][j] = -1;
	map<string, int> cid;
	city_happins *citys = new city_happins[N];
	citys[0].cn = s_city;
	citys[0].mpath = 0;
	cid.insert(pair<string, int>(citys[0].cn, 0));
	for(int i = 1; i < N; ++i){
		cin >> citys[i].cn >> citys[i].happiness;
		if(citys[i].cn == "ROM")
			rom = i;
		cid.insert(pair<string, int>(citys[i].cn, i));
	}
	for(int i = 0; i < K; ++i){
		string city1, city2;
		int paths, id1, id2;
		cin >> city1 >> city2 >> paths;
		id1 = cid.find(city1)->second;
		id2 = cid.find(city2)->second;
		path[id1][id2] = path[id2][id1] = paths;
	}
	find_way(path, citys, N);
	cout << cnt << " " << citys[rom].mpath << " " << b_happ << " " << b_happ/(s_path.size()-1) << endl;
	while(!s_path.empty()){
		int k = s_path.back();
		if(k != 0)
			cout << "->";
		cout << citys[k].cn;
		s_path.pop_back();
	}
	return 0;
}