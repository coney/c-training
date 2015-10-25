import org.junit.Before;
import org.junit.Test;

import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.CoreMatchers.notNullValue;
import static org.junit.Assert.*;

/**
 * Created by wWX245771 on 2015/8/31.
 */
public class ParkingManagerTest {

    private ParkingLot parkingLot;
    private ParkingBoyByCapacity parkingBoy;
    private Car car;
    private ParkingManager parkingManager;

    @Before
    public void setUp() throws Exception {
        parkingLot = new ParkingLot(3);
        parkingBoy = new ParkingBoyByCapacity();
        parkingBoy.addParkingLot(parkingLot);
        car = new Car();
        parkingManager = new ParkingManager();
    }

    @Test
    public void shouldAbleToManagerParkingBoy() throws Exception {
        parkingManager.addParkable(parkingBoy);

        Ticket ticket = parkingManager.park(car);

        assertThat(ticket, is(notNullValue()));
        assertThat(ticket.getCar(), is(car));
        assertThat(parkingLot.unpark(ticket), is(car));
    }

    @Test
    public void shouldAbleToManagerParkingManager() throws Exception {
        ParkingManager otherManager = new ParkingManager();
        otherManager.addParkable(parkingBoy);

        parkingManager.addParkable(otherManager);

        Ticket ticket = parkingManager.park(car);

        assertThat(ticket, is(notNullValue()));
        assertThat(ticket.getCar(), is(car));
        assertThat(parkingLot.unpark(ticket), is(car));
    }

    @Test
    public void shouldAbleToManagerParkingLotDirectly() throws Exception {
        parkingManager.addParkable(parkingLot);

        Ticket ticket = parkingManager.park(car);

        assertThat(ticket, is(notNullValue()));
        assertThat(ticket.getCar(), is(car));
        assertThat(parkingLot.unpark(ticket), is(car));
    }
}