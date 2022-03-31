#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol247;

/*
Input:  n = 2
Output: ["11","69","88","96"]
*/

tuple<int, vector<string>>
testFixture1()
{
  return make_tuple(2, vector<string>{"11", "69", "88", "96"});
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << Util::toString(get<1>(f)) << endl;
  auto result = Solution::find(get<0>(f));
  cout << "result: " << Util::toString(result) << endl;
}

main()
{
  test1();
  return 0;
}