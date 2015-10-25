#ifndef _IREPORT_H_INCLUDED_
#define _IREPORT_H_INCLUDED_

class ParkingLot;
class ParkingBoy;
class ParkingManager;

class IReportable {
public:
    virtual ~IReportable() throw() {}
    virtual ::std::string toString() = 0;
    virtual void report(const ParkingLot &parkingLot, const size_t level)  = 0;
    virtual void report(const ParkingBoy &boy, const size_t level)  = 0;
    virtual void report(const ParkingManager &manager, const size_t level)  = 0;
};

#endif // _IREPORT_H_INCLUDED_
