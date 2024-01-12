package streams;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Date;
import java.util.Vector;

public class Book implements Serializable{

	private String author;
	private String title;
	private Date published;
	static Vector<Book> books;
	static {
		if(new File("books.ser").exists()) {
			try {
				books = readBooks();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		else books = new Vector<Book>();
	}

	public Book() {

	}
	public Book(String author, String title) {
		this.author = author;
		this.title = title;
		this.published = new Date();
	}
	public String getAuthor() {
		return author;
	}
	public void setAuthor(String author) {
		this.author = author;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public Date getPublished() {
		return published;
	}
	public void setPublished(Date published) {
		this.published = published;
	}
	static Vector<Book> readBooks() throws Exception{
		FileInputStream fis = new FileInputStream("books.ser");
		ObjectInputStream ois = new ObjectInputStream(fis);
		Vector<Book> books = (Vector<Book>)ois.readObject();
		fis.close();
		ois.close();
		return books;
	}
	static void saveBooks() throws Exception {
		FileOutputStream fos = new FileOutputStream("books.ser");
		ObjectOutputStream oos = new ObjectOutputStream(fos);
		oos.writeObject(books);
		fos.close();
		oos.close();
	}
	public String toString() {
		return author + " "+title+ " "+published;
	}
}
