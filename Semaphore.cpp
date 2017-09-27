#include "Semaphore.hpp"

Semaphore::Semaphore() {
    nextSemaphore = nullptr;
    isOpen_ = false;
}

Semaphore::Semaphore(bool state) {
    nextSemaphore = nullptr;
    isOpen_ = state;
}

bool Semaphore::isOpen() const{
    return isOpen_;
}

void Semaphore::setNextSemaphore(Semaphore *next) {
    nextSemaphore = next;
}

void Semaphore::changeState() {
    isOpen_ = !isOpen_;
    nextSemaphore -> isOpen_ = !(nextSemaphore -> isOpen_);
}
