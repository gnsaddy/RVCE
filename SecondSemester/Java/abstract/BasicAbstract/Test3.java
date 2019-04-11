package BasicAbstract;

abstract class AbsNew {
    AbsNew(){
        System.out.println("Abstract class constructor ");
    }
    abstract void m1();
}
class Test3 extends AbsNew{

    void m1() {
        System.out.println("M1 method ");
    }
    Test3() {
        super();
        System.out.println("Normal class constructor");
    }
    public static void main(String[] args)
    {
        new Test3().m1();

    }
}
