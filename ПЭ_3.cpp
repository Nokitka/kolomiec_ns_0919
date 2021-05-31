#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<fstream>
#include<map>
using namespace std;
long long INF = 1000000000;


int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ifstream file;
file.open("input.txt", ios::in);
string s;
file >> s;
file.close();
map<char, vector<int>> alllessons;
for (int i = 0; i < s.size(); i++)
{
	alllessons[s[i]].push_back(i);
}
int maxlength = -1;
char les;
for (auto p : alllessons) {
	if (p.second.size() >= 2) {
		if (maxlength < p.second[p.second.size() - 1] - p.second[0] - 1) {
			maxlength = p.second[p.second.size() - 1] - p.second[0] - 1;
			les = p.first;
		}
	}
}
if (maxlength != -1) cout << les << ' ' << maxlength << '\n';
else cout << 0 << '\n';
return 0;
}