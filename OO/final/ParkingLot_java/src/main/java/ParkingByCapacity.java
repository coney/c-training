import java.util.Collection;

/**
 * Created by wWX245771 on 2015/8/22.
 */
public class ParkingByCapacity extends ParkingStrategyBase {
    @Override
    protected boolean isBetter(ParkingLot currentOne, ParkingLot newOne) {
        return newOne.getCapacity() > currentOne.getCapacity();
    }
}
