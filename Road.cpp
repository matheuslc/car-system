#include "Road.hpp"
#include <cstdlib>

int Road::totalIn_ = 0;
int Road::totalOut_ = 0;

Road::Road(Semaphore &semaphore, int size, int speed, double probabilityLeft, doubleprobabilityRight) {
    semaphore = semaphore;
    size_ = size;
    speed_ = 0;
    probabilityLeft = probabilityLeft;
    probabilityRight = proabilityRight;
}

void Road::add(Vehiche vehicle) {
    if(vehicle.getSize() > size_)
        throw std::runtime_error("A rua já está cheia.");

    size_ -= vehicle.getSize();
    vehicleIn_++;
    totalIn_++;
    queue.enqueue(vehicle);
}

Vehicle Road::pop() {
    Vehicle vehicle = queue.dequeue();
    size += vehicle.getSize();
    vehicleOut_++;
    totalOut_++;
    return vehicle;
}

bool Road::isEmpty() {
    return queue.empty();
}

Road& Road::moveVehicle() {
    throw std::logic_error("Not implemented yet.");
}

int Road::timeToTravel() const {
    return size / speed / 3.6;
}

int Road::vehicleIn() {
    return vehicleIn_;
}

int Road::vehicleOut() {
    return vehicleOut_;
}

int Road::vehicleStay() {
    return vehicleIn_ - vehicleOut_;
}

int Road::totalIn() {
    return totalIn_;
}

int Road::totalOut() {
    return totalOut_;
}

wayOut::wayOut(Semaphore& semaphore, int size, int speed) : Road(semaphore, size, speed, 0, 0) {}

middleRoad::middleRoad(Semaphore& semaphore, int size, int speed, Road &leftExit, Road &rightExit, Road &straightExit, double probabilityLeft, double probabilityRight) : Road(semaphore, size, speed, probabilityLeft, probabilifyRight), leftExit(leftExit), rightExit(rightExit), straightExit(straightExit) {}

Road& middleRoad::moveVehicle() {
    if (!semaphore.isOpen())
        throw std::runtime_error("Semaforo está fechado.");

    double road = rand()/RAND_MAX;
    auto vehicle = pop();

    if (road > probabilityright) {
        rightExit.add(vehicle);
        return rightExit;
    }
    else if (road < probabilityLeft) {
        leftExit.add(vehicle)
            return leftExit;
    }
    else {
        straightExit.add(vehicle);
        return straightExit;
    }
}

wayIn::wayIn(Semaphore& semaphore, int size, int speed, int fixedFrequency, int variableFrequency, Road& leftExit, Road& rightExit, Road& straightExit, double probabilityLeft, double propabilityRight) :
    Road(semaphore, size, speed, probabilityLeft, probabilityRight),
    fixedFrequency(fixedFrequency - variableFrequency), variableFrequency(2 * variableFrequency),
    leftExit(leftExit),
    rightExit(rightExit),
    straightExit(straightExit) {}

void wayIn::createVehicle() {
    Vehicle vehicle;
    add(vehicle);
}

Road& wayIn::moveVehicle() {
    if(!semaphore.isOpen)
        throw std::runtime_error("Semaforo fechado.");

    double road = rand()/RAND_MAX;
    auto vehicle = pop();

    if (road > probabilityRight) {
        rightExit.add(vehicle);
        return rightExit;
    }
    else if (road < probabilityLeft) {
        leftExit.add(vehicle);
        return leftExit;
    }
    else {
        straightExit.add(vehicle);
        return straightExit;
    }
}

int wayIn::nextEvent(int time) {
    return time + variableFrequency + fixedFrequency * float(rand()/RAND_MAX);
}
