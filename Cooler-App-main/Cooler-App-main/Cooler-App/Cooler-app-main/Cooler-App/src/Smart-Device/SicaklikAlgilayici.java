package AkilliCihaz;
import java.util.Random;
public class SicaklikAlgilayici implements IAlgilayici {
	public int algila(){
		Random rand = new Random();
		int sicaklik = rand.nextInt(100)+(-50);
		return sicaklik;
	}
}
