import java.util.*;
class Department {
    private String deptCode;
    private String deptName;
    private String location;

    public Department(String deptCode, String deptName, String location) {
        this.deptCode = deptCode;
        this.deptName = deptName;
        this.location = location;
    }
    public String getDeptCode() {
        return deptCode;
    }

    public String getDeptName() {
        return deptName;
    }

    public String getLocation() {
        return location;
    }

    // Setters
    public void setDeptCode(String deptCode) {
        this.deptCode = deptCode;
    }

    public void setDeptName(String deptName) {
        this.deptName = deptName;
    }

    public void setLocation(String location) {
        this.location = location;
    }

}
class Employee{
    private String empCode;
    private String empName;
    private double basic;
    private String deptCode;

    public Employee(String empCode, String empName, double basic, String deptCode) {
        this.empCode = empCode;
        this.empName = empName;
        this.basic = basic;
        this.deptCode = deptCode;
    }
    public String getEmpCode() {
        return empCode;
    }

    public String getEmpName() {
        return empName;
    }

    public double getBasic() {
        return basic;
    }

    public String getDeptCode() {
        return deptCode;
    }

    // Setters
    public void setEmpCode(String empCode) {
        this.empCode = empCode;
    }

    public void setEmpName(String empName) {
        this.empName = empName;
    }

    public void setBasic(double basic) {
        this.basic = basic;
    }

    public void setDeptCode(String deptCode) {
        this.deptCode = deptCode;
    }
}
class Company {
    private List<Department> departments;
    private List<Employee> employees;

    public Company() {
        departments = new ArrayList<>();
        employees = new ArrayList<>();
    }

    public void addDepartment(Department department) {
        departments.add(department);
    }

    public void addEmployee(Employee employee) {
        employees.add(employee);
    }

    public void displayEmployeeDetails(String empCode) {
        for (Employee emp : employees) {
            if (emp.getEmpCode().equals(empCode)) {
                String deptCode = emp.getDeptCode();
                for (Department dept : departments) {
                    if (dept.getDeptCode().equals(deptCode)) {
                        System.out.println("Employee Details:");
                        System.out.println("Employee Code: " + emp.getEmpCode());
                        System.out.println("Employee Name: " + emp.getEmpName());
                        System.out.println("Basic Pay: " + emp.getBasic());
                        System.out.println("Department Details:");
                        System.out.println("Department Code: " + dept.getDeptCode());
                        System.out.println("Department Name: " + dept.getDeptName());
                        System.out.println("Location: " + dept.getLocation());
                        return;
                    }
                }
            }
        }
        System.out.println("Employee with code " + empCode + " not found.");
    }
    public void displayAllEmployees() {
        System.out.println("Employee Details:");
        for (Employee emp : employees) {
            System.out.println("Employee Code: " + emp.getEmpCode());
            System.out.println("Employee Name: " + emp.getEmpName());
            System.out.println("Basic Pay: " + emp.getBasic());
            System.out.println("Department Code: " + emp.getDeptCode());
            System.out.println();
        }
    }
    public double getTotalBasicPayForDepartment(String deptCode) {
        double totalBasicPay = 0;
        for (Employee emp : employees) {
            if (emp.getDeptCode().equals(deptCode)) {
                totalBasicPay += emp.getBasic();
            }
        }
        return totalBasicPay;
    }
    public void removeEmployee(String empCode) {
        for (int i = 0; i < employees.size(); i++) {
            if (employees.get(i).getEmpCode().equals(empCode)) {
                employees.remove(i);
                System.out.println("Employee with code " + empCode + " removed successfully.");
                return;
            }
        }
        System.out.println("Employee with code " + empCode + " not found.");
    }
    public void modifyBasicPay(String empCode, double newBasic) {
        for (Employee emp : employees) {
            if (emp.getEmpCode().equals(empCode)) {
                emp.setBasic(newBasic);
                System.out.println("Basic pay for employee with code " + empCode + " modified successfully.");
                return;
            }
        }
        System.out.println("Employee with code " + empCode + " not found.");
    }

}
public class EmployeeQ1 {
    public static void main(String[] args) {
        Company company = new Company();
        Scanner scanner = new Scanner(System.in);

        // Add departments
        System.out.println("Enter department details (dept code, dept name, location), type 'done' to finish:");
        while (true) {
            String input = scanner.nextLine();
            if (input.equals("done")) {
                break;
            }
            String[] deptDetails = input.split(",");
            if (deptDetails.length != 3) {
                System.out.println("Invalid input. Please enter again.");
                continue;
            }
            String deptCode = deptDetails[0].trim();
            String deptName = deptDetails[1].trim();
            String location = deptDetails[2].trim();
            Department department = new Department(deptCode, deptName, location);
            company.addDepartment(department);
        }

        // Add employees
        System.out.println("Enter employee details (emp code, emp name, basic pay, dept code), type 'done' to finish:");
        while (true) {
            String input = scanner.nextLine();
            if (input.equals("done")) {
                break;
            }
            String[] empDetails = input.split(",");
            if (empDetails.length != 4) {
                System.out.println("Invalid input. Please enter again.");
                continue;
            }
            String empCode = empDetails[0].trim();
            String empName = empDetails[1].trim();
            double basicPay = Double.parseDouble(empDetails[2].trim());
            String deptCode = empDetails[3].trim();
            Employee employee = new Employee(empCode, empName, basicPay, deptCode);
            company.addEmployee(employee);
        }

        // Display employee details
        System.out.println("\nEmployee Details:");
        company.displayAllEmployees();

        // Display employee details along with corresponding department details
        System.out.println("\nEnter employee code to display details:");
        String empCode = scanner.nextLine();
        company.displayEmployeeDetails(empCode);

        // Find total basic pay for a department
        System.out.println("\nEnter department code to find total basic pay:");
        String deptCode = scanner.nextLine();
        double totalBasicPay = company.getTotalBasicPayForDepartment(deptCode);
        System.out.println("Total basic pay for department " + deptCode + ": " + totalBasicPay);

        // Remove an employee
        System.out.println("\nEnter employee code to remove employee:");
        empCode = scanner.nextLine();
        company.removeEmployee(empCode);

        // Modify basic pay of an employee
        System.out.println("\nEnter employee code to modify basic pay:");
        empCode = scanner.nextLine();
        System.out.println("Enter new basic pay:");
        double newBasicPay = Double.parseDouble(scanner.nextLine());
        company.modifyBasicPay(empCode, newBasicPay);

        // Sort the employee list

        scanner.close();
    }
    
}
