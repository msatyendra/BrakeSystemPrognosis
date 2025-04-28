
# Model Training & Prediction Scripts

This folder contains scripts related to training the AI model for brake system prognosis.
This folder contains MATLAB scripts for predicting brake system health using the trained AI model.

---

## Files:
- **BSP_AITM_v1.m** – Trains a Random Forest model on the generated dataset.
- **BSP_sampleSet.csv** – Dataset file with features and labels for model training.
- **BSP_AIPM_v1.m** – Loads the trained model and predicts brake system condition based on new sensor data.

---

## Purpose:
- Train and evaluate machine learning models.
- Save the trained model for later real-time prediction.
- Real-time prediction of brake faults using new incoming sensor values.
- Alert generation for maintenance decisions.
