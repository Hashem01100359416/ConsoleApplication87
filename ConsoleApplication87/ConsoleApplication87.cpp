#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#define ll long long 
#define d double
#define endl "\n"
#define ios  std::ios_base::sync_with_stdio(0); cin.tie(0);
#define lli unsigned ll int
using namespace std;
lli mod = 1000000007;
ll mod2(ll a, ll b)
{
	return((a % mod) * (b % mod)) % mod;
}
ll pow(int x, int n)
{
	lli result = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			result = (result * x) % mod;
		}
		x = mod2(x, x);
		n = n / 2;
	}
	return result % mod;
}
int main()
{
	int n;
	cin >> n;
	int a[100000 + 15], f[100000 + 15] = { 0 };
	lli c = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		if (max < a[i])
		{
			max = a[i];
		}
		f[a[i]]++;
	}

	for (int i = 1; i <= max; i++)
	{
		if (f[i] > 0)
		{
			c += ((pow(2, f[i]) - 1)) % mod;
		}

		c = c % mod;
	}
	cout << c % mod;
}