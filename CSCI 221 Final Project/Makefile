CC = g++
CFLAGS = -Wall -std=c++14

game: main.o satchel.o item.o bronze_dagger.o kente_cloak.o healing_calabash.o golden_stool_key.o spider_silk.o royal_drum.o glowing_red_mask.o cursed_gourd.o obsidian_ring.o whispering_shell.o ashanti_mirror.o sunstone_bead.o enchanted_ivory_tusk.o
	$(CC) $(CFLAGS) -o game main.o satchel.o item.o bronze_dagger.o kente_cloak.o healing_calabash.o golden_stool_key.o spider_silk.o royal_drum.o glowing_red_mask.o cursed_gourd.o obsidian_ring.o whispering_shell.o ashanti_mirror.o sunstone_bead.o enchanted_ivory_tusk.o

main.o: main.cpp satchel.hpp item.hpp bronze_dagger.hpp kente_cloak.hpp healing_calabash.hpp golden_stool_key.hpp spider_silk.hpp royal_drum.hpp glowing_red_mask.hpp cursed_gourd.hpp obsidian_ring.hpp whispering_shell.hpp ashanti_mirror.hpp sunstone_bead.hpp enchanted_ivory_tusk.hpp
	$(CC) $(CFLAGS) -c main.cpp

satchel.o: satchel.cpp satchel.hpp item.hpp
	$(CC) $(CFLAGS) -c satchel.cpp

item.o: item.cpp item.hpp
	$(CC) $(CFLAGS) -c item.cpp

bronze_dagger.o: bronze_dagger.cpp bronze_dagger.hpp item.hpp
	$(CC) $(CFLAGS) -c bronze_dagger.cpp

kente_cloak.o: kente_cloak.cpp kente_cloak.hpp item.hpp
	$(CC) $(CFLAGS) -c kente_cloak.cpp

healing_calabash.o: healing_calabash.cpp healing_calabash.hpp item.hpp
	$(CC) $(CFLAGS) -c healing_calabash.cpp

golden_stool_key.o: golden_stool_key.cpp golden_stool_key.hpp item.hpp
	$(CC) $(CFLAGS) -c golden_stool_key.cpp

spider_silk.o: spider_silk.cpp spider_silk.hpp item.hpp
	$(CC) $(CFLAGS) -c spider_silk.cpp

royal_drum.o: royal_drum.cpp royal_drum.hpp item.hpp
	$(CC) $(CFLAGS) -c royal_drum.cpp

glowing_red_mask.o: glowing_red_mask.cpp glowing_red_mask.hpp item.hpp
	$(CC) $(CFLAGS) -c glowing_red_mask.cpp

cursed_gourd.o: cursed_gourd.cpp cursed_gourd.hpp item.hpp
	$(CC) $(CFLAGS) -c cursed_gourd.cpp

obsidian_ring.o: obsidian_ring.cpp obsidian_ring.hpp item.hpp
	$(CC) $(CFLAGS) -c obsidian_ring.cpp

whispering_shell.o: whispering_shell.cpp whispering_shell.hpp item.hpp
	$(CC) $(CFLAGS) -c whispering_shell.cpp

ashanti_mirror.o: ashanti_mirror.cpp ashanti_mirror.hpp item.hpp
	$(CC) $(CFLAGS) -c ashanti_mirror.cpp

sunstone_bead.o: sunstone_bead.cpp sunstone_bead.hpp item.hpp
	$(CC) $(CFLAGS) -c sunstone_bead.cpp

enchanted_ivory_tusk.o: enchanted_ivory_tusk.cpp enchanted_ivory_tusk.hpp item.hpp
	$(CC) $(CFLAGS) -c enchanted_ivory_tusk.cpp

clean:
	rm -f *.o game