#include "Semaphore.hpp"
#include "Vehicle.hpp"
#include "Road.hpp"
#include "doubly_linked_list.h"
#include <ctime>

int main(int argc, char const *argv[])
{
    srand(time(0));

    DoublyLinkedList<Event *> eventos;

    // Create Semaphores
    Semaphore *S1North = new Semaphore();
    Semaphore *S1East = new Semaphore();
    Semaphore *S1South = new Semaphore;
    Semaphore *S1West = new Semaphore();
    Semaphore *S2North = new Semaphore;
    Semaphore *S2East = new Semaphore();
    Semaphore *S2South = new Semaphore();
    Semaphore *S2West = new Semaphore();

    // Set pointers
    S1West->setNextSemaphore(S1South);
    S1South->setNextSemaphore(S1East);
    S1East->setNextSemaphore(S1North);
    S1North->setNextSemaphore(S1West);

    S2West->setNextSemaphore(S2South);
    S2South->setNextSemaphore(S2East);
    S2East->setNextSemaphore(S2North);
    S2North->setNextSemaphore(S2West);

    // Create Roads
    // wayIn
    wayIn W1East
    wayIn();
    wayIn();
    wayIn();
    wayIn();
    wayIn();

    // wayOut
    wayOut W1West(*S1East, 2000, 80);
    wayOut N1North(*S1South, 500, 60);
    wayOut();
    wayOut();
    wayOut();
    wayOut();
    wayOut();

    // Middle
    middleRoad mdWest(*S1East, 300, 60, N1North, W1West, S1South, 0.3, 0.7);
    middleRoad mdEast(*S2West, 300, 60, S2South, E2East, N2North, 0.3, 0.7);

    evento.insert_sorted(new CreateVehicle());
    evento.insert_sorted(newCreateVehicle());
    evento.insert_sorted(newCreateVehicle());
    evento.insert_sorted(newCreateVehicle());
    evento.insert_sorted(newCreateVehicle());
    evento.insert_sorted(newCreateVehicle());

    evento.insert_sorted(new OpenSemaphore());
    evento.insert_sorted(new OpenSemaphore());

    int time = 0;

    while ((time <= totalTime) && !(evento.empty()) {
        auto currentEvent = evento.pop_front();

        time = currentEvent->getTime();

        auto newEvent = currentEvent->run();
        auto size = newEvent.size();

        for (auto i = 0; i < size; i++)
            evento.insert_sorted(newEvent.at(i));
     }

     std::cout << "Número de carros que entraram: " << Road::totalIn()
     << "\nNúmero de carros que saíram: " << Road::totalOut()
     << "\nNúmero de carros que permaneceram: " << (Road::totalIn() - Road::totalOut())
     << "\n------------------------------------" << std::endl;



     return 0;
}
