package testthread;

// Example that shows multiple threads
// can execute the same method but in
// synchronized way.


class Line
{

    // if multiple threads(trains) trying to access
    // this synchronized method on the same Object
    // but only one thread will be able
    // to execute it at a time.
    synchronized public void getLine()
    {
        for (int i = 0; i < 3; i++)
        {
            System.out.println("Train start : " +i);
            try
            {
                Thread.sleep(400);
            }
            catch (Exception e)
            {
                System.out.println(e);
            }
        }
    }

    public void getBusLine(){
        synchronized (this){
            for (int i = 0; i < 3; i++)
            {
                System.out.println("bus start : " +i);
                try
                {
                    Thread.sleep(400);
                }
                catch (Exception e)
                {
                    System.out.println(e);
                }
            }
        }

    }
}

class Train extends Thread
{
    // Reference variable of type Line.
    Line line;

    Train(Line line)
    {
        this.line = line;
    }

    public void run()
    {
        line.getLine();
    }
}

class Bus extends Thread{
    // Reference variable of type Line.
    Line line;

    Bus(Line line)
    {
        this.line = line;
    }

    public void run()
    {
        line.getBusLine();
    }
}

class GFG
{
    public static void main(String[] args)
    {
        Line obj = new Line();

        // we are creating two threads which share
        // same Object.
        Train train = new Train(obj);
        Bus bus = new Bus(obj);

        // both threads start executing .
        train.start();
        bus.start();
    }
}
