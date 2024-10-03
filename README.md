---

# Queue Simulation with CSV Export

This project simulates the process of handling customers arriving at a service system with random arrival and service times. It calculates various metrics for each customer, such as their waiting time in the queue and system, as well as the server's idle time. The results are displayed both on the console and saved to a CSV file for further analysis.

## Features

- **Random Customer Arrival and Service Times**: 
  - The inter-arrival time is randomly selected from a uniform distribution between 1 and 8 minutes.
  - The service time is randomly selected from a uniform distribution between 1 and 6 minutes.
  
- **Metrics Calculated for Each Customer**:
  - Arrival time
  - Service time
  - Inter-arrival time
  - Clock time (when service starts)
  - Number of customers in the system and in the queue
  - Waiting time in the queue and in the system
  - Idle time of the server

- **CSV Export**: The results of the simulation for all customers are exported to a file named `simulation_results.csv` for easy analysis.

## Requirements

- A C++ compiler supporting C++11 or higher.
- The `<random>` and `<fstream>` libraries (which are standard in most C++ compilers).

## How to Compile and Run

1. **Clone the repository or download the files**.

2. **Compile the program** using a C++ compiler:
   ```bash
   g++ -o queue_simulation queue_simulation.cpp
   ```

3. **Run the program**:
   ```bash
   ./queue_simulation
   ```

4. The output will be displayed in the console, and the simulation results will also be saved in a CSV file named `simulation_results.csv` in the same directory.

## Output Example

The program will display the following columns for each customer:

- Customer ID
- Arrival Time
- Service Time
- Inter-arrival Time
- Clock Time (start of service)
- Number of customers in the system
- Number of customers in the queue
- Waiting time in the queue
- Total waiting time in the system
- Idle time of the server

The same information will be written to the `simulation_results.csv` file, which can be opened in any spreadsheet software (e.g., Excel).

## CSV File

The generated CSV file, `simulation_results.csv`, will contain the following columns:

```csv
Customer,Arrival Time,Service Time,Inter-arrival,Clock Time,Num in System,Num in Queue,Wait in Queue,Wait in System,Idle Time Server
```

Each row in the CSV file corresponds to one customer, providing the simulation data described above.

## Future Improvements

- Add more flexibility by allowing users to change the number of customers and time distributions via command-line arguments or a configuration file.
- Include visualization tools to analyze system performance (e.g., plotting queue lengths over time).

---
