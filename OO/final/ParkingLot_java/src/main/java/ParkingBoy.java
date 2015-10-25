import java.util.ArrayList;

/**
 * Created by wWX245771 on 2015/8/18.
 */
public class ParkingBoy implements Parkable {

    private final ArrayList<ParkingLot> parkingLots = new ArrayList<>();
    private final ParkingStrategy parkingStrategy;

    public ParkingBoy(ParkingStrategy parkingStrategy) {
        this.parkingStrategy = parkingStrategy;
    }

    public void addParkingLot(ParkingLot parkingLot) {
        parkingLots.add(parkingLot);
    }

    public void accept(IReportable reporter, int level) {
        reporter.report(this, level);
        for (ParkingLot parkingLot : parkingLots) {
            parkingLot.accept(reporter, level + 1);
        }
    }

    @Override
    public Ticket park(Car car) {
        ParkingLot parkingLot = parkingStrategy.select(parkingLots);
        if (parkingLot != null) {
            return parkingLot.park(car);
        }
        return null;
    }
}
