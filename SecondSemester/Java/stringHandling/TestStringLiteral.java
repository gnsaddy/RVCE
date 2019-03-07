class TestStringLiteral{
    public static void main(String[] args){
        // creating string literal
        String str1 = "Aditya";
        String str2 = "Aditya";
        // both str1 and str2 point at same hashcode/location in string pool 
        String str3 ="Not";

        System.out.println("str1 value is : "+str1 +" str2 value is : "+str2);
        System.out.println("check the address reference or hashcode ");
        System.out.println("str1 at "+ str1.hashCode());
        System.out.println("str2 at "+ str2.hashCode());
        System.out.println("str3  at "+str3.hashCode());

    }
} 