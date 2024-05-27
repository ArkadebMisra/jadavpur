import java.io.File;
import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter the filename or directory path:");
        String filename = scanner.nextLine();
        
        File file = new File(filename);
        
        if (file.exists()) {
            System.out.println("File or directory exists.");
            if (file.isDirectory()) {
                System.out.println("It is a directory.");
                String[] fileList = file.list();
                if (fileList != null) {
                    System.out.println("Files in the directory:");
                    for (String name : fileList) {
                        System.out.println(name);
                    }
                } else {
                    System.out.println("No files in the directory.");
                }
            } else {
                System.out.println("It is not a directory.");
                System.out.println("Readable: " + file.canRead());
                System.out.println("Writable: " + file.canWrite());
            }
        } else {
            System.out.println("File or directory does not exist.");
        }
        
        scanner.close();
    }
}
