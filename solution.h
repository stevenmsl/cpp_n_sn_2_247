#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol247
{
  class Solution
  {
    static vector<string> _find(int m, int N);

  public:
    static vector<string> find(int N);
  };
}
#endif