#%%
import pandas as pd
import matplotlib.pyplot as plt

# ----------------------------- Configuration -----------------------------
csv_file = 'data.csv'  # <-- Replace with your actual CSV file path
csv_file = 'om_swembad.csv'  # <-- Replace with your actual CSV file path


sampling_rate = 208 # Hz

# Colors for the three signals (columns 2, 3, 4)
colors = ['blue', 'green', 'red']
# -------------------------------------------------------------------------

# Read CSV:
# - skiprows=1 → ignores the first descriptive line
# - header=0 → uses the second line as column names
df = pd.read_csv(csv_file, skiprows=1, header=0)


#%%
# Check number of columns
if df.shape[1] < 4:
    raise ValueError(f"Expected at least 4 columns (counter + 3 signals), but found {df.shape[1]}.")

# Generate time axis: time = counter_index / sampling_rate
# We use the DataFrame index (0, 1, 2, ...) as the sample counter
df['Time'] = df.index / sampling_rate

#%%
# Select only columns 2, 3, 4 (index 1, 2, 3 in zero-based pandas)
# These are the three signals to plot
signal_columns = df.columns[1:4]  # Takes columns at positions 1, 2, 3 (2nd, 3rd, 4th)

#%%
if len(signal_columns) != 3:
    raise ValueError("Could not identify exactly 3 signal columns.")

# Plot the three signals
plt.figure(figsize=(12, 6))
for i, col in enumerate(signal_columns):
    plt.plot(df['Time'], df[col], color=colors[i], label=col, linewidth=1.5)

plt.xlabel('Tyd (sekondes)')
plt.ylabel('Hoeksnelheid [grade/s]')
plt.title('Giro data teenoor tyd (Frekensie:  208 Hz)')
plt.legend(['x', 'y', 'z'])
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.show()
# %%
