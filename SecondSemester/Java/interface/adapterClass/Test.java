package adapterClass;

interface It1 {
    void m1();
    void m2();
    void m3();
    void m4();
    void m5();
    void m6();
}
class X implements It1{     //adapter class

    public void m1() { }
    public void m2() { }
    public void m3() { }
    public void m4() { }
    public void m5() { }
    public void m6() { }
}

public class Test extends X {
    @Override
    public void m1() {
        System.out.println("M1 method necessary");
    }

    @Override
    public void m3() {
        System.out.println("M3 method necessary");
    }

    @Override
    public void m5() {
        System.out.println("M5 method necessary");
    }
    public static void main(String[] args)
    { Test obj=new Test();
    obj.m1();
    obj.m3();
    obj.m5();
    }
}
