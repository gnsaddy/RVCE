package selftest;

class PutGet {
    public int num;
    public boolean status = false;

    public synchronized void put(int i){
        while (status == true){
            try{
                wait();
            }catch (Throwable t){
                System.out.println(t.getMessage());
            }
        }
        num = i;
        status = true;
        notifyAll();
    }

    public synchronized int get(){
        while(status == false){
            try{
                wait();
            }catch (Throwable t){
                System.out.println(t.getMessage());
            }
        }
        status = false;
        notifyAll();
        return num;
    }
}

class Producer extends Thread{
    PutGet pg;
    int num;

    Producer(PutGet pg,int num){
        this.pg = pg;
        this.num = num;
    }

    public void run(){
        for(int i=0;i<5;i++){
            pg.put(i);
            System.out.println("Produce produces item : " +(i+1));
            try{
                sleep(1000);
            }catch (Throwable t){
                System.out.println(t.getMessage());
            }
        }
    }
}


class Consumer extends Thread {
    PutGet pg;
    int num;

    Consumer(PutGet pg){
        this.pg = pg;
    }

    public void run(){
        for(int i=0;i<5;i++){
            num = pg.get();
            System.out.println("Consumer consumes item : "+ (num+1));
            try{
                sleep(1000);
            }catch (Throwable t){
                System.out.println(t.getMessage());
            }
        }
    }
}
public class Program5 {
    public static void main(String[] args) {
        PutGet pg = new PutGet();
        new Producer(pg,5).start();
        new Consumer(pg).start();
    }
}
