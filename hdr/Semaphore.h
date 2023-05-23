//
// Created by piotr on 5/14/23.
//

#ifndef LAB2_SEMAPHORE_H
#define LAB2_SEMAPHORE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <exception>

class SemaphoreException : public std::exception {
private:
    const char* message;
public:
    SemaphoreException(const char *message) noexcept : message {message} {}
    virtual  ~SemaphoreException() = default;

    const char* what() const noexcept override {
        return message;
    }
};

class Semaphore {       // Class Semaphore is simplified to use only for Linux
private:
    sem_t sem;
public:
    Semaphore( int value ) {
        if( sem_init( & sem, 0, value ) != 0 )
            throw SemaphoreException("sem_init: failed");
    }
    ~Semaphore() {
        sem_destroy( & sem );
    }

    void p() {
        if( sem_wait( & sem ) != 0 )
            throw SemaphoreException("sem_wait: failed");
    }

    void v() {
        if( sem_post( & sem ) != 0 )
            throw SemaphoreException("sem_post: failed");
    }
};

#endif //LAB2_SEMAPHORE_H
