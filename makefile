CC=gcc

electrotest: main.o
	$(CC) -o electrotest main.o -L. -lcomponent -lpower -lresistence -lm -Wl,-rpath,.

main.o: main.c
	$(CC) -c main.c


lib:
	$(CC) -c -fPIC component.c
	$(CC) -shared -fPIC -o libcomponent.so component.o
	
	$(CC) -c -fPIC calc_resistance.c
	$(CC) -shared -fPIC -o libresistance.so calc_resistance.o

	$(CC) -c -fPIC libpower.c
	$(CC) -shared -fPIC -o libpower.so libpower.o

clean:
	rm *.o
	rm -R lib
	
all:
	make lib
	if [ ! -d lib ] ; then \
		mkdir lib ; \
	fi ;
	mv libcomponent.so libresistance.so libpower.so lib	

	make main.o	
	$(CC) -o electrotest main.o -L./lib/ -lcomponent -lpower -lresistance -lm -Wl,-rpath,./lib/

install:
	cp ./lib/* /usr/lib/
	cp electrotest /usr/bin/

uninstall: 
	rm /usr/lib/libcomponent.so /usr/lib/libpower.so /usr/lib/libresistance.so
	rm /usr/bin/electrotest
