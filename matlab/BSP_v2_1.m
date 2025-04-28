% -----------------------------------
% Author : Satyendra Maurya
% BITS ID: 2023HT65067
% Project: Brake System Prognosis
% v2.1 - Combination of all sensors' plot
% -----------------------------------

clear; clc; close all;
t = 0:0.1:10;

% Simulating Brake Disc Temperature Sensor
disc_temp = 30 + 150 * exp(-0.5 * (t - 5).^2);

% Simulating Brake Fluid Pressure Sensor
pressure = 3 + 0.5 * sin(2 * pi * 0.5 * t);

% Simulating MPU6050-Vibration Sensor
vibration = randn(size(t)) * 0.05;
vibration(40:60) = vibration(40:60) + 0.3;

% Simulating MLX90393-Brake Pad Wear sensor
wear = linspace(100, 50, length(t));

% Combine into one matrix
sensor_data = [t' disc_temp' pressure' vibration' wear'];

% Plot all signals
figure;
subplot(4,1,1);
plot(t, disc_temp, 'r'); title('Brake Disc Temperature'); ylabel('°C'); grid on;

subplot(4,1,2);
plot(t, pressure, 'b'); title('Brake Fluid Pressure'); ylabel('MPa'); grid on;

subplot(4,1,3);
plot(t, vibration, 'g'); title('Brake Vibration'); ylabel('g-force'); grid on;

subplot(4,1,4);
plot(t, wear, 'm'); title('Brake Pad Wear (Magnetic Field)'); ylabel('Field Intensity'); xlabel('Time (s)'); grid on;
