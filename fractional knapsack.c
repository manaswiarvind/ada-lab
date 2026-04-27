#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

// 1. Swap function
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// 2. Sort function (by ratio descending)
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                swap(&items[i], &items[j]);
            }
        }
    }
}

// 3. Fractional Knapsack function
float fractionalKnapsack(struct Item items[], int n, float capacity) {
    sortItems(items, n);

    float totalProfit = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            totalProfit += items[i].profit * (capacity / items[i].weight);
            break;
        }
    }

    return totalProfit;
}

// 4. Main function
int main() {
    int n;
    float capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    float maxProfit = fractionalKnapsack(items, n, capacity);

    printf("Maximum Profit = %.2f\n", maxProfit);

    return 0;
}
