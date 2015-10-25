#ifndef _PARKINGMANAGER_H_INCLUDED_
#define _PARKINGMANAGER_H_INCLUDED_

#include "ParkingBoy.h"

class ParkingManager : public IParkable {
    typedef ::std::list< ::std::shared_ptr<IParkable>> IParkableList;
public:
    ParkingManager() {
    	
    }

    void addParkable(const ::std::shared_ptr<IParkable> &parkingObj) {
        parkingObjects_.push_back(parkingObj);
    }

    virtual ::std::shared_ptr<Ticket> park(const ::std::shared_ptr<Car> &car)
    {
        for (auto parkObj : parkingObjects_) {
            ::std::shared_ptr<Ticket> ticket = parkObj->park(car);
            if (ticket) {
                return ticket;
            }
        }
        return NULL;
    }

private:
    IParkableList parkingObjects_;
};
#endif // _PARKINGMANAGER_H_INCLUDED_
