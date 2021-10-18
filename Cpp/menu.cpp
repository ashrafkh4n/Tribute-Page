#include <stdio.h>
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;
class array
{
private:
    int *A;
    int size , length;
public:
    array();
    array(int length , int size);
    ~array();
    void display();
    void insert(int index , int x);
    int Delete(int index);
    int get(int index);
    int set(int index , int x);
    int max();
    int min();
    void swap(int *x , int * y);
    void reverse();
    string sorted();
    int binarysearch(int key);
    int linearsearch(int key);
    void inputarr();
    array merge(array& B);
};

array::array()
{
    int size = 10;
    int length = 0 ;
    A = new int[size];
}
array::array(int length , int size)
{

    this->length= length ;
    this->size = size ;
    A = new int[size];

}

array::~array()
{
    delete []A;
    cout<<"\n Array is destroyed ";
}
void array::insert(int index , int x)
{
    if(index>=0 && index <=length)
    {
        for (int i = 0; i >index ; i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;
    }
}
int array ::Delete(int index)
{
    int x=0;
    if(index>=0 && index <=length)
    {
        x=A[index];
        for(int i=index ; i<length-1 ; i++)
        A[i] = A[i+1];
        length--;
    }
    return x;
}
int array ::linearsearch(int key)
{
    for(int i=0 ; i<length ; i++)
    {
        if(key==A[i])
        return i;
    }
    return -1 ;
}
int array::binarysearch(int key)
{
    int l,mid, h;
    l=0;
    h=length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==A[mid])
        return mid;
        else if (key<A[mid])
        h=mid-1 ;
        else l=mid+1;
    }
    return -1;
}
int array ::get(int index)
{
    if(index>=0 && index <=length)
    return A[index];
}
int array::set(int index , int x)
{
    if(index>=0 && index <=length)
    A[index]=x;
}
int array::max()
{
    int max=A[0];
    for(int i =0 ; i<length ; i++)
    {
        if(A[i]>max)
        max=A[i];
    }
    return max;
}
int array::min()
{
    int min=A[0];
    for(int i =0 ; i<length ; i++)
    {
        if(A[i]<min)
        min=A[i];
    }
    return min;
}
void array::display()
{   cout<<endl<<"Elements of the array are  "<<endl;
    for(int i =0 ; i<length ; i++)
    cout<<A[i]<<" ";
}
void array::swap(int *x , int * y)
{
    int temp = *x;
    *x=*y;
    *y=temp;
}
string array::sorted()
{
    for(int i = 0 ; i<length ;i++)
    {
        if ( A[i]>A[i+1])
        return "It is not sorted ";
    }
    return "It is sorted ";
}
void array ::reverse() {
    int j,i;
    for(i=0 , j= length-1 ; i<j ; i++ , j--)
    swap(&A[i] , &A[j]);
}
void array::inputarr(){
    for(int i=0 ; i<length ; i++)
    cin>>A[i];
}
array array::merge(array& B){
    array C(length + B.length , length + B.length);
    int i=0 , j=0 , k=0;

    while(i<length && j<B.length)
    {
        if(A[i] < B.get(j) )
            C.set(k++ , A[i++]);
        else
             C.set(k++ , B.get(k++));

    }
    for (; i < length; i++){
            C.set(k++, A[i]);
        }
        for (; j < B.length; j++){
            C.set(k++, B.get(j));
        }
        return C;
}

int main(){
    int a , b , choice;
    cout<<"Enter length & size of array"<<endl;
    cin>>a>>b;
    array X(a,b);
    cout<<"Enter elements "<<endl;
        X.inputarr();
    while (1)
    {
    cout<<"\n1. Get";
    cout<<"\n2. Set";
    cout<<"\n3. Insert";
    cout<<"\n4. Delete";
    cout<<"\n5. Display";
    cout<<"\n6. Max";
    cout<<"\n7. Min";
    cout<<"\n8. Is sorted or not ?";
    cout<<"\n9. Reverse";
    cout<<"\n10. Linear Search";
    cout<<"\n11. Binary Search(Remember your array must be sorted)";
    cout<<"\n12. Merge";
    cout<<"\n13. Exit"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter the index ";
        int x,y;
        cin>>x;
        cout<<"\nThe element at index "<<x<<" is "<<X.get(x);
        break;
    case 2:
        cout<<"Enter the index & element";
        int x1,y1;
        cin>>x1>>y1;
        X.set(x1,y1);
        break;
    case 3:
        cout<<"Enter the index & element";
        int x2,y2;
        cin>>x2>>y2;
        X.insert(x2,y2);
        break;
    case 4:
        cout<<"Enter the index ";
        int x3;
        cin>>x3;
        cout<<X.Delete(x3)<<" is deleted from the array ";
        break;
    case 5:
        X.display();
        break;
    case 6:
        cout<<"The max element is "<<X.max();
        break;
    case 7:
        cout<<"The min element is "<<X.min();
        break;
    case 8:
        cout<<X.sorted();
        break;
    case 9:
        X.reverse();
        cout<<"Array is reversed now";
        break;
    case 10:
        int key1;
        cout<<"Enter key ";
        cin>>key1;
        cout<<endl;
        if(X.linearsearch(key1)== -1)
        cout<<"The key is not found"<<endl;
        else cout<<"The key is found successfully at "<<X.linearsearch(key1)<<endl;
        break;
    case 11:
        int key2;
        cout<<"Enter key ";
        cin>>key2;
        cout<<endl;
        if(X.binarysearch(key2)==-1)
        cout<<"The key is not found "<<endl;
        else cout<<"The key is found successfully at "<<X.binarysearch(key2)<<endl;
        break;
    case 12:
        { int a1 , b1 ;
        cout<<"Enter length & size of second array"<<endl;
        cin>>a1>>b1;
        array Y(a1,b1);
        cout<<"Enter elements in sorted order "<<endl;
        Y.inputarr();
        Y.display();
        array Z = X.merge(Y);
        cout<<"The merged array is :"<<endl;
        Z.display();
        break;}
    case 13:
        exit(0);

    default:
        cout<<"invalid choice";
        break;
    }
    }
    return 0 ;

}
