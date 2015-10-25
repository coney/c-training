#ifndef _PARKINGBOY_H_INCLUDED_
#define _PARKINGBOY_H_INCLUDED_
#include <list>
#include "ParkingLot.h"

class ParkingBoy {
public:
    void addParkingLot(::std::shared_ptr<ParkingLot> plot) {
        throw std::runtime_error("not implemented");
    }

    ::std::shared_ptr<Ticket> park(::std::shared_ptr<Car> car) {
        throw std::runtime_error("not implemented");
    }
};

#endif // _PARKINGBOY_H_INCLUDED_

