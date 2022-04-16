// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>
#include <algorithm>

#define printl(x) std::cout<<x<<std::endl;
#define print(x) std::cout<<x;

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> solution;
    if (nums.size() < 4) {
        return solution;
    }
}
class VecComparator {
public:

    bool operator()(const std::vector<int>& x, const std::vector<int>& y) const {
        std::vector<int> x1(x), y2(y);
        std::cout << "Checking equality" << std::endl;
        std::sort(x1.begin(), x1.end());
        std::sort(y2.begin(), y2.end());
        return x1 == y2;
    }
};
struct VecHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        printl("Now hashing:");
        for (auto num : v) {
            print(num << ",");
        }
        printl("");
        size_t seed = 0;
        for (int i : v) {
            //seed ^= hasher(i);// +0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed += i;
        }
        printl("returning seed:" << seed);
        return seed;
    }
};
int main()
{
    auto cmp = [](std::vector<int>& x, std::vector<int>& y) {
        return (x == y);
    };
    std::unordered_set<std::vector<int>, VecHash, VecComparator> hashSet;
    std::vector<int> vec1{ 1,2,3,4 };
    std::vector<int> vec2{ 1,2,3,4 };
    printl("Is vec1 == vec2: " << (vec1 == vec2));
    hashSet.insert(vec1);
    hashSet.insert({2,3,4,5});
    if ((hashSet.insert({ 2,3,4,5 }).second)) {
        std::cout << " 2,3,4,5 was inserted";
    }
    hashSet.insert({4,2,3,5});

    std::cout << "Printing hash set elements:" << std::endl;
    for (auto set : hashSet) {
        for (auto num : set) {
            print(num << ",");
        }
        printl("");
    }
}

