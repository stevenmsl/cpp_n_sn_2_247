#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>
using namespace sol247;
using namespace std;

/*takeaways
  - if you know you can consider the odd and even digit numbers
    separately, it will be much easier
  - N = 0, you can produce nothing: ""
  - N = 2, so how can we produce all possible SNs?
    - "1" + "" + "1" = "11" (you flipped 1 still got 1)
    - "6" + "" + "9" = "69" (you flipped 6 and got 9)
    - "88"
    - "96"
  - N=2 is based on the work done in N=0
  - N=1 we got ["0","1","8"]
  - N=3 we need to base the work done in N=1
    - "0"
      - "1" + "0" + "1" = "101"
      - other can produce from "0" are "609","808","906"
    - "1"
      - "111","619","818","916"
    - "8"
      - "181","689","888","986"
*/

/*
  - m is changing like this 6 -> 4 -> 2 -> 0
    or 5 -> 3 -> 1 depending on it's an even or
    add number
*/
vector<string> Solution::_find(int m, int N)
{
  auto nums = vector<string>();
  /* two edge cases
     - one for even number the other odd
  */
  if (m == 0)
    return {""};
  if (m == 1)
    return {"0", "1", "8"};

  /* build the foundation first from
     the numbers with two fewer digits
  */
  auto base = _find(m - 2, N);

  for (auto num : base)
  {
    /* during the process of building
       the result it's fine to have
       numbers look like these: 00
       as later we will add non-zero
       digit to its front and back
       when backtracking to form
       a valid number
    */
    if (m != N)
      nums.push_back("0" + num + "0");

    /*we have very limited combinations here,
      so we just list them out one by one
    */
    nums.push_back("1" + num + "1");
    nums.push_back("6" + num + "9");
    nums.push_back("8" + num + "8");
    nums.push_back("9" + num + "6");
  }

  return nums;
}

vector<string> Solution::find(int N)
{
  return _find(N, N);
}