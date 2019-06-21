package testthread;

class Customer extends Thread {
    int amount = 0;
    int flag = 0;

    public synchronized int withdraw(int amount) {
        System.out.println(Thread.currentThread().getName() + " is going to withdwaw ");
        if (flag == 0) {
            try {
                System.out.println("waiting..........");
                wait();
            } catch (Throwable t) {
                System.out.println(t);
            }
        }
        this.amount -= amount;
        System.out.println("withdraw complete");
        return amount;
    }

    public synchronized void deposit(int amount){
        System.out.println(Thread.currentThread().getName() + " is going to deposit ");
        this.amount += amount;
        notifyAll();
        System.out.println("Deposited.....");
        flag = 1;

    }
}

public class AmountInBank {
    public static void main(String[] args) {
        final Customer obj = new Customer();
        Thread t1 = new Thread(){
            public void run(){
                obj.withdraw(5000);
                System.out.println("After withdraw amount is : "+obj.amount);
            }
        };

        Thread t2 = new Thread(){
          public void run(){
              obj.deposit(10000);
              System.out.println("After deposit amount is : " +obj.amount);
          }
        };

        t1.start();
        t2.start();

    }
}
