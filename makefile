bin/jason : jason.c obj/responsive.o obj/journey.o
	gcc -o bin/jason jason.c obj/responsive.o obj/journey.o \
	 -lallegro -lallegro_font -lallegro_primitives 

obj/journey.o : journey.c obj/responsive.o
	gcc -o obj/journey.o -c journey.c obj/responsive.o

obj/responsive.o : responsive.c
	gcc -o obj/responsive.o -c responsive.c