package testGarbageCollector;

public class IslandOfIsolation {
        IslandOfIsolation i;
        public static void main(String[] args)
        {
            IslandOfIsolation t1 = new IslandOfIsolation();
            IslandOfIsolation t2 = new IslandOfIsolation();

            // Object of t1 gets a copy of t2
            t1.i = t2;

            // Object of t2 gets a copy of t1
            t2.i = t1;

            // Till now no object eligible
            // for garbage collection
            t1 = null;

            //now two objects are eligible for
            // garbage collection
            t2 = null;

            // calling garbage collector
            System.gc();

        }

        @Override
        protected void finalize() throws Throwable
        {
            System.out.println("Finalize method called");
        }
    }

