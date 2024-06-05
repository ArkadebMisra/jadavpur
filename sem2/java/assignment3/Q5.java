import java.io.*;
import java.util.ArrayList;
import java.util.List;

class Student implements Serializable {
    private static final long serialVersionUID = 1L;

    private int roll;
    private String name;
    private double score;

    public Student(int roll, String name, double score) {
        this.roll = roll;
        this.name = name;
        this.score = score;
    }

    @Override
    public String toString() {
        return "Student{" +
                "roll=" + roll +
                ", name='" + name + '\'' +
                ", score=" + score +
                '}';
    }
}

public class Q5 {

    public static void main(String[] args) {
        String fileName = "students.dat";

        List<Student> students = new ArrayList<>();
        students.add(new Student(1, "Alice", 85.5));
        students.add(new Student(2, "Bob", 90.0));
        students.add(new Student(3, "Charlie", 78.5));
        students.add(new Student(4, "Diana", 92.0));
        students.add(new Student(5, "Eve", 88.5));

        // Write students to the file
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(fileName))) {
            for (Student student : students) {
                oos.writeObject(student);
            }
            System.out.println("Student objects have been serialized to " + fileName);
        } catch (IOException e) {
            System.err.println("Error writing to the file: " + e.getMessage());
        }

        // Read students from the file
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(fileName))) {
            System.out.println("Reading student objects from " + fileName + ":");
            while (true) {
                try {
                    Student student = (Student) ois.readObject();
                    System.out.println(student);
                } catch (EOFException e) {
                    break; // End of file reached
                }
            }
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Error reading from the file: " + e.getMessage());
        }
    }
}

