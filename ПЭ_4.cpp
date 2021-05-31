#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<fstream>
#include<map>
using namespace std;
long long INF = 1000000000;
vector<string> allwords;
int n, m, k;
void rec(string now, int gl) {
	if (now.size() == n && gl >= m) {
		allwords.push_back(now);
	return;
}
	if (now.size() < n) {
		rec(now + 'I', gl + 1);
		rec(now + 'A', gl + 1);
		rec(now + 'N', gl);
		rec(now + 'F', gl);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	rec("", 0);
	sort(allwords.begin(), allwords.end());

	if (k >= allwords.size()) cout << "ERROR\n";
	else {
		cout << allwords.size() << ' ' << allwords[k - 1] << '\n';
	}
return 0;
}