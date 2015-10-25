import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import java.util.ArrayList;

/**
 * Created by wWX245771 on 2015/8/18.
 */
public class ParkingBoy {

    private final ArrayList<ParkingLot> parkingLots = new ArrayList<>();
    private final ParkingStrategy parkingStrategy;

    public ParkingBoy(ParkingStrategy parkingStrategy) {
        this.parkingStrategy = parkingStrategy;
    }

    public void addParkingLot(ParkingLot parkingLot) {
        parkingLots.add(parkingLot);
    }

    public Ticket park(Car car) {
        ParkingLot parkingLot = parkingStrategy.select(parkingLots);
        if (parkingLot != null) {
            return parkingLot.park(car);
        }
        return null;
    }
}
