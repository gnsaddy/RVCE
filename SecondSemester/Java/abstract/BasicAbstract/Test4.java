abstract class CheckBlocks {
    CheckBlocks(){
        System.out.println("Abstract class constructor");
    }
    {
        System.out.println("Instance block ");
    }
    static  {
        System.out.println("Static block");
    }
}
class Test4 extends CheckBlocks{
    Test4(){
        super();
        System.out.println("Normal class constructor");
    }
    public static void main(String[] args)
    {
        new Test4();
        new Test4();
    }
}
