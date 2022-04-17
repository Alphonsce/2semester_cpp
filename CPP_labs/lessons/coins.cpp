#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> amount_of_coins(int summ, std::vector<int> coins) {
    int n = coins.size(), cur_summ;

//     for (int i = 0; i < n; i++) {
//         while (coins[i] > summ)
//     }

}

int main() {
    int summ = 24;

    std::vector<int> coins = {1, 5, 15, 20};
    std::sort(coins.begin(), coins.end());
    
    amount_of_coins(summ, coins);
}