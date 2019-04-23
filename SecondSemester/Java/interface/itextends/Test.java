package itextends;

interface It1 {
    void m1();
}
interface It2 extends It1 {
    void m2();
}
interface It3 extends It2 {
    void m3();
}

class TestInterface implements It1,It2,It3 {
    @Override
    public void m1() {
        System.out.println("M1 method--1");
    }

    @Override
    public void m2() {
        System.out.println("M2 method--2");
    }
    public void m3() {
        System.out.println("M3 method--3");
    }
    public static void main(String[] args)
    {
        TestInterface obj=new TestInterface();
        obj.m1();    obj.m2();    obj.m3();
    }
}
