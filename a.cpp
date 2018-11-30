#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;
using ll = long long int;

ll solve(ll n, ll x, ll y, ll d)
{
  ll result = 0;
  if(abs(y - x) % d == 0)
  {
    result += abs(y - x) / d;
    return result;
  }else{
    ll temp = 0;
    ll temp1 = 0;
    if((y - 1) % d == 0)
    {
      temp += ceil(double(x - 1) / d);
      temp += (y - 1) / d;
    }
    if((n - y) % d == 0)
    {
      temp1 += ceil(double(n - x) / d);
      temp1 += (n - y) / d;
    }
    if(temp == 0 && temp1 == 0)
    {
      return -1;
    }else{
      if(temp == 0)
      {
        return temp1;
      }else if(temp1 == 0)
      {
        return temp;
      }else{
        return min(temp, temp1);
      }
    }
  }
  return -1;
}

int main()
{
  int t;
  cin >> t;
  vector<ll> result(t);
  for(int i = 0; i < t; i++)
  {
    ll n, x, y, d;
    cin >> n >> x >> y >> d;
    result[i] = solve(n, x, y, d);
  }
  for(auto e : result)
  {
    cout << e << endl;
  }
	return 0;
}
