import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Q1 {
    public static void main(String[] args) {
        Counter counter = new Counter();
        
        IncrementThread incrementThread1 = new IncrementThread(counter);
        IncrementThread incrementThread2 = new IncrementThread(counter);
        DecrementThread decrementThread1 = new DecrementThread(counter);
        DecrementThread decrementThread2 = new DecrementThread(counter);
        
        incrementThread1.start();
        incrementThread2.start();
        decrementThread1.start();
        decrementThread2.start();
        
        try {
            incrementThread1.join();
            incrementThread2.join();
            decrementThread1.join();
            decrementThread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        System.out.println("Final Value: " + counter.getValue());
    }
}

class Counter {
    private int value = 0;
    private final Lock lock = new ReentrantLock();
    
    public void increment(int amount) {
        lock.lock();
        try {
            value += amount;
            System.out.println("Intermediate value: " + value);
        } finally {
            lock.unlock();
        }
    }
    
    public void decrement(int amount) {
        lock.lock();
        try {
            value -= amount;
            System.out.println("Intermediate value: " + value);
        } finally {
            lock.unlock();
        }
    }
    
    public int getValue() {
        lock.lock();
        try {
            return value;
        } finally {
            lock.unlock();
        }
    }
}

class IncrementThread extends Thread {
    private Counter counter;
    
    public IncrementThread(Counter counter) {
        this.counter = counter;
    }
    
    public void run() {
        for (int i = 0; i < 100; i++) {
            counter.increment(1);
        }
    }
}

class DecrementThread extends Thread {
    private Counter counter;
    
    public DecrementThread(Counter counter) {
        this.counter = counter;
    }
    
    public void run() {
        for (int i = 0; i < 100; i++) {
            counter.decrement(1);
        }
    }
}