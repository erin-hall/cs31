#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int countMatches(const string a[], int n, string target); //YES
int detectMatch(const string a[], int n, string target); //YES
bool detectSequence(const string a[], int n, string target, int& begin, int& end); //ALMOST, ODD VALUES FOR BEGIN AND END WHEN FALSE
int detectMin(const string a[], int n); //YES
int moveToBack(string a[], int n, int pos); //YES
int moveToFront(string a[], int n, int pos); //YES
int detectDifference(const string a1[], int n1, const string a2[], int n2); //YES
int deleteDups(string a[], int n);
bool contains(const string a1[], int n1, const string a2[], int n2); 
int meld(const string a1[], int n1, const string a2[], int n2, string result[], int max); //YES
int split(string a[], int n, string splitter); //YES

bool validityCheck(int n);

//use to test function (use assert), will be ignored later by grader
int main()
{

}

//checks if n is a non-negative integer
bool validityCheck(int n)
{
	if (n <= -1) //if n is negative
		return false;
	else //if n is zero or positive
		return true;
}



//counts the number of times the target string appears in the array
int countMatches(const string a[], int n, string target)
{
	if (validityCheck(n)) //makes sure n is non-negative
	{
		int matchCount = 0; //sets number of matches to zero
		for (int x = 0; x < n; x++) //iterates through all significant elements of array
			if (a[x] == target) //if the target string is at the postition
				matchCount++; //increae number of matches by one
		return matchCount; //return number of matches
	}
	else
		return -1; //if n is negative, return -1
}



//returns the first position of the target string in the array
int detectMatch(const string a[], int n, string target)
{
	if (validityCheck(n)) //makes sure n is non-negative
	{
		for (int x = 0; x < n; x++) //iterates through all signigicant elements of array
		{
			if (a[x] == target) //if the target string is at the position
				return x; //return the position
		}
		return -1; //if there is no target string, return -1
	}
	else
		return -1; //if n is negative, return -1
}



//finds first occurrence of a sequence of the target string
bool detectSequence(const string a[], int n, string target, int& begin, int& end)
{
	if (validityCheck(n)) //makes sure n is non-negative
	{
		for (int x = 0; x < n; x++) //iterates through all interesting elements of the array
		{
			if (a[x] == target) //if the target string is at the position
			{
				begin = x; //that position is the beginning position
				while (a[x] == target) //while its still the target string
				{
					end = x; //set the end position
					x++;
				}
				//cerr << "BEGIN IS " << begin << endl;
				//cerr << "END IS " << end << endl;
				return true;
				break;
			}
		}
		//cerr << "BEGIN IS " << begin << endl;
		//cerr << "END IS " << end << endl;
		return false;
	}
	else 
	{
		return false;
	//	cerr << "BEGIN IS " << begin << endl;
	//	cerr << "END IS " << end << endl;
	}
} 



//returns position of smallest element in the array
int detectMin(const string a[], int n)
{
	if (validityCheck(n)) //makes sure n is non-negative
	{
		if (n != 0) //makes sure n is not 0
		{
			int minPos = 0; //start by assuming the max position is 0
			for (int x = 1; x < n; x++) //iterates through the rest of the array
			{
				if (a[x] < a[minPos]) //if the current position is less than the minimum
				{
					minPos = x; //sets new minimum to current position
				}
			}
			return minPos; //returns minimum position
		}
		else
			return -1; //returns -1 if n is 0
	}
	else
		return -1; //returns -1 if n is negative
}



//moves string at given position to the back, pushing everything else foward
int moveToBack(string a[], int n, int pos)
{
	if (pos < 0 || n < 0 || pos >= n)
		return -1;


	/*if (n == 1 && pos == 0)
		return 0; */

	// save the element that is to be moved
	string back = a[pos];

	// shift left the elements that are after the one to be moved
	for (int x = pos; x < n - 1; x++)
		a[x] = a[x + 1];

	// place the moved element at the end
	a[n - 1] = back;
	return pos;
}



//moves string at given position to the front, pushing everything else back
int moveToFront(string a[], int n, int pos)
{
	if (pos < 0 || n < 0 || pos >= n)
		return -1;

/*
	if (n == 1 && pos == 0)
		return 0; */

		// save the element that is to be moved
		string front = a[pos];

		// shift left the elements that are after the one to be moved
		for (int x = pos; x > 0; x--)
			a[x] = a[x-1];

		// place the moved element at the end
		a[0] = front;
		return pos;
}



//returns position of the first corresponding elements of two arrays that aren't equal
int detectDifference(const string a1[], int n1, const string a2[], int n2)
{
	if (validityCheck(n1) && validityCheck(n2)) 
	{
		int end; //where for loop below should end
		int pos; //position where the arrays differ
		if (n2 >= n1) //if n2 is bigger than or equal to n1
		{
			end = n1; //set the end of the for loop to n1
		}
		else if (n1 > n2) //if n1 is bigger than n2
		{
			end = n2; //set the end of the for loop to n2
		}
		if (end == 0) //if the smallest string is of size 0, set the end there
		{
			pos = end;
			return pos; 
		}
		else {
			for (int x = 0; x < end; x++) //iterates through the loop until the established end, which usually is of the smaller string
			{
				if (a1[x] != a2[x]) //finds where a1 does not equal a2
				{
					pos = x; //returns that position
					return pos;
				}
			}
		}
	}
	else //if n1 and/or n2 are negative
		return -1;
}




