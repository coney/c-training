#include "gmock/gmock.h"
#include "ParkingManager.h"
#include "TextParkingReport.h"

class ParkingReportSpec : public ::testing::Test {
protected:
    virtual void SetUp() {

        // Manager 1 has 1 Parking Boy with 1 Parking Lot (0/3)
        ::std::shared_ptr<ParkingLot> parkingLot1 = std::make_shared<ParkingLot>(3);
        ::std::shared_ptr<ParkingBoy> parkingBoy1 = std::make_shared<ParkingBoyByCapacity>();
        parkingBoy1->addParkingLot(parkingLot1);
        ::std::shared_ptr<ParkingManager> manager1 = std::make_shared<ParkingManager>();
        manager1->addParkable(parkingBoy1);


        // Parking Boy 2 has 2 Parking Lots (1/5) and (3/7)
        ::std::shared_ptr<ParkingLot> parkingLot2a = std::make_shared<ParkingLot>(5);
        parkingLot2a->park(std::make_shared<Car>());
        ::std::shared_ptr<ParkingLot> parkingLot2b = std::make_shared<ParkingLot>(7);
        parkingLot2b->park(std::make_shared<Car>());
        parkingLot2b->park(std::make_shared<Car>());
        parkingLot2b->park(std::make_shared<Car>());
        ::std::shared_ptr<ParkingBoy> parkingBoy2 = std::make_shared<ParkingBoyByCapacity>();
        parkingBoy2->addParkingLot(parkingLot2a);
        parkingBoy2->addParkingLot(parkingLot2b);


        // Head Manager manages Manager 1 and Parking Boy 2
        headManager().addParkable(manager1);
        headManager().addParkable(parkingBoy2);
    }

    ParkingManager &headManager() {
        return manager_;
    }

    ParkingManager manager_;
};


TEST_F(ParkingReportSpec, ShouldAbleToReportInXMLFormat) {
    ::std::string report;

    XMLParkingReport xmlReport;
    headManager().accept(xmlReport, 0);
    report = xmlReport.toString();

    ASSERT_EQ(
        "<ParkingManager>\n"
            "<ParkingManager>\n"
                "<ParkingBoy>\n"
                    "<ParkingLot>\n"
                        "<Count>0</Count>\n"
                        "<Capacity>3</Capacity>\n"
                    "</ParkingLot>\n"
                "</ParkingBoy>\n"
            "</ParkingManager>\n"
            "<ParkingBoy>\n"
                "<ParkingLot>\n"
                    "<Count>1</Count>\n"
                    "<Capacity>5</Capacity>\n"
                "</ParkingLot>\n"
                "<ParkingLot>\n"
                    "<Count>3</Count>\n"
                    "<Capacity>7</Capacity>\n"
                "</ParkingLot>\n"
            "</ParkingBoy>\n"
        "</ParkingManager>\n"
        , report);
}

