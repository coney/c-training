#ifndef _PARKINGSTRATEGY_H_INCLUDED_
#define _PARKINGSTRATEGY_H_INCLUDED_

#include <list>
#include "ParkingLot.h"

typedef ::std::list< ::std::shared_ptr<ParkingLot> > ParkingLotList;

class IParkingStrategy {
public:
    virtual ~IParkingStrategy() throw() {}
    virtual ::std::shared_ptr<ParkingLot> select(const ParkingLotList &parkingLots) const = 0;
};

class ParkingStrategyBase : public IParkingStrategy {
public:
    virtual ~ParkingStrategyBase() throw() {}

    virtual ::std::shared_ptr<ParkingLot> select(const ParkingLotList &parkingLots) const {
        ::std::shared_ptr<ParkingLot> target = NULL;
        for (auto plot : parkingLots) {
            if (isAvailable(*plot)) {
                if (target == NULL || isBetter(*target, *plot)) {
                    target = plot;
                }
            }
        }
        return target;
    }

protected:
    virtual bool isBetter(const ParkingLot &currentOne, const ParkingLot &newOne) const = 0;

private:
    bool isAvailable(const ParkingLot &parkingLot) const {
        return parkingLot.getCapacity() > parkingLot.getUsage();
    }
};

class ParkingByCapacity : public ParkingStrategyBase {
protected:
    virtual bool isBetter(const ParkingLot &currentOne, const ParkingLot &newOne) const {
        return newOne.getCapacity() > currentOne.getCapacity();
    }
};

class ParkingByAvailability : public ParkingStrategyBase {
protected:
    virtual bool isBetter(const ParkingLot &currentOne, const ParkingLot &newOne) const {
        return getAvaliableCount(newOne) > getAvaliableCount(currentOne);
    }

private:
    unsigned int getAvaliableCount(const ParkingLot &parkingLot) const {
        return parkingLot.getCapacity() - parkingLot.getUsage();
    }
};

#endif // _PARKINGSTRATEGY_H_INCLUDED_
