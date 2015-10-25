import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import java.util.HashSet;
import java.util.Set;

public class ParkingLot {
    private final int capacity;
    private final HashSet<Car> cars;

    public ParkingLot(int capacity) {
        this.capacity = capacity;
        cars = new HashSet<>();
    }


    public Ticket park(Car car) {
        if (getUsage() >= getCapacity()) {
            return null;
        } else {
            cars.add(car);
            return new Ticket(car);
        }
    }


    public Car unpark(Ticket ticket) {
        final Car car = ticket.getCar();
        if (cars.contains(car)) {
            cars.remove(car);
            return car;
        }
        return null;
    }

    private int getUsage() {
        return cars.size();
    }

    private int getCapacity() {
        return capacity;
    }
}
