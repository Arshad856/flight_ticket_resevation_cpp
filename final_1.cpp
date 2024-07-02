#include <iostream>
#include <fstream>
#include<sstream>
#include<string>
#include <iomanip>
#include <vector>

using namespace std;

//function for add new customer into customers.txt
void add_new_customer(){//defining function
    //assigning required variables
    int fileID = 0;
	string userName, fileName;
    int c;


    while(userName!="N" || userName!="n"){//starting while loop for customer name input by user

	cout << "Enter your name please: ";
	cin >> userName;//get new customer name from user
    if (userName=="N" || userName=="n"){//check if the user enter "n" or "N" to exit from this function
        break;//break the while loop if user enter "N" or "n"
    }

	ifstream fileInput;//assigning variable for reading the customers.txt file
	fileInput.open("customers.txt");//open customers.txt file in read mode
    while (fileInput >> fileID)//while loop for searching file if the customer_name which user entered already exists
	{
		getline(fileInput, fileName);//read the file line by line
		if (userName == fileName.erase(0, 1))//check if the customer id already exists
		{
            c=0;//assign 0 value to variable c for clearify the user input already exists
			cout << "This name " << userName << " is already exist in the text file.\n";//print "already exists" error when the customer id exists
            break;//break the searching while loop when the condition gone True
		}
        else{
            c=1;//assign 1 value to variable c for clearify the user input already not exixts
        }
	}

	fileInput.close();//close the opened customers.txt file

    if (c==0)//check if the customer name already exists or not
    {
        continue;//if exists(customer name) re start the loop
    }
	if (fileID == 0){//check if the username is the first customer deatil input into customers.txt file
		fileID = 1001;//if the first input to file assign 1001 as the first customer Id of file
    }
	else{
		fileID += 1;//if not the first input of file assign the next number to last customer id as customer id for this iteration
    }
	ofstream fileOutput;//assign variable for output file customers.txt
	fileOutput.open("customers.txt", ios :: app);//open customers.txt file in appending mode

    //print the output data which is written into customers.txt file on the console
	cout << "Customer ID:\t" << fileID << endl;
	cout << "Customer Name:\t" << userName << endl;
	cout << "Customer has been added to the text file.\n";//print the confirmation of the user input written to file successfully

	fileOutput << fileID << " " << userName << endl;//write the data into customers.txt file
    }
}
//function for add new flight
void add_new_flight(){//defining function

    //assigning required variables
    int fileID = 0;
	string DestName, DestName_File, fileName;
    int capacity, Adult_cost, Child_cost;
    int c;

    while(DestName!="N" || DestName!="n"){//starting while loop for destination name,capcity,adult cost and child cost input by user

	cout << "Enter your Destination name please: ";
	cin >> DestName;//get destination input from user
    if (DestName=="N" || DestName=="n"){//check if the user input "N" or "n" for Destination input to break the while loop
        break;//break the while loop if user inputs "n" or "N"
    }
    cout << "Enter Capacity of Flight: ";
    cin >> capacity;//get capacity of flight input from user
    cout << "Enter Adult Cost: ";
    cin >> Adult_cost;//get adult cost input from user
    cout << "Enter Child Cost: ";
    cin >> Child_cost;//get child cost input from user


	ifstream fileInput;//assigning variable for open flights.txt file
	fileInput.open("flights.txt");//open flights.txt file in read mode

	while (fileInput >> fileID >> DestName_File)//while loop for searching file if the destination which user entered already exists
	{

		getline(fileInput, fileName);//read the flights.txt file line by line
		if (DestName == DestName_File)//check the destination which user inputs already exists
		{
            c=0;//assign 0 value to variable c for clearify the Destination already exists
			cout << "This Dest.name " << DestName << " is already exist in the text file.\n";//print error when the Desination already exists
            break;//break the while loop if the destination which user inputs already exists
		}
        else{
            c=1;//assign 0 value to variable c for clearify the Destination already not exists
        }
	}

	fileInput.close();//close the opened flights.txt file

    if (c==0)//check if the customer name already exists or not
    {
        continue;//if exists(customer name) re start the loop
    }
	if (fileID == 0){//check if the username is the first customer deatil input into customers.txt file
		fileID = 1001;//if the above condition gone truth the flight Id will be 1001
    }
	else{
		fileID += 1;//if the above condition gone false the flight Id will be the next number to last flight id exists on the flights.txt
    }
	ofstream fileOutput;//assign variable for open output file
	fileOutput.open("flights.txt", ios :: app);// open flights.txt file in appending file

    //display the user input on the terminal
	cout << "Flight ID:\t" << fileID << endl;
	cout << "Destination Name:\t" << DestName << endl;
    cout << "Capacity Of Flight is:\t" << capacity << endl;
    cout << "Adult cost of Flight is:\t" << Adult_cost << endl;
    cout << "Child cost of Flight is:\t" << Child_cost << endl;
	cout << "Flight has been added to the text file.\n";

    //write the output on flights.txt file
	fileOutput << fileID << " " << DestName << " " << capacity << " " << Adult_cost << " " << Child_cost << endl;
    }
}
//function for add new reservation
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

