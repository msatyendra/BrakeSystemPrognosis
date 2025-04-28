
% -----------------------------------
% Author : Satyendra Maurya
% BITS ID: 2023HT65067
% Project: Brake System Prognosis
% v1.1 - AI Model Prediction Script
% -----------------------------------

clear; clc; close all;

load('BSP_model.mat');

% Example: New sensor data [MaxTemp, MinPressure, MaxVibration, MinWear]
new_sample = [380, 2.5, 0.12, 50];

predicted_class = predict(model, new_sample);

fprintf('Predicted Class: %d\n', predicted_class);

% Interpretation of predicted class
switch predicted_class
    case 0
        disp('Status: Normal Condition');
    case 1
        disp('Status: Overheating Detected');
    case 2
        disp('Status: Pressure Drop Detected');
    case 3
        disp('Status: Vibration Anomaly Detected');
    case 4
        disp('Status: Pad Wear Detected');
    case 5
        disp('Status: Combined Fault Detected');
    otherwise
        disp('Status: Unknown Condition');
end
