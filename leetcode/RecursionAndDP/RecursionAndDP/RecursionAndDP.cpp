#include <iostream>
#include <cmath>
#include <vector>

//DP solution
int minEnergyForFrogJumps(std::vector<int>& arr, int ind, std::vector<int>& dpArray) {
    if (ind <= 0) {
        return 0;
    }
    if (dpArray[ind] != -1) {
        return dpArray[ind];
    }
    int right = 0;
    //frog can take either one jump(left) or two(right)
    int left = minEnergyForFrogJumps(arr, ind - 1, dpArray) + abs(arr[ind] - arr[ind - 1]);
    if(ind > 1)
        right = minEnergyForFrogJumps(arr, ind - 2, dpArray) + abs(arr[ind] - arr[ind - 2]);

    dpArray[ind] = std::min(left, right);

    return dpArray[ind];
}
// Tabulation method
int minEnergyForFrogJumpsTabMeth(std::vector<int>& arr, int ind, std::vector<int>& dpArray) {
    if (ind <= 0) {
        return 0;
    }

    dpArray[0] = 0;
    for (int i = 1; i < arr.size(); ++i) {
        int fs = dpArray[i - 1] + abs(arr[i] - arr[i - 1]);
        int ss = INT_MAX;
        if(i > 1)
            ss = dpArray[i - 2] + abs(arr[i] - arr[i - 2]);

        dpArray[i] = std::min(fs, ss);
    }
    return dpArray[arr.size() - 1];
}

int main()
{   
    std::vector<int> arr{ 10,30,35,60,70,75 };
    std::vector<int> dpArray(arr.size(), -1);
    int minEnergy = minEnergyForFrogJumps(arr, arr.size() - 1, dpArray);
    //int minEnergy = minEnergyForFrogJumpsTabMeth(arr, arr.size() - 1, dpArray);
    std::cout << "Min energy spent Tab meth:" << minEnergy << std::endl;
}
