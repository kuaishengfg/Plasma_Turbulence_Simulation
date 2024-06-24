import math
import random
import matplotlib.pyplot as plt

# Constant numbers
PI = 3.14159265358979323846

# Function of d(sita)/dt
def fsita(t, sita, r):
    A, B, R0, m, w, k = 200.0, 1.0, 5.0, 5.0, 10.0, 1.0
    output = -(A / (B * r)) * (PI * math.sin(2 * PI * r / R0) * math.sin(m * sita + w * t + k * r) / R0 
                                 + k * math.sin(PI * r / R0) * math.sin(PI * r / R0) * math.cos(m * sita + w * t + k * r))
    return output

# Function of dr/dt
def fr(t, sita, r):
    A, B, R0, m, w, k = 200.0, 1.0, 5.0, 5.0, 10.0, 1.0
    output = A * m * math.sin(PI * r / R0) * math.sin(PI * r / R0) * math.cos(m * sita + w * t + k * r) / (B * r)
    return output

# Monte Carlo method for random number generation
def MT(seed):
    while seed > 10000000000:
        seed = seed % 107
    xx1 = 747 * seed + 211
    yy = xx1 % 1000
    xx2 = 379 * seed + 159
    zz = xx2 % 1000
    seed = (1107 * seed + 427) % 107
    if yy < 0:
        yy += 1000
    if zz < 0:
        zz += 1000
    steinsgate = 0.001 * yy + 0.000001 * zz
    return steinsgate

# Main function with 4-stage Runge-Kutta methods
def main():
    # Set random seed
    random.seed()

    # Input pre-variables
    R0, m, fai, A, B, w, k = 5.0, 5.0, 0.0, 200.0, 1.0, 10.0, 1.0
    h = 0.0001
    T = float(input("###  Enter the total execution time T: "))
    n = int(T / h)  # Total simulation steps.

    # Initialize lists to store the data points
    t_values = []
    r_values = []
    theta_values = []

    # Initial conditions
    sita = random.uniform(0, 2 * PI)
    r = random.uniform(0, R0 / 2)

    # Simulation loop
    for i in range(n):
        t = h * i

        ksita1 = fsita(t, sita, r)
        kr1 = fr(t, sita, r)

        ksita2 = fsita(t + h / 2.0, sita + ksita1 * h / 2.0, r + kr1 * h / 2.0)
        kr2 = fr(t + h / 2.0, sita + ksita1 * h / 2.0, r + kr1 * h / 2.0)

        ksita3 = fsita(t + h / 2.0, sita + ksita2 * h / 2.0, r + kr2 * h / 2.0)
        kr3 = fr(t + h / 2.0, sita + ksita2 * h / 2.0, r + kr2 * h / 2.0)

        ksita4 = fsita(t + h, sita + h * ksita3, r + h * kr3)
        kr4 = fr(t + h, sita + h * ksita3, r + h * kr3)

        sita += h * (ksita1 + 2.0 * ksita2 + 2.0 * ksita3 + ksita4) / 6.0
        r += h * (kr1 + 2.0 * kr2 + 2.0 * kr3 + kr4) / 6.0

        # Store the data points
        t_values.append(t)
        theta_values.append(sita)
        r_values.append(r)

        # Random crash condition
        if random.random() < 0.0001:  # 0.01% chance for a crash per step
            dd = R0 / 100  # Crash distance
            fai = random.uniform(0, 2 * PI)  # Random angle for the crash
            delta_r = dd * math.cos(fai)
            r += delta_r
            delta_sita = dd * math.sin(fai) / r
            sita += delta_sita

    # Convert theta to x and y coordinates for polar to cartesian conversion
    x_values = [r * math.cos(theta) for r, theta in zip(r_values, theta_values)]
    y_values = [r * math.sin(theta) for r, theta in zip(r_values, theta_values)]

    # Plotting the data points
    plt.scatter(x_values, y_values,color='red',marker='*',s=0.1)
    plt.title('Scatter Plot of Particle Trajectory in Polar Coordinates')
    plt.xlabel('X coordinate')
    plt.ylabel('Y coordinate')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()
