#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<fstream>
#include<map>
using namespace std;
long long INF = 1000000000;

vector<long long> todigit(long long what) {
vector<long long> ret;
long long div = 2;
while (what > 1)
{
	while (what % div == 0)
	{
		what /= div;
		ret.push_back(div);
		if (ret.size() == 4)return ret;
	}
	div++;
}
return ret;
}

void zaliv(vector<vector<int>>& mas, int x, int y, int newcolor, int colortochange) {
	set<pair<int, int>> que = { {x,y} };
	while (que.size() != 0) {
		int nowx = que.begin()->first;
		int nowy = que.begin()->second;
		que.erase(que.begin());
		mas[nowx][nowy] = newcolor;
		if (nowx + 1 < mas.size() && mas[nowx + 1][nowy] == colortochange) {
			que.insert({ nowx + 1, nowy });
		}
		if (nowx - 1 >= 0 && mas[nowx - 1][nowy] == colortochange) {
			que.insert({ nowx - 1, nowy });

		}
		if (nowy + 1 < mas[nowx].size() && mas[nowx][nowy + 1] == colortochange) {
			que.insert({ nowx, nowy + 1 });
		}
		if (nowy - 1 >= 0 && mas[nowx][nowy - 1] == colortochange) {
			que.insert({ nowx, nowy - 1 });
		}
	}
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int n, m;
cin >> n >> m;
vector<vector<int>> matr;
for (int i = 0; i < n; i++)
{
	vector<int> a(m);
	matr.push_back(a);
}
int x, y;
cin >> x >> y;
x--; y--;
int nowcolor;
cin >> nowcolor;
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++){
		cin >> matr[i][j];
	}
}

zaliv(matr, y, x, nowcolor, matr[y][x]);
for (int i = 0; i < n; i++){
	for (int j = 0; j < m; j++){
	cout << matr[i][j] << ' ';
	}
cout << '\n';
}
return 0;
}
