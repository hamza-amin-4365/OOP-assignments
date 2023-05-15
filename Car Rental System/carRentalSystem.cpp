#include<iostream>
#include<iomanip>
using namespace std;
class Car{
    protected:
    string car_model;
    int car_year;
    int no_of_seats;
    public:
    // SETTERS
    void setModel(string car_model){
        this->car_model = car_model;
    }
    void setYear(int car_year){
        this->car_year = car_year;
    }
     void setSeats(int no_of_seats){
        this->no_of_seats = no_of_seats;
    }
    // GETTERS
    string getModel(){
        return car_model;
    }
    int getYear(){
        return car_year;
    }
    int getSeats(){
        return no_of_seats;
    }
    virtual void car_info(){
        cout<<"CAR INFORMATION"<<endl;
        cout<<"Model :"<<car_model<<endl;
        cout<<"Year  :"<<car_year<<endl;
        cout<<"Seats :"<<no_of_seats<<endl;
    }
    virtual void car_rent(int no_of_hours) = 0;
};
class Compact_car : public Car{
    public:
    void car_rent(int no_of_hours){
        int rent = 600 * no_of_hours;
        cout<<endl;
        cout<<"------Rent------"<<endl;
        cout<<rent<<" Rs"<<endl;
        cout<<"----------------"<<endl;
    }
};
class Luxury_car : public Car{
    public:
    void car_rent(int no_of_hours){
        int rent = 1000 * no_of_hours;
        cout<<endl;
        cout<<"------Rent------"<<endl;
        cout<<rent<<" Rs"<<endl;
        cout<<"----------------"<<endl;
    }
};
int main(){
    Car* rented_cars[5];
system("CLS");
char c;
do{
cout<<"Select 1 - 5 from the folowing rental options :"<<endl;
cout << setfill('-') << setw(48) << "" << setfill(' ') << endl;cout << left << setw(4) << "#"
     << left << setw(12) << "Model"
     << left << setw(8) << "Year"
     << left << setw(16) << "No. of seats"
     << left << setw(12) << "Category" << endl;
cout << setfill('-') << setw(48) << "" << setfill(' ') << endl;
cout << left << setw(4) << "1" 
         << left << setw(12) << "Alto" 
         << left << setw(8) << "2018"
         << left << setw(16) << "   4"
         << left << setw(12) << "Compact" << endl;
    cout << left << setw(4) << "2" 
         << left << setw(12) << "Cultus" 
         << left << setw(8) << "2018"
         << left << setw(16) << "   4"
         << left << setw(12) << "Compact" << endl;
    cout << left << setw(4) << "3" 
         << left << setw(12) << "Saga" 
         << left << setw(8) << "2020"
         << left << setw(16) << "   5"
         << left << setw(12) << "Compact" << endl;
    cout << left << setw(4) << "4" 
         << left << setw(12) << "BMW_Z4" 
         << left << setw(8) << "2005"
         << left << setw(16) << "   2"
         << left << setw(12) << "Luxury" << endl;
    cout << left << setw(4) << "5" 
         << left << setw(12) << "Carnival" 
         << left << setw(8) << "2017"
         << left << setw(16) << "   7"
         << left << setw(12) << "Luxury" << endl;
cout << setfill('-') << setw(48) << "" << setfill(' ') << endl;
cout<<"The Compact car will be charged 600 pkr per hour.\n";
cout<<"The Luxury car will be charged 1000 pkr per hour.\n";
cout << setfill('-') << setw(48) << "" << setfill(' ') << endl;
int choice;
cout<<"Enter number as per your choice :";
cin>>choice;
switch (choice)
{
case 1: {
    Compact_car alto;
    alto.setModel("Alto");
    alto.setYear(2018);
    alto.setSeats(4);
    rented_cars[0] = &alto;
    rented_cars[0]->car_info();
    int hours;
    cout<<endl;
    cout<<"Enter number of hours for rent :";
    cin>>hours;
    rented_cars[0]->car_rent(hours);
    break;
}
case 2: {
    Compact_car cultus;
    cultus.setModel("Cultus");
    cultus.setYear(2018);
    cultus.setSeats(4);
    rented_cars[1] = &cultus;
    rented_cars[1]->car_info();
    int hours;
    cout<<endl;
    cout<<"Enter number of hours for rent :";
    cin>>hours;
    rented_cars[1]->car_rent(hours);
    break;
}
case 3: {
    Compact_car saga;
    saga.setModel("Saga");
    saga.setYear(2020);
    saga.setSeats(5);
    rented_cars[2] = &saga;
    rented_cars[2]->car_info();
    int hours;
    cout<<endl;
    cout<<"Enter number of hours for rent :";
    cin>>hours;
    rented_cars[2]->car_rent(hours);
    break;
}
case 4: {
    Luxury_car bmw;
    bmw.setModel("BMW_Z4");
    bmw.setYear(2005);
    bmw.setSeats(2);
    rented_cars[3] = &bmw;
    rented_cars[3]->car_info();
    int hours;
    cout<<endl;
    cout<<"Enter number of hours for rent :";
    cin>>hours;
    rented_cars[3]->car_rent(hours);
    break;
}
case 5: {
    Luxury_car grand;
    grand.setModel("Carnival");
    grand.setYear(2017);
    grand.setSeats(7);
    rented_cars[4] = &grand;
    rented_cars[4]->car_info();
    int hours;
    cout<<endl;
    cout<<"Enter number of hours for rent :";
    cin>>hours;
    rented_cars[4]->car_rent(hours);
    break;
        }
default:{
    cout << "Invalid choice. Please try again.\n";
    break;
        }
    }
cout<<"Do you want to book another car (y/n)";
cin>>c;
}while(c=='y'|| c=='Y');
cout<<endl;
cout<<"Thank you for booking!"<<endl;
cout << setfill('-') << setw(48) <<""<< setfill(' ');
return 0;
}