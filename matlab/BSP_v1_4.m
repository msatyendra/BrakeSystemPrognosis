% -------------------------------------------------
% Author : Satyendra Maurya
% BITS ID: 2023HT65067
% Project: Brake System Prognosis
% v1.4 - Corrected the vibration sensor parameter
% -------------------------------------------------

clear; clc; close all;
t = 0:0.1:10;

% 1. Simulating Brake Disc Temperature Sensor
figure;
plot(t, 30 + 150 * exp(-0.5 * (t - 5).^2), 'r');
title('Simulated Brake Disc Temperature');
xlabel('Time (s)');
ylabel('Temperature (°C)');
grid on;

% 2. Simulating Brake Fluid Pressure Sensor
figure;
plot(t, 3 + 0.5 * sin(2 * pi * 0.5 * t), 'b');
title('Simulated Brake Fluid Pressure');
xlabel('Time (s)');
ylabel('Pressure (MPa)');
grid on;

% 3. Simulating MPU6050-Vibration Sensor
vib_x = randn(size(t)) * 0.05;
vib_y = randn(size(t)) * 0.05;
vib_z = randn(size(t)) * 0.05;

vibration = sqrt(vib_x.^2 + vib_y.^2 + vib_z.^2);  % Overall vibration magnitude

vibration(40:60) = vibration(40:60) + 0.3;  
figure;
plot(t, vibration, 'g');
title('Simulated Brake Vibration Signal');
xlabel('Time (s)');
ylabel('Vibration (g)');
grid on;

% 4. Simulating MLX90393-Brake Pad Wear Sensor
wear = linspace(100, 50, length(t));  
figure;
plot(t, wear, 'm');
title('Simulated Brake Pad Wear (Magnetic Field)');
xlabel('Time (s)');
ylabel('Field Intensity (mT)');
grid on;

