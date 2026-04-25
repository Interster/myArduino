#%%
import pandas as pd
import matplotlib.pyplot as plt

# 1. Konfigurasie
input_lêer = 'om_swembad.csv'  # Maak seker die lêernaam is korrek
frekwensie_hz = 208          # Monsterfrekwensie in Hz
dt = 1 / frekwensie_hz       # Tydsinterval (Delta t)

# 2. Laai die data
df = pd.read_csv(input_lêer)

# 3. Integrasie (Kumulatiewe Som)
# Ons gebruik die 'trapezoidal' reël of eenvoudige reghoek-integrasie (cumsum)
# Hoek = som(hoeksnelheid * dt)
df['Roll_Angle'] = df['Roll (degrees/second)'].cumsum() * dt
df['Pitch_Angle'] = df['Pitch (degrees/second)'].cumsum() * dt
df['Yaw_Angle'] = df['Yaw (degrees/second)'].cumsum() * dt

# Skep 'n nuwe kolom 'Line_Counter' wat van 0 af tel
df['Line_Counter'] = range(len(df))

# Skep 'n tyd-as in sekondes gebaseer op die frekwensie
df['Time_s'] = df['Line_Counter'] * dt

#%%
# 4. Plot die resultate
plt.figure(figsize=(10, 6))

plt.plot(df['Time_s'], df['Roll_Angle'], label='Roll (Graad)')
plt.plot(df['Time_s'], df['Pitch_Angle'], label='Pitch (Graad)')
plt.plot(df['Time_s'], df['Yaw_Angle'], label='Yaw (Graad)')

plt.title(f'Geïntegreerde Hoek teen Tyd ({frekwensie_hz}Hz)')
plt.xlabel('Tyd (sekondes)')
plt.ylabel('Hoek (grade)')
plt.legend()
plt.grid(True)

plt.show()

#%%
plt.plot(df['Time_s'], df['Roll (degrees/second)'], label='Pitch (deg/s)')
plt.plot(df['Time_s'], df['Pitch (degrees/second)'], label='Pitch (deg/s)')
plt.plot(df['Time_s'], df['Yaw (degrees/second)'], label='Pitch (deg/s)')

plt.title(f'Hoektempo teen Tyd ({frekwensie_hz}Hz)')
plt.xlabel('Tyd (sekondes)')
plt.ylabel('Hoektempo (grade/s)')
plt.legend()
plt.grid(True)

plt.show()


#%%

# Kies net data tussen 5.5 sekondes en 12.0 sekondes
begin_tyd = 1.0
eind_tyd = 10.0

masker = (df['Time_s'] >= begin_tyd) & (df['Time_s'] <= eind_tyd)
df_segment = df.loc[masker]

# Plot nou net die segment
plt.plot(df_segment['Time_s'], df_segment['Roll (degrees/second)'])
plt.plot(df_segment['Time_s'], df_segment['Pitch (degrees/second)'])
plt.plot(df_segment['Time_s'], df_segment['Yaw (degrees/second)'])


plt.title(f'Hoektempo teen Tyd ({frekwensie_hz}Hz)')
plt.xlabel('Tyd (sekondes)')
plt.ylabel('Hoektempo (grade/s)')
plt.legend()
plt.grid(True)

plt.show()

# Opsioneel: Stoor die nuwe data na 'n CSV
# df.to_csv('geintegreerde_data.csv', index=False)
# %%
# Verwyder die gestadigde fout of die vooroordeel van die data

# Veronderstel die eerste 100 lesings was terwyl die vliegtuig stilgestaan het
bias_rol = df['Roll (degrees/second)'].iloc[0:200].mean()
bias_hei = df['Pitch (degrees/second)'].iloc[0:200].mean()
bias_gier = df['Yaw (degrees/second)'].iloc[0:200].mean()

# Trek die bias af van die rou data
df['Rol_Skoon'] = df['Roll (degrees/second)'] - bias_rol
df['Hei_Skoon'] = df['Pitch (degrees/second)'] - bias_hei
df['Gier_Skoon'] = df['Yaw (degrees/second)'] - bias_gier

df['Roll_Angle'] = df['Rol_Skoon'].cumsum() * dt
df['Pitch_Angle'] = df['Hei_Skoon'].cumsum() * dt
df['Yaw_Angle'] = df['Gier_Skoon'].cumsum() * dt


plt.plot(df['Time_s'], df['Roll_Angle'], label='Roll (Graad)')
plt.plot(df['Time_s'], df['Pitch_Angle'], label='Pitch (Graad)')
plt.plot(df['Time_s'], df['Yaw_Angle'], label='Yaw (Graad)')

plt.title(f'Geïntegreerde Hoek teen Tyd sonder vooroordeel ({frekwensie_hz}Hz)')
plt.xlabel('Tyd (sekondes)')
plt.ylabel('Hoek (grade)')
plt.legend()
plt.grid(True)

plt.show()
# %%
