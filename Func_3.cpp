#include<iostream>
#include<fstream>
#include<string>
#include <iostream>
#include <iomanip>
using namespace std;
void add_new_reservation()
{
    //assigning required variables for this program
    int fileID = 0;
	string DestName, customerName, file_customer, file_flight, file_reservation, CustomerId, customer_id_file;
    int flight_id_file;
    int Capacity, Adult_cost, Child_cost, FlightId, Adult, Child;
    int Total_Adult_Cost=0;
    int Total_Child_Cost=0;
    int Total=0;
    string ReservationID_file, CustomerId_file; 
    int Adult_file, Child_file;
    int c;
    int c1=0;
    
    //starting while loop for running file until user input "n" or "N"
    while(CustomerId!="N" || CustomerId!="n")
    {
    
    //opening required files to get data for add new reservations
    ifstream fileInput0, fileInput1, fileInput2;
    fileInput0.open("customers.txt");
	fileInput1.open("flights.txt");
    fileInput2.open("reservations.txt");

	cout << "Enter your Customer ID please: ";
	cin >> CustomerId;//get customer id user input
    if (CustomerId=="N" || CustomerId=="n"){//check the user input is equal to "n" or "N"
        break;//Break if condition gone True
    }
    c=0;
    while (fileInput0 >> customer_id_file >> customerName)//while loop to read customers.txt file for check is customer id which is user input exists on the file
	{

		getline(fileInput0, file_customer);//read the file line by line
		if (CustomerId == customer_id_file)//check is customer id which is user input exists on the file
		{
            c=1;
            break;//if customer id exists on the file break the reading while loop
		}
	}
    if (c==0){
        cout << "This Customer Id " << CustomerId << " doesn't exist.\n";//print error if the customer id doesn't exists
        continue;//re start the loop if the customer id doesn't exists
    }
    cout << "Enter Flight No: ";
    cin >> FlightId;//get user input for flight id
    c1=0;
    while (fileInput1 >> flight_id_file >> DestName >> Capacity >> Adult_cost >> Child_cost ){//while loop to read flights.txt file for check is flight id which is user input exists on the file
        getline(fileInput1, file_flight);//read the file line by line
        if (FlightId == flight_id_file)//check is flight id which is user input exists on the file
        {
            c1=1;
            break;//if exists on the file break the file reading whhile loop
        }
    }
    if (c1==0){
        cout << "This Flight Id " << FlightId << " doesn't exist.\n";//print error if the flight id doesn't exists on the file
        continue;
    }

    cout << "Enter Child Number: ";
    cin >> Child;//get user input for number of child
    cout << "Enter Adult Number: ";
    cin >> Adult;//get user input for the number of adult
    c=0;
    
    

    while (fileInput2 >> fileID )//while loop for read reservations.txt to generate reservation id automatically
	{

		getline(fileInput2, file_reservation);
        if (file_reservation==" "){
            break;//break the while loop if the file ends
        }
    }

    //calculate the Adult cost, Child cost and Total cost for record reservations
    Total_Adult_Cost=Adult_cost*Adult;
    Total_Child_Cost=Child_cost*Child;
    Total=Total_Child_Cost+Total_Adult_Cost;

    
    //close the opened files
	fileInput0.close();
    fileInput1.close();
    fileInput2.close();
    
    //open reservations.txt file for read the data
    fileInput2.open("reservations.txt");

    int Total_Reserverd_Capacity=0;//assign variable for calculate Total Reserved Capacity of specific flight id which input by user

    
    while (fileInput2 >> ReservationID_file >> CustomerId_file >> flight_id_file >> Adult_file >> Child_file )//while loop for calculate Total Reserved Capacity of specific flight id which input by user
	{

		getline(fileInput2, file_reservation);//read the file line by line

        if (FlightId==flight_id_file)//check the flight id which entered by user is equal to the flight id on the file
        {
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
	if (fileID == 0){//check if the username is the first customer deatil input into customers.txt file
		fileID = 1001;//if the above condition gone truth the flight Id will be 1001
    }
	else{
		fileID += 1;//if the above condition gone false the flight Id will be the next number to last flight id exists on the flights.txt
    }
    fileInput2.close();
    ofstream fileOutput;//assign variable for open output file
	fileOutput.open("reservations.txt", ios :: app);// open reservations.txt file in appending file

    //print console output by user input data and calculated costs
	cout << "Reservation No. :  " << fileID << endl;
    cout << "=======================" << endl;
    cout << endl;
    cout << "Customer ID. : " << CustomerId << endl;
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
    
    //write the new reservation record into reservations.txt 
	fileOutput << fileID << " " << CustomerId << " " << FlightId << " " << Adult << " " << Child << " " << Total << endl;
    }
    }

int main()
{
	add_new_reservation();
	return 0;
}
