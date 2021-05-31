#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
long long INF = 1000000000;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int n, m;
int total_towns, end;
cin >> total_towns >> end;
int totalroads;
cin >> totalroads;
vector <vector < vector<int>>> towns;
for (int i = 0; i < total_towns; i++){
	vector<vector<int>> a;
	towns.push_back(a);
}
while (totalroads--) {
	int first, second, time, max;
	cin >> first >> second >> time >> max;
	towns[first - 1].push_back({ second - 1, time, max });
	towns[second - 1].push_back({ first - 1, time, max });
}
cin >> n >> m;
set < pair<int, int>> unused;
vector<long long> dist(total_towns, INF);
dist[0] = 0;
unused.insert({ 0, 0 });
while (!unused.empty()) {
	int u = unused.begin()->second;
	unused.erase(unused.begin());
	for (auto a : towns[u]) {
		if (dist[u] + a[1] < dist[a[0]] && (m + n) < a[2]) {
			unused.erase({ dist[a[0]], a[0] });
			dist[a[0]] = dist[u] + a[1];
			unused.insert({ dist[a[0]], a[0] });
		}
	}
}
if (dist[end - 1] == INF)cout << - 1 << '\n';
else cout << dist[end - 1]<<'\n';
return 0;
}
