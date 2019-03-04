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



    public static void main(String[] args) {
        TestMethodOverLoad obj = new TestMethodOverLoad();
        System.out.println("Method overloading : Same method name with different arguments i.e, changing no. of arguments ");

        System.out.println("Area of rectangle : " + obj.area(10,20));
        System.out.println("Area of square : " + obj.area(10));
        System.out.println("Volume of cuboid : " + obj.area(15,20,5));

        System.out.println("Method Overloading : changing data type of arguments");

        System.out.println("Sum of all : " +obj.addAll(10, 20));
        System.out.println("Sum of double : " +obj.addAll(10.2, 20.9));
    }
}

