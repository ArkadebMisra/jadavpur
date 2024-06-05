import java.util.Scanner;

class ThreadIncr implements Runnable {
    String name;
    Thread t;
    static Scanner sc = new Scanner(System.in);

    ThreadIncr(String threadname) {
        name = threadname;
        t = new Thread(this, name);
        System.out.println("New thread: " + t);
    }

    public void run() {
        synchronized (Q1.class) {
            System.out.println("Enter a value to increment the variable for " + name);
            String instr = sc.nextLine();
            int in = Integer.parseInt(instr);
            Q1.shv += in;
        }
    }
}

class ThreadDecr implements Runnable {
    String name;
    Thread t;
    int d = 2;

    ThreadDecr(String threadname) {
        name = threadname;
        t = new Thread(this, name);
        System.out.println("New thread: " + t);
    }

    public void run() {
        synchronized (Q1.class) {
            Q1.shv -= d;
        }
    }
}

public class Q1 {
    static int shv = 0;

    public static void main(String[] args) {
        ThreadIncr t1 = new ThreadIncr("Thread 1");
        ThreadIncr t2 = new ThreadIncr("Thread 2");
        ThreadDecr t3 = new ThreadDecr("Thread 3");
        ThreadDecr t4 = new ThreadDecr("Thread 4");

        t1.t.start();
        t2.t.start();
        t3.t.start();
        t4.t.start();

        try {
            t1.t.join();
            t2.t.join();
            t3.t.join();
            t4.t.join();
        } catch (InterruptedException e) {
            System.out.println("Interrupted");
        }

        System.out.println("Final value of shared variable: " + shv);
    }
}
