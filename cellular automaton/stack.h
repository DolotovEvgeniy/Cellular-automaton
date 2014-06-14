template <class T>
class Node
{
public:
	T data;
	Node* next;
	Node()
	{
		next=NULL;
	}
	Node(const Node& _node)
	{
		next=_node.next;
		data=_node.data;
	}
	Node& operator=(const Node& _node)
	{
		next=_node.next;
		data=_node.data;
	}
	Node(T _data)
	{
		data=_data;
		next=0;
	}
	bool operator==(const Node& _node)
	{
		return (next==_node.next&&data==_node.data);
	}
};
template <class T>
class MyStack
{
public:
	int size;
	Node<T>* first;
	MyStack()
	{
		first=0;
		size=0;
	}
	MyStack(const MyStack& _stack)
	{
		first=_stack.first;
		size=_stack.size;
	}
	bool IsEmpty()
	{
		return size==0;
	}
	void push(T _data)
	{
		Node<T>* temp=new Node<T>(_data);
		temp->next=first;
		first=temp;
		size++;
	}
	void pop()
	{
		if(IsEmpty())
		{
			int i=-1;
			throw i;
		}
			Node<T>* temp=first;
			first=first->next;
			T datatemp=temp->data;
			delete temp;
			size--;
	}
	T top()
	{
		if(IsEmpty())
		{
			int i=-1;
			throw i;
		}
		return first->data; 
	}
	~MyStack()
	{
		Node<T>* f=first;
		while(f!=0)
		{
			f=first->next;
			delete first;
			first=f;
		}
	}

};