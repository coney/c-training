import org.junit.Test;

import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.CoreMatchers.nullValue;
import static org.junit.Assert.*;

/**
 * Created by wWX245771 on 2015/8/17.
 */
public class ParkingLotTest {
    private Car createCar() {
        return new Car();
    }

    private ParkingLot createSubject(int capacity) {
        return new ParkingLot(capacity);
    }

    @org.junit.Test
    public void shouldAbleToParkCarWhenParkingLotIsFree() throws Exception {
        // Given a ParkingLot which capacity is 3
        // And a car
        ParkingLot parkingLot = createSubject(3);
        Car car = createCar();

        // When I park the car
        Ticket ticket = parkingLot.park(car);

        // Then I should receive a ticket which is associated with my car
        assertThat(ticket.getCar(), is(car));
    }

    @Test
    public void shouldNotParkMorCarWhenParkingLotIsFull() throws Exception {
        // Given a ParkingLot which capacity is 3
        // And 3 cars parked in the parking lot
        ParkingLot parkingLot = createSubject(3);
        parkingLot.park(createCar());
        parkingLot.park(createCar());
        parkingLot.park(createCar());
        // When I park a new car
        Ticket ticket = parkingLot.park(createCar());

        // Then I should not able to park my car and get a ticket
        assertThat(ticket, is(nullValue()));
    }

    @Test
    public void shouldAbleToUnparkCarIfCarIsInParkingLot() throws Exception {
        // Given a ParkingLot which capacity is 3
        // And a car
        ParkingLot parkingLot = createSubject(3);
        Car car = createCar();

        // When I park a care in the parking lot
        Ticket ticket = parkingLot.park(car);

        // Then I should receive a ticket which is associated with my car
        // When I use the ticket to get my car
        Car unparkedCar = parkingLot.unpark(ticket);

        // Then I should able to unpark my car
        assertThat(unparkedCar, is(car));
    }

    @Test
    public void shouldNotUnparkCarIfCarIsNotParked() throws Exception {
        // Given a ParkingLot which capacity is 3
        // And a ticket which is not related with the given parking lot
        ParkingLot parkingLot = createSubject(3);
        Ticket ticket = new Ticket(createCar());

        // When I try to get a car with the ticket
        Car car = parkingLot.unpark(ticket);

        // Then I should get nothing
        assertThat(car, is(nullValue()));
    }

}