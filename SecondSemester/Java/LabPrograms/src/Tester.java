
class Tester
{
    public static void main(String[] args)
    {
        // Declaring 2-D array with 2 rows
        int arr[][] = new int[5][];

        // Making the above array Jagged

        // First row has 3 columns
        arr[0] = new int[5];

        // Second row has 2 columns
        arr[1] = new int[4];

        arr[2] = new int[3];

        arr[3] = new int[2];

        arr[4] = new int[1];

        // Displaying the values of 2D Jagged array
        System.out.println("Contents of 2D Jagged Array");
        for (int i=0; i<arr.length; i++)
        {
            for (int j=0; j<arr[i].length; j++)
                System.out.print("*");
            System.out.println();
        }
    }
}