//retain only one item of the sequence of consecutive items BEST
 int deleteDups(string a[], int n)
{
	int retained;
	if (validityCheck(n))
	{
		
		if (n == 0) //if no elements are checked for duplicates
		{
			return n; //return the number of retained, which is just the number of elements in the string
		}
		else 
		{
			retained = 0;
			for (int x = 0; x < n; x++)
			{
				if (a[x] == "\0")
				{
					break;
				}
					if (a[x] != a[x + 1])
					{
						//nothing to delete, keep iterating
						retained++;
					}
					else if (a[x] == a[x + 1])
					{
						//move everything left
						for (int y = x + 1; y < n - 1; y++)
						{
							a[y] = a[y + 1];
						}
						a[n - 1] = "\0";
						x--;
					}
				
				
			}
			return retained;
		}
	}
	else
		return -1;
} 


//returns true if a2 is contained in a1, false otherwise
bool contains(const string a1[], int n1, const string a2[], int n2)
{
	if (validityCheck(n1 && n2)) //makes sure that n1 and n2 are non-negative
	{
		if (n2 > n1) //makes sure that n2 is less than n1
			return false;

		if (n2 == 0) //if you're looking for a smaller string of 0 items, it will be contained
			return true;
		
		if (n1 == 0 && n2 != 0) //if the bigger string has 0 items, but the smaller one doesn't it can't possibly be contained by the bigger string
			return false;

		for (int x = 0; x < n1; x++) //iterates through loop until the end of a1
		{
			if (a2[0] == a1[x]) //if the first element in a2 equals any element in a1, look to see if it's a match
			{
				int y = x; //sets up variable for iterating through a1
				int z; //sets up variable for iterating through a2
	

				for (z = 1; z < n2 && y < n1; y++)
				{
					if (a2[z] == a1[y])
					{
						z++;
					}
				}
				if (z == n2)
				{
					return true;
				}
			}
			else
				return false;
		}
		//return false; //if there are no matches, return false
	}
	else //if n1 and n2 are negative, returns false 
		return false;
}



//merge elments of a1 and a2 in nondecreasing order and return number of elements
int meld(const string a1[], int n1, const string a2[], int n2, string result[], int max)
{
	if (validityCheck(n1 && n2)) //makes sure that n1 and n2 are non-negative
	{
		int total = n1 + n2; //adds up n1 and n2 to see the length of the string you would need
		if (total > max || n1 < 0 || n2 < 0) //makes sure the answer for total is valid
			return -1;

	
		for (int x = 0; x < (n1 - 1); x++) //iterates through a1
		{
			if (a1[x] > a1[x + 1]) //checks to ensure a1 is nondecreasing
				return -1;
		}
		for (int x = 0; x < n2 - 2; x++) //iterates through a2
		{
			if (a2[x] > a2[x + 1]) //checks to ensure a2 is nondecreasing
				return -1;
		}
		int temp1 = 0; //sets up temp variables to get everything in the right order
		int temp2 = 0; 
		int num = 0;


		if (n1 == 0 && n2 == 0) //if both strings are zero length
			return 0; //the melded string will have zero length
		if (n1 == 0) //if one string has zero length, but the other doesn't 
			return n2; //return the length of the other string
		if (n2 == 0) //if the other string has zero length, but the other doesn't
			return n1; //return the length of the other string


		while (temp1 < n1 && temp2 < n2)
		{
			if (a1[temp1] <= a2[temp2])
			{
				result[num] = a1[temp1];
				temp1++;
			}
			else if (a2[temp2] < a1[temp1])
			{
				result[num] = a2[temp2];
				temp2++;
			}
			num++;
		}
		//figure out which one i ran out of
		//add remaining elements in 
	
		if (n1 > n2)
		{
			while (temp1 < n1)
			{
				result[num] = a1[temp1];
				temp1++;
			}
		}
		else if (n2 > n1)
		{
			while (temp2 < n2)
			{
				result[num] = a2[temp2];
				temp2++;
			}
		}

		return total;
	}
	else
		return -1;
}



//rearrange elements of array into before and after splitter, and return position of element before splitter
int split(string a[], int n, string splitter)
{
	if (validityCheck(n)) //checks to see if valid
	{
		if (n == 0) //if n is 0 return 0
			return 0;
		else //if it's otherwise valid
		{
			for (int x = 0; x < n; x++) //iterate through loop
			{
				if (a[x] >= splitter) //when the element is greater or equal to the splitter
				{
					for (int y = (x + 1); y < n; y++) //increment through the loop
					{
						if (a[y] < splitter) //if the element is greater than the splitter
						{
							string temp = a[y]; //swap the places of a[x] and a[y] using the temp variable
							a[y] = a[x];
							a[x] = temp; 
							break;
						}
					}
				}
			}
			for (int z = 0; z < n; z++) //iterate through loop
			{
				if (a[z] >= splitter) //when the element is greater than or equal to the splitter
					return z; //return the element
			}
			return n; //return position otherwise
		}
	}
}









