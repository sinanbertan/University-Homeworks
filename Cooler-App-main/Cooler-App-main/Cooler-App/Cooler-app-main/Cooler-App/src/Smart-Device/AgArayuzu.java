package AkilliCihaz;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AgArayuzu {
		private IAlgilayici sicaklikAlgilayici;
		private String durum;
		private Eyleyici eyleyici;
		ISubject publisher;
		private int sicaklik;
		private int index;
		public AgArayuzu(ISubject publisher, IAlgilayici sicaklikAlgilayici, Eyleyici eyleyici){
			this.sicaklikAlgilayici = sicaklikAlgilayici;
			durum="kapali";
			this.publisher = publisher;
			sicaklik=0;
			this.eyleyici=eyleyici;
			index = -1;
		}
		
		public AgArayuzu(AgArayuzuBuilder builder) {
			this.sicaklikAlgilayici = builder.sicaklikAlgilayici;
			durum=builder.durum;
			this.publisher = builder.publisher;
			sicaklik = builder.sicaklik;
			this.eyleyici = builder.eyleyici;
			index = builder.index;
		}
		
		public void algila() {
			sicaklik = sicaklikAlgilayici.algila();
			publisher.notify("Sicaklik: "+sicaklik,index);
		}
		
		String durumBilgisiAl() {
			return durum;
		}
		
		public int ac() {
			if(durum=="kapali") {
				durum = "bekleme";
				publisher.notify("Akilli cihaz acildi.",index);
				return 1;
			}
			else if(durum == "servis disi") {
				publisher.notify("Akilli cihaz servis disi.",index);
				return 2;
			}
			else if(durum == "algila") {
				publisher.notify("Akilli cihaz algilamada.",index);
				return 3;
			}
			else {	
				publisher.notify("Akilli cihaz zaten acik.",index);
			return 1;
			}
		}
		
		public void sogutucuAc() {
			if(eyleyici.durum().equals("kapali")){
				eyleyici.ac();
				publisher.notify("Sogutucu acildi.",index);
			}
			else {
				publisher.notify("Sogutucu zaten acik.",index);
			}
		}
		
		public void sogutucuKapat() {
			if(eyleyici.durum().equals("acik")){
				eyleyici.kapat();
				publisher.notify("Sogutucu kapatildi.",index);
			}
			else {
				publisher.notify("Sogutucu zaten kapali.",index);
			}
		}
		
		public void islemSec() {
			Boolean kontrol = true;
			int secim = 0;
			Scanner sc = new Scanner(System.in);
			while(kontrol) {
				System.out.println("- Sicaklik bilgisi almak icin 1'e \n- Sogutucuyu acmak icin 2'ye \n- Sogutucuyu kapatmak icin 3'e \n- Cikis yapmak icin 4'e basýn.");
				secim = sc.nextInt();
				if(secim == 1) {
					algila();
				}
				else if(secim == 2) {
					sogutucuAc();
				}
				else if(secim == 3) {
					sogutucuKapat();
				}
				else if(secim == 4) {
					kontrol = false;
				}
				else {
					System.out.println("Hatali Giris!");
				}
				if(kontrol) {
					Boolean control =true;
					while(control) {
							System.out.println("Baska bir islem yapacak misiniz?(evet icin 1'e, hayir icin 2'ye basin)");
							secim = sc.nextInt();
							if(secim == 1) {
								break;
							}
							else if(secim == 2) {
								control = false;
								kontrol = false;
							}
							else { 
								System.out.println("Hatali Giris!");
							}
					}
				}
			}
		}
		public Boolean giris(String username, String password)
		{
			List<IObserver> kullanicilar = publisher.getUsers();
			int i = 0;
			Boolean kontrol = false;
			Kullanici1 k1 = new Kullanici1();
			Kullanici2 k2 = new Kullanici2();
			Kullanici3 k3 = new Kullanici3();
			publisher.attach(k1);
			publisher.attach(k2);
			publisher.attach(k3);
			int a = 0;
			while(i < kullanicilar.size()) {
				if(kullanicilar.get(i).getUsername().equals(username) && kullanicilar.get(i).getPassword().equals(password)) {
					kontrol = true;
					index = i;
				}	
				i++;
			}
			if(index>=0) {
				publisher.notify("Giris Basarili.",index);
				return true;
			}
			else {
				System.out.println("Giris Basarisiz.");
				return false;
			}
		}
		
		
		public static class AgArayuzuBuilder{
				private IAlgilayici sicaklikAlgilayici;
				private String durum;
				private Eyleyici eyleyici;
				ISubject publisher;
				private int sicaklik;
				private int index;
		        public AgArayuzuBuilder(ISubject publisher, IAlgilayici sicaklikAlgilayici, Eyleyici eyleyici) {
		        	this.sicaklikAlgilayici = sicaklikAlgilayici;
					this.publisher = publisher;
					this.eyleyici=eyleyici;
		        }
		        public AgArayuzuBuilder durum() {
		           this.durum = "kapali";
		           return this;
		        }
		        public AgArayuzuBuilder sicaklik () {
		        	this.sicaklik = 0;
			        return this;
		        }
		        public AgArayuzuBuilder index () {
		        	this.index = -1;
			        return this;
		        }
		        public AgArayuzu build() {
		            return new AgArayuzu(this);
		        }
		}
}
