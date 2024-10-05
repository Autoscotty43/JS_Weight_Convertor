#include <iostream>
#include <iomanip>  // For setting decimal precision
#include <limits>   // For input validation

using namespace std;

// Function to get valid input from the user
int getValidInput(const string &prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0) {  // Check if input is invalid or negative
            cout << "Invalid input. Please enter a non-negative integer.\n";
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
        } else {
            return value;  // Return valid input
        }
    }
}

int main() {
    // Variables for user input
    int tons, stones, pounds, ounces;
    
    // Variables for total ounces and metric calculations
    double totalOunces, totalKilos, metricTons, kilograms, grams;

    // Input: Get user input for tons, stones, pounds, and ounces
    cout << "Welcome to the Imperial to Metric Converter\n";
    cout << "------------------------------------------\n";

    tons = getValidInput("Enter the weight in tons: ");
    stones = getValidInput("Enter the weight in stones: ");
    pounds = getValidInput("Enter the weight in pounds: ");
    ounces = getValidInput("Enter the weight in ounces: ");

    // Step 1: Convert everything to total ounces
    totalOunces = (35840 * tons) + (224 * stones) + (16 * pounds) + ounces;

    // Step 2: Convert ounces to total kilos
    totalKilos = totalOunces / 35.274;

    // Step 3: Calculate metric tons
    metricTons = static_cast<int>(totalKilos / 1000);

    // Step 4: Calculate kilograms
    kilograms = static_cast<int>(totalKilos) % 1000;

    // Step 5: Calculate grams
    grams = (totalKilos - static_cast<int>(totalKilos)) * 1000;

    // Output: Display a summary of input values
    cout << "\nInput Summary:\n";
    cout << "Tons: " << tons << "\n";
    cout << "Stones: " << stones << "\n";
    cout << "Pounds: " << pounds << "\n";
    cout << "Ounces: " << ounces << "\n";

    // Output: Display the results in metric tons, kilograms, and grams
    cout << fixed << setprecision(1);  // Set precision to 1 decimal place
    cout << "\nConverted Weight in Metric System:\n";
    cout << "---------------------------------\n";
    cout << "Metric tons: " << metricTons << endl;
    cout << "Kilograms  : " << kilograms << endl;
    cout << "Grams      : " << grams << endl;

    return 0;
}
