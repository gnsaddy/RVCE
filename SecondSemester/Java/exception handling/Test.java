

public class Test {

    int[] m1() {
        System.out.println("m1 method  ");
        int[] a = {10,20,30,40};
        return a;
    }

    void m2(double d)
    {
        System.out.println("m2 method");
        for (double dd : d) {
            System.out.println(dd);
        }

    }
    public static void main(String[] args)
    {
        Test obj = new Test();

        int[] x = obj.m1();
        for (int xx:x) {
            System.out.println(xx); }

            double[] d = {10.1,20.2,30.3,40.4};
            obj.m2(d);

    }
}
