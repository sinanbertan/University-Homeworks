package AkilliCihaz;

public class Kullanici3 implements IObserver {
	public String username;
	public String password;
	public void kullaniciyaIlet(String mesaj) {
		System.out.println("Kullanici 3: "+mesaj);
	}
	public Kullanici3(){
		VeritabaniBaglantisi vt = new VeritabaniBaglantisi();
		username = vt.getUsername(3);
		password = vt.getPassword(3);
	}
	public String getUsername() {
		return username;
	}
	public String getPassword() {
		return password;
	}
}
