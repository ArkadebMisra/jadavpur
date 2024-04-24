import java.util.Scanner;

class NumericWrapper {
    private Integer value;

    // Constructor to create wrapper object from basic type
    public NumericWrapper(int value) {
        this.value = value;
    }

    // Method to convert object to basic type
    public int toBasicType() {
        return value;
    }

    // Method to convert basic type to String
    public String toStringFromBasicType() {
        return String.valueOf(value);
    }

    // Method to convert String (holding numeric data) to numeric object
    public static NumericWrapper fromString(String str) throws NumberFormatException {
        int numericValue = Integer.parseInt(str);
        return new NumericWrapper(numericValue);
    }

    // Method to convert object to String
    @Override
    public String toString() {
        return String.valueOf(value);
    }

    }

public class Q6 {
    public static void main(String[] args) {
        // Conversion from basic type to object
        Scanner sc = new Scanner(System.in);
        System.out.println("enter basic type value");
        int basicTypeValue = Integer.parseInt(sc.nextLine());
        NumericWrapper wrapper = new NumericWrapper(basicTypeValue);

        // Conversion from object to basic type
        int convertedBasicTypeValue = wrapper.toBasicType();
        System.out.println("Converted basic type value: " + convertedBasicTypeValue);

        // Conversion from basic type to String
        String stringFromBasicType = wrapper.toStringFromBasicType();
        System.out.println("String from basic type: " + stringFromBasicType);

        // Conversion from String to numeric object
        System.out.println("enter a numeric value as string");
        String numericString = sc.nextLine();
        try {
            NumericWrapper numericObject = NumericWrapper.fromString(numericString);
            System.out.println("Numeric object from string: " + numericObject);
        } catch (NumberFormatException e) {
            System.out.println("Error: Invalid format for numeric string.");
        }

        // Conversion from object to String
        String stringFromObject = wrapper.toString();
        System.out.println("String from object: " + stringFromObject);
        sc.close();
    }

}
