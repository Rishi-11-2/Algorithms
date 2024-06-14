#include<iostream>
#include "sllnodeWithoutAvail.h"
using namespace std;


//.......................................................
class  sll
{
    sllnode   *sllHead;  //  head pointer pointing to the sll nodes
    public:  int    nodeCnt;  // keep track of current node count

    sll(sllnode *p=NULL)
    {
    	cout<<"constructing sll "<<endl;
    	sllHead=p; nodeCnt=0;
    }
    ~sll()
    {
    	cout<<"destroying sll "<<endl;
    	//   deallocate/free one-by-one all nodes pointed by sllHead
    	while(sllHead!=NULL)
    	{
    		sllnode *temp=sllHead;  sllHead=sllHead->next;
    		//cout<<temp->val<<"  ";
    		delete  temp;
    	}
    	nodeCnt=0;

    }
    sll(const sll &x);  // copy constructor signature X(X&)
    

   // other method/ friend function prototypes

    friend int  operator+(int x, sll  &list); // 3 + a  => overloads binary +; implies add an interger at the begining of sll a; returns 1 if successful else -1
    friend int operator-(sll  &list); // - a  => overloads unary -; implies delete a node from the begining of sll a; returns the delted node info
    sll & operator=(const sll &list);  //  a = b =>  overloades the assignment operator; assigns ssl object b to a using deep copying
    int operator[](int x);     //  a[3] =>  overloades the array index operator; retives the info of the 3rd node (i.e. if nodeCnt >=3) 
    friend ostream & operator<<(ostream &x, const sll &list); // cout<<a => overloades the << operator; displays the object a

};  // End of sll class

//////Method definitions


 // copy constructor signature X(X&)
	sll::sll(const sll &rhs)  
    {  // code for deep copying......
		cout<<"constructing sllnode using copy constructor ";
    
    	// creating afresh a copy of the rhs linked list object as the new object
		nodeCnt=rhs.nodeCnt;  // copying node count member
		sllnode *rhstemp=rhs.sllHead;
		sllnode *lhstemp;
	
		for(int i=0;i<nodeCnt;i++)
		{
			if(rhstemp==rhs.sllHead)  // creating a copy of the 1st node
			{
				sllHead=new sllnode(rhstemp->val, NULL);  // assign created node address to new list head
				lhstemp=sllHead;
				rhstemp=rhstemp->next;
			}
			else
			{
				lhstemp->next=new sllnode(rhstemp->val, NULL);
				rhstemp=rhstemp->next;
				lhstemp=lhstemp->next;
			}
		}
	

    }	

// 3 + a  => overloads binary +; implies add an interger at the begining of sll a; returns 1 if successful else -1
int operator+(int x, sll  &list)
{
	cout<<"opeartor binary + overload "<<endl;
	list.sllHead=new sllnode(x, list.sllHead);  // new node points to the prev 1st and new created node becomes the 1st node pointed by sll head
	list.nodeCnt++;
	return 1;
}

// - a  => overloads unary -; implies delete a node from the begining of sll a; returns the delted node info
int operator-(sll  &list)
{
    cout<<"opeartor unary - overload "<<endl;
    sllnode  *temp=list.sllHead; 
    int  info=temp->val;
    list.sllHead=list.sllHead->next;
    list.nodeCnt--;
    delete temp;
    return info;
}

//  a[3] =>  overloades the array index operator; retives the info of the 3rd node (i.e. if nodeCnt >=3) 
int sll::operator[](int x)     
{
	cout<<"opeartor [] overload "<<endl;
	if((x>nodeCnt)&&(x<1))
		return -1;
	sllnode *temp=sllHead;
	for(int i=0; i<(x-1);i++)
          temp=temp->next;

    return temp->val;

}

 //  a = b =>  overloades the assignment operator; assigns ssl object b to a using deep copying
sll & sll::operator=(const sll &rhs) 
{
	cout<<"opeartor = overload "<<endl;
    //  deleting the lhs linked list object nodes 
    sllnode *lhstemp;
    while(sllHead!=NULL)
    	{
    		 lhstemp=sllHead;
    		 sllHead=sllHead->next;
    		//cout<<temp->val<<"  ";
    		delete  lhstemp;
    	}
    
    // creating afreash a copy of the rhs linked list object as lhs object
	nodeCnt=rhs.nodeCnt;  // copying node count member
	sllnode *rhstemp=rhs.sllHead;
	
	for(int i=0;i<nodeCnt;i++)
	{
		if(rhstemp==rhs.sllHead)  // creating a copy of the 1st node
			{
				sllHead=new sllnode(rhstemp->val, NULL);  // assign created node address to lhs list head
				lhstemp=sllHead;
				rhstemp=rhstemp->next;
			}
		else
			{
				lhstemp->next=new sllnode(rhstemp->val, NULL);
				rhstemp=rhstemp->next;
				lhstemp=lhstemp->next;
			}
	}
	return *this;  // return sthe reference of the lhs object
}

// cout<<a => overloades the << operator; displays the object a
ostream &operator<<(ostream &x, const sll  &list)
{
	sllnode   *temp=list.sllHead;
	x<<"displaying singly linear linked list: "<<endl;
	x<<"head ---";
	while(temp!=NULL)
	{
		cout<<">["<<temp->val<<", --]---";
		temp=temp->next;
	}
	cout<<"///"<<endl;

	return x;
}

//..........................................................
int main()
{
   sll  a,b;

   2+a;
   /*3+a;
   5+a;
   cout<<a<<endl;
   cout<<a[2]<<endl;
   b=a;
   cout<<b;
   -b;
   sll c(b);*/
   cout<<a;
   
   
   return 0;
}