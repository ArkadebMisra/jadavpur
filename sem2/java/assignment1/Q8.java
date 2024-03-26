class Student {
    private int roll;
    private String name;
    private double score;
    
    // Constructor with roll only
    public Student(int roll) {
        this.roll = roll;
        this.name = "";
        this.score = 0;
    }
    
    // Constructor with roll and name only
    public Student(int roll, String name) {
        this.roll = roll;
        this.name = name;
        this.score = 0;
    }
    
    // Constructor with roll, name, and score
    public Student(int roll, String name, double score) {
        this.roll = roll;
        this.name = name;
        this.score = score;
    }
    
    // Default constructor
    public Student() {
        this.roll = 0;
        this.name = "";
        this.score = 0;
    }
    
    // Copy constructor
    public Student(Student anotherStudent) {
        this.roll = anotherStudent.roll;
        this.name = anotherStudent.name;
        this.score = anotherStudent.score;
    }
    
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

public class Q8{    
    // Main method to test the class
    public static void main(String[] args) {
        // Create a student object with roll only
        Student student1 = new Student(1);
        System.out.println("Attributes of student1:");
        student1.displayAttributes();
        
        // Create a student object with roll and name only
        Student student2 = new Student(2, "Alice");
        System.out.println("\nAttributes of student2:");
        student2.displayAttributes();
        
        // Create a student object with roll, name, and score
        Student student3 = new Student(3, "Bob", 90.5);
        System.out.println("\nAttributes of student3:");
        student3.displayAttributes();
        
        // Create a student object with no value
        Student student4 = new Student();
        System.out.println("\nAttributes of student4:");
        student4.displayAttributes();
        
        // Test copy constructor
        Student student5 = new Student(student3);
        System.out.println("\nAttributes of student5 (copy of student3):");
        student5.displayAttributes();
        
        // Modify attributes of student5
        student5.setAttributes(4, "Carol", 85.0);
        System.out.println("\nAttributes of student5 (after modification):");
        student5.displayAttributes();
        
        // Display attributes of student3 to verify deep copy
        System.out.println("\nAttributes of student3 (to verify deep copy):");
        student3.displayAttributes();
    }
}
