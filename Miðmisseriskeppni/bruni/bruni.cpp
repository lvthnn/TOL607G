#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <limits>

using namespace std;

typedef pair<int, int> ii;
const int infinity = numeric_limits<int>::max();

int util(ii a, ii b) { return a.second > b.second; }

int main() {

  int n,t;
  cin >> n >> t;

  // read in routes
  vector<ii> v;
  for (int i = 0; i < n; i++) {
    int t_i, f_i;
    cin >> t_i >> f_i;

    v.push_back(make_pair(t_i, f_i));
  }

  int dur = t;
  bool T = true;
  int j;

  while (T) {
    T = false;
    int m = -infinity; // max{f_i - t_i} fyrir t_i <= t
    int fm;

    for (int i = 0; i < v.size(); i++) {
      if (v[i].first <= t) {
        if (v[i].second - v[i].first > m) {
          m = v[i].second - v[i].first;
          fm = v[i].second;
          j = i;
          T = true;
        }
        else if (v[i].second - v[i].first == m) {
          if (v[i].second >= fm) {
            m = v[i].second - v[i].first;
            fm = v[i].second;
            j = i;
            T = true;
          }
        }
      }
    }
    if (T) {
      t += m;
      v[j].first = infinity;
      dur += v[j].second;
    }
  }
  cout << dur << endl;
  return 0;
}
