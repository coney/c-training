#include "gmock/gmock.h"
#include "ParkingBoy.h"

TEST(ParkingBoy, ShoudAbleToParkCar) {
    // Given 2 Parking Lots
    ::std::shared_ptr<ParkingLot> plot3 = std::make_shared<ParkingLot>(3);
    ::std::shared_ptr<ParkingLot> plot5 = std::make_shared<ParkingLot>(5);

    // And a parking boy who knows these parking lots
    ParkingBoy boy;
    boy.addParkingLot(plot3);
    boy.addParkingLot(plot5);

    // And a car
    ::std::shared_ptr<Car> car = std::make_shared<Car>();

    // When I ask the parking boy to park my car
    ::std::shared_ptr<Ticket> ticket = boy.park(car);

    // Then I should get a ticket
    ASSERT_TRUE(ticket != NULL);

    // And the ticket represents my car
    ASSERT_EQ(car, ticket->getCar());

    // And I can pick my car from the first parking lot
    ASSERT_EQ(car, plot3->unpark(ticket));
}