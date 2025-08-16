#include <iostream>
using namespace std;

class Train
{
private:
    int train_No;
    string train_Name;
    string source;
    string destination;
    string train_Time;
    static int train_Count;

public:
    Train()
    {
        train_No = 0;
        train_Count++;
    }
    ~Train()
    {
        train_Count--;
    }

    void input_TrainDetails()
    {
        cout << "Enter Train Details : " << endl;
        cout << "Enter Train Number : " << endl;
        cin >> train_No;
        cin.ignore();
        cout << "Enter Train Name : " << endl;
        getline(cin, train_Name);
        cout << "Enter Source: ";
        getline(cin, source);
        cout << "Enter Destination: ";
        getline(cin, destination);
        cout << "Enter Train Time: ";
        getline(cin, train_Time);
    }
    void display_TrainDetails()
    {
        cout << "Enter Train Number : " << train_No << endl;
        cout << "Enter Train Name : " << train_Name << endl;
        cout << "Enter Source : " << source << endl;
        cout << "Enter destination : " << destination << endl;
        cout << "Enter Train Time : " << train_Time << endl;
        train_Count++;
    }
    int get_TrainNumber()
    {
        return train_No;
    }
};
int Train::train_Count = 0;

class RailwayStation
{
private:
    Train t[100];
    int total_train = 0;

public:
    void add_train()
    {
        t[total_train].input_TrainDetails();
        total_train++;
    }
    void displayAllTrains()
    {
        for (int i = 0; i < total_train; i++)
        {
            t[i].display_TrainDetails();
        }
    }
    void searchTrain(int num)
    {
        for (int i = 0; i < total_train; i++)
        {
            if (t[i].get_TrainNumber() == num)
            {
                t[i].display_TrainDetails();
            }
            else
            {
                cout<<"Train Not Found!!"<<endl;
            }
            
        }
    }
};
int main()
{
    RailwayStation rs1;
    int num,choice,n;
    
    do
    {
        cout<<"---------- Railway Station System ----------------- "<<endl;
        cout<<"1 : Add train "<<endl;
        cout<<"2 : Dispaly All train "<<endl;
        cout<<"3 : Search train "<<endl;
        cout<<"4 : Exit "<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            rs1.add_train();
            break;
        case 2:
            rs1.displayAllTrains();
            break;
        case 3:
            cout<<"Enter Train Number : ";
            cin>>num;
            rs1.searchTrain(num);
            break;
        case 4:
            cout<<"You are Exit!!";
            break;
        default:
            cout<<"Invalid Choice";
            break;
        }
    }while (choice!=4);
    

    return 0;
}