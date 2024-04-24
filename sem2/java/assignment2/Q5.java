

import java.util.Scanner;

// Custom exception for invalid score
class InvalidScoreException extends Exception {
    public InvalidScoreException(String message) {
        super(message);
    }
}

// Student class
class Student {
    private int roll;
    private String name;
    private int score;

    public Student(int roll, String name) {
        this.roll = roll;
        this.name = name;
        this.score = -1; // Initializing score to a non-valid value
    }

    // Getter methods
    public int getRoll() {
        return roll;
    }

    public String getName() {
        return name;
    }

    public int getScore() {
        return score;
    }

    // Setter method for score with exception handling
    public void setScore(int score) throws InvalidScoreException {
        if (score < 0 || score > 100) {
            throw new InvalidScoreException("Invalid score! Score must be between 0 and 100.");
        }
        this.score = score;
    }
}

// Main class to test Student class
public class Q5 {
    public static void main(String[] args) {
        // Creating a new student
        Scanner sc = new Scanner(System.in);
        System.out.println("roll and name and score");
        String name = sc.nextLine();
        int roll = Integer.parseInt(sc.nextLine());
        Student student = new Student(roll, name);
        int score = Integer.parseInt(sc.nextLine());
        // Testing setScore method with valid score
        try {
            student.setScore(score);
            System.out.println("Score set successfully.");
        } catch (InvalidScoreException e) {
            System.out.println("Error setting score: " + e.getMessage());
        }

        // Displaying student information
        System.out.println("Student Roll: " + student.getRoll());
        System.out.println("Student Name: " + student.getName());
        System.out.println("Student Score: " + student.getScore());
        sc.close();
    }
}

