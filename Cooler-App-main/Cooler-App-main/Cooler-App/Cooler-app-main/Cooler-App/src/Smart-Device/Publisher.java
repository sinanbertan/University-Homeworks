package AkilliCihaz;
import java.util.ArrayList;
import java.util.List;

public class Publisher implements ISubject {
	private List<IObserver> kullanicilar = new ArrayList<>();

   
    public void attach(IObserver kullanici) {
        kullanicilar.add(kullanici);
    }

  
    public void detach(IObserver kullanici) {
    	kullanicilar.remove(kullanici);
    }

    
    public void notify(String mesaj) {
        for(IObserver kullanici: kullanicilar) {
        	kullanici.kullaniciyaIlet(mesaj);
        }
        
    }
    public void notify(String mesaj, int i) {
       kullanicilar.get(i).kullaniciyaIlet(mesaj);
    }
    public List getUsers() {
    	return kullanicilar;
    }
}
