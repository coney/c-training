#ifndef _PARKINGBOY_H_INCLUDED_
#define _PARKINGBOY_H_INCLUDED_
#include "ParkingLot.h"
#include "ParkingStrategy.h"

class ParkingBoy {
public:
    ParkingBoy(const ::std::shared_ptr<IParkingStrategy> &parkingStrategy) 
    : parkingStrategy_(parkingStrategy) {

    }
    void addParkingLot(const ::std::shared_ptr<ParkingLot> &plot) {
        parkingLots_.push_back(plot);
    }

    ::std::shared_ptr<Ticket> park(const ::std::shared_ptr<Car> &car) {
        ::std::shared_ptr<ParkingLot> selectedParkingLot = 
            parkingStrategy_->select(parkingLots_);

        if (selectedParkingLot) {
            return selectedParkingLot->park(car);
        }
        
        return NULL;
    }
private:
    ::std::shared_ptr<IParkingStrategy> parkingStrategy_;
    ParkingLotList parkingLots_;
};

template <class Strategy>
class ParkingBoyWithStrategy : public ParkingBoy {
public:
    ParkingBoyWithStrategy() 
        :ParkingBoy(::std::dynamic_pointer_cast<IParkingStrategy>(std::make_shared<Strategy>())) {
    }
};

typedef ParkingBoyWithStrategy<ParkingByCapacity> ParkingBoyByCapacity;
typedef ParkingBoyWithStrategy<ParkingByAvailability> ParkingBoyByAvailability;

#endif // _PARKINGBOY_H_INCLUDED_

