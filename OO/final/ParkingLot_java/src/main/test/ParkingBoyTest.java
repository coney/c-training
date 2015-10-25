import org.junit.Test;

import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.CoreMatchers.notNullValue;
import static org.junit.Assert.*;

/**
 * Created by wWX245771 on 2015/8/18.
 */
public class ParkingBoyTest {
    @Test
    public void shoudAbleToParkCarByCapacity() throws Exception {
        // Given 2 Parking Lots
        ParkingLot plot3 = new ParkingLot(3);
        ParkingLot plot5 = new ParkingLot(5);

        // And a parking boy who knows these parking lots
        ParkingBoyByCapacity boy = new ParkingBoyByCapacity();
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

        // And I can pick my car from the biggest parking lot
        assertThat(plot5.unpark(ticket), is(car));
    }
    @Test
    public void shoudAbleToParkCarByAvailability() throws Exception {
        // Given 2 Parking Lots
        ParkingLot plot3 = new ParkingLot(3);
        ParkingLot plot5 = new ParkingLot(5);

        // And parking lot 5 has 3 cars parked already
        plot5.park(new Car());
        plot5.park(new Car());
        plot5.park(new Car());

        // And a parking boy who knows these parking lots
        ParkingBoyByAvailability boy = new ParkingBoyByAvailability();
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

        // And I can pick my car from the parking lot which has more space
        assertThat(plot3.unpark(ticket), is(car));
    }


}