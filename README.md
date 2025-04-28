
# Brake System Prognosis using Artificial Intelligence

An embedded and AI-based system developed to monitor the health of a vehicle's brake system in real-time using sensors, FreeRTOS, and machine learning techniques.  
This project predicts potential brake faults like overheating, pressure drop, vibration anomalies, and pad wear.

---

## Table of Contents
- [Introduction](#introduction)
- [Folder Structure](#folder-structure)
- [Tools and Technologies](#tools-and-technologies)
- [How to Run](#how-to-run)
- [Author](#author)

---

## Introduction

Brake failure can lead to catastrophic accidents. This project demonstrates how sensor data acquisition, embedded processing, and AI modeling can predict failures early and ensure safe operation.  
The system collects real-time data from multiple sensors, processes it via a microcontroller running FreeRTOS, and predicts faults using an ML model.

---

## Folder Structure

- /firmware/
  Embedded C firmware code

- /matlab/  
  Sensor signal simulation scripts (MATLAB) 
  Simulink models for sensor animation (optional)

- /machineLearning/
  AI model training scripts and dataset files
  Real-time prediction scripts

- /figures/  
  Graphs, block diagrams, screenshots

---

## Tools and Technologies

- MATLAB R2024a (Signal simulation, AI model)
- Simulink (Sensor animation)
- FreeRTOS (Task management)
- Microchip Studio (Embedded coding)
- Python (optional, for ML prototyping)
- Git and GitHub (Version control)

---

## How to Run

1. Open MATLAB.
2. Run `matlab/BSP_v2_2.m` to generate sensor signals.
3. Run `matlab/BSP_v3_2.m` to create dataset.
4. Train the model using `machineLearning/BSP_AITM_v1.m`.
5. Predict brake system health using `machineLearning/BSP_AIPM_v1.m`.
6. Visualize simulation results in Simulink.

---

## Author

**Satyendra Maurya**  
M.Tech – Automotive Electronics  
BITS Pilani (WILP)  
BITS ID: 2023HT65067
