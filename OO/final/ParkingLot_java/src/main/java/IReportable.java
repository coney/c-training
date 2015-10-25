/**
 * Created by wWX245771 on 2015/9/9.
 */
public interface IReportable {
    void report(ParkingBoy parkingBoy, int level);
    void report(ParkingLot parkingLot, int level);
    void report(ParkingManager parkingManager, int level);
}
