#include<iostream>
#include<fstream>
#include<string>
#include <iostream>
#include <iomanip>
using namespace std;
void delete_existing_reservation()
{
    //assigning variables needed for this project
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

	cout << "Enter your Reservation ID to edit existing Reservation: ";
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

int main()
{
	delete_existing_reservation();
	return 0;
}
