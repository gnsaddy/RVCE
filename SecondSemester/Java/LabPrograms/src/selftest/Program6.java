package selftest;

public class Program6 extends Thread{
    public void run(){
        System.out.println("Thread name : "+ Thread.currentThread().getName());
        System.out.println("Thread is running");
    }

    public static void threadObjects(){
        Program6 th1 = new Program6();
        Program6 th2 = new Program6();
        Program6 th3 = new Program6();

        System.out.println("Thread priority of 1st thread is : "+ th1.getPriority());
        System.out.println("Thread priority of 2nd thread is : "+ th2.getPriority());
        System.out.println("Thread priority of 3rd thread is : "+ th3.getPriority());
    }

}
