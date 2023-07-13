# minitalk
project minitalk 42 2.0 2023

[creer-et-tuer-des-processus-fils-en-c](https://www.codequoi.com/creer-et-tuer-des-processus-fils-en-c/)

[envoyer-et-intercepter-un-signal-en-c](https://www.codequoi.com/envoyer-et-intercepter-un-signal-en-c/)

arret 'envoyer-et-intercepter-un-signal-en-c' : Intercepter un signal avec sigaction


## Plan

* afficher PID
* donner une action si le int = 1 ou = 2 pour gérer le handler dans la strucutre afin de determiner les SIGUSR1 et SIGUSR2
* utiliser sigaction en utilisant le handler
* utiliser kill pour envoyer des signaux

### Fonctions autorisées
◦ write
◦ ft_printf and any equivalent YOU coded
◦ signal
◦ sigemptyset
◦ sigaddset
◦ sigaction
◦ kill
◦ getpid
◦ malloc
◦ free
◦ pause
◦ sleep
◦ usleep
◦ exit