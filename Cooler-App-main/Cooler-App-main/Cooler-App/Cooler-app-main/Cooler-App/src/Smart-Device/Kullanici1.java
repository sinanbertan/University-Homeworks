package AkilliCihaz;

public class Kullanici1 implements IObserver {
	public String username;
	public String password;
	public void kullaniciyaIlet(String mesaj) {
		System.out.println("Kullanici 1: "+mesaj);
	}
	public Kullanici1(){
		VeritabaniBaglantisi vt = new VeritabaniBaglantisi();
		username = vt.getUsername(1);
		password = vt.getPassword(1);
	}
	public String getUsername() {
		return username;
	}
	public String getPassword() {
		return password;
	}
}
