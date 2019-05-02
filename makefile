
   t1 : t1.c
	gcc t1.c -o t1.exe	

   valgrind : t1.exe
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./t1.exe

   clean : 
	rm -rf t1.exe
