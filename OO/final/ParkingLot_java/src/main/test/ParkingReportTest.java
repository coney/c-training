import org.junit.Before;
import org.junit.Test;

import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.CoreMatchers.notNullValue;
import static org.junit.Assert.assertThat;

/**
 * Created by wWX245771 on 2015/8/31.
 */
public class ParkingReportTest {


    ParkingManager headManager = new ParkingManager();

    @Before
    public void setUp() throws Exception {
        // Manager 1 has 1 Parking Boy with 1 Parking Lot (0/3)
        ParkingLot parkingLot1 = new ParkingLot(3);
        ParkingBoy parkingBoy1 = new ParkingBoyByCapacity();
        parkingBoy1.addParkingLot(parkingLot1);
        ParkingManager parkingManager1 = new ParkingManager();
        parkingManager1.addParkable(parkingBoy1);

        // Parking Boy 2 has 2 Parking Lots (1/5) and (3/7)
        ParkingLot parkingLot2a = new ParkingLot(5);
        parkingLot2a.park(new Car());
        ParkingLot parkingLot2b = new ParkingLot(7);
        parkingLot2b.park(new Car());
        parkingLot2b.park(new Car());
        parkingLot2b.park(new Car());
        ParkingBoy parkingBoy2 = new ParkingBoyByCapacity();
        parkingBoy2.addParkingLot(parkingLot2a);
        parkingBoy2.addParkingLot(parkingLot2b);

        // Head Manager manages Manager 1 and Parking Boy 2
        headManager.addParkable(parkingManager1);
        headManager.addParkable(parkingBoy2);
    }

    @Test
    public void shouldAbleToReportInTreeFormat() throws Exception {
        TextReporter reporter = new TextReporter();
        headManager.accept(reporter, 0);
        String report = reporter.toString();

        StringBuilder result = new StringBuilder();
        result.append("ParkingManager\n");
        result.append("--ParkingManager\n");
        result.append("----ParkingBoy\n");
        result.append("------ParkingLot(0/3)\n");
        result.append("--ParkingBoy\n");
        result.append("----ParkingLot(1/5)\n");
        result.append("----ParkingLot(3/7)\n");
        assertThat(report, is(result.toString()));
    }

    @Test
    public void shouldAbleToReportInXmlFormat() throws Exception {
        XMLReporter reporter = new XMLReporter();
        headManager.accept(reporter, 0);
        String report = reporter.toString();

        StringBuilder result = new StringBuilder();
        result.append("<ParkingManager>\n");
            result.append("<ParkingManager>\n");
                result.append("<ParkingBoy>\n");
                    result.append("<ParkingLot>\n");
                        result.append("<Count>0</Count>\n");
                        result.append("<Capacity>3</Capacity>\n");
                    result.append("</ParkingLot>\n");
                result.append("</ParkingBoy>\n");
            result.append("</ParkingManager>\n");
            result.append("<ParkingBoy>\n");
                result.append("<ParkingLot>\n");
                    result.append("<Count>1</Count>\n");
                    result.append("<Capacity>5</Capacity>\n");
                result.append("</ParkingLot>\n");
                result.append("<ParkingLot>\n");
                    result.append("<Count>3</Count>\n");
                    result.append("<Capacity>7</Capacity>\n");
                result.append("</ParkingLot>\n");
            result.append("</ParkingBoy>\n");
        result.append("</ParkingManager>\n");

        assertThat(report, is(result.toString()));
    }

}