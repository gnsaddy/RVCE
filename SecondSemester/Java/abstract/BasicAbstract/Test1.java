package BasicAbstract;

abstract class Abs1 {
    abstract void m1();
    abstract void m2();
    abstract void m3();
}
abstract class Abs2 extends Abs1 {

    void m1() {
        System.out.println("M1 method---");
    }
}
abstract class Abs3 extends Abs2{

    void m2() {
        System.out.println("M2 method---");
    }
}
public class Test1 extends Abs3 {

    void m3() {
        System.out.println("M3 method---");
    }
    public static void main(String[] args)
    {
        Test1 obj=new Test1();
        obj.m1();   obj.m2();   obj.m3();
    }
}
