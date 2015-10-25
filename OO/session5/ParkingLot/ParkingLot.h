#ifndef _PARKINGLOT_H_INCLUDED_
#define _PARKINGLOT_H_INCLUDED_

#include "Ticket.h"
#include "Car.h"
#include <set>

class IParkable {
public:
    virtual ~IParkable() throw() {}
    virtual ::std::shared_ptr<Ticket> park(const ::std::shared_ptr<Car> &car) = 0;
};


class ParkingLot : public IParkable {
public:
    ParkingLot(unsigned int capacity)
        :capacity_(capacity) {
    }

    ::std::shared_ptr<Ticket> park(const ::std::shared_ptr<Car> &car) {
        if (getUsage() >= getCapacity()) {
            return NULL;
        } else {
            cars_.insert(car);
            return std::make_shared<Ticket>(car);
        }
    }


    ::std::shared_ptr<Car> unpark(const ::std::shared_ptr<Ticket> &ticket) {
        if (cars_.count(ticket->getCar())) {
            cars_.erase(ticket->getCar());
            return ticket->getCar();
        } else {
            return NULL;
        }
    }
    unsigned int getUsage() const {
        return cars_.size();
    }

    unsigned int getCapacity() const {
        return capacity_;
    }

private:
    typedef ::std::set< ::std::shared_ptr<Car> > CarSet;
    unsigned int capacity_;
    CarSet cars_;
};

#endif // _PARKINGLOT_H_INCLUDED_
