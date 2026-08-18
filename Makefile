FILE=clock

all: $(FILE).c
	gcc -o $(FILE) $(FILE).c

install: $(FILE).c
	gcc -o $(FILE) $(FILE).c
	cp ./$(FILE) /usr/local/bin/$(FILE)

clean: $(FILE)
	rm ./$(FILE) /usr/local/bin/$(FILE)
