package AkilliCihaz;

public class Eyleyici {
	ICihaz sogutucu;

	public Eyleyici(ICihaz sogutucu){
		this.sogutucu = sogutucu;
	}
	
	public void ac() {
		sogutucu.ac();
	}
	
	public void kapat() {
		sogutucu.kapat();
	}
	public String durum() {
		return sogutucu.durumBilgisiAl();
	}
}
