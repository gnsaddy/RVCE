package TestException;

public class SubClassException {
    public static void main(String[] args) {
        int[] num = {2, 4, 6, 8, 10, 12, 14,16,20};
        int[] denom = {2, 0, 3, 4, 0};

        for(int i=0;i<num.length;i++) {
            try {
                System.out.println(num[i] + "/" + denom[i] + "=" + num[i] / denom[i]);
            }catch (ArithmeticException  e){
                System.out.println("subclass handled exception : " +e);
            }
            catch (Throwable t){
                System.out.println("superclass handled exception : " +t);
            }
        }

    }
}
