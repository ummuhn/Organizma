#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP


template <typename Object>
class ArrayList{
	private:
		Object *items;
		int length;
		int capacity;
		void reserve(int newCapacity)
		{
			 if(capacity>=newCapacity) return;
			 Object *tmp = new Object[newCapacity];
			 for(int j=0;j<length;j++) tmp[j]= items[j];
			 if(items != NULL) delete [] items;
			 items = tmp;
			 capacity = newCapacity;
		}
	public:
		ArrayList()
		{
			length = 0;
			capacity=0;
			items = NULL;
		}
		ArrayList(const ArrayList &right) // Copy constructor
		{
			length = 0;
			items = new Object[right->length()];
			for(int i=0;i<right.size();i++){
				insert(i,right.at(i));
			}
			capacity=length;
		}
		int size() const
		{
			return length;
		}
		bool isEmpty() const
		{
			return size() == 0;
		}
		int indexOf(const Object& item) 
		{
			for(int i=0;i<length;i++){
				if(items[i] == item)return i;
			}
			throw "No Such Element"; 
		}
		const Object& elementAt(int i) 
		{
			if(i<0 || i>=length) throw "No Such Element";
			return items[i]; 
		}
		void remove(const Object& item) 
		{
			for(int i=0;i<length;i++){
				if(items[i] == item){
					removeAt(i);
					return;
				}
			}
			throw "No Such Element";
		}
		void removeAt(int i) 
		{
			if(i<0 || i>=length) throw "No Such Element";
			for(int j=i+1;j<length;j++) items[j - 1] = items[j];
			length--;
		}
		void add(const Object& item)
		{			
			insert(length,item);				
		}
		void insert(int i,const Object& item)
		{
			if(i<0 || i>length) throw "Index Out Of Bound"; 
			if(length >= capacity) reserve(max(1,2*capacity)); 
			for(int j=length-1;j>=i;j--) items[j + 1] = items[j];
			items[i] = item;
			length++;					
		}
		const Object& first() 
		{
			if(length == 0) throw "List is empty"; 
			return items[0];
		}
		const Object& last() {
			if(length == 0) throw "List is empty"; 
			return items[length-1];
		}
		void clear()
		{
			length = 0;
		}
		friend ostream& operator<<(ostream& screen,ArrayList<Object>& right){
			screen<<endl;
			for(int i=0;i<right.length;i++){
				screen<<right.items[i];
				if(i+1!=right.length)screen<<" || ";
			}
			return screen;
		}
		~ArrayList()
		{
			if(items != NULL) delete [] items;
		}
};

#endif
