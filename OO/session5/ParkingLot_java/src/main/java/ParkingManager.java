import java.util.ArrayList;
import java.util.List;

/**
 * Created by wWX245771 on 2015/8/31.
 */
public class ParkingManager implements Parkable {

    private List<Parkable> parkingObjects = new ArrayList<>();

    @Override
    public Ticket park(Car car) {
        for (Parkable parkable : parkingObjects) {
            Ticket ticket = parkable.park(car);
            if (ticket != null) {
                return ticket;
            }
        }
        return null;
    }

    void addParkable(Parkable parkingObject) {
        parkingObjects.add(parkingObject);
    }
}
