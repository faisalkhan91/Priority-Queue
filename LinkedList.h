#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

template<class ItemType>
struct ListType
{
	ItemType linfo;
	struct ListType *link;
};

template<class ItemType>
class LinkedList
{
    private:
        ListType<ItemType> *front;
    public:
        LinkedList()
        {
            front = NULL;
        }

        void InsertNode(ItemType item);
        void RemoveNode();
        void PrintList();
        void MakeEmptyList()
        {
            front=NULL;
        }
};

//Insert element into the  list
template<class ItemType>
void LinkedList<ItemType>::InsertNode(ItemType item)
        {
            ListType<ItemType> *Point,*lqueue;
            Point = new ListType<ItemType>;
            Point->linfo = item;
            if (front == NULL || item > front->linfo)
            {
                Point->link = front;
                front = Point;
            }
            else
            {
                lqueue = front;
                while (lqueue->link != NULL && lqueue->link->linfo >= item)
                    lqueue = lqueue->link;
                Point->link = lqueue->link;
                lqueue->link = Point;
            }
        }

//deleting element from list with highest priority
template<class ItemType>
void LinkedList<ItemType>::RemoveNode()
        {
            ListType<ItemType> *Point;
            if(front == NULL)
                cout << "Queue Underflow occurred!\n";
            else
            {
                Point = front;
                cout << "Removed: " << Point->linfo << endl;
                front = front->link;
                free(Point);
            }
        }

//displaying of list elements
template<class ItemType>
void LinkedList<ItemType>::PrintList()
        {
            ListType<ItemType> *ptr;
            ptr = front;
            if (front == NULL)
                cout << "Queue is empty!\n" << endl;
            else
            {	cout << "List elements are: \n";
                cout << "Info  \n";
                while(ptr != NULL)
                {
                    cout << ptr->linfo << endl;
                    ptr = ptr->link;
                }
            }
        }

#endif // LINKEDLIST_H_INCLUDED
