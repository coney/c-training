/**
 * Created by wWX245771 on 2015/9/9.
 */
public class TextReporter implements IReportable {
    private StringBuilder result = new StringBuilder();

    @Override
    public String toString() {
        return result.toString();
    }

    private void printDashes(int level) {
        for (int i = 0; i < level; ++i) {
            result.append("--");
        }
    }

    @Override
    public void report(ParkingBoy parkingBoy, int level) {
        printDashes(level);
        result.append("ParkingBoy\n");
    }

    @Override
    public void report(ParkingLot parkingLot, int level) {
        printDashes(level);
        result.append("ParkingLot(");
        result.append(parkingLot.getUsage());
        result.append("/");
        result.append(parkingLot.getCapacity());
        result.append(")\n");
    }

    @Override
    public void report(ParkingManager parkingManager, int level) {
        printDashes(level);
        result.append("ParkingManager\n");
    }

}
