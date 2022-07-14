#include <iostream>
#include <fstream>
//Matthew Buehring
//During the creation of this project I had some help from the internet and friends in the creation of this project. 
//They helped to influence how the code was built and gave some insightful ideas as to how to improve upon it.
//I also used the book pages when creating this code and it helped to shape it.
using namespace std;
int P;//processes variable
int R;//resources variable

int main(int argc, char *argv[])
{
	
	ifstream file(argv[1]);
	
	file>>P;//gets process number
	file>>R;//gets resource number
	
	cout<<"There are "<<P<<" processes in the system."<<endl;
	cout<<"There are "<<R<<" resource types."<<endl;
	
	
	int al[P][R];//availble matrix
	int avala[R];//availble vector(array)
	int temp[R];//temp vector(array)
	int req[R];//temp req(array)
	bool flag[P];//flag array
	
	
	//making the matrix for allocation
	for(int i=0; i<P; i++)
	{
		for(int j=0; j<R; j++)
		{
			file>>al[i][j];
		}
	}
	
	//display for the allocation matrix
	cout<<"The Allocation Matrix is..."<<endl;
	cout<<"   ";
	for(int i=0; i<R; i++)
	cout<<(char)('A'+i)<<" ";
	cout<<endl;
		
	
	
	for(int i=0; i<P; i++)
	{
		cout<<i<<": ";
		for(int j=0; j<R; j++)
		{
			
			cout<<al[i][j]<<" ";
			
		}
		cout<<endl;
	}
	cout<<endl;
	
	
	//make the matrix for max
	int max[P][R];
	for(int i=0; i<P; i++)
	{
		for(int j=0; j<R; j++)
		{
			file>>max[i][j];
		}
	}
	
	//display for the max matrix
	
	cout<<"The Max Matrix is..."<<endl;
	cout<<"   ";
	for(int i=0; i<R; i++)
	cout<<(char)('A'+i)<<" ";
	cout<<endl;
		
	for(int i=0; i<P; i++)
	{
		cout<<i<<": ";
		for(int j=0; j<R; j++)
		{
			cout<<max[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	
	//calculate the need matrix and display the need matrix.
	int need[P][R];
	cout<<"The Need Matrix is..."<<endl;
	cout<<"   ";
	for(int i=0; i<R; i++)
	cout<<(char)('A'+i)<<" ";
	cout<<endl;
	
	for(int i=0; i<P; i++)
	{
		cout<<i<<": ";
		for(int j=0; j<R; j++)
		{
			need[i][j] = max[i][j]-al[i][j];
			cout<<need[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	
	//rint and make the available vector
	cout<<"The Available Vector is..."<<endl;
	//cout<<"   ";
	for(int i=0; i<R; i++)
	cout<<(char)('A'+i)<<" ";
	cout<<endl;
	for(int i=0; i<R; i++)
	{
		file>>avala[i];
		cout<<avala[i]<<" ";
	}
	cout<<endl;
	
	//set temp vec so we can change without changing origional
	for(int i=0; i<R; i++)
	{
		temp[i] = avala[i];
	}
	//set flag array to all false for checking
	for(int i=0; i<P; i++)
	{
		flag[i] = false;
	}
	
	//goes through and checks to see if system is in safe state
	//if so then increase the temp allowance
	for(int i=0; i<P; i++)
	{
		for(int j=0; j<R; j++)
		{
			if(flag[i] == false && need[i][j] <= temp[j])
			{
				temp[j] = temp[j] + al[i][j];
				flag[i] = true;
			}
		}
	}
	
	//if the flag array is all flase still then not safe
	for(int i=0; i<P; i++)
	{
		if(temp[i]=false)
		{
			cout<<"THE SYSTEM IS NOT IN A SAFE STATE!"<<endl;
			return 0;
		}
	}
	cout<<endl;
	cout<<"THE SYSTEM IS IN A SAFE STATE!"<<endl;
	
	int number=0;
	
	file>>number;//row number
	
	

	
	/* for(int i=0; i<R; i++)
	{
		file>> req[i];
	} */
	//create and display the request vector
	cout<<"The Request Vector is..."<<endl;
	cout<<"   ";
	for(int i=0; i<R; i++)
	cout<<(char)('A'+i)<<" ";
	cout<<endl;
	
	
	cout<<number<<": ";
	for(int i=0; i<R; i++)
	{
		file>> req[i];
		cout<<req[i]<<" ";
	}
	cout<<endl;
	
	
	//check to see if the request can be granted only if the request is smaller than or equal to the needed number
	// and if the request is smaller than or equal to the available if not then the process will have to wait
	// if the request is larger than what is availble and if the request is bigger than what is needed then it will it exceed its claim.
	
	 for(int i=0; i<R; i++)
	{
		
			
			if(req[i] <= need[number][i])
			{
				
				if(req[i] <= avala[i])
				{
					
					avala[i] = avala[i] - req[i];
					al[number][i] = al[number][i] + req[i];
					need[number][i] = need[number][i] - req[i];
				}
				else
				{
					cout<<"The process must wait as the resources are not availble at this time.";
					return 0;
				}
			}
			else
			{
				cout<<"ERROR! Process has exceeded its maximum claim.";
				return 0;
			}
		
	} 
	
		cout<<"REQUEST CAN BE GRANTED!"<<endl;
	cout<<endl;
		
	//display the current available vector.
	cout<<"The Availble Vector is..."<<endl;
	//cout<<"   ";
	for(int i=0; i<R; i++)
	cout<<(char)('A'+i)<<" ";
	cout<<endl;
	for(int i=0; i<R; i++)
	{
		cout<<avala[i]<<" ";
	}
	cout<<endl;
	
	
	
	
	
	
}

