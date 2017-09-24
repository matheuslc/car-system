#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

/*!
 * Class that represents a semaphore.
 */
class Semaphore {
 private: 
     Semaphore *nextSemaphore; // Points to the next semaphore;
     bool isOpen_;  // Return the current state
 
 public: 
     Semaphore();  // Constructor method
     Semaphore(bool isOpen_);  // Constructor method
     void setNext(Semaphore *next);  // Set next semaphore
     void nextState();  // Set next direction
     bool getOpens() const;  // Return open semaphores
};

#endif
