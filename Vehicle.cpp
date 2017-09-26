#include "Vehicle.hpp"
#include <cstdlib>

Vehicle::Vehicle() {
    size_ = FIXED_SIZE + VARIABLE_SIZE  * (double(rand()) / RAND_MAX);
}

int Vehicle:getsize() {
    return size_;
}
