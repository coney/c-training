import java.util.Stack;

/**
 * Created by wWX245771 on 2015/9/9.
 */
public class XMLReporter implements IReportable {

    class TagLevel {
        public String getTag() {
            return tag;
        }

        public int getLevel() {
            return level;
        }

        private final String tag;
        private final int level;

        public TagLevel(String tag, int level) {
            this.tag = tag;
            this.level = level;
        }
    }

    private Stack<TagLevel> disclosedTags = new Stack<>();

    private StringBuilder result = new StringBuilder();

    @Override
    public String toString() {
        closeTag(0);
        return result.toString();
    }


    private void discloseTag(String tag, int level) {
        disclosedTags.push(new TagLevel(tag, level));
    }

    private void closeTag(int level) {
        while (!disclosedTags.isEmpty()) {
            TagLevel tag = disclosedTags.peek();
            if (level <= tag.getLevel()) {
                result.append(tag.getTag());
            } else {
                break;
            }
            disclosedTags.pop();
        }
    }

    @Override
    public void report(ParkingLot parkingLot, int level) {
        result.append("<ParkingLot>\n");
        result.append("<Count>");
        result.append(parkingLot.getUsage());
        result.append("</Count>\n");
        result.append("<Capacity>");
        result.append(parkingLot.getCapacity());
        result.append("</Capacity>\n");
        result.append("</ParkingLot>\n");
    }

    @Override
    public void report(ParkingBoy parkingBoy, int level) {
        closeTag(level);
        result.append("<ParkingBoy>\n");
        discloseTag("</ParkingBoy>\n", level);
    }

    @Override
    public void report(ParkingManager parkingManager, int level) {
        closeTag(level);
        result.append("<ParkingManager>\n");
        discloseTag("</ParkingManager>\n", level);
    }

}
