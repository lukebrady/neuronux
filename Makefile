# Make file used to build Neuroux. This build will be fully automated.
GCC="/usr/bin/gcc"

init:
	GCC -o ./bin/ax ./shell/axon/axon.c
	GCC -o ./bin/chroot ./commands/chroot/chroot.c
	GCC -o ./bin/cp ./commands/cp/cp.c
	GCC -o ./bin/mkdir ./commands/mkdir/mkdir.c