class PassingArrayToMethod {
    static void printArray(int[] ar) {
        for (int var : ar) {
            System.out.println(var);
        }
    }
    public static void main(String[] args) {
       printArray(new int[]{3, 1, 2, 6, 4, 2});
    }
}
