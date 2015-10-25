import java.util.Collection;

/**
 * Created by wWX245771 on 2015/8/22.
 */
public abstract class ParkingStrategyBase implements ParkingStrategy {
    @Override
    public ParkingLot select(Collection<ParkingLot> parkingLots) {
        ParkingLot target = null;
        for (ParkingLot plot : parkingLots) {
            if (isAvailable(plot)) {
                if (target == null || isBetter(target, plot)) {
                    target = plot;
                }
            }
        }
        return target;
    }

    protected abstract boolean isBetter(ParkingLot currentOne, ParkingLot newOne);

    private boolean isAvailable(ParkingLot parkingLot) {
        return parkingLot.getCapacity() > parkingLot.getUsage();
    }
}
