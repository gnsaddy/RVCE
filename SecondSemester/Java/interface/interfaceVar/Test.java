package interfaceVar;

interface It3 {
    int a=1000;
}

interface It1 {
    int a=10;  //final public static
    interface It2 {
        int a=100;
    }
}

 class Test implements It1.It2,It3 {

      void m1() {
          System.out.println(It3.a);
         System.out.println(It1.a);
          System.out.println(It1.It2.a);
     }
     public static void main(String[] args) {
      new Test().m1();
    }
}
