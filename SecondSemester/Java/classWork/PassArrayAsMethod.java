public class PassArrayAsMethod{
    static void findMin(int[] ar){
        int sum=0;
        for(int i=0;i<ar.length;i++){
            sum=sum+ar[i];
        }
        System.out.println("Array sum : "+sum);
        
    }
    public static void main(String[] args) {
        PassArrayAsMethod obj = new PassArrayAsMethod();
        int a[]={11,22,33,44,55};
        findMin(a);
        
    }
}