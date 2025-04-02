#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 产品基类
typedef struct Product {
    void (*use)(struct Product *self);
} Product;

// 具体产品A
typedef struct ProductA {
    Product base;
} ProductA;

void useProductA(Product *self) {
    printf("Using Product A\n");
}

// 具体产品B
typedef struct ProductB {
    Product base;
} ProductB;

void useProductB(Product *self) {
    printf("Using Product B\n");
}

// 简单工厂
typedef enum {
    PRODUCT_A,
    PRODUCT_B
} ProductType;

Product *createProduct(ProductType type) {
    if (type == PRODUCT_A) {
        ProductA *productA = (ProductA *)malloc(sizeof(ProductA));
        productA->base.use = useProductA;
        return (Product *)productA;
    } else if (type == PRODUCT_B) {
        ProductB *productB = (ProductB *)malloc(sizeof(ProductB));
        productB->base.use = useProductB;
        return (Product *)productB;
    }
    return NULL;
}

// 客户端代码
int main() {
    Product *product1 = createProduct(PRODUCT_A);
    Product *product2 = createProduct(PRODUCT_B);

    if (product1) {
        product1->use(product1);
        free(product1);
    }

    if (product2) {
        product2->use(product2);
        free(product2);
    }

    return 0;
}