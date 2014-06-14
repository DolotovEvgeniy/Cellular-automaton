template <class T>
void delete_array(T**& _array,int h)
{
	for(int i=0;i<h;i++)
			{
				delete _array[i];
			}
			delete _array;
}
template <class T>
void copy_array(T**& array1,T**& array2,int h,int w)
{
array2=new T*[h];
			for(int i=0;i<h;i++)
			{
				array2[i]=new T[w];
			}
			for(int i=0;i<h;i++)
			{
				for(int j=0;j<w;j++)
				array2[i][j]=array1[i][j];	
			}
}
class Dequeue
{
public:
	int size,maxSize;
	int w_data,h_data;
	char** * myarray;
	int first,last;
	Dequeue()
	{
		size=0;
		maxSize=10;
		w_data=h_data=20;
		myarray=new char**[maxSize];
		first=-1;
		last=0;
	}
	Dequeue(int _size,int _w_data,int _h_data)
	{
		size=0;
		w_data=_w_data;
		h_data=_h_data;
		maxSize=_size;
		myarray=new char**[maxSize];
		first=-1;
		last=0;
	}
	~Dequeue()
	{
		size=maxSize=w_data=h_data=0;
		for(int i=0;i<maxSize;i++)
			delete[] myarray[i];
		delete myarray;
	}
	bool IsEmpty()
	{
		return size==0;
	}
	bool IsFull()
	{
		return size==maxSize;
	}
	char** pop_back()
	{
		if(!IsEmpty())
		{
			char** temp=myarray[last];
			myarray[last]=NULL;
			last=(last+1)%maxSize;
			size--;
			return temp;
		}
		else return NULL;
	}
	char** pop_front()
	{
		if(!IsEmpty())
		{
			char** temp=myarray[first];
			//delete myarray[last];
			myarray[first]=NULL;
			first=(first-1+maxSize)%maxSize;
			size--;
			return temp;
		}
		else 
			return NULL;
	}
	void push(char** data)
	{
		first=(first+1)%maxSize;
		if(IsFull())
		{
			char** temp=pop_back();
			delete_array(temp,h_data);
			copy_array(data,myarray[first],h_data,w_data);
		}
		else
			copy_array(data,myarray[first],h_data,w_data);
		size++;
	}
};