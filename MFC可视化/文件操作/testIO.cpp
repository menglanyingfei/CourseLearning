#include <iostream>
#include <string> 
#include <fstream>

using namespace std;

int main() {
	ifstream myfile("file.txt");
	string temp, data;
	if (!myfile.is_open())  
    {  
        cout << "δ�ɹ����ļ�" << endl;  
    } 
	while(getline(myfile,temp))  
    {  
         data += temp + "\n";
    }
	
	cout << data;
    myfile.close(); 

	return 0;
}





