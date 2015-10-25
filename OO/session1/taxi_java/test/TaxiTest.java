import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by lWX247526 on 2015/6/26.
 */
public class TaxiTest {

    @Test
    public void testChargeTaxiFee() throws Exception {
        Taxi taxi = new Taxi();
        assertEquals(1, taxi.chargeTaxiFee(0.8f));
    }
}
