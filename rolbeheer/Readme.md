# Rolbeheerstelsel vir sweeftuig

Stelsel wat die vlerke gelyk hou in rol.  Rolhoek word met 'n 3-assige versnellingsmeter gemeet en dit word dan beheer terug na 'n 0 grade rolhoek deur die aanwending van rolroere wat met servos beheer word.





![AirfoilGlideAngle](C:\WPy64-3950\notebooks\myArduino\rolbeheer\Prente\AirfoilGlideAngle.png)
$$
T = C_r \delta
$$

$$
\ddot{\theta} = \frac{T}{I_{xx}}
$$

Waar $\theta$ die heihoek is.

Die volgende diagram beskryf die beheerstelsel:

![ControlLoopRoll](C:\WPy64-3950\notebooks\myArduino\rolbeheer\Prente\ControlLoopRoll.png)

Daar is filters nodig om die metings te filter met die volgende oordragsfunksie.  Dit is nog nie in die diagram nie.

$H(s)=\frac{1}{1+sA}$

Die beheerstelsel is digitaal dus word daar van die z-transform gebruik om die digitale beheerstelsel te analiseer:

$h(t) \rightarrow H(s) \rightarrow H(z)$

Die digitale beheer het 'n ekstra filter effek wat dit inbring.  Die volgende diagram is nog nie reg/volledig nie, maar dit is soos die diagram van die s- na die z-transform gaan:

![FilterEffek](C:\WPy64-3950\notebooks\myArduino\rolbeheer\Prente\FilterEffek.png)