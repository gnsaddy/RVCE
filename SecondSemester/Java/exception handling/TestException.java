class TestException {
    public static void main(String[] args){
        try{
            int data=50/0;
        }catch(ArithmeticException e){
            System.out.println("Error is : "+e);
        }
        System.out.println("rest of code");
    }
}