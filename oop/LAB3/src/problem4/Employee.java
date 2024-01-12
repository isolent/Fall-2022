package problem4;

import java.util.Date;
import java.util.Objects;


public class Employee extends Person implements Comparable<Employee>, Cloneable{
	
	double salary;
	public Date hireDate;
	private String insuranceNumber;
	int totalSalary;
	
	public Employee(String name, double salary, String insuranceNumber) {
		super(name);
		// TODO Auto-generated constructor stub
		this.setSalary(salary);
		this.hireDate = new Date();
		this.setInsuranceNumber(insuranceNumber);
	}

	public double getSalary() {
		return salary;
	}

	public void setSalary(double salary) {
		this.salary = salary;
	}

	public String getInsuranceNumber() {
		return insuranceNumber;
	}

	public void setInsuranceNumber(String insuranceNumber) {
		this.insuranceNumber = insuranceNumber;
	}
	
	public boolean equals(Object o) {
		if (this == o) return true;
		if (!super.equals(o)) return false;
		Employee e = (Employee) o;
		return Objects.equals(insuranceNumber, e.insuranceNumber)
				&& Objects.equals(salary, e.salary);
	}

	@Override
	public String toString() {
		return "Employee [ manager's " + super.toString() + " , salary=" + salary + ", hireDate=" + hireDate + ", insuranceNumber=" + insuranceNumber ;
	}

	@Override
	public int compareTo(Employee e) {
		// TODO Auto-generated method stub
		
		if (salary < e.salary) return -1;
		if (salary > e.salary) return 1;
		return 0;
	
	}
	
	
	public Object clone() throws CloneNotSupportedException{
	
		Employee e = (Employee) super.clone();
		e.hireDate=(Date) this.hireDate.clone();
		return e;

	}

	public int getTotalSalary() {
		return totalSalary;
	}

	public void setTotalSalary(int totalSalary) {
		this.totalSalary = totalSalary;
	}
}