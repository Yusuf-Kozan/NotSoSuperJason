bin/jason : jason.c obj/responsive.o
	gcc -o bin/jason jason.c obj/responsive.o -lallegro -lallegro_font -lallegro_primitives 

obj/responsive.o : responsive.c
	gcc -o obj/responsive.o -c responsive.c