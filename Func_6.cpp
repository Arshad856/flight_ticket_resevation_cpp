#include<iostream>
#include<fstream>
#include<string>
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h> 
#include <vector>
using namespace std;
void generate_report()
{
    //assigning variables needed for this project
    string CustomerID, CustomerId_cust, customername, CustomerID_File;
    int fileID = 0;
	string file_customer, file_flight, file_reservation;
    string flightID_flight, DestName, flightID_file;
    string ReservationID, ReservationID_file, Adult, Child;
    int Cost;
    double Total_Cost=0.00 ;
    int c;
    int c1=0;
    
    //while loop for running file until user input "n" or "N"
     while(CustomerID!="N" || CustomerID!="n")
    {

    //assigning vectors for dynamic arrays
    vector<string> FlightID_Vec, ReservationID_Vec, customerName_Vec, DestName_vec, adult_vec, child_vec;
    vector<int> cost_vec; 

    //opening required file to get data for delete new reservations
    ifstream fileInput0, fileInput1, fileInput2;
    fileInput0.open("customers.txt");
	fileInput1.open("flights.txt");
    fileInput2.open("reservations.txt");

	cout << "Enter your Customer ID to Generate Invoice: ";
	cin >> CustomerID;//get user input for customer Id to generate report
    if (CustomerID=="N" || CustomerID=="n"){//check the user input is equal to "n" or "N"
        break;//Break if condition gone True
    }
    c=0;
    while (fileInput0 >> CustomerId_cust >> customername)//opening file for find the customer name for the user input customer ID
	{

		getline(fileInput0, file_customer);//read the file line by line
		if (CustomerID == CustomerId_cust)//check if the customer id which user input is equal to the customer id on file
		{
            c=1;
            break;//if the condition gone True break the file reading loop
		}
	}

    if (c==0){
        cout << "This Customer Id " << CustomerID << " doesn't exist.\n";//print error if the customer id which user input doesn't exist on the file
        continue;//if customer doesn't exist on the file restart the loop
    }

    c=0;
    while (fileInput2 >> ReservationID_file >> CustomerID_File >> flightID_file >> Adult >> Child >> Cost )//while loop for search reservation details for specific customer id
	{

		getline(fileInput2, file_reservation);//read the file line by line
		if (CustomerID == CustomerID_File)//check if the customer id on file is equal to the customer id which input ny the user
		{
            c=1;
            //collect reservation data of specific customer id
            ReservationID_Vec.push_back(ReservationID_file);
            FlightID_Vec.push_back(flightID_file);
            adult_vec.push_back(Adult);
            child_vec.push_back(Child);
            cost_vec.push_back(Cost);
		}
	}


    if (c==0){
        cout << "There is No Reservation reserved for " << CustomerID << " .\n";//print error if there is no reservations made on specific customer id
        continue;//restart the loop when there is no reservations found
    }
    //close the opened files
    fileInput0.close();
    fileInput2.close();
    fileInput1.close();
    fileInput0.open("customers.txt");
    fileInput1.open("flights.txt");

    //display terminal output for customer invoice headings
    cout << "Customer ID: \t" << CustomerID << endl ;
    cout << "Customer Name: \t" << customername << endl ;
    cout << "=============================" << endl ;
    cout << endl;
	cout.width(13);
    cout << left << "Reser.No.";
    cout.width(13);
    cout << left << "Flight.No";
    cout.width(13);
    cout << left << "Dest.Name:"; 
    cout.width(8);
    cout << left << "Adult" ;
    cout.width(8);
    cout << left << "Child" ;
    cout.width(8);
    cout << left << "Cost" << endl;
    cout.width(13);
    cout << left << "----------"; 
    cout.width(13);
    cout << left << "----------" ;
    cout.width(13);
    cout << left << "----------" ;
    cout.width(8);
    cout << left << "------"; 
    cout.width(8);
    cout << left << "------" ;
    cout.width(8);
    cout<< left << "-----"<< endl;
    
    //for loop for display all reservations made on specific customer id as  invoice
    for (int i = 0; i < ReservationID_Vec.size(); i++) 
        {
            cout.width(13);
            cout << left << ReservationID_Vec[i];
            cout.width(13);
            cout << left << FlightID_Vec[i];
            cout.width(13);
            fileInput1.close();
            fileInput1.open("flights.txt");
             while (fileInput1 >> flightID_flight >> DestName )
	            {
                getline(fileInput1, file_flight);
                if (FlightID_Vec[i]==flightID_flight)
                    {
                    break;
                    }
                }
            fileInput1.close();
            cout << left <<  DestName;
            cout.width(8);
            cout<< left << adult_vec[i];
            cout.width(8);
            cout << left << child_vec[i];
            cout.width(4);
            cout <<  left << cost_vec[i] << left << " Q.R" <<endl ;
        }
    
    //calculate the total of all reservations made by the specific custome
    Total_Cost=0.00;
    for (int i = 0; i < cost_vec.size(); i++) 
        {
            Total_Cost+=cost_vec[i];
        }

    //display the total of all reservations
    cout.width(55);
    cout << left << " ";
    cout.width(8);
    cout << left << "======" << endl;
    cout.width(39);
    cout << left << " ";
    cout.width(11);
    cout << left << "Total Cost      " ;
    cout << fixed;
    cout << setprecision(2);
    cout.width(6);
    cout << left << Total_Cost << " Q.R" << endl;

    

}
}
int main()
{

	generate_report();
	return 0;
}
