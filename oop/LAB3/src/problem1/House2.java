package problem1;

public class House2 extends House implements HasTwoFloors, CanBeSold{
	double width, length, height;
	int amount;
	
	public House2(double w, double l, double h, int a){
		this.width = w;
		this.length = l;
		this.height = h;
		this.amount = a;
	}
	
	@Override
	public double findHouseArea() {
		// TODO Auto-generated method stub
		return width * length;
	}

	@Override
	public double getHeight() {
		// TODO Auto-generated method stub
		return this.height;
	}

	@Override
	public double getPrice() {
		// TODO Auto-generated method stub
		return this.findHouseArea() * CanBeSold.ONESQMETER;
	}
	
	@Override
	public String toString() {
	return "House2 [width=" + width + ", length=" + length + ", height=" + height + "]" + "\rPrice: " + this.getPrice() + " $";
	}

	@Override
	public boolean has() {
		// TODO Auto-generated method stub
		if(this.amount == 2) return true;
		return false;
	}

}