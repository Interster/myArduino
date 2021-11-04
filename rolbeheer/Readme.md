# Rolbeheerstelsel vir sweeftuig

Stelsel wat die vlerke gelyk hou in rol.  Rolhoek word met 'n 3-assige versnellingsmeter gemeet en dit word dan beheer terug na 'n 0 grade rolhoek deur die aanwending van rolroere wat met servos beheer word.





![AirfoilGlideAngle](C:\WPy64-3950\notebooks\myArduino\rolbeheer\Prente\AirfoilGlideAngle.png)
$$
T = C_r \delta
$$

$$
\ddot{\theta} = \frac{T}{I_{xx}}
$$

Where $\theta$ is the pitch angle.




# Te doen

Maak 'n draad op waarmee die servo en die versnellingsmeter gelyk in die 5V krag kan inprop.  Onthou 2 servos.
Maak seker Arduino kan genoeg stroom gee vir die servos en versnellingsmeter
Sit tweede servo by in program
Teken stroombaan in Fritzing (dus vertaal Fritzing en teken stroombaan en dan sit dit in hierdie dokument)

Die servo uitset het baie geraas.  Vind uit waar dit vandaan kom.  Miskien moet daar 'n filter kom