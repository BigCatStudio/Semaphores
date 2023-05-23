#include <thread>
#include "../hdr/Buffer.h"
#include "../hdr/Producer.h"
#include "../hdr/Consumer.h"

int main() {
    Buffer dough_buffer("dough");
    Buffer meat_buffer("meat");
    Buffer cheese_buffer("cheese");
    Buffer cabbage_buffer("cabbage");

    Producer dough_producer(&dough_buffer);
    Producer meat_producer(&meat_buffer);
    Producer cheese_producer(&cheese_buffer);
    Producer cabbage_producer(&cabbage_buffer);

    Consumer meat_consumer(&dough_buffer, &meat_buffer);
    Consumer cheese_consumer(&dough_buffer, &cheese_buffer);
    Consumer cabbage_consumer(&dough_buffer, &cabbage_buffer);

    std::thread dough_producer_thread(&Producer::produce, &dough_producer);
    std::thread meat_producer_thread(&Producer::produce, &meat_producer);
    std::thread cheese_producer_thread(&Producer::produce, &cheese_producer);
    std::thread cabbage_producer_thread(&Producer::produce, &cabbage_producer);

    std::thread meat_consumer_thread(&Consumer::consume, &meat_consumer);
    std::thread cheese_consumer_thread(&Consumer::consume, &cheese_consumer);
    std::thread cabbage_consumer_thread(&Consumer::consume, &cabbage_consumer);

    dough_producer_thread.join();
    meat_producer_thread.join();
    cheese_producer_thread.join();
    cabbage_producer_thread.join();

    meat_consumer_thread.join();
    cheese_consumer_thread.join();
    cabbage_consumer_thread.join();

    return 0;
}
