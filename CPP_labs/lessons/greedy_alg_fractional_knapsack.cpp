#include <iostream>
#include <algorithm>

struct Item
{
    public:
        int value, weight;

        Item(int value, int weight): value(value), weight(weight) {
            
        }
};

// compare function:
bool cmp(Item a, Item b) {
    double r1 = (double) a.value / a.weight;
    double r2 = (double) b.value / b.weight;

    return r1 > r2;
}

double fractional_knapsack(int W, Item arr[], int n) {
    std::sort(arr, arr + n, cmp);

    int cur_weight = 0;
    double tot_value = 0.0;

    for (int i = 0; i < n; i ++) {
        if (cur_weight + arr[i].weight <= W) {
            cur_weight += arr[i].weight;
            tot_value += arr[i].value;
        } else { // начинаем делить, если можно делить в задаче
            int rem_weight = W - cur_weight;    // rem - ramaining
            tot_value += arr[i].value * ( (double) rem_weight / arr[i].weight);     // мы заполняем оставшуюся часть, разделив предмет

            break;
        }
    }
    return tot_value;
}

int get_len_of_static(Item arr[]) {
    return sizeof(arr) / sizeof(arr[0]);
}

int main() {
    int W = 50;

    Item arr[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int n = get_len_of_static(arr);

    return 0;
}