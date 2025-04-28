% --------------------------------------------
% Author : Satyendra Maurya
% BITS ID: 2023HT65067
% Project: Brake System Prognosis
% v3.1 - Simulating actual sensor's behaviour
% --------------------------------------------

clear; clc; close all;

n_samples_per_class = 500;  % 6 classes x 500 = 3000 samples
data = [];
labels = [];

for class = 0:5
    for i = 1:n_samples_per_class
        t = 0:0.1:10;  % Time vector

        % Base signals
        disc_temp = 30 + 150 * exp(-0.5 * (t - 5).^2);
        pressure = 3 + 0.5 * sin(2 * pi * 0.5 * t);
        vibration = randn(size(t)) * 0.05;
        wear = linspace(100, 50, length(t));

        % Inject fault behavior
        switch class
            case 1  % Overheating
                disc_temp = disc_temp + 200;
            case 2  % Pressure drop
                pressure(40:end) = pressure(40:end) - 2;
            case 3  % Vibration anomaly
                vibration(40:60) = vibration(40:60) + 0.6;
            case 4  % Excessive wear
                wear = linspace(100, 30, length(t));
            case 5  % Combined fault: Overheat + pressure drop
                disc_temp = disc_temp + 150;
                pressure(40:end) = pressure(40:end) - 2;
        end

        % Feature extraction
        sample = [max(disc_temp), min(pressure), max(abs(vibration)), min(wear)];
        data = [data; sample];
        labels = [labels; class];
    end
end

% Save dataset
dataset = [data, labels];
header = {'MaxTemp','MinPressure','MaxVibration','MinWear','Label'};
writecell(header, 'BSP_sampleSet.csv');
writematrix(dataset, 'BSP_sampleSet.csv', 'WriteMode', 'append');
disp('Dataset saved as BSP_sampleSet.csv');
