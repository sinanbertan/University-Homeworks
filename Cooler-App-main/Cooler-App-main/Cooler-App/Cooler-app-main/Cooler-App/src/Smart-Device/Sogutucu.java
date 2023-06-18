package AkilliCihaz;

public class Sogutucu implements ICihaz {
	private String durum;
	public Sogutucu(){
		durum="kapali";
	}
	public void ac() {
		durum="acik";
	}
	public void kapat() {
		durum="kapali";
	}
	public String durumBilgisiAl() {
		return durum;
	}
}
