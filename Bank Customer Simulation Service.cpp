#include <iostream>
#include <random>
#include <iomanip>
#include <fstream>  // For file handling

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    // Uniform distribution for arrival times (1 to 8 minutes)
    uniform_int_distribution<> arrival_dist(1, 8);

    // Uniform distribution for service times (1 to 6 minutes)
    uniform_int_distribution<> service_dist(1, 6);

    int total_customers = 100;
    int prev_arrival_time = 0;
    int clock_time = 0;  // Start at time 0
    int idle_time_server = 0;
    int customers_in_system = 0;

    // Summation variables
    int total_arrival_time = 0;
    int total_service_time = 0;
    int total_inter_arrival_time = 0;
    int total_wait_in_queue = 0;
    int total_wait_in_system = 0;
    int total_idle_time_server = 0;

    // Create and open the CSV file
    ofstream file("simulation_results.csv");
    // Write the CSV headers
    file << "Customer,Arrival Time,Service Time,Inter-arrival,Clock Time,Num in System,Num in Queue,Wait in Queue,Wait in System,Idle Time Server\n";

    // Output headers to the console
    cout << setw(10) << "Customer" 
         << setw(15) << "Arrival Time" 
         << setw(15) << "Service Time"
         << setw(15) << "Inter-arrival"
         << setw(15) << "Clock Time"
         << setw(20) << "Num in System"
         << setw(20) << "Num in Queue"
         << setw(20) << "Wait in Queue"
         << setw(20) << "Wait in System"
         << setw(20) << "Idle Time Server" << endl;

    int service_end_time = 0;

    // Simulate the process for each customer
    for (int i = 1; i <= total_customers; ++i) {
        int inter_arrival_time = arrival_dist(gen);  // Time between this customer and the previous one
        int arrival_time = prev_arrival_time + inter_arrival_time;
        int service_time = service_dist(gen);

        // Start of service is when the customer arrives or when the server is free
        int start_of_service = max(service_end_time, arrival_time);
        int end_of_service = start_of_service + service_time;

        int wait_in_queue = max(0, service_end_time - arrival_time);  // Waiting time in the queue
        int wait_in_system = wait_in_queue + service_time;  // Total time in system (queue + service)

        if (arrival_time < service_end_time) {
            customers_in_system++;
        } else {
            customers_in_system = 1;  // Only this customer in the system
        }

        idle_time_server = max(0, arrival_time - service_end_time);

        // Print details for each customer
        cout << setw(10) << i 
             << setw(15) << arrival_time
             << setw(15) << service_time
             << setw(15) << inter_arrival_time
             << setw(15) << start_of_service
             << setw(20) << customers_in_system
             << setw(20) << (customers_in_system - 1)  // Queue length
             << setw(20) << wait_in_queue
             << setw(20) << wait_in_system
             << setw(20) << idle_time_server << endl;

        // Write the data to the CSV file
        file << i << "," << arrival_time << "," << service_time << "," << inter_arrival_time << "," 
             << start_of_service << "," << customers_in_system << "," << (customers_in_system - 1) 
             << "," << wait_in_queue << "," << wait_in_system << "," << idle_time_server << "\n";

        // Summing up the values for totals
        total_arrival_time += arrival_time;
        total_service_time += service_time;
        total_inter_arrival_time += inter_arrival_time;
        total_wait_in_queue += wait_in_queue;
        total_wait_in_system += wait_in_system;
        total_idle_time_server += idle_time_server;

        prev_arrival_time = arrival_time;
        service_end_time = end_of_service;
    }

    // Output the totals
    cout << "\n--- Summation Results ---" << endl;
    cout << "Total Arrival Time: " << total_arrival_time << endl;
    cout << "Total Service Time: " << total_service_time << endl;
    cout << "Total Inter-arrival Time: " << total_inter_arrival_time << endl;
    cout << "Total Wait in Queue: " << total_wait_in_queue << endl;
    cout << "Total Wait in System: " << total_wait_in_system << endl;
    cout << "Total Idle Time Server: " << total_idle_time_server << endl;

    // Close the CSV file
    file.close();

    return 0;
}
