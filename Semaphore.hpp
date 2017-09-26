#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

/*!
 * Class that represents a Semaphore
 */
class Semaphore {
 private:
    bool isOpen_;  // State of a semaphore
    Semaphore *nextSemaphore;  // Pointer to the next semaphore    
   
 public:
    Semaphore(); // Constructor method.
    Semaphore(bool state_);  // Constructor method.
    bool isOpen() const;  // Return state of a semaphore.
    void setNextSemaphore(Semaphore *next);  // Set pointer
    void changeState();  // Change state of a semaphore
};

#endif

