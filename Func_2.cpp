#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void add_new_flight(){
    int fileID = 0;
	string DestName, DestName_File, fileName;
    int capacity, Adult_cost, Child_cost;
    int c;
    while(DestName!="N" || DestName!="n"){

	cout << "Enter your Destination name please: ";
	cin >> DestName;
    if (DestName=="N" || DestName=="n"){
        break;
    }
    cout << "Enter Capacity of Flight: ";
    cin >> capacity;
    cout << "Enter Adult Cost: ";
    cin >> Adult_cost;
    cout << "Enter Child Cost: ";
    cin >> Child_cost;
    

	ifstream fileInput;
	fileInput.open("flights.txt");

	while (fileInput >> fileID >> DestName_File)
	{

		getline(fileInput, fileName);
		if (DestName == DestName_File)
		{
            c=0;
			cout << "This Dest.name " << DestName << " is already exist in the text file.\n";
            break;
		}
        else{
            c=1;
        }
	}

	fileInput.close();

    if (c==0)
    {
        continue;
    }
	if (fileID == 0){
		fileID = 1001;
    }
	else{
		fileID += 1;
    }
	ofstream fileOutput;
	fileOutput.open("flights.txt", ios :: app);

	cout << "Flight ID:\t" << fileID << endl;
	cout << "Destination Name:\t" << DestName << endl;
    cout << "Capacity Of Flight is:\t" << capacity << endl;
    cout << "Adult cost of Flight is:\t" << Adult_cost << endl;
    cout << "Child cost of Flight is:\t" << Child_cost << endl;
	cout << "Flight has been added to the text file.\n";

	fileOutput << fileID << " " << DestName << " " << capacity << " " << Adult_cost << " " << Child_cost << endl;
    }
}
int main()
{
	add_new_flight();
	return 0;
}
