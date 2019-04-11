package BasicAbstract;

abstract class Abs {
    abstract void m1();
    abstract void m2();
    abstract void m3();
    void m4() {
        System.out.println("m4 method");
    }
}

class Test extends Abs {

    void m1() {
        System.out.println("m1 method");
    }


    void m2() {
        System.out.println("m2 method");
    }


    void m3() {
        System.out.println("m3 method");
    }

    public static void main(String[] args)
    {
        Test obj=new Test();
        obj.m1();   obj.m2();  obj.m3();  obj.m4();
        Abs obj1=new Test();
        obj1.m1();   // compile time-- Abs(parent) checked && runtime -- test(child) executed
        obj1.m2();   // compile time-- Abs(parent) checked && runtime -- test(child) executed
        obj1.m3();   // compile time-- Abs(parent) checked && runtime -- test(child) executed
        obj1.m4();     // compile time-- Abs(parent) checked && runtime -- test(child) executed

    }
}
