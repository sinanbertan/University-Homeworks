#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"


class List{
	private:
		Node *head;
		int size;
		
		//girilen indexteki nodun öncesinde ki nodu bulma komutu
		Node *FindPreviousNode(int index){
			Node *prev = head;
			int i=1;
			for(Node *itr=head;itr->next != NULL && i!=index;itr=itr->next,i++){
				prev = prev->next;
			}
			return prev;
		}
	public:
		//yapıcı metod
		List(){
			head = NULL;//boş düğüm kullanılmadı
			size=0;
		}
		//boyutu öğrenme komutu
		int Count()const{
			return size;
		}
		//sona node ekleme komutu
		void add(const string& item){
			insert(size,item);
		}
		//araya eleman ekleme komutu
		void insert(int index,const string& item){
			
			if(index == 0){
				head= new Node(item,head);
				if(head->next != NULL)
					head->next->prev = head;
			}
			else{
				Node *prv = FindPreviousNode(index);
				prv->next = new Node(item,prv->next,prv);
				if(prv->next->next != NULL)
					prv->next->next->prev = prv->next;
			}
			size++;
		}

		//indexi girilen nodu silme komutu
		void removeAt(int index){
			Node *del;
			if(index == 0){
				del = head;
				head = head->next;
				if(head != NULL)
					head->prev = NULL;
			}
			else{
				Node *prv = FindPreviousNode(index);
				del = prv->next;
				prv->next = del->next;
				if(del->next != NULL)
					del->next->prev = prv;
			}
			size--;
			delete del;
		}
		//liste boş mu kontrol eden komut
		bool isEmpty()const{
			return size == 0;
		
		}
		//listeyi komple silme metodu
		void clear(){
			while(!isEmpty()){
				removeAt(0);
			}
		}
		friend ostream& operator<<(ostream& screen,List& right){
			for(Node *itr=right.head;itr!=NULL;itr=itr->next){
				screen<<itr->data<<" ";
			}
			screen<<endl;
			return screen;
		}
		
		//yıkısı metod
		~List(){
			clear();
		}
};


#endif