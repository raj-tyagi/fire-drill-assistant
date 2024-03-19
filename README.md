# Fire Escape System

The Fire Escape System is a software tool designed to assist in emergency evacuations from multi-floor buildings. This system calculates the shortest paths from specified starting points to all rooms on each floor, aiding occupants in swiftly navigating to safety during critical situations.

## Features

- **Floor Plan Input:** Users can input detailed floor plans, including room layouts and distances.
  
- **Shortest Path Calculation:** Utilizes Dijkstra's algorithm to compute the shortest evacuation paths from designated starting points to all rooms on each floor.
  
- **Emergency and Drill Modes:** Offers real-time evacuation guidance in emergency mode and practice scenarios in drill mode.
  
- **Optimization Algorithms:** Incorporates Knapsack, Job Scheduling, Huffman Encoding, and Optimal Merge algorithms for efficient resource management and data handling.
  
## Algorithms Used

### Dijkstra's Algorithm
- **Description:** Dijkstra's algorithm is used to compute the shortest paths from a single source vertex to all other vertices in a weighted graph.
- **Use Case:** In the Fire Escape System, Dijkstra's algorithm is applied to calculate the shortest evacuation paths from specified starting points (e.g., emergency exits or user locations) to all rooms on each floor, ensuring occupants reach safety efficiently.

### Knapsack Algorithm
- **Description:** The Knapsack algorithm is utilized to optimize the selection of items based on their weights and values, considering a fixed capacity.
- **Use Case:** During emergency evacuations, the Knapsack algorithm helps prioritize essential items to carry, maximizing their utility while adhering to weight constraints.

### Job Scheduling Algorithm
- **Description:** The Job Scheduling algorithm prioritizes the order in which tasks or jobs are assigned to available resources or personnel.
- **Use Case:** In the Fire Escape System, the Job Scheduling algorithm aids in organizing evacuation tasks, ensuring critical activities are completed promptly to facilitate the evacuation process.

### Huffman Encoding Algorithm
- **Description:** Huffman encoding compresses data by assigning variable-length codes to input characters based on their frequencies.
- **Use Case:** The Huffman Encoding algorithm is employed to compress data related to the fire escape system, reducing storage space and improving transmission efficiency.

### Optimal Merge Algorithm
- **Description:** The Optimal Merge algorithm efficiently merges sorted data sets, minimizing the time and resources required for data processing.
- **Use Case:** In the Fire Escape System, the Optimal Merge algorithm optimizes the merging of sorted evacuation plans or resource lists, streamlining data handling during emergency scenarios.

## Getting Started

1. Clone the repository to your local machine.
2. Compile and run the `main.cpp` file using a C++ compiler.
3. Follow the on-screen instructions to input floor plans and utilize the system's features.

## Usage

- Choose between emergency and drill modes to access evacuation guidance or practice scenarios.
- Input floor plans and starting points to compute shortest evacuation paths.
- Utilize optimization algorithms for efficient resource management and data handling.

## Contributions

Contributions and healthy optimizations are always welcomed!!

