package Model;

import java.util.Calendar;
import java.util.Date;

public class User implements Comparable <User> , Cloneable{
	private int userId;
	private String login;
	private String password;
	private boolean loginStatus;
	
	private Date registerDate;
	
	public static int cnt = 0;
	
	{
		User.cnt++;
		loginStatus = false;
	}
	
	public User(String login, String password) {
		userId = User.cnt;
		this.login = login;
		this.password = password;
		registerDate = (Date)Calendar.getInstance().getTime();
	}
	
	public boolean verifyLogin(String login, String password){
		return this.login.equals(login) && this.password.equals(password);
	}
	
	public int getUserId() {
		return userId;
	}
	
	public String getLogin() {
		return this.login;
	}
	
	public boolean isLoginStatus() {
		return loginStatus;
	}
	
	public void setLoginStatus(boolean loginStatus) {
		this.loginStatus = loginStatus;
	}
	
	public Date getRegisterDate() {
		return registerDate;
	}

	@Override
	public int compareTo(User o) {
		// TODO Auto-generated method stub
		
		return this.login.compareTo(o.login);
	}
	
	public Object clone() throws CloneNotSupportedException {
		User clone = (User) super.clone();
		return clone.registerDate = (Date) this.registerDate.clone();
		
	}
}
