
all: client tools

clean: client tools

#$(warning MAKECMDGOALS = $(MAKECMDGOALS))

.PHONY: client
client:
	$(MAKE) -C client $(MAKECMDGOALS)

.PHONY: tools
tools:
	$(MAKE) -C tools/meshtool $(MAKECMDGOALS)


