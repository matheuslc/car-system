#include <cstdlib>
#include "Vehicle.hpp"

Vehicle::Vehicle() {
    size_ = FIXED_SIZE + VARIABLE_SIZE * (int(rand()) / RAND_MAX);

}

int Vehicle::getSize() {
    return size_;
}
