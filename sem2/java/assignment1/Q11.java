// Instructor class
class Instructor {
    private String name;
    private String phoneNumber;
    
    // Constructor
    public Instructor(String name, String phoneNumber) {
        this.name = name;
        this.phoneNumber = phoneNumber;
    }
    
    // Method to set instructor information
    public void setInstructorInfo(String name, String phoneNumber) {
        this.name = name;
        this.phoneNumber = phoneNumber;
    }
    
    // Method to view instructor information
    public void viewInstructorInfo() {
        System.out.println("Instructor Name: " + name);
        System.out.println("Phone Number: " + phoneNumber);
    }
}

// Textbook class
class Textbook {
    private String title;
    private String author;
    private String publisher;
    
    // Constructor
    public Textbook(String title, String author, String publisher) {
        this.title = title;
        this.author = author;
        this.publisher = publisher;
    }
    
    // Method to set textbook data
    public void setTextbookData(String title, String author, String publisher) {
        this.title = title;
        this.author = author;
        this.publisher = publisher;
    }
    
    // Method to view textbook data
    public void viewTextbookData() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Publisher: " + publisher);
    }
}

// Course class
class Course {
    private String courseName;
    private Instructor instructor;
    private Textbook textbook;
    
    // Constructor
    public Course(String courseName, Instructor instructor, Textbook textbook) {
        this.courseName = courseName;
        this.instructor = instructor;
        this.textbook = textbook;
    }
    
    // Method to set course data
    public void setCourseData(String courseName, Instructor instructor, Textbook textbook) {
        this.courseName = courseName;
        this.instructor = instructor;
        this.textbook = textbook;
    }
    
    // Method to view course data
    public void viewCourseData() {
        System.out.println("Course Name: " + courseName);
        System.out.println("Instructor Information:");
        instructor.viewInstructorInfo();
        System.out.println("Textbook Information:");
        textbook.viewTextbookData();
    }
}


public class Q11{
    public static void main(String[] args) {
        // Create an Instructor object
        Instructor instructor = new Instructor("John Doe", "123-456-7890");
        
        // View initial instructor information
        System.out.println("Initial Instructor Information:");
        instructor.viewInstructorInfo();
        
        // Set new instructor information
        instructor.setInstructorInfo("Jane Smith", "987-654-3210");
        
        // View updated instructor information
        System.out.println("\nUpdated Instructor Information:");
        instructor.viewInstructorInfo();
        
        // Create a Textbook object
        Textbook textbook = new Textbook("Java Programming", "Jane Smith", "Publisher X");
        
        // View textbook information
        System.out.println("\nTextbook Information:");
        textbook.viewTextbookData();
        
        // Create a Course object
        Course course = new Course("Introduction to Java", instructor, textbook);
        
        // View course information
        System.out.println("\nCourse Information:");
        course.viewCourseData();
    }
}
