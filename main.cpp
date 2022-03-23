#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
  auto getRetryingCount = [](std::vector<int>& vec, int& number) {
    std::unordered_set<int> set(vec.begin(), vec.end());
    return set.count(number);
  };

  std::vector<int> vec =
      std::initializer_list<int>{1, 2, 2, 2, 3, 4, 5, 4, 5, 4, 5};

  std::cout << "Enter the number:" << std::endl;
  std::cout << ">>> ";
  int number = 0;
  std::cin >> number;
  std::cout << getRetryingCount(vec, number) << std::endl;

  auto getRetryingSet = [](std::vector<int>& vec) {
    std::unordered_set<int> set(vec.begin(), vec.end());
    std::vector<int> buff_vec;
    for (auto& i : set) {
      buff_vec.push_back(i);
    }
    auto vec_2 = std::make_unique<std::vector<int>>(buff_vec);
    return vec_2;
  };

  auto vec_2 = std::make_unique<std::vector<int>>();
  vec_2 = getRetryingSet(vec);

  for (auto& i : *vec_2) {
    std::cout << i << " ";
  }
}