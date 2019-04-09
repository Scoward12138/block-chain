#include "chain.h"
#include "chain_given.cpp"


// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain(){
cout<<"destructor called"<<endl; 
    clear();
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block & ndata){
    Node *c,*data;
    c = tail_ -> prev;
    data = new Node(ndata);
    c -> next = data;
    data -> next = tail_;
    data -> prev = c;
    tail_ -> prev = data;
    length_++;
}
/**
 * Modifies the Chain by moving a contiguous subset of len Nodes
 * dist nodes toward the end of the chain beginning from startPos
 * (maintaining the sentinel at the end). Their order is
 * not changed in the move. You may assume that the startPos and
 * len parameters are kind: startPos + len -1 <= length. If there
 * are not enough nodes to shift by dist, just shift as many as
 * possible.
 */
void Chain::moveBack(int startPos, int len, int dist){
	if(dist == 0){return ;}
//	if(length_==0){return ;}
cout<<"mb 43 ok"<<endl;
	Node *a,*b,*c,*d,*e,*f;
	a = head_;
	b = head_;
	c = NULL;
	d = NULL;
cout<<"mb 48 ok"<<endl;
	e = head_;
	f = NULL;
	int pt1 = startPos + len + dist - 1;
cout<<"mb 53 ok"<<head_->next<<endl;
	if(pt1 > length_){a = tail_->prev;
        } else{a = walk(a,pt1);}
cout<<"mb 56 ok"<<a<<endl;
	b = walk(b,startPos);
cout<<"mb 57 ok"<<endl;
	c = a-> next;
	d = b-> prev;
	int pt3 = startPos + len;
	e = walk(e,pt3);

cout<<"mb 70 ok"<<endl;
	f = e -> prev;
	d->next=e;
	e->prev=d;
	a->next=b;
	b->prev=a;
	f->next=c;
	c->prev=f;

cout<<"mb 73 ok"<<endl;
}
/**
 * Rolls the current Chain by k nodes: removes the last
 * k nodes from the Chain and attaches them, in order, at
 * the start of the chain (maintaining the sentinel at the front).
 */
void Chain::roll(int k){
    int todo;
    todo = k;
    Node *c, *a, *b;
    c = head_;
    a = NULL;
    b = NULL;
    while(todo != 0){
	a = head_ -> next;
	c = tail_ -> prev;
	b = c -> prev;
	head_ -> next = c;
	c -> prev = head_;
	c -> next = a;
	a -> prev = c;
	b -> next = tail_;
	tail_ -> prev = b;
	todo --;
	
}
}
/**
 * Modifies the current chain by reversing the subchain
 * between pos1 and pos2, inclusive. The positions are
 * 1-based. You may assume that pos1 and pos2 are valid
 * locations in the Chain, and that pos2 >= pos1.
 */
void Chain::reverseSub(int pos1, int pos2){

    Node *a , *b, *c,*d,*e,*f;

    int pt1 = pos1;

    int pt2 = pos2;
	a = NULL;
	b = NULL;	
	c = NULL;
	d = NULL;
	e = NULL;
	f = NULL;

    while(pt2 > pt1){
//cout<<"chain 116 ok"<<endl;
	a = walk(head_,pt1);
//cout<<"chain 118 ok"<< d -> next <<endl;
	d = walk(head_,pt2);
//cout<<"chain 120 ok"<<endl;
	if(pt2 > pt1 + 2){
	b = a -> prev;
	c = a -> next;
	e = d -> prev;
	f = d -> next;
//cout<<"chain 125 ok"<<endl;
	b -> next = d;
	d -> prev = b;
	a -> next = f;
	f -> prev = a;
	a -> prev = e;
	e -> next = a;
	c -> prev = d;
	d -> next = c;}
	else{
	b = a -> prev;
	f = d -> next;
//cout<<"chain 143 ok"<<endl;
	b -> next = d;
	d -> prev = b;
	d -> next = a;
	a -> prev = d;
	a -> next = f;
	f -> prev = a;
}
	pt1++;
	pt2--;
}
}

/*
* Modifies both the current and input chains by removing
* nodes from other, and interleaving them between the Nodes
* from the current Chain. The nodes from the other Chain
* should occupy the even locations in the result. length
* of the resulting chain should be the sums of the lengths
* of current and the other. The other chain should have only
* two sentinels and no data nodes at the end of the operation.
* the weave fails and the original
* chains should be unchanged if block sizes are different.
* in that case, the result of the function should be:
* cout << "Block sizes differ." << endl;
*/
void Chain::weave(Chain & other) { // leaves other empty.
//cout<<"line 170 ok; size:"<<size()<<";other size:"<<other.size()<<endl;
 
	if(height_ != other.height_ || width_ != other.width_){
	cout<<"Block sizes differ."<< endl;
	return ;
}
//	length_ = size() + other.size();
//cout<<"line 177 ok"<<endl;
//Node *a, *b, *c,*d;
 //   a = head_ -> next;
  //  c = a -> next;
   // b = other.head_ -> next;
   // d = b -> next;    
//cout<<"line 183 ok"<<endl;
    //while(c != tail_){
//	a -> next = b;
//	b -> prev = a;
//	b -> next = c;
//	c -> prev = b;
//	a = c;
//	c = a -> next;
//	b = d;
//	d = b-> next;
//} 
//	a -> next = b;
//	b -> prev = a;
//	b -> next = tail_;
//	tail_ -> prev = b;
//	other.tail_ -> prev = other.head_;
//	other.head_ -> next = other.tail_; 
	Node * a, *b;
	a = head_ -> next;
	b = other.head_ -> next;
	while(a != tail_ && b !=other.tail_){
	Node *insert = b;
	b = b -> next;
	insert -> next -> prev = insert->prev;
	insert -> prev -> next = insert -> next;
	a ->next->prev = insert;
	insert -> next = a ->next;
	a -> next = insert;
	insert -> prev = a;
	a = walk(a,2);
	length_++;
	other.length_--;
}
	if(b != other.tail_){
	a = tail_->prev;
	b -> prev = a;
	a -> next = b;
	tail_->prev = other.tail_->prev;
	other.tail_->prev->next = tail_;
	other.head_->next = other.tail_;
	other.tail_->prev = other.head_;
	length_ += other.length_;
	other.length_ = 0;

}

}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */

void Chain::clear() {
	Node *a;
	a = head_;
//cout<<"line 210 ok"<<endl;
    while(a != tail_){
//cout<<"line 212 ok"<<endl;
	head_ = head_->next;
//cout<<"line 214 ok"<<a<<"!!!"<<endl;
	delete a;
//cout<<"line 217 ok"<<endl;
	a = head_;
//cout<<"line 218 ok"<<endl;
//cout<<"line 221 ok"<<endl;
//cout<<"line 221 ok"<<endl;
	}

//cout<<"line 224 ok"<<endl;
}
/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */

void Chain::copy(Chain const& other) {
    Node *a = other.head_->next;
    head_ = new Node();
    tail_ = new Node();
    length_ = 0;
    width_ = other.width_;
    height_ = other.height_;
    head_ -> next = tail_;
    tail_ -> prev = head_;
//cout<<other.width_<<"!!!"<<other.height_<<endl;
//cout<<head_<<";;;"<<tail_<<endl;
//cout<<"224 ok"<<tail_<<endl;
//cout<<"!!!"<<other.head_<<endl;
    while(a != other.tail_){
//cout<<"226 ok"<< endl;
	insertBack(a->data);
//cout<<"228 ok;;;"<<a<<endl;
        a = a -> next;
}  
//cout<<size()<<";;;"<<other.size()<<endl;
}

