#ifndef ROAD_HPP
#define ROAD_HPP

#include "Vehicle.hpp"
#include "Semaphore.hpp"
#include "linked_queue.h"

/*!
 * Class that represent a Road
 */
class Road {
 protected:
    LinkedQueue<Vehicle> queue;
    Semaphore& semaphore;
    int size_ = 0;
    int speed_ = 0;
    int vehicleIn_ = 0;
    int vehicleOut_ = 0;
    double probabilityLeft;
    double probabilityRight;
    static int totalIn_;
    static int totalOut_;

 public:
    Road(Semaphore& semaphore, int size, int speed, double probabilityLeft, double probabilityRight);  // Constructor metho.
    void add(Vehicle vehicle);  // Add a vehicle on road.
    Vehicle pop();  // Remove a vehicle.
    bool isEmpty();  // Return if road is empty.
    virtual Road& moveVehicle();  // move for another road
    int timeToTravel() const; // Return time to travel
    int vehicleIn() const;  // amount of cars in
    int vehicleOut() const;  //amount of cars out
    int vehicleStay() const;  // amount of cars in road
    static int totalIn();
    static int totalOut();

};

/*!
 * Exit road
 */
class wayOut() : public Road {
 public:
     wayOut(Semaphore& semaphore, int size, int speed);  // Constructor method.
};

/*!
 * Source road
 */
class wayIn() : public Road {
 private:
     int variableFrequency = 0;
     int fixedFrequency = 0;  // Frequency for a new car
     Road &leftExit, &rightExit, &straightExit;  // All exit roads if a car is in source road

 public:
     wayIn();  // Constructor method
     virtual Road& moveVehicle();  // Move a vehicle to another road
     int nextEvent(int time); /// Time for next event
     void createVehicle();  // Generate a new car
    
};

/*!
 * Middle road
 */
class middleRoad() : public Road {
 private:
    Road &leftExit, &rightExit, &straightExit;  // All exit roads if a car is in middleRoad.

 public:
     middleRoad(Semaphore& semaphore, int size, int speed, Road& leftExit, Road& rightExit, Road& straightExit, double probabilityLeft, double probabilityRight);  // Constructor method.
    virtual Road& moveVehicle();
};

#endif

