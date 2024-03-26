class Student {
    private int roll;
    private String name;
    private double score;
    
    
    // Method to set attributes
    public void setAttributes(int roll, String name, double score) {
        this.roll = roll;
        this.name = name;
        this.score = score;
    }
    
    // Method to display attributes
    public void displayAttributes() {
        System.out.println("Roll: " + roll);
        System.out.println("Name: " + name);
        System.out.println("Score: " + score);
    }
    
    // Method to copy attributes to another Student object
    public void copyTo(Student anotherStudent) {
        anotherStudent.setAttributes(this.roll, this.name, this.score);
    }
}

public class Q7{
    // Main method to test the class
    public static void main(String[] args) {
        // Create a student object
        Student student1 = new Student();
        
        // Display attributes of student1
        System.out.println("Attributes of student1:");
        student1.setAttributes(2, "Bob", 90.0);
        student1.displayAttributes();
        
        // Create another student object
        Student student2 = new Student();
        
        // Copy attributes from student1 to student2
        student1.copyTo(student2);
        
        // Display attributes of student2
        System.out.println("\nAttributes of student2 (after copying):");
        student2.displayAttributes();
        
        // Modify attributes of student2
        student2.setAttributes(2, "Alice", 90.0);
        
        // Display attributes of student2 again
        System.out.println("\nAttributes of student2 (after modification):");
        student2.displayAttributes();
    }
}
