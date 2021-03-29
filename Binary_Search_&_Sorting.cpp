#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <chrono>
using namespace std;


class Node {
public:
    Node* next;
    Node() 
    {
        ID = 0;
        phone = 0;
        name = "";
        next = NULL;
    }
    int ID;
    int phone;
    string name;
};
class List
{
public:
    Node* head, * tail;



    List()
    {
        head = NULL;
        tail = NULL;
    }




    void add()
    {
        Node* x = new Node();

       // x->ID = gene();
        gene(x);
        int tm = rand() % 26;
        x->name = randomName(tm);
        x->phone = nmm();
        if (head == NULL)
        {
            head = x;
            tail = x;
        }
        else
        {
            tail->next = x;
            tail = tail->next;
        }
     
    }
    void print()
    {
        ofstream myfile("Unsorted.txt");
        Node* temp;
        temp = head;
        while (temp != NULL)
       {
            cout << temp->ID << " ";
            cout << temp->phone << " ";
            cout << temp->name << " ";
            cout << " \n";
            temp = temp->next;

        }
        temp = head;
        while (temp != NULL)
        {
            myfile << temp->ID << " " << temp->phone << " " << temp->name << " \n";
            temp = temp->next;
        }
        myfile.close();
    }



    string randomName(int length)
    {

        char consonents[] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z' };
        char vowels[] = { 'a','e','i','o','u','y' };

        string name = "";

        int random = rand() % 2;
        int count = 0;

        for (int i = 0; i < length; i++)
        {

            if (random < 2 && count < 2)
            {
                name = name + consonents[rand() % 19];
                count++;
            }
            else
            {
                name = name + vowels[rand() % 5];
                count = 0;
            }

            random = rand() % 2;

        }

        return name;

    }
    void gene(Node *x)
    {
        int z = rand() % 1000000;
        
        Node* temp;
        temp = head;
        while (temp != NULL)
        {
            if (z != temp->ID)
            { 
                temp = temp->next;
            }
            else if(x==NULL) {
                break;
            }
            else
            {
                temp = head;
                z = rand() % 1000000;
            }
         }
          x->ID = z;
          
          //  cout << x->ID << " ";
    }
       
    

    int nmm()
    {
        return (rand() % 1000000000);  
    }



    int find(int a)
    {
        int i = 0;
        
        Node* temp;
        temp = head;
        
        while (temp != NULL)
        {
            if (a == temp->ID)
            {
                cout  << "NUMBER : " << i <<" \n";
                return(0); 
            }
            temp = temp->next;
            i++;
        }
        cout << "Can't Find That Number!!! \n";
        return 0;
    }
    

    void srt()
    {
        Node* temp;
        temp = head;
        int  arr[10000], i = 0, tempr, j;
        while (temp != NULL)
        {
            arr[i] = temp->ID;
            temp = temp->next;
            i++;
        }


        for (i = 0; i < 10000; ++i)
        {
            for (j = i + 1; j < 10000; ++j)
            {
                if (arr[i] > arr[j])
                {
                    tempr = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tempr;
                }
            }
        }
       /*for (i = 0; i < 10000; ++i)
            cout << arr[i] << "\n "<<endl;*/

        ofstream myfile("Sorted.txt");
        temp = head;
        for (i = 0; i < 10000; ++i)
        {
            myfile << arr[i] << " " << temp->phone << " " << temp->name << " \n";
            temp = temp->next;
        }



    }
       
    void srt2(int x){

        Node* temp;
        temp = head;
        int  arr[10000], i = 0, tempr, j;
        while (temp != NULL)
        {
            arr[i] = temp->ID;
            temp = temp->next;
            i++;
        }


        

        typedef std::chrono::high_resolution_clock Time;
        typedef std::chrono::milliseconds ms;
        typedef std::chrono::duration<float> fsec;
        auto t0 = Time::now();

       int m = binarySearch(arr, 0, 9999, x);

       cout << " \n";
       cout << " \n";
       cout << " \n";
       cout << "Trying to find with Binary Search (Second and Milisecond) :";
       auto t1 = Time::now();
       fsec fs = t1 - t0;
       ms d = std::chrono::duration_cast<ms>(fs);
       std::cout << fs.count() << "s\n";
       std::cout << d.count() << "ms\n";


       
    }

    int binarySearch(int arr[], int l, int r, int x)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;

            
            if (arr[mid] == x)
                return mid;

             
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);

            
            return binarySearch(arr, mid + 1, r, x);
        }

        
        return -1;
    }

};



int main() 
{  
    srand((unsigned)time(NULL));



    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
    auto t0 = Time::now();

    int tut;
    List* k;
    k = new List();
    for (int i = 0; i < 10000; i++)
    {
        
        if (i == 9999)
        {
            k->add();
        }
        else
        k->add();
    }
    k->print();


    cout << " \n";
    cout << " \n";
    cout << " \n";
    cout << "Creating Time (Second and Milisecond) :";


    auto t1 = Time::now();
    fsec fs = t1 - t0;
    ms d = std::chrono::duration_cast<ms>(fs);
    std::cout << fs.count() << "s\n";
    std::cout << d.count() << "ms\n";


    system("pause");


    cout << " \n";
    cout << " \n";
    cout << " \n";

    cout << "Enter a number :";
    cin >> tut;



    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
    t0 = Time::now();


    

   


    cout << " \n";
    cout << " \n";
    cout << " \n";


    k->find(tut);
    
    cout << "Trying to find (Second and Milisecond) :";
    
    t1 = Time::now();
    fs = t1 - t0;
    d = std::chrono::duration_cast<ms>(fs);
    std::cout << fs.count() << "s\n";
    std::cout << d.count() << "ms\n";

    

    system("pause");



    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
    t0 = Time::now();

    


    cout << " \n";
    cout << " \n";
    cout << " \n";



    k->srt();
    cout << "Sorting Time (Second and Milisecond) :";

    t1 = Time::now();
    fs = t1 - t0;
    d = std::chrono::duration_cast<ms>(fs);
    std::cout << fs.count() << "s\n";
    std::cout << d.count() << "ms\n";


 

    system("pause");


    k->srt2(tut);
   


	return 0;
}