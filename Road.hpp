#ifdef ROAD_HPP
#define ROAD_HPP

#include "linked_queue.h"
#include "Vehicle.hpp"
#include "Semaphore.hpp"

/*!
 * Class that representes a Road.
 * */
class Road {
 protected:
     Semaphore& semaphore;  // Last semaphore on road
     int size = 0;  // Size
     int speed = 0;  // Speed
     int in = 0;  // Amount of cars in
     int out = 0;  // Amount of cars out
     LinkedQueue<Vehicle> vehicleQueue;  // Queue of cars
     static totalIn, totalOut;  // Every car in/out in every road
     double probabilityLeft, probabilityRight;  // right/left probability

 public:
     Road(Semaphore& sem, int size, int speed); // Constructor method
     void add(Vehicle v);  // Push_front a car;
     Vehicle pop();  // Pop_back a car;
     bool isEmpty();  // Check if road is empty;
     virtual Road& moveVehicle();  // Move vehicle to next road
     int timeToTravelRoad() const;  // Time for travel the current road
     int vehicleIn();  // amount of cars in
     int vehicleOut();  // amout of cars out
     int vehicleAreIn();  // amount of cars that are on the road
     static int totalIn();  // amount of cars in on every road
     static int totalOut();  // amount of cars out on every road
};

/*!
 * Class that represents a source road
 */
class Source : public Road {
 private:
     int fixedFrequency = 0;
     int variableFrequency = 0;
     Road &leftExit, &rightExit, &straightExit;

 public:
     Source(Semaphore& sem, int size, int speed, int fixedFrequency, int variableFrequency, Road& rightExit, Road& straightExit, Road& leftExit, double probabilityLeft, double probabilityRight);
     void createVehicle();
     virtual Road& moveVehicle();
     int nextEvent(int time);
};

/*!
 * Class that represents the central road
 */
class CenterRoad : public Road {
 private: 
    Road &leftExit, &rightExit, &straightExit;

 public:
    CenterRoad(Semaphore& sem, int size, int speed, Road& rightExit, Road& straightExit, Road& leftExit, double probabilityLeft, double probabilityRight);
    virtual Road moveVehicle();
};

/*!
 * Class that represents a exit road
 */
class ExitRoad : public Road {
 public:i
        ExitRoad(Semaphore& sem, int size, int speed);  // Constructor method
};

#endif
