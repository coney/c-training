import org.junit.Test;

import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.CoreMatchers.notNullValue;
import static org.junit.Assert.*;

/**
 * Created by wWX245771 on 2015/8/18.
 */
public class ParkingBoyTest {
    @Test
    public void shoudAbleToParkCar() throws Exception {
        // Given 2 Parking Lots
        ParkingLot plot3 = new ParkingLot(3);
        ParkingLot plot5 = new ParkingLot(5);

        // And a parking boy who knows these parking lots
        ParkingBoy boy = new ParkingBoy();
        boy.addParkingLot(plot3);
        boy.addParkingLot(plot5);

        // And a car
        Car car = new Car();

        // When I ask the parking boy to park my car
        Ticket ticket = boy.park(car);

        // Then I should get a ticket
        assertThat(ticket, is(notNullValue()));

        // And the ticket represents my car
        assertThat(ticket.getCar(), is(car));

        // And I can pick my car from the first parking lot
        assertThat(plot3.unpark(ticket), is(car));
    }
}