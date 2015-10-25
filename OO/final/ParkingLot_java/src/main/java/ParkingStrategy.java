import java.util.Collection;
import java.util.List;

/**
 * Created by wWX245771 on 2015/8/22.
 */
public interface ParkingStrategy {
    ParkingLot select(Collection<ParkingLot> parkingLots);
}
