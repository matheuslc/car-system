#ifndef VEHICLE_CPP
#define VEHICLE_CPP

class Vehicle {
 private:
     int size_;
     const int FIXED_SIZE = 5;
     const int VARIABLE_SIZE = 4;
 
 public:
     Vehicle();
     int getSize();
};

#endif

