#include "Queue.h"
#include "Error.h"
#include "Utility.h"

Queue::clear() {
    count = 0;
    rear = maxqueue - 1;
    front = 0;
}

bool Queue::empty() const {
    return count == 0;
}

Error_code Queue::retrieve(Queue_entry& item) const {
    if (count <= 0) return underflow;
    item = entry[front];
    return success;
}

Error_code Queue::serve_and_retrieve(Queue_entry& item) {
    if (count <= 0)
        return underflow;
    item = entry[front];
    count--;
    front = ((front + 1) == maxqueue) ? 0 : (front + 1);
    return success;
}

bool Queue::full() const {
    return maxqueue == this->count;
}
