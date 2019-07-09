package testthread;

class PutGet{
    public int number;
    public boolean status = false; //mutex

    public synchronized void put(int i){
        while (status == true){
            try{
                wait();
            }catch (Throwable e){
                System.out.println("Exception : "+e);
            }
        }
        number = i;
        status = true;
        notifyAll();
    }

    public synchronized int get(){
        while (status == false){
            try{
                wait();
            }catch (Throwable e){
                System.out.println("Exception : "+e);
            }
        }
        status = false;
        notifyAll();
        return number;
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
        for (int i=0;i<5;i++){
            pg.put(i);
            System.out.println("Producer produces : "+i);
            try{
                sleep(1000);
            }catch (Throwable e){
                System.out.println("Exception : "+e);
            }
        }
    }
}
class Consumer extends Thread{
    PutGet pg1;
    int num;
    Consumer(PutGet pg1){
        this.pg1 = pg1;
    }

    public void run(){
        for (int i=0;i<5;i++) {
            num = pg1.get();
            System.out.println("Consumer consumes : " + num);
            try {
                sleep(1000);
            } catch (Throwable e) {
                System.out.println("Exception : " + e);
            }
        }
    }
}
public class ProducerConsumer {
    public static void main(String[] args) {
        PutGet putGet = new PutGet();
        new Producer(putGet,5).start();
        new Consumer(putGet).start();

    }
}
