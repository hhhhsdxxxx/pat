#include <iostream>

using namespace std;

void mark(int **road, int *through, int *path, int N){
	for(int i = 0; i < N; i++){
		if(through == 1){
			for(int j = 0; j < N; j++){
				if(road[i][j] > 0){
					if(path[j] == -1)
						path[j] = path[i]+road[i][j];
					else {
						if(path[i]+road[i][j] < path[j])
							path[j] = path[i]+road[i][j];
					}
				}
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int N, M, c1, c2;
	cin >> N >> M >> c1 >> c2;
	int *survive = new int[N];
	for(int i = 0; i < N; i++)
		cin >> survive[i];
	int **road = new int*[N];
	for(int i = 0; i < N; i++)
		road[i] = new int[N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == j)
				road[i][j] = 0;
			else
				road[i][j] = -1; 
		}
	}
	for(int k =0 ; k < N; k++){
		int i, j, l;
		cin >> i >> j >> l;
		road[i][j] = road[j][i] = l;
	}

	int *path = new int[N];
	int *through = new int[N];
	for(int i = 0; i < N; i++)
		path[i] = through[i] = -1;

	return 0;
}