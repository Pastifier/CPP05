all:
	make -C ex00
	make -C ex01
clean:
	make -C ex00 clean
	make clean -C ex01