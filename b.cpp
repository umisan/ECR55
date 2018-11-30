#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;
using ll = long long int;

int main()
{
  int n;
  cin >> n;
  vector<int> s;
  int g_count = 0;
  for(int i = 0; i < n; i++)
  {
    char c;
    cin >> c;
    if(c == 'G')
    {
      g_count++;
      s.push_back(1);
    }else{
      s.push_back(0);
    }
  } 
  vector<int> temp;
  for(int i = 0; i < n; i++)
  { 
    if(s[i] == 1)
    {
      temp.push_back(1);
    }else{
      if(i != 0 && s[i - 1] == 0)
      {
        temp.push_back(-1);
      }
      temp.push_back(0);
    }
  }
  vector<int> sum;
  int count = 0;
  for(int i = 0; i < temp.size(); i++)
  {
    if(temp[i] == 1)
    {
      count++;
    }else if(temp[i] == 0){
      if(count != 0)
      {
        sum.push_back(count);
      }
      count = 0;
    }else{
      sum.push_back(0);
    }
  }
  if(count != 0)
  {
    sum.push_back(count);
  } 
  /*for(auto e : sum)
  {
    cout << e << " ";
  }
  cout << endl;*/
  if(sum.size() == 1)
  {
    cout << sum[0] << endl;
  }else if(sum.size() == 2)
  {
    if(sum[0] == 0 && sum[1] == 0)
    {
      cout << 0 << endl;
    }else if(sum[0] == 0)
    {
      cout << sum[1] << endl;
    }else if(sum[1] == 0)
    {
      cout << sum[0] << endl;
    }else{
      cout << sum[0] + sum[1]<< endl;
    }
  }else{
    int max_b = 0;
    for(int i = 0; i < sum.size() - 1; i++)
    {
      int max_b_temp = 0;
      if(g_count > sum[i] + sum[i + 1])
      {
        max_b_temp = sum[i] + sum[i + 1] + 1;
      }else if(g_count == sum[i] + sum[i + 1]){
        max_b_temp = sum[i] + sum[i + 1];
      }else{
        max_b_temp = max(sum[i], sum[i + 1]);
      }
      max_b = max(max_b, max_b_temp);
    }
    cout << max_b << endl;
  }
	return 0;
}
