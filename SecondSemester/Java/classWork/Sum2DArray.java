class Sum2DArray{
   
    public static void main(String[] args) {
        int[][] ar1 = new int[][]{{1,2,3,4},{9,8,7,6}};
        int[][] ar2 = new int[][]{{11,22,33,44},{99,88,77,66}};
        int[][] ar3 = new int[4][4];

        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                ar3[i][j]=ar1[i][j]+ar2[i][j];
                System.out.print(ar3[i][j]);
                System.out.print("\t");
            }
            System.out.println(" ");
        }

        
    }
}