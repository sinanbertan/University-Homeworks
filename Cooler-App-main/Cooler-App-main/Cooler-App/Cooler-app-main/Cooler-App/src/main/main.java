package main;

import AkilliCihaz.*;
import java.util.Scanner;
public class main {
	
	public static void main(String[] args) {
		IAlgilayici sicaklikAlgilayici = new SicaklikAlgilayici();
		ICihaz sogutucu = new Sogutucu();
		Eyleyici eyleyici = new Eyleyici(sogutucu);
		Publisher publisher = new Publisher();
		VeritabaniBaglantisi vt = new VeritabaniBaglantisi();
		vt.baglan();
		Scanner sc = new Scanner(System.in);
		System.out.print("Kullanici Adi: ");
		String username = sc.next();
		System.out.print("Sifre: ");
		String password = sc.next();
		AgArayuzu agArayuzu = new AgArayuzu.AgArayuzuBuilder(publisher, sicaklikAlgilayici, eyleyici)
				.durum()
				.index()
				.sicaklik()
				.build();
		if(agArayuzu.giris(username, password)) {
			agArayuzu.ac();
			agArayuzu.islemSec();
		}
	}

}