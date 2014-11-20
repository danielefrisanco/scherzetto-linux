scherzetto: scherzetto.o
		cc -o $@ $< -lX11
		
scherzetto.o: scherzetto.cpp
	cc -c -o $@ $<
 
.PHONY: clean
clean:
		-rm -f scherzetto scherzetto.o