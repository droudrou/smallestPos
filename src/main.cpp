// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
  for (auto &el : vec) {
    os << el << ' ';
  }
  return os;
}

int solution(vector<int> &A);
int moveNegativeNbrs(vector<int> &A);
int findMissing(vector<int> &A);

int main() {

  std::vector<int> vec1 = {1, 3, 6, 4, 1, 2};
  std::cout << "\n solution(vec1) = " << solution(vec1) << std::endl;

  std::vector<int> vec2 = {-1, -3};
  std::cout << "\n solution(vec2) = " << solution(vec2) << std::endl;

  std::vector<int> vec3 = {1, 2, 3};
  std::cout << "\n solution(vec3) = " << solution(vec3) << std::endl;
}

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {

  std::cout << "\n Original table : " << A << "\n";

  // write your code in C++14 (g++ 6.2.0)
  int solution = 1;

  int negCount = moveNegativeNbrs(A);

  std::cout << "negCount =" << negCount;

  std::vector<int> positiveTab;

  if (negCount < A.size()) {
    for (int ik = negCount; ik < A.size(); ++ik) {
      positiveTab.push_back(A[ik]);
    }

    std::sort(positiveTab.begin(), positiveTab.end(), std::less<int>());

    std::cout << "\n re-ordered table : " << positiveTab;

    solution = findMissing(positiveTab);
  }

  return solution;
}

int findMissing(vector<int> &A) {
  int solution = 1;
  bool found = false;

  if (A[0] == 1) {
    int refValue = 1;
    int ik = 1;
    for (ik = 1; ik < A.size(); ++ik) {
      if (A[ik] - refValue > 1) {
        solution = refValue + 1;
        found = true;
        break;
      } else {
        refValue = A[ik];
      }
    }

    if (found == false)
      solution = A[ik - 1] + 1;
  }

  return solution;
}

int moveNegativeNbrs(vector<int> &A) {
  int negCount = 0;

  for (int ik = 0; ik < A.size(); ++ik) {
    if (A[ik] <= 0) {
      int temp = A[ik];
      A[ik] = A[negCount];
      A[negCount] = temp;
      negCount++;
    }
  }

  return negCount;
}
