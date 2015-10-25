#include "gmock/gmock.h"
#include "ParkingManager.h"

class  ParkingManagerSpec: public ::testing::Test {
protected:
    virtual void SetUp() {
        parkingLot_ = std::make_shared<ParkingLot>(3);
        parkingBoy_ = std::make_shared<ParkingBoyByCapacity>();
        parkingBoy_->addParkingLot(parkingLot_);
        car_ = std::make_shared<Car>();
    }

    const ::std::shared_ptr<ParkingBoy> &parkingBoy() {
        return parkingBoy_;
    }

    const ::std::shared_ptr<ParkingLot> &parkingLot() {
        return parkingLot_;
    }

    const ::std::shared_ptr<Car> &car() {
        return car_;
    }

    ParkingManager &subject() {
        return manager_;
    }

    ParkingManager manager_;
    ::std::shared_ptr<ParkingLot> parkingLot_;
    ::std::shared_ptr<ParkingBoy> parkingBoy_;
    ::std::shared_ptr<Car> car_;

};

TEST_F(ParkingManagerSpec, ShoudlAbleToManagerParkingBoys) {
    ParkingManager &manager =subject();

    manager.addParkable(parkingBoy());

    ::std::shared_ptr<Ticket> ticket = manager.park(car());

    ASSERT_TRUE(ticket != NULL);

    ASSERT_EQ(car(), ticket->getCar());

    ASSERT_EQ(car(), parkingLot()->unpark(ticket));
}


TEST_F(ParkingManagerSpec, ShouldAbleToManagerParkingManagers) {
    ParkingManager &manager = subject();

    ::std::shared_ptr<ParkingManager> otherManager = std::make_shared<ParkingManager>();
    otherManager->addParkable(parkingBoy());

    manager.addParkable(otherManager);

    ::std::shared_ptr<Ticket> ticket = manager.park(car());

    ASSERT_TRUE(ticket != NULL);

    ASSERT_EQ(car(), ticket->getCar());

    ASSERT_EQ(car(), parkingLot()->unpark(ticket));
}



TEST_F(ParkingManagerSpec, ShouldAbleToManagerParkingLots) {

    ParkingManager &manager = subject();

    manager.addParkable(parkingLot());

    ::std::shared_ptr<Ticket> ticket = manager.park(car());

    ASSERT_TRUE(ticket != NULL);

    ASSERT_EQ(car(), ticket->getCar());

    ASSERT_EQ(car(), parkingLot()->unpark(ticket));

}