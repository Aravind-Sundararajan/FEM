CC = g++
CFLAGS = -g -O2 -Wall
INCLUDES = -I ./src/ -I /usr/local/include
srcdir := ./src/
bindir := ./bin/
PhyDof.o: $(srcdir)PhyDof.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)PhyDof.cpp -o $(bindir)PhyDof.o
FEMSolver.o: $(srcdir)FEMSolver.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)FEMSolver.cpp -o $(bindir)FEMSolver.o
LAFuncs.o: $(srcdir)LAFuncs.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)LAFuncs.cpp -o $(bindir)LAFuncs.o
PhyElement.o: $(srcdir)PhyElement.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)PhyElement.cpp -o $(bindir)PhyElement.o
PhyElementBar.o: $(srcdir)PhyElementBar.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)PhyElementBar.cpp -o $(bindir)PhyElementBar.o
PhyElementBeam.o: $(srcdir)PhyElementBeam.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)PhyElementBeam.cpp -o $(bindir)PhyElementBeam.o
PhyElementFrame.o: $(srcdir)PhyElementFrame.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)PhyElementFrame.cpp -o $(bindir)PhyElementFrame.o
PhyElementTruss.o: $(srcdir)PhyElementTruss.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)PhyElementTruss.cpp -o $(bindir)PhyElementTruss.o
PhyGlobal.o: $(srcdir)PhyGlobal.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)PhyGlobal.cpp -o $(bindir)PhyGlobal.o
PhyMaterial.o: $(srcdir)PhyMaterial.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)PhyMaterial.cpp -o $(bindir)PhyMaterial.o
PhyNode.o: $(srcdir)PhyNode.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)PhyNode.cpp -o $(bindir)PhyNode.o
TestSuites.o: $(srcdir)TestSuites.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)TestSuites.cpp -o $(bindir)TestSuites.o
main.o: $(srcdir)main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $(srcdir)main.cpp -o $(bindir)main.o
test: PhyDof.o FEMSolver.o LAFuncs.o PhyElement.o PhyElementBar.o PhyElementBeam.o PhyElementFrame.o PhyElementTruss.o PhyGlobal.o PhyMaterial.o PhyNode.o TestSuites.o main.o
	$(CC) $(CFLAGS) $(INCLUDES) $(bindir)PhyDof.o $(bindir)FEMSolver.o $(bindir)LAFuncs.o $(bindir)PhyElement.o $(bindir)PhyElementBar.o $(bindir)PhyElementBeam.o $(bindir)PhyElementFrame.o $(bindir)PhyElementTruss.o $(bindir)PhyGlobal.o $(bindir)PhyMaterial.o $(bindir)PhyNode.o $(bindir)TestSuites.o $(bindir)main.o -o test

clean:
	rm -f *.exe test && cd $(bindir) && rm -f *.o
all: test
	