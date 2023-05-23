//
// Created by piotr on 5/13/23.
//

#ifndef LAB2_PRODUCER_H
#define LAB2_PRODUCER_H

#include "Buffer.h"

class Producer {
private:
    Buffer *buffer;
public:
    Producer(Buffer *buffer) : buffer {buffer} {}

    void produce() const {
        while(true) {
        // for(int i {0};i < 1000;i++) {
            try {
                buffer->empty_semaphore.p();
                buffer->buffer_semaphore.p();

                Ingredient product;
                buffer->add_product(product);

                buffer->buffer_semaphore.v();
                buffer->full_semaphore.v();
            } catch(const SemaphoreException &exception) {
                printf("%s\n", exception.what());
            }
        }
    }
};

#endif //LAB2_PRODUCER_H
