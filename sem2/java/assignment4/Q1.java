import java.util.Scanner;

class ThreadIncr implements Runnable{
    String name;
    Thread t;

    ThreadIncr(String threadname){
        name = threadname;
        t = new Thread(this, name);
        System.out.println("new Thread " + t);
    }
    public void run(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a value to increment the variable");
        String instr = sc.nextLine();
        int in = Integer.parseInt(instr);
        Q1.shv +=in;
        sc.close();
    }
}


class ThreadDecr implements Runnable{
    String name;
    Thread t;
    int d = 2;

    ThreadDecr(String threadname){
        name = threadname;
        t = new Thread(this, name);
        System.out.println("new Thread " + t);
    }
    public void run(){
        Q1.shv -= d;
    }
}

public class Q1{
    static int shv = 0;
    public static void main(String args[]){
        // int shv = 0;
        ThreadIncr t1 = new ThreadIncr("thread 1");
        ThreadIncr t2 = new ThreadIncr("thread 2");
        ThreadDecr t3 = new ThreadDecr("thread 3");
        ThreadDecr t4 = new ThreadDecr("thread 3");

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