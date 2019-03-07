class TestArray {
	public static void main(String[] args){

	// 1D array
	int[] s1 = new int[]{1,2,3,4}; // 1st type
	int[] s2 = {2,3,4,5}; //second type
	int[] s3 = new int[3];
	s3[0]=12;
	s3[1]=22;
	s3[2]=33;

	for (int i=0;i<s1.length;i++)  // length is a keyword
		System.out.println("--"+ s1[i]);

	for (int j=0;j<s2.length;j++)
		System.out.println("--"+ s2[j]);

		for (int j=0;j<s2.length;j++)
		System.out.println("--"+ s3[j]);

	// irregular array  [row][col]
	int[][] table = new int[2][];
	table[0] = new int[3];
	table[1] = new int[2];
	table[0][0]=1; //pos 1
	table[0][1]=2; //pos 2
	table[0][2]=5; //pos 3
	table[1][0]=3; //pos 4
	table[1][1]=4; //pos 5
	
	for(int i=0;i<table.length;i++){ // row length
		for(int j=0;j<table[i].length;j++){ //col length for specific row
			System.out.println(table[i][j]);
		}

	}

	// 2D array
	int size=5;
	int[][] a = new int[][]{{1,2,3,4,5},
							{9,8,7,6,5}};
	
	
	for(int i=0;i<size;i++){
		
		for(int j=0;j<size;j++){
			System.out.print(a[i][j]);
			System.out.print(" ");
		}
			System.out.println("\n");
	}
}
}

