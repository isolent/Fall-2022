package problem2;

public class Points implements MoveVertically{
	private int x, y;
	
	public Points(int x, int y) {
		this.setX(x);
		this.setY(y);
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	@Override
	public void fastRight() {
		// TODO Auto-generated method stub
		x += 2;
	}

	@Override
	public void fastLeft() {
		// TODO Auto-generated method stub
		x -= 2;
	}
	
	public void fastUp() {
		y += 2;
	}
	
	public void fastDown() {
		y -= 2;
	}

	@Override
	public String toString() {
		return "Points [x=" + x + ", y=" + y + "]";
	}
	
	
}
