package AkilliCihaz;
import java.util.List;

public interface ISubject {
	public void attach(IObserver o);
    public void detach(IObserver o);
    public void notify(String mesaj);
    public void notify(String mesaj, int i);
    public List getUsers();
}
