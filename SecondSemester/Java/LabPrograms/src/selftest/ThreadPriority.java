package selftest;

import java.util.Scanner;

public class ThreadPriority {
    public static void main(String[] args) {
        Program6 obj = new Program6();
        obj.threadObjects();

        Program6 th4 = new Program6();
        Program6 th5 = new Program6();
        Program6 th6 = new Program6();

        System.out.println("Current thread name : "+ Thread.currentThread().getName());
        System.out.println("Main thread priority : "+ Thread.currentThread().getPriority());

        System.out.println("Setting new priority : ");
        th4.setPriority(2);
        th5.setPriority(5);
        th6.setPriority(8);

        System.out.println("Thread 1 priority : "+ th4.getPriority());
        System.out.println("Thread 2 priority : "+ th5.getPriority());
        System.out.println("Thread 3 priority : "+ th6.getPriority());
        try {
            System.out.println("User defined priority ");
            Scanner sc = new Scanner(System.in);

            System.out.println("Enter thread 1 priority");
            int x = sc.nextInt();
            th4.setPriority(x);

            System.out.println("Enter thread 2 priority");
            int y = sc.nextInt();
            th5.setPriority(y);

            System.out.println("Enter thread 3 priority");
            int z = sc.nextInt();
            th6.setPriority(z);

        }catch (IllegalArgumentException e){
            System.out.println("Exception : "+ e + " Priority range '0-10' ");
        }

        System.out.println("Priority :");
        System.out.println("Thread 1 priority : "+ th4.getPriority());
        System.out.println("Thread 2 priority : "+ th5.getPriority());
        System.out.println("Thread 3 priority : "+ th6.getPriority());


    }
}
