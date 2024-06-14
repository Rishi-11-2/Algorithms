#include<iostream>

using namespace std;

class  sllnode
{
	public:  int val;  // node info
	sllnode  *next;    //  link to next node

	static  sllnode  *avail;  //  avail list - keeps a list of all deleted nodes available for use when new node need to be created

	sllnode(int  x=-1, sllnode *p=NULL)
	{
		//cout<<"constructing sllnode "<<endl;
		val=x;   next=p;   // initializing node members
	}
	~sllnode()
	{
		//cout<<"destroying sllnode "<<endl;
		val=-1;  next=NULL; // reseting the value of the member to ensure security
	}
    // overloading new operator 
	void *operator new(size_t sz)
	{
		//cout<<"Overloaded new for class sllnode";
		void *p;
		if(sllnode::avail==NULL)  // empty avail list 
		{
			//cout<<"(allocates node from heap)"<<endl;
			p=::operator new(sz);
		}
		else
		{   // get the 1st node from avail list
			//cout<<"(gets node from avail)"<<endl;
			p=avail;
			sllnode::avail=sllnode::avail->next;
		}
		return p;

	}

	// overloading delete operator 
	void operator delete(void *p)
	{
		//cout<<"Overloaded delete for class sllnode"<<endl;
		// adding the deleted node to the begining of avail
		sllnode *t=(sllnode*)p;
		t->next=sllnode::avail;  t->val=0;
		sllnode::avail=t;
		return;

	}


}; // End of sllnode class definition

sllnode  * sllnode::avail=NULL;  // initialzing static member