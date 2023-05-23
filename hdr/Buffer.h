//
// Created by piotr on 5/13/23.
//

#ifndef LAB2_BUFFER_H
#define LAB2_BUFFER_H

#include <iostream>
#include <queue>
#include "Semaphore.h"

const int MAX_BUFFER_SIZE {100};

struct Ingredient {};       // TODO Think if it is needed, maybe only struct product should be added

class Buffer {
private:
    std::string product_type;         // TODO ID should be changed to name of buffer -> dough, stuffing etc
    std::queue<Ingredient> products;

public:
    Semaphore buffer_semaphore;
    Semaphore full_semaphore;
    Semaphore empty_semaphore;

    Buffer(std::string product_type) : product_type {product_type}, buffer_semaphore(1), full_semaphore(0),
                                       empty_semaphore(MAX_BUFFER_SIZE) {}

    bool check_availability() {
        return (products.size() > 0);
    }

    bool add_product(Ingredient &product) {
        products.push(product);
        printf("Buffer %s added: %lu\n", product_type.c_str(), products.size());
        return true;
    }

    bool remove_product() {
        products.pop();
        printf("Buffer %s removed: %lu\n", product_type.c_str(), products.size());
        return true;
    }
};

#endif //LAB2_BUFFER_H
