cmake_minimum_required(VERSION 3.30)
project(algoritmos)

set(CMAKE_CXX_STANDARD 20)

add_executable(algoritmos main.cpp)
add_executable(hoja01_ejercicio01 HOJAEJERCICIOS01/hoja01_ejercicio01.cpp)
add_executable(hoja01_ejercicio02 HOJAEJERCICIOS01/hoja01_ejercicio02.cpp)
add_executable(hoja01_ejercicio03 HOJAEJERCICIOS01/hoja01_ejercicio03.cpp)
add_executable(hoja02_ejercicio01 HOJAEJERCICIOS02/hoja02_ejercicio01.cpp)
add_executable(hoja02_ejercicio02 HOJAEJERCICIOS02/hoja02_ejercicio02.cpp)
add_executable(hoja02_ejercicio03 HOJAEJERCICIOS02/hoja02_ejercicio03.cpp)
add_executable(ejercicio_perusall HOJAEJERCICIOS02/ejercicio_perusall.cpp)
add_executable(hoja03_ejercicio01 HOJAEJERCICIOS03/hoja03_ejercicio01.cpp)
add_executable(hoja03_ejercicio02 HOJAEJERCICIOS03/hoja03_ejercicio02.cpp)
add_executable(hoja03_ejercicio03 HOJAEJERCICIOS03/hoja03_ejercicio03.cpp)
add_executable(hoja03_ejercicio04 HOJAEJERCICIOS03/hoja03_ejercicio04.cpp)
add_executable(hoja03_ejercicio05 HOJAEJERCICIOS03/hoja03_ejercicio05.cpp)
add_executable(hoja03_ejercicio06 HOJAEJERCICIOS03/hoja03_ejercicio06.cpp)
add_executable(ejercicio01_asociacion HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/ejercicio01_asociacion.cpp)
add_executable(ejercicio02_agregacion HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/ejercicio02_agregacion.cpp)
add_executable(ejercicio03_composicion HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/ejercicio03_composicion.cpp)
add_executable(ejercicio04_herencia HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/ejercicio04_herencia.cpp)
add_executable(ejercicio05_dependencia HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/ejercicio05_dependencia.cpp)
add_executable(ejercicio_repaso HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/ejercicio_repaso.cpp
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Vehiculo.h
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Compania.h
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Automovil.h
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Conductor.h
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Flota.h
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Motocicleta.h
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Motor.h
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Motor.cpp
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Vehiculo.cpp
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Automovil.cpp
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Motocicleta.cpp
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Conductor.cpp
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Compania.cpp
        HOJAEJERCICIOS03/EJERCICIOSREFORZAMIENTO/EJERCICIOVEHICULOS/Flota.cpp)
add_executable(persona HOJAEJERCICIOS04/EJERCICIOSREPASO/main.cpp
        HOJAEJERCICIOS04/EJERCICIOSREPASO/persona.cpp
        HOJAEJERCICIOS04/EJERCICIOSREPASO/persona.h)
add_executable(hoja04_ejercicio01 HOJAEJERCICIOS04/hoja04_ejercicio01.cpp)
add_executable(hoja05_ejercicio01 HOJAEJERCICIOS05/EJERCICIO01/hoja05_ejercicio01.cpp
        HOJAEJERCICIOS05/EJERCICIO01/Boleto.h
        HOJAEJERCICIOS05/EJERCICIO01/Hotel.h
        HOJAEJERCICIOS05/EJERCICIO01/PlanVacacion.h)
add_executable(lb1_ejercicio01 LB1/lb1_ejercicio01.cpp)
add_executable(lb1_ejercicio02 LB1/lb1_ejercicio02.cpp)
