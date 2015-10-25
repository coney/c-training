import static org.hamcrest.CoreMatchers.equalTo;
import static org.hamcrest.CoreMatchers.is;
import static org.junit.Assert.*;

/**
 * Created by wWX245771 on 2015/8/13.
 */
public class LengthTest {

    @org.junit.Test
    public void testLengthShouldAbleToBeComparedWithSameUnit() throws Exception {
        assertThat(new Length(10.5, "m"), equalTo(new Length(10.5, "m")));
    }
}