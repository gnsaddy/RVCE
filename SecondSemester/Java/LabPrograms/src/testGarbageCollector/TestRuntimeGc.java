package testGarbageCollector;

public class TestRuntimeGc {
    // Java program to demonstrate requesting
// JVM to run Garbage Collector
        public static void main(String[] args) throws InterruptedException
        {
            TestRuntimeGc t1 = new TestRuntimeGc();
            TestRuntimeGc t2 = new TestRuntimeGc();

            // Nullifying the reference variable
            t1 = null;

            // requesting JVM for running Garbage Collector
            System.gc();

            // Nullifying the reference variable
            t2 = null;
            System.gc();

            // requesting JVM for running Garbage Collector
            Runtime.getRuntime().gc();

        }

        @Override
        // finalize method is called on object once
        // before garbage collecting it
        protected void finalize() throws Throwable
        {
            System.out.println("Garbage collector called");
            System.out.println("Object garbage collected : " + this);
        }
    }

