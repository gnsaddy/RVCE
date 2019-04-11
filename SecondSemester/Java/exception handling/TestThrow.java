import java.util.*;
class TestThrow{

    static void validate(int age){
        if(age<18){
            throw new ArithmeticException("Not valid");
        }else{
            System.out.println("welcome to vote");
        }
    }
    public static void main(String[] args) {
        try{
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter age");
            int a= sc.nextInt();
            validate(a);
        }catch(ArithmeticException e){
            System.out.println("error : "+e);
        }
        System.out.println("rest of code");
    }
}