#ifndef VEHICLE_CPP
#define VEHICLE_CPP

/*!
 * Class that represents a vehicle.
 */
class Vehicle {
 private:
     int size_;  // Vehicle's size.
     const int FIXED_SIZE = 5;  // Fixed size
     const int VARIABLE_SIZE = 4;  // Variable size
 
 public:
     Vehicle();  // Constructor method.
     int getSize();  // Return vehicle's size
};

#endif

