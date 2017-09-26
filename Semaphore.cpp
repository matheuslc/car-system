#include "Semaphore.hpp"

Semaphore::Semaphore() {
    nextSemaphore = nullptr;
    isOpen = false;
}

Semaphore::Semaphore(bool state) {
    nextSemaphore = nullptr;
    isOpen = state;
}

void Semaphore::nextState() {
    isOpen = !isOpen;
    nextSemaphore -> isOpen = !(nextSemaphore -> isOpen);
}

void Semaphore::setNext(Semaphore *next) {
    nextSemaphore = next;
}

bool Semaphore::getOpen() const {
    return isOpen;
}
