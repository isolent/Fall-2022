package problem4;

import java.util.Objects;


public class Manager extends Employee implements Cloneable{

	private double bonus;
	
	public Manager(String name, double salary, String insuranceNumber, double bonus) {
		super(name, salary, insuranceNumber);
		// TODO Auto-generated constructor stub
		this.setBonus(bonus);
	}
	
	public double getBonus() {
		return bonus;
	}
	
	public void setBonus(double bonus) {
		this.bonus = bonus;
	}
	

	@Override
	public boolean equals(Object o) {
		// TODO Auto-generated method stub
		if  (this == o) return true;
		if (!super.equals(o)) return false;
		Manager m = (Manager) o;
		return Objects.equals(bonus, m.bonus);
	}

	@Override
	public String toString() {
		return super.toString() + ", bonus= " + bonus;
	}
		
	public Object clone() throws CloneNotSupportedException {
		Manager m = (Manager)super.clone();
		return m;

	}
}
