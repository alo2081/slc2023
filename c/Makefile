CC := gcc
SRCDIR := src
BUILDDIR := build

main: ${SRCDIR}/main.c
	echo "Main...";
	mkdir -p $(BUILDDIR)
	${CC} ${SRCDIR}/main.c -o ${BUILDDIR}/main

clean:
	@echo "Cleaning..."; 
	rm -r $(BUILDDIR)