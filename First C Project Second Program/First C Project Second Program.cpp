

#include <iostream>
using namespace std;

#include <fstream>
#include <string>
#include <iomanip>

int main() {
    
    //Initializing last name, first name, salary, and the percentage of the increase in salary.
    string last_name, first_name;
    double salary, salary_increase;

    //Opens the file SalaryData to read from
    ifstream input_file;
    input_file.open("SalaryData.txt");

    //Creates the file SalaryOut to write too.
    ofstream output_file;
    output_file.open("SalaryOut.txt");

    //Sets the numbers in the file to be rounded to two, display the decimal point
    output_file << fixed << setprecision(2) << showpoint;

    //Creates a for loop that runs through the three entries
    //Note: Unsure if you wanted us to create a for loop for this. As the loop structure is the same as Java and you
    //mentioned them in class, I used one here.
    for (int i = 0; i < 3; i++) {
        //Takes the line of a file and splits it into the four variables
        input_file >> last_name >> first_name >> salary >> salary_increase;
        
        /* Debugging output
        cout << last_name << " " << first_name << " " << salary << " " << salary_increase <<endl;
        */

        //Creates a double called adjusted salary. This number will be reset betwen each loop.
        double adjusted_salary;
        /*
        Adds the percentage to the salary.It converts the percent to a decimal, then adds 1 and multiplies the new
        decimal to the base salary.
        */
        adjusted_salary = salary * (1 + (salary_increase / 100));
        
        //Writes the First Name, Last Name, and Adjusted Salary to the output file
        output_file << first_name << " " << last_name << " " << adjusted_salary << endl;
    }
    
    //Closes the file to prevent leaks.
    output_file.close();

    return 0;
}

