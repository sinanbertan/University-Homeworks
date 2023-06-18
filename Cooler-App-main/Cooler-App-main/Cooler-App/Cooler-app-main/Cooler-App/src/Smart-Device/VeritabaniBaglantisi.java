package AkilliCihaz;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class VeritabaniBaglantisi {
	Connection conn = null;
	Boolean kontrol = false;
	List<String> usernames = new ArrayList<>();
	List<String> passwords = new ArrayList<>();
	public VeritabaniBaglantisi() {

		 try {
			 conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/b181210056","postgres","123");
			 if(conn!=null) {
				 kontrol = true;
			 }
			 else {
				 kontrol = false;
			 }
			 
			 String sql="SELECT * FROM \"Users\" ";
			 Statement stmt = conn.createStatement();
			 ResultSet rs = stmt.executeQuery(sql);
		     while(rs.next()) {
		    	 usernames.add(rs.getString("username"));
		    	 passwords.add(rs.getString("password"));
		     }
		     
		 }

		 catch (SQLException e) {
		 e.printStackTrace();
		 }
	}
	
	public String getUsername(int i) {
		return usernames.get(i-1);
	}
	
	public String getPassword(int i) {
		return passwords.get(i-1);
	}
	
	public void baglan() {
		 try {
			 conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/b181210056","postgres","123");
			 if(conn!=null) {
				 System.out.println("Veritabani baglantisi basarili.");
			 }
			 else {
				 System.out.println("Veritabani baglantisi basarisiz.");
			 }
			 
		 }

		 catch (SQLException e) {
		 e.printStackTrace();
		 }	
	}
}
