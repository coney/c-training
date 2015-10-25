#ifndef _TICKET_H_INCLUDED_
#define _TICKET_H_INCLUDED_
#include <memory>
#include "Car.h"

class Ticket {
public:
    Ticket(const ::std::shared_ptr<Car> &car) 
        : car_(car) {
    }
    
    ::std::shared_ptr<Car> getCar() const {
        return car_;
    }

private:
    ::std::shared_ptr<Car> car_;
};

#endif // _TICKET_H_INCLUDED_
