public class MarkerInterface implements Cloneable{  //marker interface
    int a=10;
    int b=20;
    public static void main(String[] args) throws CloneNotSupportedException {
        MarkerInterface obj=new MarkerInterface();
        System.out.println(obj.a);
        System.out.println(obj.b);
        obj.a=999;  obj.b=888;
        MarkerInterface obj1=(MarkerInterface) obj.clone();  //cloning process
        System.out.println(obj.a);
        System.out.println(obj.b);
        obj.a=444;  obj.b=555;
        System.out.println(obj.a);
        System.out.println(obj.b);
        System.out.println(obj1.a);
        System.out.println(obj1.b);

    }
}

