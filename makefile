
all: client tools

client:
	$(MAKE) -C client

tools:
	$(MAKE) -C tools/meshtool

