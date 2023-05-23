//
// Created by piotr on 5/13/23.
//

#ifndef LAB2_CONSUMER_H
#define LAB2_CONSUMER_H

#include "Buffer.h"

class Consumer {
private:
    Buffer *dough_buffer;
    Buffer *stuffing_buffer;
public:
    Consumer(Buffer *dough_buffer, Buffer *stuffing_buffer)
            : dough_buffer {dough_buffer}, stuffing_buffer {stuffing_buffer} {}

    void consume() const {
        while(true) {
        // for(int i {0};i < 1000;i++) {
            try {
                dough_buffer->full_semaphore.p();
                stuffing_buffer->full_semaphore.p();
                dough_buffer->buffer_semaphore.p();
                stuffing_buffer->buffer_semaphore.p();

                dough_buffer->remove_product();
                stuffing_buffer->remove_product();

                dough_buffer->buffer_semaphore.v();
                stuffing_buffer->buffer_semaphore.v();
                dough_buffer->empty_semaphore.v();
                stuffing_buffer->empty_semaphore.v();
            } catch(const SemaphoreException &exception) {
                printf("%s\n", exception.what());
            }
        }
    }
};

#endif //LAB2_CONSUMER_H
