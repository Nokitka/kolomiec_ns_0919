#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
using namespace std;
long long INF = 1000000000;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
long long a, b;
cin >> a >> b;
long long total = 0;
long long first, second, max = 0;
for (int i = a; i <= b; i++){
	if (abs(i) > 10) {
		first = stoi(to_string(abs(i)).substr(0, 2));
		second = (abs(i)) % 100;
		if (first - second != 0 && i % (first - second) == 0) {
			max = i;
			total++;
		}
	}
}
cout << total << ' ' << max;
return 0;
}
