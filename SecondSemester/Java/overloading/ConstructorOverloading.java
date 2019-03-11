import java.util.Scanner;

class TestMethodOverLoad{

    int area(int a, int b){
        return a*b;
    }
    int area(int a){
        return a*a;
    }
    int area(int a, int b,int c){
        return a*b*c;
    }

    int addAll(int a,int b){
        return a+b;
    }

    double addAll(double a,double b){
        return a+b;
    }
}


public class ConstructorOverloading{
    int stId;
    String stName;
    int age;
    String state;

    ConstructorOverloading(){
        stId = 101;
        stName = "Aditya Raj";
        age = 20;
    }

    ConstructorOverloading(String state){
        this.state = state;
    }

    ConstructorOverloading(int stId,String stName,int age){
        this.stId = stId;
        this.stName = stName;
        this.age = age;
    }
    
    public static void main(String[] args) {
        


        
        System.out.println("Sum of double : " +obj.addAll(10.2, 20.9));


        while(true){
            Scanner sc = new Scanner(System.in);
            int ch = sc.nextInt();
            switch(ch){
                case 1:{
                    System.out.println("Constructor overloading");
                    System.out.println("Constructor overloading : same class constructor with different arguments i.e, changing no. of arguments ");
                    ConstructorOverloading obj1 = new ConstructorOverloading();
                    ConstructorOverloading obj2 = new ConstructorOverloading("Banglore");
                    ConstructorOverloading obj3 = new ConstructorOverloading(102,"Bhaskar uday",21);
                    System.out.println("Student first data : ");
                    System.out.println(obj1.stId);
                    System.out.println(obj1.stName);
                    System.out.println(obj1.age);
                    System.out.println(obj2.state);
                    System.out.println("Student second data : ");
                    System.out.println(obj3.stId);
                    System.out.println(obj3.stName);
                    System.out.println(obj3.age);
                    System.out.println(obj2.state);
                    System.out.println("Method overloading");
                }

                case 2:{
                    TestMethodOverLoad obj = new TestMethodOverLoad();
                    System.out.println("Method overloading : Same method name with different arguments i.e, changing no. of arguments ");

                    System.out.println("Area of rectangle : " + obj.area(10,20));
                    System.out.println("Area of square : " + obj.area(10));
                    System.out.println("Volume of cuboid : " + obj.area(15,20,5));

                    System.out.println("Method Overloading : changing data type of arguments");

                    System.out.println("Sum of all : " +obj.addAll(10, 20));

            }

        }

        
    }
}