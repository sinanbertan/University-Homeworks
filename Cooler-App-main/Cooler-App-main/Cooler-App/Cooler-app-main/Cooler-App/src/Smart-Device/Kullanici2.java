package AkilliCihaz;

public class Kullanici2 implements IObserver {
	public String username;
	public String password;
	public void kullaniciyaIlet(String mesaj) {
		System.out.println("Kullanici 2: "+mesaj);
	}
	public Kullanici2(){
		VeritabaniBaglantisi vt = new VeritabaniBaglantisi();
		username = vt.getUsername(2);
		password = vt.getPassword(2);
	}
	public String getUsername() {
		return username;
	}
	public String getPassword() {
		return password;
	}
}
