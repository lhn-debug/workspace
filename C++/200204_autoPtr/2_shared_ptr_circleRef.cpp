#include<iostream>
#include<memory>

using namespace std;

class Node
{
public:
	Node()
	{
		cout<<"Node()"<<endl;
	}

	~Node()
	{
		cout<<"~Node()"<<endl;
	}
public:
	int _data;
	weak_ptr<Node> _prev;
	weak_ptr<Node> _next;
};

int main()
{
	shared_ptr<Node> node1(new Node());
	shared_ptr<Node> node2(new Node());
	cout<<node1.use_count()<<endl;
	cout<<node2.use_count()<<endl;
	node1->_next = node2;
	node2->_prev = node1;
	cout<<node1.use_count()<<endl;
	cout<<node2.use_count()<<endl;
	return 0;
}
