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
  int n, m;
  cin >> n >> m; 
  vector<pair<int, ll>> cand(n);
  for(int i = 0; i < n; i++)
  {
    int s;
    ll r;
    cin >> s >> r;
    cand[i] = {s, r};
  }
  //array for each subject
  vector<vector<ll>> subject(m, vector<ll>());
  for(int i = 0; i < n; i++)
  {
    pair<int, ll> current  = cand[i];
    subject[current.first - 1].push_back(current.second);
  }
  //sort
  for(int i = 0; i < m; i++)
  {
    sort(subject[i].begin(), subject[i].end());
    reverse(subject[i].begin(), subject[i].end());
  }
  //calc cumulative sum for each subject
  vector<vector<ll>> subject_sum(m, vector<ll>());
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < subject[i].size(); j++)
    {
      if(j == 0)
      {
        subject_sum[i].push_back(subject[i][j]);
      }else{
        subject_sum[i].push_back(subject_sum[i][j - 1] + subject[i][j]);
      }
    }
  } 
  //sort subject vector by size of vector
  vector<pair<int, int>> subject_size(m);
  for(int i = 0; i < m; i++)
  {
    subject_size[i] = {subject[i].size(), i};
  }
  sort(subject_size.begin(), subject_size.end());
  reverse(subject_size.begin(),subject_size.end());
  //find max
  ll max_result = 0;
  for(int i = 0; i < subject_size.front().first; i++)
  {
    ll temp = 0;
    for(int j = 0; j < m; j++)
    {
      int index = subject_size[j].second;
      if(subject_sum[index].size() <= i) break;
      if(subject_sum[index][i] < 0) continue;
      temp += subject_sum[index][i];
    }
    max_result = max(temp, max_result);
  }
  cout << max_result << endl;
  return 0;
}
