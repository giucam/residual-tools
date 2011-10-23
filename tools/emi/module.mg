
add_executable cosb2cos cosb2cos.o
add_executable meshb2obj "meshb2obj.o lab.o"
add_executable animb2txt "animb2txt.o lab.o"
add_executable setb2set "setb2set.o lab.o"
add_executable sklb2txt "sklb2txt.o lab.o"
add_executable til2bmp "til2bmp.o lab.o" -lz

add_in_group cosb2cos emi
add_in_group meshb2obj emi
add_in_group animb2txt emi
add_in_group setb2set emi
add_in_group sklb2txt emi
add_in_group til2bmp emi
