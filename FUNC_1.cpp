#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void add_new_customer()
{
    int fileID = 0;
	string userName, fileName;
    int c;
    while(userName!="N" || userName!="n"){

	cout << "Enter your name please: ";
	getline(cin, userName);
    if (userName=="N" || userName=="n"){
        break;
    }

	ifstream fileInput;
	fileInput.open("customers.txt");

	while (fileInput >> fileID)
	{
		
		getline(fileInput, fileName);
		if (userName == fileName.erase(0, 1))
		{
            c=0;
			cout << "This name " << userName << " is already exist in the text file.\n";
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
	fileOutput.open("customers.txt", ios :: app);
	
	cout << "Customer ID:\t" << fileID << endl;
	cout << "Customer Name:\t" << userName << endl;
	cout << "Customer has been added to the text file.\n";

	fileOutput << fileID << " " << userName << endl;
    }
}
int main()
{
	add_new_customer();
	return 0;
}