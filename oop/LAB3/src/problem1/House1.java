package problem1;

public class House1 extends House{
	double width, length, height;
	
	public House1(double w, double l, double h){
		this.width = w;
		this.length = l;
		this.height = h;
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
	public String toString() {
		return "House1 [width=" + width + ", length=" + length + ", height=" + height + "]";
	}

}
