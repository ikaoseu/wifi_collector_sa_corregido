## **README - _Submission 1_**

---

Ricardo Oteros (100451998@alumnos.uc3m.es)
Manu Morales (100451690@alumnosuc3m.es)
Jaime Mato (100451639@alumnos.uc3m.es)

1. Download the folder
2. Run the command: gcc main.c quit.c collect.c display.c display_all.c -o main
3. Execute program: ./main

The proyect is structured in three parts: code folder (src), headers folder(incl) & cell folder(files).
The code folder includes all functions (.c files) and the header folder (.h files) includes all declarations.


The program showed the following error message at compile time after cleaning up all the marked errors and warnings:

jmato@jaime:~/wifi_collector_sa/src$ gcc main.c quit.c collect.c display.c display_all.c -o test
/usr/bin/ld: /tmp/ccfduiRF.o:(.data+0x0): multiple definition of `file_name'; /tmp/ccLWR5yC.o:(.data+0x0): first defined here
/usr/bin/ld: /tmp/ccfduiRF.o: in function `read_cell':
collect.c:(.text+0x286): undefined reference to `put_connection_to_struct'
collect2: error: ld returned 1 exit status

We tried to solve this problem, but we can't manage to make it compile successfully.