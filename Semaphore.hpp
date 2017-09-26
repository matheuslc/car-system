#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

/*!
 * Class that represents a semaphore.
 */
class Semaphore {
 private: 
     Semaphore *nextSemaphore; // Points to the next semaphore;
     bool isOpen;  // Current state
 
 public: 
     Semaphore();  // Constructor method
     Semaphore(bool state);  // Constructor method
     void setNext(Semaphore *next);  // Set next semaphore
     void nextState();  // Change state of a semaphore
     bool getOpen() const;  // Return state of a semaphore
};

#endif
