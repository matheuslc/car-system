#ifndef EVENT_HPP
#define EVENT_HPP

#include "Road.hpp"
#include "Semaphore.hpp"
#include "Vehicle.hpp"
#include "doubly_linked_list.h"
#include <iostream>

/*!
 * Class that represents a Event
 */
class Event
{
  private:
    int time = 0; // Initial time

  public:
    explict Event(int time); // Constructor method
    virtual ~Event();        // Destructor
    virtual void print();
    int getTime() const;
    virtual DoublyLinkedList<Event *> runEvent();

    bool operator>(const Event &e) const;
    bool operator<(const Event &e) const;
    bool operator==(const Event &e) const;
    bool operator!=(const Event &e) const;
    bool operator>=(const Event &e) const;
    bool operator<=(const Event &e) const;

    bool operator>(int i) const;
    bool operator<(int i) const;
    bool operator==(int i) const;
    bool operator!=(int i) const;
    bool operator>=(int i) const;
    bool operator<=(int i) const;
};

class CreateVehicle : public Event
{
  private:
    wayIn &source;

  public:
    CreateVehicle(int time, wayIn &source);
    DoublyLinkedList<Event *> runEvent();
    void print();
};

class RemoveVehicle : public Event
{
  private:
    wayOut &exit;

  public:
    RemoveVehicle(int time, wayOut &exit);
    DoublyLinkedList<Event *> runEvent();
    void print();
};

class ChangeRoad : public Event
{
  private:
    Road &newRoad;

  public:
    ChangeRoad(int time, Road &newRoad);
    DoublyLinkedList<Event *> runEvent();
    void print();
};

class OpenSemaphore : public Event
{
  private:
    Semaphore &semaphore;
    int frequency;

  public:
    OpenSemaphore(int time, Semaphore &semaphore, int frequency);
    DoublyLinkedList<Event *> runEvent();
    void print();
};
}
;
#endif
