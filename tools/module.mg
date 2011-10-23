
add_executable unlab unlab.o
add_executable mklab mklab.o
add_executable int2flt int2flt.o
add_executable imc2wav imc2wav.o
add_executable set2fig set2fig.o
add_executable vima vima.o
add_executable labcopy labcopy.o
add_executable patchex "patchex/patchex.o patchex/mszipd.o patchex/cabd.o"

add_subdirectory delua
add_subdirectory emi
