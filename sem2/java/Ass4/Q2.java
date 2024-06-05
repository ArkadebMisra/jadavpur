import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Q2 {
    public static void main(String[] args) {
        Counter2 counter = new Counter2();
        
        IncrementThread2 incrementThread1 = new IncrementThread2(counter);
        IncrementThread2 incrementThread2 = new IncrementThread2(counter);
        DecrementThread2 decrementThread1 = new DecrementThread2(counter);
        DecrementThread2 decrementThread2 = new DecrementThread2(counter);
        
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

class Counter2 {
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

class IncrementThread2 extends Thread {
    private Counter2 counter;
    
    public IncrementThread2(Counter2 counter) {
        this.counter = counter;
    }
    
    public void run() {
        for (int i = 0; i < 100; i++) {
            counter.increment(1);
        }
    }
}

class DecrementThread2 extends Thread {
    private Counter2 counter;
    
    public DecrementThread2(Counter2 counter) {
        this.counter = counter;
    }
    
    public void run() {
        for (int i = 0; i < 10000; i++) {
            counter.decrement(1);
        }
    }
}