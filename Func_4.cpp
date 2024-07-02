#include<iostream>
#include<fstream>
#include<string>
#include <iostream>
#include <iomanip>
using namespace std;
void edit_existing_reservation()
{
    //assigning required variables for this program
    int fileID = 0;
	string DestName, customerName, file_customer, file_flight, file_reservation;
    int flight_id_file;
    string CustomerId_file, customer_id_file_cust, customer_id_file_res;
    int Capacity, Adult_cost, Child_cost, FlightId, Adult, Child, Adult_file, Child_file, Cost_file;
    string  ReservationID, ReservationID_file;
    int Total_Adult_Cost=0;
    int Total_Child_Cost=0;
    int Total=0;
    int c;
    int c1=0;
    
    //while loop for running file until user input "n" or "N"
    while(ReservationID!="N" || ReservationID!="n")
    {
    
    //opening required files to get data for edit new reservations
    ifstream fileInput0, fileInput1, fileInput2;
    fileInput0.open("customers.txt");
	fileInput1.open("flights.txt");
    fileInput2.open("reservations.txt");

	cout << "Enter your Reservation ID to edit existing Reservation: ";
	cin >> ReservationID;//get reservations id user input
    if (ReservationID=="N" || ReservationID=="n"){//check the user input is equal to "n" or "N"
        break;//Break if condition gone True
    }
    c=0;
    while (fileInput2 >> ReservationID_file >> customer_id_file_res )//while loop to read reservations.txt file for check is reservation id which is user input exists on the file
	{

		getline(fileInput2, file_customer);//read the file line by line
		if (ReservationID == ReservationID_file)//check is reservation id which is user input exists on the file
		{
            c=1;
            break;//if customer id exists on the file break the reading while loop
		}
	}

    if (c==0){
        cout << "This Reservation Id " << ReservationID << " doesn't exist.\n";//print error if the reservation id doesn't exists
        continue;//if reservation id doesn't exist on the file restart the while loop
    }
    fileInput2.close();//close opened file
    fileInput2.open("reservations.txt");//open reservations.txt file
    while (fileInput0 >> customer_id_file_cust >> customerName){//while loop find the customer name of specific reservation
        getline(fileInput0, file_customer);//read the file line by line
        if (customer_id_file_cust==customer_id_file_res){//check if the customer id of reservation equal to customer id exist on the customers.txt
            break;
        }
    }
    cout << "Enter Flight No to Update: ";
    cin >> FlightId;//get user input for flight id to update
    c1=0;
    while (fileInput1 >> flight_id_file >> DestName >> Capacity >> Adult_cost >> Child_cost ){//while loop for check if the flight id exists on the flights.txt
        getline(fileInput1, file_flight);//read the file line bu line
        if (FlightId == flight_id_file)//check if the flight id exist on the file
        {
            c1=1;
            break;//if exists on the break the reading while loop
        }
    }
    if (c1==0){
        cout << "This Flight Id " << FlightId << " doesn't exist.\n";//print the error if the flight id which user input doesn't exists on the flights.txt
        continue;//restart the while loop if the flight id doesn't exists
    }

    cout << "Enter Child Number: ";
    cin >> Child;//get child number user input
    cout << "Enter Adult Number: ";
    cin >> Adult;//get adult number user input
    c=0;
    
    ofstream fileOutput;//assign variable for out put file
	fileOutput.open("reservations_Duplicate.txt");//open a file on writing mode for re write the reservations.txt

    //calculate the adult cost,Child cost and Total cost
    Total_Adult_Cost=Adult_cost*Adult;
    Total_Child_Cost=Child_cost*Child;
    Total=Total_Child_Cost+Total_Adult_Cost;

    int Total_Reserverd_Capacity=0;//assign variable for calculate Total Reserved Capacity of specific flight id which input by user

    
    while (fileInput2 >> ReservationID_file >> CustomerId_file >> flight_id_file >> Adult_file >> Child_file )//while loop for calculate Total Reserved Capacity of specific flight id which input by user
	{

		getline(fileInput2, file_reservation);//read the file line by line

        if (FlightId==flight_id_file)//check the flight id which entered by user is equal to the flight id on the file
        {
            if (ReservationID==ReservationID_file)//condition for checking reservationID whic user input equal to reservion id pn file
            {
                continue;//if equal restart the loop
            }
            //if condition gone True add the amount of Adult and Child on file to Total resrverd
            Total_Reserverd_Capacity+=Adult_file; 
            Total_Reserverd_Capacity+=Child_file;
        }
        
      
    }
    Total_Reserverd_Capacity=Total_Reserverd_Capacity+(Adult+Child);//add the user input Amount of Adult and child to Total reserved
    if (Total_Reserverd_Capacity>Capacity )//check if any seats available to reserve
    {
        Total_Reserverd_Capacity=Total_Reserverd_Capacity-(Adult+Child);
        cout << "There is only " << Capacity-Total_Reserverd_Capacity << " Seats left to reserve on Flight ID: " << FlightId << endl;//print error with available seats to reserve
        cout << "Please Try Again\n";
        continue;//restart the loop when unable to reserve
    }
    fileInput2.close();//close opened file
    fileInput2.open("reservations.txt");//open reservations.txt file to read data
    while (fileInput2 >> ReservationID_file >> CustomerId_file >> flight_id_file >> Adult_file >> Child_file >> Cost_file )//while loop to write data on reservation duplicate file
	{

		getline(fileInput2, file_reservation);

        if (ReservationID==ReservationID_file){
            fileOutput << ReservationID << " " << CustomerId_file << " " << FlightId << " " << Adult << " " << Child << " " << Total << endl;//write data on reservation duplicate file
        }
        else{
            fileOutput << ReservationID_file << " " << CustomerId_file << " " << flight_id_file << " " << Adult_file << " " << Child_file << " " << Cost_file << endl;//write edited data on reservation duplicate file
        }
      
    }

    //close opened files
    fileInput0.close();
    fileInput1.close();
    fileInput2.close();
    fileOutput.close();

    remove("reservations.txt");//delete outdated reservations.txt file
    rename("reservations_Duplicate.txt", "reservations.txt");//rename reservations_duplicate.txt file to reservations.txt

	//print the edited data into console
    cout << "\nYOUR RESERVARION HAS EDITED SUCCESSFULLY WHICH RESERVATION ID: " << ReservationID << endl;
    cout << "Edited Information Below Here" << endl;
	cout << "Reservation No. :  " << ReservationID << endl;
    cout << "=======================" << endl;
    cout << endl;
    cout << "Customer ID. : " << customer_id_file_res << endl;
    cout << "Customer Name.: " << customerName << endl;
    cout << endl;
    cout << "Flight No:  " << FlightId << endl;
    cout << endl;
	cout.width(13);
    cout << left << "Dest.Name:" ;
    cout.width(8);
    cout << left << "Adult"; 
    cout.width(8);
    cout << left << "Child"; 
    cout.width(8);
    cout << left << "Cost" << endl;
    cout.width(13);
    cout << left << "----------" ;
    cout.width(8);
    cout << left << "------"; 
    cout.width(8);
    cout << left << "------"; 
    cout.width(8);
    cout << left << "-----"<< endl;
    cout.width(13);
    cout << left << DestName; 
    cout.width(8);
    cout << left << Adult ;
    cout.width(8);
    cout << left <<  Child; 
    cout.width(4);
    cout << left << Total << " Q.R" <<  endl;
    
    }
    }

int main()
{
	edit_existing_reservation();
	return 0;
}
