import java.util.Collection;

/**
 * Created by wWX245771 on 2015/8/22.
 */
public class ParkingByAvailability extends ParkingStrategyBase {
    @Override
    protected boolean isBetter(ParkingLot currentOne, ParkingLot newOne) {
        return getAvailableSpace(newOne) > getAvailableSpace(currentOne);
    }

    private int getAvailableSpace(ParkingLot parkingLot) {
        return parkingLot.getCapacity() - parkingLot.getUsage();
    }
}
