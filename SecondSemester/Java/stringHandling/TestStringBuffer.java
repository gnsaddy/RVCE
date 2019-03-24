class TestStringBuffer{
    public static void main(String[] args) {
        StringBuffer str1 = new StringBuffer();
        System.out.println("Append to buffer : "+(str1.append("Hello there!")));
        System.out.println("Insert to buffer : "+(str1.insert(12,",how are u!")));
        StringBuffer str2 = new StringBuffer("Java is awesome");
        System.out.println("Replace from buffer : "+(str2.replace(0,4,"Python")));
        System.out.println("Delete from buffer : "+(str1.delete(0,5)));
        System.out.println("Reverse order : "+(str1.reverse()));
        System.out.println("Capacity : "+(str1.capacity()));
        System.out.println("CharAt : "+(str1.charAt(5)));
        System.out.println("Delete CharAt : "+(str1.deleteCharAt(5)));
        System.out.println("Indexof : "+(str1.indexOf("e")));
        System.out.println("length : "+(str1.length()));
        System.out.println("substring : "+(str1.substring(0,5)));

        
    }
}