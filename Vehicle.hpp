#ifndef VEHICLE_HPP
#define VEHICLE_HPP


/*!
 * Class that represents a Vehicle
 */

class Vehicle {
 private:
     int size_;  // Vehicle size
     int speed_;  // Vehicle speed
     const int FIXED_SIZE = 5;
     const int VARIABLE_SIZE = 3;
 
 public:
     Vehicle();  // Constructor method
     int getSize();  // Return vehicle's size

};

#endif

