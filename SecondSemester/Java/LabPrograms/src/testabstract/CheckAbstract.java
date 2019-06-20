package testabstract;

abstract class CheckAbstract {
    int x;

    abstract void m1();

    public void m2() {
        System.out.println("m2");
    }

    CheckAbstract() {
        x = 30;
        System.out.println(x);
    }
}

    class TestAbstract extends CheckAbstract {
        TestAbstract(){
            super();
        }

        public void m1(){
            System.out.println("m1");
        }
        public static void main(String[] args) {
            TestAbstract obj = new TestAbstract();
            obj.m1();
            obj.m2();
        }
    }

