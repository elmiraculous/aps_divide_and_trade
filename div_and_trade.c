#include "div_and_trade.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int divideAndTrade(Item items[], int n, int capacity) {
    // Если рюкзак пуст или товар закончился
    if (n == 0 || capacity == 0) {
        return 0;
    }
    
    // Если вес товара больше вместимости рюкзака, исключаем его из рассмотрения
    if (items[n - 1].weight > capacity) {
        return divideAndTrade(items, n - 1, capacity);
    }
    
    // В противном случае, возвращаем максимум между включением товара и исключением его из рассмотрения
    else {
        return max(items[n - 1].value + divideAndTrade(items, n - 1, capacity - items[n - 1].weight),
                   divideAndTrade(items, n - 1, capacity));
    }
}

int main() {
    Item items[MAX_ITEMS];
    int n, capacity;
    
    printf("Введите количество товаров: ");
    scanf("%d", &n);
    
    printf("Введите вместимость рюкзака: ");
    scanf("%d", &capacity);
    
    printf("Введите вес и ценность для каждого товара:\n");
    for (int i = 0; i < n; ++i) {
        printf("Товар %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    
    int max_value = divideAndTrade(items, n, capacity);
    printf("Максимальная ценность, которую можно унести в рюкзаке: %d\n", max_value);
    
    return 0;
}
