
default:
	make -C core
	make -C apps

clean:
	make -C core clean
	make -C apps clean
