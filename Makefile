all:
	make -C ex00
	make -C ex01
	make -C ex02
	make -C ex03
clean:
	make -C ex00 clean
	make clean -C ex01
	make -C ex02 clean
	make clean -C ex03