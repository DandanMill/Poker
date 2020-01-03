# GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  Poker_config = debug
endif
ifeq ($(config),release)
  Poker_config = release
endif

PROJECTS := Poker

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

Poker:
ifneq (,$(Poker_config))
	@echo "==== Building Poker ($(Poker_config)) ===="
	@${MAKE} --no-print-directory -C . -f Poker.make config=$(Poker_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f Poker.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   Poker"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"