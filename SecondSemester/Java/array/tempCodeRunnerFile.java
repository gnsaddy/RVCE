class Test2DArray{
    public static void main(String[] args) {
        String[][] ak = new String[][]{{"Aditya","Raj"},{"Bhaskar","Uday"}};
        for(int i =0;i<ak.length;i++){
            for(int j=0;j<ak[i].length;j++){
                System.out.print(ak[i][j]+" ");
            }