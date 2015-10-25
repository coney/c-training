#ifndef _PARKINGMANAGER_H_INCLUDED_
#define _PARKINGMANAGER_H_INCLUDED_

#include "ParkingBoy.h"
#include "IReportable.h"

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

    void accept(IReportable &reporter, const size_t level) const {
        reporter.report(*this, level);
        for (auto parkingObj : parkingObjects_) {
            try {
                dynamic_cast<const ParkingManager&>(*parkingObj).accept(reporter, level + 1);
            }
            catch (std::bad_cast &) {
                dynamic_cast<const ParkingBoy&>(*parkingObj).accept(reporter, level + 1);
            }
        }
    }

private:
    IParkableList parkingObjects_;
};
#endif // _PARKINGMANAGER_H_INCLUDED_
