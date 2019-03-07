class TestStringObject{
    public static void main(String[] args){
        String str1 = "First string";
        System.out.println(str1);
        System.out.println(str1.hashCode());

        str1 = "Modified string";
        System.out.println(str1);
        System.out.println(str1.hashCode());
        // from this we come to the conclusion that strings are immutable
        
    }
}