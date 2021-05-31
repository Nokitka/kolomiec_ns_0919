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

int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
long long a, b;
cin >> a >> b;
long long ans = 0, maxraz = -1, max = 0;
bool flag = true;
for (long long i = a; i <= b; i++)
{
	vector<long long> now = todigit(i);
	if (now.size() == 3) {
		if (now[0] % 10 == now[1] % 10 && now[1] % 10 == now[2] % 10 &&now[0]!=now[1]&&now[1]!=now[2]) {
			ans++;
			if (now[2] - now[0] > maxraz) {
				maxraz = now[2] - now[0];
				max = i;
			}
		//cout << ans << ' ';
		}
	}
	//if (i % 100 == 0)cout << i << '\n';
}
cout << ans << ' ' << max;
return 0;
}
