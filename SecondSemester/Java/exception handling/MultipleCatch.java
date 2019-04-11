class MultipleCatch{
    public static void main(String[] args) {
        int[] num={4,8,16,32,64,128};
        int[] denum={2,0,4,4,0};
        for(int i=0;i<num.length;i++)
            try{
            System.out.println(num[i]+"/"+denum[i]+"="+ (num[i]/denum[i]));
        }catch(ArithmeticException e){
            System.out.println("error 1 catch : "+e);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("error 2 catch");
        }
        System.out.println("rest of code");
    }
    
}