//defining function for edit existing reservation

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

//defining function for delete existing reservation

void delete_existing_reservation()
{
    //assigning variables needed for this function
    int fileID = 0;
	string file_reservation;
    string  ReservationID, ReservationID_file, CustomerId_file, flight_id_file, Adult_file, Child_file, Cost_file;
    int c;
    int c1=0;
    
    //while loop for running file until user input "n" or "N"
    while(ReservationID=="N" || ReservationID!="n")
    {
    
    //opening required file to get data for delete new reservations
    ifstream fileInput;
    fileInput.open("reservations.txt");

	cout << "Enter your Reservation ID to Delete existing Reservation: ";
	cin >> ReservationID;//get user input for reservation Id to delete reservation
    if (ReservationID=="N" || ReservationID=="n"){//check the user input is equal to "n" or "N"
        break;//Break if condition gone True
    }
    c=0;
    while (fileInput >> ReservationID_file )//while loop to read reservations.txt file for check is reservation id which is user input exists on the file
	{

		getline(fileInput, file_reservation);//read the file line by line
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
    fileInput.close();//close opened file
    fileInput.open("reservations.txt");//reopen the reservations.txt file

    
    ofstream fileOutput;//assign variable for out put file
	fileOutput.open("reservations_Duplicate.txt");//open afile on writing mode for re write the reservations.txt

    while (fileInput >> ReservationID_file >>CustomerId_file >> flight_id_file >> Adult_file >> Child_file >> Cost_file)//while loop to write data on reservation duplicate file
	{

		getline(fileInput, file_reservation);//read the file line by line

        if (ReservationID==ReservationID_file){//check if the reservation id of this data is to be deleted or not
           continue;//if the condition gone True the while loop will be continued
        }
        else{
            fileOutput << ReservationID_file << " " << CustomerId_file << " " << flight_id_file << " " << Adult_file << " " << Child_file << " " << Cost_file << endl;//write data on reservation duplicate file when condition gone false
        }
      
    }

  //close opened files
  fileInput.close();
  fileOutput.close();
  remove("reservations.txt");//delete outdated reservations.txt file
  rename("reservations_Duplicate.txt", "reservations.txt");//rename reservations_duplicate.txt file to reservations.txt


	

	cout << "Reservation No. :  " << ReservationID << " records removed Successfully" << endl;//print confirmation to deleted record
    }
    }

// defining function for generate reports

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

int main(){
    int selection=0;
    int c=1;
    while (true)
    {
        if (c==0){
            cout << "THANK YOU FOR USING THE PROGRAM" << endl;
            break;
        }
    // print the main menu
    cout << "1. ADD NEW CUSTOMER.\n2. ADD NEW FLIGHT.\n3. ADD NEW RESERVATION.\n4. EDIT EXISTING RESERVATION.\n5. DELETE EXISTING RESERVATION.\n6. PRODUCE REPORT.\n7. EXIT.\nPlease Select your Function by respective number of function:\n";
    cin >> selection;//get user input for selecting which function
        //check user input
        if (selection==1){
            add_new_customer();
        }
        if (selection==2){
            add_new_flight();
        }
        if (selection==3){
            add_new_reservation();
        }
        if (selection==4){
            edit_existing_reservation();
        }
        if (selection==5){
            delete_existing_reservation();
        }
        if (selection==6){
            generate_report();
        }
        if (selection==7)
        {
            string opinion;
            cout << "Do you wish to Exit from Main Menu: ";
            cin >> opinion;//get user opinion about exit from program
            if (opinion=="Y" || opinion=="y")
            {
                c=0;
            }

        }
    }
    return 0;
}