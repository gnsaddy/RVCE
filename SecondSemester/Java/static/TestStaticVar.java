public class TestStaticVar{
    static String name = "Aditya";
    static String city = "Banglore";

    static public void methodS(){
        System.out.println("Accessing var using static method : "+name + " "+city);
        city = "Patna";
        System.out.println("modifying var data : "+city);
    }
    public static void main(String[] args) {
        methodS();
    }

}