import java.util.HashSet;

public class ParkingLot implements Parkable {
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

    public int getUsage() {
        return cars.size();
    }

    public int getCapacity() {
        return capacity;
    }
}
