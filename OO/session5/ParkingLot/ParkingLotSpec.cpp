#include <list>
#include <gmock/gmock.h>
#include "ParkingLot.h"

class ParkingLotSpec : public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    ::std::shared_ptr<Car> createCar() {
        return std::make_shared<Car>();
    }

    ParkingLot &createSubject(unsigned int capacity) {
        parkingLot_ = std::make_shared<ParkingLot>(capacity);
        return *parkingLot_;
    }

    ::std::shared_ptr<ParkingLot> parkingLot_;
};

TEST_F(ParkingLotSpec, ShouldAbleToParkCarWhenParkingLotIsFree) {
    // Given a ParkingLot which capacity is 3
    // And a car
    ParkingLot &parkingLot = createSubject(3);
    ::std::shared_ptr<Car> car = createCar();

    // When I park the car
    ::std::shared_ptr<Ticket> ticket = parkingLot.park(car);
    
    // Then I should receive a ticket which is associated with my car
    ASSERT_EQ(car, ticket->getCar());
}

TEST_F(ParkingLotSpec, ShouldNotParkMorCarWhenParkingLotIsFull) {
    // Given a ParkingLot which capacity is 3
    // And 3 cars parked in the parking lot
    ParkingLot &parkingLot = createSubject(3);
    parkingLot.park(createCar());
    parkingLot.park(createCar());
    parkingLot.park(createCar());

    // When I park a new car
    ::std::shared_ptr<Ticket> ticket = parkingLot.park(createCar());

    // Then I should not able to park my car and get a ticket
    ASSERT_EQ(NULL, ticket.get());
}

TEST_F(ParkingLotSpec, ShouldAbleToUnparkCarIfCarIsInParkingLot) {
    // Given a ParkingLot which capacity is 3
    // And a car
    ParkingLot &parkingLot = createSubject(3);
    ::std::shared_ptr<Car> car = createCar();

    // When I park a care in the parking lot
    ::std::shared_ptr<Ticket> ticket = parkingLot.park(car);

    // Then I should receive a ticket which is associated with my car
    // When I use the ticket to get my car
    ::std::shared_ptr<Car> unparkedCar = parkingLot.unpark(ticket);

    // Then I should able to unpark my car
    ASSERT_EQ(car, unparkedCar);
}

TEST_F(ParkingLotSpec, ShouldNotUnparkCarIfCarIsNotParked) {
    // Given a ParkingLot which capacity is 3
    // And a ticket which is not related with the given parking lot
    ParkingLot &parkingLot = createSubject(3);
    ::std::shared_ptr<Ticket> ticket = std::make_shared<Ticket>(createCar());
    
    // When I try to get a car with the ticket
    ::std::shared_ptr<Car> car = parkingLot.unpark(ticket);

    // Then I should get nothing
    ASSERT_EQ(NULL, car.get());
}

