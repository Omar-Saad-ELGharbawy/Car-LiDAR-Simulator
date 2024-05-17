# Car Sensors Visualizer
This project utilizes Qt Creator (C++) to develop a visual representation of car sensor Field Of View (FOV) and obstacle detection capabilities.
## Table of contents:
- [Project Features](#project-features)
- [Project Structure](#project-structure)
- [Quick Preview](#quick-preview)
- [Requirements to run](#Requirements-to-run)
- [How it Works](#How-it-Works)
***
## Project Features

- Visualizes FOV: The sensor's FOV is displayed as a green arc, providing a clear understanding of its coverage area.
- Obstacle Detection: Obstacles within the FOV are identified and the FOV color changes to red for better awareness.
- Customizable Parameters: Sensor position, heading, range, and FOV angle can be adjusted to simulate various scenarios.
- Intuitive Interface: The Qt framework ensures a user-friendly experience for interacting with the visualization.

***
### Project Structure
- mainwindow.h: Defines the main application window class, including data structures for sensors, polygons, and functions for visualization and calculations.
- mainwindow.cpp: Implements the application logic, including event handling (paint event for drawing), sensor and polygon drawing functions, and obstacle detection algorithms.
- mainwindow.ui: This file, generated using Qt Creator's designer tool, defines the user interface layout of the main window. It includes elements like widgets and containers that make up the visual components seen by the user.

## Quick Preview  

![Screenshot (671)](https://github.com/Omar-Saad-ELGharbawy/Car-LiDAR-Simulator/assets/84602951/b3376907-32b4-4bbf-b04f-c458a9de03b7)

![Screenshot (669)](https://github.com/Omar-Saad-ELGharbawy/Car-LiDAR-Simulator/assets/84602951/c1c52da8-1ca3-40a8-b717-f23b69351a87)

[Presentation]()
[Car LiDaR.pptx](https://github.com/Omar-Saad-ELGharbawy/Car-LiDAR-Simulator/files/15357532/Car.LiDaR.pptx)
