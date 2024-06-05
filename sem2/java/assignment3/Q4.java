import java.io.*;

public class Q4 {

    public static void main(String[] args) {
        String fileName = "names.txt";
        String[] names = {"Arka", "Sohini", "Somosree", "Bismay", "Asmita", "Sayan"};

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            for (String name : names) {
                writer.write(name);
                writer.newLine();
            }
            System.out.println("Names have been written to " + fileName);
        } catch (IOException e) {
            System.err.println("Error writing to the file: " + e.getMessage());
        }

        // Reading names from the file
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            System.out.println("Reading names from " + fileName + ":");
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.err.println("Error reading from the file: " + e.getMessage());
        }
    }
}
