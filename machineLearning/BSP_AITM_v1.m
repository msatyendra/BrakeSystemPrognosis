
% -----------------------------------
% Author : Satyendra Maurya
% BITS ID: 2023HT65067
% Project: Brake System Prognosis
% v1.1 - AI Model Training Script
% -----------------------------------

clear; clc; close all;

% Load dataset
data = readmatrix('BSP_sampleSet.csv');

% Extract features and labels
X = data(:, 1:4);  % Features: MaxTemp, MinPressure, MaxVibration, MinWear
Y = data(:, 5);    % Labels: 0 - Normal, 1 - Overheating, etc.

% Split data into training (80%) and testing (20%)
cv = cvpartition(size(X,1),'HoldOut',0.2);
XTrain = X(training(cv),:);
YTrain = Y(training(cv),:);
XTest = X(test(cv),:);
YTest = Y(test(cv),:);

% Train a Random Forest (Bagged Trees) Model
model = fitcensemble(XTrain, YTrain, 'Method', 'Bag');

% Predict on test set
YPred = predict(model, XTest);

% Calculate and display accuracy
accuracy = sum(YPred == YTest) / numel(YTest) * 100;
fprintf('Test Accuracy: %.2f%%\n', accuracy);

% Display Confusion Matrix
figure;
confusionchart(YTest, YPred);
title('Confusion Matrix for Brake System Prognosis');

% Save trained model
save('brake_model.mat', 'model');

disp('Trained model saved as brake_model.mat');
