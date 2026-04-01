# C++ K-Means Visualizer

A visual, interactive implementation of the K-Means clustering algorithm built in C++ using SFML 3.

## Features
- **Object-Oriented Architecture**: Clean separation of `Point`, `Centroid`, and `KMeans` engine logic.
- **K-Means++ Initialization**: Implements proportional probability to pick robust initial centroids.
- **Interactivity**: 
  - `Left Click` to add data points dynamically.
  - `Spacebar` to perform one algorithm step (Assignment & Update).
  - `Esc` to close the application cleanly.
- **Real-Time Metrics**: Displays the Inertia (Sum of squared distances) and current point count on the screen.

## Prerequisites
- A modern C++17 compiler (e.g., AppleClang, GCC)
- CMake (version 3.15+)
- SFML 3.x (installed via Homebrew on Mac: `brew install sfml`)

## Build Instructions
1. Open a terminal in the project directory.
2. Configure the project using CMake:
   ```bash
   cmake -B build
   ```
3. Compile the executable:
   ```bash
   cmake --build build
   ```
4. Run the program:
   ```bash
   ./build/KMeansVisualizer
   ```

## Controls
- **Mouse Left Click**: Add a data point at the mouse position.
- **Spacebar**: Step the algorithm.
- **Esc**: Exit the visualizer.
# K-algorithm-Visualizer-algorithm-using-C-
