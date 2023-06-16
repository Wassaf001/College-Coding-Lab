#include <bits/stdc++.h>
using namespace std;

class Node // Creation of class node
{
 public:
    int data; // data of node
    Node* next; // pointer to next node

  Node(int d) // constructor for node 
  {
    this -> data = d;
    this -> next = NULL;
  }
};

void print_list(Node* n)  // print function to print the list
{
 cout << "Your List is: ";
 while(n!=NULL)
 {
    cout << n->data << " -> ";
    n = n -> next;
 }
 cout << "NULL";
}

void insertion_at_head(Node* &head, int head_element) // function to add element at the head
{
  Node* temp = new Node(head_element);
  temp -> next = head;
  head = temp;
}

void insertion_in_middle(Node* &head, int mid_element) // function to add element at the middle somewhere
{
  Node* temp = new Node(mid_element);
  temp -> next = head;
  head = temp;
}

void insertion_at_tail(Node* &tail, int tail_element) // function to add element at the tail
{
   Node* temp = new Node(tail_element);
   tail -> next = temp;
   temp = tail;
} 

void deletion(Node* &del, int del_element) // function to delete element
{
  Node* temp = new Node(0);
  del -> next = temp;
  del = temp;
}

void countSort(Node* &head, int i) // count sort
{
    Node* count[10] = {NULL};
    Node* temp = head;
    while(temp!=NULL){
        int c = ((temp->data)/i)%10;
        if(count[c]== NULL)
        {
             count[c] = temp;
             temp = temp->next;
              (count[c])->next = NULL;
              continue;
        }
        Node* t = count[c];
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
        temp = temp->next;
        t->next->next = NULL;
    }
   
    Node* prev = NULL;
    int j;
    for( j=0; j<10; ++j)
    {
          if(prev != NULL) break;
          if(count[j])
          {
            head = count[j];
            prev = count[j];
            while(prev->next != NULL)
            {
                prev = prev->next;
            }
          }
    }
        
    for(; j<10; ++j)
    {
       temp = count[j];
       if(temp == NULL) continue;
       prev->next = temp;
       while(temp->next != NULL)
       {
           temp = temp->next;
       }
       prev = temp;
    }
}

void radix_sort(Node* &head) // radix sort
{
    Node* temp=head;
    int m = INT_MIN;
    while(temp!=NULL)
    {
        m = max(m, temp->data);
        temp = temp->next;
    }
    for(int i=1; (m/i)>0; i*=10)
    {
        countSort(head, i);
    }
}

int main()
{
    int size;
    int head_element;
    vector<int>array;
    int d;
    int a;
    cout << "Enter size of Linked List: ";
    cin >> size;
    cout << "Enter elements of linked list: ";
    for(int i=0; i<size; i++)
    {
      cin >> a;
      array.push_back(a);
    }
    cout << "Your linked list is: ";
    for(int j=0; j<size; j++)
    {
      cout << array[j] << " -> " ;
    }
    cout << "NULL";
    cout << endl;
    reverse(array.begin(), array.end());
    int choice;
    cout << "**************************************" << endl;
    cout << "1. Insertion at head in Linked List." << endl;
    cout << "2. Insertion at tail in Linked List." << endl;
    cout << "3. Insertion at middle in Linked List." << endl;
    cout << "4. Deletion in Linked List." << endl;
    cout << "5. Sorting of Linked List." << endl;
    cout << "**************************************" << endl;
    cout << endl;
    int o = 5;
    while(o>0)
    {
    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if(choice > 5)
    {
      cout << "Enter value less than 5." << endl;
      exit(0);
    }
    Node* node1 = new Node(array[0]);
    Node* head = node1;
    if(choice==1)
    {
      cout << "Enter the element you want to enter: ";
      cin >> d;
      for(int i=1; i<size; i++)
      {
       head_element = array[i];
       insertion_at_head(head, head_element);
      }
      insertion_at_head(head, d);
    }
    else if(choice==2)
    {
      cout << "Enter the element you want to enter: ";
      cin >> d;
      insertion_at_tail(head, d);
      for(int i=1; i<size; i++)
      {
       head_element = array[i];
       insertion_at_head(head, head_element);
      }
    }
    else if(choice==3)
    {
      int pos = 0;
      cout << "Enter the element you want to enter: ";
      cin >> d;
      cout << "Enter the position at which you want to enter: ";
      cin >> pos;
      if(pos>0 && pos<size)
      {
         if(size%2==0)
         {
         pos = size - pos + 1;
         }
         else
         { 
           if(pos==(size+1)/2)
           {
            pos = size - pos;
           }
           else
           {
            pos = size - pos;
           }
        }
      }
      if(pos==0)
      {
        pos = size;
      }
      if(pos<size && pos>0)
      {
        for(int i=1; i<pos; i++)
        {
        head_element = array[i];
        insertion_at_head(head, head_element);
        } 
        insertion_in_middle(head, d);
        for(int i=pos; i<size; i++)
        {
        head_element = array[i];
        insertion_at_head(head, head_element);
        }
      }
      else if(pos>=size)
      {
        insertion_at_tail(head, d);
      for(int i=1; i<size; i++)
      {
       head_element = array[i];
       insertion_at_head(head, head_element);
      }
      }
      else{
      for(int i=1; i<size; i++)
      {
       head_element = array[i];
       insertion_at_head(head, head_element);
      }
      insertion_at_head(head, d);
      }
    }
    else if(choice==4)
    {
      cout << "Enter the element that you want to delete: ";
      cin >> d;
      if(head->data == d){
        deletion(head, d);
        head = head -> next;
      }
      for(int i=1; i<size; i++)
      {
       head_element = array[i];
       if(head_element!=d){
       insertion_at_head(head, head_element);
       }
      } 
    }
    else if(choice==5)
    {
      for(int i=1; i<size; i++)
      {
       head_element = array[i];
       insertion_at_head(head, head_element);
      }
      print_list(head);
      cout << endl;
      radix_sort(head);
    }
    print_list(head);
    o--;
  }
return 0;
}
